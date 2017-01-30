#define tp this_player()->query_name()

int uses;

id(str) {
    if (str == "mead" || str == "bottle")
        return 1;
}

short() {
    if (uses)
    return "A bottle of Mead";
    return "A bottle of Mead (empty)";
}

is_heal() { return "intox"; }
query_potence() { return 40; }
query_save_flag()  { return 1; }
query_dest_flag() {
   if(!uses) return 1;
   return 0;
}

query_value() {
   if (!uses) return 5;
   else return uses*400;
}

long() {
   write("A bottle of golden mead, the drink of kings,\n"+
     "delicious and alcoholic. Sip or drink the mead for health.\n"+
     "The bottle looks to be about "+uses+"/4 full.\n");
}

reset(arg) {
   if (arg) return;
   uses=4;
}



drink(str) {
   if (str && id(str)) {
      if(!uses) {
         notify_fail("The bottle of mead is empty.\n");
         return 0;
      }
      if (!call_other(this_player(), "drink_alcohol", 16)) return 0;
      write("The mead goes down smoothly.\n");
      say(tp+" "+query_verb()+"s some mead.\n");
      uses--;
      call_other(this_player(), "heal_self", 40);
      if (!uses) {
      write("You drink all of the mead.\n");
      }
      return 1;
   }
}

init() {
   add_action("drink","drink");
   add_action("drink","sip");
}

get() { return 1; }

query_weight() { return 2; }
