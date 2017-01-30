blade_twirl(str)  {
object ob;

  if(!str)  {
    write("What blade do you want to twirl.\n");
    return 1;
        }

  ob = present(str, this_player());
  if(!ob || ob->weapon_class() < 1)  {
    write("You need a weapon to twirl.  <blade_twirl> <weapon>\n");
    return 1;
        }

  write("You twirl "+ob->short()+" about your body with deadly grace.\n");
  say(tp+" twirls "+ob->short()+" about "+POSS+" body with deadly grace.\n");
  return 1;
        }
