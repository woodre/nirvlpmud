inherit "/players/earwax/housing/land.c";
inherit "players/dragnar/WalkingDead/rooms/WalkingDeadRM";

#include <ansi.h>

reset(arg) {
	
  if(arg) return;
  
  if( !present("girl") )
    move_object(clone_object("/players/dragnar/WalkingDead/mons/lostgirl"), this_object());
  
  short_desc = "King County "+HIG+"Forest"+NORM;
  set_light(1);
  
    items=({
   "ferns","The ferns are a "+GRN+"forest green"+NORM+" and are 10 inches tall",
    "cliff",
"The cliff is not exactly vertical, but it would be almost impossible\n\
to traverse up it safely. Ferns and other ground cover grow on the\n\
rock face wherever they can find a crack, and occasionally small\n\
trees will even take root. A shallow crevice runs up the cliff that\n\
is clear of any ground cover. The cliff runs for 75 feet and a then\n\
disappears at the ridge of the cliff",
   "crevice",
"A fissure that runs from the top of the cliff all the way up to\n\
the clearing here. It is just wide enough for a man to fit in,\n\
and it has lots of rocks jutting out that would make good foot and\n\
hand holds. A brave soul might be able to climb up it",
  "trees","Small saplings grow in the shallow dirt around the crevice",
  "grass","The "+HIG+"grass"+NORM+" grows between the windflowers in the clearing",
  "clearing","A tranquil and peaceful place",
  "rocks","It would be possible to climb up using the rocks",
  "water","The "+HIB+"water"+NORM+" is a beautiful deep shade of blue",
  "stream",
"The stream looks very tranquil and peaceful. The "+HIB+"water"+NORM+" flows\n\
slowly from north to the south and there is a slight bend in\n\
the stream at the bottom of the cliff which makes the stream wider at\n\
this point. "+HIY+"Sunlight"+NORM+" is reflected from the surface of the stream and\n\
dances through the dust in the air. The stream is almost 30 feet\n\
across at this point with a swift current so there is no way to\n\
cross it",
   "wildflowers",
"Almost every color flower is growing in the clearing, from "+HIR+"red"+NORM+" to "+HIM+"purple"+NORM
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/f7","climb",
  });
  long_desc=
"This a small strip of land around 30 feet across that runs between a\n\
cliff to the east and a "+HIB+"stream"+NORM+" on the west. There are "+HIG+"ferns, grass"+NORM+",\n\
and "+HIM+"w"+HIC+"i"+HIR+"l"+HIY+"d "+HIG+"f"+HIM+"l"+HIC+"o"+HIR+"w"+HIY+"e"+HIG+"r"+BLU+"s"+NORM+" growing in the clearing. Everything is quiet and\n\
peaceful here, a perfect spot for a picnic; at least it would have\n\
been before the end of the world.\n";
  
  set_realm_name("Walking Dead");
  set_cost(150000);
  set_lot_size(6);
  setup_land();

}

init() {
	::init();
}