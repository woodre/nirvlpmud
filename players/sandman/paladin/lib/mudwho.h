
/*
 * MUD WHO COMMANDS (4/20/94)
 *     nice_time() -  Converts age to days, hours, minutes, seconds
 *     who2()      -  New 'who': shows lvl, name, guild (if any)
 */     

nice_time(i) {
   string nicetime;
   nicetime = "";
   if(i/43200) {
      nicetime += i/43200+" days ";
      i = i-(i/43200)*43200;
   }
   if(i/1800) {
      nicetime += i/1800+" hours ";
      i = i-(i/1800)*1800;
   }
   if(i/30) {
      nicetime +=i/30+" minutes ";
      i = i-(i/30)*30;
   }
   nicetime += i*2+" seconds.";
   return nicetime;
}

who2() {
   object list, new_list;
   int i, counter, num, tp_lvl;
   
   list = users();
   write("\n");
   num = 0;
   tp_lvl = this_player()->query_level();
   new_list = ({ });
   for(i=0; i < sizeof(list); i++)
     if(!list[i]->query_invis() || list[i]->query_level() <= tp_lvl) {
       num += 1;
       new_list += ({ list[i] });
     }
   if(previous_object()->query_color())
     write(HIB);
   write("Nirvana: "+num+" users logged on.  Time: "+ctime(time())+"\n");
   write("[==============================================================="+
         "==============]\n");
   write(justify("Level:", 9)+justify("Name:", 14)+justify("Guild:",13));
   write(justify(" ",5));
   write(justify("Level:", 9)+justify("Name:", 14)+justify("Guild:",13));
   write("\n");
   write(justify("------", 9)+justify("-----", 14)+justify("------",13));
   write(justify(" ",5));
   write(justify("------", 9)+justify("-----", 14)+justify("------",13)); 
   write("\n");
   if(previous_object()->query_color())
     write(NORM);
   counter = 0;
   for(i=0; i< sizeof(new_list); i++) {              /* for each player */
      string name, gname;
      int lvl;
      counter += 1;
      gname = new_list[i]->query_guild_name();
      if(!gname) gname = "no guild";
      gname = capitalize(gname);
      name = new_list[i]->query_name();
      if(new_list[i]->query_invis())
        name = "#"+capitalize(new_list[i]->query_real_name());
      lvl = new_list[i]->query_level();
      if(lvl > 20) lvl = "WIZ";
      write(justify(lvl, 9)+justify(name, 14)+ justify(gname, 13));
      if(counter == 2) {
        write("\n");
        counter = 0;
      } else
        write(justify(" ",5));
   }
   if(counter == 1)
     write("\n");
   write(filter_color("[==================================================="+
        "==========================]\n",HIB));
   return 1;
}
