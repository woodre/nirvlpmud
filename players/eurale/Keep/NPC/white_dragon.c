/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#define TP this_player()
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name(HIW+"White Dragon"+NORM);
set_alias("white dragon");
set_race("dragon");
set_short(HIW+"White Dragon"+NORM);
set_long(
	"The White Dragon is the most evil of all the dragons.  Because\n"+
	"they defied the call of the gods, they were stripped of all\n"+
	"outward signs of intelligence and can therefore neither cast\n"+
	"spells nor speak.  This only served to increase their rage and\n"+
	"savageness when fighting...\n");

set_level(24);
set_hp(1100 + random(250));
set_al(-100);
set_wc(51);
/*
set_wc_bonus(39);
*/
set_ac(25);
set_heal(20,3);
set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The dragon tenses....\n");
  load_chat("You're overcome with an uneasy feeling...\n");
  load_chat("Your heart begins to beat much faster...\n");
set_a_chat_chance(25);
  load_a_chat("\nThe Dragon slashes you with it's claws...\n\n");
  load_a_chat("\nYou feel the tearing of your flesh...\n\n");
  load_a_chat("\nThe mighty beast tramples you with it's feet...\n\n");
  load_a_chat("\nYou see massive amounts of blood on the ground...\n\n");
add_spell("ice",

HIW+"\n                   ()  \n"+
"                   /\\  \n"+
"            ()__   \\/   __()  \n"+
"              \\_\\__/\\__/_/  \n"+
"                \\_/\\/\\_/  \n"+
"               _/_\\/\\/_\\_  \n"+
"              /_/ `\\/` \\_\\  \n"+
"            ()     /\\     ()  \n"+
"                   \\/  \n"+
"                   ()  \n"+NORM,

HIW+"\n"+
"                   /\\  \n"+
"            ()__   \\/   __()  \n"+
"              \\_\\__/\\__/_/  \n"+
"                \\_/\\/\\_/  \n"+
"               _/_\\/\\/_\\_  \n"+
"              /_/ `\\/` \\_\\  \n"+
"            ()     /\\     ()  \n"+
"                   \\/  \n"+
"\n"+NORM,
30,"60-100","other|ice",1);

add_spell("snow",
HIW+"         _\\/ . \\/_  \n"+
"        . _\\/ \\/_ .  \n"+
"       .  ' \\_/ '  .  \n"+
"       ->->->_<-<-<-  \n"+
"       '  ._/ \\_.  '  \n"+
"        . _/\\ /\\_ .  \n"+
"          /\\ ' /\\  \n"+NORM,

HIW+"         _\\/ . \\/_  \n"+
"        . _\\/ \\/_ .  \n"+
"       .  ' \\_/ '  .  \n"+
"       ->->->_<-<-<-  \n"+
"       '  ._/ \\_.  '  \n"+
"        . _/\\ /\\_ .  \n"+
"          /\\ ' /\\  \n"+NORM,
30,"40-60","other|ice",1);
}

monster_died() {
  move_object(clone_object("players/eurale/Keep/OBJ/white_scale.c"),
    environment(this_object()));
  move_object(clone_object("players/eurale/Keep/QST/whitedragon.c"),
		this_player());
  write_file("/players/eurale/Keep/LOGS/dragons",
  ctime(time())+"     Whitedragon      "+query_attack()->query_real_name()+"\n");
return 0; }
