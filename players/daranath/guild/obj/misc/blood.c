string name;

id(str) {
    return str == "blood" || str == "blood of " + lower_case(name) ||
    str == "necro_blood" || str == "necro_comp" ||
    str == "blood of "+name || str == "vial" || str == "vial of blood";
}

query_blood() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "an unknown victim";
}

set_name(n){ name = n; }

short() {return "A small vial of dark red blood"; }
long() {
write("A small glass vial of dark red blood.\n"+
      "This is the blood of "+name+".\n");
}
get() { return 1; }
query_weight() { return 1; }

