#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object *w,a;
  int x,y;
  string z;
  w = users();
  x = sizeof(w);
  TOU BOLD+BLK+"Bloodfist\n"+NORM+
    " Name         GL Level   Honor  [p a i c d h]  Location\n"+RED+"["+
    NORM+BOLD+BLK+"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+NORM+RED+"]\n"+NORM);
  for(y = 0; y < x; y++)
  {
    if((a = present("bloodfist_gob", w[y])) && environment(w[y]))
    {
      if(w[y]->query_level() >= 21 && w[y]->query_invis()){}
      else {
        z = pad(" "+capitalize((string)w[y]->query_real_name()), 14);
        z += pad((string)a->query_glevel(), 3);
        if(w[y]->query_level() < 20)
        {
          z += (string)w[y]->query_level();
          if(w[y]->query_extra_level())
            z += pad("+"+w[y]->query_extra_level(),6);
          else z += pad("",6);
        }
        else
          z += pad((string)w[y]->query_level(),8);
        if(w[y]->query_level() > 20)
          z += pad("Wiz", 7);
        else if(a->is_testchar())
          z += pad("TC",7);
        else
          z += pad((string)
          HONOR_DAEMON->query_honor(w[y]->query_real_name()),7);
        z += "[";
        if(w[y]->query_pl_k()) z += "p ";       else z += "  ";
        if(w[y]->check_fight_area()) z += "a "; else z += "  ";
        if(query_idle(w[y]) > 360) z += "i ";   else z += "  ";
        if(w[y]->query_attack()) z += "c ";     else z += "  ";
        if(w[y]->query_ghost()) z += "d ";      else z += "  ";
        if(w[y]->query_invis()) z += "h";       else z += " ";
        z += "]  ";
        z += (string)environment(w[y])->short();
        z += "\n";
        TOU z);
      }
    }
  }
  TOU RED+"["+NORM+BOLD+BLK+
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"+
    NORM+RED+"]\n"+NORM+
    "p = pk, a = pk area, i = idle, c = combat, d = dead, h = hidden\n");
  return 1;
}
