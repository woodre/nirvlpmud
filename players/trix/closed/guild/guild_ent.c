inherit "room/room";
 
reset(arg) {
    if(arg) return;
    set_light(1);
   long_desc = "You find yourself in a semidarkened place at the foot of the hill, the forest\n" +
               "starts just a few feet west of here while some stairs cut in the stone go\n" +
               "down the next to the river and disappear in the darkness.\n";
   short_desc = "A hidden corner of the realm";
    dest_dir = ({ "/players/gorgan/closed/guild/guild_adv_room.c","down",
                  "/players/trix/castle/town/mainroad5.c","east"});
}

