# VAD code makefile

MAKEFILENAME=Makefile

CC = gcc
CFLAGS = -Wall -g -O4
AR = ar
RANLIB = arnlib
LIB = -lpthread -lm
ECHO_PREFIX=@\# 
CMD_PREFIX=

SRCS = $(wildcard *.c)

LIB_TARGET = libvad.a 
OBJECTS = webrtc_vad.o \
		vad_core.o \
		vad_filterbank.o \
		vad_gmm.o \
		vad_sp.o \
		real_fft.o \
		division_operations.o \
		complex_bit_reverse.o \
		cross_correlation.o \
		complex_fft.o \
		downsample_fast.o \
		vector_scaling_operations.o \
		get_scaling_square.o \
		energy.o \
		min_max_operations.o \
		spl_init.o	\
		resample_48khz.o \
		resample_by_2_internal.o \
		resample_fractional.o



all : $(LIB_TARGET)
$(LIB_TARGET) : $(OBJECTS)
	$(ECHO_PREFIX) echo "   [AR] $^ -> $@"
	$(CMD_PREFIX) $(AR) cr $@ $^

#
# make / clean dependency list
#
depend:
	$(MAKE) -f $(MAKEFILENAME) $(MFLAGS) $(MAKEDEFS) clean_depend
	$(CC) $(CFLAGS) $(SRCS) >> $(MAKEFILENAME)

clean_depend:
	chmod u+w $(MAKEFILENAME)
	(awk 'BEGIN{f=1}{if (f) print $0}/^\# DO NOT DELETE THIS LINE -- make depend depends on it./{f=0}'\
	    < $(MAKEFILENAME) > .depend && \
	mv .depend $(MAKEFILENAME)) || exit 1;

	
clean : 
	rm -f $(LIB_TARGET) $(OBJECTS)
	
webrtc_vad.o : webrtc_vad.c signal_processing_library.h vad_core.h typedefs.h
vad_core.o : vad_core.c vad_core.h signal_processing_library.h typedefs.h vad_filterbank.h vad_gmm.h vad_sp.h
vad_filterbank.o : vad_filterbank.c vad_filterbank.h signal_processing_library.h typedefs.h
vad_gmm.o : vad_gmm.c vad_gmm.h signal_processing_library.h typedefs.h
vad_sp.o : vad_sp.c vad_sp.h signal_processing_library.h vad_core.h typedefs.h
real_fft.o : real_fft.c real_fft.h signal_processing_library.h
division_operations.o : division_operations.c signal_processing_library.h
complex_bit_reverse.o : complex_bit_reverse.c signal_processing_library.h
cross_correlation.o : cross_correlation.c signal_processing_library.h
complex_fft.o : complex_fft.c signal_processing_library.h
downsample_fast.o : downsample_fast.c signal_processing_library.h
vector_scaling_operations.o : vector_scaling_operations.c signal_processing_library.h
get_scaling_square.o : get_scaling_square.c signal_processing_library.h
energy.o : energy.c signal_processing_library.h
min_max_operations.o : min_max_operations.c signal_processing_library.h
spl_init.o : spl_init.c real_fft.h signal_processing_library.h cpu_features_wrapper.h
resample_48khz.o : resample_48khz.c signal_processing_library.h resample_by_2_internal.h
resample_by_2_internal.o : resample_by_2_internal.c resample_by_2_internal.h
resample_fractional.o : resample_fractional.c signal_processing_library.h
