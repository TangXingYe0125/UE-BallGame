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

rem 1) NAME_SRC �����̖��O�ANAME_DST ��������̖��O�ɂ��A���̃o�b�`�����s
rem 2) Source �t�H���_���Ńe�L�X�g�G�f�B�^�����g���āANAME_SRC ������� NAME_DST �Ɉꊇ�u������
rem 3) %NAME_SRC%_API �� %NAME_DST%_API�i�S�đ啶���j�ɒu��������
rem 4) .uproject ���e�L�X�g�G�f�B�^�����g���āANAME_SRC ������� NAME_DST �Ɉꊇ�u������
rem 5) .sln �́A��x�폜���āA.uproject �E�N���b�N�A"Generate Visual Studio project files" ���s��