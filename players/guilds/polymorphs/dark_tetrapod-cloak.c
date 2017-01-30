#include "/players/mizan/esc.h"
#include "definitions.h"

inherit "obj/monster";

object owner;
string owner_name;

reset(arg)
{
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   
   set_name("tetrapod");
   set_race("Tetrapod");
   set_alias("dark tetrapod");
   set_short("A dark tetrapod");
   set_level(19);
   set_hp(200000);
   set_al(-400);
   set_ac(60);
   set_wc(0);
   call_out("fake_beat", 1);
}

realm() { return "NT"; }
is_player() { return 1; }
query_guild_name() { return "polymorph"; }
query_mizan_shell() { return 1; }

short() 
{
   if(owner) 
   {
      if(this_player() && this_player()->query_level() > 19)
      return "Poly Dark Tetrapod Cloak (invis)";
      else return 0;
   }
   else return 0;
}

is_puffer() { return 1; }

long() {
   object ob;
   ob = first_inventory(this_object());
   write("This appears to be the silouette in the shadows of a dark tetrapod remarkably\n"+
         "similar to that of " + owner->query_name() + ".\n");

   while(ob) {
      if(!ob->is_player() && ob->short()) write(ob->short() + ".\n");
      ob = next_inventory(ob);
   }
   return 1;
}

can_put_and_get() { return 0; }

second_life() { return 1; }
query_hp() { return 20; }
query_mhp() { return 20; }
attack() {  return 1; }
attack_object() { ::attack_object(); }
hit_player() { return 1; }
move_player() 
{
   write("You cannot move while cloaked.\n");
   return 1; 
}

fake_beat() 
{


   if(this_object()->query_attack() != 0)
   {
     this_object()->attack_object();
     this_object()->attack_object();
     this_object()->stop_fight();
     this_object()->stop_fight();
     this_object()->stop_hunter();
     this_object()->stop_hunter();
     
     this_object()->query_attack()->attack_object();
     this_object()->query_attack()->attack_object();
     this_object()->query_attack()->stop_fight();
     this_object()->query_attack()->stop_fight();
     this_object()->query_attack()->stop_hunter();
     this_object()->query_attack()->stop_hunter();


   }

   if(owner_name) 
   {
     if(!owner) owner = find_player(owner_name);
     if(!owner) destruct(this_object());
     if(owner) move_object(owner, this_object());
   }

   remove_call_out("fake_beat");
   call_out("fake_beat", 1);
}

set_owner(a) { owner_name = a; }

catch_tell(str) 
{
   if(str && str != "What?\n")
      if(owner)
      tell_object(owner, str);
   return 1;
}

init() {
   if(owner && this_player() && this_player() == owner)
    {
      add_action("look_see","look");
      add_action("look_see","l");
      add_action("block","note");
      add_action("block","Np");
      add_action("block","get");
      add_action("block","put");
      add_action("block","drop");
      add_action("block","kill");
      add_action("dark_tetrapod_say","say");
      add_action("dark_tetrapod_say","'");
      add_action("block",";");
      add_action("block","\"");
      add_action("decloak","decloak");
      add_action("decloak","revert");
      add_action("block_cloak","cloak");
      add_action("revert","revert");
      add_action("xcatch"); add_xverb("");
   }
   ::init();
}

revert() 
{
   move_object(this_player(), environment(this_object()));
   
   write("You relax and fade into view.\n");
   say(owner->query_name() + " fades into view.\n");

   owner = 0;
   destruct(this_object());
   return 0;
}

dark_tetrapod_say(str)
{
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  tell_room(environment(this_object()),
    "A dark tetrapod shadow says: " + str + "\n");
    return 1;
}

block() 
{
   write("You fail in cloaked form.\n");
   return 1;
}

xcatch(str) 
{
   string tmp,tmp2;
   tmp = query_verb();
   if(tmp == " decloak" || tmp == "decloak") {
      decloak();
      return 1;
   }
   if(tmp == " revert" || tmp == "revert") {
      decloak();
      return 1;
   }
   if(tmp == " cloak" || tmp == "cloak") {
      block_cloak();
      return 1;
   }
   if(tmp == " revert" || tmp == "revert") {
      revert();
      return 1;
   }
   if(str) tmp = tmp + " " + str;
   sscanf(tmp, " %s", tmp2);
   return command(tmp2, this_object());
}

block_cloak()
{
   write("You are already cloaked.\n");
   return 1;
}

decloak() 
{
   /*
   move_object(this_player(), environment(this_object()));
    */

   write("You decloak and fade into view.\n");
   say(owner->query_name() + " fades into view.\n");

   owner = 0;
   command("look", this_player());

   destruct(this_object());
   return 1;
}

look_see(str) 
{
   object ob;
   string tmp,fintmp;
   ob = first_inventory(environment(this_object()));
   if(!str) {
      environment(this_object())->long();
      while(ob) 
      {
         if(ob->short() && ob != this_object()) write(ob->short() + ".\n");
         ob = next_inventory(ob);
      }
   } else {
      sscanf(str, "at %s", tmp);
      if(!tmp) tmp = str;
      ob = present(tmp, environment(this_object()));
      if(!ob) {
         write("There is no " + tmp + " here.\n");
         return 1;
        }
      ob->long();
   }
   return 1;
}

