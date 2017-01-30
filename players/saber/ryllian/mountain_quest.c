#include "/players/guilds/bards/bard_lib/include/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Clearing";
long_desc=
 "You stand in a stark clearing of dark rock and stone.  Above you looms the\n"+
 "massive bulk of mountains of the Spine of the Moon, while below you the face\n"+
 "of the mountain descends thousands of feet straight down.  In the center of\n"+
 "the clearing is a small circle of stones.\n";

items=({
 "stars","Softly gleaming stars are visible overhead",
 "mountain","Massive crags of towering rock loom over you",
 "mountains","Massive crags of towering rock loom over you",
 "rock","Massive crags of towering rock loom over you",
 "stone","Massive crags of towreing rock loom over you",
 "clearing","You stand in a clearing",
 "circle","A small circle of stones.  There's something funny about the\n"+
   "way that they have been arranged",
 });

  dest_dir=({
 "/players/saber/ryllian/mountain2.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("summon","summon");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

summon(str)  {
object ob, ob2;

  if(!str)  {
    write("Who will you attempt to summon?\n");
    return 1;
        }

ob = present("sapphire",this_player());
ob2 = present("instrument",this_player());

  if(!present("sapphire",this_player()))  {
    write("You do not have a sapphire.  How will you use a summoning?\n");
    return 1;
        }

  if(!present("instrument",this_player()))  {
    write("You are not a bard.  You may not summon!\n");
    return 1;
        }

  if((environment(ob2)->query_level()) < 8)  {
    write("You must be at least level 8 to attempt to summon.\n");
    return 1;
        }

  if(ob2->query_bard_level() !=3)  {
    write("You must be bard level 3 to attempt to summon.\n");
    return 1;
        }

  if(ob2->query_instrument() != (HIR+"Violin"+NORM)) {
    write("You are not using the correct instrument for the summons.\n");
    return 1;
        }

  if(str != "selsase")  {
    write("Nothing answers your summons...\n");
    return 1;
        }

  destruct(ob);
  write("Your gems disappears in a flash of violet light.\n\n"+
    "A spectral figure materializes in front of you...\n\n");
  say(tp+" disappears in a flash of violet light.\n");
  move_object(this_player(),"/players/saber/closed/bards/bardrooms/mountain_q.c");
  return 1;
        }
