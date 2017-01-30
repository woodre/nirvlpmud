xsexy(str)  {
object ob;
if(!str)  {
  write("You smile sexily.\n");
  say(tp+" smiles a sexy smile, her eyes smouldering with sultry fire...\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You smile...one of those you-are-so-sexy-and-I-know-you-want-me smiles.\n");
  say(tp+" smiles an incredibly radiant smile at "+CAP+".\n"+
  "You wish she would smile at you that way...\n",ob);
  tell_object(ob, tp+" smiles at you...and you can tell from her smile that\n"+
  "she thinks you are sexy...\n");
  return 1;
        }

