#include "defs.h"

inherit MNDROOM;

void reset(int arg)
{
  if(!arg)
  {
    short_desc=HIG+"The Myrmidar Mound"+NORM;
    long_desc=
"  The tunnels of the myrmidar mound open up into a grotto.  The\n\
cave is lit up by a large crystal sphere that rests upon a strange\n\
metal pillar that sticks up out of the ground.  The sphere emanates\n\
an eery green light.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",        
      "sphere","The sphere is constructed of a faceted crystal.  The sphere\n"+
               "projects an eery green light that saps your strength",
      "pedestal","The pedestal is constructed of an alien metal that appears to have\n"+
                 "been subjected to an enormous amount of heat",
      "pillar","The pedestal is constructed of an alien metal that appears to have\n"+
               "been subjected to an enormous amount of heat",
    });
    dest_dir=({
      PATH+"mound8","northeast",
    });
  }
  if(arg==2) {
    short_desc=HIR+"The Myrmidar Mound"+NORM;
    long_desc=
"  The tunnels of the myrmidar mound open up into a grotto.  The cave\n\
is dark and cool.  The shattered remains of a large crystal sphere rest\n\
upon a metal pillar that sticks up out of the ground.\n";
    items=({
      "tunnels", "The passages are perhaps six feet high, circular, and well-travelled",        
      "sphere","The sphere has been shattered",
      "pedestal","The pedestal is constructed of an alien metal that appears to have\n"+
                 "been subjected to an enormous amount of heat",
      "pillar","The pedestal is constructed of an alien metal that appears to have\n"+
               "been subjected to an enormous amount of heat",
      "remains","Nothing worthwhile remains of it",
    });   
  }
  if(arg!=2) {
    if(!present("myrmidar"))
      move_object(clone_object(MON_PATH+"myrm-warrior.c"),this_object());
    if(!present("myrmidar 2") && random(2))
      move_object(clone_object(MON_PATH+"myrm-warrior.c"),this_object());
  }
}

void init() {
  ::init();
  add_action("cmd_break","break");
  add_action("cmd_break","shatter");
  add_action("cmd_break","smash");
  call_out("whack_me",random(10),TP);
}

int cmd_break(string str) {
  if(!str || (str!="crystal" && str!="sphere")) {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  if(present("myrmidar")) {
    write("The myrmidar prevent you from approaching the sphere.\n");
    return 1;
  }
  write("You "+query_verb()+" the "+str+"!  The green light fades and you immediately\n"+
        "feel better.  You sense that something has changed.\n");
  say(TPN+" smashes the crystal sphere!\n");
  reset(2);
  HIVEMIND->set_teleport(0);
  while(remove_call_out("whack_me")!=-1) ;
  return 1;
}

void whack_me(object targ) {
/* next line added by Vertebraker [5.24.01] */
   if(!targ) return;
  if(environment(targ)!=this_object()) return;
  tell_object(targ,HIG+"The green light seems to tax your strength.\n"+NORM);
  targ->add_spell_point(-random(4));
  call_out("whack_me",random(10),targ);
}
