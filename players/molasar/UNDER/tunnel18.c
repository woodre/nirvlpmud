
int passage;

reset(arg) {
     if(!arg)
       set_light(0);
       passage = 0;
}

query_passage() { return passage; }

init() {
     add_action("west","west");
     add_action("south","south");
}

west() {
     call_other(this_player(),"move_player",
                    "west#players/molasar/UNDER/tunnel17");
     return 1;
}

south() {
     if(passage == 1) {
       write("There is a big hole in the floor! You can't go that way.\n");
       return 1;
     }
     if((call_other("players/molasar/UNDER/tunnel15","query_mech1") == 1) &&
        (call_other("players/molasar/UNDER/tunnel15","query_mech2") == 0) &&
        (call_other("players/molasar/UNDER/tunnel15","query_mech3") == 1) &&
        (call_other("players/molasar/UNDER/tunnel15","query_mech4") == 1)) {
     call_other(this_player(),"move_player",
                    "south#players/molasar/UNDER/tunnel19");
     return 1;
     }
     say(capitalize(this_player()->query_name())+" walks south and barely "+
        "misses falling into a pit that opens up behind him.\n");
     write("As you go south the floor collapses behind you.\n");
     passage = 1;
     call_other(this_player(),"move_player",
                    "south#players/molasar/UNDER/tunnel19");
     return 1;
}

short() { return "A sharp turn in the tunnel"; }

long() {
      if(passage == 0) {
        write("This is a sharp turn in the direction of the tunnel.  Looking\n");
        write("at the floor you notice many strange marks running across it.\n");
        write("   There are two obvious exits:  south and west\n");
        return 1;
      } else
      write("You have reached a sharp turn in the tunnel.  A huge hole lies\n");
      write("lies in the middle of the room preventing any passage south.\n");
      write("   There is one obvious exit:  west\n");
}

