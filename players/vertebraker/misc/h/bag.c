inherit "/obj/clean";

#include "/players/vertebraker/define.h"

inherit CONTAINER;

reset(x) {
   if(x) return;
   set_no_clean(1);
   set_name("saddle bag");
   set_short("A saddle bag");
   set_long(
      "A big, loose saddle bag that hung from the saddle of the\n"+
      "horse it used to be on.  It looks like it could carry a\n"+
      "great deal.\n");
   set_weight(1);
   max_weight = 60;
}

id(str) { return str == "bag" || str == name; }

query_save_flag() { return 1; }

short()
{
   if(USER && USER->id("horse")) return 0;
   else return short_desc;
}
