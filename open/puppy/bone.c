/* Puppy's teller to players */
#define tpn this_player()->query_name()
#define tl this_player()->query_level()
#include <ansi.h>
inherit "/obj/treasure";

reset(arg){
   if(arg) return;
   set_id("bone");
   set_alias("tool");
   set_short(""+CYN+"Puppy's bone"+NORM+"");
   set_long("This is Puppy's special tool.\n");
   
   set_weight(0);
   set_value(0);
}

drop(){
   write("You may not drop your bone.\n");
   return 1;
}

init(){
   ::init();
   add_action("pup","tt");
   add_action("pupe","te"); 
   add_action("pupf","tf");
add_action("mmuzzle","STFU");
   add_action("cchurch","church");
   add_action("force", "force");
   add_action("ppost","post");
   add_action("rraider","raider");
   add_action("ggreen","green");
   add_action("bbank","bank");
   add_action("bbank","banks");
   add_action("rrat","rat");
   add_action ("ccouncil", "council");
   add_action ("toy", "toy");
}



cchurch(string str) {
   if (!str || str != "church"){
      notify_fail("UM What???\n");
      write("You lope to the church");
      move_object(this_player(),"/room/church.c");
      command("look",this_player());
      return 1;}
}

ppost(string str) {
   if (!str || str != "post"){
      notify_fail("UM What???\n");
      write("You lope to the post office.\n");
      move_object(this_player(),"/room/post.c");
      command("look",this_player());
      return 1;}
}

ggreen(string str) {
   if (!str || str != "green"){
      notify_fail("UM What???\n");
      write("You lope to the green.\n");
      move_object(this_player(),"/room/vill_green.c");
      command("look",this_player());
      return 1;}
}

bbank(string str) {
   if (!str || str != "bank"){
      notify_fail("UM What???\n");
      write("You lope to the Banks of Stony Pond.\n");
      move_object(this_player(),"/players/puppy/EX/color.c");
      command("look",this_player());
      return 1;}
}
rraider(string str) {
   if (!str || str != "raider"){
      notify_fail("UM What???\n");
      write("You lope to the Raiders Stadium.\n");
      move_object(this_player(),"/players/puppy/raider.c");
      command("look",this_player());
      return 1;}
}
rrat(string str) {
   if (!str || str != "rat"){
      notify_fail("UM What???\n");
      write("You lope to the RAT.\n");
      move_object(this_player(),"/players/snow/ROOMS/bar.c");
      command("look",this_player());
      return 1;}
}
force(str) {
  object player;
  string name,cmd;
  if (!str) return 0;
  if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
  player=find_living(name);
  if(!player) { write(capitalize(name)+ " is not online.\n"); }
  command(cmd,player);
  return 1;
}
ccouncil(string str) {
   if (!str || str != "council"){
      notify_fail("UM What???\n");
      write("You lope to the DIRECTIVE CHAMBERS.\n");
      move_object(this_player(),"/players/dune/closed/guild/rooms/council.c");
      command("look",this_player());
      return 1;}
}

mmuzzle(str) {
object target_obj;
string target_name;
target_name = str;
if (!str) return 0;
target_obj = find_living(target_name);
if (!target_obj || target_obj==this_player()) {
write("You try to muzzle someone but they are not here.\n");
return 1;
}
write("You get tired of listening to crap and muzzle "+target_name+".\n");
move_object(clone_object("players/puppy/closed/STFU"), target_obj);
tell_object(target_obj,
"\n\n"+this_player()->query_name()+
" gets PISSED and muzzles you!\n\n");
return 1;
}

toy(str) {
   object target_obj;
   string target_name;
target_name = str;
if (!str) return 0;
   target_obj = find_living(target_name);
   if (!target_obj || target_obj==this_player()) {
      write("You consider offering a toy but can't find a target.\n");
      return 1;
   }
   write("You give a toy to "+target_name+".\n");
   move_object(clone_object("players/puppy/closed/toy"), target_obj);
   tell_object(target_obj,
      "\n\n"+this_player()->query_name()+
      " hands you a nifty little toy!\n\n");
   return 1;
}

pup(str) {
   object target;
   string who;
   string what;
   
   if(!str) 
      {
      write("Tell what?\n"); 
      return 1;
   }
   if(sscanf(str,"%s %s",who,what)==2)
      {
      target = find_player(who);
      if(!target) 
         {
         write(capitalize(who) + " is nowhere to be found.\n"); 
         return 1; 
      }
      if(this_player()->query_invis() > 1) 
         {
         tell_object(target, CYN+"[invis] Puppy barks: "+WHT+what+NORM+" \n");
         write(CYN+"You tell "+capitalize(who)+": "+WHT+what+NORM+"\n");
         target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
         
         return 1; 
      }
      if(this_player()->query_invis() < 1) 
         {
         tell_object(target,CYN+"Puppy barks: "+WHT+what+NORM+" \n");
         write(""+CYN+"You tell "+capitalize(who)+": "+WHT+what+NORM+"\n");
         target->add_tellhistory(this_player()->query_real_name()+" tells you: "+what);
         
         return 1; 
      }
      return 1;
   }
   return 1;
}


pupe(str) {
   object target;
   string who;
   string what;
   
   if(!str) 
      {
      write("Emote to whom?\n"); 
      return 1;
   }
   if(sscanf(str,"%s %s",who,what)==2)
      {
      target = find_player(who);
      if(!target) 
         {
         write(capitalize(who) + " is nowhere to be found.\n"); 
         return 1; 
      }
      if(this_player()->query_invis() > 1) 
         {
         tell_object(target,CYN+"[invis] Puppy "+WHT+what+NORM+" \n");
         write(""+CYN+"You faremote to " +capitalize(who)+": "+WHT+what+NORM+"\n");
         
         return 1; 
      }
      
      if(this_player()->query_invis() < 1) 
         {
         tell_object(target,""+CYN+"Puppy "+WHT+what+NORM+" \n");
         write(""+CYN+"You faremote to " +capitalize(who)+": "+WHT+what+NORM+"\n");
         return 1; 
      }
      return 1;
   }
   return 1;
}


pupf(str) {
   object target;
   string who;
   string what;
   
   if(!str) 
      {
      write("Emote to whom?\n"); 
      return 1;
   }
   if(sscanf(str,"%s %s",who,what)==2)
      {
      target = find_player(who);
      if(!target) 
         {
         write(capitalize(who) + " is nowhere to be found.\n"); 
         return 1; 
      }
      if(this_player()->query_invis() > 1) 
         {
         tell_object(target,""+BOLD+RED+what+NORM+" \n");
         write(""+BOLD+RED+"You echo to " +capitalize(who)+": "+what+NORM+"\n");
         
         return 1; 
      }
      if(this_player()->query_invis() < 1) 
         {
         tell_object(target,""+BOLD+RED+what+NORM+" \n");
         write(""+BOLD+RED+"You echo to " +capitalize(who)+": "+what+NORM+"\n");
         
         return 1; 
      }
      return 1;
   }
   return 1;
}
