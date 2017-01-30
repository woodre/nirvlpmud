
int folded, placed;

reset() {
     folded = 1;
     placed = 0;
}

query_placed() { return placed; }

id(str) { return str == "boat" || str == "folding boat"; }

short() {
     if(folded == 1) {
       return "A folding boat (folded)";
     } else
     return "A folding boat (unfolded)";
}

long() { 
     write("A boat which you can place in water and sail.  It can be\n");
     write("folded and unfolded for ease of transportation.\n");
}

get() {
     if(folded == 1) {
       return 1;
     } else
     return 0;
}

query_value() { return 500; }

query_weight() { return 2; }

init() {
     add_action("fold","fold");
     add_action("unfold","unfold");
     add_action("place","place");
}

fold(str) {
     string me;
     me = this_player()->query_name();

     if(!str) {
       write("Fold what?\n");
       return 1;
     }
     if(str == "boat" || str == "folding boat") {
       if(folded == 1) {
         write("The boat is already folded.\n");
         return 1;
       }
       write("You fold up the boat.\n");
       say(capitalize(me)+" folds up the boat.\n");
       folded = 1;
       placed = 0;
       return 1;
     }
}

unfold(str) {
     string me;
     me = this_player()->query_name();

     if(!str) {
       write("Unfold what?\n");
       return 1;
     }
     if(str == "boat" || str == "folding boat") {
       if(!present("boat", this_player())) {
         write("You must have the boat to unfold it.\n");
         return 1;
       }
       if(folded == 0) {
         write("The boat is not folded!\n");
         return 1;
       }
       write("You drop the boat and unfold it.\n");
       say(capitalize(me)+" drops and unfolds the boat.\n");
       folded = 0;
       command("drop boat", this_player());
       return 1;
     }
}

place(str) {
     string me;
     me = this_player()->query_name();

     if(!str) {
       write("Place what?\n");
       return 1;
     }
     if(str == "boat" || str == "boat in water" ||
        str == "folding boat" || str == "folding boat in water") {
       if(folded == 1) {
         write("You must unfold the boat before you can place it.\n");
         return 1;
       }
       if(placed == 1) {
         write("The boat has already been placed.\n");
         return 1;
       }
       write("You place the boat.\n");
       say(capitalize(me)+" places the boat.\n");
       placed = 1;
       return 1;
     }
}
