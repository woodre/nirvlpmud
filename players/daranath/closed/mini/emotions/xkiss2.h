xkiss2(str)  {
object ob;
if(!str)  {
  write("Kiss who?\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You slowly slide your arms around "+CAP+"'s neck and bring your lips to "+POS2+".\n");
say(tp+" slides her arms around "+CAP+" and kisses him deeply.\n",ob);
tell_object(ob, tp+" slides her arms around your neck and kisses you deeply,\n"+
  "her tongue probing your mouth and her body pressing hotly agaist yours.\n");
  return 1;
        }
