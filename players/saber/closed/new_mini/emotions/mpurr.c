purr(str)  {
object ob;
 if(!str)  {
  write("You purr loudly.\n");
  say(tp+" purrs loudly.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("purr at who?\n");
     return 1;   }
  write("You purr loudly at "+CAP+".\n");
  say(tp+" purrs loudly at "+CAP+".\n",ob);
  tell_object(ob, tp+" purrs loudly at you.\n");
  return 1;
       }
