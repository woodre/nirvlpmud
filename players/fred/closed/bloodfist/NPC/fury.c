#include "/players/fred/closed/bloodfist/defs.h"
inherit "/obj/monster.c";
object owner, gob, att, wep;
string myn;
int a,b, old_wc;

void set_owner(object x){ owner = x; }

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_hp(500);
  set_heal(500,1);
  set_alias("fred_bf_fury");
}

short(){ return 0; }
void dest(){ destruct(this_object()); }
void class_set(int a){  old_wc = weapon_class = a;  }

int gob_checks()
{
  int c;
  if(!gob) return 0;
  if((int)gob->query_stance(1) == 1)  c = -4;      /* neutral    */
                                               /* aggressive */
  else if((int)gob->query_stance(1) == 3)  c = 4;  /* violent    */
  else if((int)gob->query_stance(1) == 4)  c = 7;  /* murderous  */
  else if((int)gob->query_stance(1) == 5)  c = 10; /* insane     */
  if((int)gob->query_bloodlust())
    c += (old_wc / 2);
  return c;
}

void heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  if(!owner){ return dest(); }
  if(find_player((string)owner->query_real_name()))
    move_object(this_object(), environment(owner));
  else return dest();
  if(!present(owner, environment())){ return dest(); }
  gob = present("bloodfist_gob", owner);
  if(!gob){ return dest(); }
  if(!gob->query_bloodfury()){ return dest(); }
  weapon_class = (old_wc + gob_checks());
  att = (object)owner->query_attack();
  if(!att){ return dest(); }
  if(attacker_ob != att)
    attack_object(att);
  if(attacker_ob != att){ return dest(); }
  if(present(attacker_ob, environment()) && !attacker_ob->query_ghost())
  {
    if((wep = (object)owner->query_weapon()))
      message_hit = (string *) wep->query_message_hit_array();
    for(a = 0; a < random(3); a++)
    {
      b = random(9);
      myn = capitalize((string)owner->query_real_name());
      switch(b)
      {
      case 0:
        tell_room(environment(),
          RED+"A red haze blurs behind "+myn+"!\n"+NORM);
        break;
      case 1:
        tell_room(environment(), 
          RED+myn+"'s motions blur as "+owner->PRO+" strikes!\n"+NORM);
        break;
      case 2:
        tell_room(environment(),
          RED+myn+" moves as if through a blood cloud!\n"+NORM);
        break;
      case 3:
        tell_room(environment(),
          RED+"A red streak extends behind "+myn+"!\n"+NORM);
        break;
      case 4..8: break;
      }
      already_fight = 0; 
      ::attack();
    }
  }
  owner->add_hit_point(-3);
  move_object(this_object(), "/room/void.c");
}

