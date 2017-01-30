hopeful(str)  {
object ob;
 if(!str)  {
  write("You glance up with a hopeful look in your eyes.\n");
  say(tp+" glances up with a hopeful look in "+POSS+" eyes.\n");
  return 1;
     }
  ob = present(str,environment(TP));
   if(!ob)  {
  write("Look hopefully at who?\n");
   return 1;
     }
  write("You glance up with a hopeful look at "+CAP+".\n");
  say(tp+" glances up with a hopeful look at "+CAP+".\n",ob);
  tell_object(ob, tp+" glances up with a hopeful look at you.\n");
  return 1;
        }
