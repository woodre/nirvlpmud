
inherit "room/room";

reset(arg) {
  if(!arg) {

    set_light(1);
    short_desc = "Virtual Reality";
    long_desc = "You have entered another area in the virtual world of elof.\n"+
             "Here you hope to find Keivjam.  When you do, KILL HIM\n"+
             "Not that it'll be easy, but if you don't the mud shall\n"+
             "lag to an unspeakable level.\n";

    dest_dir = ( {
            "players/lew/elof/vir_wrld4", "north",
            "players/lew/elof/vir_wrld2", "south",
            "players/lew/elof/vir_wrld8", "east",
              } );
    }
}
realm() { return "NT"; }
