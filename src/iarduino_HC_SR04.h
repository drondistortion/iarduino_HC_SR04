//	���������� ��� ������ � �������������� �������� ���������� HC-SR04: http://iarduino.ru/shop/Sensory-Datchiki/ultrazvukovogo-datchika-hc-sr04-rasstoyaniya-dvizheniya.html
//  ������: 1.0.1 (��� ����������)
//  ��������� ������ ���������� �� ������ ������� �� ������: http://iarduino.ru/file/17.html
//  ��������� �������� ������� ����������� �������� �� ������: http://wiki.iarduino.ru/page/ultrazvukovoy-datchik-izmereniya-rasstoyaniya-hc-sr04/
//  ���������� �������� �������������� �������� �������� iarduino.ru � ����� �������� �������������� � ����������������!
//  ��� ���������� ��������� ��� ������� � �������������� ������ ����������, ��� �������, ��� � � ������,
//  � ��� ����� � � �������������� �����, ������ ��� ������������ ������: http://iarduino.ru
//  ����� ����������: ������� �����
//  ���� � ��� �������� ����������� �������, �������� ���: shop@iarduino.ru

#ifndef iarduino_HC_SR04_h
#define iarduino_HC_SR04_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class	iarduino_HC_SR04{
	public:		iarduino_HC_SR04(uint8_t, uint8_t);	//	������������� ������				(����� TRIG, ����� ECHO)
		long	distance		(int8_t=23);		//	����������� ����������				([t�C])
		long	averaging = 0;						//	����������� ���������� ���������	(0-��� ����������, 1-����������� ����������, ... 100-������� ����������, ... 2147483648-����� ���� ��������� ������ �� ��������)
	private:
		long	funDuration	();						//	����������� ������������ �������� ECHO
		uint8_t	pinTRIG;							//	����� ������ ������������� � TRIG
		uint8_t	pinECHO;							//	����� ������ ������������� � ECHO
		float	valDATA;							//	���������� ��� �������� ������
};

#endif
