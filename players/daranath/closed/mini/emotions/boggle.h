boggle(str)  {
object ob;
 if(!str)  {
  write("You boggle contentedly.\n");
  say(tp+" boggles contentedly.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Boggle who?\n");
     return 1;   }
  write("You boggle at "+str+".\n");
  say(tp+" boggles at "+str+".\n");
  tell_object(ob,"You feel boggled.\n");
  return 1;
       }
