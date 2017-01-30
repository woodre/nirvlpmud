/*
 study.c
*/

inherit "room/room";

int fire_is_out;
object glass_obj;
string long_desc_study, str, str2, str3, str4, str5, where, fire_msg;

init() {
  :: init();

  add_action("fire", "throw");
  add_action("fire", "pour");
  add_action("touch", "touch");
  add_action("touch", "put");
  add_action("touch", "place");
}

fire(str) {
  if (!str) {
    write("Throw what?\n");
    return 1;
  }
  where=0;
  sscanf(str, "water on %s", where);
  if (where=="fire") str="water";
  sscanf(str, "glass on %s", where);
  if (where=="fire") str="glass";
  if (str != "glass" && str != "water") return;
  if (!present("glass", this_player())) return;
  if (fire_is_out) {
    write("The fire is already out!\n");
    if (str=="water")
      write("As you pour water in the fireplace, you drop the glass "+
            "and it breaks.\n");
    if (str=="glass") write("The glass shatters in the fireplace.\n");
    say(this_player()->query_name()+" pours water in the fireplace.\n");
    return 1;
  }
  glass_obj=0;
  glass_obj=present("glass");
  if (glass_obj && !glass_obj->query_glass()) {
    write("The glass is empty.\n");
    return 1;
  }
  if (str=="water")
    write("As you put the fire out with the water, you drop the glass "+
          "and it breaks.\n");
  if (str=="glass")
    write("The glass shatters in the fireplace and the fire goes out.\n");
  say("As "+call_other(this_player(), "query_name")+
      " pours water on the fire, the glass drops and shatters.\n");
  fire_is_out = 1;
  fire_msg="The fireplace looks dark and cold.\n";
  long_desc=long_desc_study+fire_msg;
  if (str=="glass" || str=="water") {
    glass_obj=present("glass", this_player());
    destruct(glass_obj);
  }
  return 1;
}

touch(str) {
  if (!str) return;
  if (!fire_is_out) {
    write("What?  You would burn your hand!\n");
    return 1;
  }
  if (!present("nooneelseamulet", this_player())) {
    write("Touch what with what?\n");
    return 1;
  }
  sscanf(str, "amulet to %s", str2);
  sscanf(str, "amulet in %s", str3);
  sscanf(str, "%s with %s", str4, str5);
  if (str2 && str2=="indentation") {
    go_to_maze();
    return 1;
  }
  if (str3 && str3=="indentation") {
    go_to_maze();
    return 1;
  }
  if ((str4 && str5) && str4=="indentation" && str5=="amulet") {
    go_to_maze();
    return 1;
  }
}

reset (arg) {
  if (arg) return;

  set_light(1);
  no_castle_flag=1;
  short_desc=("study");
  fire_msg="There is a small cheerful fire in the fireplace.\n";
  long_desc_study=
    "This looks like a private study.  There is a large rosewood desk\n"+
    "with a burning crystal lamp on it and a comfortably padded chair\n"+
    "sitting in front of a wall of apparently empty bookshelves.\n";
  long_desc=long_desc_study+fire_msg;
  items =
    ({
      "desk", "It is a beautiful old rolltop desk.  All the drawers are empty.",
      "drawers", "All the drawers are empty.",
      "drawer", "The drawer is empty.",
      "chair", "A nice comfortable chair.",
      "bookshelves", "Unfortunately, they are empty.",
      "shelves", "Unfortunately, they are empty.",
      "shelf", "Unfortunately, it is empty.",
      "lamp", "It is made of fine-cut crystal.  It is fixed to the desk.",
      "fireplace",
        "On the back wall of the fireplace, you can see a rectangular\n"+
        "indentation approximately 2 inches across.",
      "fire", "On the back wall of the fireplace, you can see a rectangular\n"+
              "indentation approximately 2 inches across.",
      "indentation",
        "You can see a rectangular indentation approximately 2 inches across.",
  });
  dest_dir =
    ({
      "players/nooneelse/red/sunroom", "west",
      "players/nooneelse/red/library", "east",
    });
  fire_is_out = 0;
  return;
}

go_to_maze() {
    write("You feel yourself pulled into the fireplace and up.\n\n");
    say(call_other(this_player(), "query_name")+
        " floats into the fireplace and up out of sight.\n");
  move_object(this_player(), "players/nooneelse/red/maze_entrance");
  if (this_player()->query_brief())
    tell_object(this_player(), environment(this_player())->short()+"\n");
  else
    command("look", this_player());
    return 1;
}

look_at_fireplace(str) {
  if (!str) return;
  if (str != "fireplace") return;
  if (fire_is_out) {
    write("The wood in the fireplace is cold and wet.\n");
  }
  else {
    write("The wood in the fireplace is burning hotly.\n");
  }
  return 1;
}

id(str) {
  if (str=="fire" || str=="fireplace") {
    look_at_fireplace("fireplace");
    return 1;
  }
  return (str=="desk" ||
          str=="drawers" ||
          str=="drawer" ||
          str=="chair" ||
          str=="bookshelves" ||
          str=="shelves" ||
          str=="lamp" ||
          str=="indentation");
}
