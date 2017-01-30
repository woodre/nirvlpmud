
buy(str) {
   string what;
   string who;
   object trump;
   if (!str) {
      write("Buy what?\n");
      return 1;
   }
   if (sscanf(str,"%s %s",what,who) != 2) {
      write("buy what?\n");
      return 1;
   }
   if (what != "trump") {
      write("Did you want a trump or something?\n");
      return 1;
   }
   if (call_other(this_player(),"query_money",0) < 500) {
      write("You can't afford a trump!\n");
      return 1;
   }
   if (!find_player(who)) {
      write("That person is not in the MUD right now.\n");
      return 1;
   }
   trump = clone_object("/players/blackadder/trumps/gen_trump");
   call_other(trump,"set_pict",who);
   call_other(trump,"set_pict_desc","A very good likeness!\n");
   if (!call_other(this_player(),"add_weight",
            call_other(trump,"query_weight"))) {
      write("You can't carry that much!\n");
      return 1;
   }
   move_object(trump,this_player());
   call_other(this_player(),"add_money", -500);
   write("Ok.\n");
   return 1;
}

