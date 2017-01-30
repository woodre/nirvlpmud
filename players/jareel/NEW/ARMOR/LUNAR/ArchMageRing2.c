#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

#define GUILDID         "mageobj"
#define BONUS_TYPE      "necromancy"
#define BONUS_AMOUNT    1

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("ring of the necromancer");
     set_ac(0);
     set_value(4200);
     set_weight(1);
     set_type("ring");
     set_short(HIK+"Dark Ring"+NORM+" of the"+HIK+"["+HIW+"Dead"+NORM+HIK+"]"+NORM);
     set_long(
       RED+"                           ["+HIG+"Set of The Necromancer"+NORM+RED+"]\n"+
       "A swirling red and white crystal encrusted in a soft golden polished metal.  Raw energy\n"+
       "pulsates within the amulets core crystal.  A thick gold chain allows the amulet to be worn\n"+
       "a persons neck.  This does not look like it would provide much protection\n");

                     /* PUT THE ARMOR ID FOR THE SET HERE */
  Armor_pieces = ({ "ArchMageBelt", "ArchMageGloves", "ArchMageBoots", "ArchMageRing2" });
     }

status id(string arg) { return ( ::id(arg) || arg == "ArchMageRing2" || arg == "necro ring"); }

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

string short() {

  if (check_full_set())
    return (HIK+"Dark Ring"+NORM+" of the "+HIK+"["+HIW+"Dead"+NORM+HIK+"]"+NORM+BOLD+" ("+NORM+HIG+"Set of the Necromancer"+NORM+BOLD+")"+NORM+" (worn)"+NORM);

  if ((status)this_object()->query_worn())
    return(HIK+"Dark Ring"+NORM+" of the "+HIK+"["+HIW+"Dead"+NORM+HIK+"]"+NORM+HIK+"]"+NORM+NORM+" (worn)");

  return HIK+"Dark Ring"+NORM+" of the "+HIK+"["+HIW+"Dead"+NORM+HIK+"]"+NORM+HIK+"]"+NORM+NORM;
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
  int i;
  if (random(1000) > 200) /* It only hits 20% of the time */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }
    set_params("physical",0,0,"healup3");
}

    healup3(){
      int i;
          i = random(4);
      if(i==1){
         tell_room(environment(USER),
           ""+BOLD+" <<>>"+RED+"Power returns to "+environment()->query_name()+"'s body "+NORM+BOLD+"<<>>\n"+NORM);
		 USER->add_hit_point(5+random(5));
         return 0;}
         return 0;} 