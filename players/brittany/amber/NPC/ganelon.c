#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("ganelon");
set_alias("man");
set_alt_name("knight");
set_race("human");
set_short("Ganelon");
set_long("A man in a brown leather jacket over a black shirt, his\n"+
"trousers are also black.  His trousers are bloused over\n"+
"the tops of his dark books.  He has a wide belt which held\n"+
"a hoof-hilted dagger.  His beard is red, with a sprinkling\n"+
"of white, his eyes are dark as ebony.\n");

set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Ganelon asks:  Has Avalon fallen?\n");
load_chat("Ganelon asks:  How came you here from that place?\n");
load_chat("Ganelon says:  I was exiled by its sorcerer.\n");
load_chat("Ganelon asks:  Do you come here to slay me?.\n");
  
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "Ganelon wimpers as he falls dead.\n");
   return 0; }