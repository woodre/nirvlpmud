c_lick(str) {
object ob;
 if(!str)  {
write("You lick your nose.\n");
say(tp+" licks "+GENDER+" nose!\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Lick who?\n");
     return 1;   }
write("You jump up and lick "+CAP+"'s nose!\n");
say(tp+" jumps up and lick "+CAP+"'s nose!\n",ob);
tell_object(ob, tp+" jumps up and licks your nose!\n");
  return 1;
       }
