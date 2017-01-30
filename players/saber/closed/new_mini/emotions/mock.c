mock(str)  {
object ob;
 if(!str)  {
  write("Mock who?\n");
  return 1;
     }
  ob = present(str,environment(TP));
  str = CAP;
  if(!ob)  {
  write("You mock "+str+".\n");
  say(tp+" mocks "+str+".\n");
  return 1;
     }
  write("You mock "+str+".\n");
   say(tp+" mocks "+str+".\n",ob);
  tell_object(ob,tp+" mocks you.\n");
  return 1;
        }
