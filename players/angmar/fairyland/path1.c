#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (!present("tramper", this_object())){
    object tramper, we;
    tramper = clone_object("obj/monster");
    tramper->set_name("tramper");
    tramper->set_level(10);
    tramper->set_hp(150);
    tramper->set_wc(13);
    tramper->set_ac(7);
    tramper->set_gender("male");
    tramper->set_short("A wandering tramper");
    tramper->set_alias("tramper");
    tramper->set_al(30);
    tramper->add_money(random(200));
    tramper->set_long(
"The wandering tramper is whistling happily.\n");
    we=clone_object("obj/weapon");
    we->set_name("stick");
    we->set_short("A long stick");
    we->set_class(7);
    we->set_value(100);
    we->set_weight(1);
    move_object(we, tramper);
    we=clone_object("obj/armour");
    we->set_name("shoes");
    we->set_short("Worn shoes");
    we->set_long("A pair of very worn shoes.\n");
    we->set_value(100);
    we->set_weight(1);
    we->set_ac(1);
    we->set_type("boot");
    move_object(we, tramper);
    move_object(tramper, this_object());
  }
  if (arg)
    return;
  set_light(1);
  short_desc = "The path to Misty Mountain";
  long_desc = 
"You are on the path to Misty Mountain. Many people have walked\n" +
"this path. Not many have returned...\n" +
"The entrance to Darkwood is to the east.\n";
  dest_dir = ({
    "players/angmar/fairyland/path2", "west",
    "players/angmar/fairyland/darkw_entrance", "east",
    "players/angmar/fairyland/crossing", "south",
  });
  items = ({
    "entrance", "The entrance to Darkwood seems evil and forboding",
    "darkwood", "The evil forest reeks of malignant airs...beware",
    "forest", "Darkwood, the mystical forest of pure evil",
    "path", "The path leads to Misty Mountain",
    "misty mountain",
      "The mountain seems huge, even though you are far away from it",
    "mountain", "The mountain seems huge, even though you are far away from it",
  });
}

string realm() { return ("fairyland"); }
