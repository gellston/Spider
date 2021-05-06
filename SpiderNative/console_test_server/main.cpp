#include "SpiderIPC.h"


#include <thread>
#include <chrono>   

#include <iostream>
#include <stdio.h>

#include <cstdlib>
#include <ctime>
#include <random>

#pragma warning(disable:4996) 

int main() {

	spider::function notifier("test");
	notifier
		.delay(10)
		.args()
		.arg<int>("argument1")
		.arg<int>("argument2")
		.returns()
		.ret<int>("returnValue")
		.complete();


	// �õ尪�� ��� ���� random_device ����.
	std::random_device rd;

	// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());

	// 0 ���� 99 ���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
	std::uniform_int_distribution<int> dis(0, 99);



	while (true) {

		int argument1 = dis(gen);
		int argument2 = dis(gen);


		std::cout << "argument1 = " << argument1 << std::endl;
		std::cout << "argument2 = " << argument2 << std::endl;

		notifier
			.args()
			.push<int>("argument1", argument1)
			.push<int>("argument2", argument2);
		

		notifier();


		int returnValue = 0;
		notifier
			.returns()
			.get("returnValue", &returnValue);


		std::cout << "return Value = " << returnValue << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		//_sleep(100);
	}
	


	return 0;
}