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

rem 1) ��L NAME= �̌��ړI�̃v���W�F�N�g���ɂ��A���̃o�b�`�����s
rem 2) Source �t�H���_���Ńe�L�X�g�G�f�B�^�����g���āAUeBasic ������� %NAME% �Ɉꊇ�u������
rem 3) UEBASIC_API �� %NAME%�i�S�đ啶���j_API �ɒu��������
rem 4) .uproject ���e�L�X�g�G�f�B�^�����g���āAUeBasic ������� %NAME% �Ɉꊇ�u������
rem 5) .sln �́A��x�폜���āA.uproject �E�N���b�N�A"Generate Visual Studio project files" ���s��