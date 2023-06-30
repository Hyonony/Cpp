// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// DYNAMIC2_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.

#pragma once

#ifdef DYNAMIC_EXPORTS
#define DYNAMIC_API __declspec(dllexport)
#else
#define DYNAMIC_API __declspec(dllimport)
#endif

// �� Ŭ������ Dynamic2.dll���� ������ ���Դϴ�.
class DYNAMIC_API CDynamic {
public:
	CDynamic(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};

extern DYNAMIC_API int nDynamic;

DYNAMIC_API int fnDynamic(void);
