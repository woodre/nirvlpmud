/*
 ballroom.c
*/


inherit "room/room";


reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "ballroom";
    no_castle_flag = 0;
    long_desc =
        "The floor of this huge room is bare, except for a few couches\n"
        + "against the walls.  There are large crystal chandeliers hanging\n"
        + "from several places on the ceiling.\n";
    items =
        ({
          "chandelier", "It is a large, crystal chandelier.",
          "chandeliers", "They are large, crystal chandeliers.",
          "couches", "Old, overstuffed sitting couches.",
          "couch", "Old, overstuffed sitting couches.",
        });
    dest_dir =
        ({
          "players/nooneelse/red/kitchen", "north",
          "players/nooneelse/red/sunroom", "south",
          "players/nooneelse/red/dining", "east"
        });
}

query_long() { return long_desc; }

query_light() { return 1; }
