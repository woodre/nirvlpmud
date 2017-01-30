#include "/players/mythos/bounty/def.h"

/* set up for guildline - credit goes to Balowski whose examples i 
                          learned from and then improved upon */
object line_listen; /* global */

reset(arg) { if(arg) return; line_listen = ({}); }

listener(ob,arg,n) {
object targ;
int h;
  if(ob) {
  targ = ob;
  if(arg) { if (member_array(targ, line_listen) == -1) line_listen += ({ targ }); }
  else line_listen -= ({ targ });
  } else {
  line_listen = filter_array(line_listen, "nulling",this_object());
  for(h=0;h<sizeof(line_listen);h++) {
    if(presently(line_listen[h]) == -1) line_listen -=  ({ line_listen[h] });
  }
  if(n) return line_listen; }
}

presently(ob) {  object obs; obs = users();  return member_array(ob,obs);  }

nulling(ob){ return objectp(ob); }
  

/* guild powers */

#include "/players/mythos/bounty/spells/enhance.h"
#include "/players/mythos/bounty/spells/note.h"
#include "/players/mythos/bounty/spells/recall.h"
#include "/players/mythos/bounty/spells/tele_officer.h"
#include "/players/mythos/bounty/spells/ration.h" 
#include "/players/mythos/bounty/spells/grenade.h"
#include "/players/mythos/bounty/spells/smoke.h" 
#include "/players/mythos/bounty/spells/gline.h"

