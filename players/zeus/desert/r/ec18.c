inherit "room/room";       /* ec18 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The area here is desolate and lifeless.  Everywhere there is darkness.\n"+
"Vision is obscured by the blowing sands which whip against you.  To the\n"+
"southeast and east pieces of large mountains of rock are occasionally\n"+
"visible through the sands which seem to tower endlessly high.  The\n"+
"ground has been ravaged by the winds, all the remains are strewn rocks\n"+
"and a layer of forever shifting sand.\n";
  items=({
  "sands",
"The sands are blowing all around you.  Winds are whipping down from\n"+
"the mountains to the east and blowing furiously over your head,\n"+
"carrying the sands effortlessly",
  "mountains",
"As you stare to the northeast and east, glimpses of large mountains\n"+
"are visible through the blowing sands and the darkness.  It is hard\n"+
"to determine just how tall they are",
  "rock",
"The large mountains of rock tower high into the sky",
  "ground",
"The ground is hard, flat brown rock.  It is so dry that cracks seem\n"+
"to be the only visible feature.  Bits of sand rush over it as the\n"+
"winds blow around you",
  "sky",
"The sky is a swirling mass of darkness.  Different pieces of the sky\n",
"seem to be slightly different colors, not able to blend together\n"+
"with the other pieces.  It is a very mesmerizing sight as the winds\n"+
"course over your head",
  "sand",
"The sands are blowing all around you.  Winds are whipping down from\n"+
"the mountains to the east and blowing furiously over your head,\n"+
"carrying the sands effortlessly",
  "rocks",
"Small rocks are littered around you feet, mixed in with the cracks of\n"+
"the dry ground and the delicate sands.  They are brown and rather light",
  });
  dest_dir=({  "/players/zeus/desert/r/ec13.c", "north",
               "/players/zeus/desert/r/ec17.c", "west",  });
  }
 }

void init(){
  ::init();
  add_action("south_dir", "south");
  add_action("search_cmd", "search");
}

south_dir(){
  write("You walk south into the darkness...\n\n");
  this_player()->move_player("south#/players/zeus/desert/r/ec22.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

