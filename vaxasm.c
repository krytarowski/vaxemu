/*-
 * Copyright (c) 2017 Kamil Rytarowski
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/param.h>
#include <sys/types.h>
#include <sys/rbtree.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <util.h>

char *fname;
uint32_t LC; // location counter
FILE *fp;

__dead void usage(void);
void pass1(void);

int
main(int argc, char **argv)
{
	int ch;

	// Store the program name
	setprogname(argv[0]);

	// Parse command line arguments
	while ((ch = getopt(argc, argv, "hf:")) != -1) {
		switch (ch) {
		case 'f':
			if (fname)
				free(fname);
			fname = estrdup(optarg);
			break;
		case 'h':
		case '?':
		default:
			usage();
		}
	}

	// The input filename is mandatory
	if (!fname)
		usage();

	// Open the input file
	fp = efopen(fname, "r");

	// Pass 1
	// Create label and symbol table
	// Assert syntax correctness
	pass1();

	// Rewind the file pointer and prepare for the sequent pass
	rewind(fp);

	// Pass 2
	pass2();

	return EXIT_SUCCESS;
}

void
usage(void)
{
	errx(EXIT_SUCCESS, "Usage: %s [-h] [-f file]", getprogname());
}

void
pass1(void)
{
	bool finish = false; // Whether parsed the end statement
	size_t linelen;
	char *line;

	// Begin pass 1

	// Initialize location counter to zero
	LC = 0;

	do {
		// read next line from source program
		if ((line = fgetln(fp, &len)) == null)
			break;

		// analyze line for syntax
		/*
		 * Grammar
		 * =======
		 *
		 * expression =
		 * 	instruction
		 *	| data
		 *	| symbol
		 *	| control
		 *
		 * instruction =
		 *	label opcode operands comment
		 *
		 * label =
		 *	label1
		 *	| (epsilon)
		 *
		 * operands
		 *	operand1
		 *	| operand1 ',' operands
		 *
		 * data =
		 *	label type
		 *
		 * symbol =
		 *	symbol_name '=' constant
		 *
		 * constant =
		 *	decimal_number
		 *	| unary_number
		 *	| expression
		 *
		 * control =
		 *	title module_name comment
		 *	| sbttl comment
		 *	| entry procedure_name ',' register_mask
		 *	| end label
		 */ 

		
	} while (finish);

	// Assert that there were no errors when reading from a file
	if (ferror(stream))
		err(EXIT_FAILURE, "ferror");

	;
}
