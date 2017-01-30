xflirt(str)  {
object ob;
if(!str)  {
  write("You flirt seductively, running your hands down your body.\n");
  say(tp+" flirts seductively, running her hands all over her body.\n");
  say(tp+" is looking incredibly sexy!\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You seductively flirt with "+CAP+".\n");
say(tp+" seductively flirts with "+CAP+".\n",ob);
tell_object(ob, tp+" seductively flirts with you, bringing your hands to her body.\n");
  tell_object(ob, "You simply cannot resist her...\n");
   return 1;
        }
