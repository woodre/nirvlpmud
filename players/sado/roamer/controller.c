object roamer;

reset(arg)
{
   if(arg) return;
if(root()) return;
   roamer=clone_object("/players/sado/roamer/roamer.c");
   move_object(roamer,"/room/church");
}

init()
{
   add_action("kill_it","unroam");
   add_action("move_it","moveit");
   add_action("locate_it","loc");
   add_action("activate","ac");
   add_action("deactivate","deac");
}

kill_it()
{
   destruct(roamer);
   destruct(this_object());
   return 1;
}

id(str) { return str=="controller"; }

short() { return "A roamer controller"; }

get() { return 1; }

locate_it()
{
   write("It is in: "+environment(roamer)->short()+"\n");
   return 1;
}

deactivate()
{
   roamer->deactivate();
   return 1;
}

activate()
{
   roamer->activate();
   return 1;
}

move_it(str)
{
   roamer->move_to(str);
   return 1;
}
