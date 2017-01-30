c_speak(str) {
   object ob;
   if(!str)  {
      write("You bark!\n");
say(tp+ " barks!\n");
      return 1;
   }
   ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Bark at who?\n");
      return 1;   }
   write("You bark loudly at "+CAP+"!\n");
   say(tp+" barks at "+CAP+"!\n");
   tell_object(ob, tp+" barks loudly in your face!\n");
   return 1;
}
