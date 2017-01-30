int vodka_drank;

id(str) { return (str == "vodka" || str == "shot"); }

reset() {}

long() {
   write("A bottle of pure clear vodka.\n");
   write("There are "+10 - vodka_drank+" shots left.\n");
}

short() {
   return "A bottle of vodka";
}

query_save_flag() { return 1; }

init() {
   add_action("drink"); add_verb("drink");
}

drink(arg) {
   if(id(arg)) {
      if(!call_other(this_player(), "drink_alcohol", 14) {
         write("You are too drunk to open the bottle.\n");
         say(this_player()->query_name()+" tries to open a voda, but is too drunk.\n");
          return 1;
      }
      if(call_other(this_player(), "drink_alcohol", 15)
         write("You take a sip of vodka, and it burns your throat.\n");
         say(this_player()->query_name()+" drinks some vodka.\n");
         if(vodka_drank == 10) {
            write("You drank your last shot of vodka.\n");
         }
         else { 
            write("You have "+(10 - vodka_drank)+" shots left.\n");
         }
          call_other(this_player(), "heal_self", 35);
          this_player()->add_weight(-1);
         vodka_drank++;
         if(vodka_drank == 10) {
            this_player()->add_weight(-1);
            destruct(this_object());
         }
         return 1;
     }
     return 1;
}

get() { return 1; }

query_weight() { return (11 - vodka_drank); }

query_value() {
   int worth;
   worth = 3500-3500/10*vodka_drank;
   return worth;
}
