/*
 * Daemon object to generate the long descriptions for the rooms.  Having the
 * code here in one object instead of every room object makes them more
 * readable, and also has the effect of less memory usage.
 * -- Rumplemintz
 */
#include <ansi.h>

string get_long_desc(int lineno) {
  string *line1, *line2, *line3, *line4, *line5, *line6, *line7;

  line1 = ({
"     Miles of long, dark, cold, twisting, dry,",
"     Deep within the miles of long, dark, cold,",
"     Deep, dark twisting caverns are cold, dry,",
  });

  line2 = ({
"     dragon breath glass,caverned walls entwine",
"     cavern walls, covered in dragon glass run",
"     smooth wall, encased in dragon glass entwine",
  });

  line3 = ({
"     throughout the cavern.  The air has thinned, ",
  });

  line4 = ({
"     making it difficult to breath the ambient air.",
"     causing even the slightest breath some pain.",
"     taking the wind of of the surrounding noise.",
  });
  
  line5 = ({
"     Unlike the walls, the path beneath you is not",
"     The hard trodden ground path beneath you is not",
"     Walking over the dragon melted stone it is not",
  });
  
  line6 = ({
"     smooth, but rough, uneven molten rock.",
  });
  
  line7 = ({
"         "+HIY+"*"+HIW+" - Denotes a Point of Interest"+NORM+"",
  });

  switch(lineno) {
  case 7: return line7[random(sizeof(line7))] + "\n"; break;
  case 6: return line6[random(sizeof(line6))] + "\n"; break;
  case 5: return line5[random(sizeof(line5))] + "\n"; break;
  case 4: return line4[random(sizeof(line4))] + "\n"; break;
  case 3: return line3[random(sizeof(line3))] + "\n"; break;
  case 2: return line2[random(sizeof(line2))] + "\n"; break;
  case 1: return line1[random(sizeof(line1))] + "\n"; break;
  default: return 0;
  }
  return 0;
}
