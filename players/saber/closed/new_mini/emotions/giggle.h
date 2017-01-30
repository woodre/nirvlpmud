giggle(str)  {
object ob;
 if(!str)  {
  write("You giggle innocently.\n");
  say(tp+" giggles innocently.\n");
  return 1;
     }
  ob = present(str,environment(TP));
   if(!ob) { write("That is not here!\n"); return 1; }
  if(!living(ob)) { write("That is not a live .\n"); return 1; }
  str = CAP;
  write("You giggle innocently at "+str+".\n");
  say(tp+" giggles innocently at "+str+".\n",ob);
  tell_object(ob,tp+" giggles innocently at you.\n");
  return 1;
        }
