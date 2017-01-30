smile(str)  {
object ob;
 if(!str)  {
  write("You smile wickedly.\n");
  say(tp+" smiles wickedly.\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
   if(!ob)  {
   write("Smile at who?\n");
   return 1;
     }
  write("You smile wickedly at "+str+".\n");
  say(tp+" smiles wickedly at "+str+".\n",ob);
  tell_object(ob,tp+" smiles wickedly at you.\n");
  return 1;
        }
