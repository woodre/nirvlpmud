#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  
  if( !present(" ", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object(" "), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = " ";
  long_desc =
"  \n\
    \n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    " ", " ",	
  });
}