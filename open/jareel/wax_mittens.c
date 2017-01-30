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
/*
     set_short(
       "Iron "+BOLD+BLK+"gauntlets"+NORM+" of death");
*/
  set_short(HIK+"Earwax's Mittens of Mutton-Eating"+NORM+NORM);
     set_long(
       "The gauntlets of death are a dull grey with two\n"+
       "inch protruding spikes from each knuckle.  The\n"+
       "small spikes seem like they would pack quite a\n"+
       "wallup\n");

  /* Put the id's for your special armors required in here */
  Armor_pieces = ({ "mondar_armor", "wax_mittens" });
     }

status id(string arg) { return ( ::id(arg) || arg == "mondar_gauntlets" || arg == "wax_mittens" || arg == "gauntlets" || arg == "gloves"); }

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

/* changed for testing... should be > 10, not > 100 */
  if (random(100) > 100) /* It only hits 1 in 10 times */
    return 0; /* It was over 10, so kick out */

  i = sizeof(Armor_pieces);

  while(i--) {
    object t;

    t = present(Armor_pieces[i], USER);
    if (t && (status)t->query_worn())
    {
      tell_room(environment(USER), "Special woulda hit here.\n");
      return 100;
      /* This, I'm not sure of....dunno if you do a heal_self() here or hit_player() or whatever
       * Do whatever damage you're going to do, or let it return damage if that's how it works.  You know that kinda shit, I don't :)
      */
    }
    return 0; /* They didn't have all the pieces. */
  }
  return 0; /* Just in case */
}
