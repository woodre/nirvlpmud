#include "/players/fred/closed/bloodfist/defs.h"
#define ME "Seht Deyad"
inherit "room/room";       /* ec4 */
object guardian;
string *beta;

reset(arg){

  if(!present("seht", this_object()))
  {
    guardian = clone_object("/players/fred/closed/bloodfist/NPC/guardian.c");
    move_object(guardian, this_object());
  }

 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  The warmth of the darkness seems to surround you here.  The thick\n"+
"looking black sky swirls slowly as the wind cuts through it.  Flecks\n"+
"of sand fly past your face, obscuring your vision.  The ground is\n"+
"hard, dry and seemingly lifeless.  Small rocks are scattered over\n"+
"the flat tiles of brownish stone.  Towering mountains loom to the\n"+
"north and east of this corner of the desert.\n";
  items=({
  "sky",
"The sky is a luminous mass of dark swirls.  The wind causes it to\n"+
"constantly writhe and shift above you",
  "wind",
"The wind is blowing all around you, blowing the sand which obscures\n"+
"your vision",
  "sand",
"Bits of sand writhe at your feet, as well as fly past your face.  The\n"+
"wind which never seems to stop makes the sand almost seem alive",
  "ground",
"The ground seems so lifeless and dead.  It is hard and flat, lined with\n"+
"dry cracks which run ever so deep.  Life does not seem to have existed\n"+
"here for ages",
  "rocks",
"Small rocks are littered across the ground, mingling with the sand",
  "face",
"As you stare at the face of the rock mountains to the north, you\n"+
"realize that there is a hidden pathway that leads north into a ravine\n"+
"It is hard to tell what else might be lurking in the shadows",
  "rock",
"As you stare at the face of the rock mountains to the north, you\n"+
"realize that there is a hidden pathway that leads north into a ravine\n"+
"It is hard to tell what else might be lurking in the shadows",
  "shadows",
"As you stare at the shadows at the base of the mountains to the\n"+
"north, you realize that there is a hidden pathway that leads north\n"+
"into a ravine.  It is hard to tell what else might be lurking in the\n"+
"shadows",
  "mountains",
"The mountains to the north and east make travel in those directions\n"+
"seemingly impossible.  They are massive towers of rock that penetrate\n"+
"the ongoing darkness of the sky.  The face of the rock is cloaked in\n"+
"particularly dark shadows for some reason",
  "stone",
"The ground is made of dull, brown stone.  It is all very dry and cracked",
  "cracks",
"The ground is lined with small and large cracks",
  });
  /*
  dest_dir=({  "/players/zeus/desert/r/ec8.c", "south",
               "/players/zeus/desert/r/ec3.c", "west",  });
  */
 }
}

void init(){
  ::init();
  if(this_player()->is_player())
  {
    if((string)this_player()->query_guild_name() != "bloodfist")
    CHAN_DAEMON->hprint(RED+" WARNING "+NORM+BOLD+BLK+
      capitalize((string)this_player()->query_real_name())+
       " is at the guild entrance!!\n"+NORM);
   }
  add_action("west_dir", "west");
  add_action("south_dir", "south");
  add_action("north_dir", "north");
  add_action("search_cmd", "search");
  this_player()->set_fight_area();
}

exit(){
  if(this_player()) this_player()->clear_fight_area();
}

west_dir(){
  write("You walk west into the darkness...\n\n");
  if(this_player()->is_player())
  {
    if((string)this_player()->query_guild_name() != "bloodfist")
    CHAN_DAEMON->hprint(RED+" ALERT "+NORM+BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+
    " has left the guild entrance!!\n"+NORM);
  }
  this_player()->move_player("west#/players/zeus/desert/r/ec3.c");
  return 1;
}

south_dir(){
  write("You walk south into the darkness...\n\n");
  if(this_player()->is_player())
  {
    if((string)this_player()->query_guild_name() != "bloodfist")
    CHAN_DAEMON->hprint(RED+" ALERT "+NORM+BOLD+BLK+
    capitalize((string)this_player()->query_real_name())+
    " has left the guild entrance!!\n"+NORM);
  }
  this_player()->move_player("south#/players/zeus/desert/r/ec8.c");
  return 1;
}

north_dir(){
  if(present("seht", environment(this_player())))
  {
    if(this_player()->query_guild_name() != "bloodfist")
    {
      tell_room(this_object(), 
       ME+" says, \"You may not pass "+
        capitalize((string)this_player()->query_real_name())+".\"\n");
      return 1;
    }
    else
    {
     tell_room(this_object(), ME+" nods to "+
        capitalize((string)this_player()->query_real_name())+".\n\n",
        ({ this_player() }));
      tell_object(this_player(), ME+" nods to you.\n");
    }
  }
  this_player()->move_player(
    "into the darkness#players/fred/closed/bloodfist/r/ravine2.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

