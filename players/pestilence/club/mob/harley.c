#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/pestilence/club/wep/bbottle.c"),
        this_object());
  command("wield beer bottle");
  set_name("Harley");
  set_alt_name("harley");
  set_alias("harley the pervert");
  set_short("Strip club customer named Harley");
  set_long("Harley is 5 feet and 8 inches tall, with short brown hair and blue\n"+
           "eyes.  Harley looks like a guy who takes his strip club experience\n"+
           "very serious. One might not mess with him while he's in this\n"+
           "enviroment.  He is one of regular customers of Pesty's Strip Club.\n");
  set_race("human");
  set_gender("male");
  set_level(18);
  set_wc(32);
  set_ac(14);
  set_hp(700);
  set_heal(5,3);
  add_money(2000+ random(1000));
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Harley says: I love it when Bambi twirls around the pole.\n");
  load_chat("Harley says: Dude, I think that one has hemmorhoids.\n");
  set_chat_chance(20);
  load_a_chat("Harley says: Listen asshole, I'm trying to watch the girls.\n");
  load_a_chat("Harley says: Seriously, stop fucking around.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Harley hits you with a solid right hand.\n");
  set_spell_mess1("Harley throws a solid right hand, hitting his opponent solidly.\n");
  set_chance(15);
  set_spell_dam(35);
}
id(str) { return (::id(str) || str == "pervert"); }
