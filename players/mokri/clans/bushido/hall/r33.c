inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"

string *Items;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - locker room");
   set_long("generic clan hall locker room.\n");
   add_property("NT");
   if(!present("sign")) {
      move_object(clone_object(TOP_DIR + "obj/storage_sign"), this_object());
   }
   restore_me();
}

init()
{
   ::init();
   add_action("cmd_store","store");
   add_action("cmd_retrieve","retrieve");
   add_action("list_items","list");
   add_action("cmd_clear","clear");
   check_valid_entry();
}

query_cost() { return 250000; }

int
items_stored()
{
   if (!Items) return 0;/* 3.1.2-DR comp */
   return sizeof(Items) / 5;
}

cmd_store(str)
{
   mixed sh,file,args,hits,misses;
   if(!str)
      {
      write("Store what?\n");
      return 1;
   }
   else
      {
      int flag;
      object what;
      if(!(what = present(str, this_player()))){
         write("You don't have \""+str+"\".\n");
         return 1;
      }
      if(items_stored() == 10)
         {
         write("All the communal lockers are full.\n");
         return 1;
      }
      /* save flag: 1 = no save, 2 = only hotel save */
      flag = (int) what->query_save_flag();
      if (what->drop() || 
            flag == 1 || flag == 2 || root(what) || basename(what)[0..2]=="obj")
      {
         write("\""+str+"\" will not go into the lockers.\n");
         return 1;
      }
      file = basename(what);
      sh = (string) what->short();
      args = (mixed) what->locker_arg(1);
      hits = (mixed) what->query_hits();
      misses = (mixed)what->query_misses();
      
      if (Items)
         Items += ({ sh, file, args, hits, misses, });
      else
         Items = ({ sh, file, args, hits, misses, });
      
      /* save now? */
      write("You put "+what->short()+" into the communal lockers.\n");
      destruct(what);
      save_me();
      return 1;
   }
}

cmd_retrieve(str)
{
   object ob;
   string err;
   int i;
   
   if (!Items || !sizeof(Items))
      {
      write("There isn't anything stored here.\n");
      return 1;
   }
   
   i = atoi(str);
   if (i < 1) return 0;
   i = 5*(i - 1);
   if (i >= sizeof(Items)) return 0;
   
   err = catch(ob = clone_object(Items[i + 1]));
   if (err) {
      if (this_player() && this_player()->query_level() >= 21)
         write(err);
      return 0;
   }
   
   ob->locker_init(Items[i + 2]);
   ob->set_hits(Items[i + 3]);
   ob->set_misses(Items[i + 4]);
   Items = deletea(Items, i, i + 4);
   save_me();
   write("You retrieve "+ob->short()+" from the communal lockers.\n");
   move_object(ob, this_player());
   return 1;
}

int
list_items()
{
   string tmp;
   int i, j, z;
   
   if(!Items || !sizeof(Items))
      {
      write("You don't have anything stored in the communal locker system.\n");
      return 1;
   }
   j = 1;
   tmp = "";
   while(i < sizeof(Items)) {
      if (Items[i]) tmp += (j ++) + ".\t" + Items[i] + ".\n";
      i += 5; }
   if (tmp == "")
      {
      write("You don't have anything stored.\n");
      return 1;
   }
   write(tmp+"\n");
   return 1;
}


status
remove_item(string str)
{
   int i;
   
   if (!stringp(str)) return 0;
   if (!Items) return 0;
   
   i = atoi(str);
   if (i < 1) return 0;
   i = 5*(i - 1);
   if (i >= sizeof(Items)) return 0;
   
   Items = deletea(Items, i, i + 4);
   save_me();
   return 1;
}

cmd_clear(string str)
{
   int x;
   string name;
   
   if (!str) return (notify_fail("Clear out which spot?\n"), 0);
   x = atoi(str);
   if (x < 1 || (x > items_stored())) {
      write("You do not have such a thing stored.\n");
      return 1;
   }
   remove_item(str);
   write("It has been disintegrated.\n");
   return 1;
}
