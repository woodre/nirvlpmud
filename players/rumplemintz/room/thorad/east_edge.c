/* ========================================================================== */
/*   east_edge.c                                                              */
/*   (c) 2007 Rumplemintz@Nirvana                                             */
/*                                                                            */
/*   Eastern Edge of Thorad                                                   */
/* ========================================================================== */

#include "/players/rumplemintz/room/thorad/THORAD_DEFS"
#include <ansi.h>

inherit COLOR_ROOM;

void
reset(int arg)
{
  if(arg) return;
  ::reset(arg);
  set_short(YEL, "Eastern Thorad");
  set_long(YEL, "\n"+
  "This appears to be the eastern edge of Thorad.  The city gates loom high \n"+
  "into the sky to the east.  There are various trails leading off around \n"+
  "the city.  A well traveled path leads westward.  Sounds of bustling trade\n"+
  "and caravans can be heard in the distance.\n");
  set_exit_color(CYN);
  dest_dir = ({
    THORAD+"thorad_gates", "east",
    THORAD+"ne_trail", "northwest",
    THORAD+"se_trail", "southwest",
    THORAD+"e_town", "west"
  });
  items = ({
    "gates", "The gates shoot skyward and appear inviting",
    "city gates", "The gates shoot skyward and appear inviting",
    "trails", "Trails lead in multiple directions",
    "city", "Not much can be made out from here",
    "path", "It appears to lead deeper into the city"
  });
}

void
init()
{
  ::init();
  add_action("listen", "listen");
}

int
listen(string str)
{
  if (!str
    || str == "to trade"
    || str == "to bustling trade"
    || str == "to caravans")
  {
    write("You can hear the sounds of the city from here.\n");
    return 1;
  }
  else return 0;
}
