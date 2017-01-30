/* Base object for guild spells
 */
#include "../def.h"

mapping requirements;
mapping costs;
status combat;
status heal;
string skill;

reset(arg) {
  if(!requirements) requirements = ([]);
  if(!costs) costs = ([]);
}

no_target(str) {
  if(str) {
    FAIL("Unable to locate target: "+str+".\n");
  }
  else {
    FAIL("This ability requires a target.\n");
  }
}

attack_fail(str) {
  FAIL("You cannot attack that target.\n");
}

heal_fail() {
  FAIL("You may not heal again so soon.\n");
}

query_requirements() {
  return requirements;
}

/*
  Does the basic checks common to all abilities, based on requirements
  It should not be necessary to override this function
*/
exec(str,usr,gob) {
  mixed target, result;
  int chk;
  target = DAEM->test_command(str, requirements, usr, gob, TO, combat, heal);
  if(!target) return 0;
  if(skill) chk = gob->check_skill(skill);
  result = TO->main(str, target, usr, gob, chk);
  if(result)
      DAEM->asses_costs(result, costs, usr, gob, TO, heal, target);
  return result;
}

emote(str,usr,targ) {
  return DAEM->emote(str,usr,targ);
}

query_skill() { return skill; }