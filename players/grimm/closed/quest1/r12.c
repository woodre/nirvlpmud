inherit "room/room";
object paper;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Room 12";
    no_castle_flag = 0;
    paper();
    long_desc = 
        "Room 12.\n"
        + "This is one of the catacombs under the city. There is a mist in the\n"
        + "ajoining hallways that makes you feel like you are going in circles.\n";
    dest_dir = 
        ({
         "players/grimm/closed/quest1/r1", "east",
        });
}

paper() {
       paper = clone_object("players/grimm/object/paper4");
       move_object(paper, this_object());
     return 1;
      }

realm() { return "NT"; }
