inherit "room/room";
#include "/players/zeus/closed/all.h"
string exit;
object hook;

reset(arg){
 if(arg) return;

  long_desc =
"Shadows are all around you.  So dark that they block out all light.\n"+
"There is no way to tell which direction is which, they all seem the\n"+
"same.  It is hard to tell how to leave this place.\n";
  items=({
  "shadows", "Shadows are all around you",
  "darkness", "The darkness consumes you",
  });
  set_light(-10);
}

short(){ return "A dark room"; }
set_exit(str){ exit = str; }
set_hook(obj){ hook = obj; }

void init(){
  ::init();
  add_action("leave_dir", "reappear");
  add_action("leave_dir", "appear");
  add_action("leave_dir", "leave");
}

leave_dir(){
  string sb, sa;
  object redirect;
  if(!exit || !hook)
  {
    write("There is no way to exit, this is a bug.\n");
    this_player()->move_player("out#/room/church.c");
  }
  else
  {
    write("You emerge from the shadows.\n");
    if(sscanf(file_name(environment(hook)), "%s"+exit+"%s", sa, sb))
    {
      destruct(hook);
      this_player()->move_player("out#"+exit);
    }
    else
    {
      redirect = environment(hook);
      destruct(hook);
      move_object(this_player(), redirect);
      tell_room(redirect, this_player()->query_name()+" arrives.\n", 
        ({ this_player() }));
    }
  }
  if(present("vanish_obj", this_player()))
    destruct(present("vanish_obj", this_player()));
  return 1;
}

