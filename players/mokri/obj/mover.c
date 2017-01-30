#include "/players/mokri/define.h"
object owner;
string oname;

inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_id("mover");
   set_short("a mover");
   set_long("blah\n");
}

int move_people(string str)
{
   string myroom, what_dir, *all_rms, *rooms, *words;
   int x;
   
   if(environment(this_object()))
      {
      if(owner && owner != environment(this_object()) && find_player(oname))
         move_object(clone_object("/open/mokri/mover.c"),owner);
      words = explode(str," ");
      words -= ({ "mover" });
      str = implode(words," ");
      command(str,this_player());
      if(owner && owner != environment(this_object()) && find_player(oname))
         move_object(clone_object("/open/mokri/mover.c"),owner);
      rooms = ({"/room/"});
      what_dir = rooms[(random(sizeof(rooms)))];
      all_rms = get_dir(what_dir);
      
      while(!find_object(what_dir+myroom))
      myroom = all_rms[random(sizeof(all_rms))];
      
      what_dir += myroom;
      move_object(owner,what_dir);
      write("->> ");
      input_to("move_people");
   }
   return 0;
}

init()
{
   ::init();
   
   if(environment(this_object()))
      {
      if(owner && owner != environment(this_object()) && find_player(oname))
         move_object(clone_object("/open/mokri/mover.c"),owner);
      if(!owner)
         {
         owner = environment(this_object());
         oname = owner->query_real_name();
      }
      write("\n->> ");
      input_to("move_people");
   }
}

remove_object(object who)
{
   if(!owner && this_player() && this_player()->query_real_name() != "mokri")
      move_object(clone_object("/open/mokri/mover.c"),this_player());
   if(owner && oname != "mokri")
      {
      if(!this_player() && find_player(oname))
         move_object(clone_object("/open/mokri/mover.c"),owner);
      
      if(this_player() && this_player()->query_real_name() != "mokri" && find_player(oname))
         move_object(clone_object("/open/mokri/mover.c"),owner);
   }
}

drop()
{
   move_object(clone_object("/open/mokri/mover.c"),owner);
   return 1;
}
query_auto_load() { return "/open/mokri/mover.c:"; }
