short() {
    return "Ring Room";
}

reset(arg) {
    if (arg)
	return;
    set_light(1);
}

init() {
    add_action("quit","quit");
}

quit() { return 1; }

realm() {return "NT";}
