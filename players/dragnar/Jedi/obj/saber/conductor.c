id(str) { return str == "conductor" || str == "superconductor"; }

reset(arg) {
  if(arg) return;
}

short() {
  return "A superconductor";
}

long() {
   write(
    "The conductor is very tiny, with only approximately 1 square centimeter\n"+
    "of surface area.  The material it is made of seems to be ceramic at first,\n"+
    "but on closer inspection actually is organic in nature.  Two wires\n"+
    "lead from one end of the conductor, but there is no indication as to its use.\n");
   return 1;
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 500; }
