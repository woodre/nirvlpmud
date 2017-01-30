#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "players/mythos/dmon/airmon";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("firedrake");
  set_alias("drake");
  set_race("dragon");
  set_short(RED+"FireDrake"+NORM);
  set_long("A small lithe lizard glares at you with eyes of burning\n\
embers.  Its leathery wings flutter a bit as it assess you.\n");
  set_hp(200 + random(150));
  set_level(15);
  set_al(-500);
  set_wc(18 + random(10));
  set_ac(9 + random(10));
  set_heal(2+random(7),10);
  set_aggressive(1);
  if(random(2)==0) set_gender("male");
  else set_gender("female");
  set_exx(1000000); /* a little under level 16 exp */
  set_mental(random(40));
  set_strategy(random(60));
  set_distance(random(3));
  set_distance_damage(random(20));
  set_distance_hit(HIR+"\n\t\t\tF  L  A  M  E\n\n"+NORM+
    "\t\t\t\t burns into you!\n");
  set_distance_effect("The Drake opens it's mouth and "+RED+"fire"+NORM+
    " spews forth!\n");
  set_chat_chance(random(mental));
  set_a_chat_chance(mental);
  load_chat("The drake circles overhead.\n");
  load_chat("The drake roars!\n");
  load_a_chat("Metallic claws lash out!\n");   
  load_a_chat("Snapping jaws rend flesh!\n");
  load_a_chat("The drake glares at you.\n");
  load_a_chat("The red lizard attcks with great fury!\n");
  load_a_chat("Fire burns about you.\n");
  load_a_chat("The reptile screams in anger!\n");
  if(random(3) == 0)
  {
    set_chance(random(strat));
    set_spell_dam(weapon_class);
    set_spell_mess1("The drake suddenly darts forth and tears flesh from its foe!\n");
    set_spell_mess2("The drake suddenly darts in and rips into you!\n");
  }
  if(random(5) == 0)
  {
    set_mult(2 + random(2));
  }
  set_dead_ob(this_object());
}

query_prevent_shadow() { return 1; }

monster_died()
{
  object leave;
  switch(random(4))
  {
    case 0: leave = clone_object("/players/mythos/dwep/claw.c"); break;
    case 1: leave = clone_object("/players/mythos/darmor/carapace.c"); break;
    case 2: leave = clone_object("/players/mythos/dmisc/tooth.c"); break;
    case 3: leave = clone_object("/players/mythos/dmisc/meat.c"); break; 
  }
  move_object(leave,this_object());
}