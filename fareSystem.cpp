#include<iostream>
using namespace std;

class Yide {
	protected:
		string pass_name;
		int ride_id;
		double base_fare;
	
	public:	
		
		Yide(string pass_name, int ride_id, double base_fare){
			this->pass_name = pass_name;
			this->ride_id = ride_id;
			this->base_fare = base_fare;
		}
		
		void setBaseFare(double base_fare){
			double BaseFare = base_fare;
		}
		
		double getBaseFare(){
			return base_fare;
		}
		
		
		
		virtual double calculateFare(){
		
			return 0.0;
		}
		
		virtual void display(){
			cout <<"";
		}
};

class EconRide: public Yide {
	double distance_km;
	
	public:
		
		EconRide(double distance_km, string pass_name, int ride_id, double base_fare):Yide(pass_name, ride_id, base_fare) {
			this->distance_km = distance_km;
		}
		
		double calculateFare() override{
			double FinalFare = getBaseFare() +(distance_km * 8);
			return FinalFare;
		}
		
		void display() override {
			cout << "PassengerName = "<< pass_name<<endl;
			cout << "rideId = " << ride_id <<endl;
			cout << "Fnaal Fare = " << calculateFare()<<endl;
			
			cout << endl;
			cout << endl;
		}
		
};

class LuxRide: public Yide {
	double distance_km;
	double serv_charge;
	
	public:
		
		LuxRide(double distance_km, double serv_charge, string pass_name, int ride_id, double base_fare):Yide(pass_name, ride_id, base_fare){
			this->distance_km = distance_km;
			this->serv_charge = serv_charge;
		}
		
		double calculateFare() override {
			double FinalFare = getBaseFare() +(distance_km * 12) +serv_charge;
			return FinalFare;
		}
		
		void display() override {
			cout << "PassengerName = "<< pass_name<<endl;
			cout << "rideId = " << ride_id <<endl;
			cout << "Fnaal Fare = " << calculateFare()<<endl;
			
			cout <<endl;
        } 
}; 



int main(){
	EconRide e1(4.4, "anas", 3, 5.5);
	e1.calculateFare();
	e1.display();
	
	cout << endl;
	cout <<endl;
	LuxRide l1(4.4, 5.5 , "anas", 3, 5.5);
	l1.calculateFare(); 
	l1.display();       
	
}
