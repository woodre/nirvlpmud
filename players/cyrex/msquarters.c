inherit "room/room";
reset(arg) {
if(arg) return;
if(!present("Maximillian Sterling")) {
move_object(clone_object("players/cyrex/max"), this_object());
}
set_light(1);
short_desc = "Maxmillian Sterling's Quarters";
long_desc = "    You have stumbled upon Maximillian's quarters.  He seems\n"+
            "surprised and annoyed at the same time.  You look around and\n"+
            "see a room full of inventions scattered everywhere.  You pick\n"+
            "up one of them and Max turns around and grins evilly.  You \n"+
            "know not to disturb him.\n\n";
dest_dir = ({"players/cyrex/chamber", "east",
});
}
