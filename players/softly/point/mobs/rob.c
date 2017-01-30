#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
move_object(clone_object("/players/softly/point/obj/silver"),this_object()); 
   set_name("rob");
   set_alt_name("young man");   
   set_alias("man");
   set_long(
"Rob is a young man who looks old beyond his years.\n\
His shorts and plaid shirt are very worn.  He clutches\n\
something tightly to him as he hurries along.\n");
   set_short("A young man");
   set_race("human");
   set_level(13);
   set_wc(10);
   set_ac(17);
   set_hp(195);
   set_al(-200);
   set_aggressive(0);

}
