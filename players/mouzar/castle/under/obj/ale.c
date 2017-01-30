id(str) { return str == "ale"; }
long() { write("Ale brewed Duergar style!\n"); }
short() { return "An ale"; }
init() {
    add_action("drink","drink");
    return 1;
}
drink(arg) {
    if (arg != "ale") {  return 0; }
    say(this_player()->query_name() + " drinks an ale.\n");
    write("You drink the ale down.\n");
    call_other(this_player(),"heal_self",30);
    this_player()->add_intoxication(15);
    destruct(this_object());
    return 1;
}
get() { return 1; }
query_weight() { return 1; }
query_value() { return 600; }
drop() { return 0; }
 
