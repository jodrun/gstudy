#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std; 

/*
//벡터3  (xyz값)
typedef struct tagvector3
{
	float x, y, z;


	tagvector3() {};                                               //기본생성자 (매게변수 노노)
												                   
	                                                               //복사생성자 를 만드려면 기본생성자가 꼭 필요함                    //****복사생성자를 더생성하려면 매게변수를 변화줌(형태나 갯수)*****
												                   
	tagvector3(int _x, int _y)                                     //복사생성자 2
	{											                   
		out << "22" << endl;					                   
		x = _x;									                   
		y = _y;									                   
	};											                   
												                   
	tagvector3(int _x, int _y, int _z)                             //복사생성자3 
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
	int x = 0, y = 0, z = 0;                                      //초기화는 0으로


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
	transform transinfo;                                        //오브젝트가 존재하기위한 최소한의값
};


void initialize(object* _object, char* _name, int _posx = 0, int _posy = 0, int _posz = 0); // = 0 은 값을 넣으면 그값으로 하고, 안넣으면 0으로 한다는뜻
char* setname();
void output(object* _obj);



int main(void)
{
	/*
	vector3 vposition = vector3(10, 20);                        //복사생성자2
	vector3 vposition = vector3(10, 20, 30);                    //복사생성자3
	*/

	
	object* player = new object;
	initialize(player, nullptr, 10, 20, 30);                                         //초기화 함수
	
	object* enemy = new object;
	initialize(enemy, (char*)"enemy", 100, 200, 300);

	output(player);
	output(enemy);


	/*
	player->transinfo.position = vector3(0, 0, 0);		        //트렌스폼 초기화 함수사용 안하면
	player->transinfo.rotation = vector3(0, 0, 0);		        //트렌스폼 초기화 함수사용 안하면
	player->transinfo.scale = vector3(0, 0, 0);                 //트렌스폼 초기화 함수사용 안하면
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
	char buffer[128] = "";                                                    //2^n 승이 컴퓨터가 최적화하기 좋은수
	cout << "이름입력 : ";
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