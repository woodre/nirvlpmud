inherit "room/room";
#include "/players/fred/closed/bloodfist/defs.h"
#define INSIDE "/players/fred/closed/bloodfist/r/entrance_in.c"
int a;

reset(arg){
	if(arg) return;

  for(a = 0; a < 2; a++)
    move_object(clone_object(DIR+"NPC/guard.c"), this_object());

  set_light(0);
  set_no_clean(1);

  items =({
    "doors",
      "The giant wooden doors of the encampment are at least a foot thick\n"+
      "and about fifteen feet high.  Each door is mounted to the outer\n"+
      "wall of the encampment with gigantic metal bolts.  They look as\n"+
      "though they each weigh a ton",
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
      "The walls of the ravine extend up towards the dark sky to both the\n"+
      "east and west.  The ravine continues to the southeast.  To the\n"+
      "north it ends at the doors of the Bloodfist encampment.  There is\n"+
      "no way to deviate from the established path of the ravine",
  });

  dest_dir=({
    /* DIR + "r/entrance_in.c",      "north", */
    DIR + "r/ravine1.c",          "southeast",
  });
}

short(){ return "inculta creperum"; }

long(str){
  int i;
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
     write("It is dark.\n");
     return;
  }
  if(INSIDE->query_doors())
    long_desc =
"  You stand in a deep, dark ravine outside the entrance of the Bloodfist\n"+
"encampment.  The ravine ends at a pair of gigantic wooden doors which\n"+
"are attached to the outer walls of the encampment.  The doors are open.\n"+
"The walls have been built up against the mountainous rock that makes up\n"+
"the ravine.  The ground here is desolate and cracked, covered by a layer\n"+
"of sand.  Winds whip down through the ravine and whistle overhead.  The\n"+
"warmth of the desert presses down on you like a thick blanket.\n"+
"    There are two obvious exits: north and southeast\n";
  else
    long_desc = 
"  You stand in a deep, dark ravine outside the entrance of the Bloodfist\n"+
"encampment.  The ravine ends at a pair of gigantic wooden doors which\n"+
"are attached to the outer walls of the encampment.  The doors are closed.\n"+
"The walls have been built up against the mountainous rock that makes up\n"+
"the ravine.  The ground here is desolate and cracked, covered by a layer\n"+
"of sand.  Winds whip down through the ravine and whistle overhead.  The\n"+
"warmth of the desert presses down on you like a thick blanket.\n"+
"    There are two obvious exits: north and southeast\n";
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
  add_action("open", "open");
  add_action("close", "close");
  add_action("north_dir", "north");
}

status north_dir()
{
  if(!INSIDE->query_doors())
    return (notify_fail("The doors are closed.\n"), 0);
  if(present("bloodfist guard")
    && (string)this_player()->query_guild_name() != "bloodfist")
    return (notify_fail("The guard prevents you from going north.\n"), 0);
  this_player()->move_player("north#"+INSIDE);
  return 1;
}

status open(string str)
{
  if(str != "doors") return 0;
  return (notify_fail("The doors can not be opened from here.\n"),0);
}

status close(string str)
{
  if(str != "doors") return 0;
  return (notify_fail("The doors can not be closed from here.\n"),0);
}
