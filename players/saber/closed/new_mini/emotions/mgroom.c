groom(str)  {
object ob;
 if(!str)  {
  write("You groom yourself with a little pink tongue.\n");
  say(tp+" grooms "+OBJE+"self with a little pink tongue.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Groom who?\n");
     return 1;   }
  write("You begin to groom "+CAP+" with your little pink tongue.\n");
  say(tp+" begins to groom "+CAP+" with "+POSS+" little pink tongue.\n",ob);
  tell_object(ob, tp+" begins to groom you with "+POSS+" little pink tongue.\n");
  return 1;
       }
