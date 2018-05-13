#pragma once

#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <cstdlib>
#include <cstdio> 

using namespace std;

typedef char Byte;
typedef int Int32;
typedef short Int16;
typedef unsigned int UInt32;
typedef unsigned short UInt16;

class LoadWaveFile
{

public:
	Byte RIFF[4] = { 0x52, 0x49, 0x46, 0x46 };
	Byte WAVE[4] = { 0x57, 0x41, 0x56, 0x45 };
	Byte fmt[4] = { 0x66, 0x6D, 0x74, 0x20 };
	Byte data[4] = { 0x64, 0x61, 0x74, 0x61 };
	Byte wFomatTag[2] = { 0x01, 0x00 };

	int LoadFile(string path)
	{
		WaveFileProperty16bit property = WaveFileProperty16bit();

		fstream fs;
		fs.open(path, ios::in | ios::binary);

		if (!fs.is_open())
		{
			return EXIT_FAILURE;
		}

		Byte byte_16[2];
		Byte byte_32[4];

		//RIFF(捨てる)
		fs.read(byte_32, 4);

		//ファイルのサイズ
		fs.read(byte_32, 4);
	}
};

class WaveFileProperty16bit
{
public:
	Int32 m_FileSize;
	Int32 m_PCMWAVEFORMAT_Size;
	WAVEFORMATEX m_WaveFormatEx;
	MusicData16bit m_MusicData;
};

struct MusicData16bit
{
public:
	Int32 m_DataSize;
	vector<Int16> m_Data;
};

struct MusicData8bit
{
public:
	Int32 m_DataSize;
	vector<Byte> m_Data;
};

class WAVEFORMATEX
{
public:
	Int16 wFormatTag;
	UInt16 nChannels;
	UInt32 nSamplesPerSec;
	UInt32 nAvgBytePerSec;
	UInt16 nBlockAlign;
	UInt16 wBitsPerSample;

	WAVEFORMATEX()
	{
		wFormatTag = 1;
		nChannels = 1;
		nSamplesPerSec = 44100;
		nAvgBytePerSec = 11025;
		nBlockAlign = 1;
		wBitsPerSample = 8;
	}
};
