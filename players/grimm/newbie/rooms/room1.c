inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The entrance";
    long_desc = 
        "The entrance to the newbie killing grounds.\n";
    dest_dir = 
        ({
         "players/grimm/newbie/rooms/entrance","north",
         "players/grimm/newbie/rooms/room3","south"
       });
}
