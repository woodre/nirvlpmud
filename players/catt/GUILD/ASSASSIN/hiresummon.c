#define TP this_player()
id(str) { return str == "crystal"; }
short() { return "A small black crystal"; }
long() {
       write("A small black crystal for summoning hirelings.\n");
       }
get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
init() {
    add_action("hire","hire");
       }

hire() {
  object hi;
   hi = clone_object("players/catt/GUILD/ASSASSIN/hireling");
hi->set_owner(TP);
write("Hireling hired.\n");
move_object(hi,environment(TP));
return 1;
}
