#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "illusion"
#define BONUS_AMOUNT    1

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("illusion ring");
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("ring");
     set_short(HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM);
     set_long(
       RED+"              ["+HIG+"Set of Illusion"+NORM+RED+"]\n"+
       "A swirling blue and white crystal encrusted in a soft platinum polished metal.\n"+  
	   "Raw energy pulsates within the rings  rainbow crystals.  A thick gold allows\n"+ 
	   "the bracer to be worn on a persons finger.  This does not look like it would\n"+ 
	   "provide much protection\n"+NORM);

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMageBracer", "ArchMageChest", "ArchMageCloak", "ArchMageRing3" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ArchMageRing3" || arg == "illusion bracer"); }

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

#if 0 /** Gnar -- Moved to query_short */
string short() {

  if (check_full_set())
    return (HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+NORM+" (worn)");

  return HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM+NORM;
}
#endif

string query_short() {
  if( check_full_set() )
    return HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM;
  else
    return HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM;
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
  if (random(1000) > 200) /* Set Res on Player to 8% when you have complete set work. */
    return 0;
  if( check_full_set() ) {
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
