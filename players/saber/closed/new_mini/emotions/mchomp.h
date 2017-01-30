chomp(str)  {
object ob;
 if(!str)  {
  write("Chomp who?\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Chomp who?\n");
     return 1;   }
  write("You chomp "+CAP+" with your sharp kitty fangs.\n");
  say(tp+" chomps "+CAP+" upon the neck with "+POSS+" sharp kitty fangs!\n",ob);
  tell_object(ob, tp+" chomps you on the neck with "+POSS+" sharp kitty fangs!\n"+
       "OUCH!\n");
  return 1;
       }
