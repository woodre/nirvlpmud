id(str) { return str == "board" || str == "circuitry board"; }

reset(arg) {
  if(arg) return;
}

short() {
  return "A circuitry board";
}

long() {
   write(
    "This board looks like a computer board, but it is only about 5\n"+
    "centimeters long and 3 centimeters wide.  It has all of the standard\n"+
    "wiring of a circuitry board, but the hardware interface is not one\n"+
    "that you can recognize.  Whatever this board controls, it is something\n"+
    "that is very non-standard.\n");
   return 1;
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 2000; }
