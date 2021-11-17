#include <iostream>
using namespace std;


int GenRandomNum(int min, int max){
  int minRange,maxRange,sub;
    minRange = min;
    maxRange = max;
    sub = maxRange - minRange;
    int addDamage = rand() % (sub + 1) + minRange;

    return addDamage;
}
class Player{
  public:
  int maxRange,minRange,baseDamage,maxHealth;
  int baseHealth;
  string name;

  public:
  int getHealth()
  {
    return baseHealth;
  }
  string getName()
  {
    return name;
  }
void Damage(Player *player)
{
    int range_damage = GenRandomNum(minRange, maxRange);
    int total_damage = baseDamage + range_damage;
    player->baseHealth = player->baseHealth - total_damage;
    if(player->baseHealth <= 0)
     {
      player->baseHealth = 0;
      cout<<"\n\n"<<player->getName()<<" deals a total damage of "<<total_damage<<". Health after damage : "<<player->baseHealth<<endl;  
    }
    else
    {
      cout<<"\n\n"<<player->getName()<<" deals a total damage of "<<total_damage<<". Health after damage : "<<player->baseHealth<<endl; 
    } 
}
void Heal()
{
   int range_health = GenRandomNum(minRange, maxRange);
   if(baseHealth == maxHealth)
    {
      cout<<"Can't heal anymore. Health is already reached max : "<<baseHealth<<endl;
    }
    else if(baseHealth < maxHealth)
    {
      baseHealth = baseHealth + range_health;
      
      if(baseHealth > maxHealth)
      {
        baseHealth = maxHealth;
        cout<<"Health Fully Restored : "<<baseHealth<<endl;
      }
      else
      {
        cout<<"Healed "<< range_health <<" Of Max Health. New health is : "<<baseHealth<<endl;
      }
    }
  }
   void Info()
  {
  cout<<endl<<"Base Health: "<<baseHealth<<" | Base Damage: "<<baseDamage<<" | Heal and Health: "<<minRange<<" - "<<maxRange<<endl;
  // cout << "------------------------------------------------------\n"<<endl;
  }
  // void Display()
  // {
  //   cout<<endl<<"Name: "<<name<<endl<<"Health remaining: "<<baseHealth<<endl;
  //   cout << "------------------------------------------------------\n"<<endl;
  // }
};

class Venom : public Player
{
public:
Venom()
{
maxHealth = 200;
baseHealth = 200;
baseDamage = 7;
name = "VENOM";
minRange = 1;
maxRange = 5;
}
};

class Mutant : public Player
{
public:
Mutant()
{
maxHealth = 150;
baseHealth = 150;
baseDamage = 15;
name = "MUTANT";
minRange = 6;
maxRange = 12;
}
};

class Kratos  : public Player
{
public:
Kratos()
{
maxHealth = 100;
baseHealth = 100;
baseDamage = 7;
name = "Kratos";
minRange = 10;
maxRange = 20;

}
};

void startUpMenu()
{
  Venom vnm;
  Mutant mute;
  Kratos kts;

  cout<<"-----------------Welcome to The Armor Game----------------"<<endl;

  cout<<"\nHello Warrior, Please select the Type of the Player that you want \nto choose."<<endl;
  cout<<"_____________________________________________________________"<<endl;


  cout<<"\nThere are Three types of Players"<<endl<<endl;

  
  cout<<"1)Name:VENOM \nVenom who can perform black magic and potions to heal themselves possess high health:";
  vnm.Info();
  cout<<"----------------------------------------"<<endl;
  
  cout<<"\n2)Name: MUTANT \nMutant who have a great mind to build bombs and do ranged damage to the enemies:";
  mute.Info();
    cout<<"----------------------------------------"<<endl;
 
  cout<<"\n3)Name: KRATOS \nKratos the mightiest of all possess very high base and additional damage that can be done by their bloodlust claws:";
   kts.Info();
   cout<<"----------------------------------------"<<endl;
}

void checkHealth(Player player1[],Player player2[])
{
 if(player1->getHealth() <= 0)
 {
   cout<<endl<<endl<<"-----------FINAL FLASH---------"<<endl;
   cout<<player2->getName()<<" Final Bow was Massive that made "<<player1->getName()<<"\nunable to fight."<<endl;
   cout<<player2->getName()<<" Won!!!"<<endl;
 }
 else if(player2->getHealth() <= 0)
 {
  cout<<"\n\n-----------EXPELLIARMUS-----------"<<endl;
  cout << player1->getName() << "'s final blow was massive that made " << player2->getName() << ", \nunable to fight." << endl;
    cout << player1->getName() << " won!!!" << endl;
  }
 }
int main()
{
srand(time(0));
Player *player[3];
int choice;
char userInput;
startUpMenu();


for(int i=0;i<2;)
{
  cout<<"\nPlayer "<<i+1<<" please select your Hero : ";
  cin>>choice;

switch(choice)
    {
      case 1:
        cout<<"Vohoo!! you chose the 'VENOM' with great healing techniques."<<endl;
        player[i] = new Venom();
        i++;
        break;

      case 2:
        cout<<"Vohoo!! you chose the 'MUTANT'. Save yourselves from my poisonous bombs!!!!!"<<endl;
        player[i] = new Mutant();
        i++;
        break;

      case 3:
        cout<<"Vohoo!! you chose the most powerful hero 'Kratos'"<<endl;
        player[i] = new Kratos();
        i++;
        break;

      default:
        cout<<"Invalid hero code."<<endl;
        break;
    }  
}
       cout<<"----------------------"<<endl;


      while(player[0]->getHealth() >= 0 && player[1]->getHealth() >= 0) 
  {
    cout<<player[0]->getName()<<" press 'A' to attack or 'H' to heal : ";
    cin>>userInput;

    if(userInput == 'a' || userInput == 'A')
    {
      cout<<player[0]->getName()<<" attacked..."<<endl;
      player[0]->Damage(player[1]);
      if(player[1]->baseHealth <= 0)
      {
        break;
      }
    }
  
    if(userInput == 'h' || userInput == 'H')
    {        
      cout<<player[0]->getName()<<" is healing..."<<endl<<endl;
      player[0]->Heal();
    }
     cout<<player[1]->getName()<<" press 'A' to attack or 'H' to heal : ";
     cin>>userInput;

    if(userInput == 'a' || userInput == 'A')
    {
      cout<<player[1]->getName()<<" attacked..."<<endl<<endl;
      player[1]->Damage(player[0]);
      if(player[0]->baseHealth <= 0)
      {
        break;
      }
    }

    if(userInput == 'h' || userInput == 'H')
    {
      cout<<player[1]->getName()<<" is healing..."<<endl;
      player[1]->Heal();
    }
    checkHealth(player[0],player[1]);
  }
  checkHealth(player[0],player[1]);
}
