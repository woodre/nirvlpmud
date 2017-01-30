#include "/players/feldegast/defines.h"

inherit "/players/feldegast/std/book.c";
void reset(int arg)
{
  if(arg) return;
  set_id("scroll");
  set_alias("invitation");
  set_short("A handwritten scroll");
  set_long(
"This is a short, handwritten scroll with a few short lines scribbled\n"+
"upon it in fine black ink.  At the bottom of the scroll is embossed\n"+
"the personal seal of the Master of the Crystal Tower.  Perhaps you\n"+
"should read it?\n"
  );
  set_weight(1);
  set_value(1);
  set_file(OBJ_PATH+"text/tourney.txt");
}
