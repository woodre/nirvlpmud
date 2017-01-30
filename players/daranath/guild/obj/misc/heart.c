string name;

id(str) {
    return str == "heart" || str == "heart of " + lower_case(name) ||
    str == "necro_heart" || str == "necro_comp" || str == "heart of "+name;
}

query_heart() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "A heart torn from an unfortunate victim"; }
long() {
write("A heart torn from the chest cavity of some victim.\n"+
      "This is the heart of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }

