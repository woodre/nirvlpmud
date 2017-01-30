#define FADE_TIME 60
string exit_com;
object where_to;
string short_desc;
string last_verb;
object whose;
id(str) { return str == "footprint" || str == "footprints"; }
reset(arg)
{
   if(arg) return;
   exit_com = ""; last_verb = ""; where_to = 0; whose = 0; short_desc = 0;
}
find_me()
{
   object here,there;
   if(!whose)
      {
      destruct(this_object());
      return;
   }
   here = environment(this_object());
   there = environment(whose);
   if(here!=there)
      {
      set_short("A trail of "+whose->query_name()+"-foot-shaped prints lead out of the room and into " + there->short());
      set_exit(last_verb,there);
      for(here = first_inventory(there); here; here = next_inventory(here)) if(here->query_whose() == whose) return;
      here = clone_object(explode(file_name(this_object()),"#")[0]);
      move_object(here,there);
      here->set_whose(whose);
      return;
   }
}
init()
{
#ifndef __LDMUD__
        add_action("update");  add_xverb("");
#else
           add_action("update","",3);
#endif
}
update(str)
{
   if(this_player()==whose)
      {
      call_out("find_me",0);
      last_verb = str;
   }
}
set_whose(w)
{
   whose = w;
   last_verb = "";
   return 1;
}
set_short(str)
{
   remove_call_out("fade");
   short_desc = str;
   call_out("fade",FADE_TIME);
}
short() { return short_desc; }
fade()
{
   if(!whose)
      {
      destruct(this_object());
      return;
   }
   if(environment(whose) == environment(this_object())) { set_short(0); return; }
   destruct(this_object());
}
set_exit(str, w)
{
   exit_com = str;
   where_to = w;
}
query_exit_com()
{
   return exit_com;
}
query_where_to()
{
   return where_to;
}
query_whose()
{
   return whose;
}
long()
{
   if(exit_com != "") write("These footprints look like they've been here less than a minute.\n");
}
