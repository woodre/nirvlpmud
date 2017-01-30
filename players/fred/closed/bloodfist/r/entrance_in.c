inherit "room/room";
#include "/players/fred/closed/bloodfist/defs.h"
int doors;

reset(arg){
	if(arg) return;

  doors = 1; /* open */
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "doors",
      "The giant wooden doors of the encampment are at least a foot thick\n"+
      "and about fifteen feet high.  Each door is mounted to the outer\n"+
      "wall of the encampment with gigantic metal bolts.  They look as\n"+
      "though they each weigh a ton",
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "walls",
      "The stone walls of the encampment extend from here to the east and\n"+
      "west.  They climb at least fifteen feet into the air, protecting\n"+
      "the encampment from whatever lurks in the desert",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked, and broken.  A thin layer of sand\n"+
      "covers it which is constantly being blown around",
    "sand",
      "The ground is caked with a layer of dry sand",
    "mountains",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
    "ravine",
      "The ravine to the south winds through the dark mountains towards\n"+
      "the desert.  Either side of the ravine are dangerously steep,\n"+
      "preventing anyone from deviating from the path",
  });

  dest_dir=({
    DIR + "r/courtyard.c",        "north",
    /* DIR + "r/entrance_out.c",     "south", */
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  int i;
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
     write("It is dark.\n");
     return;
  }
  if(doors)
    long_desc =
"  You stand inside the entrance of the Bloodfist encampment.  To the\n"+
"south two gigantic wooden doors attach to the great wall surrounding\n"+
"the encampment.  The doors are open and lead south into a winding dark\n"+
"ravine.  There are many torches mounted on the walls around the doors.\n"+
"The courtyard of the Bloodfist lies to the north.  The dark sky above\n"+
"is a torrent of blowing sand.  The ground below is dead and lifeless,\n"+
"covered with a fine layer of sand.  Off in the distance to the north,\n"+
"large towering mountains can be seen beyond the encampment.\n"+
"    There are two obvious exits: north and south\n";
  else
    long_desc = 
"  You stand inside the entrance of the Bloodfist encampment.  To the\n"+
"south two gigantic wooden doors attach to the great wall surrounding\n"+
"the encampment.  The doors are closed, preventing travel to the south\n"+
"into the ravine.  There are many torches mounted on the walls around\n"+
"the doors.  The courtyard of the Bloodfist lies to the north.  The dark\n"+
"sky above is a torrent of blowing sand.  The ground below is dead and\n"+
"lifeless, covered with a fine layer of sand.  Off in the distance to the\n"+
"north, large towering mountains can be seen beyond the encampment.\n"+
"    There are two obvious exits: north and south\n";
  if(!str)
    write(long_desc);
  if(!items)
	  return;
  i = 0;
  while(i < sizeof(items))
  {
	  if(items[i] == str)
    {
	    write(items[i+1] + ".\n");
	    return;
    }
	i += 2;
  }
}

void init(){
  ::init();
  add_action("open",      "open");
  add_action("close",     "close");
  add_action("south_dir", "south");
}

int query_doors(){ return doors; }

status south_dir()
{
  if(!doors)
    return (notify_fail("The doors are closed.\n"), 0);
  this_player()->move_player("south#"+DIR+"r/entrance_out.c");
  return 1;
}

status open(string str)
{
  if(str != "doors") return 0;
  if(doors)
    return (notify_fail("The doors of the encampment are already open.\n"),0);
  write("With a great effort you open the doors of the encampment.\n");
  say("With a great effort "+this_player()->query_name()+
    " opens the doors of the encampment.\n");
  doors = 1;
  return 1;
}

status close(string str)
{
  if(str != "doors") return 0;
  if(!doors)
    return (notify_fail("The doors of the encampment are "+
    "already closed.\n"),0);
  return (notify_fail("The doors are jammed open from the sand.\n"),0);
  write("With a great effort you close the doors of the encampment.\n");
  say("With a great effort "+this_player()->query_name()+
    " closes the doors of the encampment.\n");
  doors = 0;
  return 1;
}
