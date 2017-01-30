#include "/players/mizan/esc.h"
#include "definitions.h"

inherit "obj/monster";

object owner;
string owner_name;
string new_body;
string desc_body;
int body_lines;

reset(arg) 
{
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   set_name("foldspace");
   set_race("portal");
   set_alias("space");
   set_short("A foldspace portal");
   set_level(7);
   set_hp(200000);
   set_al(130);
   set_ac(6);
   set_wc(0);


   call_out("slow_reset", 1);      
   call_out("fake_beat", 1);
}

realm() { return "NT"; }
query_realm() { return "NT"; }
is_player() { return 1; }
query_guild_name() { return "polymorph"; }
query_mizan_shell() { return 1; }
is_puffer() { return 1; }
second_life() { return 1; }
query_hp() { return 20; }
query_mhp() { return 20; }
hit_player() { return 1; }
can_put_and_get() { return 0; }

short() 
{
   return "A foldspace portal (" + capitalize(owner_name) + ")";
}

long()
{
   if(this_player() && environment(this_player()) && environment(this_player()) == this_object())
   {
      /* inside the treehouse */
      write("  You are inside a break of foldspace, halfway between that of the \n"+
            "  'normal' world and the ever-familiar Plane of Etheriel. Looking and\n"+
            "  feeling vaguely similar, you sense that the area that you are in is\n"+
            "  an oasis of rest and recovery. It however would not be a good idea\n"+
            "  to leave things here in this temporary rift, lest they be consumed.\n"+
            "   There is one obvious exit: out.\n");

   }
   else
   {
      /* outside the treehouse */
      write("You see a strange fold in space and time. While it is not fully open, you\n"+
            "can discern the shape of " + capitalize(owner_name) + " inside.\n");
   }

   return 1;
}

move_player(dir_dest) 
{
   write("Nothing happens.\n");
   return 1; 
}

attack() 
{
  return 1;
}

attack_object()
{
  ::attack_object();
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
      if(!owner)
      {
         destruct(this_object());
      }
      
      if(owner) move_object(owner, this_object());
   }
   random_emote();
   
   remove_call_out("fake_beat");
   call_out("fake_beat", 1);
}

random_emote()
{
   if(1 == random(160))
   {
      tell_room(this_object(), "A low pressure wave slowly collides into you.\n");
   }
   else if(1 == random(160))
   {
      tell_room(this_object(), "The muffled thumping of the foldspace soothes your nerves.\n");
   }
   else if(1 == random(160))
   {
      tell_room(this_object(), "You hear a 'thump... thump... thump...' as the foldspace beats around you.\n");
   }
}

set_owner(a) { owner_name = a; }


init() 
{
   /* Owner Only */
   if(owner && this_player() && this_player() == owner) 
   {
      add_action("revert","revert");
      add_action("decloak","out");
   }

   /* Other people who my be INSIDE including OWNER*/
   if(owner && this_player() && environment(this_player()) == this_object())
   {
      add_action("block","kill");
      add_action("block","say");
      add_action("block","'");
      add_action("block","converse");
      add_action("block",";");
      add_action("block","'");
      add_action("block","\"");
   }

   ::init();
}

block() 
{
   write("You can't do that here.\n");
   return 1;
}

/* todo - properly dump all objects out */
revert(arg) 
{
   object oc;
   object ob;
   int i;
   
   if(arg) oc = arg;
   else oc = this_player();
   
   owner = 0;
   say("The foldspace is collapsing!\n");
   
   ob = all_inventory(this_object());
   for(i = 0; i < sizeof(ob); i ++)
   {
      if(ob[i]->short()) say(ob[i]->short() + " falls out of the foldspace!\n");
   }
   
   move_object(oc, environment(this_object()));

   destruct(this_object());
   return 0;
}

decloak() 
{
   move_object(this_player(), environment(this_object()));
   
   write("You exit the foldspace and fade into view.\n");
   say("A foldspace portal collapses!\n");
   say(owner->query_name() + " fades into view.\n");
   command("look", this_player());

   owner = 0;
   destruct(this_object());
   return 1;
}
