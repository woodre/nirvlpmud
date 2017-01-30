#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  no_clean = 1;
  set_short("A fountain");
  set_alias("fountain");
  set_long("This finely crafted fountain spurts water from\n"+
           "the mouth of a sculpted fish curled on top of a\n"+
           "wave of water.  The fountains base is slightly\n"+
           "chipped and worn from years of neglect.\n");
}
get() { return 0; } 
