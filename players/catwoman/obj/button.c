
inherit "obj/treasure";

reset(arg) {
        if(arg) {
                return;
        }

        set_id("button");
        set_alias("red button");
        set_short("a red button");
        set_long("This is a red button.  If you press it, it will destroy\n"+
                 "everything in the room other than players.\n");
        set_weight(1000);
        set_value(1);
}

init() {
        ::init();
        add_action("push", "push");
        add_action("push", "press");
}

push(str) {
        object ob, temp;
        int changed;

        if (str = "button") {
                changed = 1;
                while (changed) {
                        changed = 0;
                        ob = first_inventory(environment(this_object()));
                        while (ob) {
                                if (ob != this_object() && !query_ip_number(ob))
 {
                                        changed = 1;
                                        temp = ob;
                                }
                                else {
                                }
                                ob = next_inventory(ob);
                                if (temp) {
                                        destruct(temp);
                                }
                        }
                }
                write("Ok.\n");
                return 1;
        }
        return 0;
}

