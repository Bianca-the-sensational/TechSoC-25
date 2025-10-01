#include<iostream>
#include<string>
#include<limits>
using namespace std;

class Pokemon;
void turn_order(const Pokemon& o1 , const Pokemon& o2);

class Pokemon{
    string name;
    int HP;
    int attack;
    int defense;
    int speed;
    const int max_HP;
    struct moves{
        string move_name;
        int power_level;

    };

    friend void random_order(){};    //making the function a friend to be able to access it from main function
    friend void turn_order(const Pokemon& o1 , const Pokemon& o2);
    
    public:
    

    moves move[4];

    Pokemon(string n, int hp, int a, int d, int s)
    : name(n), HP(hp), max_HP(hp), attack(a), defense(d), speed(s) {}


    void display_stats(){
        cout<<"Name: "<<name<<endl;
        cout<<"HP(health points): "<<HP<<"/"<<HP<<endl;
        cout<<"Attack: "<<attack<<endl;
        cout<<"Defense: "<<defense<<endl;
        cout<<"Speed: "<<speed<<endl;
    }



    double damage(const Pokemon& attacker , const Pokemon& defender , int i){                  //Function to return the value of damage by an attack
        return (attacker.attack * attacker.move[i].power_level)/(defender.defense);
    }

    void Battle( Pokemon& attacker ,  Pokemon& defender){
        cout<<attacker.name<<" used "<<attacker.move[0].move_name<<"!"<<endl;
        double damage1 = damage(attacker , defender , 0);
        cout<<defender.name<<" took "<<damage1<<" damage!"<<endl;
        defender.HP = defender.HP - damage1 ;         // The HP value of defender is modified
        check_faint(attacker);
        check_faint(defender);
        cout<<defender.name<<" HP: "<<(defender.HP )<<"/"<<(defender.HP + damage1)<<endl;
        
        

        cout<<"TURN 2: "<<endl;                                                   //Stats of turn 2 where the attacker becomes the
        cout<<defender.name<<" strikes back! "<<endl;                             //defender and the defender become the attacker
        cout<<defender.name<<" used "<<defender.move[0].move_name<<"!"<<endl;
        double damage2 = damage(defender , attacker ,0);
        cout<<attacker.name<<" took "<<damage2<<" damage! "<<endl;
        attacker.HP = attacker.HP - damage2;                             //new varaible introduced to store the changes in
        check_faint(attacker);                                           //damage of the player attcked   
        check_faint(defender);
        cout<<attacker.name<<" HP: "<<( attacker.HP )<<"/"<<(attacker.HP + damage2)<<endl;  

        
        cout<<"TURN 3: "<<endl;
        cout<<attacker.name<<" goes first!"<<endl;
        cout<<attacker.name<<" used "<<attacker.move[3].move_name<<endl;
        double damage3 = damage(attacker , defender , 3);
        cout<<"Excellent move! "<<endl;
        cout<<defender.name<<" took "<<damage3<<" damage! "<<endl;
        defender.HP = defender.HP - damage3 ;    
        check_faint(attacker);
        check_faint(defender);     
        cout<<defender.name<<" HP: "<<(defender.HP )<<"/"<<(defender.HP + damage3 + damage1)<<endl;

        

        cout<<"TURN 4: "<<endl;
        cout<<defender.name<<" strikes back! "<<endl;
        cout<<defender.name<<" used "<<defender.move[3].move_name<<"!"<<endl;
        double damage4 = damage(defender , attacker , 3);
        cout<<attacker.name<<" took "<<damage4<<" damage! "<<endl;
        attacker.HP = attacker.HP - damage4;
        check_faint(attacker);
        check_faint(defender);
        cout<<attacker.name<<" HP: "<<( attacker.HP )<<"/"<<( attacker.HP + damage2 + damage4)<<endl;

        

        cout<<"TURN 5: "<<endl;
        cout<<attacker.name<<"makes a move!"<<endl;
        cout<<attacker.name<<" used "<<attacker.move[1].move_name<<endl;
        double damage5 = damage(attacker , defender , 1);
        cout<<"Sensational move! "<<endl;
        cout<<defender.name<<" took "<<damage5<<" damage! "<<endl;
        defender.HP = defender.HP - damage5 ;  
        check_faint(attacker);
        check_faint(defender);       
        cout<<defender.name<<" HP: "<<(defender.HP )<<"/"<<(defender.HP + damage1 + damage3 + damage5)<<endl;

        

        cout<<"TURN 6: "<<endl;
        cout<<defender.name<<" strikes back! "<<endl;
        cout<<defender.name<<" used "<<defender.move[1].move_name<<"!"<<endl;
        double damage6 = damage(defender , attacker ,1);
        cout<<attacker.name<<" took "<<damage6<<" damage! "<<endl;
        attacker.HP = attacker.HP - damage6;
        check_faint(attacker);
        check_faint(defender);
        cout<<attacker.name<<" HP: "<<( attacker.HP )<<"/"<<(attacker.HP + damage2 + damage4 + damage6)<<endl;

        

        cout<<"TURN 7: "<<endl;
        cout<<attacker.name<<"makes a move!"<<endl;
        cout<<attacker.name<<" used "<<attacker.move[2].move_name<<endl;
        double damage7 = damage(attacker , defender , 2);
        cout<<"Nerve wrecking move! "<<endl;
        cout<<defender.name<<" took "<<damage7<<" damage! "<<endl;
        defender.HP = defender.HP - damage7 ; 
        check_faint(attacker);
        check_faint(defender);        
        cout<<defender.name<<" HP: "<<(defender.HP )<<"/"<<(defender.HP + damage1 + damage3 + damage5 + damage7)<<endl;

        

        cout<<"TURN 8: "<<endl;
        cout<<defender.name<<" strikes back! "<<endl;
        cout<<defender.name<<" used "<<defender.move[2].move_name<<"!"<<endl;
        double damage8 = damage(defender , attacker , 2);
        cout<<attacker.name<<" took "<<damage8<<" damage! "<<endl;
        attacker.HP = attacker.HP - damage8;
        check_faint(attacker);
        check_faint(defender);
        cout<<attacker.name<<" HP: "<<( attacker.HP )<<"/"<<(attacker.HP + damage2 + damage4 + damage6 + damage8)<<endl;

        
    }


    void check_faint(const Pokemon& obj){
        if (obj.HP <= 0){
            // obj.HP = 0;   
            cout<<obj.name<<" HP: "<<"0/"<<obj.max_HP<<endl;
            cout<<"RESULT: "<<endl;
            cout<<obj.name<<" has fainted! "<<endl;    
            cout<<"Battle is over! "<<endl;
            cout<<obj.name<<" has lost the battle!"<<endl;
            exit(0);                                   //Terminates the program and stops the compiler from reading code forward
}                                                      //and breaks out of the code block(learnt something new!)
    }

};


void turn_order(const Pokemon& o1 , const Pokemon& o2){    //Function to decide which pokemon attacks first based on their speed
        cout<<"=== POKEMON BATTLE STARTED ===="<<endl;
        if(o1.speed > o2.speed){
            cout<<"TURN 1: "<<endl<<o1.name<<" attacks on "<<o2.name<<"!"<<endl;
        }
        else if(o1.speed == o2.speed){
            string random_choice;
            cout<<"Which pokemon do you want to attack first: "<<endl;
            cin>>random_choice;
            cout<<random_choice<<" attacks first!"<<endl;

            cout<<"TURN 1: "<<endl<<"Speed Tie!"<<endl;
        }
        else{
            cout<<"TURN 1: "<<endl<<o2.name<<" attacks on "<<o1.name<<"!"<<endl;
        }
    }

int main(){
    string name1 , name2;
    int HP1 ,  HP2;
    int attack1 , attack2 ;
    int defense1 , defense2;
    int speed1 , speed2;
    cout<<"Enter name of the first Pokemon: "<<endl;
    getline(cin , name1);
    cout<<"Enter HP(health points) of the first pokemon: "<<endl;
    cin>>HP1;
    cout<<"Enter attack stats of the first pokemon: "<<endl;
    cin>>attack1;
    cout<<"Enter defense stats of the first pokemon: "<<endl;
    cin>>defense1;
    cout<<"Enter the speed of the first pokemon: "<<endl;
    cin>>speed1;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"Enter name of the second Pokemon: "<<endl;
    getline(cin , name2);
    cout<<"Enter HP(health points) of the first pokemon: "<<endl;
    cin>>HP2;
    cout<<"Enter attack stats of the first pokemon: "<<endl;
    cin>>attack2;
    cout<<"Enter defense stats of the first pokemon: "<<endl;
    cin>>defense2;
    cout<<"Enter the speed of the first pokemon: "<<endl;
    cin>>speed2;


    struct moves{
        string move_name;
        int power_level;

    };
    moves move1[4];
    moves move2[4];
    for(int i=0 ; i<4 ; i++){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the move name "<<i+1<<" of the first pokemon: "<<endl;
        getline(cin, move1[i].move_name);
        cout<<"Enter the power level of move "<<i+1<<" of the first pokemon: "<<endl;
        cin>>move1[i].power_level;
    }

    for(int i=0 ; i<4 ; i++){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Enter the move name "<<i+1<<" of the second pokemon: "<<endl;
        getline(cin , move2[i].move_name);
        cout<<"Enter the power level of move "<<i+1<<" of the second pokemon: "<<endl;
        cin>>move2[i].power_level;
    }


    Pokemon pok1(name1 , HP1 , attack1 , defense1 , speed1 );
    pok1.move[0] = {move1[0].move_name , move1[0].power_level};         //Assigning the move array its values for pok1
    pok1.move[1] = {move1[1].move_name , move1[1].power_level}; 
    pok1.move[2] = {move1[2].move_name , move1[2].power_level}; 
    pok1.move[3] = {move1[3].move_name , move1[3].power_level}; 



    Pokemon pok2(name2 , HP2 , attack2 , defense2 , speed2);            //Assigning the move array its values for pok2
    pok2.move[0] = {move2[0].move_name , move2[0].power_level};
    pok2.move[1] = {move2[1].move_name , move2[1].power_level};
    pok2.move[2] = {move2[2].move_name , move2[2].power_level};
    pok2.move[3] = {move2[3].move_name , move2[3].power_level};


    pok1.display_stats();
    pok2.display_stats();

    turn_order(pok1 , pok2);

    pok1.Battle(pok1 , pok2);


    return 0;
}