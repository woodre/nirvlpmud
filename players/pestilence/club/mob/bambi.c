#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bambi");
  set_alias("stripper");
  set_short("Bambi the stripper");
  set_long("Bambi is a volumptious blonde stripper.  She is wearing no clothes\n"+
           "at all.  Her bush is completely shaved and smooth.  Her tits are huge\n"+
           "and make you just drool.  She has nice long legs, and a really fine\n"+
           "blemish free ass.\n");
  set_race("stripper");
  set_gender("female");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(450);
  set_ep(100000);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Bambi bends over backwards showing you a nice shot of her wet pussy.\n");
  load_chat("Bambi says: come on baby, let me give you a private dance.\n");
  load_chat("Bambi runs her finger over her clitoris, while winking suggestively at you.\n");
  set_chat_chance(20);
  load_a_chat("Bambi screams in delight.\n");
  load_a_chat("Bambi says: oh hit me harder, you know i like it rough.\n");
  set_a_chat_chance(30);
  set_spell_mess2("Bambi hits you with her DD breasts.\n");
  set_spell_mess1("Bambi attacks with her DD breasts.\n");
  set_chance(30);
  set_spell_dam(40);
}



monster_died() {
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Bambi dies you see her cum for the last time.\n");
return 0; }
