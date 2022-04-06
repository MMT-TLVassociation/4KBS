// IB25Decoder.h: IB25Decoder �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////


#pragma once


/////////////////////////////////////////////////////////////////////////////
// �萔��`
/////////////////////////////////////////////////////////////////////////////

#define TS_INVALID_PID	0xFFFFU		// ����PID


/////////////////////////////////////////////////////////////////////////////
// B25�f�R�[�_�C���^�t�F�[�X
/////////////////////////////////////////////////////////////////////////////

class IB25Decoder
{
public:
	virtual const BOOL Initialize(DWORD dwRound = 4) = 0;
	virtual void Release(void) = 0;

	virtual const BOOL Decode(BYTE *pSrcBuf, const DWORD dwSrcSize, BYTE **ppDstBuf, DWORD *pdwDstSize) = 0;
	virtual const BOOL Flush(BYTE **ppDstBuf, DWORD *pdwDstSize) = 0;
	virtual const BOOL Reset(void) = 0;
};


/////////////////////////////////////////////////////////////////////////////
// B25�f�R�[�_�C���^�t�F�[�X2
/////////////////////////////////////////////////////////////////////////////

class IB25Decoder2	: public IB25Decoder
{
public:
	enum	// GetDescramblerState() ���^�[���R�[�h
	{
		DS_NO_ERROR			= 0x00000000UL,		// �G���[�Ȃ�����
		DS_BCAS_ERROR		= 0x00000001UL,		// B-CAS�J�[�h�G���[
		DS_NOT_CONTRACTED	= 0x00000002UL		// �������_��
	};

	virtual void DiscardNullPacket(const bool bEnable = true) = 0;
	virtual void DiscardScramblePacket(const bool bEnable = true) = 0;
	virtual void EnableEmmProcess(const bool bEnable = true) = 0;

	virtual const DWORD GetDescramblingState(const WORD wProgramID) const = 0;

	virtual void ResetStatistics(void) = 0;

	virtual const DWORD GetPacketStride(void) const = 0;
	virtual const DWORD GetInputPacketNum(const WORD wPID = TS_INVALID_PID) const = 0;
	virtual const DWORD GetOutputPacketNum(const WORD wPID = TS_INVALID_PID) const = 0;
	virtual const DWORD GetSyncErrNum(void) const = 0;
	virtual const DWORD GetFormatErrNum(void) const = 0;
	virtual const DWORD GetTransportErrNum(void) const = 0;
	virtual const DWORD GetContinuityErrNum(const WORD wPID = TS_INVALID_PID) const = 0;
	virtual const DWORD GetScramblePacketNum(const WORD wPID = TS_INVALID_PID) const = 0;
	virtual const DWORD GetEcmProcessNum(void) const = 0;
	virtual const DWORD GetEmmProcessNum(void) const = 0;
};




// �C���X�^���X�������\�b�h
extern "C" __declspec(dllimport) IB25Decoder * CreateB25Decoder(void);
