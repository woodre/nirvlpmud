xmoan(str)  {
object ob;
  if(!str)  {
  write("You moan softly and huskily.\n");
  say(tp+" moans...and you wonder what could feel THAT good...\n");
  return 1;
        }
ob = present(str,environment(this_player()));
THAT;
write("You moan at "+ob->query_objective()+" looking at "+OOBJ+" to say you WANT "+OOBJ+".\n");
say(tp+" moans huskily at "+CAP+", her whole body tensing...\n",ob);
tell_object(ob, tp+" moans at you...her head thrown back a bit and her back arching...\n"+
  "You have never before seen such an example of pleasure...\n");
  return 1;
        }
