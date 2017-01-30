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

set_name(HIG+"Green Dragon"+NORM);
set_alias("green dragon");
set_race("dragon");
set_short(HIG+"Green Dragon"+NORM);
set_long(
	"The Green Dragon is one of the most cruel and repulsive denizens\n"+
	"of the dragon breed.  It's smooth, flexible deep green scales\n"+
	"provide very good protection for this giant toad look-alike.\n"+
	"It has tiny wings, webbed feet and bony ridges that surround\n"+
	"it's beady black eyes.  Yellow warts cover most of it's body.\n"+
	"It attacks without warning or provocation.\n");

set_level(24);
set_hp(1100 + random(250));
set_al(-500);
set_wc(51);
/*
set_wc_bonus(39);
*/
set_ac(25);
set_heal(20,3);
  add_money(6000+random(2000));
set_aggressive(1);
set_dead_ob(this_object());
set_chat_chance(15);
  load_chat("The dragon crouches....\n");
  load_chat("You feel the beady-eyed stare of the dragon...\n");
set_a_chat_chance(15);
  load_a_chat("The dragon leaps over you....\n");
  load_a_chat("\nThe Dragon SWINGS IT'S TAIL at you....\n\n");
  load_a_chat("\nThe dragon brushes an acidic wart against you..\n");

/*
set_chance(12);
set_spell_dam(55);
set_spell_mess1(
  "\nThe Dragon breathes a "+HIG+"S T R E A M  of  A C I D"+NORM+"\n\n");
set_spell_mess2(
  "\nThe Dragon breathes a "+HIG+"S T R E A M  of  A C I D"+NORM+" at you.\n\n");
*/
add_spell("acid",
  "\nThe Dragon breathes a "+HIG+"S T R E A M  of  A C I D"+NORM+" at you.\n\n",
  "\nThe Dragon breathes a "+HIG+"S T R E A M  of  A C I D"+NORM+"\n\n",
12,55,"other|poison",0);


add_spell("cloud",
"#MN# breathes a cloud of $HG$A C I D$N$ at you.\n",
"#MN# breathes a cloud of $HG$A C I D$N$ at #TN#.\n",
30,"40-60","other|acid",0);

add_spell("burn",
"  $HG$A $N$\n    $HG$C $N$\n      $HG$I $N$\n        $HG$D $N$\n      Burns your skin!!.\n",
"  $HG$A $N$\n    $HG$C $N$\n      $HG$I $N$\n        $HG$D $N$\n      Burns #TN#'s skin!!.\n",
 30,"60-100","other|acid",1);

/*  Replaced with add_money and updated with new level
gold = clone_object("obj/money");
gold->set_money(4000 + random(2000));
move_object(gold,this_object());
*/
}

monster_died() {
  move_object(clone_object("players/eurale/Keep/QST/greendragon.c"),
		this_player());
  write_file("/players/eurale/Keep/LOGS/dragons",
  ctime(time())+"     Greendragon      "+TP->query_real_name()+"\n");
return 0; }
