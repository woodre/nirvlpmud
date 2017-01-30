#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "wisdom"
#define BONUS_AMOUNT    1

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("wisdom ring");
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("ring");
     set_short(HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Wisdom"+NORM+HIK+"]"+NORM);
     set_long(
       RED+"              \n"+
       "A swirling blue and white crystal encrusted in a soft platinum polished metal.\n"+  
	   "Raw energy pulsates within the rings  rainbow crystals.  A thick gold allows\n"+ 
	   "the bracer to be worn on a persons finger.  This does not look like it would\n"+ 
	   "provide much protection\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMageBracer", "ArchMageChest", "ArchMageCloak", "ArchMageRing3" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ArchMageRing4" || arg == "wisdom ring"); }

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
  int i;

  if(!USER) return 0;
  i = sizeof(Armor_pieces);

  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);

    if (!t || !((status)t->query_worn()))
      return 0;
  }
  return 1;
}

#if 0 /* Gnar */
string short() {

  if (check_full_set())
    return (HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+NORM+" (worn)");

  return HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM+NORM;
}
#endif

string query_short() {

  if (check_full_set())
    return HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of Illusion"+NORM+BOLD+")"+NORM;
  else
    return HIW+"Platinum Ring"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+HIK+"]"+NORM;
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
        present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}