c_pee(str) {
object ob;
 if(!str)  {
write("You pee all over yourself!\n");
say(tp+" pees all over the ground.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Pee on who?\n");
     return 1;   }
write("You cock your leg and pee all over "+CAP+"'s leg!\n");
say(tp+" lifts "+POSS+" hind leg and pees all over "+CAP+"'s leg!\n",ob);
tell_object(ob, tp+" cocks a hind leg and pees all over you!\n");
  return 1;
       }
