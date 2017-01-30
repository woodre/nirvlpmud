#include <ansi.h>
inherit "obj/weapon.c";

int wc, weight;
string owner;

/*GLOBALS*/
int *Wstats; /*Wstats[0] = Weapon Level Wstats[1] = Weapon Exp*/

reset(arg) {
  ::reset(arg);
  if (arg) return;
  if(!wc || !weight || !Wstats || !owner)
  {
    Wstats = allocate(2);
    wc = 17;
    weight = 4;
    Wstats[0] = 1;
    Wstats[1] = 0;
    owner = "The Black Willow";
  }
  set_name("blades");
  set_alias("glove");
  set_short(HIC+"B"+HIK+"lades"+NORM+" of the "+HIK+"B"+HIC+"lack "+HIK+"W"+HIC+"illow"+NORM);
  set_long("Mmmmmm... Blades\n");
  set_class(wc);
  set_weight(weight);
  set_value(0);
  set_owner(owner);
  set_params("other|dark",16,0);
  message_hit=({HIR+"OVERWHELMED"+NORM," with a "+HIR+"deadly"+NORM+" series of attacks",
  RED+"carved"+NORM," with deadly grace, "+HIR+"blood"+NORM+" is splattered everywhere",
  "cackled with glee as"," staggered backwards from the onslaught",
  "left"," gasping for air",
  "hit"," with a simple combination",
  "barely touched"," with a "+HIG+"clumsy"+NORM+" attack sequence",
  "stumbled backward as"," "+HIC+"parried"+NORM+" most of the attack"});
  set_hit_function(this_object());
}

weapon_hit(attacker)
{
  int combo_dam;
  if(attacker && Wstat[0])
  {
    combo_dam = dam_func(Wstat[0],attacker);
  }
  return 0;
}

int
dam_func(int lev, object att)
{
  int att_no,i;
  object wielder;
  string wield_name;
  
  wielder = environment(this_object());
  wield_name = capitalize(wielder->query_name());
  att_no = random(lev+1);
  while(att_no > 0)
  {
    switch(10)
    {
      case 0:
        
    }
  }
}