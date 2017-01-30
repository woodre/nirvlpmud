#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("gug");
set_alias("gug");
set_alt_name("sentry");
set_race("monster");
set_short("Gug Sentry");
set_long("The sentry's paws are two and a half feet across,\n"+
"with formidable talons.  It's arms are black-furred\n"+
"and attached to short forearms.  It has a head the\n"+
"size of a barrel.  It's eyes are pink and it has\n"+
"huge yellow fangs running from the top to the\n"+
"bottom of it's head with a vertical opening.\n");

set_level(18);
set_hp(450);
set_al(0);
set_wc(26);
set_ac(15);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(6);
  load_chat("Sentry growls angrily. \n");
set_a_chat_chance(15);
load_a_chat("Sentry growls.\n");

set_chance(15);
set_spell_dam(30+random(40));

set_spell_mess1(
"Sentry bites its opponent's arm, cutting into a chunk of skin.\n");
set_spell_mess2(
"Sentry bites your arm, cutting into a chunk of skin.\n");
}

monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/fang.c"),
      this_object());
  tell_room(environment(this_object()),
"The ground trembles as the Sentry falls dead.\n");
return 0; }
