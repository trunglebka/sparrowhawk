if HAVE_BIN
bin_PROGRAMS = normalizer_main normalizer_worker

AM_CPPFLAGS = -I$(srcdir)/../include

AM_LDFLAGS = -Wl,--whole-archive,-l:libfst.a,--no-whole-archive
LDADD= ../lib/libsparrowhawk.la -l:libthrax.a -l:libfstscript.a -l:libfstfar.a -l:libprotobuf.a -l:libre2.a -lm -ldl -lpthread

normalizer_worker_LDADD= $(LDADD) -l:libredis++.a -l:libhiredis.a
normalizer_main_SOURCES = normalizer_main.cc
normalizer_worker_SOURCES = normalizer_worker.cc
endif
