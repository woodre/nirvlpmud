smolder(str)  {
object ob;
 if(!str)  {
  write("You smolder in anger.\n");
  say(tp+" smolders angerly.\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
   if(!ob)  {
   write("Smolder towards whom?\n");
   return 1;
     }
  write("You give "+str+" a smoldering glare.\n");
  say(tp+" gives "+str+" a smoldering glare.\n",ob);
  tell_object(ob,tp+" gives you a smoldering glare.\n");
  return 1;
        }
