/*
 * oblit_unholy_avenger.c
 * Sir Obliterator's Unholy Avenger
 */

inherit "obj/weapon";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("unholy avenger");
  set_alt_name("avenger");
  set_alias("sword");
  set_class(20);              /* Unmodified class, which never happens */
  set_value(8000);
  set_weight(6);
  set_short("An Unholy Avenger of Specified Annihilation");
  set_long("What a horrible weapon! It is black as night, cold as ice and heavy\n"+
           "as a gravestone soaked in blood. You shiver with fear just from\n"+
           "looking at this evil, evil, evil thing.\n"+
           "But you understand that this is a very special weapon, existing\n"+
           "only for a single purpose. Somewhere, someone has made this sword,\n"+
           "infested it with pure evil, and filled it with a hate that burns\n"+
           "for a single being in the world...\n");
  set_hit_func(this_object());
  set_wield_func(this_object());
}

int
weapon_hit(object victim)
{
  if ((string)victim->query_name() == "Violens")
  {
    if (!random(3))
    {
      write("The unholy avenger screams in thirst for blood!\n");
      say("The unholy avenger screams in thirst for blood!\n");
      return 20;
    }
    return 4;
  }
  else
  {
    write("The unholy avenger seems totally uninterested in this fight.\n");
    return -17;
  }
}

status
wield()
{
  if (this_player()->query_alignment() > -200)
  {
    write("This sword is not for you. Your personality is much too nice.\n");
    return 0;
  }
  else
  {
    write("Beware! This sword might not be as good as you believe it is.\n");
    return 1;
  }
}
