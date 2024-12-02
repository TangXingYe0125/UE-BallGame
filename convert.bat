%~d0
cd %~dp0

set NAME=UeL1_MiniGame

ren UeBasic.sln %NAME%.sln
ren UeBasic.uproject %NAME%.uproject
cd Source\
ren UeBasic.Target.cs %NAME%.Target.cs
ren UeBasicEditor.Target.cs %NAME%Editor.Target.cs
ren UeBasic %NAME%
cd %NAME%\
ren UeBasic.Build.cs %NAME%.Build.cs
ren UeBasic.cpp %NAME%.cpp
ren UeBasic.h %NAME%.h
ren UeBasicGameModeBase.cpp %NAME%GameModeBase.cpp
ren UeBasicGameModeBase.h %NAME%GameModeBase.h

rem 1) 上記 NAME= の後を目的のプロジェクト名にし、このバッチを実行
rem 2) Source フォルダ下でテキストエディタ等を使って、UeBasic 文字列を %NAME% に一括置換する
rem 3) UEBASIC_API も %NAME%（全て大文字）_API に置き換える
rem 4) .uproject もテキストエディタ等を使って、UeBasic 文字列を %NAME% に一括置換する
rem 5) .sln は、一度削除して、.uproject 右クリック、"Generate Visual Studio project files" を行う