inherit "room/room";
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
string *prs, *pns;
object gem_seller;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  if(!present("old man"))
  {
    gem_seller = clone_object(DIR+"NPC/gem_seller.c");
    move_object(gem_seller, this_object());
  }

  prs = ({ }); /* private room paths */
  pns = ({ }); /* private names */
  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "torches",
      "The torches are mounted on the stone walls of the arena",
    "walls",
      "The stone walls of the encampment are visible in all directions\n"+
      "from the courtyward.  The walls of the arena are also visible\n"+
      "through the sandy wind to the north",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken",
    "sand",
      "The ground is caked with a layer of dry sand",
    "mountains",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "well",
      "A well is visible to the west",
    "tables",
      "A few wood tables are here in the sand.  Each one is a wood board\n"+
      "fastened to stone blocks and all of them are in bad shape thanks\n"+
      "to the harsh desert winds",
    "chairs",
      "The wooden chairs don't look comfortable, but they're better than\n"+
      "sitting on the dirt.  Half of them are fallen over and covered in\n"+
      "a layer of sand",
    "horizon",
      "The mountains make up the horizon, which is constantly shrouded\n"+
      "by the sands whipping through the air",
    "doorways",
      "There are a multitude of small doorways to the east which lead into\n"+
      "private rooms",
    "rooms",
      "There are a multitude of small doorways to the east which lead into\n"+
      "private rooms.  They all look relatively small",

  });

  dest_dir=({
    DIR + "r/open.c",          "north",
    /* DIR + "r/private.c",       "east", */
    DIR + "r/courtyard.c",     "west",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  int i;
  if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())) {
     write("It is dark.\n");
     return;
  }
  if(torch)
    long_desc =
"  This is the eastern part of the encampment.  There are some chairs and\n"+
"tables set up here for people to rest at.  To the east there are many\n"+
"small doorways which lead into the private rooms of the encampment.  To\n"+
"the north and west, the area is generally open.  To the south and above\n"+
"the rooms to the east the walls of the encampment are visible, and beyond\n"+
"them the mountains.  The dark sky above swirls in the sandy wind.  The\n"+
"area is lit by a multitude of torches.  The warmth is constant here.\n"+
"    There are three obvious exits: north, east and west\n";
  else
    long_desc = 
"  This is the eastern part of the encampment.  There are some chairs and\n"+
"tables set up here for people to rest at.  To the east there are many\n"+
"small doorways which lead into the private rooms of the encampment.  To\n"+
"the north and west, the area is generally open.  To the south and above\n"+
"the rooms to the east the walls of the encampment are visible, and beyond\n"+
"them the mountains.  The dark sky above swirls in the sandy wind.  There\n"+
"are many unlit torches here.  The warmth is constant here.\n"+
"    There are three obvious exits: north, east and west\n";
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
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("east", "east");
  add_action("rooms", "rooms");
}

status rooms(){
  int a;
  if(this_player()->query_level() < 100) return 0;
  write("These players currently have rooms:\n");
  for(a = 0; a < sizeof(pns); a++)
  {
    if(pns[a])
      write(" "+(a + 1)+". "+capitalize(pns[a])+"\n");
  }
  return 1;
}

status east(){
  object new_room, gob;
  int a;
  if((string)this_player()->query_guild_name() != "bloodfist")
    return (notify_fail("A guard blocks you from entering the rooms.\n"), 0);
             /* true if they already have a room this boot */
  if(!(gob = present("bloodfist_gob", this_player())))
    return (notify_fail("A guard blocks you from entering the rooms.\n"), 0);
  if(gob->query_glevel() < 1)
    return (notify_fail("A guard says, \"You must be at least "+
      "guild level 1 to enter.\"\n"), 0);
  if((a = index(pns, this_player()->query_real_name())) > -1
    && find_object(prs[a]))
  {
    write("You enter your private room...");
    if(gob->is_testchar())
      write(" room "+a+".\n\n");
    else
      write("\n\n");
    this_player()->move_player("east#"+prs[a]);
    return 1;
  }
  else { /* first time entering- add glvl check before here */
    if((a = index(pns, this_player()->query_real_name())) > -1
      && !find_object(prs[a])) /* if it is not in memory for some reason */
    {
      pns -= ({ this_player()->query_real_name() });
      prs -= ({ prs[a] });
    }
    new_room = clone_object(DIR+"r/private.c");
    if((int)this_player()->query_level() < 20)
    {
      pns += ({ this_player()->query_real_name() });
      prs += ({ file_name(new_room) });
    }
    write("You enter your private room...\n\n");
    this_player()->move_player("east#"+file_name(new_room));
    return 1;
  }
  return 1;
}


