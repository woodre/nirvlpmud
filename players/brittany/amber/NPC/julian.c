#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("julian");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Prince Julian");
set_long("A man with dark hair hanging long and blue eyes.  He is dressed in\n"+
"a scaled white armor, not silver or metallic colored, but looking as\n"+
"if enameled.  It has a decorative and festive appearance. \n");

set_gender("male");
set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(8);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
set_chat_chance(5);
load_chat("Julian exclaims.  What a surprise!\n");
load_chat("Julian says:  I enjoy slaughting beasts.\n");
load_chat("Julian says:  Eric set me to watch this road.\n");
load_chat("Julian says:  If your going to kill me be about it.\n");
  
   gold = clone_object("obj/money");
gold->set_money(450);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/amber/OBJ/Ransword.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The prince wimpers as he falls dead.\n");
   return 0; }