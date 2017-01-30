xfondle(str)  {
object ob;
if(!str)  {
  write("Fondle who?\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You grab "+CAP+"'s hands and guide them all over your body.\n");
say(tp+" grabs "+CAP+"'s hands and guides them all over her body.\n");
tell_object(ob, tp+" guides your hands, running them over her body.\n");
tell_object(ob, "You begin to want to explore her body more.\n\n");
  return 1;
        }
