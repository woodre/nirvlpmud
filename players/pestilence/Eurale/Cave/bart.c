/*  black Bart - the dark one  */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#include "defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name(HIK+"Black Bart"+NORM);
set_race("human");
set_alt_name("bart");
set_gender("male");
set_short(HIK+"Black Bart"+NORM);
set_alias("black bart");
set_long(
	"  Black Bart, sometimes referred to as Dark Bart, is a heartless \n"+
	"and ruthless killer.  He shows no compassion or foregiveness to \n"+
	"anyone.  His trusty old Colt has many notches on the handle to \n"+
	"remind all that cross his path that it's a deadly road to take. \n"+
	"Beware this bad hombre!! \n");
set_level(26);
set_hp(1400);
set_al(-800);
set_ac(24);
set_heal(31,5);
set_aggressive(1);
set_spell_mess2("Bart smashes you in the head with the butt of his colt.\n");
set_spell_mess1("Bart smashes his attacker with the butt of his colt.\n");
set_chance(20);
set_spell_dam(25);
move_object(clone_object("players/eurale/Cave/OBJ/colt"),TO);
init_command("wield revolver");
set_wc(60);
/*
set_wc_bonus(34);
*/
add_money(random(2500)+9500);
set_chat_chance(6);
  load_chat("Bart sneers:  It's boot hill for you, pardner! \n");
  load_chat("Bart laughs hysterically..... \n");

add_spell("barrage",
"#MN# fires #MP# colt in a barrage, with several $W$bullets$N$ piercing into your flesh.\n",
"#MN# fires #MP# colt in a barrage, with several $W$bullets$N$ piercing into #TN#'s flesh.\n",
 25,"30-55","other|magic",1);

add_spell("critical",
"#MN# fires a $HW$C R I T I C A L$N$ shot into your chest.#RET#You grasp your chest in immense pain!\n",
"#MN# fires a $HW$C R I T I C A L$N$ shot into #TN#'s chest.#RET##TN# grasps #TP# chest in immense pain!\n",
25,"40-120","phyiscal",5);

set_multi_cast(1);
/*
gold = clone_object("obj/money");
gold->set_money(random(2500)+10500);
move_object(gold,this_object());
*/
}
