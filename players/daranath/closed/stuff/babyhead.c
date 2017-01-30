string name;

id(str) {
    return str == "head" || str == "head of " + lower_case(name) ||
    str == "head of "+name;
}

query_head() { return "daranath"; }

reset(arg) { 
  if(arg) return;
  name = "baby";
}

set_name(n){ name = n; }

short() {
    return "The head of " + capitalize(name);
}

long() {
write("This is the head of "+capitalize(name)+".\n"+
      "Baby was a Paladin traitor and it looks like someone\n"+
      "finally caught up with his cowardly personage.\n"+
      "Justice is Served....\n");
}

get() { return 1; }

query_weight() { return 1; }

