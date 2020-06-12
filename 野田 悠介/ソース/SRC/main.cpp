#include"numDecision.h"
#include"struct.h"
#include"Scene/GameScene/gameScene.h"
#include"Scene/TitleScene/titleScene.h"
#include"Scene/LoseResultScene/LoseResult.h"
#include"Scene/SceneManeger/sceneManeger.h"
#include"Sound/SoundBase/soundBase.h"
#include"Sound/SoundBase/soundBase.h"
#include"Wavread/wavread.h"

#pragma comment(lib,"dsound.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

LPDIRECT3D9				lpD3D;		// Direct3D�C���^�[�t�F�C�X

LPDIRECT3DDEVICE9		lpD3DDevice;	// Direct3DDevice�C���^�[�t�F�C�X

D3DPRESENT_PARAMETERS d3dpp;


// ���_�t�H�[�}�b�g�̒�`


////  �O���[�o���ϐ��錾

LPD3DXSPRITE lpSprite;	// �X�v���C�g
LPD3DXFONT lpFont;		// �t�H���g
bool gameFullScreen;	// �t���X�N���[���itrue,false)

C_SceneManeger  sceneManeger;
HWND hwnd;



//���֌W
LPDIRECTSOUND8 lpDSound;	//DirectSound�I�u�W�F�N�g
LPDIRECTSOUNDBUFFER lpSPrimary;

void LoadWAVE3D(LPDIRECTSOUNDBUFFER8& pDSData, LPDIRECTSOUND3DBUFFER8& pDSData3D, const char* fname)
{
	HRESULT hr;

	// WAVE�t�@�C�����J��
	CWaveSoundRead WaveFile;
	WaveFile.Open((char*)fname);

	// �Z�J���_���E�o�b�t�@���쐬����
	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsbdesc;
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC);

	//(DSBCAPS_CTRL3D=�R�c�T�E���h���g�p)
	dsbdesc.dwFlags = DSBCAPS_GETCURRENTPOSITION2 | DSBCAPS_GLOBALFOCUS | DSBCAPS_CTRL3D |
		DSBCAPS_CTRLVOLUME | /*DSBCAPS_CTRLPAN |*/ DSBCAPS_CTRLFREQUENCY;
	dsbdesc.dwBufferBytes = WaveFile.m_ckIn.cksize;
	dsbdesc.lpwfxFormat = WaveFile.m_pwfx;

	//3D�T�E���h��HEL�A���S���Y����I��
	dsbdesc.guid3DAlgorithm = DS3DALG_NO_VIRTUALIZATION;
	//	dsbdesc.guid3DAlgorithm=DS3DALG_DEFAULT;

		// �o�b�t�@�����
	LPDIRECTSOUNDBUFFER pDSTmp;
	//	lpDSound->CreateSoundBuffer(&dsbdesc, &pDSData, NULL); 
	lpDSound->CreateSoundBuffer(&dsbdesc, &pDSTmp, NULL);
	pDSTmp->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&pDSData);
	pDSTmp->Release();

	// �Z�J���_���E�o�b�t�@��Wave�f�[�^����������
	LPVOID lpvPtr1;		// �ŏ��̃u���b�N�̃|�C���^
	DWORD dwBytes1;		// �ŏ��̃u���b�N�̃T�C�Y
	LPVOID lpvPtr2;		// �Q�Ԗڂ̃u���b�N�̃|�C���^
	DWORD dwBytes2;		// �Q�Ԗڂ̃u���b�N�̃T�C�Y

	hr = pDSData->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);

	// DSERR_BUFFERLOST���Ԃ��ꂽ�ꍇ�CRestore���\�b�h���g���ăo�b�t�@�𕜌�����
	if (DSERR_BUFFERLOST == hr)
	{
		pDSData->Restore();
		hr = pDSData->Lock(0, WaveFile.m_ckIn.cksize, &lpvPtr1, &dwBytes1, &lpvPtr2, &dwBytes2, 0);
	}
	if (SUCCEEDED(hr))
	{
		// ���b�N����

		// �����ŁC�o�b�t�@�ɏ�������
		// �o�b�t�@�Ƀf�[�^���R�s�[����
		UINT rsize;
		WaveFile.Read(dwBytes1, (LPBYTE)lpvPtr1, &rsize);
		if (0 != dwBytes2)
			WaveFile.Read(dwBytes2, (LPBYTE)lpvPtr2, &rsize);

		// �������݂��I������炷����Unlock����D
		hr = pDSData->Unlock(lpvPtr1, dwBytes1, lpvPtr2, dwBytes2);
	}

	//3D�̃Z�J���_���o�b�t�@�����
	pDSData->QueryInterface(IID_IDirectSound3DBuffer8, (LPVOID*)&pDSData3D);
}

void DrawMesh(XFILE *XFile)
{
	for (DWORD i = 0; i < XFile->NumMaterial; i++)
	{
		lpD3DDevice->SetMaterial(&(XFile->Mat[i]));

		lpD3DDevice->SetTexture(0, XFile->Tex[i]);

		XFile->lpMesh->DrawSubset(i);
		//i�Ԗڂ̃O���[�v��\��
	}
}

//�J���[�Ή���DrawMesh�֐�------------------------
void DrawMesh(XFILE* XFile,Color rgb)
{
	D3DMATERIAL9 Mat;
	for (DWORD i = 0; i < XFile->NumMaterial; i++)
	{
		//��U�F���R�s�[
		Mat = XFile->Mat[i];
		//Alpha�l��������
		//rgb�������邱�Ƃ��ł���
		Mat.Diffuse.r = rgb.r;
		Mat.Diffuse.g = rgb.g;
		Mat.Diffuse.b = rgb.b;

		lpD3DDevice->SetMaterial(&Mat);

		lpD3DDevice->SetTexture(0, XFile->Tex[i]);

		XFile->lpMesh->DrawSubset(i);
		//i�Ԗڂ̃O���[�v��\��
	}
}
//----------------------------------------------------
void LoadMesh(struct XFILE *XFile, const char FName[])
{
	LPD3DXBUFFER lpD3DXBuffer;
	
	D3DXLoadMeshFromX(FName, D3DXMESH_MANAGED, lpD3DDevice, NULL, &lpD3DXBuffer, NULL, &(XFile->NumMaterial), &(XFile->lpMesh));

	XFile->Mat = new D3DMATERIAL9[XFile->NumMaterial];
	XFile->Tex = new LPDIRECT3DTEXTURE9[XFile->NumMaterial];

	D3DXMATERIAL* D3DXMat = (D3DXMATERIAL*)lpD3DXBuffer->GetBufferPointer();

	DWORD i;
	for (i = 0; i < XFile->NumMaterial; i++) {
		XFile->Mat[i] = D3DXMat[i].MatD3D;
		XFile->Mat[i].Ambient = XFile->Mat[i].Diffuse;
		if (FAILED(D3DXCreateTextureFromFile(lpD3DDevice, D3DXMat[i].pTextureFilename, &(XFile->Tex[i])))) {
			XFile->Tex[i] = NULL;
		}
	}

	lpD3DXBuffer->Release();
}


void ReleaseMesh(struct XFILE *XFile)
{
	if (XFile->lpMesh != NULL) {
		DWORD i;

		delete[] XFile->Mat;
		for (i = 0; i < XFile->NumMaterial; i++) {
			if (XFile->Tex[i] != NULL) {
				XFile->Tex[i]->Release();
				XFile->Tex[i] = NULL;
			}
		}
		delete[] XFile->Tex;
		XFile->lpMesh->Release();

		XFile->lpMesh = NULL;
	}
}


//�x�N�g���̊p�x�����߂�
float GetVecAng(D3DXVECTOR3 Vec)
{
	Vec.y = 0;
	D3DXVec3Normalize(&Vec, &Vec);
	float Dot;
	Dot = D3DXVec3Dot(&D3DXVECTOR3(0.0f, 0.0f, 1.0f), &Vec);
	if (Dot > 1)Dot = 1;
	if (Dot < -1)Dot = -1;
	double Ang;
	Ang = D3DXToDegree(acos(Dot));
	if (Vec.x < 0)Ang *= -1;
	return (float)Ang;
}

//�Ώۂ̊p�x�Ɍ����Ĉ��̊p�x����]����
float TurnToAng(D3DXMATRIX* Mat, float TargetAng, float PlusAng)
{
	float NowAng;
	D3DXVECTOR3 NowVec;
	D3DXVec3TransformNormal(&NowVec, &D3DXVECTOR3(0, 0, 1), Mat);
	NowAng = GetVecAng(NowVec);

	float LastAng = TargetAng - NowAng;

	//+-180�͈̔͂ɂ���
	if (LastAng < -180)LastAng += 360;
	if (LastAng > 180)LastAng -= 360;

	D3DXMATRIX TmpMat;

	if (LastAng > PlusAng)//1��̑����ȏ�̊p�x���c����Ă���
	{
		D3DXMatrixRotationY(&TmpMat, D3DXToRadian(PlusAng));
		LastAng -= PlusAng;
	}
	else
	{
		if (LastAng < -PlusAng)
		{
			D3DXMatrixRotationY(&TmpMat, D3DXToRadian(-PlusAng));
			LastAng += PlusAng;
		}
		else
		{
			D3DXMatrixRotationY(&TmpMat, D3DXToRadian(LastAng));
			LastAng = 0;
		}
	}

	*Mat = TmpMat * *Mat;

	return LastAng;
}




LRESULT APIENTRY WndFunc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_ESCAPE:
			/*PostQuitMessage(0);*/
			return 0;
		}
		return 0;

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);

}

void LoadTexture(LPDIRECT3DTEXTURE9 *lpTex, const char fname[], int W, int H, D3DCOLOR Color)
{
	if (W == 0)W = D3DX_DEFAULT;
	if (H == 0)H = D3DX_DEFAULT;
	D3DXCreateTextureFromFileEx(lpD3DDevice, fname, W, H, 1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT, Color, NULL, NULL, lpTex);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev,
	LPSTR lpszCmdParam, int nCmdshow)
{
	MSG msg;


	WNDCLASS wc;
	char szAppName[] = "Generic Game SDK Window";

	wc.style = CS_DBLCLKS;
	wc.lpfnWndProc = WndFunc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;

	RegisterClass(&wc);

	hwnd = CreateWindowEx(
		0,
		szAppName,
		"����",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCRW, SCRH,
		NULL, NULL, hInst,
		NULL);

	if (!hwnd)return FALSE;

	ShowWindow(hwnd, nCmdshow);
	UpdateWindow(hwnd);
	SetFocus(hwnd);

	gameFullScreen = false;	// �E�B���h�E���[�h
	//�t���X�N���[���ւ̐؂�ւ�
    //MB_�̓��b�Z�[�W�{�b�N�X                                            //2�߂̃{�^�����f�t�H���g�ɂ���
	if (MessageBox(NULL, "�t���X�N���[���ɂ��܂����H", "�N���m�F", MB_YESNO|MB_DEFBUTTON2 | MB_ICONQUESTION ) == IDYES)
	{
		gameFullScreen = true;
	}
	if (gameFullScreen) {
	}
	else {
		RECT rc = { 0,0,SCRW,SCRH };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(hwnd, NULL, 50, 50, rc.right - rc.left, rc.bottom - rc.top, SWP_SHOWWINDOW | SWP_NOZORDER);
	}

	//---------------------DirectX Graphics�֘A-----------------------

	// Direct3D �I�u�W�F�N�g���쐬
	lpD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (!lpD3D)
	{
		// �I�u�W�F�N�g�쐬���s
		MessageBox(NULL, "Direct3D �̍쐬�Ɏ��s���܂����B", "ERROR", MB_OK | MB_ICONSTOP);
		// �I������
		return 0;
	}
	int adapter;

	// �g�p����A�_�v�^�ԍ�
	adapter = D3DADAPTER_DEFAULT;

	// �E�C���h�E�̍쐬�����������̂ŁADirect3D ������������
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	// Direct3D �������p�����[�^�̐ݒ�
	if (gameFullScreen)
	{
		// �t���X�N���[�� : �قƂ�ǂ̃A�_�v�^�ŃT�|�[�g����Ă���t�H�[�}�b�g���g�p
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	}
	else
	{
		// �E�C���h�E : ���݂̉�ʃ��[�h���g�p
		D3DDISPLAYMODE disp;
		// ���݂̉�ʃ��[�h���擾
		lpD3D->GetAdapterDisplayMode(adapter, &disp);
		d3dpp.BackBufferFormat = disp.Format;
	}
	// �\���̈�T�C�Y�̐ݒ�
	d3dpp.BackBufferWidth = SCRW;
	d3dpp.BackBufferHeight = SCRH;
	d3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;

	if (!gameFullScreen)
	{
		// �E�C���h�E���[�h
		d3dpp.Windowed = 1;
	}

	// Z �o�b�t�@�̎����쐬
	d3dpp.EnableAutoDepthStencil = 1;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	//�ޯ��ޯ̧��ۯ��\�ɂ���(GetDC���\�ɂȂ�)
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	// �f�o�C�X�̍쐬 - T&L HAL
	if (FAILED(lpD3D->CreateDevice(adapter, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice)))
	{
		// ���s�����̂� HAL �Ŏ��s
		if (FAILED(lpD3D->CreateDevice(adapter, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice)))
		{
			// ���s�����̂� REF �Ŏ��s
			if (FAILED(lpD3D->CreateDevice(adapter, D3DDEVTYPE_REF, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &lpD3DDevice)))
			{
				// ���ǎ��s����
				MessageBox(NULL, "DirectX9���������ł��܂���B\n���Ή��̃p�\�R���Ǝv���܂��B", "ERROR", MB_OK | MB_ICONSTOP);
				lpD3D->Release();
				// �I������
				return 0;
			}
		}
	}

	// �����_�����O�E�X�e�[�g��ݒ�
	// Z �o�b�t�@�L����->�O��֌W�̌v�Z�𐳊m�ɂ��Ă����
	lpD3DDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// �A���t�@�u�����f�B���O�L����
	lpD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	// �A���t�@�u�����f�B���O���@��ݒ�
	lpD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	lpD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// �����_�����O���̃A���t�@�l�̌v�Z���@�̐ݒ�
	lpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	// �e�N�X�`���̐F���g�p
	lpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	// ���_�̐F���g�p
	lpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	// �����_�����O���̐F�̌v�Z���@�̐ݒ�
	lpD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	//���ʃJ�����O
	lpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	// �t�B���^�ݒ�
	lpD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	lpD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	lpD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	
	lpD3DDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);
	//�\���Ɋւ���ݒ��ύX����֐�

	

	// ���_�t�H�[�}�b�g�̐ݒ�
	lpD3DDevice->SetFVF(FVF_VERTEX);

	timeBeginPeriod(1);

	// �Q�[���Ɋւ��鏉�������� ---------------------------
	srand(time(0));

	C_SceneBase SoundBase;
	//---------------------DirectSound�֘A-----------------------
	DirectSoundCreate8(NULL, &lpDSound, NULL);

	//�������x����ݒ�
	lpDSound->SetCooperativeLevel(hwnd, DSSCL_PRIORITY);

	// �v���C�}���E�o�b�t�@�̍쐬
	// DSBUFFERDESC�\���̂�ݒ�
	DSBUFFERDESC dsbdesc;
	ZeroMemory(&dsbdesc, sizeof(DSBUFFERDESC));
	dsbdesc.dwSize = sizeof(DSBUFFERDESC);
	// �v���C�}���E�o�b�t�@���w��
	dsbdesc.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_CTRL3D | DSBCAPS_PRIMARYBUFFER;
	dsbdesc.dwBufferBytes = 0;
	dsbdesc.lpwfxFormat = NULL;

	// �o�b�t�@�����
	lpDSound->CreateSoundBuffer(&dsbdesc, &lpSPrimary, NULL);

	// �v���C�}���E�o�b�t�@��Wave�t�H�[�}�b�g��ݒ�
	// �@�@�@�D�拦�����x���ȏ�̋������x�����ݒ肳��Ă���K�v������܂��D
	WAVEFORMATEX pcmwf;
	ZeroMemory(&pcmwf, sizeof(WAVEFORMATEX));
	pcmwf.wFormatTag = WAVE_FORMAT_PCM;
	pcmwf.nChannels = 2;		// �Q�`�����l���i�X�e���I�j
	pcmwf.nSamplesPerSec = 44100;	// �T���v�����O�E���[�g�@44.1kHz
	pcmwf.nBlockAlign = 4;
	pcmwf.nAvgBytesPerSec = pcmwf.nSamplesPerSec * pcmwf.nBlockAlign;
	pcmwf.wBitsPerSample = 16;		// 16�r�b�g
	lpSPrimary->SetFormat(&pcmwf);

	CoInitialize(NULL);

	// �X�v���C�g�쐬
	D3DXCreateSprite(lpD3DDevice, &lpSprite);
	lpSprite->OnResetDevice();

	// �t�H���g�쐬
	D3DXCreateFont(lpD3DDevice, 20, 20, FW_REGULAR, NULL, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, PROOF_QUALITY, FIXED_PITCH | FF_MODERN, "�l�r �S�V�b�N", &lpFont);

	lpFont->OnResetDevice();
	sceneManeger.ChangScene(new C_Title());
	while (1) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0))
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			sceneManeger.NowScene();
		}
	}

	// �Q�[���Ɋւ���I������ ---------------------------



	lpSprite->Release();	// �X�v���C�g
	lpFont->Release();		// �t�H���g


	timeEndPeriod(1);

	// Direct3D �I�u�W�F�N�g�����
	lpD3DDevice->Release();
	lpD3D->Release();

	return (int)msg.wParam;
}