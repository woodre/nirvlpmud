
inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A small storage room";
    no_castle_flag = 1;
    long_desc = 
        "You are in a small and dusty storage room.\n" +
            "You can see the shop through the opening to the east.\n";
    dest_dir = ({"/players/catwoman/THIEF/t1", "east"});
}

init(arg)
{
 
        object  ob;
        int     does_exist;

        if(this_player()) {
                if(
                        !present("shop", this_player())
                        &&
                        !present("shop", this_object())
                ) {
                        /* it does no exist */
                        ob = clone_object("/players/catwoman/obj/menut.c");
                        move_object(ob, this_object());
                }
        }
         ::init(arg);
}

realm() {return "NT";}

