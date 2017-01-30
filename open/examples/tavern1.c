#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Bloated Toad";
  long_desc=
"  A cool breeze blows through the open doors of this sleazy dive.  A\n\
typical crowd of low-lifes and thugs is scattered around the tables\n\
benches that populate the central room.  The tables are arranged so\n\
that there is a clear space in the center for entertainers.  To the\n\
east you hear the sound of gaming, and to the north you see a stair-\n\
case leading up and the bar where waitresses pick up food and drinks.\n";
  items=({
    "doors","They are spread wide open so that a cool breeze can blow in",
    "crowd","They don't look very interesting",
    "low-lifes","They don't look very interesting",
    "thugs","They don't look very interesting either",
    "tables","These are good strong tables, battered by abuse but still\n"+
             "strong and durable",
    "benches","The graffiti on one of the benches says: Kilroy was here",
    "bar","It is to the north",
    "waittresses","They bustle about among the patrons",
  });
  dest_dir=({
    PATH+"sgate.c","out",
    PATH+"stav2.c","north",
    PATH+"stav5.c","east",
  });
}