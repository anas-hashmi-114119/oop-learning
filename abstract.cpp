#include<iostream>
using namespace std;

class FoodOrder {
	protected:
		
	    int orderId;
	    string customerName;
	    double price;
	
	public:
	   
	virtual void calculateBill()= 0;
	
	virtual void displayOrder()= 0;
	    
};

class PizzaOrder:public FoodOrder {
public:
    PizzaOrder(int id, string name, double p) {
	
	    orderId = id;
	    customerName = name;
	    price = p;
	}

    void calculateBill() {
        double total =price +(price*0.10); 
        cout <<"Pizza total bill: " <<total;
    }

    void displayOrder() {
        cout << "Pizza Order id: "<<orderId;
        cout << "Name: " << customerName;
        cout << "Price: "<< price << endl;
    }
};


class BurgerOrder :public FoodOrder {
public:
    BurgerOrder(int id, string name, double p) {
	
	    orderId = id;
	    customerName = name;
	    price = p;
	}

    void calculateBill() {
        double total = price+50; 
        cout <<"Burger otal bill:"<< total<<endl;
    }

    void displayOrder() {
        cout << "Burger order id: "<<orderId;
        cout<< "Name: " << customerName;
        cout<< "Price: " << price <<endl;
    }
};

int main(){
	

    PizzaOrder p1(1, "Javid", 1000);
    BurgerOrder b1(2, "ghulam",500);

    p1.calculateBill();
    
    p1.displayOrder();

    b1.calculateBill();
    b1.displayOrder();


	return 0;
}
