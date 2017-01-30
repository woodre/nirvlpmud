id(str) { return str == "lens" || str == "focal lens"; }

reset(arg) {
  if(arg) return;
}

short() {
  return "A lens";
}

long() {
   write(
    "This lens is made out of a high density material, but looks and feels\n"+
    "like glass.  It has a concave shape to it, and is roughly 4 centimeters\n"+
    "in diameter.  There is no apparent use for the lens that you can see, but\n"+
    "from the high level of quality of the material, it must be very\n"+
    "important for something.\n");
   return 1;
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 1200; }
