id(str) { return str == "table" || str == "worktable"; }
reset() {}
short() {return "A large worktable";}
get() {return 0;}
query_weight() { return 1;}
query_value() {return 0;}
long() {write("     This table is made entirely of obsidian.  It was dragged from the depths\n"+
              "of the sea after the fall of Istar.  It is over seven feet long and is covered\n"+
              "with runes and sigils that catch your eye.  The surface is clean of any debris\n"+
              "that you can see.\n");}
init() {
        add_action("heat","heat");
}
heat() {
        write("You feel the temperature of the room rise several degrees.\n");
return 1;
}
