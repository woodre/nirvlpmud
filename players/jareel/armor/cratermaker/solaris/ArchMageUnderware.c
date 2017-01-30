#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "illusion"
#define BONUS_AMOUNT    2

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("illusion shorts");
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("underwear");
     set_short(HIK+"Lunar shorts"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM);
     set_long(
       RED+"                ["+HIG+"Set of the Veil"+NORM+RED+"]\n"+
       "Swirling red and white crystals sewn in encrusted soft golden polished\n"+
	   "rivets, pulsate with raw energy.  A fine tailor has allowed the shorts \n"+
	   "to sit snug with any armor.  This does not look like it would provide\n"+
	   "much protection.\n"+NORM);
                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMagePants", "ArchMageUnderware" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ArchMageUnderware" || arg == "shorts"); }

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
  
  t = present(Armor_pieces[0], USER);
  if( !t )
    return 0;
  
  return (int)t->query_worn();
}

#if 0 /* Gnar */
string short() {

  if (check_full_set())
    return (HIK+"Lunar pants"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of the Veil"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Lunar pants"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+NORM+" (worn)");

  return HIK+"Lunar pants"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+NORM;
}
#endif

string query_short() {

  if (check_full_set())
    return HIK+"Lunar shorts"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of the Veil"+NORM+BOLD+")"+NORM;
  else
    return HIK+"Lunar shorts"+NORM+" of "+HIK+"["+HIW+"Illusion"+NORM+HIK+"]"+NORM;
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
  if( !random(5) && check_full_set() )
    set_params("physical",0,0,"powerheal");
}

 powerheal(){
  if( !random(4) ){
    tell_room(environment(USER),
        BOLD+"<<>>"+RED+"Power returns to "+environment()->query_name()+"'s body "+NORM+BOLD+"<<>>\n"+NORM);
	  USER->add_hit_point(5+random(5));
    return 1;
  }
  return 1;
}
