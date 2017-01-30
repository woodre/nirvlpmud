#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("test");
  set_alias("pregnancy test");
  set_short("Pregnancy Test");
set_long(

	"A simple little pregnancy test.  Perform the test and within moments\n" +
	"you will know if you are pregnant or not.  If the test turns " + HIM + "pink" + OFF + ", \n" +
	"then congratulations are in order!  If it turns " + HIC + "blue" +  OFF +", its time\n" +
	"to try again.\n");

  set_value(1);
  set_weight(1);
}

init() {
  add_action("cmd_test","perform");
}

cmd_test(str)
{
	if(id(str))
  	{
		if (this_player()->query_pregnancy() == 0)
	  	{
		  say(HIC + this_player()->query_name() + " is not pregnant.\n" + OFF);
		  write (HIC + "You are not pregnant.\n" + OFF);
		  destruct(this_object());
		  return 1;
	  	}
		else if (this_player()->query_pregnancy() != 0)
	  	{
		  say(HIM + "Congratulations!  " + this_player()->query_name() + " is pregnant!\n" + OFF);
		  write (HIM + "Congratulations!  You are pregnant!\n" + OFF);
		  destruct(this_object());
		  return 1;
	  	}

  		notify_fail("What are you trying to do?\n");
  		return 0;
	}
}