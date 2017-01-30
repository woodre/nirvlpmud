heartbreak(str)  {
object ob;
 if(!str)  {
  write("You give a cry as if your heart has been broken.\n");
  say(tp+" gives a soulful cry, as if "+POSS+" heart has been broken.\n");
  return 1;
     }
  ob = present(str,environment(TP));
   if(!ob)  {
  write("Who broke your heart?\n");
   return 1;
     }
  write("You look at "+CAP+", and give a soulful cry as if your heart has been broken.\n");
  say(tp+" looks at "+CAP+" and gives a soulful cry, as if "+POSS+" heart has been broken.\n",ob);
  tell_object(ob, tp+" looks at you and gives a soulful cry, as if "+POSS+" heart has been broken.\n");
  return 1;
        }
