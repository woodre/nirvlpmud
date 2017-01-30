#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

move_object(clone_object("/players/softly/point/obj/clasp.c"),this_object());

   set_name("kidd");
   set_short(BOLD + "Ghost" + NORM + " of Captain Kidd");
   set_alias("ghost");
   set_long("\
  A tall thin man with dark eyes and a curved mustache\n\
stands before you.  He wears a rakish dark red hat with\n\
a white feather and a matching red cloak held in place.\n\
with a brass clasp\n");
   set_race("ghost");
   set_level(18);
   set_ac(15);
   set_wc(26);
   set_hp(400);
   set_al(0);
   add_money(2000+random(450)); 
   set_chance(20);
   set_spell_dam(15+random(15));
   set_spell_mess1("Kidd calls on the ghosts of all of the pirates\n"+
                   "who live here to expel you from the lighthouse.\n\n");
   set_spell_mess2(BOLD+"\nKidd calls on the ghosts of all of the pirates\n"+
                   "who live here to expel you from the lighthouse.\n"+NORM); 
   set_dead_ob(this_object());
}

monster_died(ob) {
  object shovel;
  shovel = clone_object("/obj/treasure");
  shovel->set_id("shovel");
  shovel->set_short("A small shovel");
  shovel->set_long("A small shovel with dirt adhering to the blade\n");
  shovel->set_weight(1);
  shovel->set_value(30);
  tell_room(environment(),"As the ghost expires a small shovel falls on the staircase.\n");
  move_object(shovel,environment(ob));

}
