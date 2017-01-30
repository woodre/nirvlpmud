inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Other side of the portal";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the other side of the portal.  You can hear a commotion\n"
 + "above you.  You can see a small hole here that you may be able to\n"
 + "climb up through.  To the south there is a passage that is filled\n"
 + "with a large cloud of dust.  And to the north you can see the gates\n"
 + "of another city.\n";
    dest_dir = 
        ({
         "room/forest1", "up",
         "players/grimm/rooms/enter1", "south",
       });
}
query_light() {
    return 1;
}
