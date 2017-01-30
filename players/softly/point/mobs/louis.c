#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
move_object(clone_object("/players/softly/point/obj/fittings"),this_object()); 
   set_name("louis");
   set_alt_name("young man");   
   set_alias("man");
   set_long(
"Louis is a handsome young man with a slight grin\n\
who must live nearby.  He wears only shorts and a\n\
t-shirt and is barefooted as he rushes past.\n");
   set_short("A young man");
   set_race("human");
   set_level(13);
   set_wc(10);
   set_ac(17);
   set_hp(200);
   set_al(-200);
   set_aggressive(0);
   add_money(20+random(180));

}
