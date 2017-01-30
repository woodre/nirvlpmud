#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("dworkin");
set_alias("man");
set_alt_name("jester");
set_race("human");
set_short("Jester Dworkin");
set_long("A tiny man around five feet tall and hunchbacked.  His\n"+
"hair and beard are thick.  He has a long, hooked nose and\n"+
"he has almost black eyes.\n");

set_level(8);
set_hp(120);
set_wc(12);
set_ac(7);
set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());

set_chat_chance(5);
load_chat("Dworkin chuckles in the shadow.\n");
load_chat("Dworkin ask:  Trying to escape?\n");
   
   gold = clone_object("obj/money");
gold->set_money(350);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The jesters dies.\n");
   return 0; }