inherit "obj/monster";
object owner;
string owner_name;

reset(arg) {
   object weapon,treasure;
   ::reset(arg);
   if(arg) return;
   set_name("pufferfish");
   set_race("pufferfish");
   set_alias("fish");
   set_short("A pufferfish");
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
      return "A pufferfish";
   } else return "A pufferfish (disconnected)";
}

is_puffer() { return 1; }

long() {
   object ob;
   ob = first_inventory(this_object());
   write("Before you is an average spotted tropical pufferfish.\n"+
      "It looks relatively harmless, with its beady little eyes and\n"+
      "flimsy wavering fins, but the fact that it is rather poisonous\n"+
      "must be what keeps would-be predators away.\n"+
      "\tPufferfish is carrying:\n");
   write("Fish guts.\n");
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
   tell_room(filename, "A pufferfish arrives.\n");
   move_object(this_object(), filename);
   tell_room(oldroom, "A pufferfish leaves " + destroom + ".\n");
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
      add_action("bubble","say");
      add_action("block",";");
      add_action("block","'");
      add_action("block","\"");
      add_action("revert","revert");
      add_action("xcatch"); add_xverb("");
   }
   ::init();
}

bubble(str) {
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  tell_room(environment(this_object()),
    "A pufferfish named " + (this_player()->query_name()) + " says: " + str + "\n");
    return 1;
}

block() {
   write("You fail as a puffer fish.\n");
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

revert() {
   owner = 0;
   move_object(this_player(), environment(this_object()));
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

