c_hump(str) {
object ob;
 if(!str)  {
write("You dry hump the ground.\n");
say(tp+ " rubs "+POSS+" underside against the ground and grins.\n");
  return 1;
   }
  ob = present(str,environment(this_player()));
   str = capitalize(str);
   if(!ob) { write("Hump who?\n");
     return 1;   }
write("You rush up to "+CAP+" and vigourously hump their leg!\n");
say(tp+" rushes up and starts to hump "+CAP+"'s leg!\n");
tell_object(ob, tp+" rushes up to you and starts to hump your leg...EEEWWW!!!\n");
  return 1;
       }
