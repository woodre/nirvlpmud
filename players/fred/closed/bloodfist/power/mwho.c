#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object *w,a;
  int x,y,zz;
  string z;
  w = users();
  x = sizeof(w);
  zz = 0;
  TOU BOLD+BLK+"Nirvana\n"+NORM+
    " Name         Guild       Level   [p a i c d h]   Location\n"+RED+"["+
    NORM+BOLD+BLK+"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+NORM+RED+"]\n"+NORM);
  for(y = 0; y < x; y++)
  {
    if(!environment(w[y])){}
    else if(w[y]->query_level() >= 21 && w[y]->query_invis()){}
    else {
      zz++;
      z = pad(" "+capitalize((string)w[y]->query_real_name()), 14);
      if(w[y]->query_guild_name()) /* if guild */
      {
        if((string)w[y]->query_guild_name() == "Knights Templar") /* knight */
          z += pad("Knight", 12);
        else if((string)w[y]->query_guild_name() == "neo symbiote") /* symb */
          z += pad("NeoSymbiote", 12);
        else                                           /* if not knight */
          z += pad(capitalize((string)w[y]->query_guild_name()), 12);
      }
      else /* if no guild name */
        z += pad("None", 12);
      if(w[y]->query_level() > 20)  /* if wiz */
        z += HIY+pad((string)w[y]->query_level(),8)+NORM;
      else {
        z += (string)w[y]->query_level();
        if(w[y]->query_extra_level())
          z += pad("+"+w[y]->query_extra_level(),6);
        else {
          if(w[y]->query_level() < 10)
            z += pad("",7);
          else
            z += pad("",6);
        }
      }
      z += "[";
      if((w[y]->query_level() < 21 && 
        w[y]->query_pl_k()))       z += "p ";  else z += "  ";
      if(w[y]->check_fight_area()) z += "a ";  else z += "  ";
      if(query_idle(w[y]) > 360)   z += "i ";  else z += "  ";
      if(w[y]->query_attack())     z += "c ";  else z += "  ";
      if(w[y]->query_ghost())      z += "d ";  else z += "  ";
      if(w[y]->query_invis())      z += "h";   else z += " ";
      z += "]   ";
      if(w[y]->query_invis() && w[y]->query_level() >= User->query_level()){}
      else
        z += (string)environment(w[y])->short();
      z += "\n";
      TOU z);
    }
  }
  TOU RED+"["+NORM+BOLD+BLK+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+
    NORM+RED+"]\n"+NORM+
    "p = pk, a = pk area, i = idle, c = combat, d = dead, h = hidden\n");
  if(zz == 1)
    TOU "There is 1 person on Nirvana right now.\n");
  else
    TOU "There are "+zz+" people on Nirvana right now.\n");
  return 1;
}
