inherit "room/room";
#include "/players/zeus/closed/ansi.h"
#include "/players/fred/closed/bloodfist/defs.h"
int torch;
#include "/players/fred/closed/bloodfist/r/torches.h"

reset(arg){
	if(arg) return;

  torch = 1;
  set_light(1);
  set_no_clean(1);

  add_property("no_teleport");

  items =({
    "torches",
      "There are a couple torches mounted on the rock sides of the\n"+
      "graveyard and the southern wall of the encampment",
    "tombstones",
      "Each of the tombstones extends about two feet from the ground and\n"+
      "has a small inscription on it",
    "tombstone",
      "Each of the tombstones extends about two feet from the ground and\n"+
      "has a small inscription on it",
    "inscription",
      "Many of the inscriptions are difficult to read, because the "+
      "constantly\nblowing sand has begun to smooth them out",
    "wall",
      "The stone walls of the encampment are visible to the south from\n"+
      "here.  It connects with the rock to the west that climbs equally\n"+
      "high into the sky",
    "sky",
      "The sky is a shroud of darkness and swirling sand",
    "ground",
      "The ground is destolate, cracked and broken.  In numerous places it\n"+
      "has clearly been disturbed by the digging of a tomb",
    "sand",
      "The ground is caked with a layer of dry sand",
    "mountains",
      "The encampment is built around some mountains of rock that jut\n"+
      "out of the earth at almost as sharp an angle as the walls of the\n"+
      "encampment itself",
    "well",
      "A well is visible to the east",
  });

  dest_dir=({
    DIR + "r/well.c",         "east",
  });
}

short(){ return "An encampment in the desert"; }

long(str){
  if(torch)
    long_desc =
"  This area has been dug out of the rock to create a very cozy, private\n"+
"place to bury the fallen.  Numerous tombstones protrude from the hard\n"+
"ground here, with the sandy ground disturbed to varrying degrees in\n"+
"front of them.  To the south the exterior wall of the encampment climbs\n"+
"into the sky, and to the north and west all you can see is rock.  An old\n"+
"well is visible to the east.  The sky is dark, the air is thick and warm,\n"+
"and there are a few torches mounted on the rock providing light for the\n"+
"tombstones.\n";
  else
    long_desc = 
"  This area has been dug out of the rock to create a very cozy, private\n"+
"place to bury the fallen.  Numerous tombstones protrude from the hard\n"+
"ground here, with the sandy ground disturbed to varrying degrees in\n"+
"front of them.  To the south the exterior wall of the encampment climbs\n"+
"into the sky, and to the north and west all you can see is rock.  An old\n"+
"well is visible to the east.  The sky is dark, the air is thick and warm,\n"+
"and there are a few torches mounted on the rock however they are all dark\n";
  ::long(str);
}

void init(){
  ::init();
  add_action("extinguish", "extinguish");
  add_action("light", "light");
  add_action("read_cmd", "read");
}

status read_cmd(string str)
{
  int a;
  string b;
  if(str != "tomb" && str != "tombstone" && str != "inscription")
    return 0;
  a = random(25);
  write("An inscription reads:\n");
  switch(a)
  {
  case 0:
    b = "Here lies Sir William Thatcher who died as he lived";
    break;
  case 1:
    b = "Sir Sagramore will live forever in our memories";
    break;
  case 2:
    b = "Lady Sybil the gem of the night sky.  Forever loved";
    break;
  case 3:
    b = "Rest in peace Lady Clarinda";
    break;
  case 4:
    b = "Tom of Warwick was a true gentleman and a true husband";
    break;
  case 5:
    b = "Han Sing was more a man then you'll ever be";
    break;
  case 6:
    b = "Here lies the social life of Zeus";
    break;
  case 7:
    b = "Here lies any hope of Zeus ever getting laid";
    break;
  case 8:
    b = "Love and Death.\n  Death and Love.\n  Of God's hand";
    break;
  case 9:
    b = "The memory of Michael O'Hagerty will never die";
    break;
  case 10:
    b = "A straight line may be the shortest distance between\n"+
      "  two points, but it is by no means the most interesting";
    break;
  case 11:
    b = "I'm just a simple man, trying to make my way in the universe";
    break;
  case 12:
    b = "Whether or not what we experienced was an According to Hoyle\n"+
      "  miracle is irrelevant. What is relevant is that I felt the\n"+
      "  touch of God. God got involved";
    break;
  case 13:
    b = "Here lies the memory of Qui-Gon Jinn";
    break;
  case 14:
    b = "Here lies snowball, my beloved cat";
    break;
  case 15:
    b = "Here lies my hopes and dreams of a better tomorrow";
    break;
  case 16:
    b = "Here lies Jesus, my hero";
    break;
  case 17:
    b = "For the record, I prefer writing code to updating Excel spreadsheets";
    break;
  case 18:
    b = "Here lies the Pope ... nobody cares";
    break;
  case 19:
    b = "Here lie many beta testers who have failed";
    break;
  case 20:
    b = "Here lies Smack....once a good mudder, such a shame....";
    break;
  case 21:
    b = "\"I Ain't As Good As I Once Was - Jatar\"";
    break;
  case 22:
    b = "Here lies Dreadwolf....\"Yes, I was that good.\"";
    break;
  case 23:
    b = "\"Heavy Metal Jesus\" -- Riddick";
    break;
  case 24:
    b = "\"Here lies Sartan.  Slain by the Lag Beast!!!\"";
    break;
  }
  write("  "+b+".\n");
  say(this_player()->query_name()+" reads an inscription.\n");
  return 1;
}
