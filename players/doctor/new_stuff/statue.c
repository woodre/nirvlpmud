string long_desc;
string player;
object ob, dest;
int len;

short() {
    return ("Statue");
}

long() {
    write(long_desc);
}

id(str) {
    return (str == "statue");
}

get() {
    return 0;
}

init() {
    add_action("no","quit");
    add_action("no","goto");
    add_action("no","home");
}

no() {
    if (environment(this_player()) == this_object()) {
        write("Sorry.\n");
        return 1;
    }
    return 0;
}

set_len(c) {
    len = c;
}

set_desc(str) {
    long_desc = "This is a statue of " + str + ".\n";
    player = lower_case(str);
    call_out("done",len);
}

done() {
    move_object(first_inventory(this_object()),environment(this_object()));
    say("The statue crumbles to dust.\n");
    destruct(this_object());
    return 1;
}

