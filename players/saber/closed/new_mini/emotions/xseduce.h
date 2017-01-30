xseduce(str)  {
object ob;
if(!str)  {
  write("You want to seduce who...?\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
  write("You slowly walk around "+CAP+" in a circle...when you get to in front of "+OOBJ+"\n"+
  "again you stop...and sliding your hands down your body look at him in a way\n"+
  "that no mortal man can refuse...\n");
  say(tp+" slowly looks "+CAP+" over, than runs her hands down her body and\n"+
  "allows her eyes to invite him to more...\n",ob);
tell_object(ob, tp+" slowly walks around you in a circle.  When she gets to in front\n"+
   "of you again she stops, sliding her hands down her UNBELIEVEABLY perfect\n"+
   "and sexy body she looks at you in a way that no mortal man could refuse...\n\n"+
   "But who would want to refuse???\n");
   return 1;
        }
