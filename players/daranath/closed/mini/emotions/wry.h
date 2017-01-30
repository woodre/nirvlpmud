wry(str)  {
object ob;
 if(!str)  {
  write("You smile wryly.\n");
  say(tp+" smiles wryly.\n");
  return 1;
     }
  ob = present(str,environment(TP));
   str = CAP;
   if(!ob)  {
   write("Be wry towards whom?\n");
   return 1;
     }
  write("You smile wryly at "+str+".\n");
  say(tp+" smiles wryly at "+str+".\n",ob);
  tell_object(ob,tp+" smiles wryly at you.\n");
  return 1;
        }
