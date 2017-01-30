get() {
    return 1;
}

drop() {
    return 1;
}

init() {
#ifndef __LDMUD__
    add_action("set_curse"); add_xverb("");
#else
    add_action("set_curse", "", 3);
#endif
}

set_curse(str) {
    string first, rest;
    
    sscanf(str,"%s %s",first,rest);
    add_action("curse",first);
}

curse() {
    write("You can't do that.\n");
    return 1;
}
