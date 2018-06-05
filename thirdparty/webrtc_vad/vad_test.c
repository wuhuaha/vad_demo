#include "webrtc_vad.h"
#include<stdio.h>

int main()
{
	int ret = 0;
	int i = 0;
	int kRates[] = { 8000, 12000, 16000, 24000, 32000, 48000 };
	//int kMaxFrameLength = 1440;
	int kFrameLengths[] = { 80, 120, 160, 240, 320, 480, 640, 960 };
	short zeros[16] = {0};
	short speech[16] = {0};
	
	for (i = 0; i < 16; i++) {
		speech[i] = (i * i);
	}
	
	VadInst* handle = NULL;
	int mode = 0;
	WebRtcVad_Create(&handle);
	WebRtcVad_Init(handle);
	WebRtcVad_set_mode(handle,mode);
	
	ret = WebRtcVad_Process(handle, kRates[0], NULL, kFrameLengths[0]);
	printf("ret1 = %d\n",ret);
	
	ret = WebRtcVad_Process(handle, kRates[0], zeros, kFrameLengths[0]);
	printf("ret2 = %d\n",ret);	
	
	
	return 0;
}