
#define tp this_player()->query_name()

int uses;

id(str) {
    if (str == "ipocras" || str == "juice" || str == "skin")
        return 1;
}

short() {
    if (uses)
    return "A skin of Ipocras";
    return "A skin of Ipocras (empty)";
}

is_heal() { return "soak"; }
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
   write("A skin of Ipocras.  Best described as grape cider.\n"+
     "It is white grape juice with spices served chilled or heated.\n"+
     "You may sip or drink the Ipocras to regain lost vitality.\n"+
     "The skin looks to be about "+uses+"/4 full.\n");
}

reset(arg) {
   if (arg) return;
   uses=4;
}



drink(str) {
   if (str && id(str)) {
      if(!uses) {
         notify_fail("The skin of Ipocras is empty.\n");
         return 0;
      }
      if (!call_other(this_player(), "drink_soft", 18)) return 0;
      write("The Ipocras tingles down your throat.\n");
      say(tp+" "+query_verb()+"s from a skin of Ipocras.\n");
      uses--;
      call_other(this_player(), "heal_self", 40);
      if (!uses) {
      write("You empty the skin of Ipocras.\n"+
         "The sweet aftertaste leaves you longing for more.\n");
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

