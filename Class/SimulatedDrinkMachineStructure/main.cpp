/*
 * Author:  Amanda Sarenana
 *          with a little help from Dr. Lehr
 * Date:    April 3rd, 2020
 * Purpose: Understanding of ADT data type called a structure
*/

//System Level Libraries
#include <iostream>  //I/O System Library
#include <string>    //String Data Type - Class
#include <iomanip>   //Formatting Library
using namespace std; //System Libraries are compile under the std namespace

//User Libraries - Normally store in .h file and include
//However, Code-E requires all code to be in 1 file
//VendingMachine structure
struct VendingMachine{
    string name;            //You should also be able to use character arrays
    float cost;             //Never use a double, only a float!!!
    unsigned char stock;    //The range of this data is within a 1 Byte integer i.e. char
};

//function prototypes
void menu(VendingMachine *,int);       //Just Display the Menu
void select(string &,short &);         //Get the Selection
bool disburse(VendingMachine *,int,string,short,unsigned short &);//Compare and make change

//main function
int main(){
    //Declare and Initialiize the Data Structure and Variables
    //Array of structure of type VendingMachine
    const int SIZE=5;//The proper way to declare a static array
    VendingMachine drink[SIZE]={ {"Cola",75,20},
                       {"Root Beer",75,20},
                       {"Lemon-Lime",75,20},  
                       {"Grape Soda",80,20},
                       {"Cream Soda",80,20}};
    string choice;//Users choice in drinkeCost
    short recvd;//Change received  with a 2 Byte integer in pennies/cents
    unsigned short earned=0;//How much did the machine make?
    
    //Loop until user inputs Quit
    do{
                      
        //Present the choices to the users
        menu(drink,SIZE);
        
        //Acquire the users selection
        select(choice,recvd);
        
        //Compare and disburse amount
    }while(disburse(drink,SIZE,choice,recvd,earned));
    
    //Output the amount the machine earned
    cout<<earned<<endl;
    
}

//Disburse and Total how much the machine has earned until the User Quits!
bool disburse(VendingMachine *drink,int SIZE,string choice,short recvd,unsigned short &earned){
    //Time to Quit
    if(choice=="Quit")return false;
    //Find the Drink Requested
    bool found=false;
    for(int i=0;i<SIZE && !found;i++){
        //Loop thru all the choices, if not found exit program
        if(choice==drink[i].name){
            //If the user gives less than required exit program
            if(recvd<drink[i].cost){
                exit(0);
            }else{
                //If not in stock then don't accept the money and return
                if(drink[i].stock>=1){
                    drink[i].stock--;
                    cout<<recvd-drink[i].cost<<endl;
                    earned+=drink[i].cost;
                    found=true;
                }
            }
        }
    }
    return found;
}

//Get the Choice and Payment by the user
void select(string &drink,short &change){
    change=0;
    getline(cin,drink);
    if(drink!="Quit") {
        cin>>change;
        cin.ignore();
    }
    if(change<0||change>100)exit(0);
}

//Display the Choices
void menu(VendingMachine items[],int size){

        for(int i=0;i<size;i++){
            cout<<setw(11)<<left<<items[i].name;
            cout<<items[i].cost<<"  "<<static_cast<int>(items[i].stock)<<endl;
        }
        cout<<"Quit\n";
}