/* Pass through the mountains*/
#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_light(1);
  short_desc = "A mountain pass";
  long_desc = 
"The road turns steeply downhill and twists down around the  \n\
massive stone walls deeper into the mountains. The walls rise\n\
sharply and shearly up providing no good ambush points. Helping\n\
to explain why this continues to be the safest way through the \n\
mountains. The clouds grow more ominous overhead. It seems that\n\
it might be a bad idea to be at the bottom of a gully in case \n\
of flashflooding.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "road","The road is now simply a path worn down from heavy travel and weather",
	"walls","Smooth stone walls formed of ancient stone pushing upward toward the heavens",
    "stone","Ancient granite with small spots of quartz visible periodically",
	"mountains","Only the slopes of the mountain on either side of you can be vaguely seen",
	"clouds","Storm clouds unleash there power on the higher slopes. Down here you get mostly the rain",
	"gully","To the side of the path a grove has been worn and carries much of the water away"
  });

  dest_dir = ({
    "/players/wren/Area/coastline/path","east",
    "/players/wren/Area/coastline/mountain","west", 
  }); 
 
  /* Commented out by Sparrow 9/14/2006
  set_chance(5);       
  add_msg("Thunder rumbles high above\n");
  add_msg("Lightning flashes throwing the area into high contrast \n");
  add_msg("Pebbles dislodged by thunder clatter down a ravine \n");
  add_msg("Trickles of rainwater run down the steep walls \n");
  add_msg("Puddles slosh as you stomp through them\n");
  */
  add_listen("main","Thunder rumbles the higher slopes and water is everywhere ");
  add_listen("water","Your feet spash as you move through the rivelets ");
  add_listen("thunder","The rumbling above draws your attention to possible rockslides");
  add_smell("main","The air is clear with a hint of ozone ");
  add_smell("ozone","Sharp tang from a recent lightning flash ");
  add_touch("stone","Smooth and cold to the touch");
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("Nothing interesting is found or should be sought in this downpour. \n");
  say(this_player()->query_name() +" searches the area. \n");
  return 1;
}
