#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("Rockhopper penguin");
   set_short("A rockhopper penguin");
   set_alias("penguin");
   set_long("A small sturdy penguin with a black back and white\n\
belly.  A bright yellow crest sprouts from above\n\
clear red eyes and a pointed beak.\n");
   set_type("creature");
   set_level(5);
   set_ac(5);
   set_wc(9);
   set_hp(75);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
}

monster_died(ob) {
  object crest;
  crest = clone_object("/obj/treasure");
  crest->set_id("crest");
  crest->set_short("Rockhopper crest");
  crest->set_long("A feather crest from a rockhopper penguin.\n\
Such crests are rare and of some value.\n");
  crest->set_weight(1);
  crest->set_value(175+random(50));
  tell_room(environment(),"The rockhopper dies, losing it's crest with a final cry.\n");
  move_object(crest,environment(ob));
}

