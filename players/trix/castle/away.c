inherit "room/room";
 
reset(arg) {
    int cont;
    object clerk;
    if(arg) return;
    set_light(1);
    long_desc = "                          Yes, u're right, this is:\n" +
                "                              !THE AWAY ROOM!\n                  ";
    short_desc = "I'm Away, beep me if necessary";
    dest_dir = ({ "/players/trix/workroom","work"});
}

