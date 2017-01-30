/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#include "defs.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name(HIR+"Hellhound"+NORM);
  set_alt_name("hellhound");
  set_race("hound");
  set_short("Hellhound");
set_long(
	"  This huge, shaggy, grey-black animal resembles a giant dog \n"+
	"except that it's eyes glow red and it has a stare that will \n"+
	"pierce your soul.  It's putrid breath comes from devouring long \n"+
	"dead carrion.  It's slender yet muscular body would lend itself \n"+
	"well to either fighting or running down it's prey. \n");
  set_hp(900+random(200));
  set_level(24);
  add_money(4000+random(1000));
  set_al(-1000);
  set_wc(42+random(6));
/*
  set_wc_bonus(43);
*/
  set_ac(22+random(8));
  set_heal(25,5);
  set_aggressive(1);
  set_dead_ob(this_object());
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("The hellhound growls and bares it's huge canines.. \n");
  load_chat("Glowing red eyes pierce your soul.... \n");
  load_chat("Slime drips from it's quivering mouth in anticipation. \n");
  load_chat("The hair stands up on the back of your neck... \n");
	load_a_chat("The huge beast snaps at you.. \n");
	load_a_chat("The hellhound quickly circles behind you... \n");
/*
  set_chance(10);
  set_spell_dam(60);
set_spell_mess1(
	"\n\nThe hellhound's huge jaws clamp down and... \n\n"+
	"         P I E R C E S \n\n"+
	"it's victim's flesh to the bone. \n\n");
set_spell_mess2(
	"\n\nThe hellhound's huge jaws clamp down and... \n\n"+
	"          P I E R C E S \n\n"+
	"your flesh to the bone. \n\n");
*/

add_spell("pierce",
"\n\nThe hellhound's huge jaws clamp down and... \n\n"+
"          P I E R C E S \n\n"+
"your flesh to the bone. \n\n",
"\n\nThe hellhound's huge jaws clamp down and... \n\n"+
"         P I E R C E S \n\n it's victim's flesh to the bone. \n\n",
10,60,0,0);
add_spell("bite",
"#MN#\n          $HR$B I T E S$N$\n                    you with his mighty jaws.\n",
"#MN#\n          $HR$B I T E S$N$\n                    #TN# with his mighty jaws.\n",
20,"70-100",("physical"),0);
add_spell("breath",
"\n$R$Flames$N$ ignite your skin as fire erupts from the mouth of #MN#\n\n",
"\n$R$Flames$N$ ignite #TN#'s skin as fire erupts from the mouth of #MN#\n\n",
30,"70-100","other|fire",1);
}

monster_died() {
  move_object(clone_object("players/eurale/Cave/OBJ/canines"),
      environment(this_object()));
return 0; }
