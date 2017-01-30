/*
  e_forest0.c
*/

#define TP this_player()
inherit "room/room";

realm() { return "NT"; }

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="A dimly lit forest";
  long_desc="You are in part of a dimly lit forest.  The entrance to a\n"+
            "restaurant is to the west.  An entrance to the mines is to\n"+
            "the east.\n";
  items=({
    "forest", "It is full of trees",
    "trees", "They are mostly oak",
    "tree", "This one seems to be a sturdy redwood",
    "trails", "They seem to be somewhat clear paths between the trees",
    "trail", "It seems to be a somewhat clear path between the trees",
    "entrance", "An entrance to the mines cut into solid granite",
  });
  dest_dir=({
            "players/nooneelse/entryforest/e_forest1", "north",
            "room/mine/tunnel_room", "east",
    "/players/eurale/VAMPIRES/RMS/souvenir_shop.c","west",
          });
  if (!present("onyx pillar",
               find_object("/players/nooneelse/entryforest/e_forest0")))
    move_object(clone_object("/players/nooneelse/obj/onyx_pillar"),
                "/players/nooneelse/entryforest/e_forest0");
  if (!present("onyx pillar", this_object()))
    move_object(clone_object("/players/nooneelse/obj/onyx_pillar"),
                this_object());
}

init() {
  ::init();
  add_action("east", "east");
}

east() {
  write("You walk slowly into the dark tunnel in the mountain.\n");
  say(this_player()->query_name()+" walks slowly into the dark tunnel.\n",
      this_player());
  return 0;
}
