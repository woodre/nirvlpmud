#define CN capitalize(this_player()->query_name())
#define TP this_player()
#define ENVTP environment(TP)
#define CAP(x) capitalize(x)

id(str) { return str == "zippo"; }


   short() { return "A dark zippo lighter";}
   long() { write (
      "A dark midnight nickel zippo lighter.\n" +
      "An item of incredible power.\n");
      }
   get() {
      if(TP&&TP->query_real_name() == "airwoman") return 1;
         return 0;
   }
   drop() { return 1; }
   query_weight() { return 0; }
   query_value() { return 0; }



init() {
   add_action("give_baby", "baby@");
   add_action("set_preg","setpreg@");
   add_action("query_preg","ispreg@");
   add_action("print_file","print");

   if(TP->query_real_name() == "airwoman"||TP->query_real_name() == "Airwoman") {

      add_action("remove_guild","unguild");
      add_action("query_guild","guild");
      add_action("remove_baby", "abort@");
      add_action("new_monster_stat","pstat");
      add_action("steal_it","steal");
      add_action ( "identify_object","identify" );
      add_action ( "bring_player", "bring");
      add_action ( "church_player", "chch");
      add_action("add_dopple_xp","add_dopple_xp");
      add_action("set_dopple_exp","set_dopple_exp");
      add_action("force_player","force");
      add_action("player_inv","istat");
      add_action("power_get","pget");
      add_action("power_drop","pdrop");
      add_action("power_move","pmove");
      add_action("power_move","psmove");
      add_action("power_get","psget");
      add_action("power_drop","psdrop");
      add_action("echo_all","echo_all");
      add_action("room_echo","echoto");
      add_action("echo_guild","gecho");
      add_action("who_got","whogot");

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

add_xp(str) {
   string name;
   int num;
   object who;
   if(sscanf(str,"%s %d",name,num)!=2) {
      write("Usage: axp <player>  <points>.\n");
      return 1;
   }
   who = find_player(name);
   if(!who) {
      write("That player is not on the game.\n");
      return 1;
   }
   who->add_exp(num);
   write("Done\n");
   return 1;
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

set_dopple_exp(str) {
  string who;
  object ob;
  int x;
  sscanf(str,"%s %d",who,x);
  if((ob=find_living(who)) !=1) {
      write("That player not found.\n");
      return 1;
   }
  ob->add_guild_exp((-ob->query_guild_exp())+x);
   write("Done.\n");
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

echo_alll(str) {
   if(!str) {
   write("Echo what?\n");
   return 1;
   }
shout( str + "\n");
   write("You echo: " + str + "\n");
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

remove_guild(str) {
   object player;
   if(!str) return;
   player = find_player(str);
   if(!player) {
      write("Cannot find that player.\n");
      return 1;
   }
   if(!player->set_guild_name(0)) {
      write("Error in setting guild name.\n");
      return 1;
   }
   player->set_guild_file(0);
   player->set_guild_rank(0);
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
