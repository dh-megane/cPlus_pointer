// MakeDoubleSize.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *pInFile = NULL;
	char *szInFileName = NULL;
	size_t size_tFileSize = 0;
	FILE *pOutFile = NULL;
	char *szOutFileName = NULL;
	char *pvWriteData = NULL;
	char *pvReadData = NULL;
	char *szAddName = (char*)".double";

	if (argc != 2)
	{
		printf("引数の数が違います。\n");
		return -1;
	}

	szInFileName = argv[1];
	printf("入力ファイル名:%s\n", szInFileName);
	pInFile = fopen(szInFileName, "rb");
	if (pInFile == NULL)
	{
		printf("InFileのfopenがNULLをリターン。\n");
		return -1;
	}

	fseek(pInFile, 0, SEEK_END);
	size_tFileSize = ftell(pInFile);

	printf("ファイルのサイズ：%dバイト\n", size_tFileSize);

	pvReadData = (char*)malloc(size_tFileSize);

	if (pvReadData == NULL)
	{
		printf("読み込み用mallocがNULLをリターン。\n");
		fclose(pInFile);
		return -1;
	}

	fseek(pInFile, 0, SEEK_SET);
	fread(pvReadData, sizeof(char), size_tFileSize, pInFile);
	fclose(pInFile);

	pvWriteData = (char*)malloc(size_tFileSize * 2);
	if (pvWriteData == NULL)
	{
		printf("書き込み用mallocがNULLをリターン。\n");
		free(pvReadData);
		return -1;
	}

	memcpy(pvWriteData, pvReadData, size_tFileSize);
	memcpy(pvWriteData + size_tFileSize, pvReadData, size_tFileSize);

	free(pvReadData);

	szOutFileName = (char*)malloc(strlen(szInFileName) + strlen(szAddName) + 1);
	if (szOutFileName == NULL)
	{
		printf("書き込みファイル名用mallocがNULLをリターン。\n");
		free(pvWriteData);
		return -1;
	}

	strcpy(szOutFileName, szInFileName);
	strcpy(szOutFileName + strlen(szInFileName), szAddName);
	printf("書き込みファイル名：%s<\n", szOutFileName);

	pOutFile = fopen(szOutFileName, "wb");
	if (pOutFile == NULL)
	{
		printf("OutFileのfopenがNULLをリターン。\n");
		free(szOutFileName);
		free(pvWriteData);
		return -1;
	}

	fwrite(pvWriteData, sizeof(char), size_tFileSize * 2, pOutFile);
	fclose(pOutFile);

	free(szOutFileName);
	free(pvWriteData);

	return 0;

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
