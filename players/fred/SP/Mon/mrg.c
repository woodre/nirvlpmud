#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object hat;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("mr. Garrison");
set_alias("garrison");
set_race("human");
set_short("Mr. Garrison");
set_long(
  "  Mr. Garrison is the boys' teacher at school.  He is slightly\n"+
  "balding, has glasses, and isn't all there if you know what I mean.\n"+
  "His best friend is a hand puppet that he has with him at all times.\n");
  
add_money(400);
set_level(12);
set_hp(180);
set_al(500);
set_wc(16);
set_aggressive(0);
set_chat_chance(8);
  load_chat("Mr. Garrison says: Did you ask Mr. Hat?\n");
  load_chat("Mr. Garrison says: I really think you should ask Mr. Hat.\n");
  load_chat("Mr. Garrison says: Well what do you think Mr. Hat?\n");
set_a_chat_chance(8);
  load_a_chat("Mr. Garrison cries: Save yourself Mr. Hat, it's to"+
              " late for me.\n");   
	hat = clone_object("/players/fred/SP/Obj/mhat.c");
      move_object(hat, this_object());
	command("wear hat", this_object());
set_ac(9);
}


