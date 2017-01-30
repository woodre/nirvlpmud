jump(str)  {
object ob;
 if(! str)  {
  write("You jump around.\n");
  say(tp+" jumps around.\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
   if(!ob)  {
   write("Jump who?\n");
   return 1;
     }
  write("You jump on top of "+str+".\n");
  tell_object(ob,tp+" jumps on top of you!\n");
  say(tp+" jumps on top of "+str+".\n",ob);
  return 1;
        }
