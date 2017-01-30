string name;

id(str) {
    return str == "eye" || str == "eye of " + lower_case(name) ||
    str == "necro_eye" || str == "necro_comp" || str == "eye of "+name;
}

query_eye() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "An eye removed from a skull"; }
long() {
write("An eye taken from an uncaring corpse.\n"+
      "This is the eye of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }

