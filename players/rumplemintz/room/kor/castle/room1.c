inherit "room/room";
id(str) { return str == "castle"; }
init() {
   ::init();
        add_action("enter"); add_verb("enter");
}
enter(str) {
        if (!id(str))
        return 0;
        write("The castle is not open yet, try back later.\n");
        return 1;
}
reset(arg) {
        if(!arg) {
                set_light(1);
        short_desc = "Entrance Lane to Kor, the Orc Lord's castle";
        long_desc = "You stand at the end of a Lane to Kor's castle.  It is a rather\n"+
                "ugly looking castle, but it serves it's purpose i'm sure.\n";

        dest_dir = ({
                "players/rumplemintz/room/kor/room20", "northeast",
                "players/rumplemintz/room/kor/room21", "southeast",
                });
        items = ({
                "castle", "It is a most exquisite piece of art work."
                });
        }
}
