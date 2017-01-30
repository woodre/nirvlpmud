#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "obj/armor";

reset(arg) {
   ::reset(arg);
   
   set_name("Liber Bubonicus");
   set_alias("liber");
   set_short(YEL+"Liber"+MAG+" Bubonicus"+NORM);
   set_long(
"   The Liber Bubonicus.  A Foul magical tome in the lore of the\n"+
"spreading of all things infectious and disease.  Clan Pestilens\n"+
"has whole libraries of these tomes detailing all the many foul\n"+
"contagions they have unleashed upon the world.\n");
   set_ac(2);
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(3);
   set_value(0);
}
