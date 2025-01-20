#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
 
using namespace std;
 
class Animal // animal is more abstract, while cats and dogs get more specific
{
public:
	virtual void do_act(); // remembers action, virtual means it's something you might want to change
};
void Animal::do_act() { cout <<"Move Move!"<< endl; }; // says what action does
 
class Dog : public Animal { // creates dog class, JUST LIKE class animal except for some differences , if there are like 14 objects and you only want to change one, this is helpful
	// Default constructor is Dog, it just defines it and doesnt do anything else.
public:
	virtual void do_act(); // by putting the word virtual here, it means it's available to change.  could create a german shepard class with properties of dog, 
};
void Dog::do_act() { cout <<"Bark Bark!"<<endl; }; // has same act except it says "Bark Bark."  if you called it something besides do_act it wouldn't override and you could have both actions.
 
class Cat : public Animal {
public:
	Cat(); // Cat() is a constructor. A constructor is all the things this object needs to do in order to come into exsitance.   Cat() is a special one that sets mouse number = 4 
	// It's like when you get born you're given a name, but even if you werent you were still born.  Mouse = 4 is like giving Cat() a name. Dog was just born.
	virtual void do_act();
	int mouse; // Animal doesn't have mouse variable but cats do
};
Cat::Cat() {mouse = 4;}
void Cat::do_act() { cout <<"Scratch Scratch! "<<mouse<<endl; };
 
int main() {
	Dog fido; // variable of type dog called fido
	Cat fritz; // variable of type cat called fritz
	Animal snail; // variable of type animal called snail
	// These objects can have the same things done with them as ints and string, we can point to them, etc.
	cout << "The dog "<<endl;
	fido.do_act();
	cout << "The cat " << endl;
	fritz.do_act();
	cout << "The snail " << endl;
	snail.do_act(); 
	
	cout <<"The cat through an Animal Pointer"<<endl;
	Animal *aptr = &fritz;
	// (*aptr).do_act() is the same thing as below.  Aka go follow this pointer and then do action. 
	aptr->do_act(); // Since we used the pointer, we still have the Cat behavior. Not an animal, but rather a buisness card to animals.  Want to change value of pointer vs  where the pointer points
	// cout << "mouse" << aptr->mouse; wont work until we change Animal *aptr above to Cats *aptr
	
	cout <<"The cat assigned to an Animal"<<endl;
	snail = fritz; // if it takes a more specific type and sticks it into a generic animal variable, it will act like an animal.
	snail.do_act(); // Slicing stripped off the cat behavior and data
	
	cout <<"The cat in a vector of Animal pointers"<<endl;
	vector<Animal *> animals;
	animals.push_back(new Cat);
	animals.push_back(&fido); // the and percand is not putting actual fido in there, just find where fido is and put him in there.
	animals.push_back(&fritz);
	animals.push_back(new Dog); //Animals all have do_act but they don't all have mice. 
	animals[0]->do_act(); // new Cat does do_act
	animals[1]->do_act(); 
	animals[2]->do_act();// Since we didnt copy, we can still call the Cat do_act, thing at animals[1] do action.
	
	vector <Animal* > zoo;
	zoo.push_back(animals[1]);// points to the same place as animals one.  Can have a set of all animals, and then actually can have a working set aka which ones are being considered.
	/*for (unsigned int i=0; i< animals.size() ; i++) 
	{
		delete animals[i]; // deletes empty spaces, doesn't delete whats inside vector, just the spaces not being used...i
	}*/
	
	cout <<"The cat in a vector of Animals"<<endl;
	vector<Animal> pets;
	pets.push_back(fido); // this one is like "go make a copy" since it doesn't have an anpercandt
	pets.push_back(fritz);
	pets[0].do_act();
	pets[1].do_act(); // This will call the Animal do_act
	
	system("pause");
}
