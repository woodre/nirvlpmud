mew(str)  {
object ob;
 if(!str)  {
  write("You mew softly.\n");
  say(tp+" mews softly.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Mew at who?\n");
     return 1;   }
  write("You mew softly at "+CAP+".\n");
  say(tp+" mews softly at "+CAP+".\n",ob);
  tell_object(ob, tp+" mews softly at you.\n");
  return 1;
       }
