id(str) { return str == "symbol" || str == "holy symbol"; }

short() {
   return "A holy symbol";
}

long() {
write("A holy symbol, the bronze interlocking circles are the mark of the\n");
   write("of the prophet.\n");
}

query_weight() {
   return 1;
}

query_value() {
   return 200;
}

get() {
   return 1;
}
