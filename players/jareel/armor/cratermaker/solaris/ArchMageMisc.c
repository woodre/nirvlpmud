#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "necromancy"
#define BONUS_AMOUNT    2

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("misc of the red goddess");
     set_ac(0);  /* 0 Ac 0 Res allows for armor to give a better return */
     set_value(4200);
     set_weight(1);
     set_type("misc");
     set_short("A Full Moon "+HIK+"["+HIW+"Glow Spot"+HIK+"]"+NORM+" of the "+RED+"Red Goddess"+NORM);
     set_long(
       RED+"             ["+HIG+"Set of the Caster"+NORM+RED+"]\n"+
       "A swirling red and white crystal encrusted in a soft golden polished metal.\n"+  
	   "Raw energy pulsates within the amulets core crystal.  A thick gold chain \n"+
	   "allows the amulet to be worn a persons neck.  This does not look like it \n"+
	   "would provide much protection.\n"+NORM);

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMageMisc", "ArchMageNecklace" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ArchMageMisc" || arg == "Goddess misc"); }

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
  object t;

  if(!USER || !query_worn() ) return 0;

  t = present(Armor_pieces[1], USER);
  if( !t )
    return 0;

  return (int)t->query_worn();
}

#if 0 /* Gnar */
string short() {

  if (check_full_set())
    return ("A Full Moon "+HIK+"["+HIW+"Glow Spot"+HIK+"]"+NORM+" of the "+RED+"Red Goddess"+NORM+BOLD+" ("+NORM+HIG+"Set of the Caster"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return("A Full Moon "+HIK+"["+HIW+"Glow Spot"+HIK+"]"+NORM+" of the "+RED+"Red Goddess"+NORM+NORM+" (worn)");

  return "A Full Moon "+HIK+"["+HIW+"Glow Spot"+HIK+"]"+NORM+" of the "+RED+"Red Goddess"+NORM+NORM;
}
#endif

string query_short() {

  if (check_full_set())
    return "A Full Moon "+HIK+"["+HIW+"Glow Spot"+HIK+"]"+NORM+" of the "+RED+"Red Goddess"+NORM+BOLD+" ("+NORM+HIG+"Set of the Caster"+NORM+BOLD+")"+NORM;
  else
    return "A Full Moon "+HIK+"["+HIW+"Glow Spot"+HIK+"]"+NORM+" of the "+RED+"Red Goddess"+NORM;
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

do_special(owner) {
  if (random(100) > 22) /* I like the number 22 */
    return 0;

  if( !check_full_set() || !ATT )
    return 0;

  if(ATT->is_npc())
    ATT->heal_self(-(4+random(6)));
  else 
    ATT->add_hit_point(-(4+random(6)));

  tell_room(environment(USER),
  CAP(ATT->query_name())+" is drained in the "+RED+"Lunar"+NORM+" light.\n\n"+
      ""+ATT->query_name()+"'s body looks drained from the power of the "+RED+"Red Goddess\n"+NORM);
  return 10;
}
