id(str) { return str == "cake"; }
reset() {}
long() { write("A slice of Mouzar & Brittany's wedding cake.\n"); }
short() { return "Slice of cake"; }
init() {
    add_action("eat","eat");
    return 1;
}
eat(arg) {
    if (arg != "cake" || arg != "slice") {  return 0; }
    say(this_player()->query_name() + " eats a slice of Wedding cake.\n");
    write("You eat your slice of cake and what a wonderful cake it is.\n");
    this_player()->add_stuffed(5);
    destruct(this_object());
    return 1;
}
get() { return 1; }
query_weight() { return 1; }
drop() { return 0; }

