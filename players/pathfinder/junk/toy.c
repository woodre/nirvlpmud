inherit "/obj/armor";
id(str) { return str == "notarmor" || str == "toy"; }
short() { return "toy"; }
long() { write("this is a toy.\n"); }
init() {
  this_player()->set_ac(30);
}
