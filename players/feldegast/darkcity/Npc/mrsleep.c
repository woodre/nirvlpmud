/* 
This is the small Stranger who liked to bite. 
*/
#include "../def.h"
inherit STRANGER;

reset(arg) {
  ::reset(arg);
  if(!present("knife")) {
    move_object(clone_object(ARM_PATH+"trenchcoat"),this_object());
    init_command("wear trenchcoat");
    move_object(clone_object(PATH+"Wep/sdagger"),this_object());
    init_command("wield knife");
  }
  if(arg) return;
  set_name("Mr. Sleep");
  set_alt_name("mister");
  set_alias("sleep");
  set_short("Mr. Sleep");
  set_long(
    "Mr. Sleep is a stranger with an unusually young body,\n"+
    "perhaps 7-8 years old.  Nevertheless, he is a ruthless\n"+
    "and dangerous foe.  Like all Strangers, he is thin, pale\n"+
    "and completely absent of hair.\n"
  );
  set_gender("male");
  set_race("stranger");
  set_level(20);
  set_wc(28);
  set_ac(15); /* +ac2 armor */
  set_ac_bonus(2);
  set_hp(550);
  set_al(-1000);
  set_aggressive(1);
  set_chat_chance(5);
  set_a_chat_chance(0);
  load_a_chat("Mr. Sleep warps reality around him.\n");
  load_a_chat("Mr. Sleep slashes with his knife, spilling "+RED+"blood"+NORM+" freely.\n");
  set_chance(30);
  set_spell_mess1(
"\nMr. Sleep projects a column of "+HIM+"warped reality"+NORM+" at his foe.\n");
  set_spell_mess2(
"\nMr. Sleep projects a column of "+HIM+"warped reality"+NORM+" at you.\n");
  set_spell_dam(40);
}
