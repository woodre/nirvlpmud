#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object corpse, wep;
  int cl; 
  if(User->query_ghost()) return 0;
  if(!PO->level_check(6)) return 0;
  if(str != "corpse") return 0;

  if((corpse = present("corpse", environment(User)))
    && corpse->is_corpse()){}
  else if((corpse = present("corpse", environment(PO)))
    && corpse->is_corpse()){}
  else {
    TOU "There is no corpse here to absorb.\n");
    return 1;
  }

  if((wep = (object)User->query_weapon()))
  {
    if(wep->query_bloodfist_wep_shadow()) /* wep is Bf wep */
      wep->add_charge((int)corpse->query_corpse_level());
    else {
      TOU "You are not using a Bloodfist weapon.\n");
      return 1;
    }
  }
  else {
    TOU "You are not using a weapon.\n");
    return 1;
  }

  TOU "You plunge your "+wep->short()+" into the corpse.\n"+
    "Your weapon absorbs the remaining life force of the corpse.\n");

  TRU Name+" plunges "+User->POS+" "+wep->short()+" into the corpse.\n"+
    Name+"'s weapon absorbs the remaining life force of the corpse.\n",
    ({ User }));

  destruct(corpse);
  return 1;
}
