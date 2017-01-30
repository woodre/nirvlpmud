scoff(str)  {
object ob;
 if(!str)  {
  write("You scoff at reality.\n");
  say(tp+" scoffs at reality.\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
  if(!ob)  {
  write("You scoff at "+str+".\n");
  say(tp+" scoffs at "+str+".\n");
  return 1;
     }
  write("You scoff at "+str+".\n");
  say(tp+" scoffs at "+str+".\n",ob);
  tell_object(ob,tp+" scoffs at you.\n");
  return 1;
        }
