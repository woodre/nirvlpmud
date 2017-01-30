inherit "players/illarion/room";
#include "/players/illarion/dfns.h"
void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_short("A dark street in New York");
  set_long(
"Dark, dirty buildings stretch down the street to the east and west, "+
"disappearing into the gloom of insufficient street lights.  Wide, once "+
"nice sidewalks run down either side of the street, with the occasional "+
"parked car along or on them.  Along the south side of the street a board "+
"fence tries to fill the gap between two of the buildings, with a parked "+
"car directle in front of it.");

  add_item("buildings","Typical big-city buildings line the street to "+
                       "the north and south of the street.  The windows "+
                       "that aren't boarded up are dirty and dark; "+
                       "apparently this isn't the best neighborhood.");
  add_item("street","The asphault street is faded, cracked, and marked with "+
                  "numerous potholes.  The double yellow line down the "+
                  "middle is almost invisible.");
  add_item("lights","A few street lights march down the street, but they "+
                    "are either too far apart or giving off less light "+
                    "than they should, because they do nothing to dispel "+
                    "the gloom that seems to pervade the area.");
  add_item("sidewalks","These sidewalks seem to serve mainly as trash "+
                       "depositaries, although it's hard to tell wether "+
                       "the mounds of refuse are the human or inanimate "+
                       "variety.");
  add_item("trash","Smelly, ugly trash litters the sidewalks and the "+
                   "edges of the street.  Some of the piles look like they "+
                   "might shelter living things, if you're crazy enough to "+
                   BLD("check")+"them.");
  add_item("car","The car in front of the fence acually looks like it might "+
                 "run, even if it's not exactly new.  It seems to be emtpy "+
                 "right now, although "+BLD("disturbing")+" it might upset "+
                 "the owner, absent or not.");
  add_item("fence","A wall of weathered boards blocks off the end of an "+
                  "alley between two buildings to the south.  Enough of the "+
                  "slats are missing that you could probably "+BLD("peek")+
                  " into the alley without being seen.");

  add_exit("west",HROOM+"nystreet");
  add_exit("south",HROOM2+"alley");
  
}
void init() {
  ::init();
  add_action("cmd_check","check");
  add_action("cmd_dist","disturb");
  add_action("cmd_peek","peek");
}
int cmd_check(string str) {
  if(!str || str != "piles") FAIL("Check what?\n");
  write("You nudge a few of the piles of trash with your foot, causing them\n"+
        "to smell even worse.\n");
  say(format(
    TPN+" nudges some of the piles of trash with "+TP->query_possessive()+
    "foot.  The stink here becomes even worse.",70));
  /* possibility of disturbing a monster added later */
  return 1;
}
void alarm_emote(int x) {
  tell_room(this_object(),
"The car parked by the alley makes a loud, annoying alarm noise!\n");
  x++;
  if(x<5)
    call_out("alarm_emote",9,x);
}
int cmd_dist(string str) {
  if(!str || str != "car") FAIL("Disturb what?\n");
  write("You peer into the windows of the parked car, and find that is is\n"+
        "indeed empty.  On the seat is an open green canvas bag, with the\n"+
        "ends of what look like machine gun clips visible inside it.  As\n");
  write("you turn away, you brush the car a little too hard, and a loud,\n"+
        "obnoxious car alarm starts up!\n");
  say(format(
    TPN+" examines the car closely for a few moments, then somehow manages "+
    "to set off a loud, obnoxious alarm!\n",70));
  remove_call_out("alarm_emote");
  call_out("alarm_emote",9,1);
  return 1;
}
int cmd_peek(string str) {
  if(!str || str !="into alley")
    FAIL("Peek into what?\n");
  write("You peek through a gap in the boards of the fence into the alley,\n"+
        "and catch a glimpse of something shiny and new-looking, that\n"+
        "probably doesn't belong in a dark, dirty alley.\n");
  say(TPN+" peeks through a gap in the fence to the south.\n");
  return 1;
}
