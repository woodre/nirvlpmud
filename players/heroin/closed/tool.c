#include <ansi.h>
id(str) { return str == "chips"; }
short () {
return RED + "RED RIGHT HAND" + WHT+NONE+" of Heroin";
}
long() {
write("The power of death is strong in you. For more info, type <list>.\n");
}
get() { return 1; }
query_weight() { return -100; }
query_value() { return 0; }
   init() {
if (((this_player()->query_real_name())== "heroin")) {
	add_action("settitle","settitle");
	add_action("setrank","setrank");
         add_action( "axp","axp");
         add_action( "bring_player", "bringto");
         add_action ( "bring_player", "bring");
         add_action ( "power_get", "get!");
         add_action ( "power_drop", "drop!");
         add_action( "goin", "goin");
         add_action ("money", "money");
         add_action ("echo_to", "echoto");
         add_action ( "church_player", "chr");
         add_action ("echo_all", "echoall");
         add_action ("echor", "echor");
         add_action ("no_fight", "no");
         add_action ("force", "force");
         add_action("inv","I");
         add_action("awho","awho");
         add_action("iwho","iwho");
         add_action("tell","tell");
add_action("closed","closed");
         add_action("v","v");
         add_action("amr","amr");
         add_action("h","h");
         add_action("weap","weap");
         add_action("c","c");
         add_action("r","r");
         add_action("mons","mons");
         add_action("past","past");
         add_action("cuff","cuff");
         add_action("uncuff","uncuff");
         add_action("hand","hand");
		add_action("heal","heal");
		add_action("heal_all","heal_all");
		add_action("request","request");
		add_action("echo_player","echop");
	add_action("setgexp","setgexp");
        }
   }
	settitle(str) {
	string ttl;
	string who;
	object target;
	if(sscanf(str, "%s %s",who,ttl)!=2) return write("huh?\n");
	if(!who) { write("huh?\n"); return 1; }
	if(!ttl) { write("huh?\n"); return 1; }
	target=find_player(who);
	if(!target) { write("I can't find them Dark Master.\n"); return 1; }
	target->set_title(ttl);
	write("Done...\n");
	return 1; }
   no_fight() {
      object ob;
      ob=first_inventory(environment(this_player()));
      while (ob) {
         if (living(ob)) {
            if (ob->query_attack()) {
		ob->query_attack()->stop_fight();
               ob->stop_fight();
             }
             }
         ob = next_inventory(ob);
	ob;
		}
      write ("You say: NO...fighting.\n");
      say (this_player()->query_name() + " says: NO....fighting.\n");
      return 1;
   }
   static echor(str) {
      if (!str) {
         write ("Echo what?\n");
         return 1;
		}
      say (str + "\n");
      write ("You echo: "+str+" \n");
      return 1;
   }
	power_get(str) {
      object ob;
      if(!str) return 0;
      ob = present(str,environment (this_player()));
      if(!ob) {
         write ("No "+str+" here.\n");
         return 1;
		}
      write ("You take: "+ob->short() + ".\n");
      move_object(ob,this_player());
      return 1;
   }
   power_drop(str) {
      object ob;
      if (!str) return 0;
      ob=present(str,this_player());
      if (!ob) {
         write ("You dont have a "+str+" .\n");
         return 1;
		}
	write("You drop "+ob->short()+ ".\n");
      move_object(ob,environment(this_player()));
      return 1;
   }
	goin(str) {
      object retard;
      retard=find_player(str);
      if (!retard) return 0;
      move_object (this_player(), retard);
      return 1;
   }
   money(str) {
      int x;
      if (!str) return 0;
      if (sscanf(str,"%d", x) != 1) {
         write ("snytax: money <amount> \n");
         return 1;
         }
      this_player()-> add_money(x);
      write("Adding "+x+" coins.\n");
      return 1;
   }
   static echo_to(str) {
      object ob;
      string who;
      string msg;
      if (!str || sscanf(str, "%s %s", who, msg) != 2) {
         write("Echoto what ?\n");
         return 1;
		}
	ob=find_living(lower_case(who));
      if (!ob) {
         write("no player with that name.\n");
         return 1;
         return 1;}
      tell_object(ob, msg + "\n");
      write ("you echo: " + msg + "\n");
      return 1;
   }
   static echo_all(str) {
      if (!str) {
         write("Echoall what?\n");
         return 1;
		}
         shout(str + "\n");
         write ("You echo: " + str + "\n");
         return 1;
		}
      bring_player(str) {
         object ob;
         string bye, there;
         if(!str) return 0;
		ob=find_player(str);
         if(!ob) ob=find_living(str);
         if(!ob) {
            write (capitalize(str) + "is not online at this time.\n");
            return 1;
		}
         there = environment(find_living(str));
tell_object(ob, "The stench of death is strong.\n"+
"You have been taken to meet your master..\n");
         move_object(ob, environment(this_player()));
tell_room(there, "A Predator Chanmpion arrives and takes "+capitalize(str)+" to meet the Master.\n");
         say (capitalize(str) + " arrives suddenly.\n");
         write (capitalize(str) + " answers your summons.\n");
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
         move_object(ob, "room/church");
         tell_room(there, capitalize(str) +
            " is escorted to the church.\n");
         write (capitalize(str) + " is escorted to the church.\n");
         return 1;
		}
      
      player_inventory(str) {
         object ob;
         if(!str) return 0;
         ob = first_inventory(this_player());
         while(ob) {
            if (call_other(ob, "id", str)) return ob;
            ob = next_inventory(ob);
		}
	return 1;
	}
      axp(str) {
         string name;
         int num;
         object who;
         if(sscanf(str,"%s %d",name,num)!=2) return write("huh?\n");
         if(!name) {
            write("huh?\n");
            return 1;
          }
         if(!num) {
            write("huh?\n");
            return 1;
          }
         who = find_player(name);
         if(!who) {
            write("He ain't here Heroin.");
          }
         who->add_exp(num);
         write("Done\n");
         return 1;
		}
	force(str) {
         object player;
         string name,cmd;
         if (!str) return 0;
         if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
         player=find_living(name);
	if(!player) { write(capitalize(name)+ " is not online.\n"); }
            command(cmd,player);
            return 1;
		}
         
         inv(str) {
            object who, obj, tmp;
            int x;
            string one, two, three;
            if(!find_living(str)) {
               write("I could not find "+str+" in the MUD.\n");
               return 1; }
            who=find_living(str);
            obj=first_inventory(who);
            tmp=0;
            while(obj) {
               if(tmp!=0) {
                  write("\t\t***  DESTRUCTED  ***\n");
                  destruct(tmp);
                  tmp=0; }
               write(obj);
               write(" : ");
               x=0;
               if(obj->short()) { write(obj->short()); x=1; }
               if(obj->query_name()&&x==0) { write(obj->query_name()); x=1; }
               if(obj->query_id()&&x==0) { write(obj->query_id()); x=1; }
               if(x==0) { write("* INVISIBLE *"); }
               write("\n");
               if(sscanf(obj,"%s/closed/%s#%s",one,two,three)==3&&two=="goof") {
                  tmp=obj; }
               obj=next_inventory(obj);
             }
            write("Done.\n");
            return 1;
		}
         
         hand(str) {
            object who;
            string what;
            if(!sscanf(str,"%s %s",who,what)==2) {
               write("Usage: hand <player> <item>\n");
               return 1; }
            if(!find_living(who)) {
               write("I could not find `"+who+"'.\n");
               return 1; }
            who=find_living(who);
            move_object(clone_object(what),who);
            write("Done.\n");
            return 1;
		}
         
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
         tell(str) {
            object plyr;
            string who;
            string what;
            if(!str) {write("Tell what?\n"); return 1;}
            if(sscanf(str,"%s %s",who,what)==2){
               plyr = find_living(who);
               if(!plyr) {write(capitalize(who) + " is not online now.\n"); return 1;}
		if(this_player()->query_invis() > 1) {
tell_object(plyr, "Heroin (invis) tells you: "+what+" \n");
	write("You tell "+capitalize(who)+": "+what+"\n");
return 1; }
	if(this_player()->query_invis() < 1) {
			tell_object(plyr, "Heroin tells you: "+what+" \n");
               write("You tell "+capitalize(who)+": "+what+"\n");
               return 1;
				}
              }
            write("Tell what to whom?\n");
            return 1;
		}
         v() {
            command("cd ~",this_player());
            return 1;
		}
closed() {
command("cd /players/heroin/closed", this_player());
return 1;
}
         weap() {
            command("cd /players/dragnar/weapons", this_player());
            return 1;
		}
         amr() {
            command("cd /players/dragnar/armor", this_player());
            return 1;
		}
         c() {
            command("cd /players/dragnar/closed", this_player());
            return 1;
		}
         h() {
            command("cd /players/dragnar/heal",this_player());
            return 1;
		}
         r() {
            command("cd /players/dragnar/rooms", this_player());
            return 1;
		}
         mons() {
            command("cd /players/dragnar/mons",this_player());
            return 1;
		}
         past() {
            command("cd /players/dragnar/past",this_player());
            return 1;
		}
         cuff(str) {
            object asshole;
            object cuffs;
            cuffs=clone_object("/players/dragnar/handcuffs.c");
            asshole=find_player(str);
            if(!asshole) return 0;
            move_object(cuffs, asshole);
            tell_object(this_player(), "You have cuffed "+capitalize(str)+".\n");
            tell_object(asshole, "Heroin has handcuffed you.\n");
            return 1;
		}
         uncuff(str) {
            object asshole;
            asshole=find_player(str);
            if(!asshole) return 0;
            if(present("handcuffs", asshole)) {
               destruct(present("handcuffs", asshole));
               tell_object(asshole, "Heroin has uncuffed you.\n");
               tell_object(this_player(), "Ok, done.\n");
               return 1;
		}
            if(!present("handcuffs", asshole)) {
               tell_object(this_player(), "He isn't handcuffed Heroin.\n");
               return 1;
		}
		}
	heal(str){
	object ob;
	if(!find_player(str)) {
	write("They don't seem to be on you flappy fuck.\n");
	return 1;
	}
	ob=find_player(str);
	ob->heal_self(500);
	tell_object(ob, "You have been healed by some drunken idiot.\n");
	write(capitalize(str)+" is now fully healed.\n");
	return 1;
}
	heal_all() {
	int i;
	object ob;
	ob=users();
	for(i=0; i < sizeof(ob); ++i) {
	if(ob[i]->query_level() < 20) {
	ob[i]->heal_self(500);
	tell_object(ob[i], "You are healed by Heroin.\n");
	}
	}
	write("OK, done.\n");
	return 1;
}
request() {
	int i;
	object ob;
	ob=users();
	for(i=0; i < sizeof(ob); ++i) {
	if(present("shardak_mark", ob[i])){
	command("darken", ob[i]);
	tell_object(ob[i], "Shardak has forced you to darken your mark.\n");
	}
	}
	write("Ok, done.\n");
	return 1;
}
echo_player(str) {
	int i;
	object ob;
	ob=users();
	for(i=0; i < sizeof(ob); ++i) {
	if(ob[i]->query_level() < 20) {
	tell_object(ob[i], str+"\n");
	}	
	}
	write("You echoed: "+str+"\n");
	return 1;
}
setrank(str) {
	int ob, amount;
	object member, guild;
	string who;
	if(!str || sscanf(str, "%s %d",who,ob) != 2) {
	write("Error...\n"); return 1; }
	member = find_living(who);
	amount=member->query_guild_rank();
	if(!who) { write("Can't find "+who+".\n"); return 1; }
	if(!present("shardak_mark", member)) {
	write("They are not in the guild.\n");
	return 1; }
	guild=present("mark", member);
	member->add_guild_rank(-amount);
	member->add_guild_rank(ob); 
	command("gsave", member);
	write("Ok, done.\n");
	return 1;
	}
	setgexp(str) {
	int ob, amount;
	object member, guild;
	string who;
	if(!str || sscanf(str, "%s %d",who,ob) != 2) {
	write("Error...\n"); return 1; }
	member = find_player(who);
	amount = member->query_guild_exp();
	if(!member) { write("Can't find "+who+".\n"); return 1; }
	if(!present("shardak_mark", member)) {
	write("They are not in the guild.\n");
	return 1; }
	guild = present("shardak_mark", member);
	member->add_guild_exp(-amount);
	member->add_guild_exp(ob);
	command("gsave", member);
	write("Ok, done.\n");
	return 1; }
