#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";

reset(arg){
  ::reset(arg);
  if(arg) return ;
long_desc = ""+
"   Bodies fill the room as they have been heaped upon each other in\n"+
"disarray.  The smell is aweful and there is little room for movement\n"+
"as the walls enclose upon the room.  They have been covered in dirt\n"+
"over the years with only a small portion of stone still catching the\n"+
"dim light that has filtered its way down here.\n";
dest_dir = ({
  PATH+"crypt2.c","east",
});
}
