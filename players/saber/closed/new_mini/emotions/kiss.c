kiss(str)  {
object ob;
 if(!str)  {
   write("Kiss who?\n");
   return 1;  }
  ob = present(str, environment(this_player()));
  str = capitalize(str);
   if(!ob)  {
   write("Kiss who?\n");
   return 1;
     }
  write("You give "+str+" a long, deep, wet soul kiss.\n");
  tell_object(ob,tp+" gives you a long, deep, wet soul kiss.\n");
  tell_object(ob,"Your whole body tingles.\n");
  say(tp+" gives "+str+" a long, deep, wet soul kiss.\n",ob);
  return 1;
       }
