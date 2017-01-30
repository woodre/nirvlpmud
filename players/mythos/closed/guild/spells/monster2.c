/* recoded by verte 6.15.01 - to work with code i already
   wrote and for code yet to come in..

    inherits /obj/monster.
*/

#include "/players/mythos/closed/guild/def.h"

inherit "/players/mythos/amon/forest/monster1";

int disease, dischance, spec_aggres, intel, itl;

/* added by mizan */
void
reset(int arg)
{
    ::reset(arg);
}

void
init()
{
    int ste, atc, agnum, rdn;
    object a, *ob5, ob6, *ob7, grr;

    ::init();

    if(!environment()) return;

    if((a = this_player()) && !a->query_npc() &&
      !a->id("amoril") && !present("friend_ob", this_player()))
    {
      set_heart_beat(1);
      if(aggressive)
      {
        atc = random(100);
        ste = (int)a->query_attrib("ste");
        if (ste < atc)
          kill_ob = a;
       }
     if(intel == 1 && (tl < itl +1))
       kill_ob = a;
     if(spec_aggres)
     {
       int sa, si;
       object thing;

       ob5 = all_inventory(environment());
       agnum = 2;
       si = sizeof(ob5);
       for(sa=0;sa<si;sa++)
         if(living(thing = ob5[sa]) && thing != me && 
           !thing->id("messenger") && !thing->id("amoril") &&
           !present("friend_ob",thing))
         {
           ob6= clone_object("/players/mythos/closed/guild/spells/num.c");
           ob6->set_ag(agnum);
           move_object(ob6, thing);
           agnum ++;
         }
       rdn = random(agnum);
       si = sizeof(ob7 = all_inventory(environment()));
       for(sa=0;sa<si;sa++)
         if(rdn < 2)
           if(present(fear,(thing = ob7[sa])) && 
           !present("friend_ob", thing))
             kill_ob = thing;

      if(rdn > 1 && (grr = present("numbered", thing)))
        if(rdn == (int)grr->query_ag())
          kill_ob = thing;

      if(grr) destruct(grr);
      }
    }
}

void
set_spec_aggres()
{
    spec_aggres = 1;
}

void
set_intel(int n)
{
    intel = 1; 
    itl = n;
}

void
set_disease(int ds)
{
    disease = 1; 
    dischance = ds;
}

status
query_dmon()
{
    return 1;
}
