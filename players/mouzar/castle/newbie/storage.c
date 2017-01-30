 
inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    set_light(1);
    short_desc = "A small storage room";
    no_castle_flag = 1;
    long_desc = 
        "You are in a small storage room where the Halflings have stored\n" +
        "their most prized possession.  To the east you see the shop.\n";
    dest_dir = ({"players/mouzar/castle/newbie/shop", "east"});
}
 
init(arg)
{
        object  ob;
        int     does_exist;
 
        if(this_player()) {
                if(
                        !present("tech_quicktyper", this_player())
                        &&
                        !present("tech_quicktyper", this_object())
                ) {
                        /* it does no exist */
                        ob = clone_object("obj/quicktyper");
                        move_object(ob, this_object());
                }
        }
        ::init(arg);
}
