#	$NetBSD$

PROGS=	vaxemu vaxasm vaxdisasm
NOMAN=	yes

LDADD+=-lutil
DPADD+=${LIBUTIL}

CLEANFILES+=	*~

test:
	echo aa

.include <bsd.prog.mk>
