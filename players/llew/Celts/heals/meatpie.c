
#define tp this_player()->query_name()

int uses;

id(str) {
    if (str == "meat pie" || str == "pie" || str == "meat")
        return 1;
}

short() {
    if (uses)
    return "A bowl of meat pie";
    return "A bowl of meat pie (empty)";
}

is_heal() { return "stuff"; }
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
   write("A bowl of meat pie.  A recipe of beef, fowl and.\n"+
     "marshberries surrounded by a flaky dark crust.\n"+
     "The bowl looks to be about "+uses+"/4 full.\n");
}

reset(arg) {
   if (arg) return;
   uses=4;
}



eat(str) {
   if (str && id(str)) {
      if(!uses) {
         notify_fail("The bowl of meat pie is empty.\n");
         return 0;
      }
      if (!call_other(this_player(), "eat_food", 16)) return 0;
      write("The hot meat pie makes you feel better.\n");
      say(tp+" eats some meat pie.\n");
      uses--;
      call_other(this_player(), "heal_self", 40);
      if (!uses) {
      write("You eat all of the meat pie.\n");
      }
      return 1;
   }
}

init() {
   add_action("eat","eat");
}

get() { return 1; }

query_weight() { return 2; }
