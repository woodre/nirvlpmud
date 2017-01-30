#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
object gold, ob, ob2;
  ::reset(arg);
  if(arg) return;

set_name("corwin");
set_alias("man");
set_alt_name("prince");
set_race("human");
set_short("Lord Corwin");
set_gender("male");
set_long("The first thing you notice about this man is his big GREEN eyes.\n"+
"His hair is black and he is dressed in black and silver.  He is wearing\n"+
"a cloak that is slightly furled as by a wind, silver gloves and black\n"+
"boots.  The clasp around his neck is cast in the form of a silver rose.\n"+
"He is holding a heavy blade at his side.\n");

set_level(12);
   set_hp(180);
   set_wc(16);
   set_ac(9);
   set_al(0);
   ob=clone_object("/players/brittany/amber/OBJ/grayswindir.c");
   move_object(ob,this_object());
   ob2=clone_object("/players/brittany/amber/OBJ/cloak.c");
   move_object(ob2,this_object());
   init_command("wield grayswindir");
   init_command("wear cloak");
   set_aggressive(0);
   set_dead_ob(this_object()); 
   
   gold = clone_object("obj/money");
gold->set_money(550);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_obect("/players/brittany/amber/OBJ/grayswindir.c"),
		this_object());
   tell_room(environment(this_object()),
"The prince wimpers as he falls dead.\n");
   return 0; }
