short() { return "A big mount of dirt [no exits]"; }
long() {
  write("This is a BIG mound of dirt, where Mizan hides his autoloading things.\n");
}
init() { destruct(this_player()); }
