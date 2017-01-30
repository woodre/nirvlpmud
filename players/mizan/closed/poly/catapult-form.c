inherit "obj/monster";
#include "/obj/user/shout_only.c"

object thingo,target;
object owner;
string owner_name;

reset(arg) {
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   set_name("catapult");
   set_race("catapult");
   set_alias("pult");
   set_short("An Acme [tm] siege catapult");
   set_level(7);
   set_hp(200000);
   set_al(130);
   set_ac(6);
   set_wc(0);
   call_out("fake_beat", 1);
}

realm() { return "NT"; }
is_player() { return 1; }
query_guild_name() { return "polymorph"; }
query_mizan_shell() { return 1; }

short() {
   if(owner) {
      return "A portable Acme Siege Catapult [tm]";
   } else return "A portable Acme Siege Catapult [tm] (disconnected)";
}

is_puffer() { return 1; }

long() {
   object ob;
   ob = first_inventory(this_object());
   write("This is a complex looking wooden device on wheels that\n"+
   "is actually very simple to use. A big red sticker on it reads:\n\n"+
   "  Siege Catapult Model Number 10497SL, Acme Corp.\n"+
   "  To load this catapult with something type 'arm <object>'.\n"+
   "  To aim this catapult at someone type 'aim <playername>'.\n"+
   "  To fire the catapult type 'pull lever'.\n\n");

   if(thingo) write("The catapult is loaded with " + lower_case(thingo->short()) + ".\n");
      else write("The catapult is not loaded.\n");
   if(target) write("The catapult is currently pointed at " + (target->query_name()) + ".\n");
      else write("The catapult is not pointed at anyone.\n");
  if(this_player() && this_player()->query_guild_name() == "polymorph")
    write("You can see who fired what recently with the command 'catapult history'.\n");

   return 1;
}

can_put_and_get() { return 0; }

move_player(dir_dest) {
   object oldroom;
   string destroom,filename;
   if(!dir_dest || sscanf(dir_dest, "%s#%s", destroom, filename) != 2) return 0;
   oldroom = environment(this_object());
   tell_room(filename, "A catapult slowly arrives.\n");
   move_object(this_object(), filename);
   tell_room(oldroom, "A catapult rumbles slowly leaves " + destroom + ".\n");
   if(owner) command("look", owner);
}

second_life() { return 1; }
query_hp() { return 20; }
query_mhp() { return 20; }
hit_player() { return 1; }


attack() {
  return 1;
}

attack_object()
{
  ::attack_object();
}

fake_beat() {

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

catch_tell(str) {
   if(str && str != "What?\n")
      if(owner)
      tell_object(owner, str);
   return 1;
}

init() {
   if(owner && this_player() && this_player() == owner) {
      add_action("look_see","look");
      add_action("look_see","l");
      add_action("block","note");
      add_action("block","Np");
      add_action("block","get");
      add_action("block","put");
      add_action("block","kill");
      add_action("catapult_say","say");
      add_action("block",";");
      add_action("block","'");
      add_action("block","drop");
      add_action("block","\"");
      add_action("revert","revert");
#ifndef __LDMUD__
add_action("xcatch"); add_xverb("");
#else
add_action("xcatch", "", 3);
#endif
   }

   /* everyone else can do these */
   add_action("arm","arm");
   add_action("aim","aim");
   add_action("pull_lever","pull");
   add_action("catapult","catapult");

   ::init();
}

catapult_say(str) {
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  tell_room(environment(this_object()),
    "A siege catapult named " + (this_player()->query_name()) + " says: " + str + "\n");
    return 1;
}

block() {
   write("You fail as a catapult.\n");
   return 1;
}

xcatch(str) {
   string tmp,tmp2;
   tmp = query_verb();
   if(tmp == " revert" || tmp == "revert") {
      revert();
      return 1;
   }
   if(str) tmp = tmp + " " + str;
   sscanf(tmp, " %s", tmp2);
   return command(tmp2, this_object());
}

revert(arg) 
{
   object ob;
   
   if(arg) ob = arg;
   else ob = this_player();
   
   owner = 0;
   move_object(ob, environment(this_object()));
   destruct(this_object());
   return 0;
}

look_see(str) {
   object ob;
   string tmp,fintmp;
   ob = first_inventory(environment(this_object()));
   if(!str) {
      environment(this_object())->long();
      while(ob) {
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

/* catapult abilities now */
arm(str) {
  object ob;
  int cost;
  if(!str) return 0;
  ob = present(str, this_player());
  if(thingo) {
    write("The catapult is already loaded.\n");
    return 1;
  }
/* it shouldnt happen but its here */
  if(ob == this_object()) {
    write("Doh. This shouldnt happen.\n");
    return 1;
  }
  if(!ob) {
    write("You have no such item.\n");
    return 1;

  }
  if(ob->query_value() < 450) {
    if(this_player()->query_hp() < 6) {
      write("You are too tired to arm the catapult!\n");
      return 1;
    }
  cost = 5;
  }
  if(this_player()->query_hp() < 30) {
    write("You are too tired to arm the catapult.\n");
    return 1;
  } else cost = 29;
  /* for wizzes */
  if(this_player()->query_level() < 21)
  if(!ob->get() || ob->drop()) {
    write("You cannot load the catapult with that.\n");
    return 1;

  }
  thingo = ob;
  if(!thingo) return 1;
  move_object(thingo, this_object());

  this_player()->add_weight(-thingo->query_weight());
  tell_room(environment(this_object()), (this_player()->query_name()) +
  " arms the catapult with " + lower_case(thingo->short()) + ".\n");
  this_player()->add_hit_point(-cost);
  return 1;
}


aim(str) {
  object ob;
  if(!str) return 0;
  if(!thingo) {
    write("You need to arm the catapult with something first.\n");
    return 1;
  }
  ob = find_player(str);
  if(str == "mizan") {
    write("Doh!\n");
    return 1;
  }
if(!ob || ob->query_invis() > 17)
   {
    write("There is no such player logged in.\n");
    return 1;
  }
  if(this_player()->query_level() < 20)
    if(ob->query_level() > 20) {
    write("Somehow, you think that would be very foolish.\n");
    return 1;
    }
  target = ob;
  tell_room(environment(this_object()), (this_player()->query_name()) +
    " aims the catapult at " + (target->query_name()) + ".\n");
  return 1;

}

pull_lever(str) {
  if(!str || str != "lever") return 0;
  if(!thingo) {
    write("The catapult is not loaded with anything.\n");
    return 1;
  }

  if(!target) {
    write("The catapult is not aimed at anyone.\n");
    return 1;
  }   
  tell_room(environment(this_object()), (this_player()->query_name()) +
  " pulls the lever and launches something into oblivion!\n");

  log_file("mizan.catapult", this_player()->query_name() + " hit " + target->query_name() + " with " + lower_case(thingo->short()) + ".\n");

  chan_msg((thingo->short()) + " rockets across the MUD and knocks " + (target->query_name()) + " to the ground!\n");
  tell_object(target, (thingo->short()) + " falls from nowhere and smacks you silly!\n");
  if(environment(target))
    tell_room(environment(target), "Something drops from the heavens and smashes " +
    (target->query_name()) + " squarely in the head!\n");
  if(environment(target))
  {
      move_object(thingo, environment(target));
      call_other(thingo, "on_explode", target);
  }
    else destruct(thingo);
  thingo = 0;
  target = 0;
  return 1;
}

catapult(str)
{
   if(this_player() && this_player()->query_guild_name() != "polymorph")
     return 0;

   if(str && str == "history")
   {
      write("\n>>Catapult Usage History--------------------------------------------------<<\n\n");
      tail("/log/mizan.catapult");
      return 1;
   }
   
   return 0;
}

