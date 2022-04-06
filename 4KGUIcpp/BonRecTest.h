#pragma once

class CBonRecTest
{
public:
	CBonRecTest();
	~CBonRecTest();
	bool Start();
	bool Stop();
	void RecMain();
	void StopRec();

	LPCTSTR bonDriverPath;
	LPCTSTR decoderPath;
	LPCTSTR outputPath;
	DWORD space;
	DWORD channel;
	bool emm;
	bool log;

private:
	void LoadBonDriver();
	void UnloadBonDriver();
	void LoadDecoder();
	void UnloadDecoder();
	void OpenOutput();
	void CloseOutput();
	void OpenTuner();
	void CloseTuner();
	void StartThread();
	void StopThread();

	static unsigned int __stdcall RecThread(void *param);
	//void RecMain();

	HMODULE hBonDriver;
	HMODULE hDecoder;
	IBonDriver2 *pBonDriver2;
	IB25Decoder2 *pDecoder2;
	HANDLE hRecThread;
	HANDLE hOutput;
	bool isThreadWorking;
};
