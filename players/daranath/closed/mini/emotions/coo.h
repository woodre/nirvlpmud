coo(str)  {
object ob;
 if(!str)  {
  write("You coo softly.\n");
  say(tp+" 'coo's softly.\n");
  return 1;
     }
  ob = present(str,environment(this_player()));
  str = CAP;
  if(!ob)  {
  write("Coo at who?\n");
  return 1;
     }
  write("You coo softly at "+str+".\n");
  say(tp+" 'coo's softly at "+str+".\n",ob);
  tell_object(ob,tp+" 'coo's softly at you.\n");
  return 1;
        }
