
inherit "obj/armor";
/*
 * BOOTS OF SPRINTING 
 * Allows the player to carry out direction commands in lists.
 */

#define VERSION "1.0.2"
query_version() { return VERSION; }

#define UPDATE "12/02/94"
query_update() { return UPDATE; }

/* Valid directions a player can sprint */
#define VALID_DIR ({ "n","s","e","w","ne","nw","se","sw","u","d" })

#define notify_fail(A) { write(A+"\n"); return 1; }

string al_dir_alias, al_dir_list;
string command_list, *dir_alias, *dir_list; 

justify(str,len) { return extract(str+"                       ",0,len-1); }


reset() {
   set_id("boots");
   set_short("Boots of Sprinting");
   set_long("A fine pair of leather boots made for sprinting.\n"+
     "They allow you to move many directions at once.\n"+
     "[!] validdir\n"+
     "     Lists the valid directions you may sprint.\n"+
     "[!] sprint <directions>    ex - sprint n,w,w,n,e\n"+
     "    will cause you to go in the specified directions faster than\n"+
     "    you normally would.\n"+
     "You can also set aliases for direction lists.\n"+
     "[!] adddir <alias>:<directions>  ex - adddir church:n,w,w,w,n\n"+
     "    This provides a shortcut to direction commands entered alot.\n"+
     "    By typing 'sprint church' it will execute the commands n,w,w,w,n\n"+
     "    Typing sprint by itself lists all the aliases you have set.\n"+
     "[!] deldir <alias>             ex - deldir church\n"+
     "    Removes the alias 'church'\n"+
     "You can store up to five aliases.\n"+
     "The boots and aliases are auto-loading.\n"+
     "If you notice any problems mail Molasar.\n"+
     "Version: "+query_version()+"  Last Update: "+query_update()+"\n");
   set_type("boots");
   set_value(0);
   set_weight(1);
   convert_to_arrays();
}

init() {
   add_action("sprint","sprint");
   add_action("deldir","deldir");
   add_action("adddir","adddir");
   add_action("validdir","validdir");
   ::init();
}

query_auto_load() { return "players/sandman/paladin/obj/boots:"+
                           al_dir_alias+"#"+al_dir_list; }

init_arg(str) {
   sscanf(str, "%s#%s", al_dir_alias, al_dir_list);
   convert_to_arrays();
   return;
}

drop() {
  return 1;
  ::drop();
}

convert_to_arrays() {
   string curr, tmp_str, tmp_alias, tmp_list;  
   
   dir_list = ({ });             dir_alias = ({ });
   tmp_alias = al_dir_alias;     tmp_list = al_dir_list;
   if(al_dir_alias) {
     while(sscanf(tmp_alias, "%s=%s", curr, tmp_str) == 2) {
        dir_alias += ({ curr });
        tmp_alias = tmp_str;
     }
     if(tmp_alias)
       dir_alias += ({ tmp_alias });
     while(sscanf(tmp_list, "%s=%s", curr, tmp_str) == 2) {
        dir_list += ({ curr });
        tmp_list = tmp_str;
     }
     if(tmp_list)
       dir_list += ({ tmp_list });
   }
   return 1;
}

convert_to_strings() {
   int i;

   al_dir_alias = "";
   al_dir_list = "";
   if(sizeof(dir_alias)) {
     for(i=0; i < sizeof(dir_alias); i++) 
        al_dir_alias += "="+dir_alias[i];
   }
   if(sizeof(dir_list)) {
     for(i=0; i < sizeof(dir_list); i++)
        al_dir_list += "="+dir_list[i];
   }
   return 1;
}

/*
 * The following functions allow players to store/execute direction
 * lists. They can 'sprint' in any of the directions defined by
 * VALID_DIR.
 */

sprint(str) {
   int i;
   
   if(!worn) 
     notify_fail("You must wear the boots first.");
   if(!str) {   
     write("Direction Aliases:\n");
     write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");  
     if(!sizeof(dir_alias)) 
       write("None.\n");
     else
       for(i=0; i < sizeof(dir_alias); i++) {
          write(justify(dir_alias[i],10));
          write(justify(" ",5));
          write(dir_list[i]);
          write("\n");
       }
     write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");  
     return 1;
   }
   if(member_array(str, dir_alias) != -1) {
     for(i=0; i < sizeof(dir_alias); i++) 
        if(str == dir_alias[i])
          break;
     write("You begin your sprint: "+str+"\n");
     command_list = dir_list[i];
     execute_sprint();
     return 1;
   }
   command_list = str;
   write("You begin your sprint!\n");
   execute_sprint();
   return 1;
}

deldir(str) {
   int i;

   if(!str) 
     notify_fail("USAGE: deldir <direction list alias>");
   if(!sizeof(dir_alias))
     notify_fail("You have no direction list aliases!");
   if(member_array(str, dir_alias) == -1) 
     notify_fail("No such direction list: "+str+".");
   for(i=0; i < sizeof(dir_alias); i++) 
      if(str == dir_alias[i])
        break;
   dir_alias -= ({ dir_alias[i] });
   dir_list -= ({ dir_list[i] });
   write("Direction List '"+str+"' Deleted!\n");
   convert_to_strings();
   return 1;
}

adddir(str) {
   string cmd, list;
   int cnt;

   if(!str || sscanf(str, "%s:%s", cmd, list) != 2) {
     write("USAGE: addcmd <direction list alias>:<direction list>\n");
     write("Ex - addcmd church:n,s,w,e,e,e,n\n");
     return 1;
   }
   if(member_array(cmd, dir_alias) != -1)  
     notify_fail("You already are using that direction list alias: "+str);
   cnt = sizeof(dir_alias);
   if(cnt >= 5) 
     notify_fail("You cannot store anymore direction lists.");
   if(!cnt) {
     dir_alias = ({ });
     dir_list = ({ });
   }
   dir_alias += ({ cmd });
   dir_list += ({ list });
   write("Command List: SET!\n");
   convert_to_strings();
   return 1;
}

execute_sprint() {   
   string curr_cmd, rest_cmd;
   int ii;

    ii = 0;
   while(command_list && 
         ii < 5 &&
         sscanf(command_list, "%s,%s", curr_cmd, rest_cmd) == 2) {
     if(member_array(curr_cmd, VALID_DIR) == -1) {
       write("Sprint aborted. You cannot sprint '"+curr_cmd+"'.\n");
       write("If you feel you should be able to, mail Molasar.\n");
       command_list = 0;
     } else {
       write("Sprinting: "+curr_cmd+"\n");
       command(curr_cmd, this_player());
       command_list = rest_cmd;
     }
   ii += 1;
   } 
   if(command_list) {
     if(sscanf(command_list, "%s,", curr_cmd) == 1) {
       if(member_array(curr_cmd, VALID_DIR) == -1) {
         write("Sprint aborted. You cannot sprint '"+curr_cmd+"'.\n");
         write("If you feel you should be able to, mail Molasar.\n");
         return 1;
       }
       write("Sprinting: "+curr_cmd+"\n");
       command(curr_cmd, this_player());
     } else {
       if(member_array(command_list, VALID_DIR) == -1) {
         write("Sprint aborted. You cannot sprint '"+command_list+"'.\n");
         write("If you feel you should be able to, mail Molasar.\n");
         return 1;
       }
       write("Sprinting: "+command_list+"\n");
       command(command_list, this_player());
     }
   }
   if (ii > 4) write("You may not sprint more than 6 commands.\n");
   /* added -Bp. should have been added per my mail months ago */
   write("You lean over to catch your breath from that long sprint.\n");
   return 1;
}

validdir() {
   int i, cnt;   
   string *tmp_arr;

   tmp_arr = VALID_DIR;
   write("Valid Directions:\n");
   write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
   cnt = 0;
   for(i=0; i < sizeof(tmp_arr); i++) {   
      write(justify(tmp_arr[i],15));
      cnt += 1;
      if(cnt >= 3) {
        cnt = 0;
        write("\n");
      } else
        write(justify(" ",5));
   }
   if(cnt)
     write("\n");
   write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"); 
   return 1;
}

