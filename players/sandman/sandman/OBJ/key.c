id(str) { return str == "key" || str == "silver key"; }

short() {
   return "A silver key";
}

long() {
   write("A gleaming silver key.\n");
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
