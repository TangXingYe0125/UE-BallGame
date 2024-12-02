%~d0
cd %~dp0

set NAME_SRC=UeL1_MiniGame
set NAME_DST=Ue_MiniGameV1

ren %NAME_SRC%.sln %NAME_DST%.sln
ren %NAME_SRC%.uproject %NAME_DST%.uproject
cd Source\
ren %NAME_SRC%.Target.cs %NAME_DST%.Target.cs
ren %NAME_SRC%Editor.Target.cs %NAME_DST%Editor.Target.cs
ren %NAME_SRC% %NAME_DST%
cd %NAME_DST%\
ren %NAME_SRC%.Build.cs %NAME_DST%.Build.cs
ren %NAME_SRC%.cpp %NAME_DST%.cpp
ren %NAME_SRC%.h %NAME_DST%.h
ren %NAME_SRC%GameModeBase.cpp %NAME_DST%GameModeBase.cpp
ren %NAME_SRC%GameModeBase.h %NAME_DST%GameModeBase.h

rem 1) NAME_SRC を元の名前、NAME_DST を改名後の名前にし、このバッチを実行
rem 2) Source フォルダ下でテキストエディタ等を使って、NAME_SRC 文字列を NAME_DST に一括置換する
rem 3) %NAME_SRC%_API も %NAME_DST%_API（全て大文字）に置き換える
rem 4) .uproject もテキストエディタ等を使って、NAME_SRC 文字列を NAME_DST に一括置換する
rem 5) .sln は、一度削除して、.uproject 右クリック、"Generate Visual Studio project files" を行う