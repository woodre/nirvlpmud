#include "/players/jareel/define.h"
inherit "/obj/armor.c";

#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "illusion"
#define BONUS_AMOUNT    1

string *Armor_pieces;
int SuperSpeed;

void
init()
{
  ::init();
  add_action("SuperSpeedGo","SuperSpeedGo");
}

reset(arg) {
     ::reset(arg);

     set_name("illusion bracer");
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("bracelet");
     set_short(HIW+"Platinum bracer"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM);
     set_long(
       RED+"         ["+HIG+"Set of Illusion"+NORM+RED+"]\n"+
       "A swirling blue and white crystal encrusted in a soft platinum polished metal.\n"+  
	   "Raw energy pulsates within the chests core crystal.  A thick gold allows the \n"+
	   "bracer to be worn on the persons wrist.  This does not look like it would provide\n"+ 
	   "much protection\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMageBracer", "ArchMageChest", "ArchMageCloak", "ArchMageRing3" });
}

status id(string arg) { return ( ::id(arg) || arg == "ArchMageBracer" || arg == "illusion bracer" ||
                                              arg == "bracer"); }

int wear(string str) { 

if (str && !id(str))
        return 0;
  if ((int)this_player()->query_level() < 15) {
    write("This armor is too powerful for you to wear.\n"); 
    return 1; 
  }

  return (::wear(str) ? 1 : 0);
}

status check_full_set() {
  object MageChest;
  MageChest = present("ArchMageChest", USER);
  if( MageChest )
    return (int) MageChest->query_full_set();

  return 0;
}

#if 0 /* Gnar */
string short() {

  if (check_full_set())
    return (HIW+"Platinum Bracer"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIW+"Platinum Bracer"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+NORM+" (worn)");

  return HIW+"Platinum Bracer"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM+NORM;
}
#endif

string query_short() {

  if (check_full_set())
    return HIW+"Platinum Bracer"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM;
  else
    return HIW+"Platinum Bracer"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM;
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  object MageChest;
  MageChest = present("ArchMageChest", USER);
  if( MageChest )
    MageChest->add_armor_set();

  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus()
{
  object MageChest;
  MageChest = present("ArchMageChest", USER);
  if( MageChest )
    MageChest->del_armor_set();

  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}

do_special(owner) {
  int i;
  if( check_full_set() && !random(10) ) {
    SuperSpeed = 1;
      command("SuperSpeedGo", owner);
    set_params("physical",0,2);
    return 1;
  }
  return 0;
}

int SuperSpeedGo() {
  string attname;
  object wep, att, me;
  if (!SuperSpeed)
    return 1;
  SuperSpeed = 0;
  me = this_player();
  att = (object)me->query_attack();
  wep = (object)me->query_weapon();
  if (!att)
    return 1;
  attname = (string) att->query_name();
  me->toggle_already_fight(1);
  me->attack();

  if (wep && att)
    wep->hit(att);
tell_room(environment(me), 
   me->query_name()+"'s body explodes with blinding "+HIW+"L I G H T\n\
\t"+me->query_name()+"'s Illusion bursts forth from the light to attack "+attname+"!!!"+NORM+"\n");
  return 1;
}
