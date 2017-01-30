#include <ansi.h>
#include "../lib/guild_defs.h"

inherit G_HALL;

void reset(status arg)
{
   ::reset(arg);
   if(arg) return;
   set_light(-5);
   set_short(CEN);
   set_long("\
  You stand before the gatehouse of the " + CEN + ".\n\
The two gigantic towers that make up the menacing gatehouse stand at\n\
least the height of fifty men. The marble around is decrepit and\n\
blood-stained from wars waged long ago. The battlements are dark\n\
and brooding. To the north, the drawbridge looms ominously.\n");
   add_exit(ROOMDIR + "f2", "north");
   add_exit("/room/south/sislnd18","exit");
   items = ({
"towers", "blah\n",
"gatehouse", "blah\n",
"marble", "blah\n",
"battlements", "blah\n",
"drawbridge", "blah\n",
});
}

