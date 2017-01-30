/******************************************
This is the corpse for the zombies.  If the
player does not dispose of the corpse with
the magic charm, the corpse will repop a new
zombie.
******************************************/
inherit "obj/clean";
string name;

id(str) { return str == "body" || str == "zombie_corpse"; }

short(){ return "The body of a zombie"; }

long() {
   write(
      "The fallen body of a zombie.  The body looks motionless\n"+
      "and dead.  Liquid puss seeps from gashes in the flesh.\n");
}
query_weight() { return 8; }

query_name() { return name; }
set_name(string n) { return (name=n); }
get() {
   write("The body is too heavy.\n");
   return 0;
}
query_info() {
   return "The body has an intense magical aura, preventing it from being\n"+
   "moved, or even damaged any more.\n";
}
