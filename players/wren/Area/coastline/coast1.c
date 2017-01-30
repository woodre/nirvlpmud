/* West Coast, nice view, Beacon Stone here of elven make for ships */

#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif
inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_light(1);
  short_desc = "Western Coast";
  long_desc = 
    "Sea cliffs on the western coast. These massive stone barriers\n"+
    "extend down from the mountain range to the sea. The nearly sheer\n"+
    "surfaces have helped deter invasion for centuries. You stand on\n"+
    "a large stone shelf overlooking the sea. Far below and to the\n"+
    "south the fishing village is visible. Barely visible out over the\n"+
    "sea is another landmass. Nearby an ancient beacon sits occasionally\n"+
    "flaring to brilliance with a heartbeat like pulse. The only way\n"+
    "back from here is the footpath. The view here is breathtaking.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "cliffs","Primordial stone weathered and pounded by daily waves",
	"coast","Western boundry of the mainland of Nirvana",
    "barriers","The narrow approaches have discouraged any western aggressors",
    "range","Chain of mountains stretching north to south ",
	"mountains","The massive piles of stone just navigated by you",
	"shelf","Flat area of stone above the cliffs extending from a mountain",
	"sea","Foam capped breakers are seen below in the rough waters",
	"village","Fishing village battened down to weather the storm",
	"landmass","It must be the continent Hirandea though its hard to see",
    "beacon","Magic is apparent in the large crystal, runes are on the base",
    "footpath","Trail leading back into the foothills from the shelf",
    "runes","Old trade common: 'Given by elves that all ours may find home'",
    "crystal","Pulses brightly with an inner light to guide sailers by the cliffs",
  });

  dest_dir = ({
    "/players/wren/Area/coastline/mountain2","east", 
  }); 
 
  /* Commented out by Sparrow 9/13/06
  set_chance(5);       
  add_msg("A cool invigorating sea mist sprays across the shelf \n");
  add_msg("The beacon crystal pulses brightly \n");
  add_msg("A gull cries out from above and wings toward the village \n");
  add_msg("Waves crash into the cliffs  \n");
  */
  add_listen("main","The crash of waves and gulls can be heard on the shelf");
  add_listen("waves","Soothing regular spash of water on the massive stones");
  add_listen("gulls","The loud sea birds return to feeding following the storm");
  add_smell("main","Crisp sea air  ");
  add_smell("air","The storm has washed away everything but the sea smell ");
  add_touch("crystal","It is slightly warm to the touch when on");
  add_touch("beacon","A strange tingle of magic runs through your fingers");
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("Nothing of portable interest is found in the area \n");
  say (this_player()->query_name() +" searches the area. \n");
  return 1;
}
