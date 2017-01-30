/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#define TP this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(BOLD+"Kodragon"+NORM);
set_alias("kodragon");
set_race("dragon");
set_short(BOLD+"Kodragon"+NORM);
set_long(
	"The Kodragon is an extremely rare species of dragon.  It is a\n"+
	"furry dragon about the size of a house cat.  At first glance,\n"+
	"it appears to be a large bat.  Closer inspection reveals that\n"+
	"it is shaped like a dragon, with four spindly legs, a long\n"+
	"sinuous neck and leathery wings.  It has fine gray fur instead\n"+
	"of scales.  It's face has a blunt snout and large luminous\n"+
	"black eyes.\n");

set_level(24);
set_hp(1100 + random(250));
set_al(50);
set_wc(51);
/*
set_wc_bonus(39);
*/
set_ac(25);
set_heal(20,3);
add_money(6000 + random(3000));
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The kodragon flies out of reach...\n");
  load_chat("The kodragon darts between your legs..\n");
  load_chat("The kodragon disappears... and reappears a few feet away..\n");
set_a_chat_chance(15);
  load_a_chat("The kodragons darts behind you and BITES you on the ass..\n");
  load_a_chat("The kodragon flys in a nips at your exposed neck..\n");
  load_a_chat("You miss widely...\n");
  load_a_chat("You stumble as you try to strike the quick dragon..\n");

/*
set_chance(20);
set_spell_dam(45 + random(30));
set_spell_mess1(
  "\n\n"+
  "The Kodragon breaths a cloud of "+HIC+"NOXIOUS GAS"+NORM+"\n\n");
set_spell_mess2(
  "\n\nThe Kodragon breathes "+HIC+"NOXIOUS GAS"+NORM+" in your face..\n\n");
*/

add_spell("breath",
  "\n\nThe Kodragon breathes "+HIC+"NOXIOUS GAS"+NORM+" in your face..\n\n",
  "\n\nThe Kodragon breaths a cloud of "+HIC+"NOXIOUS GAS"+NORM+"\n\n",
20,"45-75","other|poison",0);
add_spell("blast",
HIK+"\n            ____ __ \n"+NORM+
HIK+"           { --.\\  | $HG$         .)%%%)%%\n"+NORM+
HIK+"           '-._\\\\ | (\\___ $HG$  %)%%(%%(%%%\n"+NORM+
HIK+"               `\\\\|{/ ^ _)$HG$-%(%%%%)%%;%%%\n"+NORM+
HIK+"           .'^^^^^^^  /`    $HG$%%)%%%%)%%%'\n"+NORM+
HIK+"          //\\   ) ,  /       $HG$'%%%%(%%'\n"+NORM+
HIK+"    ,  _.'/  `\\<-- \\<\n"+NORM+
HIK+"     `^^^`     ^^   ^^ \n"+NORM,  
"#MN# attacks #TN# with a ferocious barrage.\n",
30,"40-60","other|acid",0);

add_spell("spray",
HIK+"\n                      \\`-\\`-._ \n"+NORM+
HIK+"                         \\` )`. `-.__      ,\n"+NORM+
HIG+"      '' , . _      $HK$ _,-._;'_,-`__,-'    ,/\n"+NORM+
HIG+"     : `. ` , _' :-$HK$ '--'._ ' `------._,-;'\n"+NORM+
HIG+"      `- ,`- '       $HK$     `--..__,,---'  \n"+NORM,  
 "#MN# attacks #TN# with a fierce blast of $HG$A C I D$N$.\n",
30,"60-100","other|acid",1);

/* Updated to the add money, and increased with increased lvl
gold = clone_object("obj/money");
gold->set_money(4000 + random(2000));
move_object(gold,this_object());
*/
}

monster_died() {
  move_object(clone_object("players/eurale/Keep/QST/kodragon.c"),
		this_player());
  write_file("/players/eurale/Keep/LOGS/dragons",
  ctime(time())+"     Kodragon         "+query_attack()->query_real_name()+"\n");
return 0; }
