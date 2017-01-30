inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A Black Road";
    no_castle_flag = 0;
    long_desc = 
"You are on the beginning of a very dark road.  The bushes from the sides of\n"
+"the road have grown thick enough that it is impossible to pass.  To the\n"
+"south you feel a tremendous evil looming towards you.\n";
    dest_dir = 
        ({
         "players/grimm/town/mainstreet_10", "west",
         "players/grimm/frst/path4","south",
        });
}

