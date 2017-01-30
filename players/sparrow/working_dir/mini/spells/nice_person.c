/*
 *  The kender ability to tell who is nice and who is not.  (v2.0)
 *
 */

#define ALIGN ob->query_alignment()

nice_person(str)  {

  object ob;
  string nice, nice2;
  int like_it;

  if(!str)  {
    write("Who are you wondering about...?\n");
  return 1;
        }

  ob = present(str, environment(this_player()));
  if(!ob)  {
    write("You do not see "+CAP+" here.\n");
    return 1;
        }

  if(!living(ob))  {
    say(tp+" studies the "+ob->short()+" intently.\n");
    write("You study the "+ob->short()+" intently.\n");
    like_it = random(6);
    if(like_it == 0) nice2 = "is a very ordinary "+ob->short()+".";
  if(like_it == 1) nice2 = "is a pretty nice "+ob->query_name()+".";
  if(like_it == 2) nice2 = "isn't that likeable.";
  if(like_it == 3) nice2 = "is pretty dull.  Oh well...";
  if(like_it == 4) nice2 = "looks very interesting!";
  if(like_it == 5) nice2 = "is special.  You're not sure why, but you should find out!";
  write(ob->query_name()+" "+nice2+"\n");
  return 1;
        }

  write("You glance up at "+ob->short()+".\n");
  if(ALIGN >  750)  nice = "could be a paladin!  Wow...";
  if(ALIGN >  500 && ALIGN <  751)  nice = "gives you good vibes.";
  if(ALIGN >  150 && ALIGN <  501)  nice = "seems pretty nice.";
  if(ALIGN > -150 && ALIGN <  150)  nice = "is ok...  *shrug*";
  if(ALIGN > -501 && ALIGN < -150)  nice = "makes you feel uneasy.";
  if(ALIGN > -751 && ALIGN < -500)  nice = "gives you a *very* creepy feeling...";
  if(ALIGN < -750)  nice = "almost seems to radiate evil.";
    write(ob->query_name()+" "+nice+"\n");
    return 1;
        }
