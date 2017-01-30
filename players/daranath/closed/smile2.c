an_smile2(str)  {
object ob;
 if(!str)  {
   write("Smile at whom???\n");
   return 1;  }
  ob = present(str, environment(this_player()));
  str = capitalize(str);
   if(!ob)  {
   write("Smile at whom???\n");
   return 1;
     }
  write("You give "+str+" an angelic little smile.\n");
  tell_object(ob,tpn+" flashes an angelic little smile at you.\n");
  say(tpn+" flashes an angelic little smile at "+str+".\n");
  return 1;
       }
