int light_level;

restore_lighting()
{
   while((int)this_object()->query_light() != 1)
   {
      if((int)this_object()->query_light() > 1) set_light(-1);
      if((int)this_object()->query_light() < 1) set_light(1);
   }
   set_light(light_level);
}

string get_clan_name()
{
   string *tmp, *tmp2;
   
   tmp = explode(TOP_DIR,"/");
   tmp -= ({ "" });
   tmp2 = explode("/" + file_name(this_object()),"/");
   tmp2 -= ({ "" });
   if(sizeof(tmp)+1 > sizeof(tmp2)) return "";
   return tmp2[sizeof(tmp)];
}

void save_me()
{
   string here, tmp, *tmp2;
   if( (int) call_other( this_object(), "query_cost" )  == 250000 )
     no_clean = 1;
   here = file_name(this_object());
   if(sscanf(here,"%s#%s",here,tmp) == 2);
   tmp2 = explode(here,"/");
   save_object(extract(TOP_DIR,1) + get_clan_name() + "/hall/saves/" + tmp2[sizeof(tmp2)-1]);
}

int restore_me()
{
   int ret;
   string here, tmp, *tmp2;
   here = file_name(this_object());
   if(sscanf(here,"%s#%s",here,tmp) == 2);
   tmp2 = explode(here,"/");
   ret = restore_object(extract(TOP_DIR,1) + get_clan_name() + "/hall/saves/" + tmp2[sizeof(tmp2)-1]);
   if( (int) call_other( this_object(), "query_cost" )  == 250000 )
     no_clean = 1;
   return ret;
}

string get_reverse_dir(string str)
{
   if(str == "north") return "south";
   if(str == "south") return "north";
   if(str == "east") return "west";
   if(str == "west") return "east";
   if(str == "up") return "down";
   if(str == "down") return "up";
   if(str == "northwest") return "southeast";
   if(str == "southwest") return "northeast";
   if(str == "northeast") return "southwest";
   if(str == "southeast") return "northwest";
   return "";
}

int room_long()
{
   object long_builder;
   if(!C_OBJ)
      {
      write("Error! Missing clan object.\n");
      return 1;
   }
   
   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   long_builder = clone_object(TOP_DIR + "obj/room_long_builder");
   long_builder->start_long();
   return 1;
}

int room_short(string str)
{
   
   if(!C_OBJ && !"/bin/play/_update_clan"->cmd_update_clan())
      {
      write("No clan or missing object. Moving to green.\n");
      move_object(TP,"/room/vill_green");
      return 1;
   }
   
   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   
   if(!str)
      {
      write("Set the short description to what?\n");
      return 1;
   }
   
   str = (string)call_other(TOP_DIR + "funcs","modify_spell_message",str, this_player());
   write("Short description set to: " + str + "\n");
   set_short(str);
   save_me();
   return 1;
}

int build_room(string str)
{
   string dir, type, *files, *types;
   int cost, x;
   object tmp, *stuff;
   
#ifdef __LDMUD__
      write("This command is not available on LD.\n"+
      "You may build a room on the live port, then exit and re-enter\n"+
      "this room if you wish to add rooms.\n");
   return 1;
#endif
      if(!C_OBJ && !"/bin/play/_update_clan"->cmd_update_clan())
      {
      write("No clan or missing object. Moving to green.\n");
      move_object(TP,"/room/vill_green");
      return 1;
   }
   
   if(!C_OBJ->query_leader(TP->query_real_name())) return 0;
   files = get_dir(TOP_DIR + "hall_rooms/templates/");
   types = ({ });
   for(x = 0; x < sizeof(files); x++)
   {
      if(file_size(TOP_DIR + "hall_rooms/templates/" + files[x]) > 1)
         {
         cost = (int)call_other(TOP_DIR + "hall_rooms/templates/" + files[x],"query_cost");
         if(cost != 0)
            types += ({ extract(files[x],0,strlen(files[x])-3) });
       }
   }
   
   if(!str || sscanf(str,"%s %s",dir,type) != 2)
      {
      write("Syntax: build_room [direction] [type].\n"+
         "'Type' may be one of the following:\n");
      for(x = 0; x < sizeof(types); x++)
      write("  " + types[x] + ", " + call_other(TOP_DIR + "hall_rooms/templates/" + types[x],"query_cost") + " coins.\n");
      return 1;
   }
   x = member(types,type);
   if(x == -1)
      {
      write("Syntax: build_room [direction] [type].\n"+
         "'Type' may be one of the following:\n");
      for(x = 0; x < sizeof(types); x++)
      write("  " + types[x] + ", " + call_other(TOP_DIR + "hall_rooms/templates/" + types[x],"query_cost") + " coins.\n");
      return 1;
   }
   
   if(dir != "north" && dir != "south" && dir != "east" && dir != "west" && dir != "up" && dir != "down" && dir != "northwest" && dir != "southwest" && dir != "northeast" && dir != "southeast")
      {
      write("Direction must be one of north, south, east, west, up, down, northwest, southwest, northeast, or southeast.\n");
      return 1;
   }
   
   cost = (int)call_other(TOP_DIR + "hall_rooms/templates/" + types[x],"query_cost");
   types = query_dest_dir();
   if(types && member(types,dir) != -1)
      {
      write("There is already an exit in that direction.\n");
      return 1;
   }
   if((int)C_OBJ->query_private_coffer() < cost)
      {
      write("Your clan is too poor for that!\n");
      return 1;
   }
   
   x = 1;
   while(file_size(TOP_DIR + get_clan_name() + "/hall/r" + x + ".c") > 1)
   x++;
   C_OBJ->add_private_coffer(-cost);
#ifndef __LDMUD__
   cp(TOP_DIR + "hall_rooms/templates/" + type + ".c",TOP_DIR + get_clan_name() + "/hall/r" + x + ".c");
#else
   copy_file(TOP_DIR + "hall_rooms/templates/" + type + ".c",TOP_DIR + get_clan_name() + "/hall/r" + x + ".c");
#endif
   this_object()->add_exit(TOP_DIR + get_clan_name() + "/hall/r" + x,dir);
   save_me();
   tmp = find_object(TOP_DIR + get_clan_name() + "/hall/r" + x);
   if(tmp)
      destruct(tmp);
   tmp = clone_object(TOP_DIR + get_clan_name() + "/hall/r" + x);
   tmp->add_exit("/" + file_name(this_object()),get_reverse_dir(dir));
   tmp->save_me();
   destruct(tmp);
   call_other(TOP_DIR + get_clan_name() + "/hall/r" + x,"???");
   write("You build a '" + type + "' room in direction '" + dir + "'.\n");
   stuff = all_inventory(this_object());
   move_object(this_player(),TOP_DIR + get_clan_name() + "/hall/r" + x);
   for(x = 0; x < sizeof(stuff); x++)
   move_object(stuff[x],this_object());
   
   return 1;
}

int room_light(string str)
{
   if(!C_OBJ && !"/bin/play/_update_clan"->cmd_update_clan())
      {
      write("No clan or missing object. Moving to green.\n");
      move_object(TP,"/room/vill_green");
      return 1;
   }
   
   if(str != "up" && str != "down")
      {
      write("You may turn the lighting 'up' or 'down'.\n");
      return 1;
   }
   
   if(str == "up")
      {
      set_light(1);
      light_level += 1;
      write("You turn the lights up.\n");
      say(TP->query_name() + " turns the lights up.\n");
      save_me();
      return 1;
   }
   
   set_light(-1);
   light_level -= 1;
   write("You turn the lights down.\n");
   say(TP->query_name() + " turns the lights down.\n");
   save_me();
   return 1;
}

int check_valid_entry()
{
   if(TP->is_player())
      {
      if(!C_OBJ && !"/bin/play/_update_clan"->cmd_update_clan())
         {
         write("No clan. Moving to green.\n");
         move_object(TP,"/room/vill_green");
         return 0;
      }
      
      restore_me();
      restore_lighting();
      if((string)CNAME != get_clan_name())
         {
         write("Not a member of clan. Moving to green.\n");
         move_object(TP,"/room/vill_green");
         return 0;
      }
      
      if((int)this_object()->query_owner_room() == 1 && C_OBJ->query_owner() != TP->query_real_name())
         {
         write("Clan owner only.\n");
         move_object(TP,TOP_DIR + get_clan_name() + "/hall/main");
         return 0;
      }
      
      if((int)this_object()->query_leader_room() == 1 && !C_OBJ->query_leader(TP->query_real_name()))
         {
         write("Clan leaders only.\n");
         move_object(TP,TOP_DIR + get_clan_name() + "/hall/main");
         return 0;
      }
      
      add_action("build_room","build_room");
      add_action("room_short","room_short");
      add_action("room_long","room_long");
      add_action("room_light","room_light");
      return 1;
   }
}

exit() {
   
   restore_lighting();
   
}

query_sandstorm() { return 1; }

#ifdef __LDMUD__

mixed deletea(mixed a, int start, int end) {
    return a[0..start-1] + a[end+1..];
}

#endif
