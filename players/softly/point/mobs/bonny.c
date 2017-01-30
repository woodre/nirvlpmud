#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("bonny");
   set_short(BOLD + "Ghost" + NORM + " of Anne Bonny");
   set_alias("ghost");
   set_long("\
  A well endowed young woman with fiery red hair and\n\
wearing men's clothing and a handkerchief tied around\n\
her head, stares off into the distance.\n");
   set_race("ghost");
   set_level(19);
   set_ac(16);
   set_wc(28);
   set_hp(450);
   set_al(0);
   set_chance(35);
   set_spell_dam(25);
   set_spell_mess1("Bonny fires her pistol.\n");
   set_spell_mess2("\nBonny fires her pistol.  You are hit.\n"+
                   "You feel "+HIR+"blood "+NORM+"running down your body.\n");
   add_money(2000+random(500));   
   set_dead_ob(this_object());
}

monster_died(ob) {
  object pistol;
  pistol = clone_object("/obj/weapon");
  pistol->set_id("pistol");
  pistol->set_short("Firing Pistol");
  pistol->set_long("The firing pistol has a steel grey finish and wooden\n\
stock.  A small skull and crossbones is carved in the stock.\n");
  pistol->set_type("bow");
  pistol->set_class(17);
  pistol->set_weight(1);
  pistol->set_value(1500);
  pistol->set_alt_name("gun");
  tell_room(environment(),"As the ghost expires a pistol clatters onto the staircase.\n");
  move_object(pistol,environment(ob));

}
