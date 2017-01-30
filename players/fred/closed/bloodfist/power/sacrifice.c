#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object corpse, wep, gold;
  int cl, ws, spec; 
  if(User->query_ghost()) return 0;
  if(!PO->level_check(1)) return 0;
  if(str != "corpse") return 0;

  if((corpse = present("corpse", environment(User)))
    && !corpse->id("sacrificed_corpse") && corpse->is_corpse()){}
  else if((corpse = present("corpse", environment(PO)))
    && !corpse->id("sacrificed_corpse") && corpse->is_corpse()){}
  else {
    TOU "There is no corpse here to sacrifice.\n");
    return 1;
  }

  wep = (object)User->query_weapon();
  cl = (int)corpse->query_corpse_level();
  if(cl > 25)
    PO->add_honor_potential(6);
  else if(cl > 22)
    PO->add_honor_potential(4);
  else if(cl > 20)
    PO->add_honor_potential(2);
  else if(cl > 18 && !random(10))
    PO->add_honor_potential(1);
  if(wep && wep->query_bloodfist_wep_shadow())
  {
    spec = (int)wep->query_spec();
    ws = (int)wep->query_ws();
    if((spec == 1 && ws == 24)    /* minor gold gem */
      || (spec == 2 && ws == 14)  /* gold gem       */
      || (spec == 3 && ws == 8))  /* major gold gem */
    {
      gold = clone_object("/obj/money.c");
      if(ws == 24)
        gold->set_money((int)corpse->query_corpse_level() * (25+random(5)));
      else if(ws == 14)
        gold->set_money((int)corpse->query_corpse_level() * (55+random(8)));
      else if(ws == 8)
        gold->set_money((int)corpse->query_corpse_level() * (85+random(11)));
      move_object(gold, environment(User));
      destruct(corpse);
      tell_object(User, 
        "The gem in your "+wep->query_type()+" glows gold.\n"+
        "The corpse is magically absorbed into the gem.\n"+
        "All that remains is a small pile of gold coins.\n");
      tell_room(environment(User), 
        HIY+Name+"'s "+wep->query_type()+" glows as the corpse is absorbed.\n"+
        NORM, ({ User }));
      return 1;
    }
  }
  corpse->add_decay(-96);
  corpse->add_id("sacrificed_corpse");

  TOU "You take the knife from your belt and drag it across the corpse.\n"+
    "Blood pours from the corpse as it quickly begins to rot away.\n");

  TRU Name+" takes the knife from "+User->POS+" belt and drags it across "+
    "the corpse.\nBlood pours from the corpse as it quickly begins to "+
    "rot away.\n", ({ User }));
  return 1;
}
