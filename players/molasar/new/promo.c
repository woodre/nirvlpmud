
/*
 * PROMO LIST (3/1/94)
 */

#define SAVEFILE "players/molasar/promo_data"

justify(str, len) { return extract(str+"                       ",0,len-1); }

string *castles;
string *guilds;
string *guild_names;

reset(arg) {
   if(!arg) 
     restore_object(SAVEFILE);
   if(!castles) castles = ({ });
   if(!guilds) guilds = ({ });
   if(!guild_names) guild_names = ({ });
}

add(str) {
   string who;

   if(this_player()->query_level() < 21)
     return 0;
   who = this_player()->query_real_name();
   if(str == "castle") {
     if(member_array(who, castles) != -1) { 
       write("Your name is already in the castle list!\n");
       return 1;
     }
     castles += ({ who });
     write("Your name is now in the castle list.\n");
     save_file();
     return 1;
   }
   if(str == "guild") {
     if(member_array(who, guilds) != -1) {
       write("Your name is already in the guild list.\n");
       return 1;
     }
     guilds += ({ who });
     write("What is your guild name? ");
     input_to("get_guild_name");
     return 1;
   }
   return 0;
}

get_guild_name(name) {
   if(!name) {
     write("What is your guild name? ");
     input_to("get_guild_name");
     return 1;
   }
   guild_names += ({ name });
   write("You are now in the guild list: "+name+"\n");
   save_file();
   return 1;
}

remove(str) {
   string who;
   int i;

   if(this_player()->query_level() < 21)
     return 0;
   who = this_player()->query_real_name();
   if(str == "castle") {
     if(member_array(who, castles) == -1) {
       write("Your name is not in the castle list.\n");
       return 1;
     }
     for(i=0; i < sizeof(castles); i++)
        if(who == castles[i])
          break;
     castles -= ({ castles[i] });
     write("Your name has been removed from the castle list.\n");
     save_file();
     return 1;
   }
   if(str == "guild") {
     if(member_array(who, guilds) == -1) {
       write("Your name is not in the guild list.\n");
       return 1;
     }
     for(i=0; i < sizeof(guilds); i++)
        if(who == guilds[i])
          break;
     guilds -= ({ guilds[i] });
     guild_names -= ({ guild_names[i] });
     write("Your name has been removed from the guild list.\n");
     save_file();
     return 1;
   }
   return 0;
}

save_file() {
   save_object(SAVEFILE);
   return 1;
}

show_castles(str) {
   int i, tmp;
   
   if(str) {
     show_ind_castle(str);
     return 1;
   }
   write("Wizards with open castles:\n");
   write("[========================================================]\n");
   if(!sizeof(castles)) {
     write("No castles have been entered yet.\n");
     return 1;
   }
   tmp = 0;
   for(i=0; i < sizeof(castles); i++) {
      tmp += 1;
      write(justify(capitalize(castles[i]),15));
      if(tmp == 3) {
        write("\n");
        tmp = 0;
      } else {
        write(justify(" ",5));
      }
   }
   if(tmp) write("\n");
   write("[========================================================]\n"); 
   return 1;
}

show_guilds(str) {
   int i;
   
   if(str) {
     show_ind_guild(str);
     return 1;
   }
   write("Wizards with open guilds:\n");
   write("[========================================================]\n");
   if(!sizeof(guilds)) {
     write("No guilds have been entered yet.\n");
     return 1;
   }
   write(justify("Wizard:",20)+justify("Guild:",30)+"\n");
   write(justify("-------",20)+justify("------",30)+"\n");
   for(i=0; i < sizeof(guilds); i++) {
      write(justify(capitalize(guilds[i]),20));
      write(justify(capitalize(guild_names[i]),30));
      write("\n");
   }
   write("[========================================================]\n"); 
   return 1;
}

show_ind_castle(str) {
   if(member_array(str, castles) == -1) {
     write(capitalize(str)+" is not in the castle list!\n");
     return 1;
   }
   if(!cat("/open/PROMO/"+str+"_CASTLE")) 
     write("No information available at this time.\n");
   return 1;
}

show_ind_guild(str) {
   if(member_array(str, guilds) == -1) {
     write(capitalize(str)+" is not in the guild list!\n");
     return 1;
   }
   if(!cat("/open/PROMO/"+str+"_GUILD"))
     write("No information available at this time.\n"); 
   return 1;
}





