inherit "/obj/treasure.c";
#define REPLICANT_PATH "/players/mokri/cybers/obj/template.c"
#define COST 1000
reset(int arg) {
   if(arg) return;
   set_id("replicator");
   set_short("A replicator");
   set_long("\nA rectangular, metallic machine. It stands six feet tall.\n"+
      "There is a square hole halfway up the machine. Directly below\n"+
      "the hole sits a control panel with buttons.\n\n"+
      "Operating instructions:\n"+
      "  To create a copy of an object, 'replicate <item>'.\n"+
      "  The cost is " + COST + " credits.\n"+
      "  NOTE: The resulting duplicate is a duplicate in looks\n"+
      "        only. It will NOT be functional in any way.\n");
   set_weight(1000);
}

init()
{
   ::init();
   
   add_action("replicate","replicate");
}

int replicate(string arg)
{
   int credits;
   object gobj, original, replicant;
   
   gobj = present("guild_implants",this_player());
   if(!gobj)
      {
      write("Error. No implants present.\n");
      return 1;
   }
   
   if(!arg)
      {
      write("What object would you like to replicate?\n");
      return 1;
   }
   
   credits = (int)gobj->balance();
   
   if(credits < COST)
      {
      write("You do not have enough credits.\n");
      return 1;
   }
   
   original = present(arg,this_player());
   if(!original)
      {
      write("You have no such object to replicate.\n");
      return 1;
   }
   
   if(original->drop())
      {
      write("You cannot let go of that to put it in the replicator.\n");
      return 1;
   }
   
   gobj->addToBalance(-COST);
   write("You place the item in the replicator and press a few buttons.\nIt shimmers and begins to vibrate...\n\nIt settles back down, and a copy sits next to it.\nYou take the copy and the original out of the replicator.\n");
   say(this_player()->query_name()+" places something into the replicator and presses a few buttons.\nIt shimmers and begins to vibrate...\n\nIt settles back down, and a copy sits next to it.\n" + this_player()->query_name()+" takes the copy and the original out of the replicator.\n");
   replicant = clone_object(REPLICANT_PATH);
   replicant->set_short(original->query_short());
   replicant->set_long(original->query_long());
   replicant->set_id(original->query_name());
   move_object(replicant,this_player());
   return 1;
}

get() { return 0; }
