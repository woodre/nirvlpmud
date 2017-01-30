#include "/players/fakir/color.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
set_id("Wyrmscar");
set_alias("scar");
set_short(BOLD+"Jagged Scar of Icingdeath"+OFF);
set_long(
  "  An ice white scar beginning at the temple and jaggedly crossing\n"+ 
"the right cheek, ending at the corner of the upper lip.  The flesh\n"+
"near the scar shimmers with an unnatural ice-like appearance.  Only\n"+
"those who defeat the mighty Wyrm Icingdeath and complete the task\n"+
"given by the archwizard Glarvinthal receive such a scar.  Greatly\n"+
"fear those who bear it.\n");

set_weight(0);
set_value(0);
set_no_clean(1);
}

drop() { return 1; }

query_auto_load() { return "players/fakir/closed/scar.c:"; }
