#include "../DEFS.h"
#include DEFS_ALEVELS
#include DEFS_OFFICES
#include DEFS_COLORPAD


status main(string str)
{
  int b, artlev, deg, honor, userCount;
  string brand, type, art, role, sphere, msg;
  object * iter;
  object ob;
  status hidePlayer;

  userCount = 0;
  msg = "\n"+LINE+
        BOLD+YELLOW+"  "+
        pad("Ninja",       12)+
        pad("Sensei",      12)+
        pad("Honor",       10)+
        pad("Chip",        12)+
        pad("Belt",         9)+
        pad("Guild Rank",  22)+
        OFF+"\n"+LINE;

  iter = users();
  for (b=0;b<sizeof(iter);b+=1)
  {
    ob = iter[b];

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
    
    if (!hidePlayer && present(GUILD_ID, iter[b]))
    {
      /* do not show muffled guild wizzes at all */
      if (IPOB->guild_wiz() && IPOB->muffled()) continue;

      userCount++;

      if ((string)IPOB->query_brand())
        brand  = capitalize((string)IPOB->query_brand());

      artlev = (int)IPOB->query_art_level();
      deg    = artlev - BLACK_BELT;
      if (deg < 0 ) deg = 0;
      role   = (string)call_other(OFFICED, "findRole", ob);

      if (IPOB->muffled() > 0) msg += "X";
      else                     msg += " ";

      if (call_other(OFFICED, "checkStone", ob, "diamond sapphire pearl ruby emerald onyx"))
        msg += "*";
      else
        msg += " ";

      msg += BOLD;
      if (ob->query_pl_k()) msg += RED;
      msg += pad(capitalize((string)ob->query_name()), 12)+OFF;

      if (IPOB->query_counselor())
      {
        msg += pad(capitalize((string)IPOB->query_counselor()), 12);
      }
      else
      {
        msg += "            ";
      }

      honor = (int)IPOB->query_honor();
      if (!IPOB->query_nohonor())
      {
        msg += pad((string)call_other(HLEVELD, "honorTitle", honor), 10);
      }
      else
      {
        msg += pad("Renegade", 10);
      }

      sphere = (string)IPOB->query_sphere();
      if(IPOB->guild_wiz() || sphere)
      {
        msg += color_pad("    "+RED+
          (string)call_other(OFFICED, "findSphere", ob, sphere)+OFF, 33);
      }
      else
      {
        msg += pad(brand, 12);
        if (deg > 0)
          msg += pad((string)call_other(ALEVELD, "findBeltColor", artlev)+" "+deg, 9);
        else
          msg += pad((string)call_other(ALEVELD, "findBeltColor", artlev), 9);
        if (!role) 
          type = (string)call_other(GLEVELD, "guild_title", (int)IPOB->guild_lev() + artlev);
        else
          type = capitalize(role);
        msg += pad(type, 12);
      }
      msg += "\n";
    }
  }

  msg += LINE;
  msg += "Note:  * = Sensei    X = Muffled\n\n";

  if (!userCount) write("No "+FUNKYNAME+"s currently online.\n");
  else            write(msg);
  return 1;
}
