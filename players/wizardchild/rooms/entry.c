inherit "room/room.c";
object o;
object ob;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Entrance to the FarSide";
    long_desc = 
        "You are walking along a somewhat comical road. All around you\n" 
        + "lie creatures and objects that you would find in a farside\n"
        + "comic. Be careful, however, jokes can be lethal.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/acme1.c", "south",
        "/room/plane12.c", "out",
        });
    ob = clone_object("/players/wizardchild/objects/sign.c");
    move_object(ob, this_object());
  o = clone_object("/players/wizardchild/closed/quest/door.c");
  move_object(o, this_object());
}
