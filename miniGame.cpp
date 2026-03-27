#include<iostream>
using namespace std;

class Hero {
	
	protected:
		string hero_name;
		string hero_type;
		int health_points;
		double power_level;
		int experience_points;
	public:
		Hero(string name, string type, int hp, double pl, int ep){
			hero_name = name;
			hero_type = type;
			health_points = hp;
			power_level = pl;
			experience_points = ep;
		}
		
		void welcome_msg(){
			cout <<endl;
			cout <<endl;
			cout << "--  Welcome  --" << endl;
		}
		
		virtual void display() = 0;		
		virtual void attack_action() = 0;
		virtual void defend_action() = 0;
		
		virtual double damage_calc() = 0;
		virtual void protection_calc() = 0;
};

class Warrior:public Hero{
	string weapon_name;
	int armor_strength;
	double rage_level;
	
	public:
		Warrior(string weapName, int armStrength, double rageLevel, string name, string type, int hp, double pl, int ep):Hero(name, type, hp, pl, ep){
			weapon_name = weapName;
			armor_strength = armStrength;
			rage_level = rageLevel;
		}
		
		void display() override {
			cout << "-- hero basic profile --" <<endl;
			cout << "Hero name: " << hero_name << endl;
			cout << "Hero type: " << hero_type << endl;
			cout << "Health points: " << health_points <<endl;
			cout << "Power level: " << power_level << endl;
			cout << "Experience points: " << experience_points << endl;
			cout << "-- hero special attributes --"<<endl;
			cout << "Weapon Name: " << weapon_name << endl;
			cout << "Armor strength: " << armor_strength <<endl;
			cout << "rage level: " << rage_level <<endl;
		}		
		void attack_action() override {
			cout << "worrior kicks..." <<endl;
		}
		void defend_action() override {
			cout << "worrior depending using armor..."<<endl;
		}
		double damage_calc() override {
			double damage = (armor_strength + rage_level)*2;
			return damage;
		}
		void protection_calc() override {
			double defence = (armor_strength + rage_level)*4;
			cout << "Defence value: " << defence << endl;
		}
};
class Mage:public Hero{
	string spell_name;
	int mana_points;
	double magic_multiplier;
	
	public:
		Mage(string spellName, int manaPoints, double magicMult, string name, string type, int hp, double pl, int ep):Hero(name, type, hp, pl, ep){
			spell_name = spellName;
			mana_points = manaPoints;
			magic_multiplier = magicMult;
		}
		
		void display() override {
			cout << "-- hero basic profile --" <<endl;
			cout << "Hero name: " << hero_name << endl;
			cout << "Hero type: " << hero_type << endl;
			cout << "Health points: " << health_points <<endl;
			cout << "Power level: " << power_level << endl;
			cout << "Experience points: " << experience_points << endl;
			cout << "--- hero special attributes ---"<<endl;
			cout << "spell Name: " << spell_name << endl;
			cout << "mana points: " << mana_points <<endl;
			cout << "magic Multiplier: " << magic_multiplier <<endl;
		}		
		void attack_action() override {
			cout << "Mage spells..."  <<endl;
		};
		void defend_action() override {
			cout << "Mage defending using magical shield..."<<endl;
		};
		double damage_calc() override {
			double damage = (mana_points + magic_multiplier)*2;
			return damage;
		}
		void protection_calc() override {
			double defence = (mana_points + magic_multiplier)*4;
			cout << "Defence value: " << defence << endl;
		}
};
class Archer:public Hero{
	string bow_type;
	int arrows;
	double accuracy_rate;
	
	public:
		Archer(string bowType, int arrow, double accuracyRate, string name, string type, int hp, double pl, int ep):Hero(name, type, hp, pl, ep){
			bow_type = bowType;
			arrows = arrow;
			accuracy_rate = accuracyRate;
			
		}
		
		void display() override {
			cout << "--- hero basic profile ---" <<endl;
			cout <<"Hero name: " << hero_name << endl;
			cout<< "Hero type: " << hero_type << endl;
			cout << "Health points: " << health_points <<endl;
			cout<<"Power level: " << power_level << endl;
			cout <<"Experience points: " << experience_points << endl;
			cout <<"--- hero special attributes ---"<<endl;
			cout<< "bow type: " << bow_type << endl;
			cout << "arrows: " << arrows <<endl;
			cout << "accuracy: " << accuracy_rate <<endl;
		}		
		void attack_action() override {
			cout << "Archer is attcking using precision..."<<endl;
		};
		void defend_action() override {
			cout << "Archer defending using agility..."<<endl;
		};
		double damage_calc() override {
			double damage = (arrows + accuracy_rate)*2;
			return damage;
		}
		void protection_calc() override {
			double defence = (arrows + accuracy_rate)*4;
			cout << "Defence value: " << defence << endl;
		}
};



int main(){
	
	Warrior w("sword", 7, 5.5, "muhammad", "worrior", 11, 4.3, 8);
	w.welcome_msg();
	w.display();
	w.attack_action();
	w.defend_action();
	cout << "Attack value: "<<w.damage_calc() <<endl;
	w.protection_calc();
	
	Mage m("Dark Magic", 14, 3.2, "fahad", "Mage", 13, 5.3,10);
	m.welcome_msg();
	m.display();
	m.attack_action();
	m.defend_action();
	cout << "Attack value: "<< m.damage_calc() <<endl;
	m.protection_calc();
	
	Archer a("Curve", 8, 3.4, "jamshid", "Archer", 4, 4.2, 3);
	a.welcome_msg();
	a.display();
	a.attack_action();
	a.defend_action();
	cout << "Attack value: "<< a.damage_calc() <<endl;
	a.protection_calc();
	

	cout<< endl;
	cout <<endl;
	if(w.damage_calc() > m.damage_calc() && w.damage_calc() > a.damage_calc()){
		cout << "Warrior is the highest attacking value: " << w.damage_calc() <<endl;
	}
	else if(m.damage_calc() > w.damage_calc() && m.damage_calc() > a.damage_calc()){
		cout << "Mage is the highest attacking value: " << m.damage_calc() <<endl;
	}
	else{
		cout << "Archor is the highest attacking value: " << a.damage_calc() <<endl;
	}
	
	return 0;
}