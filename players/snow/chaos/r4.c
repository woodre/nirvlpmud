/* Gas room */

inherit "players/snow/chaos/arch.c";
#include "/players/snow/chaos/defs.h"
#include "/players/snow/closed/cyber/color.h"

reset(arg) {
  ::reset();

  if(!PRE("gasobj")) MO("/players/snow/chaos/objects/gas.c",TO);

  if(!arg) {
  short_desc=YELLOW+"C"+OFF+
             MAGENTA+"h"+OFF+
             GREEN+"A"+OFF+
             CYAN+"o"+OFF+
             BLUE+"S"+OFF;
  long_desc=
"  A horrible-smelling gas whirls through this area. Your\n\
vision is blurred and you realize you have to get out of\n\
this horrible place!\n";
  items=({
      });
  }
}
