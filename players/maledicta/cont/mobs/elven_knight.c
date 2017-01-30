#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int gold;

reset(arg)  {
 ::reset(arg);
  if(arg) return;
set_name("elf");
set_alt_name("knight");
set_race("elf");
set_short(HIG+"Elven "+NORM+BOLD+"Knight"+NORM);
set_long(
"  This is a tall elven knight. He is nearly six feet in\n"+
"height and has a very slender build. His body is covered\n"+
"in light elven plate armor and is tinted a light green.\n"+
"He holds a lightweight sword in his right hand with a\n"+
"glowing bracer on his left. He seems ready to do battle\n"+
"if necessary.\n");
set_level(16);
set_hp(450);
set_al(1000);

set_wc(23);
set_ac(12);
set_heart_beat(1);
set_dead_ob(this_object());
set_chance(25);
set_spell_dam(30);
set_spell_mess1(
"The Elven Knight holds forth the glowing bracer...\n"+
"  A giant "+HIG+"Emerald Claw"+NORM+" of light flows from its top crystal!\n"+
"         "+HIR+"RAKE        RAKE          RAKE"+NORM+"\n"+
"His opponent falls back in pain!\n");
set_spell_mess2(
"The Elven Knight holds forth the glowing bracer...\n"+
"  A giant "+HIG+"Emerald Claw"+NORM+" of light flows from its top crystal!\n"+
"  It rushes towards you, "+HIR+"GASHING"+NORM+" you terribly!\n");
set_chat_chance(30);
load_chat("The Elven Knight watches you carefully.\n");
load_chat("The Elven Knight says,'Welcome stranger.'\n");
gold = clone_object("obj/money");
gold->set_money(850 + random(60));
move_object(gold, this_object());
}

monster_died(){
tell_room(environment(),
"As the Knight falls to the ground dead his armor and equipment turn to\n"+
"a light green dust. It blows away on the wind.\n");
return 1;
}
