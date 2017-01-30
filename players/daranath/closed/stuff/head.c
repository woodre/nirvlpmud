string name;

id(str) {
    return str == "head" || str == "head of " + lower_case(name) ||
    str == "head of "+name;
}

query_head() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "noone";
}

set_name(n){ name = n; }

short() {
    return "The Head of " + capitalize(name);
}

long() {
    write("This is the head of " + capitalize(name) + ".\n");
}

get() { return 1; }

query_weight() { return 1; }