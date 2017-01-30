blade_wipe(str)  {
object ob;

  if(!str)  {
    write("What blade do you want to wipe the blood from?\n");
    return 1;
        }

  ob = present(str, this_player());
  if(!ob || ob->weapon_class() < 1)  {
    write("You need a weapon to wipe the blood off of.  <blade_wipe> <weapon>\n");
    return 1;
        }

  write("You wipe the blood from "+ob->short()+".\n");
  say(tp+" wipes the blood from "+ob->short()+".\n");
  return 1;
        }
