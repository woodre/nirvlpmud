#define TO this_object()
#define TP this_player()


string files, name;

id(str) { return str == "stat" || str == "shadow-stat"; }

short() { return "A Shadow Stat Object"; }
long() { destruct(TO); }
get() { return 1; }

int shxp, shlevel, guild_status, last_login, gbday;

reset(arg) {
   if(!arg) {
      shlevel = 0;
      guild_status = 0;
      last_login = 0;
      gbday = 0;
   }
}

init() {
   if(this_player()->query_real_name() != "gemini") destruct(this_object());

   add_action("show_greater", "shgreater");
   add_action("guild_status", "shstat");
   add_action("show_equal", "shequal");
}

show_greater(str) {
   int size, n, num;
   if(sscanf(str, "%d", num) != 1) {
      write("Bad arg.\n");
      return 1;
   } 
   get_files();
   size = sizeof(files);
write("Size is "+size+"\n");
   n = 0;
   while(n < sizeof(files)) {
      restore_file(n);
      if(shlevel > num) write(name +"\t\t"+ shlevel+"\n");
      shlevel = 0;
      name = "0";
      n+=1;
   }
   write("Done.\n");
   return 1;
}

guild_status(str) {
   int members, full_mem, sus_mem, ban_mem, gcs, wiz_mem;
   int size, n;
   get_files();
   size = sizeof(files);
   n = 0;
   while(n < size) {
      shlevel = 0;
      restore_file(n);
      if(shlevel) {
         if(shlevel == 13) gcs++;
         if(shlevel > 13) wiz_mem++;
         if(guild_status == 1) full_mem++;
         if(guild_status == 0) sus_mem++;
         if(guild_status == -1) ban_mem++;
         members++;
      }
      n++;
   }
   write("Status complete.\n\nFull members:\t"+full_mem+"\n");
   write("Gcs:\t\t"+gcs+"\nWizzes:\t\t"+wiz_mem+"\n");
   write("Suspended:\t"+sus_mem+"\nBanished:\t"+ban_mem+"\n");
   write("Total Files:\t"+n+"\n");
   write("\nStat complete.\n");  
   return 1;
 }

write_old(str) {
   int days, n, size, temp, curtime;
   curtime = time();
   if(!str) days = 60;
   if(str && sscanf(str, "%d", days) !=1) {
      write("Bad arg.\n");
      return 1;
   }
   n = 0;
   get_files();
   size = sizeof(files);
   write("Checking for players over "+days+" old.\n");
   while(n < size) {
      name = "0";
      restore_file(n);
      if(name != "0" && ((curtime - last_login)/86400) > days) 
         write(name + ": "+(curtime - last_login)/86400 + "days old.\n");
      n++;
   }
   write("Done.\n");
   return 1;
 }
restore_file(num) {
   string current;
   if(sscanf(files[num], "%s.o", current) == 1) {
      restore_object("players/guilds/shadow/shadows/"+current);
   }
   name = current;
   return 1;
}

get_files() {
   files = get_dir("/players/guilds/shadow/shadows/");
   return 1;
}

show_equal(str) {
   int size, n, num;
   if(sscanf(str, "%d", num) != 1) {
      write("Bad arg.\n");
      return 1;
   }
   get_files();
   size = sizeof(files);
write("Size is "+size+"\n");
   n = 0;
   while(n < sizeof(files)) {
      restore_file(n);
      if(shlevel == num) write(name +"\t\t"+ shlevel+"\n");
      shlevel = 0;
      name = "0";
      n+=1;
   }
   write("Done.\n");
   return 1;
}
