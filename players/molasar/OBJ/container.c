
id(str) { return str == "bottle" || str == "empty bottle"; }

get() { return 1; }

query_value() { return 5; }

short() { return "An empty bottle"; }

long() {
   write("An empty bottle.\n");
}

