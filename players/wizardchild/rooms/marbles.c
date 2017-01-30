inherit "room/room.c";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME marble shop";
    long_desc = 
        "This is the ACME marble shop. Here you can 'buy <item>,'\n" 
        + "'info', or 'list'. East goes back to the plaza.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/acme2.c", "east",
        });
}
init() {
        add_action("list", "list");
        add_action("buy", "buy");
        add_action("info", "info");
        ::init();
}
info() {
        write("Ok, here is an explanation of our stock.\n");
        write("The marbles are for playing with, or if you got the right\n");
        write("stuff, you can shoot 'em. The clip extender is what it says,\n");
        write("a clip extender. It lets you load 20 extra marbles into your clip.\n");
        write("But, as they say, shit happens, and we are all out of extenders.\n");
        return 1;
}
list() {
        write("Currently available:\n");
        write("Item:                    Cost:\n");
        write("bag of marbles (30)      1500\n");
        write("big bag of marbles (50)  2250 (NOT AVAILABLE)\n");
        write("clip extender (20)       2500 (NOT AVAILABLE)\n");
        return 1;
}
buy(st) {
        object ob;
        if(!st || st == "") return 0;
        if(st != "bag" && st != "bag of marbles") return 0;
        if(st == "bag" || st == "bag of marbles") {
                if(this_player()->query_money() < 1500) {
                        write("Check your cash, man, you don't got 1500.\n");
                        return 1;
                } else {
                        write("You buy a bag of marbles.\n");
                        say(this_player()->query_name() + " buys something.\n");
                        this_player()->add_money(-1500);
                        ob = clone_object("/players/wizardchild/objects/bm30.c");
                        move_object(ob, this_player());
                        return 1;
                }
        }
}
