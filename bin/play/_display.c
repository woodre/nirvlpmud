int
cmd_display(string str)
{
    object ob, x, me, merf;
    string what, who, shrt;

    if(!str) return (notify_fail("You may either display an item, or display an item to someone.\n"), 0);

    if(sscanf(str, "%s to %s", what, who) < 2)
      what = str;

/* changed to show items that are descriptive in the inventory
   -Bp
    if(!(ob=present(what, this_player())) || !ob->short())
--->
  if(!(ob=present(what, this_player())) || (!ob->short() && !ob->extra_look()) || (ob->extra_look() && !ob->extra_look_two()))
      return (notify_fail("You don't have that item.\n"), 0);
*/
  if(!(ob=present(what, this_player())))
    return (notify_fail("You don't have that item.\n"), 0);

    shrt = (string)ob->short();
    if(!shrt) shrt = (string)ob->extra_look_two();
  if(!shrt && !function_exists("extra_look", ob))
    return (notify_fail("You don't have that item.\n"), 0);
  if(!shrt) shrt=str;
  if(this_player()->query_level() >= 21)
  {
    write("\
Due to recent security changes, please note that this command\n\
may not work as hoped for in usage with other wizards,\n\
specifically those of a higher or equal level. Rest assured\n\
however that it has the same functionality for players-\n\
the ppl that really matter- as it always has.\n\
  Vertebraker <5-18-04>\n");
  }
    if(who)
    {
      x = find_player(who);
      if(!x || environment(x) != environment(this_player()))
        return (notify_fail("You don't see " + capitalize(who) + " around you.\n"), 0);
      if((int)x->query_level() >= 21)
      {
        write("You may not display an item to a wiz.\n");
        return 1;
      }
      write("You display " + shrt + " to " + (string)x->query_name() + ".\n");
      merf=ob;
      ob = clone_object("/obj/user/display_merf");
      ob->set_ob(merf);
      tell_object(x, "\n" + (string)(me=this_player())->query_name() + " displays " + 
        possessive(this_player()) + " " + shrt + " for you to see.\n");
      tell_room(environment(me), (string)me->query_name() + " displays " +
         possessive(this_player()) + " " + shrt + " for " +
         (string)x->query_name() + " to see.\n", ({ this_player(), x }));
      tell_object(x, "\n");
      command("merf", x);
      tell_object(x, "\n");
      destruct(ob);
      return 1;
    }

    else
    {
      object xb, xc;

      tell_room(environment(this_player()), (string)this_player()->query_name() + " displays " +
        shrt + " for everyone to see.\n", ({ this_player() }));
      write("You display " + shrt + " for everyone to see.\n");
      merf=ob;
      ob=clone_object("/obj/user/display_merf");
      ob->set_ob(merf);
      xb = first_inventory(environment(me=this_player()));
      while(xb)
      {
        xc = next_inventory(xb);
        if((int)xb->is_player() && (xb != me) && (int)xb->query_level() <= 20)
        {
          if(ob) move_object(ob, xb);
          tell_object(xb, "\n");
          command("merf", xb);
          tell_object(xb, "\n");
        }
        xb = xc;
      }
      if(ob) destruct(ob);
    }
    return 1;
}
