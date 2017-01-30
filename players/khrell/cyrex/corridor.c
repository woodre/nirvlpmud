inherit "room/room";
reset(arg) {
if(arg) return;
set_light(1);
short_desc = "Shipboard Corridor";
long_desc = "    A long corridor that seems to be damaged in some areas\n"+
            "and unpassable in certain directions.  You notice on the \n"+
            "ceiling numerous red flashing lights indicating the ship is in\n"+
            "red alert.  Your hear sirens going on in the distance and see\n"+
            "smoke filled rooms to the north and south.  You wonder if you\n"+
            "should dare move on further to investigate...\n\n";
dest_dir = ({"room/plane4", "out",
 "players/cyrex/waiting", "north",
 "players/cyrex/investigation", "south",
 "players/cyrex/passageway", "east",
 "players/cyrex/shaft", "down",
});
}
