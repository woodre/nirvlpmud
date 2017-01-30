string name;

id(str) {
    return str == "skin" || str == "skin of " + lower_case(name) ||
    str == "necro_skin" || str == "necro_comp" ||
    str == "skin of "+name || str == "patch" || str == "patch of skin";
}

query_skin() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "A small patch of skin"; }
long() {
write("A small patch of skin removed from a corpse.\n"+
      "This is the skin of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }

