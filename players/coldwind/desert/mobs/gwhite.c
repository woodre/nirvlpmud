#include "/players/coldwind/define.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/coldwind/desert/weapons/cleaver.c"),this_object());
init_command("wield weapon");

set_name("giant");
set_alt_name("slave");
set_race("giant");
set_short(HIW+"White giant slave"+NORM);
set_long(
"  The white giant studies your moves as he walks slowly closer\n"+
"to you. His skin is pale white, while his eyes, hair and beard are\n"+
"of a silver gray color. He stands over ten feet tall, carrying a \n"+
"heavy cleaver in his right.\n"+NORM);
set_level(20);
set_hp(500);
set_al(-220);
set_gender("male");
set_dead_ob(this_object());
set_wc(30);
set_ac(17);
set_aggressive(0);
set_chat_chance(5);
  load_chat("The slave screams madly...\n"+
  "          GUAARAAAAHH\n");
  load_chat("You take a step back.\n");
  load_chat("The giant moves his weapon angrily.\n");
set_a_chat_chance(15);
  load_a_chat("The giant glares at you.\n");
  load_a_chat("The giant throws a wild swing at you!\n");
  load_a_chat("The slave misses your neck by inches..\n");
  set_wc_bonus(16);
   set_chance(40);
  set_spell_dam(40);
  set_spell_mess1("The giant grabs his enemy by the neck and "+HIR+"SLAM"+NORM+" them into the ground\n");
  set_spell_mess2("The giant grabs you by the neck and "+HIR+"SLAMS"+NORM+" you into the ground!\n");

}

monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  move_object(clone_object("/players/coldwind/desert/items/soul_4.c"),
      environment(this_object()));
	  if(corpse)

return 1; }