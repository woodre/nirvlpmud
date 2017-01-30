#include "/players/francesco/univ/ansi.h"

long_descr(){
    switch(random(1)){
 /* description 1, static*/
     case 7: return ""+
     "\n(note: this is the 'static' description)\n\n"+
     "   A circular room, with several mirrors on the walls.  There is a\n"+
     "projector positioned on a tripod in the center of the room which sends\n"+
     "a beam of light through a colored glass towards the mirrors.  Due to\n"+
     "the multiple reflections on the mirrors the same pattern of light can\n"+
     "be seen with the same shape and the same colors regardless the position\n"+
     "of the spectator within the room.  By using mechanical actuators the\n"+
     "mirrors can be rotated and shifted one against the others in order to\n"+
     "produce other patterns, differently shaped and colored.  Other patterns\n"+
     "of light are visible from the north, east, south and west directions."+NORM+"\n";
     break;
 /* description 2, dynamic, version 1.0*/
     case 1: return ""+
     "\n(note: this is the 'dynamic' description, version 1)\n\n"+
     "   A circular room, with several mirrors on the walls.  There is a\n"+
     "projector positioned on a tripod in the center of the room which \n"+
     "sends a beam of light through a colored glass towards the mirrors.\n"+
     "The mirrors, the glass and the projector are continuously moved, \n"+
     "rotated and shifted one against the others by means of mechanical\n"+
     "actuators, powered by small electrical engines.  Due to the multiple\n"+
     "reflections on the mirrors a pattern of light is formed on a screen \n"+
     "and can be seen with shape and colors changing endlessly, regardless\n"+
     "the position of the spectator within the room.  Other patterns of\n"+
     "light are visible from the north, east, south and west directions."+NORM+"\n";
     break;
 /* description 3, dynamic, version 1.1*/
     case 2: return ""+
     "\n(note: this is the 'dynamic' description, version 2)\n\n"+
     "   A circular room, with several mirrors on the walls.  The room is\n"+
     "travelled by neverending beams of light which form colored patterns\n"+
     "on a screen.  There is a projector positioned on a tripod in the\n"+
     "center of the room where the light emerges from.  The light in turn\n"+
     "is diffracted by a colored glass and reflected by the mirrors.  The\n"+
     "mirrors, the glass and the projector are continuously moved, rotated\n"+
     "and shifted one against the others by means of mechanical actuators, \n"+
     "powered by small electrical engines, thus producing patterns of light\n"+
     "which continuously change in shape and colors, endlessly, regardless\n"+
     "the position of the spectator within the room.  Other patterns of\n"+
     "light are visible from the north, east, south and west directions."+NORM+"\n";
     break;
     case 3: return ""+
     "\n(note: this is the 'dynamic' description, version 3)\n\n"+
     "   A circular room, with several mirrors on the walls.  The room is\n"+
     "travelled by neverending beams of light which form colored patterns\n"+
     "on a screen.  There is a projector positioned on a tripod in the\n"+
     "center of the room where the light emerges from.  The light in turn\n"+
     "is diffracted by a colored glass and reflected by the mirrors.  The\n"+
     "mirrors, the glass and the projector are continuously moved, rotated\n"+
     "and shifted one against the others by means of mechanical actuators, \n"+
     "powered by small electrical engines.  Thus, the formed pattern of \n"+
     "light is continuously changing in shape and colors, endlessly, \n"+
     "regardless the position of the spectator within the room.  Other  \n"+
     "patterns of light are visible in the surrounding area."+NORM+"\n";
     break;
     case 4: return ""+
     "\n(note: this is the 'dynamic' description, version 4)\n\n"+
     "   A circular room, with several mirrors on the walls.  The room is\n"+
     "travelled by neverending beams of light which form colored patterns\n"+
     "on a screen.  There is a projector positioned on a tripod in the\n"+
     "center of the room where the light emerges from.  The light in turn\n"+
     "is diffracted by a colored glass and reflected by the mirrors.  The\n"+
     "mirrors, the glass and the projector are continuously moved, rotated\n"+
     "and shifted one against the others by means of mechanical actuators, \n"+
     "powered by small electrical engines.  So, the formed pattern of light\n"+
     "is continuously changing in shape and colors, endlessly, regardless\n"+
     "the position of the spectator within the room.  Other  patterns of\n"+
     "light are visible from the north, east, south and west directions."+NORM+"\n";
     break;
     case 5: return ""+
     "   A circular room with several mirrors on the walls.  Neverending\n"+
     "beams of light travel the room and are reflected by the mirrors \n"+
     "and play with each other and form patterns always different in the \n"+
     "shape and color.  Seems like the spectators in this room are wrapped \n"+
     "by the light itself.  More patterns of light are visible from north, \n"+
     "east, south and west directions in an endless multicolored show.\n";
     break;
     case 6: return ""+
     "   A circular room with several mirrors on the walls.  Neverending\n"+
     "beams of light travel the room and are reflected by the mirrors \n"+
     "and play with each other and form patterns always different both\n"+
     "in shape and color.  More patterns of light are visible from north, \n"+
     "east, south and west directions in an endless multicolored show.\n";
     break;
     case 0: return ""+
     "   A circular room with several mirrors on the walls.  Neverending\n"+
     "beams of light travel the room and are reflected by the mirrors, \n"+
     "play with each other, form patterns always different in shape and\n"+
     "color.  You feel completely wrapped up in this game of light.\n"+
     "More patterns of light are visible from north, east, south and \n"+
     "west directions in an endless multicolored show.\n";
     break;  }
/*
   else {
     return ""+
     "   A circular room, with several mirrors on the walls.  The room is\n"+
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
   }
*/
}
