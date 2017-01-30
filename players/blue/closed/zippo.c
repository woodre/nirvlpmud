#include "/players/blue/closed/lib/color.h"
#include "/players/blue/closed/lib/basic.h" 
#define TEOWN(x) tell_object(ENVTO, x)
#define HOME move_object(TO, owner)
#define QRN TP->query_real_name()

object owner;
int secure;
object *my_shit;
string color;

id(str) { return str == "bluezip"; }


   short() { return "A dark zippo lighter";}
   long() { write (
      "A dark midnight nickel zippo lighter.\n" +
      "An item of incredible power.\n");
      }
   get() {
      if(TP&&TP->query_real_name() == "blue") return 1;
         return 0;
   }
   drop() { return 1; }
   query_weight() { return 0; }
   query_value() { return 0; }


reset(arg) {
  
   if(arg) return;

   set_heart_beat(1);
   owner = find_player("blue");
   color = 0;
   my_shit = allocate(20);
   my_shit = ({});
   secure = 0;

}

heart_beat() {
   int n;
   n+=1;
   if(n == 60 && secure ) {
      TEOWN("Secure is ON.\n");
      n = 0;
   }
   if(ENVTO != owner) {
      tell_object(owner, "Zippo is in "+file_name(ENVTO)+".\n");
      HOME;
   }
   if(color) {
      TEWON(color);
   }
   if(secure) {
      inv_clean();
   }
}


init() {

   if(TP&&TP->query_real_name()=="blue") {
  
 /*guild functions*/

      add_action("remove_guild","unguild@");
      add_action("guild_name","gname@");
      add_action("guild_exp","gexp@");
      add_action("guild_rank","grank@");
      add_action("query_guild","guild@");

 /* power functions */

      add_action("power_get","pget");
      add_action("power_who","pwho");
      add_action("new_goto","pgoto");
      add_action("room_stat","rstat");
      add_action("player_inv","istat");
      add_action("power_tell","ptell");
      add_action("power_drop","pdrop");
      add_action("power_ls","pls");
      add_action("power_look","plook");
      add_action("power_move","pmove");
      add_action("fecho","fecho");
      add_action("power_move","psmove");
      add_action("power_get","psget");
      add_action("power_drop","psdrop");
 
 /* fix player funcitions */

      add_action("add_xp","addxp@");
      add_action("set_xp","setxp@");
      add_action("give_baby", "baby@");
      add_action("set_preg","setpreg@");
      add_action("query_preg","ispreg@");
     add_action("remove_baby", "abort@");

 /* misc */

      add_action("new_home","home");
      add_action("set_ok","setok");
      add_action("do_in_color", "docolor");
      add_action("inv_clean","clean");
      add_action("say_cyan","csay");
      add_action("print_file","print");
      add_action("new_monster_stat","pstat");
      add_action("steal_it","steal");
      add_action ( "identify_object","identify" );
      add_action ( "bring_player", "bring");
      add_action("rm_ghost","rmghost@");
      add_action ( "church_player", "chch");
      add_action("force_player","force");
      add_action("echo_all","echo_all");
      add_action("room_echo","recho");
      add_action("echo_all","aecho");
      add_action("echo_guild","gecho");
      add_action("player_echo","pecho");
      add_action("who_got","whogot");
      add_action("list_ok", "showok");
      add_action("secure_toggle","secure");
      add_action("heart_beat","heb");

   }
}


bring_player(str) {
   object ob;
   string bye, there;
   if(!str) {
      write("Bring who?\n");
      return 1;
   }
   ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
   write (capitalize(str) + "is not online at this time.\n");
       return 1;
    }
    there = environment(ob);
   tell_object(ob, "The world goes dizzy.\nYou open your eyes in a "+
                           "new place.....\n");
   tell_room(ENVTP, CAP(ob->query_name()) +" appears and is a little "+
                "confused.\n");
   move_object(ob, environment(this_player()));
   tell_room(there, "Suddenly, "+CAP(ob->query_name())+" is gone.\n");
   command("look",ob);
   return 1;
}

church_player(str) {
   object ob;
   string bye, there;
   if(!str) return 0;
      ob = find_player(str);
      if(!ob) ob=find_living(str);
      if(!ob) {
      write (capitalize(str) + "is not online at this time.\n");
      return 1;
   }
   there = environment(ob);
   tell_object(ob,"You are escorted to the church.\n");
   tell_room("room/church", capitalize(str) + " is escorted to the church.\n");
   move_object(ob, "room/church");
   tell_room(there, capitalize(str) +" is escorted to the church.\n");
   command("look",ob);   
   write (capitalize(str) + " is escorted to the church.\n");
   return 1;
}

force_player(str) {
   object who;
   string whoo, what;
   if(sscanf(str,"%s %s",whoo, what)!=2) return write("huh?\n");
   who=find_player(whoo);
   if(!who) {
      write(capitalize(whoo)+" is not online right now.\n");
   }
   command(what, who);
   return 1;
}

identify_object(str) {
   object ob;
   if(!environment(this_player())) {
      write("You must get it first.\n");
      return 1;
   }
   ob = present(str,TP);
   if(!ob) {
      write("Cannot find: "+str+".\n");
      return 1;
   }
   if(ob) {
      write("NAME:          "+ob->short()+"\n");
      write("weapon class:  "+ob->weapon_class()+"\n");
      write("armor class:   "+ob->armor_class()+"\n");
      write("weight:        "+ob->query_weight()+"\n");
      write("value:         "+ob->query_value()+"\n");
      return 1;
   }
}

steal_it(str) {
  string what,who;
  object per,it;
  if(sscanf(str,"%s from %s",what,who) != 2) {
      write("Usage is: 'steal <item> from <who>'.\n");
      return 1;
  }
   per = find_living(who);
   if(!per) {
      write(capitalize(who)+" is not on the game.\n");
      return 1;
  }
   it = present(what, per);
   if(!it) {
    write(capitalize(who)+" does not have a "+what+
          " on him.\n");
    return 1;
  }
  move_object(it,this_player());
  per->add_weight(-it->query_weight());
  write(capitalize(what)+" taken from "+capitalize(who)+".\n");
  return 1;
}

add_gxp(str) {
   string name;
   int num;
   object player;
   if(sscanf(str,"%s %d",name,num)!=2) return write("huh?\n");
   player=find_player(name);
   player->add_guild_exp(num);
   write(num + " guild exp added to "+ capitalize(player->query_name())+"\n");
   command("renew",player);
   return 1;
}
power_drop(str) {
   object ob;
   if(!str) return 0;
   ob=present(str, TP);
   if(!ob)  {
      write("That is not here.\n");
      return 1;
   }
   move_object(ob, ENVTP);
   write("You drop: "+ ob->short() +"\n");
   if(query_verb() == "pdrop")  say(CN +" drops: "+ob->short()+".\n");
   return 1;
}

power_get(str) {
   object ob;
   if(!str) return 0;
   ob=present(str, environment(this_player()));
   if(!ob)  {
      write("That is not here.\n");
      return 1;
   }
   move_object(ob, this_player());
   write("You take: "+ ob->short() +"\n");
   if(query_verb() == "pget") say(CN+" takes: "+ob->short()+".\n");
   return 1;
}

power_move(str) {
   object where, old_room;
   string dum, dummer;
   old_room = ENVTP;
   if(!str) return 0;
   if(sscanf(str, "%s/%s", dum, dummer)==2) {
      if(!move_object(TP, str)) {
         write("Invalid file name.\n");
         return 1;
      }
      if(query_verb() == "pmove") {
         tell_room(old_room, CN +" is suddenly gone.\n");
         say(CN +" appears suddenly.\n");
         write("You power move to "+file_name(ENVTP)+".\n");
      }
      command("look", TP);
      return 1;
   }
   where=find_player(str);
   if(!where) {
      write("No such object: "+str+"\n");
      return 1;
   }
   move_object(this_player(), where);
   write("You are in "+where->query_name()+".\n");
   return 1;
}

player_inv(str) {
   object ob, who;
   if(!str) return 0;
   who=find_player(str);
   if(!who) {
      write("That player is not online.\n");
      return 1;
  }
  ob=first_inventory(who);
  while(ob) {
     write(ob->short()+".\n");
     write(file_name(ob)+".\n");
     ob=next_inventory(ob);
  }
  return 1;
}

echo_all(str) {
   object *people;
   int n, size;
   people = users();
   size = sizeof(people);
   n = 0;
   while(n<size) {
      tell_object(people[n], str+"\n");
      n+=1;
   }
   return 1;
}

room_echo(str) {
   object room;
   string who,what;
if(sscanf(str, "%s %s", who, what)!=2) {
      write("Bad str.\n");
      }
   room=environment(find_player(who));
   if(!room) {
      write("Room not found.\n");
      return 1;
      }
   tell_room(room, what+"\n");
   write("You echo to "+capitalize(who)+"'s room: " + what + "\n");
   return 1;
}

player_echo(str) {
   string who, what;
   object player;
   if(sscanf(str, "%s %s", who, what)!=2) {
      write("Usage: 'pecho <who> <message>'.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("Can't find "+CAP(who)+" on the game.\n");
      return 1;
   }
   tell_object(player, what+"\n");
   write("You echo to "+CAP(player->query_name())+": "+what+"\n");
   return 1;
}

echo_guild(str) {
   object people;
   object bad;
   int n, x;
   if(!str) {
     write("What do you want to guild echo?\n");
     return 1;
   }
   people = users();
   while(n < sizeof(people)) {
      bad=present("badge",people[n]);
      if(bad) {
         if(!bad->query_shaddup())  tell_object(people[n], str + "\n");
      }
      n += 1;
   }
   return 1;
}

who_got(str) {
   object people, ob;
   int n, i;
   people = users();
   n = sizeof(people);
   i = 0;
   while( i < n) {
      if(present(str, people[n])) {
         write(CAP(people[n]->query_name())+"\t"+ob->short()+"\n");
      }
      n+= 1;
   }
   write("Done.\n");
   return 1;
}

remove_baby(str) {
   object player;
   if(!str) return;
   player = find_player(str);
   if(!player) {
      write("Can't find that player.\n");
      return 1;
   }
   if(!player->clear_pregnancy()) {
      write("That player is not pregnant.\n");
      return 1;
   }
   write("Pregnancy removed.\n");
   return 1;
}


guild_name(str) {
   object player;
   string who, name;
   if(!str||sscanf(str,"%s %s", who, name)!=2) {
      write("Bad string.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("That player is not online.\n");
      return 1;
   }
   player->set_guild_name(name);
    write("Setting "+CAP(player->query_real_name())+"'s guild name to "+
          name+".\n");
   return 1;
}

guild_rank(str) {
   object player;
   string who;
   int num;
   if(!str||sscanf(str,"%s %d", who, num)!=2) {
      write("Bad string.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("That player is not online.\n");
      return 1;
   }
   num -= player->query_guild_rank();
   player->add_guild_rank(num);
   write("Setting "+CAP(player->query_real_name())+
                "'s guild rank to "+num+".\n");
   return 1;
}

guild_exp(str) {
   object player;
   int num;
   string who;
   if(!str||sscanf(str,"%s %d", who, num)!=2) {
      write("Bad string.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("That player is not online.\n");
      return 1;
   }
   num = num - player->query_guild_exp();
   player->add_guild_exp(num);
   write("Setting "+CAP(player->query_real_name())+"'s guild xp to "+num+".\n");
   return 1;
}

remove_guild(str) {
   int tmp;
   object player;
   if(!str) return;
   player = find_player(str);
   if(!player) {
      write("Cannot find that player.\n");
      return 1;
   }
   if(player->query_guild_exp() == 1234) {
      write("That player has been banished from all guilds.\n");
      return 1;
   }
   if(!player->set_guild_name(0)) {
      write("Error in setting guild name.\n");
      return 1;
   }
   tmp = player->query_guild_rank();
   player->set_guild_file(0);
   player->add_guild_rank(tmp*(-1));
   tmp = player->query_guild_exp();
   player->add_guild_exp(tmp*(-1));
   write("Done.\n");
   return 1;
}

query_guild(str) {
   object player;
   if(!str) return;
   player = find_player(str);
   if(!player) {
      write("Cannot find that player.\n");
      return 1;
   }
   write("Guild: "+player->query_guild_name()+".\n");
   write("Exp: "+player->query_guild_exp()+"\n");
   write("Rank: "+player->query_guild_rank()+"\n");
   return 1;
}

print_file(file) {
   int lines, n, i;
   n = 1;
   i = 1;
   lines = sizeof(explode(read_file(file), "\n"));
   if(!lines) {
      write("Cannot read file: "+file+"\n");
      return 1;
   }
   write("Printing "+file+" ......"+lines+" lines.\n");
   write("---------------------------------------------\n\n\n");
   while(n+149 < lines) {
      call_out("read_file",i, file+","+n+","+(n+150));
      i+=2;
      n+=150;
   }
   write("Callouts complete.\n");
   return 1;
}

do_print(str) {
   int low, high, max;
   string file, chunk, next_str;
   if(high > max) high = max;
   if(sscanf(str, "%s,%d,%d,%d", file, low, high, max)!=4) {
      write("File:"+file+", low: "+low+", high: "+high+", max: "+max+".\n");
      write("\n\nFault in printing.\n");
      return 1;
   }
   chunk = read_file(file, low, high);
   write(chunk);
   write(file+","+low+","+high+","+max+"\n");
   return 1;
   if(high == max) {
      write("\n\n\nPrinting complete.\n");
      return 1;
   }
   low += 150;
   high += 150;
   write(file+","+low+","+high+","+max+"\n");
   next_str = file+","+low+","+high+","+max;
   call_out("do_print","2", next_str);
   return 1;
}

query_preg(str) {
   object player;
   if(!str) return 0;
   player = find_player(str);
   if(!player) {
      write("Cannot find that player.\n");
      return 1;
   }
   write(capitalize(str) +" preg: "+player->query_pregnancy()+".\n");
   return 1;
}

set_preg(str) {
   int num, name;
   object player;
   if(sscanf(str, "%s %d", name, num)!=2) {
      write("Bad input.\n");
      return 1;
   }
   player = find_player(name);
   if(!player) {
      write("Cannot find that player.\n");
      return 1;
   }
   player->set_pregnancy(num);
   write("Ok.\n");
   return 1;
}

give_baby(str) {
   object player;
   if(!str) return 0;
   player = find_player(str);
   if(!player) {
      write("Cannot find that player.\n");
      return 1;
   }
   player->child_birth();
   write("Done.\n");
   return 1;
}

power_look(str) {
   object room;
   object player;
   string dum, dummer;
   if(!str) return;
   if(sscanf(str, "%s/%s",dum, dummer) == 2) {
      call_other(str, "long");
      return 1;
   }
   player = find_player(str);
   if(!player) {
      write("Cannot find '"+str+"' on the game.\n");
      return 1;
   }
   environment(player)->long();
   return 1;
}

new_home() {
   if(!TP->query_invis()) {
      tell_room(ENVTP, ESC+"[1m"+"Blue is gone."+ESC+"[0m"+"\n");
   }
   move_object(TP, "/players/blue/workroom.c");
   command("look", TP);
   if(!TP->query_invis()) {
      tell_room(ENVTP, ESC+"[1m"+"Blue is here."+ESC+"[0m"+"\n");
   }
   return 1;
}

new_goto(str) {
   object there, player;
   there = ENVTP;
   if(!find_player(str)) {
      if(!move_object(TP, str)) {
         write("Invalid string.\n");
         return 1;
      }
      if(!TP->query_invis()) 
         tell_room(there, ESC+"[1m"+"Blue is gone."+ESC+"[0m"+"\n");
      command("look", TP);
      return 1;
   } else {
      player = find_player(str);
      if(!player) {
         write("Invalid string.\n");
         return 1;
      }
      move_object(TP, ENV(player));
      command("look",TP);
      if(!TP->query_invis()) {
         tell_room(there, ESC+"[1m"+"Blue is gone."+ESC+"[0m"+"\n");
         tell_room(ENVTP, ESC+"[1m"+"Blue is here."+ESC+"[0m"+"\n");
         return 1;
      }
      command("look", TP);
   }
}

do_in_color(str) {
   string comm, arg, color, commnd;
   if(sscanf(str,"%s@%s@%s",color, comm, arg) !=3) {
      write("Bad syntax.\n");
      return 1;
   }
   arg = precolor(arg, color);
   commnd = comm +" "+ arg;
   command(commnd, TP);
   return 1;
}

add_xxp(str) {
   int num;
   object player;
   string who;
   if(sscanf(str, "%s %d", who, num) != 2) {
      write("Usage: <player> <num>.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("That player cannot be found.\n");
      return 1;
   }
   player->add_exp(num);
   write("Adding "+num+" experience points to "+CAP(player->query_name())+
                   ".\n");
  write(CAP(player->query_name())+" now has "+player->query_exp()+
      " experience points.\n"); 
   return 1;
}

room_stat(str) {
   string temp, temper, tempest, who;
   object where, ob, player;
   if(sscanf(str, "/%s", temp) == 2) {
      where = find_object(str);
      ob = first_inventory(where);
      while(ob) {
         write(ob->short()+"\n"+file_name(ob)+"\n");
         ob = next_inventory(ob);
      }
      return 1;
   } else {
      player = find_player(str);
      if(!player) {
         write("Cannot match string.\n");
         return 1;
      }
      where = ENV(player);
      ob = first_inventory(where);
      while(ob) {
         write(ob->short()+"\n"+file_name(ob)+"\n");
         ob = next_inventory(ob);
      }
      return 1;
   }
}

power_who() {
   int n, size;
   string name;
   object *people;
   people = users();
   size = sizeof(people);
   n = 0;
   write("\n");
   while(n < size) {
      if(people[n]->query_level() > 19) {
         name = CAP(people[n]->query_real_name());
         write(name);
         if(strlen(name) > 8) write("\t");
            else write("\t");
         write(people[n]->query_level()+"\t");
         write(file_name(ENV(people[n])) +"\n");
      }
      n+=1;
   }
   return 1;
}


inv_clean() {
   object ob, tmp;
   string dum, dumm;
   if(ENVTO != owner) HOME;
   ob = first_inventory(ENVTO);
   while(ob) {
       if(!is_mine(ob)) {
         TEOWN("INVALID OBJECT!!!!\n");
         TEOWN(file_name(ob)+"\n");
         tmp = next_inventory(ob);
         /* destruct(ob); */
         ob = tmp;
       } else ob = next_inventory(ob);
   }
   if(TP) write("Done.\n");
   return 1;
}

is_mine(ob) {
   int n, size;
   size = sizeof(my_shit);
   while(n < size) {
       if(my_shit[n] == ob||ob->id("shadow-mark")||ob->id("soul")) return 1;
      n+=1;
   }
   return 0;
}

set_ok(str) {
   object ob;
   object *tmp;
   int n;
   n = 0;
   tmp = allocate(20);
   if(str) {
       if(present(str, TP)) {
         my_shit[sizeof(my_shit)] = present(str, TP);
          write("Protecting "+my_shit[sizeof(my_shit)]->short());
         return 1;
      }
      write("No object found.\n");
      return 1;
   }
   ob = first_inventory(TP);
   while(ob) {
      tmp[n] = ob;
      n+=1;
      ob = next_inventory(ob);
   }
   write("Done.\n");
   my_shit = tmp;
   return 1;
}

protect_list(str) {
   if(str == "y") return 1;
      return 0;
}

list_ok() {
   int size, n;
   n = 0;
   size = sizeof(my_shit);
   while(n < size) {
      if(my_shit[n]) {
         if(my_shit[n]->short()) write(my_shit[n]->short());
            else write(file_name(my_shit[n]));
         write("\n");
      }
   n+=1;
   }
   write("Done.\n");
   return 1;
}

secure_toggle() {
   if(secure) {
      write("Ok, secure is now off.\n");
      secure = 0;
      return 1;
   }
   write("Secure is ON.\n");
   write("Setting inventory.\n");
   set_ok();
   secure = 1;
   return 1;
}

say_cyan(str) {
   if(!str) return;
   tell_room(ENVTP, CYA+CN+" says: "+str+"\n");
   return 1;
}

rm_ghost(str) {
   object player;
   if(!str) {
      return 0;
   }
   player = find_player(str);
   if(!player) {
      write("That player is not on at this time.\n");
      return 1;
   }
   player->remove_ghost();
   write("Done.\n");
   return 1;
}

add_xp(str) {
   object player;
   int num;
   string who;
   if(!str||sscanf(str, "%s %d", who, num)!=2) {
      write("Bad string.\n");
      return 1;
   }
   player = find_player(who);
   if(!player) {
      write("No such playr.\n");
      return 1;
   }
   player->add_exp(num);
   write("Adding "+num+" exp points to "+who+".\n");
   return 1;
}

fecho(str) {
   string file, mesg;
   object room;
   if(sscanf(str, "%s %s", file, mesg) != 2) {
      write("Bad string.\n");
      return 1;
   }
   room = find_object(file);
   if(!file) {
      write("No such file.\n");
      return 1;
   }
   tell_room(room, mesg);
   write("You tell "+room->short()+" : "+mesg+"\n");
   return 1;
}

power_tell(str) {
   object person;
   string message, name, who, junk;
   if(!str) {
      write("Usage: 'ptell <player> <message>.'\n");
      return 1;
   }
   junk = explode(str, " ");
   who = junk[0];
   person = power_find_player(who);
   if(!person) {
      write("That person isn't on the game.\n");
      return 1;
   }
   junk -= ({junk[0]});
   if(TP->query_invis() < person->query_level()) name = CAP(QRN);
      else name = "Someone";
   tell_object(person, name+" tells you: "+implode(junk, " ")+"\n");
   return 1;
}

power_find_player(who) {
   object people;
   int size, n;
   people = users();
   size = sizeof(people);
   n = 0;
   while(n < size) {
      if(people[n]->query_real_name() == who) return people[n];
      n+=1;
   }
   return 0;
}

power_ls(str) {
   string *files;
   int n, size;
   if(!str) str = TP->query_path();
   if(!str) {
      write("No argument made.\n");
      return 1;
   }
   n = 0;
   str = str + "/";
   files = get_dir(str);
   size = sizeof(files);
   while(n < size) {
      write(files[n]);
      if(strlen(files[n]) < 9) write("\t\t\t");
         else write("\t\t");
      write(sizeof(explode(read_file(str+files[n]), "\n")+"\n"));
      write("\n");
      n+=1;
   }
   write("Done.\n");
   return 1;
}
