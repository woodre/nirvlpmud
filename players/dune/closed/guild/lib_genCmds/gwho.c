#include "../DEFS.h"
#include DEFS_COLORPAD


status main(string str)
{
  int i, level, pk, extraLevel, playerCount;
  string gname, gen, room, msg;
  object *people;
  object ob;
  status hidePlayer;

  people = users();

  playerCount = 0;
  msg = "\n"+LINE+CYAN+ 
        "Player         Level   Guild        Pk  Gender  Location"+
        OFF+"\n"+LINE;

  for (i=0; i<sizeof(people); i+=1)
  {
    ob = people[i];

    if (TP->query_level() > ob->query_level())
    {
      hidePlayer = 0;
    }
    else if (TP->query_level() < 20 && ob->query_level() < 20 &&
             ((TP->query_level() + TP->query_extra_level()) > 
              (ob->query_level() + ob->query_extra_level())))
    {
      hidePlayer = 0;
    }
    else if (!ob->query_invis())
    {
      hidePlayer = 0;
    }
    else
    {
      hidePlayer = 1;
    }

    if (!hidePlayer)
    {
      playerCount++;
    /* no detail on the invis! */
    if(!ob->query_invis()) {
      level = (int)ob->query_level();
      gname = (string)ob->query_guild_name();
      pk    = (status)ob->query_pl_k();
      gen   = (string)ob->query_gender();
      extraLevel = (int)ob->query_extra_level();

      if (environment(ob))
        room = (string)environment(ob)->short();
      else room = "unknown";
      if (!room) room = "unknown";
    }
    else 
    {
      level = 0;
      gname = "unknown";
      pk   = (status)ob->query_pl_k();
      gen  = "unknown";
      room = "unknown";
      extraLevel = (int)ob->query_extra_level();
    }
      msg += pad(capitalize((string)ob->query_name()), 15)+" ";

      if (level >= 1000) msg += pad("GOD", 6);
      else
      if (level == 0) msg += pad("unk", 6);
      else      
      {
        if (level == 19 && extraLevel >= 1)
        {
          msg += pad(level + "+" + extraLevel, 6);
        }
        else
        {
          msg += pad(level, 6);
        }
      }

      msg += " ";

      if (gname && lower_case(gname) == "knights templar")
      {
        msg += pad("knights", 13);
      }
      else if (gname) msg += pad(gname, 13);
      else            msg += pad("", 13);

      if (pk) msg += pad("yes", 4);
      else    msg += pad("no", 4);

      msg += pad(gen, 8);

      msg += color_pad(room, 21)+OFF+OFF;
      msg += "\n";
    }
  }

  msg += LINE+"\n";

  if (!playerCount) write("Nobody logged on.\n");
  else              write(msg);

  return 1;
}
