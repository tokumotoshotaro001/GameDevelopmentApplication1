#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//メイン関数（プログラムはここから始まります）
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Windowモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドウサイズ（横：６４０px、縦：４８０px）を設定
	SetGraphMode(640, 480, 32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//異常を検知
		return -1;
	}

	//ローカル変数定義
	Scene* scene = new Scene();
	int result = 0;

	//描画先を裏画面から始めるように指定する
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		//シーンの初期化
		scene->Initialize();

		//メインループ（ウインドウの異常発生orESCキーが押されたら、ループ終了）
		while (ProcessMessage() != -1 && CheckHitKey(KEY_INPUT_ESCAPE) != TRUE)
		{
			//入力機能の更新
			InputControl::Update();

			//画面の初期化
			ClearDrawScreen();

			//シーンの描画処理
			scene->Draw();

			//裏画面の内容を表画面に反映する
			ScreenFlip();
		}
	}
	catch (const char* error_log)
	{
		//エラー情報をLog.txtに出力する
		OutputDebugString(error_log);
		//異常状態に変更する
		result = -1;
	}

	//シーン情報を削除する
	if (scene != nullptr);
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}
	
	//DXライブラリの終了処理
	DxLib_End();

	//終了状態を維持
	return result;
}