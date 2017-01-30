inherit "obj/monster.c";
#include "/players/fakir/color.h"

reset(arg)  {
  ::reset(arg);
  if(arg) return;
add_money(60);
set_name("imp");
set_race("fairy");
set_short("Sneaky"+RED+" Imp"+OFF);
set_long(
  "The flat cheekbones and square nose would almost make one think this tiny\n"+
  "fellow a member of the Troll's.  His dark eyes shift constantly from place\n"+
  "to place and the miniature body seems somehow out of proportion.\n");

move_object(clone_object("/players/fakir/woods/WEP/dagger.c"),
(this_object()));
init_command("wield dagger");

set_level(3);
set_hp(45);
set_al(-200);
set_wc(6);
set_ac(4);
set_aggressive(0);

set_chat_chance(10);
  load_chat("Imp says: Your ugly and your mother dresses you funny, human.\n");
  load_chat("Imp says: I shall make an ashtray of your empty skull you foolish person.\n");
  load_chat("Imp says: Hey! Your pants are unzipped...\n");
  load_chat("Imp says: You are one smelly human. Go take a bath.\n");
  load_chat("Imp says: You will be lost in these woods...no way out humans!\n");
  
set_a_chat_chance(15);
  load_a_chat("Imp says: You can't catch me if I run.  H E L P he's killing me!\n");
  load_a_chat("Imp says: Yikes, its got a sharp thingy. We must run very fast now.\n");

}

