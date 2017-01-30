#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object corpse;
  string a,b;
  if(User->query_ghost()) return 0;
  if(!str) return 0;
  if(!sscanf(str, "%scorpse%s",a,b)) return 0;

  if((corpse = present(str, environment(User)))
    && !corpse->id("sacrificed_corpse") && corpse->is_corpse()
    && !corpse->id("preserved_corpse")){}
  else if((corpse = present("corpse", environment(PO)))
    && !corpse->id("sacrificed_corpse") && corpse->is_corpse()
    && !corpse->id("preserved_corpse")){}
  else
    return (notify_fail("What corpse do you want to preserve?\n"), 0);

  corpse->add_decay(1200);
  corpse->add_id("preserved_corpse");
  a = (string)corpse->short();
  corpse->set_short("preserved "+a);

  TOU "You pull out a balm from your belt and spread it over the corpse.\n"+
    corpse->short()+" is now preserved and will decay much slower.\n");

  TRU Name+" pulls out a balm from "+User->POS+" belt and spreads it "+
    "over the corpse.\n", ({ User }));
  return 1;
}
