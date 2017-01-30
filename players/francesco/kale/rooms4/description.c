#include "/players/francesco/univ/ansi.h"

long_descr(){
    switch(random(3)){
 /* description 1, static*/
     case 0: return ""+
     ""+HIR+"   A circular room, with several mirrors on the walls.  There is a\n"+
     "projector positioned on a tripod in the center of the room which sends\n"+
     "a beam of light through a colored glass towards the mirrors.  Due to\n"+
     "he multiple reflection on the mirrors the same pattern of light can\n"+
     "be seen with the same shape and the same colors regardless the position\n"+
     "of the spectator within the room.  By using suitable mechanisms the\n"+
     "mirrors can be rotated and shifted one against the others in order to\n"+
     "produce other patterns, differently shaped and colored.  Other patterns\n"+
     "of light are visible from the north, east, south and west directions."+NORM+"\n";
     break;
 /* description 2, dynamic, version 1.0*/
     case 1: return ""+
     ""+HIC+"   A circular room, with several mirrors on the walls.  There is a\n"+
     "projector positioned on a tripod in the center of the room which \n"+
     "sends a beam of light through a colored glass towards the mirrors.\n"+
     "The mirrors, the glass and the projector are continuously moved, \n"+
     "rotated and shifted one against the others by means of suitable \n"+
     "mechanisms, powered by small electrical engines.  Due to the \n"+
     "multiple reflections on the mirrors a pattern of light is formed\n"+
     "and can be seen with shape and colors changing endlessly, regardless\n"+
     "the position of the spectator within the room.  Other patterns of\n"+
     "light are visible from the north, east, south and west directions.\n";
     break;
 /* description 3, dynamic, version 1.1*/
     case 2: return ""+
     ""+HIM+"   A circular room, with several mirrors on the walls.  The room is\n"+
     "travelled by neverending beams of light which form colored patterns\n"+
     "onto a screen.  There is a projector positioned on a tripod in the\n"+
     "center of the room where the light emerges from.  The light in turn\n"+
     "is diffracted by a colored glass and reflected by the mirrors.  The\n"+
     "mirrors, the glass and the projector are continuously moved, rotated\n"+
     "and shifted one against the others by means of mechanical actuators, \n"+
     "powered by small electrical engines, thus producing patterns of light\n"+
     "which continuously change in shape and colors, endlessly, regardless\n"+
     "the position of the spectator within the room.  Other patterns of\n"+
     "light are visible from the north, east, south and west directions.\n";
     break;
 }
}