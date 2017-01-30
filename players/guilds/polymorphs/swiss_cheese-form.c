inherit "obj/monster";
object owner;
string owner_name;

reset(arg) {
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   set_name("A giant wheel of Swiss cheese");
   set_race("cheese");
   set_alias("wheel");
   set_short("A giant wheel of Swiss cheese");
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
   if(owner) 
   {
      return "A giant wheel of Swiss cheese";
   } else return "A giant wheel of Swiss cheese (disconnected)";
}

is_puffer() { return 1; }

long() {
   object ob;
   ob = first_inventory(this_object());
   write("Before you is a giant wheel of Swiss cheese. Holy cow!\n"+
      "It looks like you can eat from it, but in order to do so you must have\n"+
      "the proper eating utensil... a plastic butter knife. Perhaps you can actually\n"+
      "ask this giant wheel of cheese for a butter knife with the command 'ask knife'.\n"+
      "\tA giant wheel of Swiss cheese is carrying:\n");
   write("A bag of plastic knives.\n");
   while(ob) {
      if(!ob->is_player() && ob->short()) write(ob->short() + ".\n");
      ob = next_inventory(ob);
   }
   return 1;
}

can_put_and_get() { return 0; }

move_player(dir_dest) {
   object oldroom;
   string destroom,filename;
   if(!dir_dest || sscanf(dir_dest, "%s#%s", destroom, filename) != 2) return 0;
   oldroom = environment(this_object());
   tell_room(filename, "A wheel of cheese arrives.\n");
   move_object(this_object(), filename);
   tell_room(oldroom, "A wheel of cheese leaves rolling " + destroom + ".\n");
   if(owner) command("look", owner);
}

second_life() { return 1; }
query_hp() { return 20; }
query_mhp() { return 20; }
hit_player() { return 1; }


attack_object() {
  if(owner) environment(owner)->run_away();
  return 1;
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
      add_action("mod_say","say");
      add_action("block",";");
      add_action("block","'");
      add_action("block","\"");
      add_action("revert","revert");
      add_action("on_allow", "allow");
      add_action("xcatch"); add_xverb("");
   }
   else
   {
      add_action("on_cut", "cut");
      add_action("on_ask", "ask");
   }
   ::init();
}

on_cut(str)
{
    if(!str || str != "cheese") return;

    if(!present("cheese knife", this_player()))
    {
        write("You do not have the proper utensil to cut this cheese with. Sorry.\n");
        return 1;
    }

    say(this_player()->query_name() + " hacks off a chunk of Swiss cheese and gobbles it ferociously!\n");

    write("You cut some cheese and gobble an entire chunk whole!\n");
    return 1;
}

on_ask(str)
{
    if(!str || str != "knife") return;

    say(this_player()->query_name() + " says: I-i-i-i-i want a knife.... please.\n");

    tell_room(this_object(), this_player()->query_name() + " has asked for a plastic cheese knife.\n"+
        "To allow " + this_player()->query_name() + " a knife, give the command 'allow " + this_player()->query_name() + "'.\n");

    return 1;
}

on_allow(str)
{
    object knife;
    object ob;

    if(!str) return;

    ob = present(str, environment(this_object()));

    if(!ob)
    {
        write("There are no players here named " + str + ".\n");
        return 1;
    }

    if(!living(ob))
    {
        write("The '" + str + "' is not a living thing.\n");
        return 1;
    }

    if(!ob->is_player())
    {
        write("That unfortunately is not a player.\n");
        return 1;
    }

    if(ob->query_invis() > this_player()->query_level()) return 0;

    knife = clone_object("/players/mizan/closed/poly/swiss_cheese-knife.c");

    move_object(knife, ob);
    
    tell_room(environment(this_object()), "A giant wheel of Swiss cheese gives a plastic knife to " + ob->query_name() + ".\n");
    write("Done.\n");
    tell_object(ob, "You have been given a plastic cheese knife. You may eat some cheese if in\n"+
                "the same room as the wheel with the command 'cut cheese'. Yup, that's right :)\n");

    return 1;

}

mod_say(str) 
{
  if(!str) 
  {
    write("Say what?\n");
    return 1;
  }
  tell_room(environment(this_object()),
    "A giant wheel of Swiss cheese says: " + str + "\n");
    return 1;
}

block() {
   write("You fail as a wheel of cheese.\n");
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

revert() 
{
   owner = 0;
   move_object(this_player(), environment(this_object()));
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

