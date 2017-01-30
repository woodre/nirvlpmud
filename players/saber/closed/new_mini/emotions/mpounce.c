pounce(str)  {
object ob;
 if(!str)  {
  write("You pounce upon your tail!\n");
  say(tp+" pounces upon "+POSS+" tail!\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Pounce upon who?\n");
     return 1;   }
  write("You hunch down, swish your tail, and pounce upon "+CAP+".\n");
  say(tp+" hunches down, swishes "+POSS+" tail, and pounces upon "+CAP+"\n",ob);
  tell_object(ob, tp+" hunches down, swishes "+POSS+" tail, and pounces upon you!\n");
  return 1;
       }
