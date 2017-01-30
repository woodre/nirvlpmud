mlick(str)  {
object ob;
 if(!str)  {
  write("You lick your lips, running your little pink tongue over sharp kitty fangs.\n");
  say(tp+" licks "+POSS+" lips, running a little pink tongue over sharp kitty fangs.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Lick who?\n");
     return 1;   }
  write("You lick "+CAP+" with your pink little kitty tongue.\n");
  say(tp+" licks "+CAP+" with "+POSS+" pink little kitty tongue.\n",ob);
  tell_object(ob, tp+" licks you with "+POSS+" little pink kitty tongue.\n");
  return 1;
       }
