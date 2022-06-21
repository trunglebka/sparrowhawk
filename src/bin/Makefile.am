if HAVE_BIN
bin_PROGRAMS = normalizer_main normalizer_worker

AM_CPPFLAGS = -I$(srcdir)/../include

LDADD= ../lib/libsparrowhawk.la -L/usr/local/lib/fst -lthrax -lfstscript -lfstfar -lfst -lm -ldl -lprotobuf -lre2

normalizer_worker_LDADD= ../lib/libsparrowhawk.la -L/usr/local/lib/fst -lthrax -lfstscript -lfstfar -lfst -lm -ldl -lprotobuf -lre2 -lredis++ -lhiredis
normalizer_main_SOURCES = normalizer_main.cc
normalizer_worker_SOURCES = normalizer_worker.cc
endif
