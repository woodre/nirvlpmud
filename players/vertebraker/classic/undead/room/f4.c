#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

void reset(status arg)
{
   if(arg) return;
   set_light(-5);
   set_short(CEN);
   long_desc = "\
  You stand inside the chapel within " + CEN + ".\n\
You hear gloomy, desperate music racketing from a phantom pipe organ.\n\
" + HIY + "Lightning" + NORM + " flashes through broken, boarded-up stained glass windows.\n\
To the north, you see a black altar. East lies an ornately decorated\n\
door; to the west a doorway, and the south brings you back to  \n\
the main gallery.\n";
  add_item(({"chapel","organ","lightning","stained glass windows",
             "windows","altar","black altar","door","doorway",
             "gallery"}),"");
  set_exits(({
ROOMDIR + "f5","north",
ROOMDIR + "f3","south",
}));
}
