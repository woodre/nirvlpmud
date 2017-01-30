
inherit "room/room";

object button;

reset(arg) {
        if (!button) {
                button = clone_object("players/catwoman/obj/button");
                move_object(button, this_object());
        }

        if (arg) return;

        set_light(1);

        short_desc = "The study";

        long_desc = "I'm busy editing.  Shhhhhhh\n";

        dest_dir = ({
             "players/catwoman/garden", "garden",

                "room/shop", "shop",

                "players/catwoman/workroom", "north"

        });

}

init() {

        ::init();

        say(this_player()->query_name()+" trips on the wire and rings the bell.\n");

        write("You trip on a wire and hear a bell ring.\n");

}

