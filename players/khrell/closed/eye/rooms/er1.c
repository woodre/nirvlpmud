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
add_property("no_magic");

items = ({
  "plane","It endlesslsy spreads out before you",
  "bones","Long dead remains of many beings",
  "skulls","Their eyeless sockets stare vacantly out at you",
  "specters","They soundless scream adn moan in torment",
  "rift","A tear in the fabric of reality and space",
});

}

short(){ return HIR+"Eye of Terror"+NORM+" ("+HIK+"Rho'Rhakk"+NORM+")"; }

long()
{
  write( "   Stretching out endlessly before you is a vast plane of countless\n"+
         "bones and skulls of every race.  A maddening wind whips through the\n"+
         "area with a maddening cackle.  Faint etherial specters waft past in\n"+
         "an eternal torment, wordlessly howling in agony, this is the legendary\n"+
         "daemon world, Rho'Rhakk.  Named after a fell infernal creature that\n"+
         "had once been human but cast off it's humanity for immortality and a\n"+
         "eternal damnation as a prince of chaos.  You can see the pulsing out-\n"+
         "line of the rift that brought you here, and normal means of navagation\n"+
         "is useless as natural laws have ceased to exist.  One can move '"+HIW+"ahead"+NORM+"'\n"+
         "'"+HIW+"back"+NORM+"' or through the '"+HIW+"portal"+NORM+"'.\n");
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
  tp->move_player("fades from view#players/khrell/closed/eye/rooms/er2.c");
  return 1; }
  
back() {
  tp->move_player("vanishes into the swirling madness#players/khrell/closed/eye/rooms/er1.c");
  return 1; }
 
portal() {
  tp->move_player("steps through the warp rift#players/khrell/area/goblins/gobrm16.c");
  return 1; }

  
