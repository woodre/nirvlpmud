/* sad we may have to make multiple of these . */

#include <ansi.h>

inherit "/obj/treasure";

void reset(int arg) {
  if(arg) return;
  set_id("gravestone");
  set_alias("stone");
  SetMultipleIds(({"gravesite","grave"}));
  set_short(HIW+"A beautiful grave"+NORM);
  set_long(HIW+"\
A beautiful white cross adorned in gilded letters.\n\
Upon its face, it reads:\n\
\n\
"+NORM+"\t"+YEL+"R.I.P.\n\
"+NORM+"\n\n\
  The Lord bless thee and keep thee.\n\
  The Lord cause his light to shine upon thee.\n\
  The Lord lift up his countenance upon thee.\n\
  And give thee peace.\n\
  Amen.\n");
}
