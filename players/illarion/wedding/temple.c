inherit "/players/illarion/room";
#include "/players/illarion/dfns.h"
#define VERBS ({"quit","nirvana","look","exa","examine","inventory","score","tell"})
#define RING "/players/illarion/wedding/wring.c"

int silence_players;

reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A ruined temple");
  set_long(
"A wide floor of cracked cobblestones and some broken-off columns are all\n"+
"that remains of this temple, yet you sense a strong power still runs\n"+
"through this place.  The sky spreads above like a giant canopy, only\n"+
"a few white clouds and the occasional hawk marring the perfect shade of\n"+
"blue.  All around the ruins spreads a grassy plain, clearly visible from\n"+
"the hilltop where the temple sits.  Between the final two partial columns\n"+
"at the north end is a crumbling but recognizable altar.\n");

  add_item("floor",
"The cobblestones are cracked, with the occasional weed growing up between "+
"them, but the floor seems to be sound.");
  add_item("cobblestones",
"Wide, broad, and thick stones, meant to last a long time, but finally "+
"starting to yield to rain, wind, and plants.");
  add_item("columns",
"Once tall,  they are still proud, even though all of them have been broken, "+
"their fallen sections strewn next to the parts still standing.  Faint "+
"carvings are apparent on them all, but the passage of time has erased "+
"whatever they might have depicted.");
  add_item("sky",
"Blue, large, and distant, yet there is also a sense that it is close to "+
"the temple in some way.");
  add_item("clouds",
"The clouds drift across the sky indifferently, following the winds.");
  add_item("plains",
"A gently-rolling expanse of grass and very little else.  The hill the "+
"temple stands on seems to be the tallest for miles all around.");
  add_item("altar",
"The altar is a solid block of stone, and was carved once, but the carvings "+
"have faded away with the passing of years.  The power still lingering in "+
"the ruins seems to center around it.");

  add_exit("nirvana","room/church");
}
init() {
  ::init();
#ifndef __LDMUD__
  add_action("silence_hook"); add_xverb("");
#else
  add_action("silence_hook", "", 3);
#endif
  add_action("quick_wedding","marry");
  if(TP->query_level() >= 21)
    add_action("cmd_silence","silence");
}
cmd_silence() {
  silence_players=!silence_players;
  if(silence_players)  {
  tell_room(this_object(),"The ceremony is starting.  Please be quiet.  If "+
    "necessary, you may leave.\n");
    write("Silencing on.\n");
  } else
    write("Silencing off.\n");
  return 1;
}
silence_hook(str) {
  string verb,arg;
  if(TP->query_level()>19) return 0;
  if(!silence_players) return 0;
  if(!str) return 0;
  if(sscanf(str,"%s %s",verb,arg)!=2) verb=str;
  if(verb=="nirvana" || verb=="quit") return 0;
  write("Please be silent.\n");
  return 1;
}
quick_wedding(str) {
  string s1,s2;
  object ring1,ring2,sp1,sp2;
  if(!str) return 0;
  if(sscanf(str,"%s %s",s1,s2)!=2) return 0;
  sp1=present(s1); sp2=present(s2);
  if(!sp1 || !sp2) return 0;
  ring1=clone_object(RING);
  ring2=clone_object(RING);
  ring1->init_arg(s2+"@@@0@@@joins you in the realms of Nirvana.@@@leaves you all alone.");
  ring2->init_arg(s1+"@@@0@@@joins you in the realms of Nirvana.@@@leaves you all alone.");
  move_object(ring1,sp1);
  move_object(ring2,sp2);
  write("Done.\n");
  return 1;
}
