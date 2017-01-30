xlick(str)  {
object ob;
if(!str)  {
  write("You lusciously lick your lips while lowering one shoulder of your loose garb...\n");
  say(tp+" licks her lips, and lowers one shoulder of her loose garb...\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
  write("You lick your lips at "+CAP+", and use "+POS2+" hand to lower\n"+
    "one shoulder of your loose garb...\n");
  say(tp+" licks her lips at "+CAP+" while using "+POS2+" hand to\n"+
     "lower one shoulder of her loose garb...\n",ob);
  tell_object(ob, tp+" licks her lips at you, and uses your hand to\n"+
 "lower one shoulder of her loose garb...\n");
tell_object(ob,"You WANT this woman!\n");
  return 1;
        }
