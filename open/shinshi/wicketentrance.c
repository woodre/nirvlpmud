inherit"/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);

if(arg)return;
  set_light(1);
  short_desc = "A Television Set";
  long_desc = 
  "A small screen television set, with small parts inside of it that glow\n"+
  "a knob seems to radiate a wierd energy. Several stations flash before the\n"+
  "screen showing a glimpse of places that can be traveled to in the fanasty\n"+
  "lands.\n";

  items=
  ({
  	"tv",
  	"Turn the knob",
   });
   
   dest_dir =
   ({
           "/room/south/sforst18.c",     "out",
   });
}
   
init(){
	::init();
	
	add_action("turn", "turn");
}

turn(str){
	if(!str)
	{
		write("What would you like to turn?\n");
		return 1;
	}
	
	if(str != "knob to channel 5")
	{
		write("You can only 'turn' the 'knob to channel 5'.\n");
		return 1;
	}
	
	if(str == "knob to channel 5")
	{
		write("You turn the knob and are sucked into channel 5!\n");
		this_player()->move_player("into channel 5#players/wicket/tv/looney/rooms/tinyentrance");
		return 1;
	}
	return 1;
}