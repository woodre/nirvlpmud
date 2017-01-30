string invitee;
object treehouse;

id(str) { return str == "acorn"; }

short()
{
   if(!invitee) return 0;
   else return "An acorn from " + invitee;
}

long()
{
   write("This is an acorn with some writing scribbled on it.\n"+
   "It reads:\n\n"+
   "   This is an invitation to the treehouse of " + invitee + ".\n"+
   "   To accept entry to the treehouse type 'climb_tree'.\n"+
   "   To decline, merely drop the acorn or type 'discard'.\n");
}

set_invitee(str) { invitee = str; }
set_treehouse(arg) { treehouse = arg; }

query_value() { return 0; }
query_save_flag() { return 1; }
query_get() { return 1; }
query_drop() { return 1; }
drop()
{
   write("The acorn fades away into nothing.\n");
   destruct(this_object());
   return 1;
}

reset()
{
   call_out("destroy_self", 50);
}

init()
{
   if(this_player() && this_player()->query_pl_k() && this_player()->query_level() < 20)
   {
      destruct(this_object());
   }

   add_action("drop","discard");
   add_action("climb_tree","climb_tree");
}

climb_tree()
{
   object room, ob;
   int i;
   
   i = 0;
   if(!treehouse) return drop();
   
   room = environment(this_player());
   if(!room) return 0;
   
   ob = first_inventory(room);
   while(ob)
   {
      if(ob == treehouse) i = 1;
      ob = next_inventory(ob);
   }
   
   if(i == 0)
   {
      write("The treehouse of " + invitee + " is not nearby.\n");
      return 1;
   }
   else
   {
      write("You climb up the branches and into the treehouse...\n\n");
      command("look", this_player());
      tell_room(treehouse, this_player()->query_name() + " arrives climbing into the treehouse.\n");
      move_object(this_player(), treehouse);
      tell_room(room, this_player()->query_name() + " leaves up into the treehouse.\n");

      return drop();
   }
   
}

destroy_self()
{
   say("The acorn fades away into nothing.\n");
   destruct(this_object());
   return 1;
}   
