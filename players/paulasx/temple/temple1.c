inherit "room/room";
reset(arg) {
  if (!arg){
    set_light(1);
    short_desc = "Temple of Bishamon entrance way";
    long_desc = 
"You are in the first leg of a long hallway leading towards the center of\n" +
"the Temple.  It is rather dark, however you are still able to see small\n" +
"figures to the north.  You are completely at a loss as to who or even what\n" +
"they might be.  Are you sure you want to experience this much evil?\n\n" +
"";
/* No shop! Molasar 4/30/94
"There is a BODYGUARD shop to the west!!!!!\n";
*/
    dest_dir = 
        ({
        "players/paulasx/temple/temple2", "north",
        "players/paulasx/temple/temple_entrance", "south",
        });
}
}

