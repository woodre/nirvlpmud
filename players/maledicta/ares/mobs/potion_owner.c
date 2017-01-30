#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("gratilda");
set_alt_name("gratilda_witch");
set_alias("hag");
set_race("human");
set_short("Gratilda the Hag");
set_long(
"  This is perhaps the oldest human woman in existence.  She is\n"+
"wrinkled beyond recognition and has more moles on her face than\n"+
"should be allowed by law.  Her left eye is a milky white and is\n"+
"obviously blind.  Her hair is patchy and gray in color and hangs\n"+
"down almost to her knees. She is dressed in ancient rags that\n"+
"might have once been a beautiful dress. You can 'ask about wares'\n"+
"if you are interested.\n");
set_level(5);
set_hp(75);
set_al(50);
set_wc(9);
set_ac(5);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Gratilda watches you carefully with her one good eye.\n");
  load_chat("The old hag cackles as she mixes a potion.\n");
  load_chat("Gratilda smacks her lips and tries to remember what she was doing.\n");
gold = clone_object("obj/money");
gold->set_money(200);
move_object(gold,this_object());
}

