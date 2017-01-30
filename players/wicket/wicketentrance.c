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
/* Added a period to above sentence -- Rumplemintz */
  "A knob seems to radiate a wierd energy. Several stations flash before the\n"+
/* Changed the 'a' to capitalized 'A' in above sentence -- Rumplemintz */
  "screen showing a glimpse of places that can be traveled to in the fanasty\n"+
  "lands.\n";

  items=
  ({
  	"tv",
  	"Turn the knob",
  	"knob",
  	"Turn the knob",
/* Added below items, as you could not look at any of them -- Rumplemintz */
    "stations", "They flash before the screen",
    "screen", "It shows random flashes of places in the fantasy lands",
    "places", "Random images of the fantasy lands",
    "set", "It is a small screen television set",
    "television", "It is a small screen television set",
    "parts", "Various parts glow inside of the television set",
/* End Rumplemitnz addition */
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
