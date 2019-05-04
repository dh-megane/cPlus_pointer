// Swap.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

void swap(int *piData1, int *piData2);

int main()
{
	int iA = 100;
	int iB = 200;

	printf("iAの値：%d\n", iA);
	printf("iBの値：%d\n", iB);

	swap(&iA, &iB);

	printf("iAの値：%d\n", iA);
	printf("iBの値：%d\n", iB);

	return 0;
}

void swap(int *piData1, int *piData2)
{
	int iTmp;

	iTmp = *piData1;

	*piData1 = *piData2;

	*piData2 = iTmp;

	return;

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
