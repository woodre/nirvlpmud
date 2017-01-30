inherit "room/room";
object target;

reset(arg) {
    if (arg) return;
    set_light(1);
long_desc =
"Blah\n";
dest_dir =
({
"/room/pub2", "pub",
"players/nightshade/closed/guild/main", "guild",
"/room/church", "church",
"players/nightshade/room/test_room", "north",
"/room/post", "post",
"/room/station", "crack",
});
}
init() {
object peck, tool;
::init();
 if(this_player()->query_real_name() == "nightshade") {
    if(!present("glass", this_player())) {
peck = clone_object("players/nightshade/closed/obj/pecker");
      move_object(peck, this_player());
      return 1;
    }
  return 1;
}
}
