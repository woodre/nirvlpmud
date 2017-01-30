manic(str)  {
object ob;
 if(!str)  {
  write("You laugh maniacally.\n");
  say(tp+" laughs maniacally.\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
   if(!ob)  {
  write("Laugh at who?\n");
   return 1;
     }
  write("You look at "+CAP+" and laugh maniacally.\n");
  say(tp+" glances at "+CAP+" and laughs maniacally.\n",ob);
  tell_object(ob, tp+" glances at you and laughs maniacally.\n");
  return 1;
        }
