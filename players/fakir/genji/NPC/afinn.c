#include "/players/fakir/color.h"
inherit "obj/monster.c";
  
reset(arg)  {
object armor;
  ::reset(arg);
  if(arg) return;
  
add_money(400);
set_name("aelfinn");
set_alias("finn");
set_race("snake");
set_short("Aelfinn");
set_long(
  "Glistening scales of blue and green cover the snakelike body\n"+
"of the Aelfinn, and shimmer with the rhythm of his breathing.\n"+
"Short legs and double jointed knees give him the appearence of\n"+
"a cripple, though the short club he carries would say otherwise.\n"+
"A slender forked tounge flicks out of his thin lips from time\n"+
"to time, testing the air.  He watches you closely.\n"); 

move_object(clone_object("/players/fakir/genji/ARM/askin.c"),
(this_object()));
init_command("wear skin");
set_level(16);
set_hp(140+random(50));
set_al(-500);
set_wc(22);
set_ac(13);
set_aggressive(0);
set_chat_chance(5);
  load_chat("The Aelfinn rasps: You'sss has'sss summoned me'sss here.  What is'sss thy bidding?\n");
set_a_chat_chance(15);
  load_a_chat("The Aelfinn rasps: This'sss is'sss a good day to dies'sss.\n");

set_chance(20);
set_spell_dam(10);

set_spell_mess1(
  "The Aelfinn's scales shimmer bright"+BOLD+BLUE+" blue"+OFF+" and"+BOLD+GREEN+" green"+OFF+" and sparks dance across his skin.\n");
set_spell_mess2(
  "The Aelfinn's scales shimmer bright"+BOLD+BLUE+" blue"+OFF+" and"+BOLD+GREEN+" green"+OFF+".  Sparks fly into your eyes.\n");
}
