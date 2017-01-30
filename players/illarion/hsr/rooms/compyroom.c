inherit "room/room";
#include "../def.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="Strong Bad's Computer Room";
  long_desc="\
This small room is clearly all about the computer, which sits on a wooden\n\
table against the north wall.  A small stool sits under the table.  The\n\
walls are an even blue, broken only by doorways to the east and west, and\n\
a large sign above and to the left of the computer.  Beside the door to the\n\
west are two light switches, one at normal height, and one just above the \n\
yellow shag carpet.\n";
  items= ({
    "computer","\
It's an old-style all-in-one computer with a CRT monitor.  The label on the\n\
front says Compy 386",
    "stool","A wooden stool with a yellow cushion top.",
    "table","Yep.  It's a table.  Made of wood.",
    "walls","They're painted blue.  Nothing special about them.",
    "wall","&walls&",
    "doorway","\
Actually, they have doors in them.  Try to imagine you're opening and\n\
closing them as you pass through",
     "doorways","&doorway&",
     "door","Yeah, the things you open and close to get through doorways"
  });
  dest_dir= ({
    HRROOM+"entrance","east",
    HRROOM+"living","west"
  });
}
