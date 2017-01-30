/*  Updated 10/18/01 to conform to /doc/build/RULES/monster.guide  */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIG+"Amphidragon"+NORM);
set_alt_name("amphidragon");
set_race("dragon");
set_short(HIG+"Amphidragon"+NORM);
set_long(
	"This cross between the green and sea dragons is one of the most\n"+
	"cruel denizens of the dragon breed.  Though it has smooth and\n"+
	"flexible, deep green scales like the green dragon, it more\n"+
	"closely resembles a giant toad with tiny, vestigal wings and\n"+
	"webbed feet.  Bony ridges surround it's beady black eyes.\n");

  set_level(24);
  set_hp(1100 + random(250));
  set_al(0);
  set_wc(51);
/*
  set_wc_bonus(39);
*/
  set_ac(25);
  set_aggressive(1);
add_money(6000+random(2000));
  set_heal(20,3);
  set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Tiny bubbles escape the dragon's nose...\n");
  load_chat("You see a sinister face through the murky water...\n");
set_a_chat_chance(15);
  load_a_chat("You feel the STING of the dragon's tongue...\n");
  load_a_chat("Your eyes and skin burn from something in the water..\n");
  load_a_chat("Your lungs begin to burn from lack of oxygen..\n");

/*
set_chance(8);
set_spell_dam(50 + random(30));

set_spell_mess1(
  "\nA cloud of "+HIG+"ACID"+NORM+" is released into the water...\n\n");
set_spell_mess2(
  "\nYou feel the burn of "+HIG+"ACID"+NORM+" as it's released into the water...\n\n");
*/

add_spell("acid",
  "\nYou feel the burn of "+HIG+"ACID"+NORM+" as it's released into the water...\n\n",
  "\nA cloud of "+HIG+"ACID"+NORM+" is released into the water...\n\n",
8,"50-80","other|poison",0);


add_spell("storm",
"#RET#$HK$                                _____\n$N$"+
"$HK$                             __(_    )___\n$N$"+
"$HK$                            (           _)\n$N$"+
"$HK$                           (__           )\n$N$"+
"$HK$                           (__           _)\n$N$"+
"$HK$                             (___________)\n$N$"+
"$HC$                                |  .  . |\n$N$"+
"$HC$                               . .|   |\n$N$"+
"$HC$                               .   .  . .\n$N$"+
"$HC$                               .|  |  .\n$N$"+
"$HC$                               |    .  |\n$N$",
"#MN# unleashes a storm upon #TN#.\n",
30,"60-100","other|water",0);

add_spell("drop",
"$HC$#RET#         ,              ,              ,   \n$N$"+ 
"$HC$         )\\             )\\             )\\ \n$N$"+
"$HC$        /  \\           /  \\           /  \\ \n$N$"+
"$HC$       '   $HW$}$HC$'         '   $HW$}$HC$'         '   $HW$}$HC$'\n$N$"+
"$HC$       ',  ,'         ',  ,'         ',  ,'\n$N$"+
"$HC$         `'             `'             `'\n$N$",
"#MN# hits #TN# with a barrage of $HC$W A T E R$N$.\n",
30,40-60,"other|water",1);

/* replaced with add_money and updated with lvl
gold = clone_object("obj/money");
gold->set_money(3800 + random(1600));
move_object(gold,this_object());
*/
}

monster_died() {
  move_object(clone_object("players/eurale/Keep/QST/amphidragon.c"),
	this_player());
  write_file("/players/eurale/Keep/LOGS/dragons",
  ctime(time())+"     Amphidragon      "+query_attack()->query_real_name()+"\n");
return 0; }
