id(arg) {return arg=="fnord";}

init() {
    add_action("null","fnord");
    add_action("null","f");
}

null(arg) {return 1;}
