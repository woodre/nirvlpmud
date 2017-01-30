shy(str)  {
object ob;
 if(!str)  {
  write("You feel shy.\n");
  say(tp+" looks shy.\n");
  return 1;
     }
  ob = present(environment(TP));
  str = CAP;
   if(!ob)  {
   write("Be shy for who?\n");
   return 1;
     }
  write("You look shyly at "+str+".\n");
  say(tp+" looks shyly over at "+str+".\n",ob);
  tell_object(ob,tp+" looks shyly over at you.\n");
  return 1;
        }
