xpurr(str)  {
object ob;
if(!str)  {
  write("You purr sexily.\n");
  say(tp+" purrrrrs and she seems to vibrate with plesaure.\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You purrrrr deep from your throat at "+CAP+".\n");
  say(tp+" purrrrs softly at "+CAP+", her whole body quivering...\n"+
    "You wonder why that is soooo damn sexy...\n",ob);
  tell_object(ob, tp+" purrrs at you...The purr comes from deep inside.\n"+
    "Her whole body quivers and you wonder what you did to\n"+
    "deserve her purrrr...and how to do it again...\n");
  return 1;
        }
