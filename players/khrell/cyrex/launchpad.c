inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("Veritech Fighter")) {
move_object(clone_object("players/cyrex/veritechb"), this_object());
}
set_light(1);
short_desc = "Launch Pad";
long_desc = "    You see in front of you an enormous robot!  You walk aorund\n"+
            "and around to see more of the details of this advanced tech.\n"+
            "You notice the wings of this veritech have been destroyed but\n"+
            "everything else seems to working.  There seems to be someone\n"+
            "sitting in the control pod but you can't make out who it is.\n"+
           "All you can think of is that it would not be wise to attack!\n\n";
dest_dir = ({"players/cyrex/cargobay", "south",
});
}
