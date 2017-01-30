id(str) { return str == "potion"; }
short() { return "A Potion of Minor Healing"; }
long() { write("It looks pretty vile tasting.\n");
return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 750; }
init() {
add_action("drink","drink");
}

drink() {
say(this_player()->query_name() + " drinks a potion of minor healing.\n");
write("You drink a potion of minor healing.\n");
this_player()->heal_self(15);
destruct(this_object());
return 1;
}
