int level, player_killing;
string gender, hostname, called_from_ip, guild_name, name;

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
  if(this_player()->query_level() < 21) {
  destruct(this_object()); return 1;}
  add_action("commands","commands");
#ifndef __LDMUD__
  add_action("list"); add_xverb("lis");
#else
  add_action("list", "lis");
#endif
}

commands() {
  write("The items that may be compared are as follows:\n"+
        "  level,  player_killing,  gender,  hostname,\n"+
        "  called_from_ip,  guild_name\n\n");
  write("To use: lisp <type> <restrictions> <file path>\n");
  write("    or: lisv <type> <restrictions>  to view only and\n"+
        "        not log the check.\n");
  write("For hostname and called_from_ip: the name of a\n"+
        "  player must be stated to compare against.\n");
  write("For player_killing: either a yes or a no is needed.\n");
  write("For guild_name and gender: a type of the corresponding\n"+
        "  item must be typed- i.e. lisp gender female /log/females\n");
  write("For level: a number must be stated and also whether\n"+
        "  the item that is to be checked is to be above, below,\n"+
        "  or the same as to the stated number.  usage of > < =\n");
return 1;}

list(str) {
string see, full, type, restrict, path;
string appr, msg, hos, iip;
string files, file;
int n, size;
int lv;
  if(sscanf(str,"%s %s",see,full) != 2 && see != "p" && see != "v") {
     write("Type commands\n"); return 1;}
  if((see == "p" && sscanf(full,"%s %s %s",type,restrict,path) != 3) ||
     (see == "v" && sscanf(full,"%s %s",type,restrict) != 2)) {
     write("Type commands\n"); return 1;}
  if(type != "level" && type != "player_killing" && type != "gender" &&
     type != "hostname" && type != "called_from_ip" && type != "guild_name") {
     write("Type commands\n"); return 1;}
  if(type == "level" && sscanf(restrict,"%d %s",lv,appr) != 2) {
     write("Type commands\n"); return 1;}
  if(type == "player_killing" && restrict != "yes" && restrict != "no") {
    write("Type commands\n"); return 1;}
  if(type == "hostname" || type == "called_from_ip") {
    if(!restore_object("players/"+restrict)) { 
    tell_object(environment(this_object()),"Player does not exist.\n");  
          return 1;}
    hos = hostname;
    iip = called_from_ip; }
  files = get_dir("/players/");
  if(sizeof(files) < 1) {
    tell_object(environment(this_object()),"No files found.\n");
    return 1;
  }
  for(n=0;n<sizeof(files);n++) {
  level = 0; player_killing = 0;
  gender = 0; hostname = 0; called_from_ip = 0; guild_name = 0; name = 0;
     restore_object("players/"+ files[n]);
     msg = 0;
     if(type == "level" && level) {
       if(appr == "<" && level < lv) { msg = name+"\t\t"+level+"\n";}
       if(appr == ">" && level > lv) { msg = name+"\t\t"+level+"\n";}
       if(appr == "=" && level == lv) { msg = name+"\t\t"+level+"\n";}
       } 
     if(type == "gender" && gender && gender == restrict) {
       msg = name+"\t\t"+gender+"\n";}
     if(type == "guild_name" && name && guild_name == restrict) {
       msg = name+"\t\t"+guild_name+"\n";}
     if(type == "player_killing") {
       if(restrict == "yes" && player_killing) { msg = name+"\t\tPK\n";} 
       if(restrict == "no" && !player_killing) { msg = name+"\t\tNO PK\n";} 
     }
     if(type == "hostname" && hostname && hostname == hos) {
       msg = name+"\t\t"+hostname+"\n";}
     if(type == "called_from_ip" && called_from_ip && called_from_ip == iip) {
       msg = name+"\t\t"+called_from_ip+"\n";}
       if(see == "p" && name) { write_file(path,msg);}
       if(see == "v" && name) { write(msg); }
   }
   write("Done.\n");
   return 1;
}
