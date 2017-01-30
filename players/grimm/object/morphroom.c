inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "holding bin";
    no_castle_flag = 0;
    long_desc = 
        "Holding Bin.\n";
    dest_dir = 
        ({
    "" 
        });
}

monflag() {
   if(present("morph")) return 1;
return 0;
}
realm() {
    return "NT";
}
