id(str) { return str == "crown"; }

reset() {}

long() { write("You have a jewel encrusted crown.\n"); }

short() { return "A golden Crown"; }

init() {
   add_action("give","give");
   add_action("drop","drop");
}

drop(arg) {
    if (arg=="crown") {
     return write("You seem to love this crown so much that you wont let it go!\n");
        return 1;
    } else {
 return write("Something seems to be keeping you from doing this!\n");
    }
}
give(arg) {
    if (arg=="crown") {
  return write("You will never give this precious item up!\n");
   } else {
 return write("Something seems to be keeping you from doing this!\n");
   }
}

get() { return 1; }

query_weight() { return 6; }

query_value() { return 1000; }

