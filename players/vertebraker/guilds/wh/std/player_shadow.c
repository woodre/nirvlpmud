#include "../def.h"

int beat_dr;
object shadowee;
static int dam_round;
static int last_dam;
static int total_dam;

reset(x)
{
  if(x) return;
  set_heart_beat(1);
}

start_shadow(ob)
{
  shadowee=ob;
  if(!ob) return;
  shadow(ob, 1);
}

end_shadow()
{
  shadow(shadowee, 0);
  destruct(this_object());
}

query_wh_shadow() { return 1; }

do_damage(damarr, typearr)
{
  int dam;
  int dd;
  object c;
  c = shadowee->query_pob_dd();
  dam = shadowee->do_damage(damarr, typearr);
  if(!c || c->query_attack() != shadowee) return dam;
  if(typearr && pointerp(typearr) && sizeof(typearr) == 2 && typearr[1] != "physical") {
    dd += damarr[1];
  }
  if(typearr && pointerp(typearr) && sizeof(typearr) == 1 && typearr[0] != "physical") {
    dd += damarr[0];
  }
  if(dd > 0)
  {
    if(dam_round) last_dam = dam_round;
    dam_round += dd;
  }
  return dam;
}

heart_beat()
{
  if(dam_round > 0) {
    if(beat_dr) {
    if(last_dam) {
      dam_round -= last_dam;
      total_dam += last_dam;
      last_dam = 0;
    }
    else {
      total_dam += dam_round;
      dam_round = 0;
    }
    beat_dr = 0;
    }
    else beat_dr = 1;
  }
/********* 
        ADJUST THIS LATER.  THIS CONTROLS SLOW BURN ENERGY
        DISSIPATION. THOSE WHO ARE LOWER RANKED/SKILLED
        WILL FIND THEIR ENERGY POOLS SLOWLY DISSIPATING INTO
        THEIR ENVIRONMENT. SET AT A '1' PT LOSS PER HB ATM.
*********/
  if(total_dam > 0) total_dam -= 1;

}

query_wh_kep() { return dam_round; }
query_wh_pep() { return total_dam; }
add_wh_pep(x) { total_dam += x; }
add_wh_kep(x) { dam_round += x; }
