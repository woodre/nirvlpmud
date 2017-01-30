/*
 * CyberNinja Poison-Heal Object
 * Temporarily reduces a monster's heal rate.
 */

inherit "obj/clean";

int origHealRate, origHealIntv, poisonDuration;


id(str)
{
  return str == "_poisonHeal_";
}


get() { return 0; }
query_weight() { return 1; }
query_value() { return 0; }


status activate()
{
  call_out(
    "poisonDone", 
    poisonDuration, 
    origHealRate + " " + origHealIntv);
  return 1;
}


status poisonDone(string str)
{
  string *args;
  int rate, intv;
  object monster;

  if (environment() && this_object())
  {
    if (environment(this_object()))
    {
      monster = environment(this_object());

      if (!function_exists("query_heal_rate", monster))
      {
        /* this isn't a monster, maybe the monster died */
        destruct(this_object());
        return 1;
      }

      if (str && sscanf(str, "%d %d", rate, intv) == 2)
      {
        monster->set_heal(rate, intv);
        if (environment(monster))
        {
          tell_room(environment(monster), 
            "\n~~~~ " + 
            capitalize((string)monster->query_name()) +
            " seems to be overcoming the degenerative poison ~~~~\n\n");
        }
      }
    }
    destruct(this_object());
  }
  return 1;
}


setOrigHealRate(int x)   { origHealRate = x; }
setOrigHealIntv(int x)   { origHealIntv = x; }
setPoisonDuration(int x) { poisonDuration = x; }
