id(str) { return str == "manual" || str == "answer manual"; }

short() {
   return "A teacher's answer manual";
}

long() {
   write("This is the holy grail of all teachers. Without it a teacher is\n");
   write("just as smart as you or I.\n");
}

get() {
   return 1;
}

query_weight() {
   return 1;
}

query_value() {
   return 150;
}
