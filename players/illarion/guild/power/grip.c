/* grip.c - start using a weapon with guild skills */

#include "/players/illarion/guild/def.h"

string help(object gob) {
  int cost;
  cost=10;
  if(gob)
    cost+=(int)gob->query_base_wc();
  return "Usage: grip <weapon>\n"+
         "Cost:  none\n\n"+
         "To use your skills, you must shift a sword into a two-\n"+
         "handed grip.  To do this, you must not be using a shield,\n"+
         "and you may not wear any more armor while using your two-\n"+
         "handed grip.  To stop using the grip, unwield your weapon.\n";
}

status main(string arg,object gob,object owner) {
  int wc,ac,skill_wc,skill_ac;
  object wep;
  int armor_wt;
  mapping armors;
  status shield_on;
  if(!arg)
    FAIL("Grip what?\n");
  wep=present(arg,owner);
  if(!wep)
    FAIL("You do not have that item.\n");
  if(wep!=(object)owner->query_weapon())
    FAIL("You must first be wielding the weapon.\n");
  if((string)wep->query_type()!="sword")
    FAIL("Your skills may only be applied to swords.\n");
  if(wep->query_broke())
    FAIL("You should have the weapon repaired first.\n");

  armors=(mixed)owner->QueryArmors();
  if(armors) {
    int x,s;
    object *gear;
    gear=m_indices(armors);
    s=sizeof(gear);
    ac=0;
    armor_wt=0;
    for(x=0;x<s;x++) {
      if(armors[gear[x]]==0)
        continue;
      if((string)gear[x]->query_type() == "shield") {
        shield_on=1;
        break;
      }
      ac+=(int)gear[x]->armor_class();
      armor_wt+=(int)gear[x]->query_weight();
    }
  }

  if(shield_on)
    FAIL("You need both hands free for your blade.\n");

  wc=(int)wep->weapon_class();
  /* Limit bonuses baseed on skills */
  skill_ac=(int)DAEM->calc_max_ac(gob);
  skill_wc=(int)DAEM->calc_max_wc(gob);
  if(wc>skill_wc) wc=skill_wc;
  if(ac>skill_ac) ac=skill_ac;

  gob->set_weapon(wep);
  gob->set_base_wc(wc);
  gob->set_base_ac(ac);
  gob->set_armor_wt(armor_wt);
  owner->RegisterArmor(gob,({"physical",ac,0,"armor_func"}));
  DAEM->do_skill_spam("grip",gob,owner,0,1);

  return 1;
}
