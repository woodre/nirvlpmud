c_slobber(str) {
object ob;
 if(!str)  {
write("You slobber all over yourself!\n");
  say(tp+" slobbers all over "+POSS+" face!\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Slobber who?\n");
     return 1;   }
write("You jump up and slobber all over "+CAP+"'s face!\n");
say(tp+" jumps up and slobbers all over "+CAP+"'s face!\n",ob);
tell_object(ob, tp+" jumps up and slobbers all over your face!\n");
  return 1;
       }
