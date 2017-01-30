/*  Dimetrodon  */

inherit "obj/monster.c";
reset(arg) {

::reset(arg);
if(arg) return;
set_name("dimetrodon");
set_race("creature");
set_short("Dimetrodon");
set_alias("dime");
set_long(
 	"  Dimetrodon was a fin-back reptile.  It measured 9 feet long \n"+
	"and was very agile.  At the highest point, its sail could be \n"+
	"7 feet high. \n");
set_level(20);
set_hp(500 + random(40));
set_al(-5);
set_aggressive(1);
set_dead_ob(this_object());

set_wc(30 + random(3));
set_ac(17);


set_chat_chance(5);
  load_chat("The fin slowly raises..... \n");
set_a_chat_chance(7);
  load_a_chat("The dimetrodon nips at you..... \n");


set_chance(8);
set_spell_dam(25 + random(15));
set_spell_mess1(
  "\n\nThe dimetrodon gets in a hard BITE!!! \n\n");
set_spell_mess2(
  "\n\nThe dimetrodon BITES you VERY hard!!!\n\n");

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe big fin collapses and a piece breaks off as the huge\n"+
  "dimetroden falls over on its side..... dead!\n\n");
  move_object(clone_object("players/eurale/Park/OBJ/dime_fin"),
    environment(this_object()));
return 0; }
