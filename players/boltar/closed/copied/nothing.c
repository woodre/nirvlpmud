init() {
    add_action("none");add_xverb("");
}

short() {
    return "nothing";
}

long() {
    write("nothing important.\n");
}

id(str) {
    return str == "nothing";
}

get(str) {
    return 1;
}

none() {
    tell_object(this_player(),"Nope.\n");
    return 1;
}

reset(arg) {
    if (arg)
        return;
    call_out("done",15);
}

done() {
    destruct(this_object());
    return 1;
}
