int level, player_killing;
string gender, hostname, called_from_ip, guild_name, name;
static int n;

id(str) { return str == "playcheck" || str == "lister";}

drop() { return 1;}
get() { return 0;}

short() { return "A Playcheck";}

reset(arg) { 
  if(arg) return;
  level = player_killing = 0;
  gender = hostname = called_from_ip = guild_name = name = 0;
}

long() { write("An item that allows one to compare player files.\n"+
                "To have the list that you call up logged- simply\n"+
                "type the pathname of the file to be written after\n"+
                "the command <lisp gender male /log/male>\n"+
                "For commands type 'commands'\n");}

init() {
  add_action("commands","commands");
  add_action("levels","levels");
  add_action("hosts","hosts");
  add_action("genders","genders");
  add_action("pks","pks");
  add_action("guilds","guilds");
}

commands() {
 write("commands are as follows:\n"+
       "  levels  guilds  hosts  genders pks\n"+
       "  Levels:  levels [#] [> < =]\n"+
       "  Pks:  pks [y n]\n"+
       "  Hosts:  hosts [name]\n"+
       "  rest:  [function] [string]\n");
return 1;}

levels(str) {
int lv;
string appr;
string files;
string checker;
  if(!str) return 0;
  if(sscanf(str,"%d %s",lv,appr) != 2) return 0;
  files = get_dir("/players/");
  if(sizeof(files) < 1) {
    write("No files found.\n");
    return 1;
  }
  checker = 0;
  for(n=0;n<sizeof(files);n++) {
  level = 0;
  restore_object("players/"+files[n]);
  if(name != checker) {
  checker = name;
  if(file_size("players/"+files[n]) != -2) {
  if(appr == "<" && level < lv) { write(name+"\t"+level+"\n"); }
  if(appr == ">" && level > lv) { write(name+"\t"+level+"\n"); }
  if(appr == "=" && level == lv) { write(name+"\t"+level+"\n"); } 
  }}
  }
  write("Done.\n");
return 1;}

genders(str) {
string files;
string checker;
  if(!str) return 0;
  files = get_dir("/players/");
  if(sizeof(files) < 1) {
    write("No files found.\n");
    return 1;
  }
  checker = 0;
  for(n=0;n<sizeof(files);n++) {
  gender = 0;
  restore_object("players/"+files[n]);
  if(name != checker) {
  checker = name; 
  if(file_size("players/"+files[n]) != -2) {
  if(gender == str) write(name+"\t"+gender+"\n");
  }
  } }
  write("Done.\n");
return 1;}

guilds(str) {
string files;
string checker;
  if(!str) return 0;
  files = get_dir("/players/");
  if(sizeof(files) < 1) {
    write("No files found.\n");
    return 1;
  }
  checker = 0;
  for(n=0;n<sizeof(files);n++) {
    guild_name = 0;
  restore_object("players/"+files[n]);
  if(name != checker) {
  checker = name;
  if(file_size("players/"+files[n]) != -2) {
  if(guild_name == str) write(name+"\t"+guild_name+"\n"); }
  }
  }
  write("Done.\n");
return 1;}

hosts(str) {
string files;
string checker;
string hn, ip;
  if(!str) return 0;
  if(!restore_object("players/"+str)) { 
    write("Player does not exist.\n");  
          return 1;}
    hn = hostname;
    ip = called_from_ip; 
   
    files = get_dir("/players/");
  if(sizeof(files) < 1) {
    write("No files found.\n");
    return 1;
  }
  checker = 0;
    for(n=0;n<sizeof(files);n++) {
    hostname = called_from_ip = 0;
    restore_object("players/"+files[n]);
    if(name != checker) {
    checker = name;
    if(file_size("players/"+files[n]) != -2) {
  if(hostname == hn || called_from_ip == ip) 
     write(name+"\t"+hostname+"  "+
       called_from_ip+"\n"); }
       }
  }
  write("Done.\n");
return 1;}

pks(str) {
string files;
string checker;
  if(!str) return 0;
 files = get_dir("/players/");
  if(sizeof(files) < 1) {
    write("No files found.\n");
    return 1;
  }
 checker = 0;
  for(n=0;n<sizeof(files);n++) {
  player_killing = 0;
  restore_object("players/"+files[n]);
  if(name != checker) {
    checker = name;
  if(file_size("players/"+files[n]) != -2) {
  if(player_killing && str == "y") 
    write(name+"\t"+"PK"+"\n");
  if(!player_killing && str == "n")
    write(name+"\t"+"NO PK"+"\n"); }
    }
  }
  write("Done.\n");
return 1;}
