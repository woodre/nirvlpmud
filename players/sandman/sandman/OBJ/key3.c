id(str) { return str == "key" || str == "rusty key"; }

short() {
   return "A rusty key";
}

long() {
   write("A rusty old key, it looks to be ancient.\n");
}

query_weight() {
   return 1;
}

query_value() {
   return 300;
}

get() {
   return 1;
}
