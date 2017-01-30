/******************************************
|  "corpse" object for "immortal" monsters
|  will enable players to loot it, but not
|  allow them to destroy it
******************************************/
inherit "obj/clean";
string name;

id(str) { return str == "body" || str == "ill_imm_body"; }

short() { return "The body of "+(name?name:"an unknown man"); }

long() {
  write(
    "The dead, battered body of "+(name?name:"an unknown man")+
    ".  Despite the fact that this\nbody is obviously dead, it doesn't "+
    "seem to be affected by any kind of decay.\n");
}
query_weight() { return 8; }

query_name() { return name; }
set_name(string n) { return (name=n); }
get() {
  write("The body seems to resist being moved.\n");
  return 0;
}
query_info() {
  return "The body has an intense magical aura, preventing it from being\n"+
         "moved, or even damaged any more.\n";
}
