/*
  private_room.c
*/

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "nooneelse's private room";
    long_desc =
"This is NoOneElse's private contemplation room (how did you get here?).\n" +
"I come here to rest and contemplate the whichness of the why.  Right now\n" +
"everything seems to be upside down.  Or is it you that's upside down?\n" +
"\n";
    dest_dir = ({
                 "room/church",                "church",
                 "room/adv_guild",             "guild",
                 "room/post",                  "post",
                 "room/shop",                  "shop",
                 "players/nooneelse/workroom", "work",
                 });
}

init() {
    ::init();

    if ((lower_case(this_player()->query_real_name())=="nooneelse") ||
        this_object()->id()=="nooneelse_ring") return 1;
    forbid();
}

forbid() {
    write("A huge hand appears and blocks your way!\n" +
          "It pushes you out to the front room.\n" +
          "You hear a booming voice echo through the room saying:\n" +
          "'You are not permitted in there.'\n");
    move_object(this_player(), "players/nooneelse/workroom");
    tell_room("players/nooneelse/private_room",
              this_player()->query_real_name()+
              "tried to enter the private room.\n");
    return 1;
}
