/*
 * CyberNinja Poison-Aggressive Object
 * Temporarily makes a monster non-aggressive.
 */

inherit "obj/clean";


int poisonDuration;


id(str)
{
  return str == "_poisonAggressive_";
}


get() { return 0; }
query_weight() { return 1; }
query_value() { return 0; }


status activate()
{
  call_out("poisonDone", poisonDuration);
  return 1;
}


status poisonDone()
{
  string *args;
  int rate, intv;
  object monster;

  if (environment() && this_object())
  {
    if (environment(this_object()))
    {
      monster = environment(this_object());

      if (!function_exists("query_aggressive", monster))
      {
        /* this isn't a monster, maybe the monster died */
        destruct(this_object());
        return 1;
      }

      monster->set_aggressive(1);
      if (environment(monster))
      {
        tell_room(environment(monster), 
          "\n~~~~ " + 
          capitalize((string)monster->query_name()) +
          " seems to be overcoming the tranquilizer poison ~~~~\n\n");
      }
    }
    destruct(this_object());
  }
  return 1;
}


setPoisonDuration(int x) { poisonDuration = x; }
