cold(str)  {
object ob;
 if(!str)  {
  write("Be cold to who?\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
   if(!ob)  {
   write("Be cold to who?\n");
   return 1;
     }
  write("You give "+str+" a cold glare.\n");
  say(tp+" gives "+str+" a cold glare.\n",ob);
  tell_object(ob,tp+" gives you a cold glare.\n");
  return 1;
        }
