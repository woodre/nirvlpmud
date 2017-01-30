#include "defs.h"

inherit "/players/feldegast/equip/backpack.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_short("A leather pack");
  set_long("This is a brown leather pack, with straps.  You can 'pack'\n"+
           "and 'unpack' it.\n");
}

void init() {
  ::init();
  if((string)this_player()->query_guild_name()=="cyberninja" ||
     (string)this_player()->query_guild_name()=="rangers" ||
     (string)this_player()->query_guild_name()=="dark rangers")
    {
      object ob,next;
      ob=first_inventory(this_object());
      while(ob) {
        next=next_inventory(ob);
        if(ob->weapon_class() || ob->armor_class()) destruct(ob);
        ob=next;
      }
    }
}
