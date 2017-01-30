string name;

id(str) {
    return str == "dust" || str == "dust of " + lower_case(name) ||
    str == "dust of "+name || str == "corpse dust" || str == "corpse dust of "+name;
}

query_dust() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "A pile of corpse dust"; }
long() {
write("A small pile of corpse dust left from a consumed corpse.\n"+
      "This is the corpse dust of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }

