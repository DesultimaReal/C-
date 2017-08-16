#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>

//Goal for today,
using namespace std;
stringstream debugger;
enum eOptions{
    Attack = 0,
    Heal = 1,
    Defend = 2
};
enum EnemyOptions{
    EAttack = 0,
    EDefend = 1,
    ECharge = 2
};
class LifeForm{
private:
    int hp, attack, defense, Maxhp, Originalattack, Originaldefense, Energy, MaxEnergy, BeastNumber;

    string name;
    string Interaction;
    string BInteraction;
    string state;

    int ChargeTimer;

    bool Defending;
public:
    LifeForm(int OGhp, int OGattack, int OGdefense, string OGname, int OGEnergy, int NewBeastNumber){
        state = "Neutral";
        //Set up our hp/energy and their max
        Maxhp = OGhp;hp = OGhp;
        Energy = OGEnergy;MaxEnergy = OGEnergy;
        //Set up our Original and current ATK/DEF
        Originalattack = OGattack;
        attack = OGattack;
        Originaldefense = OGdefense;
        defense = OGdefense;
        //Setup our name
        name = OGname;
        //Setup our Beastiary Number
        BeastNumber = NewBeastNumber;
        //Setup our Initial Interaction and Default Interaction
        Interaction = "NULL";
        BInteraction = " Attacks!";
        ChargeTimer = 0;

    }
    void decrementTimer(int Timer){
        Timer--;
    }
    void AddToInteraction(string AddTo){
        Interaction += AddTo;
    }
    void SetChargeTimer(int SetNum){
        ChargeTimer = SetNum;
    }
    void SetupBattleInteraction(){// Our Default Interaction
        if(name == "PlayerName"){
            Interaction = "PlayerName stands ready!";
        }
        else{
            Interaction = BInteraction.insert(0,name);
        }
    }
    inline GetBNumber(){
        return BeastNumber;
    }
    inline GetEN(){
        return Energy;
    }
    inline GetHP(){
        return hp;
    }
    inline GetMaxHP(){
        return Maxhp;
    }
    void FullHeal(){
        hp = Maxhp;
    }
    inline GetAttack(){
        return attack;
    }
    inline GetDefense(){
        return defense;
    }
    string GetName(){
        return name;
    }
    void ClearInteraction(){
        Interaction = "";
    }
    string GetInteraction(){
        return Interaction;
    }
    void setInteraction(string NewInteraction){
        Interaction = NewInteraction;
    }
    int GetChargeTimer(){
        return ChargeTimer;
    }
    bool TakeDamage_DeathCheck(int damage){
        hp -= damage;
        stringstream ss;
        ss << GetName() << " takes " << damage << "!";
        if(hp > 0){
            if(hp < 10){
                ss << GetName() << " looks heavily damaged!";
            }
        }
        else {
            hp = 0;
            ss << name << " Dead!";
            Interaction = ss.str();
            return true;
        }
        Interaction += ss.str();
        //cout << Interaction << endl;
        return false;
    }
    void Defend(){
        state = "Defend";
        Interaction += (name + " is defending!");
    }
    string GetState(){
        return state;
    }
    void ReturnToNeutral(){
        state = "Nuetral";
    }
    void Charge(){
        state = "Charge";
        Interaction += (name + " is drawing power!");
    }
    void Heal(int Healing){
        stringstream ss;

        if((hp + Healing) > Maxhp){
            hp = Maxhp;
            ss << "Player Overheals!";
        }
        else{
            hp += Healing;
            ss << "Player heals " << Healing << ".";
        }
        Interaction += ss.str();
    }
};
class BattleController{
private:


    bool quit;
    bool gameover;
    string winner;
    int width, height;
    char Up, Left, Down, Right, Enter, QuitKey;
    int OptionX;
    string OptionArray[2];
    int SizeOfArray;
    int SizeOfElement;
    int ElementsInArray;
    int SepHeight, PlHeight, EnHeight, OptHeight, StatHeight;
    string Options;

    vector<LifeForm *> Enemys;
    bool reset;int CurrentEnemyNum;
    LifeForm * player;
    LifeForm * enemy;
    LifeForm * goblin;
    LifeForm * kobald;
    LifeForm * dragon;

    //string CurrentAiGrid[3][3];
    string CurrentAiGrid[3][3] =
        {
            {"Attack", "Defend", "Charge"},
            {"Attack", "Defend", "Charge"},
            {"Attack", "Defend", "Charge"}
        };
    int TurnCount;
public:
    BattleController(int w, int h){
        TurnCount = 0;
        reset = false;
        //Create Enemys For Our Player To Fight, and our Player
        player = new LifeForm(42, 5, 5, "PlayerName", 10, 10); //Our Player
        goblin = new LifeForm(70, 5, 1, "Goblin", 10, 0);//Our First Enemy, Has High HP, Grind it out
        kobald = new LifeForm(20, 13, 1, "Kobald", 10, 1);//Our Second Enemy, Has High Attack, Kill it fast
        dragon = new LifeForm(150, 10, 5, "Dragon", 10, 2);//Our Final Boss, Has a special attack, defend against it
        //Addd them to a vector of enemy pointers
        Enemys.push_back(goblin);
        Enemys.push_back(kobald);
        Enemys.push_back(dragon);
        //Set our Current Enemy as Goblin
        CurrentEnemyNum = 0;
        enemy = Enemys[CurrentEnemyNum];

        width = w; height = h; //Width and Height of the printed screen//
        SepHeight = height / 2 + 3; //HEIGHT AT WHICH TO PRINT A SEPERATOR LINE
        PlHeight = height / 2 + 7;
        EnHeight = height / 2 + 8;
        OptHeight = height / 2 + 9;
        StatHeight = height - 2;
        //MOVE TO OPTION CLASS//

        Options = "NULL";
        SizeOfArray = sizeof(OptionArray); //OUR ARRAY SIZE IN DATA
        SizeOfElement = sizeof(OptionArray[0]); //OUR ELEMENT SIZE IN DATA
        ElementsInArray = sizeof(OptionArray)/sizeof(OptionArray[0]); //THE NUMBER OF ELEMENTS IN OUR ARRAY

        OptionX = 0; //Our Starting position in our options
        OptionArray[0] = "Attack"; // Our First Option
        OptionArray[1] = "Heal"; // Our Second Option

        //Establish our Controls

               Up = 'w';
    Left = 'a';Down = 's'; Right = 'd';

               Enter = 'e';
               QuitKey = 'q';

    }

    ~BattleController(){
        delete player, enemy;
    }

    //Prints our string Appropriately Spaced//
    string BalancedString(string LineToPrint){
                    stringstream ss;
                    int StringLen = LineToPrint.length();   //Get the string length
                    int LEFTANDRIGHTSPACES = (width - StringLen) / 2; //Set up balanced sides
                    for(int i = 0; i < LEFTANDRIGHTSPACES; i++){ss << " ";} //LeftSide Spaces
                    if((width - StringLen) % 2 != 0){ss << " ";} //Balancing Space
                    ss << LineToPrint; //Print our String
                    for(int i = 0; i < LEFTANDRIGHTSPACES; i++){ss << " ";}//RightSide Spaces
                    return ss.str();
    }

    string DrawOptions(){
        stringstream ss;
        for(int i = 0; i<ElementsInArray; i++){
            if(i == OptionX){
                ss << "\xB2";
            }
            if(i != ElementsInArray){ //IF WE ARENT ON OUR LAST OPTION ADD SPACE IN BETWEEN
                ss << OptionArray[i] << "         ";
            }
        }
        return ss.str();
    }

    string DrawStats(){
        stringstream ss;
        ss << "PlayerName: " << player->GetName() << " HP: " << player->GetHP() << " EN: " << player->GetEN();
        return ss.str();
    }

    void Draw(){
        bool haventprintedoptions = true;
        string PlString =  BalancedString(player->GetInteraction()); //Get our enemys Interaction and Format It
        string EnString =  BalancedString(enemy->GetInteraction()); //Get our enemys Interaction and Format It
        string OptString = BalancedString(DrawOptions()); //Get our Options and format them
        string StatString = BalancedString(DrawStats());
        system("cls");
        for(int i = 0; i < width + 2; i++){
            cout << "\xB2";//Top
        }cout << endl;
        for(int i = 0; i < height; i++)//y coord
        {
            for(int j = 0; j < width; j++)//x coord
            {
                if(j == 0){cout << "\xB2";}//PRINT LEFT SIDE

                //              PRINT CENTER            //
                if(i == SepHeight){cout << "\xB2";}//SEPERATOR LINE
                else if(i == PlHeight && j < PlString.length()){cout << PlString[j];}//THE PLAYER ROW
                else if(i == EnHeight && j < EnString.length()){cout << EnString[j];}//THE ENEMY ROW
                else if(i == OptHeight && j < OptString.length()){ cout << OptString[j];}//THE OPTION ROW
                else if(i == StatHeight && j < StatString.length()){ cout << StatString[j];}//The player stats row
                else {cout << " ";}//PRINT BY DEFAULT

                if(j==width - 1)
                    cout << "\xB2";//PRINT RIGHT SIDE
            }
            cout << endl;
        }
        for(int i = 0; i < width + 2; i++){cout << "\xB2";}cout << endl; //PRINT BOTTOM
        cout<<debugger.str();
        debugger.str("");
        debugger.clear(); // Clear state flags.
    }

    StartBattle(){//Setup our initial interactions
        player->SetupBattleInteraction();
        enemy->SetupBattleInteraction();
    }

    void CallReset(){
        CurrentEnemyNum++;
        enemy = Enemys[CurrentEnemyNum];
        player->FullHeal();
        ClearStatesAndInteractions();
        StartBattle();
    }

    bool CallBattle(){//Cause our logic to occur changing the interaction

        //OptionX is Attack or Heal ect, represents our current players selection as an int
        //EnemyOption is our enemys option as a string
        //CurrentEnemyNum is the enemy we are fighting
        if(enemy->GetChargeTimer() > 0){
            enemy->AddToInteraction("Releasing Charged Attack!");
            player->TakeDamage_DeathCheck(enemy->GetAttack()+10);
            enemy->decrementTimer(enemy->GetChargeTimer());
            return true;
        }
        //Attack Heal Defend//Player
        //Attack Defend Charge//Enemy
        //
        //ChooseMove(randomchoice ,enemy);
        //Defend->Anything
        int EnemyChoice = rand()%10;
        int CurrentEnemyMoveNum = CurrentEnemyMoveNum % 3;
        string EnemyOption = CurrentAiGrid[CurrentEnemyNum][CurrentEnemyMoveNum];

        //"Attack", "Defend", "Charge"
        //"Attack", "Defend", "Charge"
        //"Attack", "Defend", "Charge"
        //If either fighter defends, this takes priority and raises their defense
        if(OptionX == Defend){
            player->Defend();
        }
        else if(OptionX == Heal){
            player->Heal(12);
        }

        if(EnemyOption == "Defend"){
            enemy->Defend();
        }
        else if(EnemyOption == "Charge"){
            enemy->Charge();
            enemy->SetChargeTimer(2);

        }


        if(OptionX == Attack){ //If we attack
            int Damage = player->GetAttack();
            if(enemy->GetState() == "Defend"){//If the enemy is defending halve the attack
                Damage = Damage / 2;
                if(enemy->TakeDamage_DeathCheck(Damage)){//If our Damage kills the enemy reset
                    CallReset();
                }
            }
            else{
               if(    enemy->TakeDamage_DeathCheck(Damage - enemy->GetDefense())    ){//If our Damage kills the enemy through its regular defense
                    CallReset();
                }
            }
        }
        if(EnemyOption == "Attack" && OptionX == Heal){//If our enemy attacks
            enemy->setInteraction(enemy->GetName()+" Attacks!");
             player->TakeDamage_DeathCheck(enemy->GetAttack()); //The enemy Attacks, adds taking damage to player interaction
        }
        else if(EnemyOption == "Attack"){
            player->TakeDamage_DeathCheck(enemy->GetAttack()); //The enemy Attacks, adds taking damage to player interaction
        }
    }
    void ClearStatesAndInteractions(){
        enemy->ReturnToNeutral();
        player->ReturnToNeutral();
        enemy->ClearInteraction();
        player->ClearInteraction();
    }
    bool Input()//If our input is true we will need to clear our interactions after drawing
    {
        if(_kbhit()){
            char current = _getch();
            if(current == Enter){//Each turn we get rid of our previous state and interaction
                ClearStatesAndInteractions();//Resets our Interactions and states
                TurnEnd();//Increments the turn
                CallBattle();//Causes our characters to interact
            }
            else if(current == QuitKey){
                quit = true;
            }
            else if(current == Left && !(OptionX == 0)){OptionX --;}//If we arent equal to 0 go Left
            else if(current == Right && !(OptionX == ElementsInArray - 1)){OptionX ++;}//If we arent equal to our upper bound go right
            else if(current == Up){
                //Implement Later complete current dev cycle
            }
            else if(current == Down){
                //Implement Late complete current dev cycle
            }
            return true;
        }
    }
    //MAKE AN MENU CLASS TO USE THIS//PRINTS AN ARRAY USING COUT//MAKE 2D?
    /*friend ostream & operator<<(ostream & o, string OptionArray[]){
        int SizeOfArray = sizeof(OptionArray);
        int SizeOfElement = sizeof(OptionArray[0]);
        int ElementsInArray = sizeof(OptionArray)/sizeof(OptionArray[0]);

        o<< "Greetings" << "" << "," <<""<< "]" << endl;
        for(int i = 0; i<ElementsInArray; i++){
            //if(i == OptionX){
            //    o << " X ";
            //}
            o << OptionArray[i] << "\t\t";
        }
        return o;
    }*/
    void TurnEnd(){
        TurnCount++;
    }
    void Run(){ // Draw(); Input(); Logic();
        //if battling
        StartBattle();//Setup Our Initial Interactions
        Draw();//Our Initial Screen
        while(!quit){//While our input isn't quit
            if(Input()){//If we input our current interactions are added to
                //Logic();
                Draw(); //We redraw
            }

        }
        cout << "GAME IS OVER";
    }
};

int main()
{
    srand(time(NULL)); //SEED RANDOM
    BattleController Manager(60, 30); //SETUP OUR CONTROLLER//WIDTH//HEIGHT
    Manager.Run(); //RUN IT
}
