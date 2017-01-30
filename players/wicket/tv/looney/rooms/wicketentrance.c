inherit"/room/room";
#include <ansi.h>

reset(arg)
{
::reset(arg);
if(!present("dexter", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/dexter.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A TV Set";
  long_desc = 
  "A small screen television set, with small parts inside of it that glow.\n"+
  "A knob seems to radiate a wierd energy. Several stations flash before the\n"+
  "screen showing a glimpse of places that can be traveled to in the fanasty\n"+
  "lands.\n";

  items=
  ({
  	"tv",
  	"Turn the knob",
  	"knob",
  	"Turn the knob",
  	"parts",
  	"The parts inside of the tv that radiate electricity",
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