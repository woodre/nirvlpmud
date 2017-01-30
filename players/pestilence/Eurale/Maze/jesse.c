/*  Jesse James  */
/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */

#include "/players/eurale/defs.h"
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name(YEL+"Jesse James"+NORM);
set_alt_name("jesse");
set_race("human");
set_short(YEL+"Jesse James"+NORM);
set_alias("james");
set_long(
	"  Jesse Woodson James (1847-1882)  Bandit and train robber.  He \n"+
	"was severely wounded in 1865 but survived to terrorize Missouri \n"+
	"for nearly 20 years.  A $10,000 reward, dead or alive, was placed \n"+
	"on his head and he was killed by two members of his own gang. \n");
set_level(24);
set_hp(950);
set_al(0);
set_ac(21);
set_aggressive(1);
set_wc(44);
set_wc_bonus(12);
move_object(clone_object("players/eurale/Maze/OBJ/colt"),TO);
init_command("wield revolver");
add_money(random(3000)+5000);
set_heal(15,3);
set_chat_chance(20);
  load_chat("Jesse whispers:  I don't like strangers, get out! \n");
  load_chat("Jesse moves his hand closer to his pistol. \n");

add_spell("colt",
"#MN# fires his colt into #TN#.\n",
"#MN# fires his colt into #TN#.\n",
30,"20-60",0,3,"gun_attack");

}

gun_attack( object target, object room, int damage ) {
tell_room(environment(),
HIK+"\n           ^\n"+NORM+
HIK+"          | |\n"+NORM+
HIK+"        @#####@\n"+NORM+
HIK+"      (###   ###)-.\n"+NORM+
HIK+"   ."+HIK+" (###     ###) \\\n"+NORM+
YEL+"  / "+HIK+"  (###   ###)  "+NORM+YEL+" )\n"+NORM+
YEL+" (=-"+HIK+"   .@#####@|_"+NORM+YEL+"--\n"+NORM);
tell_room(environment(),
YEL+" /\\   "+HIK+"  \_|l|_/ "+NORM+YEL+"(\\\n"+NORM+
YEL+"(=-\\    "+HIK+"  |l|    \n"+NORM+
YEL+" \\  \\.___"+HIK+" |l|"+NORM+YEL+"___/\n"+NORM+
YEL+" /\\      "+HIK+" |_|"+NORM+YEL+"   /\n"+NORM+
YEL+"(=-\\._________/\\\n"+NORM);
tell_room(environment(),
YEL+" \\             /\n"+NORM+
YEL+"   \\._________/\n"+NORM+
HIK+"      #  ----  #\n"+NORM+
HIK+"      #   __   #\n"+NORM+
HIK+"      \\########/\n"+NORM);
return 1; }
