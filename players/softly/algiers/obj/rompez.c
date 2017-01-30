#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg)  {
  if(arg) return;

  set_id("rompezaraguey");
  set_short("Rompezaraguey");
  set_alias("rompez");
  set_long("\A rose toned bottle containing a clear liquid\n\
with tiny flecks in it.  The hand written label\n\
reads 'wash' with this to be cleansed of evil.\n");
  set_weight(1);
  set_value(400);
}

void init()
{
  add_action("wash","wash");
}

wash(str) 
{
  if(str == "liquid" || str == "rompez" || str == "rompezaraguey") 
    {
      this_player()->add_alignment(1500);
      write("\You slowly pour the cool liquid over your hands.\n"+
	    "    Momentarily they appear to glow with a pink color.\n"+
	    "        You feel lighter, as if infused with goodness.\n");
      destruct(this_object());
      this_player()->recalc_carry();
      return 1; 
    }
}

get() { return 1; }
