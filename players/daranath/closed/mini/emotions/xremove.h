xremove(str)  {
object ob;
if(!str)  {
  write("You don't want to remove your garb for NO reason, do you...?\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You peel off your lingerie, and slide into "+CAP+"'s arms.\n");
say(tp+" slowly slides out of her garb, and slides into "+CAP+"'s arms...\n",ob);
tell_object(ob, tp+" gives you a sexy wink, and slowly slides out of her garb...\n");
tell_object(ob, "She than slides herself into your arms!\n");
say(CAP+" grins evilly.\n");
  return 1;
        }
