/*
 * Test Armor - for use on LD for testing - do not use
 */

inherit "/obj/armor";

void
reset(status arg)
{
  if (arg)
    return;
  set_name("armor");
  set_short("Test Armor");
  set_long("Rumplemintz's Test Armor.  It looks VERY protective.\n");
  set_type("armor");
  set_ac(35);
  set_params("other|fire",0,95,"element_emote");
  set_params("other|ice",0,95,"element_emote");
  set_params("other|wind",0,95,"element_emote");
  set_params("other|fire",0,95,"element_emote");
  set_params("magical",95);
  set_weight(0);
  set_value(-1);
}

void
element_emote()
{
  if (environment())
    tell_object(environment(), "Your Test Armor absorbed a lot of that attack.\n");
}
