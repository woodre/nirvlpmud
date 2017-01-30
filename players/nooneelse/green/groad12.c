/*
 groad12.c - evil side of green road
*/

inherit "room/room";

string str, str2;

object mimic, coins;

init() {
  ::init();

  add_action("mimic_react", "take");
  add_action("mimic_react", "get");
  add_action("mimic_react", "open");
  add_action("mimic_react", "unlock");
}

mimic_react(str) {
  object mimic_obj;
  if (!str) return;
  mimic_obj=present("mimic");
  if (!mimic_obj) return;
  sscanf(str, "at %s", str2);
  if (str != "mimic" &&
      str != "chest" &&
      str != "box" &&
      str2 != "mimic" &&
      str2 != "chest" &&
      str2 != "box")
    return;
  write("As you examine the object, you realize that it is not a box,\n");
  write("but some kind of monster!\n");
  mimic_obj->attack_object(this_player());
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("a gloomy path");
  no_castle_flag=1;
  long_desc="You are standing on a path in a gloomy forest.  "+
            "You sense evil everywhere.\n";
  items =
    ({
      "forest", "It is a dense forest.  The trees are too close together for\n"+
                "you to go anywhere except on the path.",
      "path", "It is a narrow, clear path.",
      "trees", 
        "The trees are twisted and diseased.  There are many thornbushes.",
      "tree", "The tree is twisted and diseased.  There are many thornbushes.",
      "thornbush", "The bush is thick and has long, dangerous thorns.",
      "thornbushes", "The bushes are thick and have long, dangerous thorns.",
      "bushes", "The bushes are thick and have long, dangerous thorns.",
      "bush", "The bush is thick and has long, dangerous thorns.",
      "thorns", "The thorns are long and sharp.",
      "thorn", "The thorn is long and sharp.",
    });
  dest_dir=
    ({
      "players/nooneelse/green/groad11", "west",
      "players/nooneelse/green/groad13", "south",
    });
  if (!present("mimic")) {
    mimic=clone_object("obj/monster");
    mimic->set_name("mimic");
    mimic->set_alias("chest");
    mimic->set_level(6); /*13*/
    mimic->set_hp(180);  /*120*/
    mimic->set_wc(13);   /*10*/
    mimic->set_ac(5);    /*8*/
    mimic->set_al(-230);
    mimic->set_ep(63000);
    mimic->set_short("A wooden chest");
    mimic->set_long("A large wood chest with iron straps and fittings.\n");
    mimic->set_aggressive(0);
    coins=clone_object("obj/money");
    coins->set_money(360);
    move_object(coins, mimic);
    move_object(mimic, this_object());
  }
  return;
}


id (str) {
  if (str=="mimic" || str=="chest" || str=="box") {
    mimic_react("mimic");
    return 1;
  }
  return (str=="trees" || str=="tree" ||
          str=="thornbushes" || str=="thornbush" ||
          str=="bushes" || str=="bush" ||
          str=="thorns" || str=="thorn");
}
