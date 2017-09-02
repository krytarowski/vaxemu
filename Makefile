#	$NetBSD$

PROGS=	vaxemu vaxasm vaxdisasm
NOMAN=	yes

LDADD+=-lutil
DPADD+=${LIBUTIL}

CLEANFILES+=	*~

.include <bsd.prog.mk>
