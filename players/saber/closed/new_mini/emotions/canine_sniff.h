c_sniff(str) {
   object ob;
   if(!str)  {
      write("You sniff around the room.\n");
      say(tp+" sniffs around the room, smelling everything in sight.\n");
      return 1;
   }
   ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Sniff what?\n");
      return 1;   }
   write("You lope over to "+CAP+" and take in a big whiff!\n");
   say(tp+" lopes over to "+CAP+" and takes in a big whiff!\n");
    tell_object(ob, tp+" lopes over to you and takes a big whiff of your private area!\n");
   return 1;
}
