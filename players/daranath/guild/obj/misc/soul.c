string name;

id(str) {
    return str == "soul" || str == "soul of " + lower_case(name) ||
    str == "necro_soul" || str == "necro_comp" ||
    str == "soul of "+name || str == "crystal" || str == "glowing crystal";
}

query_soul() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "A small glowing crystal"; }
long() {
write("A small crystal holding the soul of some victim.\n"+
      "This is the captured soul of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }

