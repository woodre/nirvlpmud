#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

string *Armor_pieces;

     reset(arg) {
       ::reset(arg);

     set_name("death gauntlets");
     set_ac(2);
     set_value(1200);
     set_weight(2);
     set_type("ring");
     set_short(
       "Iron "+BOLD+BLK+"gauntlets"+NORM+" of death");
     set_long(
       "The gauntlets of death are a dull grey with two\n"+
       "inch protruding spikes from each knuckle.  The\n"+
       "small spikes seem like they would pack quite a\n"+
       "wallup\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "mondar_armor", "mondar_gauntlets" });
     }

status id(string arg) { return ( ::id(arg) || arg == "mondar_gauntlets" || arg == "ring" || arg == "gauntlets" || arg == "gloves"); }

/* Earwax changes begin
     do_special(owner) {
       int i;
         i = random(10);
           if(i==1){
       if(ATT->is_npc())
         ATT->heal_self(-(1+random(3)));
       else ATT->add_hit_point(-(1+random(3000)));
         tell_room(environment(USER),
           CAP(ATT->query_name())+" is smashed with a spinning backhand.\n\n"+
             ""+ATT->query_name()+"'s "+RED+"blood"+NORM+" spurts everywhere.\n");
       return 0;}
       return 0;}
*/

do_special(owner) {
  int i;
  if (random(100) > 100) /* It only hits 1 in 10 times */
    return 0; 
  i = sizeof(Armor_pieces);
  while(i--) {
    object t;
    t = present(Armor_pieces[i], USER);
    if (!t || !((status)t->query_worn()))
      return 0;
  }

  if(ATT->is_npc())
    ATT->heal_self(-(4+random(6)));
  else ATT->add_hit_point(-(4+random(6)));
  tell_room(environment(USER),
  CAP(ATT->query_name())+" is smashed with a spinning backhand.\n\n"+
      ""+ATT->query_name()+"'s "+RED+"blood"+NORM+" spurts everywhere.\n");
  return 100;
}
