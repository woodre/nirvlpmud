/*
 * oblit_longsword.c
 * Sir Obliterator's longsword (normal weapon)
 */

inherit "obj/weapon";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("black longsword");
  set_alias("longsword");
  set_alt_name("sword");
  set_class(16);
  set_value(200);
  set_weight(3);
  set_short("A black longsword");
  set_long("This is the black longsword of Sir Obliterator, the anti-paladin.\n"+
           "As a weapon it's not really that impressing, but Sir Obliterator\n"+
           "obviously things it is quite sufficient for the random encounters\n"+
           "he will have while he is on his quest - those nerds who actually\n"+
           "are stupied enough to attack him. Him!\n"+
           "For his real mission, though, he has another weapon...\n");
  set_hit_func(this_object());
}

int
weapon_hit(object victim)
{
  object env;
  env = find_living("obliterator");
  if (environment(this_object()) == env &&
      (object)env->query_attack() == victim &&
      victim->query_npc() &&
      (string)victim->query_name() != "Violens" &&
      object_name(environment(env)) != "/players/padrone/outside/crossing")
  {
    /* Obliterator is using his longsword to fight an NPC,
     * that is not Violens, in a place other than the crossing!
     */
    tell_room(environment(env),
              "Sir Obliterator says: I don't have time for this ridiculous "+
              "fighting.\n");
    tell_room(environment(env),
              "Sir Obliterator disappears in a puff of smoke.\n");
    move_object(env, "/players/padrone/outside/crossing");
    tell_room("/players/padrone/outside/crossing",
              "Sir Obliterator arrives in a puff of smoke.\n");
  }
  return 0;
}
