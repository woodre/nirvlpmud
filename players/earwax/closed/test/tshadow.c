/* Combat Tester Shadow */

#include "defs.h"

#define WHICH 1

/* Global Variables */
object Owner;

/* ==================================================================
 * Setup, Heartbeat and Shadow Functions
 * ==================================================================
 */
void heart_beat() 
{
  Owner->heart_beat();
  TESTD->add_round();
}

object start_shadow(object what) 
{ 
  Owner = what;
  return shadow(what, 1); 
}

void stop_shadow(object what) {
  shadow(what, 0);
  destruct(this_object());
}

/* ==================================================================
 * Masked Functions
 * ==================================================================
 */
int report(string fun, int dam)
{
  int dam2, hp, ret;
  
  hp = (int)Owner->query_hp();
  ret = (int)call_other(Owner, fun, dam);
  dam2 = (int)Owner->query_hp() - hp;
  TESTD->add_info(WHICH, fun, ({ dam, dam2 }) );  
  return ret;
}

/* Simple Damage Functions: These go through report() */
int heal_self(int dam)     { return report("heal_self", dam); }
int add_hit_point(int dam) { return report("add_hit_point", dam); }
int add_hp(int dam)        { return report("add_hp", dam); }

/* Now for the harder funs */
varargs int hit_player(string type1, string type2, int dam1, int dam2)
{
  int ret, t;
  
  t = (int)Owner->hit_player(type1, dam1);
  TESTD->add_info(WHICH, type1, ({ dam1, t }) );
  ret = t;
  t = (int)Owner->hit_player(type2, dam2);
  TESTD->add_info(WHICH, type2, ({ dam2, t }) );
  return ret + t;
}

varargs int do_damage(int *damage, string *method)
{
  int ret, i, dam;
  
  i = sizeof(damage);
  ret = 0;
  
  while(i--)  
  {
    dam = (int)Owner->do_damage( ({ damage[i] }), ({ method[i] }) );
    TESTD->add_info(WHICH, method[i], ({ damage[i], dam }) );
    ret += dam;
  }
  
  return ret;
}