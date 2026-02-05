#include<iostream>
using namespace std;

class Car {
	public:
		string brand;
		int speed;
		
		void showDetails(){
			cout << "The "<< brand <<" is moving with "<< speed << " Km/h." << endl;
		}
};

int main(){
	
	Car c1;
	c1.brand = "Toyota";
	c1.speed = 120;
	c1.showDetails();
	
	Car c2;
	c2.brand = "Ferarri";
	c2.speed = 150;
	c2.showDetails();

	return 0;
	
}