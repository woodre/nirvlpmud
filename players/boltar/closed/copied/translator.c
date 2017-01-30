id(str) {
    return str == "translator";
}

short() {
    return 0;
}

long() {
    write("a language translator\n");
}

get() {
    return 1;
}

drop(str) {
    if (str == "all")
        destruct(this_object());
    if (!id(str))
        return 0;
    return 1;
}

init() {
    add_action("new_say","say");
    add_action("new_say");add_xverb("'");
}

new_say(str) {
    int i;
    string rts;

    if (!str)
        return 1;
    i = strlen(str);
    write("You say: ");
    say(this_player()->query_name() + " says: ");
    while (i>=0) {
        write(extract(str,i,i));
        say(extract(str,i,i));
        i -= 1;
    }
    write("\n");
    say("\n");
    return 1;
}
