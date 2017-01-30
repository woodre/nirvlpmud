/* Base object for guild spells
 */
#include "../def.h"

mapping requirements;
mapping costs;
string default_target; /* self, room, attacker */
string target_range; /* caster, room, mud */

string spell_name;
string fail_message;
string special_target_string;
int difficulty;
string difficulty_type;
int difficulty_multiplier;



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

query_requirements() {
  return requirements;
}

/*
  Does the basic checks common to all abilities, based on requirements
  Also checks for spell failure
*/
exec(str,usr,gob) {
  mixed target, result;
  int chk;
  /* First check for a valid target and if the user meets the requirements */
  target = DAEM->test_command(str, requirements, usr, gob, TO, default_target, special_target_string, target_range);
  if(!target) return 0;
  /* target equal to the command object means the user passed the tests, but has a special target */
  if(target == TO) target = 0;
  /* Next check for spell failure, if applicable */
  if(difficulty_type) {
    chk = DAEM->check_difficulty(difficulty, difficulty_type, difficulty_multiplier, (int)gob->query_healer_level(),
      (int)gob->query_healer_piety());
  } else {
    chk = 1;
  }
  if(chk) { /* spell did not fail, or cannot fail */
    result = TO->main(str, target, usr, gob);
  } else { /* spell failed */
    DAEM->display_fail_message(usr, fail_message);
    result = call_other(TO, "fail", str, target, usr, gob);
  }
  if(result)
      DAEM->asses_costs(result, costs, usr, gob, TO, target);
  return result;
}

/*
  By default, a difficulty fail will still result in all costs being assessed.
  If this needs to be changed, override the fail function and have it return 0.
*/
status fail() {
  return 1;
}

query_spell_name() { return spell_name; }
