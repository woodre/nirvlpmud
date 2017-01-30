/*  Zapata  */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#include "/players/eurale/defs.h"
inherit "obj/monster";
reset(arg) {

object hat, gold;
::reset(arg);
if(arg) return;
set_name(YEL+"Zapata"+NORM);
set_race("bandito");
set_alt_name("zapata");
set_short(YEL+"Zapata"+NORM);
set_long(
	"  This handsome Mexican bandito is dressed in black.  His drooping \n"+
	"moustache and jet black hair give him the look of evil.  He has \n"+
	"a beautiful Mexican sombrero that is colorful and shades his eyes \n"+
	"and face from the hot western sun. \n");
set_level(24);
set_hp(940);
set_al(-300);
set_wc(43);
set_wc_bonus(17);
set_aggressive(1);
set_ac(21);
set_heal(10,4);

add_money(random (1000) + 6000);
move_object(clone_object("players/eurale/Maze/OBJ/sombrero"),TO);
init_command("wear sombrero");

set_chat_chance(5);
  load_chat("The bandito looks you over very carefully. \n");
  load_chat("Zapata mumbles:  You should not be here, senor. \n");

add_spell("sombrero",
"#RET#$HY$                _-'-_$N$\n"+
"$HC$               /_-_-_\\$N$\n"+
"$Y$       _______$HM$|-_-_-_-|$N$$Y$________$N$\n"+
"$Y$      (________________________)$N$\n"+
"$HR$      ! ! ! ! ! ! ! ! ! ! ! ! !$N$\n",
"#MN# throws his Sombrero at #TN#.#RET#The Sombrero returns to #MN#.\n",
25,40,0,5);

add_spell("gun",
  "#MN# F#RET#          I#RET#             R#RET#                E#RET#                  S#RET#a shot into #TN#'s chest.\n", 
  "#MN# F#RET#          I#RET#             R#RET#                E#RET#                  S#RET#a shot into #TN#'s chest.\n", 
20,40,0,0);
/*
gold = clone_object("obj/money");
gold->set_money(random(100)+950);
move_object(gold,this_object());
*/
}
