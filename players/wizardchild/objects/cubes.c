int hp;
short() {
        return "Some sugar cubes";
}
long() {
        write("A few sugar cubes. You could possibly eat them...\n");
        return 1;
}
get() { return 1; }
drop() { return 0; }
query_value() { return 600; }
id(str) { return str == "cubes" || str == "sugar" || str == "sugar cubes"; }
init() {
        add_action("eat", "eat");
}
eat(str) {
        if(str != "cubes" && str != "sugar" && str != "sugar cubes") return 0;
        write("As you eat the cubes, you go on a sugar high. You feel stronger.\n");
        call_other(this_player(), "heal_self", 20);        
        say(this_player()->query_name() + " gets high on sugar.\n");
        destruct(this_object());
        return 1;
}
