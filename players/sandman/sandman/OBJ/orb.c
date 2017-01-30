id(str) { return str == "orb" || str == "ebony orb"; }

short() {
   return "An Ebony Orb";
}

long() {
   write("A pulsing ebony orb, exuding evil!\n");
}

query_weight() {
   return 1;
}

query_value() {
   return 1000;
}

get() {
   return 1;
}
