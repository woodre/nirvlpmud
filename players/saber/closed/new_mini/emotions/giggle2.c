giggle2(str)  {
object ob;
 if(!str)  {
  write("You giggle happily.\n");
  say(tp+" giggles happily.\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
  if(!ob)  {
  write("Giggle at who?\n");
   return 1;
     }
  write("You giggle happily at "+str+".\n");
  say(tp+" giggles happily at "+str+".\n",ob);
  tell_object(ob,tp+" giggles happily at you.\n");
  return 1;
        }
