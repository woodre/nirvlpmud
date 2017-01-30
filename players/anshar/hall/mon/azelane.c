#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "obj/monster";

reset(arg)
{
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("azelane");
  set_short("A beautiful dark haired woman");
  set_alias("woman");
  set_race("goddess");
  set_long("     As you look at this beautiful woman, you cannot help\n\
but stand in wonder that so lovely a lady can even exist.\n\
With long flowing hair as dark as night, skin as lustrous\n\
and pale as moonlight and eyes of pale green flame, few\n\
could deny her allure. Few also could deny the dangerous\n\
calm with which she eyes you.\n");
  set_hp(800);
  set_level(20);
  set_al(-1000);
  set_wc(40);
  set_ac(15);
  set_aggressive(0);
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("Azelane smiles with sinister intent.\n");
  load_chat("Azelane's eyes flare brightly.\n");
  load_a_chat("You are chilled to the bone by Azalane's unfeeling glare.\n");
  set_chance(40);
  set_spell_dam(100);
  set_spell_mess1("Azelane fires a bolt of "+GRN+"green energy"+NORM+" at her attacker.\n");
  set_spell_mess2("A bolt of " + GRN + "green death" + NORM +
    " slams into you, you can feel yourself being unmade.\n" +
    "The smell of singed flesh permeates the air.\n");
}
