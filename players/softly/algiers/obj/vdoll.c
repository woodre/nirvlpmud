#include "/players/softly/closed/define.h"
inherit "obj/treasure";

string who, longd;

reset(arg)
{
  if (arg) return;

  switch(random(6)) 
    { 
    case 0: 
      longd = "The small brown cloth figure with a hand\n"+
	"painted clay face hangs on a black string.\n"+
	"Orange feathers seem to erupt from it's head.\n"; 
      break; 

    case 1: 
      longd = "The small tubular black cloth figure has black\n"+
	"features painted on a white face and hands.\n"+
	"Two black feathers are attached to the sides.\n"; 
      break; 
      
    case 2: 
      longd = "The small brown rope doll with beaded eyes and\n"+
	"mouth.  It wears a black vest with golden\n"+
	"braid and several blue and orange feathers.\n"; 
      break; 

    case 3: 
      longd = "The small white straw doll with a painted face\n"+
	"wears a red pouch.  Its hand sewn face is topped\n"+
	"with a blue feather and its arms stretch skyward.\n"; 
      break; 

    case 4: 
      longd = "The small doll of yellow broom straws wears a\n"+
	"silver mask topped with a long black feather.\n"+
	"Its torso is wrapped tightly with blue yarn.\n"; 
      break; 

    case 5: 
      longd = "The small doll has a body of bone and a red\n"+
	"yarn head and hands.  A tall feather rises\n"+
	"from the top of the white hand-painted face.\n"; 
      break; 
    } 

  set_id("voodoo doll");
  set_alias("doll");

  set_weight(1);
  set_value(150);
  set_light(0);
}

set_who(str) { who = str; }
short() { return "A voodoo doll of " + who; }
long() { write("A voodoo doll of " + who + " with a black pin attached.\n" + longd+
"You should be able to stick the doll with the pin.\n"); }

void
init()
{
  ::init();
  add_action("cmd_stick", "stick");
}

cmd_stick (str)
{
  if (!str) return 0;
  if(!id(str))
    {
      notify_fail("\
What did you want to stick?\n");
      return 0;
    }
  write("\n"+who+" squirms and cries out as you stick the doll.\n");
  say(this_player()->query_name() + " sticks a pin into the doll.\n");
  return 1;   
}
