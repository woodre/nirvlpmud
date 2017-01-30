
id(str) { return str == "fountain"; }

int full;

reset(arg) {
     if(!arg) 
       full = 6;
}

init() {
     add_action("drink","drink");
}

drink(str) {
     if(!str) {
       write("Drink from what?\n");
       return 1;
     }
     if(str == "from fountain" || str == "water") {
       if(full == 0) {
         write("The fountain seems to be drained right now.\n");
         write("Come back later after someone fills it up.\n");
         return 1;
       }
       call_other(this_player(), "heal_self", 5);
       write("You feel much better!\n");
       say(capitalize(this_player()->query_name())+" drinks from the fountain.\n");
       full = full - 1;
       return 1;
     }
}

short() { return "A large marble fountain"; }

long() {
     write("This is a large marble fountain.  In the center resting on\n");
     write("a pedastal is a statue of a lifesize mermaid.\n");
     if(full > 0) {
       write("The water in the fountain shimmers in the sunlight.\n");
     }
}

