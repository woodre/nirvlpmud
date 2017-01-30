

#define REF_INTV 300
string who;
int amt;
int refreshing;

#define CWHO capitalize(who)
#define TARGET find_player(who)
#define TARGETOB find_living(who)
#define CME capitalize(this_player()->query_real_name())
#define DEST environment(this_player())

justify(str, len) { return extract(str+"                        ",0,len-1); }

id(str) { return str == "staff" || str == "ND"; }

get() {
   if(this_player()->query_level() < 21) {
     write("The staff disappears as your hand moves towards it.\n");
     destruct(this_object());
     return 0;
   }
   return 1;
}

drop() {
   tell_room(DEST, CME+" drops a staff.\nA second before it reaches the "+
	     "ground it disappears in a flash of light.\n");
   destruct(this_object());
   return 1;
}

short() { return "A gnarled staff"; }

init() {
   if(this_player() && this_player()->query_level() < 21)
     return;
   if(!refreshing) {
     write("Starting refresh cycle.....\n");
     call_out("refresh", REF_INTV);
     refreshing = 1;
   }
   add_action("sendpl","sendpl");
   add_action("invis_tell","Tell");
   add_action("check_time","time");
   add_action("set_attrib","setattrib");
   add_action("true_inventory","inv");
   add_action("remote_destruct","Destruct");
   add_action("remote_set","Call");
   add_action("remote_obj_set","Callobj");
   add_action("remote_destruct_inventory","Clean");
   add_action("players","players");
   add_action("quicktyper_info","q");
   add_action("stats","stats");
   add_action("maxstats","maxstats");
   add_action("gag","gag");
   add_action("check_guild","ckguild");
   add_action("moveobj","moveobj");
   add_action("page","page");
   add_action("sunndi_align","sunndi_align");
   add_action("sunndi_room","sunndi_room");
   add_action("sunndi_debug","sunndi_debug");
}

sunndi_align(string str) {

   int alignment;
   
   if(!str || !sscanf(str, "%d", alignment))
     return 0;

   if (call_other("/players/molasar/sunndi/sunndi_master", "set_alignment", alignment)) {
      write("Alignment set\n");
      return 1;
   }

}

sunndi_debug() {
   int debug;

   if (call_other("/players/molasar/sunndi/sunndi_master", "toggle_debug", 0)) {
   }
      debug = (int)call_other("/players/molasar/sunndi/sunndi_master", "query_debug", 0);
      if (debug)
         write("Sunndi Debug enabled\n");
      else 
         write("Sunndi Debug disabled\n");
      return 1;

}

sunndi_room(string loc) {

   if (call_other("/players/molasar/sunndi/rooms/sunndi_road/" + loc, "reset", 1)) {
      write("Done\n");
      return 1;
   }

}


page(str) {
   object player;
   string who, pose;

   if(sscanf(str, "%s=%s", who, pose) != 2) {
      write("USAGE: page <person>=<pose>\n");
      return 1;
    }

   player = find_player(who);
    if(!player) {
     write("Could not find player: "+capitalize(who)+"\n");
      return 1;
    }
   tell_object(player, this_player()->query_name()+" "+pose);
   return 1;
}


long() {
   if(this_player()->query_level() < 21) {
     write("An ordinary looking staff.\n");
     return 1;
   }
   write("\n");
   write(CME+"'s staff has the following capabilities:\n");
   write("===============================================================\n");
   write("Call <player> <func> <arg>\n");
   write("                        Sets a <func> in <player> to <arg>\n");
   write("Callobj <player> <item> <func> <arg>\n");
  write("                        Sets <func> in <item> which is contained\n");
   write("                          in <player>'s inventory.\n");
   write("Clean <room/player>     Destruct inventory of room/player\n");
   write("ckguild <player>        Gives guild info of <player>\n");
   write("Destruct <obj>          Remote destruct of object/filename\n");
   write("gag <player>            Disable player's commands\n");
   write("inv <room/player>       Show the true inventory of player/room\n");
   write("maxstats <player> <amt> Raise player's stats to <amt>\n");
   write("moveobj <obj> <dest>    Move object to destination\n");
   write("players                 Gives some info on all players\n");
   write("q <a/h> <player>        Show quicktyper info (alias/history)\n");
   write("sendpl <player> <dest>  Sends player to specified dest\n");
   write("setattrib <player> <attrib> <num>\n");
   write("                        Sets <attrib> of <player> to <num>\n");
   write("stats                   Shows attributes of logged in players\n");
   write("Tell <player> <msg>     Used when invisible\n");
   write("time                    Check the current date and time\n");
   write("=============================================================\n");
}

refresh() {
   object staff, wiz;
   
   wiz = environment(this_object());
   if(wiz && !query_ip_number(wiz)) {
     destruct(this_object());
     return 1;
   }
   if(first_inventory(wiz) == this_object()) {
     call_out("refresh", REF_INTV);
     return 1;
   }
   tell_object(wiz, "Your inventory has been re-arranged.\n");
   staff = clone_object("players/molasar/closed/staff");
   move_object(staff, wiz);
   destruct(this_object());
   return 1;
}

gag(str) {
   object gag;

   if(!str) {
     write("Who do you wish to gag?\n");
     return 1;
   }
   who = str;
   if(!TARGETOB) {
     write(CWHO+" not found.\n");
     return 1;
   }
   gag = clone_object("players/molasar/closed/gag");
   gag->set_placer(this_player()->query_real_name());
   move_object(gag, TARGETOB);
   write(CWHO+" has been gagged!\n");
   return 1;
}

maxstats(str) {
   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
     write("Usage: maxstats <player> <amt>\n");
     return 1;
   }
   if(!TARGET) {
     write(CWHO+" is not on.\n");
     return 1;
   }
   TARGET->set_attrib("str", amt);
   TARGET->set_attrib("int", amt);
   TARGET->set_attrib("wil", amt);
   TARGET->set_attrib("mag", amt);
   TARGET->set_attrib("pie", amt);
   TARGET->set_attrib("luc", amt);
   TARGET->set_attrib("ste", amt);
   TARGET->set_attrib("sta", amt);
   write(CWHO+"'s attributes have been set to "+amt+".\n");
   tell_object(TARGET, "Your attributes have been set to "+amt+".\n");
   return 1;
}

remote_set(str) {
   object ob;
   string who, func, what;
   int amt;
   
   if(!str)
     return 0;
   if(sscanf(str, "%s %s %d", who, func, amt) == 3) {
     ob = find_living(who);
     if(!ob)
       ob = find_object(who);
     if(!ob) {
       write("Could not find "+who+"\n");
       return 1;
     }
     call_other(ob, func, amt);
     write("Ok.\n");
     return 1;
   }
   if(sscanf(str, "%s %s %s", who, func, what) == 3) {
     ob = find_living(who);
     if(!ob)
       ob = find_object(who);
     if(!ob) {
       write("Could not find "+who+"\n");
       return 1;
     }
     call_other(ob, func, what);
     write("Ok.\n");
     return 1;
   }
   return 0;
}

remote_obj_set(str) {
   string who, item, func, what;
   int amt;
   object player, itemob;

   if(!str)
     return 0;
   if(sscanf(str, "%s %s %s %d", who, item, func, amt) == 4) {
     player = find_living(who);
     if(!player) {
       write("Could not find "+capitalize(who)+".\n");
       return 1;
     }
     itemob = present(item, player);
     if(!itemob) {
       write(capitalize(who)+" does not have an "+item+".\n");
       return 1;
     }
     call_other(itemob, func, amt);
     write("Ok.\n");
     return 1;
   }
   if(sscanf(str, "%s %s %s %s", who, item, func, what) == 4) {
     player = find_living(who);
     if(!player) {
       write("Could not find "+capitalize(who)+".\n");
       return 1;
     }
     itemob = present(item, player);
     if(!itemob) {
       write(capitalize(who)+" does not have an "+item+".\n");
       return 1;
     }
     call_other(itemob, func, what);
     write("Ok.\n");
     return 1;
   }
   write("USAGE: Callobj <player> <item> <function> <arg>\n");
   return 1;
}

invis_tell(str) {
   string msg;

   if(sscanf(str, "%s %s", who, msg) != 2) {
     write("Usage: Tell <player> <msg>\n");
     return 1;
   }
   if(!TARGET) {
     write("You cannot find "+CWHO+".\n");
     return 1;
   }
   tell_object(TARGET, CME+" tells you: "+msg+"\n");
   write("Ok.\n");
   return 1;
}

sendpl(str) {
   object dest;

   if(!str || sscanf(str, "%s %s", who, dest) != 2) {
     write("Usage:  sendpl <player> <destination>\n");
     return 1;
   }
   if(!TARGETOB) {
     write("You cannot find "+CWHO+".\n");
     return 1;
   }
   move_object(TARGETOB, dest);
   write("You send "+CWHO+" to "+dest+".\n");
   tell_object(TARGETOB, "You find yourself in another place.\n");
   TARGETOB->look();
   return 1;
}

moveobj(str) {
   string item, where;
   object itemob, dest;

   if(!str || sscanf(str, "%s %s", item, where) != 2) {
     write("USAGE: moveobj <object> <destination>\n");
     return 1;
   }
   itemob = present(item, this_player());
   if(!itemob)
     itemob = present(item, environment(this_player()));
   if(!itemob)
     itemob = find_object(item);
   if(!itemob) {
     write("Could not find item.\n");
     return 1;
   }
   dest = find_living(where);
   if(!dest)
     dest = find_object(where);
   if(!dest) {
     write("Not a valid destination: "+where+"\n");
     return 1;
   }
   move_object(itemob, dest);
   write("You moved "+item+" to "+where+".\n");
   return 1;
}

check_time() {
   write("It is now "+ctime(time())+"\n");
   return 1;
}

check_guild(who) {
   int grank, gexp;
   string gfile, gname;

   if(!who) 
     return 0;
   if(!TARGET) {
     write(CWHO+" is not on.\n");
     return 1;
   }
   gname = TARGET->query_guild_name();
   if(!gname)
     gname = "None";
   gfile = TARGET->query_guild_file();
   if(!gfile)
     gfile = "None";
   grank = TARGET->query_guild_rank();
   gexp = TARGET->query_guild_exp();
   write("\n");
   write(CWHO+":\n");
   write("[=======================]\n");
   write("Guild Name: "+gname+"\n");
   write("Guild File: "+gfile+"\n");
   write("Guild rank: "+grank+"\n");
   write("Guild exp:  "+gexp+"\n");
   write("[=======================]\n");
   write("\n");
   return 1;
}

stats() {
   int str, sta, wil, mag, pie, ste, luc, intel, i, name;
   object list;

   list = users();
write("[================================================================]\n");
   write(justify("Name:",12)+justify("Str:",6)+justify("Sta:",6)+
	 justify("Wil:",6)+justify("Mag:",6)+justify("Pie:",6)+
	 justify("Ste:",6)+justify("Luc:",6)+justify("Int:",6)+"\n");
   write(justify("-----",12)+justify("----",6)+justify("----",6)+
	 justify("----",6)+justify("----",6)+justify("----",6)+
	 justify("----",6)+justify("----",6)+justify("----",6)+"\n");
   for(i=0; i < sizeof(list); i++) {
    if(list[i]->query_level() < 21) {
     name = capitalize(list[i]->query_real_name());
     str = list[i]->query_attrib("str"); sta = list[i]->query_attrib("sta");
     wil = list[i]->query_attrib("wil"); mag = list[i]->query_attrib("mag");
     pie = list[i]->query_attrib("pie"); ste = list[i]->query_attrib("ste");
     luc = list[i]->query_attrib("luc"); intel = list[i]->query_attrib("int");
     write(justify(name,12)+justify(str,6)+justify(sta,6)+justify(wil,6)+
	   justify(mag,6)+justify(pie,6)+justify(ste,6)+justify(luc,6)+
	   justify(intel,6)+"\n");
    }
   }
write("[================================================================]\n");
   return 1;
}

set_attrib(str) {
   string who, attrib;
   int num;
   
   if(!str) 
     return 0;
   sscanf(str, "%s %s %d", who, attrib, num);
   if(!TARGET) {
     write(CWHO+" is not on now.\n");
     return 1;
   }
   TARGET->set_attrib(attrib, num);
   write(CWHO+"'s attrib "+attrib+" has been set to "+num+"\n");
   return 1;
}

true_inventory(str) {
   object ob, invob;
   int cnt;
   string sh_str;
   
   if(!str)
     str = this_player()->query_real_name();
   if(str == "here")
     str = file_name(environment(this_player()));
   invob = find_living(str);
   if(!invob)
     invob = find_object(str);
   if(!invob)
     invob = present(str, DEST);
   if(!invob) {
     write("Not a valid object!\n");
     return 1;
   }
   cnt = 0;
   ob = first_inventory(invob);
   write("\n");
   write(invob);
   write("   "+invob->short()+"\n");
   while(ob) {
     cnt += 1;
     sh_str = ob->short();
     write(cnt+":\t");
     write(ob);
     write("   "+sh_str+"\n");
     ob = next_inventory(ob);
   }
   return 1;
}

remote_destruct(str) {
   object ob;
   string what; 

   if(!str) {
     write("You must give an object to destruct.\n");
     return 1;
   }
   ob = find_living(str);
   if(!ob)
     ob = find_object(str);
   if(!ob) {
     write("Not a valid object!\n");
     return 1;
   }
   write("Destructing: "); write(ob); write("   "+ob->short()+"\n");
   destruct(ob);
   return 1;
}

remote_destruct_inventory(string what) {
   object ob, invob, next_invob;

   if(!what)
     return 0;
   if(what == "here")
     what = file_name(environment(this_player()));
   ob = find_living(what);
   if(!ob)
     ob = find_object(what);
   if(!ob) {
     write("Not a valid object!\n");
     return 1;
   }
   invob = first_inventory(ob);
   while(invob) {
     next_invob = next_inventory(invob);
     if(!query_ip_number(invob) && !invob->id("ND")) {
       write("Destructing: "); write(invob); write(invob->short()+"\n");
       destruct(invob);
     }
     invob = next_invob;
   }
   return 1;
}

players() {
   object list;
   string name;
   int lvl, gp, exp, qstpts;
   int i, ac, wc;

   list = users();
   write("Players logged on:\n");
   write("[==============================================================]\n");
   write(justify("Name:",14)+justify("Level:",10)+justify("Money:",10));
   write(justify("Exp:",12)+justify("Qst:",8)+justify("Wc:",6));
   write(justify("Ac:",6));
   write("\n");
   write(justify("-----",14)+justify("------",10)+justify("------",10));
   write(justify("----",12)+justify("----",8)+justify("---",6));
   write(justify("---",6));
   write("\n");
   for(i=0; i < sizeof(list); i++) {
      name = capitalize(list[i]->query_real_name());
      lvl = list[i]->query_level();
      gp = list[i]->query_money();
      exp = list[i]->query_exp();
      qstpts = list[i]->query_quest_point();
      wc = list[i]->query_wc();
      ac = list[i]->query_ac();
      if(lvl < 21) {
	write(justify(name,14)+justify(lvl,10)+justify(gp,10)+justify(exp,12));
	write(justify(qstpts,8)+justify(wc,6)+justify(ac,6));
	write("\n");
      }
   }
   write("[==============================================================]\n");
   return 1;
}

/*
 * Funtions to check players quicktyper info
 */

quicktyper_info(str) {
   object typer;
   string tmp, who;
   
   if(!str || sscanf(str, "%s %s", tmp, who) != 2) {
     write("Usage: q <a/h> <player>\n");
     return 1;
   }
   if(tmp != "a" && tmp != "h") {
     write("First argument must be either 'a' of 'h'.\n");
     return 1;
   }
   if(!TARGET) {
     write(CWHO+" is not on.\n");
     return 1;
    }
    typer = present("quicktyper", TARGET);
    if(!typer) {
      write(CWHO+" does not have a quicktyper.\n");
      return 1;
    }
    if(tmp == "a") 
      write(CWHO+"'s quicktyper alias':\n");
    if(tmp == "h")
      write(CWHO+"'s quicktyper history:\n");
    write("[====================================]\n");
    if(tmp == "a")
      typer->alias();
    if(tmp == "h")
      typer->history();
    write("[====================================]\n");
    return 1;
}

