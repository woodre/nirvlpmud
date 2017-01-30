
**Howdy** get pie from bag
survey_area() 
{
   object room,temproom;
   string exits,tempg,temph,tempi;
   int i;

   if(check_dead()) return 1;
   if(!check_level(2)) return 1;
   if(!check_sp(SURVEY_COST)) return 1;
   
   room = environment(this_player());
   exits = room->query_dest_dir();
   
   if(!exits)
   {
      write("For some reason, you cannot survey this area.\n");
      return 1;
   }
   
   this_player()->add_spell_point(-SURVEY_COST);
   
   if(room->realm() == "NT" && 1 == random(3 + this_player()->query_guild_rank()))
   {
      write("You attempt to survey the area, but are suddenly distracted, and fail.\n");
      return 1;
   }
   
   write("You peer about intently.\n\n");
   remote_say((this_player()->query_name()) + " surveys the area carefully.\n");
   temph = environment(this_player())->short();
   
   if(temph && sscanf(temph, "Plane of Etherie%s", tempi) == 1) 
   {
      /* we are inside the jello. The room system is a bit different here. */
      while(i < sizeof(exits)) 
      {
         temproom = find_object("/players/mizan/etheriel/ROOMS/" + exits[i]);
         if(temproom) 
         {
            tempg = dump_inventory(temproom);
            if(tempg)
               write("Scanning " + exits[i] + " you find:\n" + tempg);
            else 
               write("Scanning " + exits[i] + " find nothing.\n");
         }
         else 
            write("Scanning towards " + exits[i] + " you find it is unexplored.\n");

         i++;
      }
      return 1;
   } 
   else 
   {
      i = 1;
      while(i < sizeof(exits)) 
      {
         temproom = find_object(exits[i-1]);
         if(temproom) 
         {
            tempg = dump_inventory(temproom);
            if(tempg) write("Looking " + exits[i] + " you find:\n" + tempg);
            else write("Looking " + exits[i] + " find nothing.\n");
         }
         else write("Looking " + exits[i] + " you find it is unexplored.\n");
         i = i + 2;
      }
      return 1;
   }
}

/* used by above */

static dump_inventory(arg) 
{
   object ob;
   string tempj;
   int lim;
   tempj = "";
   ob = first_inventory(arg);
   while(ob) {
      object oc;
      oc = ob;
      ob = next_inventory(ob);
      if(oc->short()) tempj = tempj + "\t" + (oc->short()) + ".\n";
      
      lim ++;
      if(lim > 12) {
         tempj = tempj + "\t[TRUNCATED]\n";
         break;
         }
   }
   return tempj;
}
