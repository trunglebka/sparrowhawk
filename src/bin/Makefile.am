if HAVE_BIN
bin_PROGRAMS = normalizer_main normalizer_worker

AM_CPPFLAGS = -I$(srcdir)/../include

LDADD= ../lib/libsparrowhawk.la -L/usr/local/lib/fst -l:libthrax.a -l:libfstscript.a -l:libfstfar.a -l:libfst.a -lm -ldl -l:libprotobuf.a -l:libre2.a

normalizer_worker_LDADD= $(LDADD) -lredis++ -lhiredis
normalizer_main_SOURCES = normalizer_main.cc
normalizer_worker_SOURCES = normalizer_worker.cc
endif
