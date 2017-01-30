#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("aizenmyoo")) {
    move_object(clone_object("/players/mythos/amon/forest/aizen.c"),this_object());
  }
  if(!arg) {
  set_light(0);
    short_desc = "Tower Hidden";
    long_desc =
    "You have entered the room which connects to the Temple of Bishamon.\n"+
    "To protect this realm from entrances from the Temple, Aizen-myoo\n"+
    "stands ready.  Through the mirror can be seen the Temple.\n";
  items = ({
    "mirror","This mirror shows the reflection of Paulasx's realm- The Bishamon Temple",
    "back","The wall will slide back to allow you to go back",
  });

  dest_dir = ({
  "/players/paulasx/temple/temple_entrance.c","mirror",
  "/players/mythos/aroom/forest/tower2.c","back",
  });
}}
realm() {return "NT";}

init() {
  ::init();
  this_player()->set_fight_area();
}

exit(ob) { if(ob) ob->clear_fight_area(); }
