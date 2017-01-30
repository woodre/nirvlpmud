/*
 * Example for letting something be worn by the player only if a certain
 * condition is fulfilled, in this case we need a clip to close the robe.
 */

#include <message.h>

inherit "basic/message";
inherit "obj/armour";

void reset(status arg) {
  if (!clonep())
    return;
  ::reset(arg);
  if (arg)
    return;
  set_name("sorcerer's robe");
  set_alias("robe");
  set_short("sorcerer's robe");
  set_long(
    "The robe is made of dark blue fabric and has silver stars, moons and\n" +
    "suns applied on it. You notice two small holes at the collar. There\n"+
    "may be something needed to close the robe.\n");
  set_type("cloak");
  set_ac(1);
  set_value(800);
  set_weight(1);
}

mixed wear(string arg) {
  /* This function overloads the standard wear action of the armour */
  object what, clip;

  /* If player doesn't mean me, don't do anything */
  what = present(arg, this_player());
  if (what != this_object())
    return 0;

  /* is ther anything with id "clip"? */
  clip = present("clip", this_player());
  if (clip && (program_name(clip) == "domains/examples/obj/sorcerer_clip")) {
    /* We have a clip, and it's the right one */
    if (!worn_by) {
      /* We don't already wear it, apply the clip to the robe */
      message(({ ({ "As ", M_PLAYER, M_PL_VERB, " wrap", " the robe around ",
                    M_PL_POSSESSIVE, " shoulder, the clip happily jumps to ",
                    "the robe and fixes it." }) }));
      /* We don't need the clip now */
      destruct(clip);
    }
    /* Let complex/armour do the work of wearing it */
    return armour::wear(arg);
  }
  else { /* We don't have the right clip */
    message(({ ({ M_WRITE, "The robe slips from your shoulders. It seems ",
                  "as if something is missing." }),
               ({ M_SAY, M_PLAYER, M_PL_VERB, " try", " to wear the ",
                  "sorcerer's robe, but fails." }) }));
    return 1;
  }
}

mixed remove(string arg) {
  /* Overload the standard remove of the armour */
  object what;

  what = present(arg, this_player());
  if (what != this_object())
    return 0;
  if (worn_by) {
    message(({ ({ "The clip slips from ", M_PLAYER_S, " robe." }) }));
    move_object(clone_object("domains/example/obj/sorcerer_clip"),
                this_object());
  }
  return armour::remove(arg);
}

