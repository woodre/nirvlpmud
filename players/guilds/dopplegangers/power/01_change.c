/*
 * change
 * Doppleganger command to morph into an evil creature
 */

object shadowob, badge, playerob, lookblocker, lightob;
string aoran, morph;

int unmorph_me(int called);

status main(string str) {
  if (this_player()->query_attack()) {
    write("Your adrenalyn is pumping too fast to morph in the heat of " +
          "battle.\n");
    return 1;
  }

  if (environment(this_player())->no_change()) {
    write("As you try to transform, you lose your concentration.\n");
    return 1;
  }

  badge = present("V-GUILD", this_player());

  morph = (string)badge->query_morph();
  if (!morph) morph = "orc";

  playerob = this_player();

  if (badge->query_fang_casting()) {
    write("You are busy drinking the blood of your victim.\n");
    return 1;
  }

  lookblocker = present("look_block", this_player());
  lightob = present("dopplegagner_light_object", this_player());

  if ((string)badge->query_morph() == "orc")
    aoran = "an";
  else
    aoran = "a";

  if (badge->query_morphed()) {
    write("You concentrate on your original form and become " +
          playerob->query_race() + " again.\n");
    if (find_call_out("unmorph_me") != -1)
      remove_call_out("unmorph_me");
    unmorph_me(1);
    if (lookblocker)
      destruct(lookblocker);
    if (lightob)
      destruct(lightob);
    return 1;
  }
  else
  {
    write("As you raise your hands, your body transforms into " + aoran +
          " " + capitalize(morph) + "!\n");
    say(this_player()->query_name() + " spins in a circle and transforms " +
        "into " + aoran + " " + capitalize(morph) + "!\n");
    shadowob = clone_object("/players/guilds/dopplegangers/obj/morph_shadow");
    shadowob->set_morph(morph);
    shadowob->set_doppleganger_player_shadow(this_player());
    badge->set_morphed(1);
    move_object(clone_object("/players/guilds/dopplegangers/obj/lookblock"),
                this_player());
    move_object(clone_object("/players/guilds/dopplegangers/obj/lightob"),
                this_object());
    call_out("unmorph_me", 600, 0);
    return 1;
  }
}

int unmorph_me(int called) {
  object lookblock, lightob;

  lookblock = present("look_block", playerob);
  lightob = present("doppleganger_light_object", playerob);
  shadowob->remove_doppleganger_player_shadow();
  if (!called)
    tell_object(playerob,
                "Your concentration is exhausted and you change back to " +
                "normal.\n");
  tell_room(environment(playerob), "You sense an evil being as " + aoran +
            " " + capitalize((string)badge->query_morph()) + " transforms " +
            "into " + playerob->query_name() + ".\n", ({ playerob }));
  badge->set_morphed(0);
  if (lookblock) destruct(lookblock);
  if (lightob) destruct(lightob);
  return 1;
}

