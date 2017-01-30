xhug(str)  {
object ob;
if(!str)  {
  write("Hug who?\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
  write("You take "+CAP+" into your arms and combine your body with "+POS2+".\n");
  say(tp+" holds "+CAP+" very tight and close.\n",ob);
  tell_object(ob, tp+" grabs you and holds you very tightly.  You feel the\n"+
  "heat and love pulsing from her body for you.\n");
  return 1;
        }
