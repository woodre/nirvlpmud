/*
 *  The gypsy ability to tell home much something is worth.  (v2.0)
 *
 */

value_item(str)  {
  object ob;

  if(!str)  {
    write("What do you want to tell the value of?\n");
    return 1;
        }

  ob = present(str, TP);
    if(!ob)  ob = present(str, environment(TP));
    if(!ob)  {
      write("You cannot find a "+CAP+".\n");
      return 1;
        }

  if(ob)  {
    write(ob->short()+" is worth "+ob->query_value()+" golden coins.\n");
    say(tp+" looks at the "+ob->query_short()+".\n");
    return 1;
        }
        }
