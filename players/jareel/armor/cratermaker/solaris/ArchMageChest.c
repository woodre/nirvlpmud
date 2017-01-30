#include "/players/jareel/define.h"
inherit "/obj/armor.c";
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "illusion"
#define BONUS_AMOUNT    1

int armor_set;
void add_armor_set();
void del_armor_set();
int query_full_set();

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("chest of illusion");
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("chest");
     set_short(HIW+"Platinum Chest"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM);
     set_long(
       RED+"            ["+HIG+"Set of Illusion"+NORM+RED+"]\n"+
       "A swirling blue and white crystal encrusted in a soft platinum polished metal.\n"+
	   "Raw energy pulsates within the chests core crystal.  A thick gold allows the \n"+
	   "chests to be worn over the persons shoulder.  This does not look like it would \n"+
	   "provide much protection.\n"+NORM);

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMageBracer", "ArchMageChest", "ArchMageCloak", "ArchMageRing3" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ArchMageChest" || arg == "illusion chest"); }

void check_full_set() {
  int i;

  if(!USER) return 0;
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if( t && (status)t->query_worn())
      add_armor_set();
  }
}

int wear(string str) { 

if (str && !id(str))
        return 0;
  if ((int)this_player()->query_level() < 15) {
    write("This armor is too powerful for you to wear.\n"); 
    return 1; 
  }
  armor_set = 0;
  check_full_set();
  return (::wear(str) ? 1 : 0);
}


#if 0 /* Gnar */
string short() {

  if (check_full_set())
    return (HIW+"Platinum Chest"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIW+"Platinum Chest"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+NORM+" (worn)");

  return HIW+"Platinum Chest"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM+NORM;
}
#endif


string query_short() {
  string msg;

  if (query_full_set())
    msg = HIW+"Platinum Chest"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM;
  else
    msg = HIW+"Platinum Chest"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM;

  if( this_player() && this_player()->query_level() > 50 )
    msg += " <"+armor_set+">";
  return msg;
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  add_armor_set();

  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus()
{
  armor_set = 0;

  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}

do_special(owner) {
  if (random(1000) > 200) /* Set Res on Player to 8% when you have complete set work. */
    return 0; 
  if( query_full_set() ) {
    set_params("physical",0,2,"heal3up");
    return 1;
  }
  else
    return 0;
}

heal3up(){
  if( !random(6) ) {
    tell_room(environment(USER), BOLD+"<<>>Power returns to "+environment()->query_name()+"'s body<<>>\n"+NORM);
    USER->add_spell_point(5+random(5));
    return 1;
  }
  return 0;
}

void add_armor_set() {
  armor_set ++;
}

void del_armor_set() {
  if( armor_set > 0 )
    armor_set--;
}

int query_full_set() { 
  return (armor_set >= sizeof(Armor_pieces) ? 1 : 0);
}
