#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIG+"Slytherin Dormitory"+NORM;
long_desc =
  "  Green bed frames with serpent heads on the top of each post support these\n"+
  "comfortable looking bed mattresses.  Under each bed is a sizeable trunk which\n"+
  "leaves room for the small table in the middle of the room.  Light comes through\n"+
  "the window in the northern wall and heat emminates from the fireplace in the\n"+
  "eastern wall.  A large candle burns brightly from table.\n";

items = ({
  "frames","Shiney green frames of wood with the corner posts carved to look like\n"+
           "a climbing snake",
  "heads","Snarling snake heads with long fangs",
  "post","Each corner post of every bed is carved to look like a snake",
  "mattresses","Soft filled mattresses with matching pillows",
  "trunk","Personal trunks to house each student's gear",
  "table","Round and distressed from many years of use, this wooden table is\n"+
          "often used to play Wizard chess",
  "candle","A large, green candle that when burning smells faintly like apples",
  "window","A long retangular window to let in the pale northern light",
  "fireplace","Small and cut into the rock, it provides heat to the room",
});

dest_dir = ({
  "players/eurale/Pot/slytherin2.c","south",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
