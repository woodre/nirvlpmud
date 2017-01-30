/* *************************************************************************
 * Quit
 *
 * - Earwax 09/14/03
 *
 * Quit override.  If they quit out during pk, it's counted as a death.
 * They don't actually die or anything, but for the tracker statistical
 * purposes, it's considered a death.
 *
 * *************************************************************************
*/

#include "../defs.h"

void tell_wax(string arg) { object ob; if (ob = find_player("earwax")) tell_object(ob,arg+"\n"); }

status main(string arg) {
  object ob, t;
  object *killers;
  int i;

  t = (object)this_player()->query_attack();

  if (!t) {
    present(TRACKER_ID,this_player())->save_info(0);
    return 0;
  }

  killers = ({ });
  ob = first_inventory(environment(this_player()));

  while (ob) {
    if ((status)ob->is_player())
      if ((object)ob->query_attack() == this_player()) {
        t = present(TRACKER_ID,ob);
        if (t)
          killers += ({ ob });
      }
    ob = next_inventory(ob);
  }

  i = sizeof(killers);

  if (!i) {
    present(TRACKER_ID,this_player())->save_info(0);
    return 0;
  }
  
  write(HIC+"DAEMON tells you: Recording PK quit-out as death.\n");
  CHANNELD->channel_msg(HIB+"["+HIK+"Legends"+NORM+NORM+HIB+"] "+HIC
    + "DAEMON REPORTS: PK QUIT-OUT RECORDED AS A DEATH.\n");

  while(i--)
    present(TRACKER_ID,killers[i])->kill_check(this_player());

  t = present(TRACKER_ID,this_player());
  t->death_check(this_player());
  return 0;
}
