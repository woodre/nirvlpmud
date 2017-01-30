/* ========================================================================== */
/*   thorad_gates.c                                                           */
/*   (c) 2007 Rumplemintz@Nirvana                                             */
/*                                                                            */
/*   The gates to Thorad                                                      */
/* ========================================================================== */

#include "/players/rumplemintz/room/thorad/THORAD_DEFS" /* Thorad Area DEFS */
#include <ansi.h>

inherit COLOR_ROOM;

void
reset(int arg)
{
  if(arg) return;
  ::reset(arg);
  set_short(YEL, "Thorad Gates");
  set_long(YEL,"\n"+
    "Large golden gates tower into the forest skyline.  A well traveled path\n"+
    "shows signs of caravans and various animal tracks.  Ruts have formed in\n"+
    "dirt, creating collection spots for moisture and fallen leaves.  Trees\n"+
    "line the path, creating a tunnel out of the landscape.\n");
  set_exit_color(CYN);
  dest_dir = ({
    CASTLE_ROOM, "east",
    THORAD+"east_edge", "west"
  });
  items = ({
    "gates", "They appear as if they have not been closed in ages",
    "golden gates", "They appear as if they have not been closed in ages",
    "skyline", "The forest creates a beautiful skyline in the sky",
    "path", "There are ruts in the dirt from various caravans",
    "ruts", "Ruts in the path collect moisture and fallen leaves",
    "leaves", "The foilage is changing color, and leaves are beginning to fall",
    "trees", "The foilage is changing color, and leaves are beginning to fall",
    "tunnel", "The trees have overgrown the path, creating a tunnel",
    "moisture", "It collects in the ruts created by wheels",
    "tracks", "Various animal tracks",
    "animal tracks", "Various animal tracks",
    "dirt", "There are ruts in the dirt from various caravans",
  });
}
