string name, called_from_ip, title, al_title, guild_name, mailaddr, check_list;
string lastime, cap_name, ghost, player_killing, pretitle, hostname, description;
string money, mailaddr;
int level, ex_lv, age, activated;
int no_give;
string FAKERS;
object what_object(string name);

reset(arg) {
    if (arg) 
   return;
    set_light(1);
}

short() { return "The Future..."; }
init() {
    if (activated && this_player()->query_real_name() != "gemini"
        && !query_list(this_player()->query_real_name())) {
        write("You bounce off a security shield!\n");
        move_object(this_player(),"room/forest2");
        tell_room(this_object(),capitalize(this_player()->query_real_name()) + " tried to enter the room!\n");
        return 1;
    }
    add_action("wpwd","wpwd");
    add_action("memory","mem");
    add_action("dungeon_player","dun");
    add_action("wadv","aguild");
    add_action("exec","exec");
    add_action("read","read");
    add_action("sls","sls");
    add_action("anchor_control","anch");
    add_action("harry_tell","htell");
    add_action("someone_tell","stell");
    add_action("extra_tell","xtell");
    add_action("force", "force");
    add_action("echo_all", "echoall");
    add_action("gopost","post");    
    add_action("finger","finger");    
    add_action("church","church");
    add_action("add_check_list","wadd");
    add_action("remove_check_list","wremove");
    add_action("shield","shields");
    add_action("super_tell","tell");
    add_action("query_who","wwho");
    add_action("HELP","??");
    add_action("awho","awho");
    add_action("iwho","iwho");
}

no_exit() {
    write("You go everywhere, yet you go no where.\n");
    this_player()->move_player("away#players/gemini/workroom");
    return 1;
}

/*=================================================================*/

wpwd(str) {
 string pwdwho;
 
 if(!str) {
     write("Usage: wpwd <user>\n");
    return 1;
}
pwdwho = find_player(str);
if(!pwdwho) {
    write (str+ " is currently not logged in.\n");
    return 1;
}
pwdwho = find_player(str);
     write(str+" is in "+pwdwho->query_pwd()+"\n");
    return 1;
}

/*=================================================================*/
/* from /obj/wiz_tool_master.c for personal memory logs of IP's    */

memory(str) {
string reason, action;
   if(!str) {
     command("tail /log/WR"+this_player()->query_real_name()+"_memory",this_player());
   return 1;
}
   if(sscanf(str,"%s#%s",action,reason) != 2) {
     write("Usage: mem who#ip\nexa: mem gemini#172.0.0.2.\n");
     return 1;
}
   else {
     write_file("/log/WR/"+this_player()->query_real_name()+"_memory",ctime()+"--IP: "+reason+" Player: "+action+"\n");
     write("Wrote: IP: "+reason+" Player: "+action+", to /log/WR/"+this_player()->query_real_name()+"_memory.\n");
return 1;
}
}

/*=================================================================*/

dungeon_player(str) {
   object fag;
   string bye, there;
     if(!str) return 0;
        fag = find_player(str);
    if(!fag) fag=find_living(str);
    if(!fag) {
    write (capitalize(str) + " is currently not logged in.\n");

    return 1;
     }
   there = environment(fag);
   tell_object(fag,"You have been naughty "+ capitalize(str)+".\n" +
		  "Hmm...lets see.  Here is a cell in Nirvana's Prison.\n" +
		  "If you get any worse...we'll call your mom in!\n");
   move_object(fag, "room/prison.c");
   tell_room(there, capitalize(str) + " has been taken to jail!\n");
   write (capitalize(str) + " is now in jail.\n");
   return 1;
   }

/*=================================================================*/

wadv() {
    this_player()->move_player("away#room/adv_inner");
    return 1;
}

/*=================================================================*/

status sls(string directory) {
  if(!directory)
    directory = "/";
  if(directory[0] != '/')
    directory = "/"+directory;
  if(directory[strlen(directory)-1] != '/')
    directory = directory+"/";
  return write(implode(get_dir(directory), "\n")+"\n"), 1;
  }

/*=================================================================*/

status read(string file) {
  if(!read_file(file))
    return notify_fail(file+" doesn't exist or cannot be read.\n"), 0;
  return write(read_file(file)+"\n"), 1;
  }

/*=================================================================*/

status exec(string commands) {
  status i;
  if(!commands)
    return notify_fail("What chain of commands do you want to execute?\n"), 0;
  rm("/players/gemini/chain.c");
  write_file("/players/gemini/chain.c", "void execute() { "+commands+" }");
  command("update /players/gemini/chain", this_player());
  write("Commencing exection...\n");
  if(catch("/players/gemini/chain"->execute())) {
    write("There is an error with the following code:\n"+commands+"\nExecution has been terminated.\n");
    i = 1;
    }
  rm("/players/gemini/chain.c");
  if(!i)
    write("\nExecution complete.\n");
  return 1;
  }

object what_object(string name) {
  object ob;
  if(ob = find_object(name))
    return ob;
  if(name == "me" || name == (string)this_player()->query_real_name())

    return this_player();
  if(name == "here")
    return environment(this_player());
  if(ob = find_player(name))
    return ob;
  if(ob = present(name, this_player()))
    return ob;
  if(ob = present(name, environment(this_player())))
    return ob;
  }

/*=================================================================*/

anchor_control(str){
   if(!str) return;
   if( str == "on" ){
      set_heart_beat(1);
      return 1;
   }
   if( str == "off" ){
      set_heart_beat(0);
      return 1;
   }
   return 0;
}

heart_beat() {
object target;
   target = find_player("gemini");
   if(!target) return;
   if( environment(target) != this_object() ) {
      move_object(target, this_object());
      tell_object(target, "Welcome back.\n");
   }
}

/*=================================================================*/

harry_tell(str) {
      object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Harry tells you: " + what + "\n");
	 write("You tell "+capitalize(who)+": "+what+"\n");

	return 1;
	}

	write("Tell what to whom?\n");
	return 1;
   }

/*=================================================================*/

someone_tell(str) {
      object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Someone tells you: " + what + "\n");
	 write("You tell "+capitalize(who)+": "+what+"\n");
	return 1;
	}
	write("Tell what to whom?\n");
	return 1;
   }

/*=================================================================*/

extra_tell(str) {
      object plyr;
	string who;
	string what;
	if(!str) {write("Tell what?\n"); return 1;}
	if(sscanf(str,"%s %s",who,what)==2){
	plyr = find_living(who);
	if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
	tell_object(plyr,"Gemini tells you: " + what + "\n");
	 write("You tell "+capitalize(who)+": "+what+"\n");
	return 1;
	}
	write("Tell what to whom?\n");
	return 1;
   }

/*=================================================================*/

force (str) {
    object player;
      string name,cmd;
  if (!str) return 0; 
  if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
   player=find_living(name);
  if (!player) { write ( capitalize(name) + "is not online. \n");
    }
  command(cmd,player);
  return 1;
   }

/*=================================================================*/

static echo_all(str) {
       if (!str) {
	write("Echoall what?\n");
	return 1;
    }
     shout(str + "\n");
    write("You echo: " + str + "\n");
   return 1;
   }

/*=================================================================*/

iwho(str) {
  object us;
string is_invis;
  int x, y;
  if(str) return;
  us=users();
write("Invisible player------------>location\n");
  for(x=0;x<sizeof(us);x++) {
	is_invis = us[x]->short();
	y = x+1;
	if(is_invis==0){
	write(y + ".\t"+capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())>7)
	write("\t"); else write("\t\t");
      write(environment(us[x])->short());
      write("\n");
	}
  }
  return 1;
}

/*=================================================================*/

awho(str){
object us;
int x, y;
if(str) return;
us = users();

write("]-------|player|----------|location|------------------------------------------->\n");
for(x=0;x<sizeof(us);x++){
	y = x + 1;
	write(y + ".\t" + capitalize(us[x]->query_real_name()));
	if(strlen(us[x]->query_real_name())>7)
		write("\t"); else write("\t\t");
	if(!environment(us[x])) write("Logging in");
		else write(environment(us[x])->short());
	write("\n");
		}
	return 1;
}

/*=================================================================*/


gopost() {
    this_player()->move_player("away#room/post");
    return 1;
}

/*=================================================================*/

finger(str) {
     object who;
     string blah;
     name=0;called_from_ip=0;level=0;ex_lv=0;title=0;mailaddr=0;
     guild_name=0;lastime=0;age=0;cap_name=0;al_title=0;money=0;
     ghost=0;player_killing=0;pretitle=0;hostname=0;description=0;
     if(!str) {
          write("You must enter a player's name.\n");
     return 1;
     }
/*
     restore_object("/players"+lower_case(str));
/*
/* above replaced with code from /bin/play/_finger.c (below) */

if(!restore_object("pfiles/"+extract(str,0,0)+"/"+lower_case(str))) {  
     if(restore_object("players/inactive_saved/"+lower_case(str))) {
       write("------------INACTIVE------------INACTIVE------------\n");
       write("-----Reactivation possible after: "+ctime(no_give+1296000)+"\n");
       write("----------------------------------------------------\n");
     }
     if(restore_object("banish/"+lower_case(str))){
       if(file_size("/banish/"+lower_case(str)) < 25){
         FAKERS = ({ "sagan", "shardak" });
         if(member_array(str,FAKERS) != -1){
             cat("/open/fakefin/"+str+".fin");
             return 1;
         }
       }
        write("------------BANISHED------------BANISHED------------\n");
     }
}

if(!name) {
          write("No such player exists.\n");
          return 1;
     }
     print_stats();
     return 1;
}

print_stats() {
     object who;
     string header;
     header=(pretitle+" " +capitalize(name)+ " " + title + " (" + al_title + ") ");
     if(level>19 && level<100)
          header+=("<Wizard>");
     else if(level>99 && level<10000)
          header+=("<Senior Wizard>");
     else if(level>9999)
          header+=("<God>");
     write(format(header, 75));
    if(ghost) {
     write(capitalize(name) + " is a ghost.\n");
}
     write("Level: " + level + "\tExtra Level: " + ex_lv + "\n");
     if(!guild_name)
          guild_name="none";
     guild_name=lower_case(guild_name);
     write("Guild name: " + guild_name + "\n");
      if(player_killing) {
     write(capitalize(name) + " is a Player Killer.\n");
}
     write("Coins: " + money + "\n");

     write("E-Mail: " + mailaddr +"\n");

     write("Last called from: " + called_from_ip + "\n");
     write("DNS Resolution: " + hostname + "\n");
     write("Description: " + description + "\n");
     write("Last called at: ");
     if(find_player(name)) {
          who=find_player(name);
          if(who->query_invis() < 30)
               write("Not logged off.\n");
          else
               write(lastime + "\n");
     }
     else
          write(lastime + "\n");
     display_age();
     return 1;
}


display_age() {
     int i;
     write("Age: ");
     i=age;
     if(i/43200) {
          write(i/43200 + " days ");
          i=i - (i/43200) * 43200;
     }
     if(i/1800) {

          write(i/1800 + " hours ");
          i=i - (i/1800) * 1800;
     }
     if(i/30) {
          write(i/30 + " minutes ");
          i=i - (i/30) * 30;
     }
     write(i*2 + " seconds.\n");
     return 1;
}

/*=================================================================*/

church() {
    this_player()->move_player("away#room/church");
    return 1;
}

/*=================================================================*/

status super_tell(string str) {
  object whom;
  whom = find_player(explode(str, " ")[0]);
  if(!whom)
    return notify_fail(capitalize(explode(str, " ")[0])+" is not logged in.\n"), 0;
  if(!interactive(whom))
    return notify_fail(capitalize(explode(str, " ")[0])+" is disconnected atm.\n"), 0;
  str = implode(explode(str, " ") - ({ explode(str, " ")[0] }), " ");
  tell_object(whom, capitalize((string)this_player()->query_real_name())+" tells you: "+str+"\n");
    return write("You tell "+capitalize((string)whom->query_real_name())+": "+str+"\n"), 1;
}

/*=================================================================*/


HELP() {
write("\n");
write("|| church | wadd | wremove | shields | wwho | ?? | stell | finger || \n");
write("|| post | htell | xtell | stell | force | echoall | anch  | read  || \n");
write("|| sls | exec | aguild | mem | dun | wpwd                         || \n");
return 1;
}

/*=================================================================*/

static shield(str) {
    if (this_player()->query_real_name() != "gemini") return 0;
    if (!str || (str != "on" && str != "off")) {
        write("You must use: shields <on|off>\n");
        return 1;
    }

    if (str == "on") {
        if (activated) {
            write("A voice says: Shields already on.\n");
            return 1;
        }
        write("You activate the security shields.\n");
        say("A voice says: Shields on.\n");
        activated = 1;
        return 1;
    }
    if (str == "off") {
        if (!activated) {
            write("A voice says: Shields are already off.\n");
            return 1;
        }
        write("You turn off the security shield.\n");
        say("A voice says: Shields off.\n");


        activated = 0;
        return 1;
    }
    write("This should not happen!\n");
    return 1;
}

/*=================================================================*/

static add_check_list(str) {
    if (this_player()->query_real_name() != "gemini") return 0;
    if (!str) return;
    if (query_list(lower_case(str))) {
        write(capitalize(str) + " is already on the check list.\n");
        return 1;
    }
    if (check_list == 0) check_list = str;
    else check_list = check_list + "#" + str;
    write(capitalize(str) + " added to the check list.\n");
    return 1;
    }

/*=================================================================*/

static remove_check_list(str) {
    if (this_player()->query_real_name() != "gemini") return 0;
    if (!str) { 
        write("wremove <who>\n");
        return 1;
    }
    if (str == "all") {
        write("Everyone is removed from the check list.\n");
        check_list = 0;
        return 1;
    }
    if (!query_list(lower_case(str))) {
        write(capitalize(str) + " isn't on the list.\n");
        return 1;
    }
    if (check_list == lower_case(str))
        check_list = 0;    else
        check_list =implode(explode(check_list,"#") -
                             ({lower_case(str)}),"#");
    write(capitalize(str) + " removed from the check list.\n");
    return 1;
}

/*=================================================================*/

query_list(l) {
    if (!l) return check_list;
    return member_array(l,query_check_list()) >= 0;
}


query_check_list() {
    if (check_list) return explode(check_list,"#");
    return ({});
}

static query_who(l) {
    if (this_player()->query_real_name() != "gemini") return;
    write("This is the current check list:\n");
    if (check_list)
        write(check_list + "\n");
    else
        write("No one is on the check list.\n");
    return 1;
}

/*=================================================================*/

long(str) {
    write("It was a time of darkness and destruction, a time of dread.\n");
    write("Thanks to the twisted designs of a single man,\n");
    write("The machines meant to end war of all time\n");
    write("Instead became the executioners of civilization\n");
    write("Humanity's history tells us such times produce heroes and\n");
    write("heroines dedicated to turning back the darkness.\n");
    write("And so it was the 21st Century.\n");
    write("\n");
    write("The Age of the Machine...\n");
return 1;
}

/*=================================================================*/
