/*
  g_path_cryptw_lower.c
*/

inherit "room/room";

string str;
int icon_is_placed;

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(0);
  short_desc="Lower room in a crypt";
  items=({
          "stairs", "Stairs carved out of solid granite, leading up",
        });
  dest_dir=({
             "players/nooneelse/graveyard/g_path_cryptw_stairs", "up",
           });
}

long() {
  if (icon_is_placed)
    write("You are in a lower room of a dark crypt.  There is a small\n"+
          "pedestal in the center of the room with a gold icon on it.\n");
  else
    write("You are in a lower room of a dark crypt.  There is a small,\n"+
          "empty, pedestal in the center of the room.\n");
}

init() {
  ::init();

  add_action("look_at_pedestal", "look");
  add_action("look_at_pedestal", "examine");
  add_action("place_icon",       "put");
  add_action("place_icon",       "place");
  add_action("place_icon",       "set");
  add_action("place_icon",       "sit");
  add_action("take_icon",        "get");
  add_action("take_icon",        "take");
}

look_at_pedestal(str) {
  string str2;
  if (!str) return 0;
  str2=0;
  sscanf(str, "at %s", str2);
  if (str != "pedestal" && str2 != "pedestal") return 0;
  if (icon_is_placed) {
    write("It is carved from dark granite, about 4' tall.  There is a small\n"+
          "gold icon sitting on it.\n");
  }
  else {
    write("It is carved from dark granite, about 4' tall.\n");
  }
  return 1;
}

place_icon(str) {
  string str2;
  object icon_obj;
  if (!str) return 0;
  sscanf(str, "icon %s", str2);
  if (!str2 || str2 != "on pedestal") return 0;
  icon_obj=present("nooneelseicon", this_player());
  if (!icon_obj) {
    write("But, you don't have an icon.\n");
    return 1;
  }
  icon_is_placed=1;
  destruct(icon_obj);
  return 1;
}

take_icon(str) {
  if (!str || str != "icon" || !icon_is_placed) return 0;
  write("You can't move the icon.  It seems to be held by some magic.\n");
  return 1;
}

query_icon() { return icon_is_placed; }
