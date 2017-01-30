inherit "/obj/monster";
#include <ansi.h>
reset(arg) {
object gold;
if(arg) return ;  ::reset(arg);

set_name("hound");
set_short(RED+"A Heart Hound"+NORM);
set_alias("hound");

set_long("Larger than a wolf, as well as smarter, this creature's name is \n"+
"under debate. Some say that it name comes from how it hunts, by hearing \n"+
"the sound of your heart beating, others say it is how they make the kill, \n"+
"by going for the heart, rather than the throat, if there is more than one, \n"+
"they will often fight over the heart, and they have big enough teeth to get \n"+
"the job done. It's fur is tan colored, and is short with a long mouth.\n");

set_level(9);
set_wc(13);
set_ac(7);
set_hp(135);
set_dead_ob(this_object());
}
monster_died() {
   object hide;
   hide = clone_object("/players/data/OUTERB/ITEMS/hide.c");
   move_object(hide,environment());
   return 1; 
}


