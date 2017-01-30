#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg)  {
  if(arg) return;

  set_id("powder");
  set_short("Bat's Blood Powder");
  set_alias("powder");
  set_long("\A small paper fashioned in a complex fold\n\
containing a dark ash colored powder\n\
that can be sniffed it.\n");
  set_weight(1);
  set_value(400);
}

void init()
{
  add_action("sniff","sniff");
}

sniff(str) 
{
  if(str == "powder" || str == "blood" || str == "bat's blood" || str == "bat's blood powder" || str == "bats blood powder") 
    {
      this_player()->add_alignment(-1500);
      write("\As you sniff the fine powder you suddenly disoriented....\n"+
	    "    Darkness momentarily surrounds you.... \n"+
	    "        You are at one with evil.\n");
      destruct(this_object());
      this_player()->recalc_carry();      
      return 1; 
    }
}

get() { return 1; }
