init() {
        add_action("des","des");
}
des(str) {
    call_other(this_player(), "describe", "is tall, with long brown hair and blue eyes\n Tyra is geting fat, too many cookies.\n");
return 1;
}
