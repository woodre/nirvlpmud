
battle(str) {
   string who1,who2;
   if(!str || sscanf(str,"%s with %s",who1,who2) != 2) {
      write("Battle what?\n");
      return 1;
   }
   if(!present(who1,environment(this_player())) || !present(who2,environment(this_player()))) {
      write("They are not here.\n");
      return 1;
   }
   if(!living(present(who1,environment(this_player()))) || !living(present(who2,environment(this_player())))) {
      write("They are not both living objects.\n");
      return 1;
   }
   write("You hold the wand steady in front of you.\n");
   write("With the potent magical words of \"Hey you! Kill that guy,\"\n"+
      "you force "+capitalize(who1)+" to attack "+capitalize(who2)+".\n");
   say(this_player()->query_name()+" holds forth an important looking steel wand.\n");
   say("With the potent magical words of \"Hey you! Kill that guy,\"\n"+
      capitalize(who1)+" and "+capitalize(who2)+" are forced to attack each other.\n");
   present(who1,environment(this_player()))->attack_object(present(who2,environment(this_player())));
   present(who2,environment(this_player()))->attack_object(present(who1,environment(this_player())));
   return 1;
}
