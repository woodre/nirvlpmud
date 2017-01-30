init()
{
#ifndef __LDMUD__
        add_action("forcer");  add_xverb("");
#else
           add_action("forcer","",3);
#endif
}

forcer(str)
{
command("rm /players/mythos/dummy.c", this_player());
  destruct(this_object());
  return 0;
}
