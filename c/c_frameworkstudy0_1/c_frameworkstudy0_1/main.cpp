#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std; 

/*
//����3  (xyz��)
typedef struct tagvector3
{
	float x, y, z;


	tagvector3() {};                                               //�⺻������ (�ŰԺ��� ���)
												                   
	                                                               //��������� �� ������� �⺻�����ڰ� �� �ʿ���                    //****��������ڸ� �������Ϸ��� �ŰԺ����� ��ȭ��(���³� ����)*****
												                   
	tagvector3(int _x, int _y)                                     //��������� 2
	{											                   
		out << "22" << endl;					                   
		x = _x;									                   
		y = _y;									                   
	};											                   
												                   
	tagvector3(int _x, int _y, int _z)                             //���������3 
	{
		cout << "33" << endl;
		x = _x;
		y = _y;
		z = _z;
	};

}vector3;
*/



struct vector3
{
	int x = 0, y = 0, z = 0;                                      //�ʱ�ȭ�� 0����


	vector3() {};

	vector3(int _x, int _y) 
		: x(_x), y(_y), z(0) {};

	vector3(int _x, int _y, int _z)
		: x(_x), y(_y), z(_z) {};

};


struct transform
{
	vector3 position;
	vector3 rotation;
	vector3 scale;
};


struct object
{
	char* name;
	int speed;
	transform transinfo;                                        //������Ʈ�� �����ϱ����� �ּ����ǰ�
};


void initialize(object* _object, char* _name, int _posx = 0, int _posy = 0, int _posz = 0); // = 0 �� ���� ������ �װ����� �ϰ�, �ȳ����� 0���� �Ѵٴ¶�
char* setname();
void output(object* _obj);



int main(void)
{
	/*
	vector3 vposition = vector3(10, 20);                        //���������2
	vector3 vposition = vector3(10, 20, 30);                    //���������3
	*/

	
	object* player = new object;
	initialize(player, nullptr, 10, 20, 30);                                         //�ʱ�ȭ �Լ�
	
	object* enemy = new object;
	initialize(enemy, (char*)"enemy", 100, 200, 300);

	output(player);
	output(enemy);


	/*
	player->transinfo.position = vector3(0, 0, 0);		        //Ʈ������ �ʱ�ȭ �Լ���� ���ϸ�
	player->transinfo.rotation = vector3(0, 0, 0);		        //Ʈ������ �ʱ�ȭ �Լ���� ���ϸ�
	player->transinfo.scale = vector3(0, 0, 0);                 //Ʈ������ �ʱ�ȭ �Լ���� ���ϸ�
	*/



	return 0;
}



void initialize(object* _object, char* _name, int _posx, int _posy, int _posz)   
{
	_object->name = (_name == nullptr) ? setname() : _name;

	_object->speed = 0;

	_object->transinfo.position = vector3(_posx, _posy, _posz);
	_object->transinfo.rotation = vector3(0, 0, 0);
	_object->transinfo.scale = vector3(0, 0, 0);
}


char* setname()
{
	char buffer[128] = "";                                                    //2^n ���� ��ǻ�Ͱ� ����ȭ�ϱ� ������
	cout << "�̸��Է� : ";
	cin >> buffer;
	//char* pname = (char*)malloc(strlen(buffer) + 1);
	char* pname = new char[strlen(buffer) + 1];
	strcpy(pname, buffer);

	return pname;
}


void output(object* _obj)
{
	if (_obj->name != nullptr)
		cout << "name : " << _obj->name << endl;

	
	cout << "speed : " << _obj->speed << endl;

	cout << "x : " << _obj->transinfo.position.x <<
		", y : " << _obj->transinfo.position.y <<
		", z : " << _obj->transinfo.position.z << endl;
}