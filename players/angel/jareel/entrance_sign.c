#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short("A wooden sign");
  set_alias("sign");
  set_long("The sign is made of a gnarled wood that's driveninto the ground.\n");
  set_read("\n"+BOLD+
           "     .---------------------------.\n"+
           "     |__                       __|\n"+
           "        |   "+GRN+"Chaos Wood"+NORM+"    (N) |\n"+
           "        |                     |\n"+
           "        |   Temple of the (E) |\n"+
           "        |          "+BOLD+YEL+"SUN"+NORM+"        |\n"+
           "        |                     |\n"+
           "        |   "+BOLD+GRN+"Hendrickville"+NORM+" (E) |\n"+
           "        |                     |\n"+
           "        ````| |`````````| |````\n"+
           "            | |         | |\n"+
           "\n\n"+NORM);
}
get() { return 0; }
