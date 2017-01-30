#include <ansi.h>

inherit "/obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  
  set_name(HIR+"Freddy's"+NORM+" "+YEL+"Gloves"+NORM);
  set_short(HIR+"Freddy's"+NORM+" "+YEL+"Gloves"+NORM);
  set_long("\
These sinister looking gloves are make from a dark brown leather\n\
and four forged steel blades on each glove. One blade protrudes\n\
from each finger and is stained with blood.\n");
  set_type("gloves");
  set_weight(4);
  set_ac(0);
}

get()
{
  if(this_player()->query_real_name() != "nyteshade")
    return 0;
  else return ::get();
}

do_special(owner)
{
  object atk;
 if(!owner || (owner != environment())) return 0;
  if(!(atk=owner->query_attack()))
    return 0;
  if(owner->query_attrib("dex") > random(120))
  {
    object wep;
    owner->toggle_already_fight(1);
    if(wep = owner->query_weapon())
      wep->hit(atk);
    if(wep = owner->query_second_weapon())
      wep->hit(atk);
    owner->attack();
    tell_object(owner, HIR+"You counterattack!\n"+NORM);
    tell_room(environment(owner),
      HIR+owner->query_name()+" counterattacks!\n"+NORM,
      ({ owner }));
  }
  if(owner->query_attrib("dex") > random(90))
  {
    if(!atk) return 0;
    if (atk->query_name())
    {
      tell_object(owner,
        "Your "+YEL+"Gloves"+NORM+" "+RED+"REND"+NORM+" into "+
        atk->query_name()+"'s skin!\n");
      tell_room(environment(owner),
        owner->query_name()+"'s "+YEL+"Gloves"+NORM+" "+RED+"REND"+NORM
        +" into "+atk->query_name()+"'s skin!\n", ({ owner }));
      atk->hit_player(5 + random(5), "other|poison");
    }
  }
}
