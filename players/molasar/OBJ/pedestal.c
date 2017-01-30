
int found;
object rod;

reset(arg) {
     if(arg) return;
    found = 0;
}

id(str) { return str == "pedestal"; }

short() { return "A black marble pedestal"; }

long() {
    write("A perfectly rectangular pedestal made of the purest marble.\n");
    write("There is however a small irregularity near the bottom.\n");
}

init() {
    add_action("search","search");
    add_action("search","examine");
    add_action("search","exa");
}

search(str) {
     if(!str) {
       write("Search what?\n");
       return 1;
     }
     if(str == "pedestal") {
       if(found == 1) {
         write("You find nothing.\n");
         return 1;
       }
       write("You find a brass rod hidden in a secret compartment.\n");
       move_object(clone_object("players/molasar/TREASURE/brass_rod"),
                        this_player());
       found = 1;
       return 1;
     }
}

can_put_and_get() { return 1; }

