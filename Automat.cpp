#include <iostream>
using namespace std;


const int AUTOMAT_MAX=10;//Maximum value for Automat array myFood and myDrink
const int ORDER_MAX=5; //Maximum value for the Order array of myFood and myDrink
// Class Definition for Food
class Food{
	public:
		Food();//Default Constructor
		Food(string name,int calories,double price);//Constructor w/Parameters
		string getName();//Returns myName
		int getCalories();//Returns myCalories
		double getPrice();//Returns myPrice
		void setName(string name);//Sets value for myName
		void setCalories(int calories);//Sets value for myCalories
		void setPrice(double price);//Sets value for myPrice
		void display();//Prints info about object
	private:
		string myName;//Name of Food
		int myCalories;// Amount of Calories
		double myPrice;// Price of Food
};
//---------------------------

// Class Definition for Drink
class Drink{
	public:
		Drink();//Defualt Constructor 
		Drink(string name, int ounces, double price);//Constructor w/Parameters
		string getName();//Returns myName
		int getOunces();//Returns myOunces
		double getPrice();//Returns myPrice
		void setName(string name);//Sets value for myName
		void setOunces(int ounces);//Sets value for myOunces
		void setPrice(double price);//Sets value for myPrice
		void display();//Displays myName,myOunces, and myPrice
	private:
		string myName;//Name of drink
		int myOunces; //Ounces for the drink
		double myPrice;	//Price of drink
		
};
//---------------------------

// Class Definition for Automat
class Automat{
	public:
		Automat();//Defualt constuctor for Automat
		bool emptyFood();//Checks if Food Queue is empty 
		bool emptyDrink();//Checks if Drink Queue is empty
		void enqueue(Food f);//enqueues to Food queue
		void enqueue(Drink d);//Enqueues to drink queue
		void dequeueFood();//Increases myFoodFront
		void dequeueDrink();//Increases myDrinkFront
		Food frontFood();//Returns the food from the  front of the Food Queue
		Drink frontDrink();//Returns the drink from the  front of the drink queue
		int foodCount();//Returns how much food items are in Foodqueue
		int drinkCount();//Returns how much drink items are in Drink Queue	
		int getTotalCalories();//Returns an int of total calories in Food Queue
		int getTotalOunces();//Returns an int of total ounces in Drink Queue
		double getTotalPrice();//Returns the total price of all Food and drinks in Queue
		void display();//Displays info on automat
		
	private:
		int myFoodFront; //Front of Food Queue
		int myFoodBack; // Back of Food Queue
		int myDrinkFront;//Front of Drink Queue
		int myDrinkBack;// Back of Drink Queue
		Food myFood[AUTOMAT_MAX];// Array for Food Queue
		Drink myDrink[AUTOMAT_MAX];// Array for Drink Queue
		
};
//---------------------------


// Class Definition for Order:
class Order{
	public:
		Order();//Defualt constructor 
		bool emptyFood();//Checks if Food stack is empty
		bool emptyDrink();//Checks if Drink Stack is empty 
		void push(Food f);//Pushes food to food stack
		void push(Drink d);//Pushes drink to Drink stack
		void popFood();//Removes top from food stack
		void popDrink();//Removes top from drink stack
		Food topFood();//Returns the food object from top of food stack
		Drink topDrink();//Returns the drink object from top of drink stack
		int foodCount();//Returns how much food items are in food stack
		int drinkCount();//Returns how much drink items are in drink stack
		double getTotalPrice();//returns the total price of the food and drink stack
		void display();//Displays the order 
		void cancel(Automat& a);// Pops each item from both stacks and enqueues into Automat
		void purchase();//Resets the stacks
		static int getTotalOrders();//Returns myTotalOders

	private:
		int myFoodTop;//Top of myFood stack
		int myDrinkTop;//Top of myDrink stack
		Food myFood[ORDER_MAX];//Array for the myFood stack
		Drink myDrink[ORDER_MAX];//Array for the myDrink stack
		static int myTotalOrders; //Keeps track of total orders
		

};


//---------------------------

int main() { //More details on these classes and their methods and functions detailed in the declerations.
	//Classes:
		//Automat:The automat can hold food and drink objects in a two queues.
		//Order:Order is two stack of food and drinks. It takes in food and drink objects to fill the stack.  
		//Drink:Drink is a object that has three attributes to it  name,  ounces, and price
		//Food:Food is an object that has three main attributes to it name,calories, and price.
}
//Class Method/Constuctor Definitions:

//Order Method and Constuctor Definitions
int Order::myTotalOrders=0;
Order::Order(){
	myFoodTop=-1;
	myDrinkTop=-1;
	myTotalOrders++;//Increment total orders 
	
}

bool Order::emptyFood(){
	return (myFoodTop==-1);
}

bool Order::emptyDrink(){
	return (myDrinkTop==-1);
}

void Order::push(Food f){
	if(myFoodTop<ORDER_MAX-1){// Checks to see if adding one more order will reach the maximum allowed
		++myFoodTop;
		myFood[myFoodTop]=f;
		
	}else{
		cerr<<"Order food full; new food not added\n";
		
	}
}

void Order::push(Drink d){
	if(myDrinkTop<ORDER_MAX-1){//Checks to see if adding one more order will reach the maximum allowed
		++myDrinkTop;
		myDrink[myDrinkTop]=d;

	}	else{
		cerr<<"Order drink full; new drink not added\n";

	}
}
	
void Order::popFood(){
	if(!emptyFood()){
		myFoodTop--;
	}else{
		cerr << "Order Food empty can not remove from top";
	}
}

void Order::popDrink(){
	if(!emptyDrink()){
		myDrinkTop--;
	}else{
		cerr << "Order Drink empty can not remove from top";
	}
}

Food Order::topFood(){
	if(!emptyFood()){
		cerr<<"Order Food is empty can not return top\n";
		
		return Food();
	}else{
		return myFood[myFoodTop];
	}
}

Drink Order::topDrink(){
	if(!emptyDrink()){
		cerr<<"Order Drink is empty can not return top";
		return Drink();
	}else{
		return myDrink[myDrinkTop];
	}
}

int Order::foodCount(){
	int count=0;
	for(int i=myFoodTop;i>=0;i--){//Goes down food stack adding +1 to count
		count++;
	}
	return count;
}

int Order::drinkCount(){
	int count=0;
	for(int i=myDrinkTop;i>=0;i--){//Goes down drink stack adding +1 to count
		count++;
	}
	return count;
}

double Order::getTotalPrice(){
	double price=0;
	
	for(int i=myFoodTop;i>=0;i--){//Goes down food stack adding to price
		price=price+myFood[i].getPrice();
	}
	for(int i=myDrinkTop;i>=0;i--){//Goes down drink stack adding to price
		price=price+myDrink[i].getPrice();
	}

	return price;
	

	
}

void Order::display(){
	cout<<"Order:\n";

	//Printing Food info:
	cout<<"\tFood ("<<foodCount()<<" items):\n";
	for(int i=myFoodTop;i>=0;i--){//Goes down food stack printing food info
		cout<<"\t\t"<<myFood[i].getName()<<": "<<myFood[i].getCalories()<<" calories, $"<<myFood[i].getPrice()<<"\n";
	}

	//Printing Drink info:
	cout<<"\tDrink ("<<drinkCount()<<" items):\n";

	for(int i=myDrinkTop;i>=0;i--){//Goes down drink stack printing drink info
		cout<<"\t\t"<<myDrink[i].getName()<<": "<<myDrink[i].getOunces()<<" ounces, $"<<myDrink[i].getPrice()<<"\n";
			
		
	}
	cout<<"\tOrder total: $"<<getTotalPrice()<<"\n\n";
	
}

void Order::cancel(Automat& a ){

	//Adding food to Automat
	for(int i=myFoodTop;i>=0;i--){//Goes down food stack
		a.enqueue(myFood[i]);
		popFood();
	}
	//Adding drinks to Automat
	for(int i=myDrinkTop;i>=0;i--){//Goes down drink stack 
		a.enqueue(myDrink[i]);
		popDrink();
	
	}
	
}

void Order::purchase(){
	myFoodTop=-1;
	myDrinkTop=-1;
}

int Order::getTotalOrders(){
	return myTotalOrders;
}

//---------------------------






//Automat Method and Constructor Definitions 
Automat::Automat(){
	myFoodFront=0;
	myFoodBack=0;
	myDrinkFront=0;
	myDrinkBack=0;
}

bool Automat::emptyFood(){
	return(myFoodFront==myFoodBack);
}

bool Automat::emptyDrink(){
	return(myDrinkFront==myDrinkBack);
}

void Automat::enqueue(Food f){
	int newFoodBack=(myFoodBack+1)%AUTOMAT_MAX;//Possible new back for Food Queue
	if(newFoodBack==myFoodFront){//If the newBack is equal to the front then reached max 
		cerr << "Food Queue is full \n";
	}else{
		myFood[myFoodBack]=f;//Append f to the array
		myFoodBack=newFoodBack;//Increase myFoodBack
		
	}
}

void Automat::enqueue(Drink d){
	int newDrinkBack=(myDrinkBack+1)%AUTOMAT_MAX;//Possible new back for Drink queue
	if(newDrinkBack==myDrinkFront){//If newDrinkBack is equal to front then currently at max
		cerr<<"Drink Queue is full \n";
	}else{
		myDrink[myDrinkBack]=d;//Append d to array
		myDrinkBack=newDrinkBack;//Increase myDrinkBack
	}
}

void Automat::dequeueFood(){
	if(!emptyFood()){//Checks if food queue is empty before incrementing FoodFront
		myFoodFront=(myFoodFront+1)%AUTOMAT_MAX;
	}else{
		cout << "Food Queue is empty"<<"\n";
	}
}

void Automat::dequeueDrink(){
	if(!emptyDrink()){
		myDrinkFront=(myDrinkFront+1)%AUTOMAT_MAX;//if DrinkQueue is empty before incrementing DrinkFront
	}else{
		cout<<"Drink Queue is empty"<<"\n";
	}
	
}

Food Automat::frontFood(){
	return(myFood[myFoodFront]);//Returns a food item
	
}

Drink Automat::frontDrink(){
	return(myDrink[myDrinkFront]);
	
	
}

int Automat::foodCount(){
	int sum=0;
	for(int i=myFoodFront;i!=myFoodBack;i=(i+1)%AUTOMAT_MAX){
		sum++;
		
	}
	return sum;
}

int Automat::drinkCount(){
	int sum=0;
	for(int i=myDrinkFront;i!=myDrinkBack;i=(i+1)%AUTOMAT_MAX){
		sum++;
	}
	return sum;
}

int Automat::getTotalCalories(){
	int total_calories=0;
	for(int i=myFoodFront;i!=myFoodBack;i=(i+1)%AUTOMAT_MAX){
		total_calories=total_calories+myFood[i].getCalories();
	}
	return total_calories;
}

int Automat::getTotalOunces(){
	int total_ounces=0;
	for(int i=myDrinkFront;i!=myDrinkBack;i=(i+1)%AUTOMAT_MAX){
		total_ounces=total_ounces+myDrink[i].getOunces();
	}
	return total_ounces;
}

double Automat::getTotalPrice(){
	double total_sum=0;
	for(int i=myFoodFront;i!=myFoodBack;i=(i+1)%AUTOMAT_MAX){
		total_sum=total_sum+myFood[i].getPrice();
	}

	for(int i=myDrinkFront;i!=myDrinkBack;i=(i+1)%AUTOMAT_MAX){
		total_sum=total_sum+myDrink[i].getPrice();
	}

	

	return total_sum;
	
}

void Automat::display(){
	cout<<"Automat:\n";

	//Printing Food info:
	cout<<"\tFood:\n";
	for(int i=myFoodFront;i!=myFoodBack;i=(i+1)%AUTOMAT_MAX){
		cout<<"\t\t"<<myFood[i].getName()<<": "<<myFood[i].getCalories()<<" calories, $"<<myFood[i].getPrice()<<"\n";
	}
	cout<<"\t\t"<<foodCount()<<" food items - Total Calories: "<<getTotalCalories()<<"\n";

	//Printing drink info:
	cout<<"\tDrinks:\n";
	for(int i=myDrinkFront;i!=myDrinkBack;i=(i+1)%AUTOMAT_MAX){
		cout<<"\t\t"<<myDrink[i].getName()<<": "<<myDrink[i].getOunces()<<" ounces, $"<<myDrink[i].getPrice()<<"\n";
	}
	cout<<"\t\t"<<drinkCount()<<" drinks - Total Ounces: "<<getTotalOunces();
	cout<<"\n\n";
	
}
//---------------------------

//Drink Method and Constructor Definitions
Drink::Drink(){
	
}

Drink::Drink(string name, int ounces, double price){
	myName=name;
	myOunces=ounces;
	myPrice=price;
}

string Drink::getName(){
	return myName;
}

int Drink::getOunces(){
	return myOunces;
}

double Drink::getPrice(){
	return myPrice;
}

void Drink::setName(string name){
	myName=name;
}

void Drink::setOunces(int ounces){
	myOunces=ounces;
}

void Drink::setPrice(double price){
	myPrice=price;
}

void Drink::display(){
	cout<<myName<<": "<<myOunces<<" ounces, $"<<myPrice;
}

//---------------------------

//Food Method Definitions
Food::Food(){
	
}

Food::Food(string name,int calories,double price){
	myName=name;
	myCalories=calories;
	myPrice=price;
}

string Food::getName(){
	return myName;
}

int Food::getCalories(){
	return myCalories;
}

double Food::getPrice(){
	return myPrice;
}

void Food::setName(string name){
	myName=name;
}

void Food::setCalories(int calories){
	myCalories=calories;
}

void Food::setPrice(double price){
	myPrice=price;
}

void Food::display(){
	cout<<myName<<": "<<myCalories<<" calories, $"<<myPrice;
}

//--------------------------


//--------------------------------------------------------------------------------