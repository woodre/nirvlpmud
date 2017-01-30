#ifndef _CRYSTAL_DEFS_

#include "/players/feldegast/closed/ansi.h"

#define TP         this_player()
#define TPN        (string)this_player()->query_name()
#define GUILD_DIR  "/players/feldegast/crystal/"
#define GOB        "/players/feldegast/crystal/gob.c"
#define MONSTER     "/players/feldegast/std/monster.c"
#define ROOM       "/players/feldegast/std/room.c"
#define ROOM_DIR   "/players/feldegast/crystal/rooms/"
#define OBJ_DIR    "/players/feldegast/crystal/obj/"
#define CMD_DIR    "/players/feldegast/crystal/cmds/"
#define SAVE_DIR   "players/feldegast/crystal/saves/"
#define HELP_DIR   "/players/feldegast/crystal/info/"
#define DEBUG_FILE "/players/feldegast/crystal/error.log"

#define GUILD_NAME "Crystal Mage"
#define GUILD_NEWS "/players/feldegast/crystal/NEWS"
#define GUILD_ID   "crystal_mage_guild_object"
#define CHANNEL    "/players/feldegast/std/channel.c"

#define NOSP_MSG   "You do not have enough energy.\n"

#define NOTHING    0
#define LIFEGAIN   1
#define MANAGAIN   2
#endif

#ifdef _MULTICOLOR_
string rand_color()
{
  switch(random(12))
  {
    case 0: return HIB; break;
    case 1: return HIR; break;
    case 2: return HIY; break;
    case 3: return HIM; break;
    case 4: return HIG; break;
    case 5: return HIC; break;
    case 6: return BLU; break;
    case 7: return RED; break;
    case 8: return YEL; break;
    case 9: return MAG; break;
    case 10: return GRN; break;
    case 11: return CYN; break;
  }
}

string multi_color(string str)
{
  string new;
  string *part;
  int i, length;
  int p;

  p = 0;
  part = allocate(2 * strlen(str));

  length = strlen(str);
  for(i = 0; i < length; i++)
  {
  part[i*2][0] = str[i];
    part[i*2+1] = rand_color();
  }
  new = implode(part, "");
  return new;
}
#endif
