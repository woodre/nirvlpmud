inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("sentry")) {
move_object(clone_object("players/cyrex/sentry"), this_object());
}
set_light(1);
short_desc = "Mechanical Passageway";
long_desc = "    As you continue down the corridor, you notice the space\n"+
            "between you and the walls are getting smaller.  It seems you\n"+
            "are now in a small passageway.  You see all aroud pipes and \n"+
            "boilers blowing off steam.  All around you everything is hazy\n"+
            "and blurred.  You desperately swing your arms in front of you\n"+
            "to try and see...you suddenly hit your head on a dangling pipe\n"+
            "and fall backwards only to get up and find yourself face to\n"+
            "face with a......\n\n";
dest_dir = ({"players/cyrex/corridor", "west",
 "players/cyrex/rhquarters", "north",
 "players/cyrex/conference", "south",
 "players/cyrex/barrier", "east",
});
}
