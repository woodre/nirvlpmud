#include "../defs.h"
inherit ROOM;



reset(int arg){
object sexton;
if(!sexton){
  sexton = clone_object(MON+"/sexton.c");
  move_object(sexton,this_object());
}
  if(!arg){
    is_pk = 1;
    set_light(1);
    short_desc= "Necromancer Component Storage";
    long_desc="  "+
      "A small store reeking of preservatives and dried blood. There are\n"+
      "small vials lined along the back of the room and filling the shelves\n"+
      "above.  Dead rats and bats hang from the ceilings along with an\n"+
      "assortment of other larger animals.  Woven baskets filled with dry\n"+
      "goods pilled along the side.  There is a small counter of stone resting\n"+
      "in the middle of the room.  Small wards and designs have been carved deep\n"+
      "into its surface.  Any necromancer could spend all day digging around the\n"+
      "store looking for the perfect component to use.\n"+
      "A small sign rests on the far wall of the storage area.\n";

    items=({
     "wall","The walls here are made of a very dirty marble",
     "walls","The walls here are made of a very dirty marble",
     "sign","The sign upon the far wall reads:\n\n"+
        "\t'List' and you shall receive knowledge,\n"+
        "\t'Buy' and you shall take it with you forever.\n"+
        "\tThe Darkness comes from Deep within the Corpse",
    });

    dest_dir=({
     PATH+"/room/necro4.c","north",
    });

    }
}

init(){
  ::init();
  add_action("read","read");
}

read(str){
  if(str != "sign"){
    notify_fail("What would you like to read?\n");
    return 0;
  }
  write("The sign upon the far wall reads:\n\n"+
        "\t'List' and you shall receive knowledge,\n"+
        "\t'Buy' and you shall take it with you forever.\n"+
        "\tThe Darkness comes from Deep within the Corpse.\n");
  return 1;
}

search(){
  write("Bits of bone and areas of dried blood are all about the room.\n");
  say(tp->query_name() +" searches the area.\n");
  return 1;
}

realm(){ return "NT"; }