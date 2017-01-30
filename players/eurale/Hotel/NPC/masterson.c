/*  Bat Masterson  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("bat");
set_race("human");
set_short("Bat Masterson");
set_alias("masterson");
set_long(
	"  William Barclay Masterson (1853-1921)  Lawman, buffalo hunter, \n"+
	"scout, gambler, editor.  Died at his typewriter, a New York \n"+
	"sportswriter.  'Sky Masterson' in Guys and Dolls is based on \n"+
	"his character. \n");
set_hp(210);
set_level(14);
set_al(-50 + random(100));
set_wc(18);
set_ac(11);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Bat whispers:  Anyone interested in a card game? \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+800);
move_object(gold,this_object());
}
