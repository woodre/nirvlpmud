blade_display(str)  {
object ob;

  if(!str)  {
    write("With what weapon do you want to pose?\n");
    return 1;
        }

  ob = present(str, this_player());
  if(!ob || ob->weapon_class() < 1)  {
    write("You need a weapon to pose with.  <blade_pose> <weapon>\n");
    return 1;
        }

  write("You raise "+ob->short()+" high above your head.\n");
  say(tp+" raises "+ob->short()+" high above "+POSS+" head.\n");
  return 1;
        }
