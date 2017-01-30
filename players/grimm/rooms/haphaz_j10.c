inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Bottom of the Crater";
    no_castle_flag = 0;
    long_desc = 
"You are standing at the bottom of a very large crater.  There are a few\n"
+"vines hanging down here that you may be able to climb.\n";
    dest_dir = 
        ({
         "players/grimm/rooms/haphaz_j11", "south",
         "players/grimm/rooms/haphaz_i11", "southwest",
         "players/grimm/rooms/haphaz_i10", "west"
        });
}
/*
climb(str) {
  if (str=="vine" || str=="vines") {
    this_player()->move_player("up the vines#players/grimm/forest/enter1");
    write("You climb up the vines and arrive in a dense forrest.\n");
     return 1;
    } else {
     write("What do you want to climb?\n");
     return 1;
    }
}
*/
