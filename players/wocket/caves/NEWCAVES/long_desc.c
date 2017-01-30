#include "/players/wocket/closed/ansi.h"

int roomcount;

string get_long_desc(){
    string long_desc;
    switch(random(7)){
    case 0:  long_desc = ""+
	MAG+"   The walls are covered with a slimy mucus giving off a soft\n"+
	"violet glow, creating shadows which flicker in every direction.\n"+
	"The ruff walls are made of dirt and stone and the ground is\n"+
	"covered in lose rocks.  Small strange white plants feed off\n"+
	"the darkness.\n"+NORM;    
	break;
    case 1:  long_desc = ""+
	MAG+"   A soft glow emminates from the mucus which textures the already\n"+
	"ruff dirt walls.  A small amount of violet light casts shadows\n"+
	"making everything seem alive.  White plants grow in abundance in\n"+
	"the intense darkness.\n"+NORM;
	break;
    case 2:  long_desc = ""+
	MAG+"   Violet light from a strange mucus, casts shadows against the rocky\n"+
	"walls.  The ground is littered in loose rocks and white plants that\n"+
	"seem to be at home in this cold, dark place.  The mucus covers everything\n"+
	"making an explorers walk a slippery one.\n"+NORM;
	break; 
    case 3:  long_desc = ""+
	MAG+"   The walls are covered in small plantlife.  The plants are a dull\n"+
	"white and seem very fragile.  They shrink back from the light of the\n"+
	"violet mucus which seems to cover everything.  Small rocks litter\n"+
        "the ground adding more to the danger of tripping.\n"+NORM; 
	break;
    case 4:  long_desc = ""+
	MAG+"   White plants grow in abundance down here.  Some can be found in every\n"+
	"little crack or hole in the walls.  They seem to feed off the darkness\n"+
	"itself.  A mucus covers the majority of things, giving off a soft violet\n"+
	"glow, which the plants hide from.  The walls are sharp with jagged rocks,\n"+
	"though many have come loose and now lay upon the ground.\n"+NORM;
	break;
    case 5:  long_desc = ""+
	MAG+"   The walls are covered in a slimy mucus which gives off a soft \n"+
	"violet glow.  The light casts shadows against the rocky surface\n"+
	"giving refuge for the dark loving plants who grow in abundance here.\n"+
	"Loose rocks acumulate in the corners of the cavern, knocked off from\n"+
	"the walls.\n"+NORM;
	break;
    case 6:  long_desc = ""+
	MAG+"   The soft violet glows from the mucus spread around the room, casting\n"+
	"shadows against the rocky walls.  White plants shrink back and hide in\n"+
	"thier life giving darkness.  Fallen rocks from the walls loosely scatter\n"+
	"around on the ground as everything grows slimy.\n"+NORM;
	break;
    }
    return long_desc;
}

int query_roomcount(){ return roomcount; }

status add_roomcount(int i){ roomcount += i; return 1; }
status remove_roomcount(int i){ roomcount -= i; return 1; }
