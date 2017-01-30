/*  Updated 10/18/01 to conform to /doc/build/RULES/monster.guide  */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#define tp this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Astral Dragon"+NORM);
set_alias("astral dragon");
set_race("dragon");
set_short(HIY+"Astral Dragon"+NORM);
set_long(
	"This Astral Dragon is yellow in color due to it's scales.  It\n"+
	"stands about 50 feet tall with human hands and long, slim fingers.\n"+
	"It has huge black eyes and it's scales are covered with fine\n"+
	"blonde fur.  The dragon is enveloped in a permanent aura of\n"+
	"golden light.\n");

set_level(24);
set_hp(1100 + random(250));
set_al(100);
set_wc(51);
/*
set_wc_bonus(39);
*/
set_ac(25);
set_heal(20,3);
  set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The dragon stoops down to look closer at you...\n");
  load_chat("You begin to sweat...\n");
  load_chat("THUMP, THUMP... the dragon moves closer..\n");
set_a_chat_chance(15);
  load_a_chat("\nThe dragon KICKS viciously at you...\n");
  load_a_chat("\nThe dragon's huge teeth just miss snatching you...\n");
  load_a_chat("\nThe dragon jumps over you and attacks from behind..\n");

/*
set_chance(10);
set_spell_dam(80);

set_spell_mess1(
  "\n\nThe dragon casts a "+HIY+"S*U*N*B*A*L*L"+NORM+" at it's target.\n\n");
set_spell_mess2(
  "\n\nThe dragon casts a "+HIY+"S*U*N*B*A*L*L\n\n"+
  "                             *\n"+
  "                             *\n"+
  "                          *  *  *\n"+
  "                           * * *\n"+
  "                            *** \n"+
  "                        ************ \n"+
  "                            *** \n"+
  "                           * * * \n"+
  "                          *  *  * \n"+
  "                             * \n"+
  "                             * \n\n"+
  NORM+"                 and SCORCHES your exposed flesh....\n\n");
*/
add_spell("sunball",
  "\n\nThe dragon casts a "+HIY+"S*U*N*B*A*L*L\n\n"+
  "                             *\n"+
  "                             *\n"+
  "                          *  *  *\n"+
  "                           * * *\n"+
  "                            *** \n"+
  "                        ************ \n"+
  "                            *** \n"+
  "                           * * * \n"+
  "                          *  *  * \n"+
  "                             * \n"+
  "                             * \n\n"+
  NORM+"                 and SCORCHES your exposed flesh....\n\n",
  "\n\nThe dragon casts a "+HIY+"S*U*N*B*A*L*L"+NORM+" at it's target.\n\n",
8,"50-80","other|light",0);


add_spell("star",
HIY+"\n         /\\                  /\\ \n"+NORM+
HIY+"      __/  \\__            __/  \\__ \n"+NORM+
HIY+"     `.      .'          `.      .' \n"+NORM+
HIY+"       x    x              x    x \n"+NORM+
HIY+"      /__(\\__\\            /__(\\__\\ \n"+NORM,

HIY+"\n         /\\                  /\\ \n"+NORM+
HIY+"      __/  \\__            __/  \\__ \n"+NORM+
HIY+"     `.      .'          `.      .' \n"+NORM+
HIY+"       x    x              x    x \n"+NORM+
HIY+"      /__(\\__\\            /__(\\__\\ \n"+NORM,
30,"40-60","other|light",0);
add_spell("lightning",
HIY+"\n                                    ,/\n"+NORM+
HIY+"                                  ,'/\n"+NORM+
HIY+"                                ,' /\n"+NORM+
HIY+"                              ,'  /_____,\n"+NORM+
HIY+"                            .'____    ,'\n"+NORM+   
HIY+"                                 /  ,'\n"+NORM+
HIY+"                                / ,'\n"+NORM+
HIY+"                               /,'\n"+NORM+
HIY+"                              /'\n"+NORM,
"#MN# strikes #TN# with a bolt of $HY$lightning$N$\n",
30,"60-100","other|electric",1);

}

monster_died() {
tell_object(this_player(),
  "As the big, beautiful dragon hits the floor, you hear a slight\n"+
  "slight snap as one of its wings buckle under and breaks...\n\n");
  move_object(clone_object("players/eurale/Keep/OBJ/bone"),
    environment(this_object()));
  move_object(clone_object("players/eurale/Keep/QST/astraldragon.c"),
		this_player());
  write_file("/players/eurale/Keep/LOGS/dragons",
  ctime(time())+"     Astraldragon     "+query_attack()->query_real_name()+"\n");
}
