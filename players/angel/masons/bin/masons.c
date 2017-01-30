#include "../defs.h"

/* Global Variables */
int mylevel;

status filter_users(object ob)
{
  if (!environment(ob)) return 0;
  if ((int)ob->query_level() > mylevel && (int)ob->query_invis())
    return 0;
  return (present(MGOB_ID, ob) ? 1 : 0);
}

status main(string arg, int gl) {
  object gob;
  object *who;
  int i, siz;

  mylevel = (int)this_player()->query_level();
  siz = sizeof(who = filter_array(users(), "filter_users", this_object()));

  for (i = 0; i < siz; i++)
  {
    int lev;
    string levelstr;

    gob = present(MGOB_ID, who[i]);
    lev = (int)who[i]->query_level();
    levelstr = (lev < 10 ? " " : "") + lev;
    levelstr += (lev == 19 ? "+"+(int)who[i]->query_extra_level() : "    ");
    write(pad((string)who[i]->query_name(), 15)
      +pad(levelstr, 10)
      + pad((int)gob->query_glevel(), 6)
      + ( (status)gob->query_muffle() > 0 ? "(muffled)" : "" ) +"\n");
  }

  return 1;
}
