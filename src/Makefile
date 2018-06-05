#INC=  
LIB= -lpthread 
  
CC=gcc  
#CC_FLAG=-Wall  
  
PRG=vad_demo  
OBJ =  main.o file_cut.o period_format.o simple_vad.o   
  
$(PRG) : $(OBJ)  
	$(CC)   -o $@  $(OBJ)  ./libvad.a  $(LIB)
main.o : webrtc_vad.h simple_vad.h period_format.h file_cut.h
file_cut.o : file_cut.h
period_format.o : common.h period_format.h
simple_vad.o : simple_vad.h
      
  
.PRONY:clean  
clean:  
	@echo "Removing linked and compiled files......"  
	rm -f $(OBJ) $(PRG)  
