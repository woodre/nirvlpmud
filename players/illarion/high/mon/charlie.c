inherit "obj/monster";
#include "/players/illarion/dfns.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Charlie DeSalvo");
  set_race("human");
  set_gender("male");
  set_short("A fit and athletic black man");
  set_long(
"Though this man has dark skin, it is light enough to make you think one\n"+
"of his parents was not black.  He wears jeans, tennis shoes, and a\n"+
"t-shirt, but somehow they remind you of combat fatigues.  He moves\n"+
"confidently, and gracefully, almost like a dancer, but not quite.\n");
  set_level(16);
  set_al(150);
  set_hp(400+random(100));
  set_wc(22);
  set_ac(13);
  add_money(750+random(100));
  set_chance(10);
  set_spell_mess1("Charlie whirls and nails you in the head with a spin kick.\n");
  set_spell_dam(30);
  set_spell_mess2("Charlie hits his his opponent with a spin kick to the head.\n");
  set_chat_chance(7);
  load_chat("The man says, \"This is a private dojo.\"\n");
  load_chat("The man says, \"What, you're going to take over my office?\"\n");
  load_chat("The man says, \"All right, if you can pass the initiation, you can join.\"\n");
  set_a_chat_chance(7);
  load_a_chat("Charlie beckons you to attack him again.\n");
  load_a_chat("Charlie moves with astounding grace.\n");
}
id(str) { return ::id(str) || str == "charlie" || str == "man"; }
