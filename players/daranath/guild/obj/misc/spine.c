string name;

id(str) {
    return str == "spine" || str == "spine of " + lower_case(name) ||
    str == "necro_spine" || str == "necro_comp" ||
    str == "spine of "+name || str == "spinal column";
}
reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "A severed spinal column"; }
long() {
write("A severed spinal column removed from a corpse.\n"+
      "This is the spine of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }
query_spine() { return "daranath"; }
