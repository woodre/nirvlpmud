drop() {
        return 0;
}
get() {
        return 1;
}
short() {
        return "A halved coconut";
}
long() {
        write("A halved coconut. It looks like it would be good to imitate\n");
        write("the sound of a horse with.\n");
        return 1;
}
id(str) {
        return str == "coconut" || str == "halved coconut";
}
init() {
        add_action("imitate", "imitate");
}
imitate(blah) {
        if(!blah || blah != "horse") return 0;
        write("You fool everybody and make noises like a horse.\n");
        say("You hear " + call_other(this_player(), "query_name")+ " gallop on his horse.\n");
        return 1;
}
query_value() {
        return 150;
}
