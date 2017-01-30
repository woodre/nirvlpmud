id(str) { return str == "manual"; }

init() {
   add_action("read","read");
}

get() { return 1; }

drop(str) {
   if(str == "manual") {
      destruct(this_object());
      return 1;
   }
}

query_value() { return 0; }

short() { return "A pet manual"; }

long() {
   write("pets have the following commands:\n\n"+
        "-> fight <thing>\n"+
        "-> menace <thing>\n"+
        "-> guard\n"+
        "-> heel\n"+
        "-> name <name>\n");
   return 1;
}

read(str) {
   if (id(str)) long(); return 1; }
