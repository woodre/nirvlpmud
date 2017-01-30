#include "/players/fakir/color.h"
inherit "obj/monster.c";
  
reset(arg)  {
object armor;
  ::reset(arg);
  if(arg) return;
  
set_name("burfinn");
set_alias("finn");
set_race("snake");
set_short("Burfinn");
set_long(
  "Dull, flat scales of grey and black cover the snakelike body\n"+
"of the Burfinn, and curved horns grow from the crown of its head.\n"+
"The Burfinn sits coiled upon its long whip-like tail, which lies\n"+
"twitching upon the floor of the room.  Many have tried to 'cut'\n"+
"the tail from the Burfinn...few have survived to tell the tale.\n"+
"A slender forked tounge flicks in and out from the creatures lips,\n"+
"testing the air.  He watches you closely.\n"); 

move_object(clone_object("/players/fakir/genji/ARM/bskin.c"),
(this_object()));
init_command("wear skin");
set_level(18);
set_hp(375+random(50));
set_al(-500);
set_wc(26);
set_ac(15);
set_aggressive(0);
set_chat_chance(5);
  load_chat("The Burfinn rasps: What is'sss thy bidding?\n");
  load_chat("The Burfinn whispers: My'sss tail has many uses'sss.\n");
set_a_chat_chance(15);
  load_a_chat("The Aelfinn rasps: You'sss cannot cut my tail from me'sss.\n");

set_chance(20);
set_spell_dam(10);

set_spell_mess1(
  "The Burfinn's tail slashes "+BOLD+BLUE+" through the air"+OFF+" and"+BOLD+GREEN+" smacks you"+OFF+" on the head.\n");
set_spell_mess2(
  "The Burfinn's tail slashes "+BOLD+BLUE+" through the air"+OFF+" and"+BOLD+GREEN+" flashes brightly"+OFF+".\n");
}
