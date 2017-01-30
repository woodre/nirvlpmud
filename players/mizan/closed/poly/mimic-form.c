inherit "obj/monster";
#include "/players/mizan/esc.h"
#include "definitions.h"

/* The desc of the object we are trying to mimic */
string mimic_short;
string mimic_long;

object owner;
string owner_name;

reset(arg)
{
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   mimic_short = "A mimic";
   mimic_long = "Nothing.\n";
   
   set_name("mimic");
   set_race("mimic");
   set_alias("mimic");
   set_short("A mimic");
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

short() 
{
   if(owner) 
   {
      if(this_player() && this_player()->query_level() > 19)
      return mimic_short + " [POLYMORPH MIMIC]";
      else return mimic_short;
   }
   else return mimic_short + " (disconnected)";
}

is_puffer() { return 1; }

long() {
   object ob;
   ob = first_inventory(this_object());
   write("This appears to be a very convincing copy of " + lower_case(mimic_short) + ".\n");

   while(ob) {
      if(!ob->is_player() && ob->short()) write(ob->short() + ".\n");
      ob = next_inventory(ob);
   }
   return 1;
}

can_put_and_get() { return 0; }

move_player(dir_dest) 
{
   object oldroom;
   string destroom,filename;
   if(!dir_dest || sscanf(dir_dest, "%s#%s", destroom, filename) != 2) return 0;
   oldroom = environment(this_object());
   tell_room(filename, mimic_short + " arrives.\n");
   move_object(this_object(), filename);
   tell_room(oldroom, mimic_short + " leaves " + destroom + ".\n");
   if(owner) command("look", owner);
}

second_life() { return 1; }
query_hp() { return 20; }
query_mhp() { return 20; }
attack() {  return 1; }
attack_object() { ::attack_object(); }
hit_player() { return 1; }

fake_beat() 
{

   /* We want to give ourselves away a little bit sometimes */
   if(1 == random(120) && mimic_short != "A mimic")
   {
     if(owner) tell_object(owner, "You wiggle a little bit.\n");
     tell_room(environment(this_object()), mimic_short + " wiggles ever so slightly.\n");
   }
   else if(1 == random(120) && mimic_short != "A mimic")
   {
     if(owner) tell_object(owner, "You twich a little from the strain.\n");
     tell_room(environment(this_object()), mimic_short + " twitches a little bit.\n");
   }


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
      if(owner)
      tell_object(owner, str);
   return 1;
}

init() {
   if(owner && this_player() && this_player() == owner)
    {
      add_action("mimic_logview","mimic_log");
      add_action("mimic_imitate","imitate");
      add_action("mimic_imitate","mimic");
      add_action("look_see","look");
      add_action("look_see","l");
      add_action("block","note");
      add_action("block","Np");
      add_action("block","get");
      add_action("block","put");
      add_action("block","kill");
      add_action("mimic_say","say");
      add_action("block",";");
      add_action("block","'");
      add_action("block","\"");
      add_action("block","drop");
      add_action("revert","revert");
#ifndef __LDMUD__
add_action("xcatch"); add_xverb("");
#else
add_action("xcatch", "", 3);
#endif
   }
   ::init();
}

mimic_logview()
{
  write("Here is a listing of what other people have mimicked lately:\n\n");
  tail("/players/mizan/logs/POLY_MIMIC_SIMPLE");
  return 1;
}

mimic_say(str)
{
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  tell_room(environment(this_object()),
    mimic_short + " says: " + str + "\n");
    return 1;
}

block() 
{
   write("You fail as a mimic.\n");
   return 1;
}

xcatch(str) 
{
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

/** mimic stuff */
mimic_imitate(str)
{
  object ob, room;
  room = environment(this_object());
  if(!room) return 0;

  if(this_player()->query_sp() < 30)
  {
    write("You do not have enough spellpoints to do this.\n");
    return 1;
  }
  
  if(!str)
  {
    write("Mimic what object?\n");
    return 1;
  }
  
  ob = present(str, room);
  if(!ob) ob = present(str, this_player());
  /* no invisible objects */
  if(!ob || !ob->short())
  {
    write("There is no object named '" + str + "' nearby to mimic.\n");
    return 1;
  }
  
  /* no players */
  if(ob->is_player())
  {
    write("Sorry, but you cannot imitate players.\n");
    return 1;
  }

  /* no invisible shit */  
  if(!ob->short())
  {
    write("You cannot mimic that, for some reason.\n");
    return 1;
  }
  
 
  write("You adjust and shimmer into the form of '" + ob->short() + "'!\n");
  tell_room(room, mimic_short + " shimmers and takes the form of '" + ob->short() + "'!\n");
  
  this_player()->add_spell_point(-30);
  set_alias(str);
  set_name(ob->short() + ESC + "[0m");
  mimic_short = ob->short() + ESC + "[0m";
  
  /* Log this in case people are abusing mimic... */
  write_file(LOGPATH + "POLY_MIMIC",
         (this_player()->query_real_name()) + " mimicked alias '" +
         str + "', object '" + mimic_short + "' on " + ctime() + "\n");

  /* this one is for players to see */
  write_file(LOGPATH + "POLY_MIMIC_SIMPLE",
         (this_player()->query_name()) + " mimicked '" + mimic_short + "' at " + ctime() + "\n");
  
  return 1;
}



