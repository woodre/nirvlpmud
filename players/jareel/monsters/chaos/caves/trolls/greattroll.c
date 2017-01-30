/* **********************************************************************
*
********************************************************************** */

inherit "obj/monster.c";
#include "/players/jareel/define.h"

  reset(arg)  {
    ::reset(arg);
  if(arg) return;

  set_name("Great Troll");
  set_alt_name("great");
  set_short(HIK+"Great Troll"+NORM);
  set_alias("troll");

  set_long(
    "This massive beast looms four meters high.  The great maul\n"+
    "clenched in this monstrouse hand looks like the stup of a tree\n"+
    "ripped out of the ground. Hunched over the creature's back\n"+
    "scrapes against the top of the cavern.\n");

  set_spell_mess1("The great troll ROARS as his maul smashes his foe.\n");
  set_spell_mess2("The dark troll crushes you with his maul.\n");

  MOCO("/players/jareel/weapons/greattrollmaul.c"),this_object());
    init_command("wield maul");

  set_chance(25);
  set_spell_dam(100);
  set_race("troll");
  set_al((500-random(500)));
  set_level(26);
  set_hp(1200);
  set_wc(46);
  set_ac(24);
  set_heal(5,1);
  set_aggressive(1);
  add_money(9000+random(2000));
  set_armor_params("other|light",0,-100,0); /* Double damage from light */
  set_armor_params("other|dark",0,100,0); /* Immune from dark */
  set_dead_ob(this_object());
}

heart_beat(){
  ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
  attack();
}
}
     

