#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
add_property("fight_area");
add_property("no_teleport");
add_property("no_follow");

items = ({
  "plane","It endlesslsy spreads out before you",
  "bones","Long dead remains of many beings",
  "skulls","Their eyeless sockets stare vacantly out at you",
  "specters","They soundless scream and moan in torment",
  "rift","A tear in the fabric of reality and space",
});

}

short(){ return "Realm of Chaos ("+HIK+"Formless Wastes"+NORM+")"; }

long()
{
  write( "   Stretching out endlessly before you is a vast plane of countless\n"+
         "bones and skulls of every race.  A maddening wind whips through the\n"+
         "area with a maddening cackle.  Faint etherial specters waft past in\n"+
         "an eternal torment, wordlessly howling in agony, this is the infamous\n"+
         "Wastes of Chaos, the Formless Wastes.  It is here that all natural laws\n"+
         "cease to exist, and what is perverse and unnatural exists.  Here the\n"+
         "insane and the nightmare are given form and life.  None can stay here\n"+
         "for long without feeling its gnawing at their sanity.  Normal navagation\n"+
         "is useless as natural laws have ceased to exist.  One can move '"+HIW+"ahead"+NORM+"'\n"+
         "'"+HIW+"back"+NORM+" '"+HIW+"left"+NORM+"' or '"+HIW+"right"+NORM+"'.\n");
}


init() {
  ::init();
  add_action("search","search");
  add_action("ahead","ahead");
  add_action("back","ahead");
  add_action("left","left");
  add_action("right","right");
}

search() {
  write("You search the area and find nothing special.\n");
  return 1; }

ahead() {
  tp->move_player("fades from view#players/khrell/closed/roc/rm4.c");
  return 1; }
  
back() {
  tp->move_player("vanishes into the swirling madness#players/khrell/closed/roc/rm2.c");
  return 1; }

left() {
  tp->move_player("vanishes into the swirling madness#players/khrell/closed/roc/rm5.c");
  return 1; }
  
right() {
  tp->move_player("vanishes into the swirling madness#players/khrell/closed/roc/rm6.c");
  return 1; }
	  	