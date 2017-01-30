#include "def.h"
#include "/players/feldegast/std/colorize.h"

#include "cmds/ht.h"
#include "cmds/hte.h"
#include "cmds/hmuffle.h"
#include "cmds/hsc.h"
#include "cmds/hwho.h"
#include "cmds/hw.h"
#include "cmds/hpromote.h"
#include "cmds/hsave.h"
#include "cmds/quit.h"
#include "cmds/set_title.h"
#include "cmds/shine.h"
#include "cmds/know.h"

#include "cmds/attack.h"
#include "cmds/balance.h"
#include "cmds/bandage.h"
#include "cmds/bless.h"
#include "cmds/calm.h"
#include "cmds/cure.h"
#include "cmds/defend.h"
#include "cmds/disrupt.h"
#include "cmds/emtp.h"
#include "cmds/enhance.h"
#include "cmds/gift.h"
#include "cmds/glow.h"
#include "cmds/pyre.h"
#include "cmds/resurrect.h"
#include "cmds/rush.h"
#include "cmds/shield.h"
#include "cmds/ward.h"
#include "cmds/vita.h"



void reset(int arg) 
{
  move_object(this_object(),"/players/feldegast/closed/tower/study.c");
  CHANNEL->add_channel(GUILD_STRING, HIB+"["+NORM+"Healers"+HIB+"] "+NORM, 10);
  if(arg) return;
}

string *query_cmds() 
{
  string *cmds;
  int guild_rank;
  guild_rank=(int)TP->query_guild_rank();
  cmds=({ });

  if(guild_rank >= 1)
    cmds+=({
      "ht",
      "hmuffle",
      "hsc",
      "hwho",
      "hw",
      "hsave",
      "shine",
      "know",
      "set_title",
      "quit",
      "bandage",
    });

  if(guild_rank >= 2)
    cmds+=({
      "pyre",
      "glow",
      "balance",
    });

  if(guild_rank >= 3)
    cmds+=({
      "cure",
      "infuse",
      "defend",
    });

  if(guild_rank >= 4)
    cmds+=({
      "gift",
      "ward",
      "disrupt",
      "rush",
    });

  if(guild_rank >=5)
    cmds+=({
      "vita",
      "calm",
      "shield",
      "enhance",
    });

  if(guild_rank >= 6)
    cmds+=({
      "bless",
      "marry",
      "resurrect",
    });

  /* Guild wiz */
  if(guild_rank >= 10)
    cmds+=({
      "hpromote"
    });
  return cmds;
}

/* Physical properties */
string short() {
  return "The Heart of Order";
}

int id(string str) {
  return str=="heart";
}

void long() {
  write("This is The Heart of Order, the very source of the\n"+
        "power that Healers possess.\n");
}
