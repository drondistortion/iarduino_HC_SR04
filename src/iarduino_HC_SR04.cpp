#include "iarduino_HC_SR04.h"
//		������������� ������
		iarduino_HC_SR04::iarduino_HC_SR04(uint8_t i, uint8_t j){	//	i: � ������ TRIG, j: � ������ ECHO)
		pinTRIG=i; pinMode(pinTRIG, OUTPUT);						//	��������� � ������ TRIG � ������������� ��� ����� ������ �� �����
		pinECHO=j; pinMode(pinECHO, INPUT );						//	��������� � ������ ECHO � ������������� ��� ����� ������ �� ����
		digitalWrite(pinTRIG, LOW);									//	������������� ������� ����������� �0� �� ������ TRIG
}
//		����������� ����������
long	iarduino_HC_SR04::distance(int8_t i){						//	i: ������� ����������� � �C
		long		j=funDuration();								//	��������� ������������ �������� �� ������ ECHO
		if(j<400){	j=funDuration();}								//	�������� ��������� ������������ �������� (��� ���������� "������" ��������� ��������)
					j=j*sqrt(273+i)/1000;							//	���������� ����������: L = Echo * ������(t+273) / 1000
		if(j>400){	j=400;}											//	�������������� ����������� ���������� �����������
		if(averaging<=0){valDATA=float(j);}else{					//	���� ���������� ���������� �� ���������, �� ������� ��������� � ���� ��������� ���������, ����� ...
			valDATA *= float(averaging);							//	�������� ���������� ��������� �� ����������� ���������� - 1
			valDATA += j;											//	��������� � ����������� �������� ������� ���������
			valDATA /= float(averaging)+1.0;						//	����� ���������� �������� �� ����������� ����������
		}															//
		return long(valDATA);										//	������� ���������
}
//		����������� ������������
long	iarduino_HC_SR04::funDuration(){
		digitalWrite(pinTRIG, HIGH);								//	������������� ������� ���������� �1� �� ������ TRIG
		delayMicroseconds(10);										//	��� 10 ���
		digitalWrite(pinTRIG, LOW);									//	������������� ������� ����������� �0� �� ������ TRIG
		return pulseIn(pinECHO, HIGH);								//	��������� ������������ �������� �� ������ ECHO
}
