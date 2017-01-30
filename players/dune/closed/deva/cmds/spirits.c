/*
 * SPIRITS command for Ascension
 * who command to list guild members
 */
#include "../def.h"

status main() {
  int i, lev, xlev, glev, qp, lev_percent, qp_percent;
  string type;
  object *people;
  object ob;
  people = users();

  write("\n");
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  write("Spirit       Type                  Level%    Quest%\n");
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  for(i=0;i<sizeof(people);i++)  {
    ob = people[i];
    if(!ob->query_invis()) {
      if(IPOB)  {
        glev = ((int)IPOB->query_setting(CLASS));
        type = ((string)LEVELD->get_title(glev));
        lev  = ((int)ob->query_level());
        xlev = ((int)ob->query_extra_level());
        qp   = ((int)ob->query_quest_point());
        lev_percent = ((int)LEVELD->get_lev_percent(lev, xlev));
        qp_percent  = ((int)LEVELD->get_qp_percent(qp));
        write(pad(OPN,13));
        write(pad(type,25));
        write(pad(lev_percent, 10));
        write(pad(qp_percent, 3));
        write("\n");
        }
      }
    }
  write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 1;
}
