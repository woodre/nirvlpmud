/*  Puppy's Special Wiztell  */

#include <ansi.h>
inherit "obj/treasure";

reset(arg){
   if(arg) return;
   set_id("toy");
   set_alias("puptoy");
   set_alias("teller");
   set_alias("chew toy");
   set_short(""+BOLD+CYN+"A chew toy"+NORM+"");
   set_long(
      "This is a small chew toy.  Little plastic pieces are dangling\n"+
      "off of it.  There are dirt and slobber marks all over it.\n"+
      "Usage: 'pup' to tell, 'pupe' to emote\n");
   set_weight(0);
   set_value(0);
}


init(){
   ::init();
   add_action("cmd_tell","pup");
   add_action("cmd_emote","pupe");
   add_action("cmd_ptell", "tell");
}

cmd_tell(str){
   object toy;
   toy=find_player("puppy");
   if(!toy){
      notify_fail("You don't see Puppy anywhere.\n");
      return 0;
   }
   
   write(""+BOLD+CYN+"You tell Puppy: "+str+NORM+"\n");
   tell_object(toy,""+GRN+":::::"+this_player()->query_name()+" : "+str+NORM+"\n");
   return 1;
}

cmd_emote(str){
   object toy1;
   toy1=find_player("puppy");
   if(!toy1){
      notify_fail("Puppy is nowhere to be found.\n");
      return 0;
   }
   
   write(""+BOLD+CYN+"You emote to Puppy: "+str+NORM+"\n");
   tell_object(toy1,""+GRN+":::::"+this_player()->query_name()+" "+str+NORM+"\n");
   return 1;
}

cmd_ptell(string arg)
{
   string who, what, a;
   object c;
   
   if(!stringp(arg) || sscanf(arg, "%s %s", who, what) < 2)
      {
      write("Um what?\n");
      return 1;
   }
   
   if(who != "puppy" && who != "f" && who != "me")
      return 0;
   
   if(!(c = find_player("puppy")))
      {
      write(""+HIB+"You can not find Puppy."+NORM+"\n");
      return 1;
   }
   
   write(""+HIB+""+NORM+"\n");
   if(!environment(c) || !interactive(c))
      {
      return 1;
   }
   if(query_idle(c) > 120)
   write("Puppy is idle.\n");
   write("["+HIG+"PTELL"+NORM+"] "+what+"\n");
   tell_object(c, HIB +""+HIB+"["+NORM+""+CYN+"PTELL"+NORM+""+HIB+"]"+NORM+""+HIB+" "+ 
      (a = (string)this_player()->query_name()) +
" tells you: " + HIB + what + NORM + "\n");
   c->add_tellhistory(CYN + a + " told you: " + NORM + what);
   c->Replyer((string)this_player()->query_real_name());
   return 1;
}

drop(){
   write("You can't drop the toy because it might get dirty.\n");
   return 1;
}

get(){
   write("The toy is too slimy to get.\n");
   return 1;
}

query_save_flag(){
return 1;
}
