#pragma strong_types

inherit "room/room";

void populate();

void
reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("In a livingroom");
  set_long(
"In Kitiaras livingroom, this is a comfortable room where it\n"+
"should be possible to relax. the room is dimly lighted from a\n"+
"hole in the ceiling.\n");
  dest_dir = ({
    "players/kantele/kitiaras_innerhall", "north",
    "players/kantele/kitiaras_smallroom", "east",
    "players/kantele/kitiaras_strangeroom", "west"
  });
  items = ({
    "hole", "You look up in the whole, you see only light !"
  });
}

void
populate() {
  object kitiara;
  if (!present("kitiara", this_object())) {
    kitiara = clone_object("obj/monster");
    kitiara->set_name("kitiara");
    kitiara->set_level(20);
    kitiara->set_al(-1000);
    kitiara->set_short("Kitiara the Witch is here");
    kitiara->set_wc(30);
    kitiara->set_ac(17);
    kitiara->set_hp(500);
    kitiara->set_chance(30);
    kitiara->set_aggressive(1);
    kitiara->set_spell_mess1("Kitiara casts a flashing glance at you !");
    kitiara->set_spell_mess2("You are hit by the flashing glance !");
    kitiara->set_spell_dam(20);
    kitiara->add_money(random(5000));
    move_object(kitiara, this_object());
  }
}
