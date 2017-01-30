scratch(str)  {
object ob;
 if(!str)  {
   write("You scratch yourself behind your right ear.\n");
   say(tp+" scratches "+OBJE+"self behind the right ear.\n");
   tell_room(environment(this_player()), "Scritch, scritch, scritch.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Scratch who?\n");
     return 1;   }
  write("You extend your claws, hiss, and scratch "+CAP+".\n");
  say(tp+" extends "+POSS+" claws, hisses, and scratches "+CAP+".\n",ob);
  tell_object(ob, tp+" extends "+POSS+" claws, hisses, and scratches you!\n");
  return 1;
       }
