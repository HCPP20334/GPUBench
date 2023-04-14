#include <iostream>
#include <string>
#include <time.h>
#include "Colors.h"
#include <conio.h>


#define MAX_HEIGHT 1080
#define MAX_WIDTH 1920
#define MAX_PARTICLES 255


using namespace std;



int main(int argc, char *argv[])
{
	int64_t fGPURenderLoop = 1;
	int64_t fCurrentFrames = 1;
	int64_t fGPUPerfomanceScore = 1;
	int64_t fUsageGPUMemory = 1;
	int64_t fGPUXResolutions[] = {320,640,800,1280,1360,1366,1920};
	int64_t fGPUYResolutions[] = {240,480,600,720,768,1080};
	int64_t fGPUXResValues = 5;
	int64_t fGPUYResValues = 6;
	int64_t fLastTimeValue = 0;
	int64_t fGPUThreads = 0;
	int64_t fSetItemVal = 0;
	int64_t fItCol0  = 0;
	int64_t fItCol1  = 0;
	int64_t fItCol2  = 0;
	int64_t fInputDelay = 0;
	int64_t fMaxInputDelay = 5;//Delay Input KeyBoard!!
	int64_t fR = 0;
	int64_t fMaxTime = 1;
	int64_t fX = 0;
	int64_t fY = 0;
	int64_t fXR = 0;
	int64_t fYR = 0;
	int64_t fScreenX = 320;
    int64_t fScreenY = 240;
    int64_t fPart = 0;
    int64_t fRed = 0;
    int64_t fGreen = 0;
    int64_t fBlue = 0;
    int64_t fCDel = 0;
    int64_t fColorS = 0;
    int64_t fColorF = 0;
    int64_t fStackX = 0;
    int64_t fStackY = 0;
	//
	bool fGPURender = false;
	bool fSettings;
	bool fDebugMenu = false;
	//
	string fStrTitle = "";
	string fRESArray = "NULL";
	string fDebug = "NULL";
	string fStrStatus;
	//
	HWND hWCon = GetConsoleWindow();
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	HDC fDC = GetDC(hWCon);
	tagPOINT fPos;
	//
	for(int64_t fMLoop = 1;fMLoop > 0;fMLoop++)
    {
    if(!fGPURender)
    {
    	fCDel++;
    	if(fCDel == 0)
    	{
    		fColorS = 119;
    		fColorF = 133;
		}
		if(fCDel == 15)
    	{
    		fColorS = 30;
    		fColorF = 136;
		}
		if(fCDel == 30)
    	{
    		fColorS = 15;
    		fColorF = 132;
    		fCDel = 0;
		}
    	cls(hCon);
    	srand(time(0));
    	 SetColorAMD64(139);
	cout<<"                                                                                                       "<<endl;
	cout<<"                                                                                                       "<<endl;
		SetColorAMD64(fColorF);
	cout<<"                                        :::::: GPUBenchMark by HCPP ::::::                             "<<endl;
	SetColorAMD64(139);
	cout<<"                                                                                                       "<<endl;
	cout<<"                                                                                                       "<<endl;
	cout<<"_______________________________________________________________________________________________________\n\n"<<endl;
	SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(15 + fItCol0);
	cout<<" RESOLUTION:";
	SetColorAMD64(15);
	cout<<fRESArray<<endl;
	SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(15 + fItCol1);
	cout<<"  OverLoad(Threads):";
	SetColorAMD64(15);
	cout<<fGPUThreads<<endl;
	SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(15 + fItCol2);
	cout<<"  Time          :";
	SetColorAMD64(15);
	cout<<fMaxTime<<"s"<<endl;
	 SetColorAMD64(15);
    cout<<"\t\t\t";
    cout<<"Start Render";
	//SetColorAMD64(fColorS);
	cout<<" [ENTER]"<<endl;
	SetColorAMD64(15);
	cout<<"      \t\t\t_______________________:::: Result ::::_______________________"<<endl;
	cout<<"\t\t\tResolution X:"<<fX<<"| Y:"<<fY<<"\n"<<endl;
		 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(30);
    cout<<"Pixels: "<<(fPart / fMaxTime)<<"/s -> "<<fPart<<" /"<<fMaxTime<<"s"<<endl;
    	 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(132);
    cout<<"Stack0 = "<<&fGPUXResolutions[fStackX]<<endl;
    	 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(132);
    cout<<"Stack1 = "<<&fGPUYResolutions[fStackY]<<endl;
    	 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(132);
    cout<<fStrStatus<<endl;
    	 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(132);
    	cout<<"InputDelay:"<<fInputDelay<<endl;
    		 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(132);
		cout<<"ItemSelected:"<<fSetItemVal<<endl;
			 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(132);
		cout<<"MaxDelay:"<<fMaxInputDelay<<endl;
			 SetColorAMD64(15);
    cout<<"\t\t\t";
	SetColorAMD64(30);
    	cout<<"KeyBoard InputLag D + (+) - Delay++ ,D + (-) - Delay--"<<endl;
    cout<<"\t\t\t____________________________________________________________________"<<endl;
    SetColorAMD64(15);
             if(fR == 0)
			 {
			 	fRESArray = to_string(fGPUXResolutions[1]) + "x"+ to_string(fGPUYResolutions[1]);
			    fX = fGPUXResolutions[1];
			 	fY = fGPUYResolutions[1];
			 	fStackX = 1;
			 	fStackY = 1;
			 }
			 if(fR == 1)
			 {
			 	fRESArray = to_string(fGPUXResolutions[2]) + "x"+ to_string(fGPUYResolutions[2]);
			 	fX = fGPUXResolutions[2];
			 	fY = fGPUYResolutions[2];
			 	fStackX = 2;
			 	fStackY = 2;
			 }
			 if(fR == 2)
			 {
			 	fRESArray = to_string(fGPUXResolutions[3]) + "x"+ to_string(fGPUYResolutions[3]);
			 	fX = fGPUXResolutions[3];
			 	fY = fGPUYResolutions[3];
			 	fStackX = 3;
			 	fStackY = 3;
			 }
			 if(fR == 3)
			 {
			 	fRESArray = to_string(fGPUXResolutions[4]) + "x"+ to_string(fGPUYResolutions[4]);
			 	fX = fGPUXResolutions[4];
			 	fY = fGPUYResolutions[4];
			 	fStackX = 4;
			 	fStackY = 4;
			 }
			 if(fR == 4)
			 {
			 	fRESArray = to_string(fGPUXResolutions[4]) + "x"+ to_string(fGPUYResolutions[5]);
			 	fX = fGPUXResolutions[4];
			 	fY = fGPUYResolutions[5];
			 	fStackX = 4;
			 	fStackY = 5;
			 }
			  if(fR == 5)
			 {
			 	fRESArray = to_string(fGPUXResolutions[5]) + "x"+ to_string(fGPUYResolutions[6]);
			 	fX = fGPUXResolutions[5];
			 	fY = fGPUYResolutions[6];
			 	fStackX = 5;
			 	fStackY = 6;
			 }
	if(GetAsyncKeyState(VK_RETURN))
	{
		fPart = 0;
		fGPURender = true;
		system("cls");
	}
	if(GetAsyncKeyState('A'))
	{
		Sleep(80);
		if(fSetItemVal == 0)
		{
			 fR--;
			 if(fR < 0)
			 {
			 	fR = 5;
			 }
		}
		if(fSetItemVal == 1)
		{
			fGPUThreads--;
			if(fGPUThreads < 1)
			{
				fGPUThreads = 1;
				cout<<" Min 1!"<<endl;
			}
		}
		if(fSetItemVal == 2)
		{
			fMaxTime = fMaxTime - 1;
			if(fMaxTime < 1)
			{
				fMaxTime = 1;
				cout<<" Min 1!"<<endl;
			}
		}
	}
	if(GetAsyncKeyState('D'))
	{
		Sleep(80);
		if(GetAsyncKeyState(VK_ADD))
		{
			Sleep(80);
			fMaxInputDelay++;
		}
		if(GetAsyncKeyState(VK_SUBTRACT))
		{
			Sleep(80);
			fMaxInputDelay--;
			if(fMaxInputDelay < 0)
			{
				fMaxInputDelay = 1;
			}
		}
		if(fSetItemVal == 0)
		{
			 fR++;
			 if(fR > 5)
			 {
			 	fR = 0;
			 }
		}
		if(fSetItemVal == 1)
		{
			fGPUThreads++;
			if(fGPUThreads > 4)
			{
				fGPUThreads = 4;
				cout<<" Max 4!"<<endl;
			}
		}
		if(fSetItemVal == 2)
		{
			 fMaxTime++;
		}
	}
	if(GetAsyncKeyState('S'))
	{
		fInputDelay++;
		if(fInputDelay == fMaxInputDelay)
		{
			fSetItemVal++;
			fInputDelay = 0;
			fStrStatus = "CPU Normal      ";
		}
		if(fInputDelay <= 8)
		{
			fStrStatus = "CPU OverLoaded!!";
		}
		if(fSetItemVal > 2)
		{
			fSetItemVal = 0;
		}
	}
	if(GetAsyncKeyState('W'))
	{
		fInputDelay++;
		if(fInputDelay == fMaxInputDelay)
		{
			fSetItemVal--;
			fInputDelay = 0;
		}
		if(fSetItemVal < 0)
		{
			fSetItemVal = 2;
		}
	}
	  if(fSetItemVal == 0)
	  {
	  	fItCol0 = 15;
	  	fItCol1 = 0;
	  	fItCol2 = 0;
	  }
	  if(fSetItemVal == 1)
	  {
	  	fItCol0 = 0;
	  	fItCol1 = 15;
	  	fItCol2 = 0;
	  }
	  if(fSetItemVal == 2)
	  {
	  	fItCol0 = 0;
	  	fItCol1 = 0;
	  	fItCol2 = 15;
	  } 
   }
    if(fGPURender)
    {
    	ConsoleFullScreen(GetConsoleWindow(),3);
      for(int64_t fRandomVec = 1;fRandomVec <= (fMaxTime * 3600);fRandomVec++)
   {
   	    //cls(fHandle);
   	    //fCurrentFrameRate = fPart / fSec;
   	    SetWindowText(hWCon,("[Engine: RenderScreen:"+to_string(fX)+"X"+to_string(fY)+" Pixels:"+to_string(fPart)+"]").c_str());
   	    if(fXR += fXR){fPart++;}
   	    if(fYR += fYR){fPart++;}
   //	ofstream fRenderList("ConGLRender.log");
   //	fRenderList.is_open();
   //	fRenderList<<"[ENGINE][X = "<<fX<<" : Y = "<<fY<<"]"<<"ColorREF = "<<RGB(fRandR,fRandG,fRandB)<<"[R("<<fRandR<<"),G("<<fRandG<<"),B("<<fRandB<<")]\n
   		fXR = rand() % fScreenX;
   	    fYR = rand() % fScreenY;
   	    fScreenX = fX;
   	    fScreenY = fY;
  	    fRed = rand() % 255;
  	    fGreen = rand() % 255;
  	    fBlue = rand() % 255;
  	    if(fGPUThreads == 0)
  	    {
  	    	cls(hCon);
  	    	cout<<"[Error] Render not Selected!!"<<endl;
  	    	cout<<" return to "<<fRandomVec<<"/"<<fMaxTime<<"ms"<<endl;
  	    	fPart  = 0;
		  }
   	    if(fGPUThreads == 1)
   	    {
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
		}
		if(fGPUThreads == 2)
   	    {
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
		}
		if(fGPUThreads == 3)
   	    {
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
		}
		if(fGPUThreads == 4)
   	    {
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
   	    	SetPixel(fDC,fXR,fYR,RGB(fRed,fGreen,fBlue));
		}
   	    if(GetAsyncKeyState(VK_ESCAPE))
   	    {
   	    	fRandomVec = -1;
   	    	fGPURender = false;
		}
   }
     fGPURender = false;
	}
}
}
