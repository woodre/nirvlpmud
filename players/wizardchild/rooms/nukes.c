inherit "room/room.c";
int i;
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "ACME nuclear handgrenade shop";
    long_desc = 
        "This is ACME's famous Nuclear Handgrenade shop. As you can imagine,\n" 
        + "these items are a hot commodity. This forces their prices to be high.\n"
        + "Commands are: 'buy <item>', 'info', or 'list'.\n";
    dest_dir = 
        ({
        "/players/wizardchild/rooms/acme2.c", "west",
        });
}
init() {
        add_action("info", "info");
        add_action("list", "list");
        add_action("buy", "buy");
        ::init();
}
info() {
        write("This shop is fairly straight forward. We carry two items.\n");
        write("A light nuclear handgrenade (not available), and a heavy one.\n");
        write("Be warned, they have 'strange' side effects...\n");
        return 1;
}
list() {
        write("Items Currently Available:\n");
        write("Item:                    Cost:\n");
        write("heavy handgrenade        6000\n");
        return 1;
}
buy(st) {
        object ob;
        if(st != "heavy handgrenade" && st != "heavy") return 0;
        if(st == "heavy handgrenade" || st == "heavy") {
		if(this_player()->query_money() < 6000) {
		   write("Check your cash, man, you don't got 6000\n");
                        return 1;
                } else {
                        if(i > 4) {
                                write("Sorry, guy, we are sold out today.\n");
                                return 1;
                        } else {
                                write("Use it carefully man...\n");
                                say(this_player()->query_name() + " buys something.\n");
				this_player()->add_money(-6000);
                                i += 1;
                                ob = clone_object("/players/wizardchild/objects/hnuke.c");
                                move_object(ob, this_player());
                                return 1;
                        }
                }
        }
}
