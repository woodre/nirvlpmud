#pragma strong_type

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("In the Nightmare's stable");
  set_long(
"You are in the Nightmare's stable, the smell of sulphur lies\n" +
"heavy in the air. you can flee south onto the roof.\n");
  dest_dir = ({
    "players/kantele/on_roof", "south"
  });
}

void
populate() {
  object nightmare, harness;
  if (!present("nightmare", this_object())) {
    nightmare = clone_object("obj/monster");
    nightmare->set_name("nightmare");
    nightmare->set_level(19);
    nightmare->set_short("A large nightmare is here");
    nightmare->set_wc(28);
    nightmare->set_ac(16);
    nightmare->set_hp(450);
    nightmare->set_al(-300);
    nightmare->set_aggressive(1);
    nightmare->set_chance(30);
    nightmare->set_spell_dam(40);
    nightmare->set_spell_mess1("The demon steed breaths fire at you.");
    nightmare->set_spell_mess2("You are hit by the firebreath");
    nightmare->add_money(3000 + random(600));
    move_object(nightmare, this_object());
    harness = clone_object("obj/treasure");
    harness->set_id("harness");
    harness->set_short("The nightmare's harness");
    harness->set_value(600);
    move_object(harness, nightmare);
  }
}
