/*
 * invis_com.c
 * Invisible companion to Wizard's apprentice
 */

#include <ansi.h>  /* Because someone added underlines to attack messages
                    * -- Rumplemintz
                    */
inherit "obj/monster";

void take_weapon(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("invisible companion of the apprentice");
  set_alias("invisible companion");
  set_short(0);  /* invisible! */
  set_long("He is invisible and lurks in a corner.\n");
  set_level(20);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_ac(22000000);
  set_hp(22000000);
#else
  set_ac(22000000);  /* don't want him dying */
  set_hp(22000000);  /* don't want him dying */
#endif
#if 0 /* Doesn't work on Nirvana, doesn't matter anyway -- Rumplemintz */
  setup_invis();
#endif

  /* setup gear */
  move_object(clone_object("/players/padrone/obj/immunity"), this_object());

  /* catch_tell setup */
  set_object(this_object());
  set_function("take_weapon");
  set_type("hit");
  set_match("");
  set_type("missed");
  set_match("");
  set_type("smashed");
  set_match("");
  set_type("massacred");
  set_match("");
}

object
get_wielded(object ob)
{
  object an_item, this_item;
  string junk;

  an_item = first_inventory(ob);
  while (an_item)
  {
    this_item = an_item;
    an_item = next_inventory(an_item);
    if (this_item->weapon_class()
        && (sscanf(this_item->short(), "%s (wielded)", junk)))
      return this_item;
  }
  return 0;
}

void
take_weapon(string str)
{
  object foe, foe_weapon, app_weapon, new_app_weapon;
  object apprentice;
  int app_wc, foe_wc;
  string who, rest;

  apprentice = present("apprentice", environment(this_object()));
  if (!apprentice)
  {
    destruct(this_object());
    return;
  }
  if ((sscanf(str, "%s hits Apprentice%s\n", who, rest) == 2)
   || (sscanf(str, "%s hit Apprentice%s\n", who, rest) == 2)
   || (sscanf(str, "%s missed Apprentice%s\n", who, rest) == 2)
   || (sscanf(str, "%s massacred Apprentice%s\n", who, rest) == 2)
   || (sscanf(str, "%s smashed Apprentice%s\n", who, rest) == 2))
  {
    foe = present(lower_case(who), environment(this_object()));
    if (!foe)
      return;
    if (!random(2))  /* 50% don't do it */
      return;
    app_weapon = get_wielded(apprentice);
    if (app_weapon)
      app_wc = (int)app_weapon->weapon_class();
    else
      app_wc = 0;
    foe_weapon = get_wielded(foe);
    if (foe_weapon)
    {
      say(HIW+"The apprentice casts the spell "+HIR+
          "MAGNETIC WEAPON SUMMONING"+NORM+".\n");
      write(HIW+"The apprentice casts the spell "+HIR+
            "MAGNETIC WEAPON SUMMONING"+NORM+".\n");
      foe_wc = (int)foe_weapon->weapon_class();
      foe_weapon->deShadow();
      if (foe_weapon->drop())
        tell_object(foe, "Strange, that weapon seems to be stuck.\n");
      else
      {
        int fweight;
        fweight = (int)foe_weapon->query_weight();
        say(capitalize((string)foe->query_name()) + "'s " +
            foe_weapon->query_name() +
            " jumps to the apprentice!\n");
        write("Your " + foe_weapon->query_name() +
              " jumps to the apprentice!\n");
        move_object(foe_weapon, apprentice);
        foe->add_weight(-fweight);
        if (foe_wc > app_wc)
        {
          apprentice->init_command("wield "+foe_weapon->query_name());
          new_app_weapon = get_wielded(apprentice);
          if (!new_app_weapon)
          {
            apprentice->init_command("wield "+app_weapon->query_name());
          } /* wield failed (Doomsgiver, for example), re-wield old weapon */
        }
      }
    } /* foe had a weapon */
  } /* if apprentice is in a fight */
} /* take_weapon */
