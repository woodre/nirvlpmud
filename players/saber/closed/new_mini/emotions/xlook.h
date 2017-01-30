xlook(str)  {
object ob;
if(!str)  {
  write("You close your eyes and seem to radiate pleasure.\n");
  say(tp+" closed her eyes.  She seems to radiate pleasure and you wonder\n"+
  "what she is thinking...\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
  write("You look at him...your eyes spending time carressing every inch.\n");
  say(tp+" looks at "+CAP+", her eyes brushing lightly over "+POS2+" whole body.\n",ob);
  tell_object(ob, tp+" looks at you...her eyes focus first on your eyes,\n"+
  "than down your body...you can almost feel etheral hands\n"+
  "brush where her eyes go...\n");
  return 1;
        }
