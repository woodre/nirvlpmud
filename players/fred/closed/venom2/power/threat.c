#include "../defs.h"

status main(string str, object PO, object User)
{
  int i, b, namer, gspacer, guilder, spacer;
  object *plist;
  
  if(GHOST) return 0;
  if(User->QL < 15) return 0;
  if(!User->query_pl_k())
  {
    TOU "Why would you care about such things when your own pk isn't set?\n");
    return 1;
  }
  if(User->query_sp() < 1)
  {
    TOU "You don't have the energy for this.\n");
    return 1;
  }

  plist = users();
  TOU "               "+BOLD+"-=[  "+HIR+"Threat List"+NORM+BOLD+"  ]=-"+NORM+"\n\n"+
      ""+HIR+"Name"+NORM+BOLD+":         "+HIB+"Guild"+NORM+BOLD+":"+
      "        Room:"+NORM+"\n");

  for(i=0; i<sizeof(plist); i++)
  {
    if(plist[i]->query_invis() && plist[i]->QL >= User->QL) continue;
    if(plist[i]->QL < 20)
    {
      if(plist[i]->query_pl_k() || plist[i]->query_fight_area())
      {
        namer = strlen((string)plist[i]->QN);
        spacer = 14 - namer;
        TOU HIR+plist[i]->QN+""+NORM);

        for(b=0; b<spacer; b++) 
        {
          TOU " ");
        }
        if(plist[i]->query_guild_name())
        {  
          guilder = strlen((string)plist[i]->query_guild_name());
          gspacer = 14 - guilder;
          TOU HIB+plist[i]->query_guild_name()+NORM+"");
        }
        else
        {
          gspacer = 10;
          TOU HIB+"none"+NORM);
        }
        for(b=0; b<gspacer; b++) 
        {
          TOU " ");
        }
        if(ENV(plist[i]))
        {
          TOU ENV(plist[i])->short()+"\n");
        }
        else
        {
          TOU "Unknown Location\n");
        }
      }
    }
  }
  TOU "\n\n");
  return 1;
}
