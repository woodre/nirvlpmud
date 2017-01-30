#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("benkei");
  set_race("hero");
  set_gender("male");
  set_alias("warrior");
  set_short("Benkei");
  set_long("Benkei is a tall very well built warrior.  He wears the armor\n"+
    "of a warrior monk and wields the 1.5 meter long katana- the feared\n"+
    "no-dachi.  Benkei refuses to let anyone past him without a fight.\n"+
    "Howver, if you are too scared to fight him you may be able to run by him.\n");
  set_hp(1000);
  set_level(22);
  move_object(clone_object("/players/mythos/awep/forest/nodachi.c"),this_object());
  init_command("wield nodachi");
  set_al(0);
  set_wc(40);
  set_ac(17);
  set_heal(3,20);
  set_aggressive(0);
  set_chat_chance(20);
  set_chat_chance(30);
  set_a_chat_chance(15);
  load_chat("Benkei tells you: I will not let anyone pass without a fight!\n");
  load_chat("Benkei glares at you.\n");
  load_a_chat("Benkei attacks you with great fury and strength.\n");
  load_a_chat("Benkei whispers to you: I will defeat you...\n");
  load_a_chat("Benkei grins.\n");
  move_object(clone_object("/players/mythos/aarmor/forest/robe.c"),this_object());
/* redone as add_spell by illarion 2 dec 2004
  set_chance(40);
  set_spell_dam(random(60));
  set_spell_mess1(BOLD+"\n\t\tSSSSSLLLIIICCCEEEEE\n\n"+NORM+"Benkei cuts through muscle and bone!\n");
  set_spell_mess2(BOLD+"\n\t\tSSSSSLLLIIICCCEEEEE\n\n"+NORM+"Benkei cuts through muscle and bone!\n");
*/
  add_spell("slice",
BOLD+"\n\t\tSSSSSLLLIIICCCEEEEE\n\n"+NORM+"Benkei cuts through your muscle and bone!\n\n",
BOLD+"\n\t\tSSSSSLLLIIICCCEEEEE\n\n"+NORM+"Benkei cuts through #TN#'s muscle and bone!\n\n",
40,60);
  set_mult(2);
  set_mult_chance(30);
  set_mult_dam1(30);
  set_mult_dam2(20);
}
