rub(str)  {
object ob;
 if(!str)  {
  write("You rub up against the wall.\n");
  say(tp+" rubs up against the wall.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Rub against who?\n");
     return 1;   }
  write("You rub up against "+CAP+".\n");
  say(tp+" rubs up against "+CAP+".\n",ob);
  tell_object(ob, tp+" rubs up against you.\n");
  return 1;
       }
