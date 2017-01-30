short() { return "A shining quartz"; }

reset(arg) {
    if (arg)
        return;
}

query_weight() {
    return 1;
}

long() {
     write("This is a magical quartz. You can summon the shadows with it!\n");
    return 1;
}

id(str) {
    return str == "quartz";
}

query_value() {
    return 0;
}

get() {
    return 1;
}

