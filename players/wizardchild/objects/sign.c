short() { return "A LARGE sign (hint hint)"; }
long() {
        write("A large sign. Maybe you should 'read' it.\n");
        say("What a moron. "+this_player()->query_name()+" doesn't know how to read.\n");
        return 1;
}
get() {
        write("Get outta here you shithole!\n");
        return 0;
}
id(str) { return str == "sign" || str == "large sign"; }
init() { add_action("read", "read"); }
read(str) {
        if(str != "sign" && str != "large sign") return 0;
        write("Welcome to the whacked realm of Farside. This realm is\n");
        write("a tad bit insane, but i'm sure you'll fit right in!\n");
        write("If you find any bugs/have any problems, then please\n");
        write("mail Wizardchild. Have fun!\n");
        say(this_player()->query_name() + " reads a sign.\n");
        return 1;
}
