/* a generic monster set-up */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name(HIR+"El Diablo"+NORM);
set_alt_name("diablo");
set_race("devil");
set_short(HIR+"El Diablo"+NORM);
set_alias("el diablo");
set_long(
	"  As you gaze into the face of this bandito, he is like no other \n"+
	"person or thing you have ever seen before.  His crimson skin and \n"+
	"ebony eyes give him a sinister look.  He is well muscled and \n"+
	"looks to be about 7 feet tall..... a formidable foe. \n");
set_level(26);
set_hp(1650);
set_al(-1000);
set_ac(23);
set_aggressive(1);
set_dead_ob(this_object());

move_object(clone_object("players/eurale/Maze/OBJ/hawk50"),TO);
init_command("wield rifle");
set_wc(52);
set_wc_bonus(28);
set_heal(5,2);
add_money(random(3000)+6000);


set_chat_chance(5);
  load_chat("Diablo whispers: It's a nice day to die.... \n");
  load_chat("Diablo growls...... \n");


add_spell("flames",
"\nDiablo raises his hand.... \n\n"+
RED+ "  F L A M E S "+NORM+" fly from his fingertips to your chest...\n\n"+
"     You feel intense pain and smell burning flesh.. \n\n",
"\n\nDiablo's eyes glow bright red as he glares at you...\n\n",
16,100,"other|fire",0);

add_spell("fire",
"#RET#$HR$               (  .      )$N$\n"+
"$HR$           )           (              )$N$\n"+
"$HR$                 .  '   .   '  .  '  .$N$\n"+
"$HR$        (    , )       (.   )  (   ',    )$N$\n"+
"$HR$         .' ) ( . )    ,  ( ,     )   ( .$N$\n"+
"$HR$      ). , ( .   (  ) ( , ')  .' (  ,    )$N$\n"+
"$HR$     (_,) . ), ) _) _,')  (, ) '. )  ,. (' )$N$\n"+
"$HR$ jgs^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$N$\n",
"$HR$Flames$N$ lash out at #TN#, scorching $TN$'s flesh.\n",
25,"40-60","other|fire",3);

/*
set_chance(16);
set_spell_dam(100);
  set_spell_mess1("\n\nDiablo's eyes glow bright red as he glares at you...\n\n");
  set_spell_mess2("\nDiablo raises his hand.... \n\n"+
   RED+ "  F L A M E S "+NORM+" fly from his fingertips to your chest...\n\n"+
	"     You feel intense pain and smell burning flesh.. \n\n");
*/

/* updated to add_money and to new lvl
gold = clone_object("obj/money");
gold->set_money(random(200)+4000);
move_object(gold,this_object());
*/
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\n"+
  "As his 'body' hits the ground, Diablo gurgles...\n\n"+
  "We will meet again in "+BOLD+"HELL,"+NORM+" my friend!\n\n");
return 0;
}
