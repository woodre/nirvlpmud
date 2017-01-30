#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  short_desc=BOLD+"An ancient plaza"+NORM;
  long_desc=
"  You stand amongst the ruins of some long forgotten city now turned\n\
to rubble and ruin.  A cobblestoned plaza, surrounded by pillars,\n\
stretches thirty meters in either direction.  Beyond the pillars you\n\
see only trees and bushes.  In the middle of the plaza is a fountain,\n\
a moss-covered reminder of a forgotten age.  Nearby, smoke rises from\n\
one of the few standing buildings, a small red-tiled residence that\n\
appears to have been maintained through the years, albeit somewhat\n\
poorly.  Next to the house is a long golden horn mounted on a stand.\n";
  items=({
    "city","You can make out very little beyond the plaza and a few\n"+
           "crumbling buildings",
    "plaza","The plaza is about thirty meters square and lined with\n"+
            "fluted columns",
    "trees","You judge them to be silverleaf trees, rare and hard to find",
    "bushes","The thick undergrowth prevents movement in all directions",
    "fountain","The fountain consists of a circular basin with the statue of\n"+
               "a lizard-like creature in the center.  The water is not running\n"+
               "and the water is probably bad",
    "building","A red tiled single-story residence that appears to have been\n"+
               "maintained through the years, albeit somewhat poorly",
    "horn","A long golden horn, bolted to a stone pedestal.  You can 'sound' it",
  });
  dest_dir=({
    ROOMPATH+"summhut.c","enter"
  });
}

void init() {
  ::init();
  add_action("cmd_blow","blow");
}

int cmd_blow(string arg)
{
  notify_fail("Blow what?\n");
  if(!arg || arg!="horn") return 0;
  if(!present("khazanth"))
  {
    while(remove_call_out("summon_dragon")!=-1) ;
    call_out("summon_dragon",20);
    write("You blow the horn, and are nearly deafened by the loud, echoing\n"+
          "sound it makes.\n");
  }
  else 
    write("The dragon is already here.\n");
  return 1;
}

void summon_dragon()
{
  call_other(NPCDIR+"khazanth","???");
  move_object(NPCDIR+"khazanth.c",this_object()); /* Only one at a time */
  tell_room(this_object(),
"A huge black dragon, his scales as black as coal, descends upon the\n\
tower and lands deftly.\n");
  call_out("wait_dragon",4);
}

query_loc() { return 2; }