#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("jim"); 
  set_alias("bouncer");
  set_short("Jim the Bouncer");
  set_long("Jim is the bouncer and head of Security for Pesty's Strip Club.\n"+
           "Jim is six foot five inches and weighes 260 pounds.  He is well\n"+
           "built and does a good job as a bouncer.\n");
  set_race("human");
  set_gender("male");
  set_level(20);
  set_wc(30);
  set_ac(17);
  set_hp(500);
  set_heal(20,3);
  add_money(2000 + random(3000));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  set_assist("/players/pestilence/club/mob/joe.c", 20, 1, 1);
  load_chat("Jim says: do you wanna come in and see some fine young women?\n");
  set_chat_chance(5);
  load_a_chat("Jim says: do you think you could hurt me?\n");
  load_a_chat("Jim pushes you to the ground.\n");
 set_a_chat_chance(30);
set_spell_mess2("Jim punches you in the nose.\n");
set_spell_mess1("Jim starts throwing a flurry of punches.\n");
  set_chance(20);
  set_spell_dam(15);
}

monster_died() {
  tell_room(environment(this_object()),
        "Jim hits the floor, leaving you free reign of the club.\n");
return 0; }
