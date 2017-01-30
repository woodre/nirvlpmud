#include "/players/mizan/esc.h"
#include "definitions.h"

#define INVITE_OBJECT "/players/mizan/closed/poly/spuckmobile-invite.c"

inherit "obj/monster";

object owner;
object sofa;
object catapult;
string owner_name;

status listen_tl;

reset(arg) 
{
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   set_name("spuckmobile");
   set_race("spuckmobile");
   set_alias("spuckmobile");
   set_short("A Spuckmobile");
   set_level(7);
   set_hp(200000);
   set_al(130);
   set_ac(6);
   set_wc(0);

   sofa = clone_object("/players/mizan/closed/poly/treehouse-sofa");
   move_object(sofa, this_object());

   catapult = clone_object("/players/mizan/closed/poly/guild-catapult");
   move_object(catapult, this_object());

   listen_tl = 1;
      
   call_out("fake_beat", 1);
}

realm() { return "NT"; }
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
   if(owner)
   {
      return ("A Spuckmobile [" + (owner->query_name()) + "]");
   }
    else return ("A Spuckmobile [" + (owner->query_name()) + "]");
}

long()
{
   if(this_player() && environment(this_player()) && environment(this_player()) == this_object())
   {
      /* inside the treehouse */
      write("You are inside a treehouse. This is a very quaint, old-school treehouse\n"+
            "that brings back fond memories of childhood. It has uneven wooden plank floors,\n"+
            "a good view for hitting things below, and even a little paper sign hanging that\n"+
            "says: 'NO GIRLS ALLOWED'. To look down on the ground, you can 'look down'.\n"+
            "You can also talk to the people below by 'yell <msg>' at them.\n"+
            "   There is one obvious exist: down.\n");
      if(this_player() == owner)
      {
         if(listen_tl) write(">> You currently have 'ptoggle listen' [ENABLED].\n");
         else write(">> You currently have 'ptoggle listen' [DISABLED].\n");
           
      }
   }
   else
   {
      /* outside the treehouse */
      write("You see a big oak tree, with a treehouse halfway up its branches. The house\n"+
            "itself seems nestled securely within, and looks very inviting. There appear\n"+
            "people inside the treehouse, and if you talk to them by 'yell <message>'\n"+
            "they will hear you and might be able to let you climb up.\n");
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
   if(owner_name) {
      if(!owner) owner = find_player(owner_name);
      if(!owner) destruct(this_object());
      if(owner) move_object(owner, this_object());
/*
      if(owner && environment(owner) != this_object()) move_object(owner, this_object());
 */
   }
   remove_call_out("fake_beat");
   call_out("fake_beat", 1);
}

set_owner(a) { owner_name = a; }

catch_tell(str) 
{
   if(str && str != "What?\n")
      if(owner && listen_tl)
      {
         if(this_player() && environment(this_player()) &&
            environment(this_player()) != this_object())
            tell_object(owner, "From below: " + str);
      }
   return 1;
}

init() {
   /* Owner Only */
   if(owner && this_player() && this_player() == owner) 
   {
      add_action("revert","revert");
      add_action("treehouse_invite","invite");
      add_action("treehouse_expel","expel");
      add_action("treehouse_ptoggle","ptoggle");
   }

   /* Other people inside but NOT the owner */
   if(owner && this_player() && 
      environment(this_player()) == this_object() &&
      this_player() != owner)
   {
      add_action("treehouse_descend","descend");
      add_action("treehouse_descend","down");
      add_action("treehouse_descend","d");
   }
   
   /* Other people who my be INSIDE including OWNER*/
   if(owner && this_player() && environment(this_player()) == this_object())
   {
      add_action("treehouse_out_say","yell");
      add_action("look_see","look");
      add_action("look_see","l");
      add_action("block","note");
      add_action("block","Np");
      add_action("block","get");
      add_action("block","put");
      add_action("block","kill");
      add_action("block",";");
      add_action("block","'");
      add_action("block","\"");
   }
   else
   {

   /* Everyone else outside only can do these */
      add_action("outside_yell","yell");
   }
   ::init();
}

block() 
{
   write("You can't do that here.\n");
   return 1;
}

/* todo - properly dump all objects out */
revert() 
{
   object ob;
   int i;
   
   owner = 0;
   say("The treehouse is melting!\n");
   
   if(sofa) destruct(sofa);
   if(catapult) destruct(catapult);

   ob = all_inventory(this_object());
   for(i = 0; i < sizeof(ob); i ++)
   {
     if(ob[i]->short()) say(ob[i]->short() + " falls out of the treehouse!\n");
   }
   
   move_object(this_player(), environment(this_object()));

   destruct(this_object());
   return 0;
}

treehouse_ptoggle(str)
{
  if(!str)
  {
      write("\n>> Toggle settings: --------------<<\n\n");
      write("  listen\t");
      if(listen_tl) write("ENABLED\n"); else write("MUFFLED\n");
      write(">>--------------------------------<<\n");

      return 1;
  }
  else
  {
     listen_tl = !listen_tl;
     if(listen_tl)
        write("Listening to outside environment messages ENABLED.\n");
     else
        write("Listening to outside environment messages MUFFLED.\n");
     return 1;
  }
  
}

treehouse_invite(str)
{
   object ob, oc;
   
   if(!str)
   {
      write("Invite who?\n");
      return 1;
   }
   
   ob = present(str, environment(this_object()));
   
   if(!ob)
   {
      write("There is no '" + str + "' here.\n");
      return 1;
   }

   if(!living(ob) || !ob->is_player())
   {
      write("You cannot invite " + lower_case(ob->short()) + ".\n");
      return 1;
   }
   
   oc = clone_object(INVITE_OBJECT);

   say("An acorn plops onto " + ob->query_name() + "'s head.\n");   
   write("You have invited " + ob->query_name() + ".\n");
   
   oc->set_treehouse(this_object());
   oc->set_invitee(this_player()->query_name());
   move_object(oc, ob);
   tell_object(ob, "You have received an acorn invitation to " + owner->query_name() + "'s treehouse.\n"+
      "You can either 'climb_tree' to accept the invitation or 'discard' it.\n");
   return 1;
}

treehouse_expel(str)
{
   object ob;
   
   if(!str)
   {
      write("Expel who?\n");
      return 1;
   }
   
   ob = present(str, this_object());
   if(!ob)
   {
      write("There is no '" + str + "' here.\n");
      return 1;
   }
   if(!living(ob))
   {
      write("You cannot do that.\n");
      return 1;
   }
   
   write("You break loose and punt " + ob->query_name() + " out of the treehouse!\n");
   tell_room(this_object(), "You see " + ob->query_name() + " punted clear out of the treehouse!\n");
   tell_room(environment(this_object()), ob->query_name() + " arrives crashing into the ground, punted out of the treehouse!\n");
   tell_object(ob, "You are punted out of the treehouse!\nYou crash into the ground with a sickening THUD!\n");
   move_object(ob, environment(this_object()));
   command("look", ob);
   return 1;
}

treehouse_descend()
{
   write("You descend from the treehouse onto the room below.\n");
   tell_room(this_object(), this_player()->query_name() + " leaves climbing down.\n");
   tell_room(environment(this_object()), this_player()->query_name() + " arrives descending from " + owner->query_name() + "'s treehouse.\n");
   move_object(this_player(), environment(this_object()));
   return 1;
}

look_see(str) 
{
  if(this_player())
  {
     if(environment(this_player()) == this_object())
     {
        /* we are INSIDE */
        if(!str) return look_inside();
        else if(str && str == "down") return look_outside();
        else return 0;
     }
     else return 0;
  }
}

look_inside()
{
   object ob;
   string tmp,fintmp;
   ob = first_inventory(this_object());
   this_object()->long();
   while(ob) 
   {
       if(ob->short() && ob != this_object() && ob != this_player()) write(ob->short() + ".\n");
       ob = next_inventory(ob);
   }
   return 1;
}

look_outside()
{
   object ob;
   string tmp,fintmp;
   ob = first_inventory(environment(this_object()));
   tell_room(this_object(), this_player()->query_name() + " peers " + this_player()->query_possessive()+ " head out, looking down below.\n");
   say(this_player()->query_name() + " pops " + this_player()->query_possessive()+ " head out of the treehouse, peering at you from above.\n");
   environment(this_object())->long();
   while(ob) 
   {
       if(ob->short() && ob != this_object()) write(ob->short() + ".\n");
       ob = next_inventory(ob);
   }
   return 1;
}

outside_yell(str)
{
   if(!str)
   {
       write("Yell what?\n");
       return 1;
   }
  
   write("You yell up to the treehouse: " + str + "\n");
   tell_room(this_object(), this_player()->query_name() + " yells from below: " + str + "\n");
   return 1;
}

treehouse_say(str) 
{
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  say("A treehouse that looks somewhat like " + (this_player()->query_name()) + " says: " + str + "\n");
  tell_room(this_object(), owner->query_name() + " says something to the room down below.\n");
    return 1;
}

treehouse_out_say(str) 
{
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  tell_room(this_object(), (this_player()->query_name()) + " yells to down below: " + str + "\n");
  tell_room(environment(this_object()), this_player()->query_name() + " yells from above: " + str + "\n");
  return 1;
}
