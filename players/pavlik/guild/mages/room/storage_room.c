inherit "room/room";
#include "/players/pavlik/guild/mages/defs.h"

object lock;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The Mage's Storage Room";
  long_desc="The Mage's Storage Room.\n";

  dest_dir=({
	ROOM_DIR+"advance",		"out",
  });

}

init(){
  add_action("list_items","list_items");
  add_action("list_items","list");
}

list_items()
{
  object ob;
  int count;

  ob = first_inventory(this_object());
  count = 0;

  write("-- The Storage Room contains: \n");
  while(ob){
    object obj;
    obj = ob;
    ob = next_inventory(ob);

    if(!living(obj)){
      write(obj->short()+".\n");
      count++;
    }
  }
  if(count == 0)
    write("nothing.\n");
  write("   There are "+count+" items in the Storage Room.\n");
  return 1;
}

