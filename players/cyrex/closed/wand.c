#define ARCH 35
#define WIZ 21
#define LEVEL this_player()->query_level()
#define PATH this_player()->query_path()
#define FILENAME "players/cyrex/closed/wand"
#define PLAYERDIR "/players/"+this_player()->query_real_name()+"/"
#define SOULFILE "players/"+this_player()->query_real_name()+"/wand"
#define CLONE 0 /* 1 to enable the wands setmclone */
#define DEST 0 /* 1 to enable the wands setmdest */
#define STAT 0 /* 1 to enable extended stat.. location, IP, and mail_addr added
*/
#define ECHO 0 /* Enable the wands echo wiz, echo arch, echo player, and echo but *  */
#define Call(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ)
static object owner_ob,last_arg,seek,seeker,drag,dragger;
static object temp,ob;
static int wield,count;
static string alt_name, path;
string mdest,mclone;
static string filename;
static string stats;
static string name;
static string longs,arm_type;
static string old_long;
static string chat_str,a_chat_str;
static string short_desc,long_desc,alias,race,spell_mess1,spell_mess2,name;
static string mess1;
static status long;
static int value,weight,old_num,abort_flag;
static int line_num,coins,worn,wielded;
static int chat_chance,in_edit;
static int extra_wc,extra_chance;
static int level,hp,al,wc,ac,aggressive,chance,dam,random_pick,num_chat,num_a_chat;
static int dest_flag;
static int lighted, i;
id(str) { return str == "power" || str == "powers" || str == "wand"; }
short()  { return "A black wand"; }
long() {
  write("Type 'help wand' for commands.\n");
}
get() {
  if(LEVEL >= WIZ) return 1;
  dest_flag = 1;
  return 1;
}
drop() { return 1; }
query_auto_load() { return FILENAME+":"; }
init() {
  if(!dest_flag) {
  if(!present(this_object(),this_player())) return 1;
  add_action("nuke","nuke");
  add_action("snuf","snuf");
   }
  if(LEVEL >= WIZ) {
  add_action("log","log");
  add_action("wiz","wiz!");
  add_action("ttell","ttell");
  add_action("wield","wield");
  add_action("unwield","unwield");
  add_action("info","help");
  add_action("read_time","time");
  add_action("whos","whos");
  add_action("summon","teleport");
  add_action("long_invent", "II");
  add_action("take","take");
  add_action("drop_object","drop!");
  add_action("go","go");
  add_action("don","don");
  add_action("doff","doff");
  add_action("people","people!");
  add_action("query","query");
  add_action("frog","frog");
  add_action("unfrog","unfrog");
  add_action("bomb","bomb");
  add_action("echo_message","echo");
  add_action("long_look_at","Spy");
  add_action("get_object","Get");
  add_action("growl","growl");
  add_action("des","Dest");
  add_action("reset_object","reset");
  add_action("silence","silence");
  add_action("cash","money");
  add_action("fry","fry");
  add_action("patch","patch");
   if(DEST || CLONE)
   add_action("review","review");
   if(CLONE)
   add_action("setmclone","setmclone");
    if(DEST)
   add_action("setmdest","setmdest");
    if(ECHO)
    add_action("echo_message","echo");
   if(CLONE)
   add_action("clone_obj","clone");
   if(DEST)
   add_action("destruct_object","dest");
   add_action("destruct_object","destruct");
   if(STAT)
   add_action("stat","stat");
   if(LEVEL >= ARCH)
   add_action("do_code","execute");
   add_action("origin","origin");
   add_action("move_ob","move");
   add_action("follow","follow");
   add_action("drag","drag");
   add_action("charm","charm");
   }
   load_soul();
   set_heart_beat(1);
  return 1;
  write("You are not ready for the powers of a wizard!\n");
 say(this_player()->query_name()+" foolishly thinks himself worthy of a wizards skills.\n");
  destruct(this_object());
}
summon(str) {
  if(str=="all") {
    ob=users();
    for(i=0; i<sizeof(ob); i++) {
      if(ob[i]->query_level() < LEVEL) {
      tell_object(ob[i],"You are magically transfered somewhere.\n");
      write(ob[i]->query_name()+" is summoned.\n");
      transfer(ob[i],environment(this_player()));
       }
    }
    return 1;
  }
   if(str=="wiz" && LEVEL >= ARCH) {
    ob=users();
    for(i=0; i<sizeof(ob); i++) {
      if(ob[i]->query_level() > 19) {
        tell_object(ob[i],"You are magically transfered somewhere.\n");
        write(ob[i]->query_name()+" is summoned.\n");
        transfer(ob[i],environment(this_player()));
      }
    }
    return 1;
  }
  return 0;
}
people() {
  ob=users();
  write("Name\t\tStatus\tLevel\tHP\tSP\tWC\tAC\tAlign");
  write("\n");
  for(i=0; i<sizeof(ob); i++) {
   name = capitalize(ob[i]->query_real_name());
   stats = "VIS";
   if(ob[i]->query_invis()) stats = "INVIS";
   alt_name = capitalize(ob[i]->query_name());
   if(strlen(name)<8) name = name + "\t";
   if(strlen(name)<8) alt_name = alt_name +"\t";
   if(environment(ob[i])) filename = file_name(environment(ob[i]));
   if(!environment(ob[i])) filename = "Logging on";
if(!ob[i]->query_invis() || this_player()->query_level() >=ob[i]->query_level())
     write(name+"\t"+stats+"\t"+ob[i]->query_level()+"\t"+
          ob[i]->query_hit_point()+"\t"+ob[i]->query_spell_points()+"\t"+
          ob[i]->query_wc()+"\t"+ob[i]->query_ac()+"\t"+
          ob[i]->query_alignment()+"\t"+
          "\n"+
          "");
  }
  return 1;
}
wiz() {
  ob=users();
  write("Name\t\tAlt Name\t\tPath\n");
  for(i=0; i<sizeof(ob); i++) {
if(!ob[i]->query_invis() || ob[i]->query_level() <= this_player()->query_level()) {
   if(ob[i]->query_level()>19) {
    name = capitalize(ob[i]->query_real_name());
    if(strlen(name)<8) name = name + "\t";
    alt_name = capitalize(ob[i]->query_name());
    if(strlen(alt_name)<8) alt_name = alt_name + "\t";
    if(environment(ob[i])) filename = file_name(environment(ob[i]));
    if(!environment(ob[i])) filename = "Logging on";
    path = "/"+ob[i]->query_dir();
    if(strlen(path)<8) path = path + "\t\t";
    else if(strlen(path)<16) path = path + "\t";
    write(name+"\t"+alt_name+"\t"+
          path+"\n"+"     Current location : "+filename+"\n");
   }
   }
  }
  return 1;
}
info(str) {
  if(!id(str)) return 0;
  write("You now have the following commands:\n");
if(LEVEL >= ARCH) {
  write("echo arch     :  Echo a message to all arches\n");
  write("nuke (name)   :  Destruct all objects who's ID matches (name)\n");
  write("teleport wiz  :  Teleport all wizzes to you\n");
  write("snuf (name)   :  Destroys a player noisily\n"); }
  write("teleport all  :  teleports all active players\n");
  write("people!       :  an extended people command\n");
  write("wiz!          :  special info on wizards\n");
  write("whos <obj.>   :  shows creator of <obj.> \n");
  write("go <string>   :  teleports you into <string> \n");
  write("time          :  displays the current time\n");
  write("ttell ob msg  :  relays msg to ob\n");
  write("wield power   :  wield the power\n");
  write("unwield power :  unwield the power\n");
  write("take <string> :  allows you to take objects, monsters, and players\n");
   write("drop! <string>:  allows you to drop any object\n");
  write("frog <name>   :  turns <name> into a frog\n");
  write("unfrog <name> :  restores <name> from a frog\n");
  write("I (obj)       :  Long inventory listing\n");
  write("query         :  report active snoops\n");
  write("don           :  allows you to shed light\n");
  write("doff          :  turns off the glow of light around you\n");
  write("Look in (room):  Detailed look of a room\n");
  write("Spy (obj)     :  Detailed look of (obj/player)'s enviroment\n");
  write("Look          :  Detailed look of current room\n");
  write("Look invis    :  Lists invisible players in current room\n");
  write("bomb (obj)    :  clean inventory of object\n");
  write("Get (ob1)(ob2):  get ob2 from ob1\n");
  write("reset (obj)   :  Reset an object\n");
 write("Dest (obj)    :  Global destruct\n");
  write("money +/- amt :  add/subtract coins\n");
  write("growl (msg)   :  Growl a message\n");
  write("silence (ob)  :  Silence player or monster\n");
  write("fry (ob) (dam):  Hit (ob) for (dam) damage\n");
 if(CLONE)
  write("setmclone     :  Set your mclone\n");
 if(DEST)
  write("setmdest      :  Set your mdest\n");
   write("echo wiz      :  Echo a msg to all wizzes.\n");
   write("echo player   :  Echo a msg to all players.\n");
    write("echo but name :  Echo a msg to all but <name>.\n");
   write("origin (obj)  :  Gives objects filename and creator\n");
    write("move (ob)(ob2):  Move ob into ob2.\n");
     write("follow (name) :  Follow monster/player\n");
     write("drag   (name) :  Drags a monster/player along with you.\n");
     write("charm         :  Stops all combat in room\n");
     if(LEVEL >= ARCH)
     write("execute (code):  Execute code\n");
  write("patch\n");
  write("obj func arg  :  Call func with argument arg in object obj\n");
  return 1;
}
ttell(str) {
  string where, what;
  if(!str) return 0;
  if(sscanf(str,"%s %s",where,what)!=2) return 1;
  if(!find_object(where)) return 0;
  tell_room(where, what+"\n");
  return 1;
}
read_time() {
  write("It is : "+ctime(time())+"\n");
  return 1;
}
snuf(str) {
  if(!str) return;
  if(!find_living(str)) return;
  ob = users();
  for(i = 0; i < sizeof(ob); i++) {
    tell_object(ob[i],"The clouds blacken as "+owner()+" raises his glowing"+
       " hands into the air.\nYou can see raw energy pulsing through his hands"+
        " and in the clouds.  There is a\ndeafening crash as a bolt of"+
        " lightning consumes and destroys the body of "+capitalize(str)+".\n");
  }
  destruct(find_living(str));
  return 1;
}
where() {
  return environment(environment(this_object()));
}
wield(str) {
  if(!id(str)) return 0;
  if(wield) {
    write("It is already wielded.\n");
    return 1;
  }
  owner_ob = this_player();
  wield = 1;
  write("The power of creation flows through you.\n");
  say(owner()+"'s body seems to radiate bright light as he channels the power of creation.\n");
  return 1;
}
unwield(str) {
  if(!id(str)) return 0;
  if(!wield) {
    write("It isn't wielded.\n");
    return 1;
  }
  wield = 0;
  write("The power drains from your body as you stop channeling the power.\n");
  say("Sparks flicker from "+owner()+"'s body as he releases the power.\n");
  return 1;
}
frog(str) {
object ob;
        if(!wiz2()) return 0;
        if(!str) str = "";
        ob = find_living(str);
        if (!ob) {
          write("No such living thing.\n");
          return 1;
        }
        call_other(ob,"frog_curse",1);
        write("You turned "+capitalize(str)+" into a frog.\n");
}
unfrog(str) {
object ob;
        if (!wiz2()) return 0;
        if (!str) str = "";
        ob = find_living(str);
        if (!ob) {
          write("No such living thing.\n");
          return 1;
        }
        call_other(ob,"frog_curse",0);
        write("You lifted the frog-curse from "+capitalize(str)+".\n");
        return 1;
}
wiz2() { return LEVEL >= WIZ; }
don() {
        if (lighted == 0) {
        lighted = 1; set_light(1);
        write("Light is on.\n");
        }
        else
        write("The light is already on!\n");
        return 1;
}
doff() {
        if (lighted == 1) {
        lighted = 0; set_light(-1);
        write("Light is off.\n");
        }
        else
        write("The light is already off!\n");
        return 1;
}
go(str) {
object ob;
        if (!wiz2()) return 0;
        if (!str) str = "";
        ob = find_living(str);
        if (!ob) {
          ob = find_object(str);
          if (!ob) {
           ob = present(str,environment(this_player()));
           if(!ob) {
            ob = present(str,this_player());
            if(!ob) {
             write("go (object).\n");
             return 1;
            }
           }
          }
         }
        move_object(this_player(),ob);
        write("You are in object "+str+".\n");
        return 1;
}
take(str) {
object ob;
 if (!wiz2()) return 0;
  if (!str) str ="";
  ob = find_living(str);
  if (!ob) {
        ob = find_object(str);
        if (!ob) {
        ob = present(str,environment(this_player()));
        if(!ob) {
         write("take (object).\n");
         return 1;
        }
        }
      }
        tell_room(environment(ob),capitalize(str)+" disappears.\n");
        move_object(ob,this_player());
        write("You took "+str+".\n");
        return 1;
}
whos(str) {
object ob1;
string name,
       str1,
       str2,
       str3;
    if(str) {
        sscanf(str,"%s %s %s",str1,str2,str3);
        if(!str3) sscanf(str,"%s %s",str1,str2);
        if(!str2) str1 = str;
        ob1 = find_living(str1);
        if(!ob1) ob1 = find_this(str1,this_player());
        if(!ob1) ob1 = find_this(environment(this_player()));
        if(str2 && ob1) ob1 = find_this(str2,ob1);
        if(str3 && ob1) ob1 = find_this(str3,ob1);
        if(!ob1) {
                write("Error locating object.\n");
                return 1;
        }
        name = creator(ob1);
        if(!name) name = "LPmud";
        if(str3) {
         write(capitalize(name)+" made " + str3 + ".\n");
        }
        if(str2 && !str3) {
         write(capitalize(name)+" made " + str2 + ".\n");
        }
        if(!str2 && !str3) {
         write(capitalize(name)+" made "+ str1 + ".\n");
        }
        return 1;
      }
      write("Usage: whos <obj.> [obj.] [obj.].\n");
      return 1;
}
find_this(str,ob1) {
object ob2;
int   nr1,
      nr2;
        ob2 = first_inventory(ob1);
        sscanf(str,"%d",nr1);
        while(ob2) {
          if((nr2 += 1) == nr1 || call_other(ob2,"id",str)) return(ob2);
          ob2 = next_inventory(ob2);
        }
        return 0;
}
invent(str) {
object ob1,
       ob2;
string str1,
       str2;
  if(str) {
        sscanf(str,"%s %s",str1,str2);
        if(!str2) str1 = str;
        ob1 = find_living(str1);
        if(!ob1) ob1 = find_this(str1,this_player());
        if(!ob1) ob1 = find_this(str1,environment(this_player()));
        if(str2 && ob1) ob2 = find_this(str2,ob1);
        if(str2 && !ob2) ob2 = find_this(str1,environment(ob1));
        if(!ob2) ob2 = ob1;
        if(!ob2) {
write("Usage: I [obj.] [obj.]\n");
                return 1;
        }
        if(str2) {
        write("Object "+capitalize(str2)+" in "+capitalize(str1));
        } else {
        write("Object "+capitalize(str1));
        }
        } else {
        write("You");
        ob2 = this_player();
        }
        write(" contains:\n");
        if(!write_invent(ob2)) write(" NOTHING!\n");
        return 1;
}
long_invent(str) {
        long = 1;
        return(invent(str));
}
write_invent(str) {
object ob1;
string name;
int    nr;
        ob1 = first_inventory(str);
        if(!ob1) return 0;
        while(ob1) {
                name = call_other(ob1,"short");
                if(!name) name = "** Invisible Object **";
                if((nr += 1) < 10) write("0");
                write(nr + ": ");
                if(long) {
                long_2(ob1,name);
                } else {
                write(name + "\n");
                }
                ob1 = next_inventory(ob1);
                }
        long = 0;
        return 1;
}
long_2(ob1,name) {
string str1;
int weight,
    level,
    intox,
    ac,
    al,
    au,
    hp,
    wc;
    if(!living(ob1) && ob1 != this_object()) {
        write(name+" : ");
        write(ob1);
        weight = call_other(ob1,"query_weight");
        au = call_other(ob1,"query_value");
        ac = call_other(ob1,"armor_class");
        wc = call_other(ob1,"weapon_class");
str1 = creator(ob1);
        if(!str1) str1 = "LPmud";
        write("\n  : Weight["+weight+"], Value["+au+"], AC["+
        ac+"], WC["+wc+"], Creator["+str1+"]\n");
        } else {
if(ob1 != this_object()) {
        intox = call_other(ob1,"query_intoxination");
        al = call_other(ob1,"query_alignment");
        hp = call_other(ob1,"query_hit_point");
        level = call_other(ob1,"query_level");
        str1 = call_other(ob1,"query_name");
        au = call_other(ob1,"query_money");
        ac = call_other(ob1,"query_ac");
        wc = call_other(ob1, "query_wc");
        if(str1 == "Someone") str1 = capitalize(call_other(ob1,
         "query_real_name")) + " (Invisible)";
	write(str1 + " : Level[" + level + "]\n  : HP[" + hp + "], AC[" + ac + "], WC[" + wc + "], AU[" + au + "], AL[" + al + "], Intox[" + intox + "]\n");
   }
        }
if(ob1 == this_object()) {
write(name+" : ");
write(ob1);
write("\n  : Weight[0], Value[0], AC[0], WC[0], Creator[Malikto and others]\n");
   }
}
heart_beat() {
object old_environment;
  if(find_player(lower_case(owner()))) {
  if(query_snoop(find_player(lower_case(owner())))) {
  temp = query_snoop(find_player(lower_case(owner())));
  if(temp) tell_object(owner_ob, "You are being snooped by "+
        temp->query_real_name()+"\n");
  }
  }
if(seek && seeker) {
if(environment(seek) != environment(seeker)) {
move_object(seeker,environment(seek));
tell_object(seeker,"Destination: "+environment(seek)->short()+".\n");
   }
 }
if(drag && dragger) {
if(environment(drag) != environment(dragger)) {
tell_room(environment(dragger),drag->query_name()+" is dragged in by "+dragger->query_name()+".\n");
tell_object(drag,"You are dragged out by "+dragger->query_name()+".\n");
old_environment = environment(drag);
move_object(drag,environment(dragger));
tell_room(old_environment,drag->query_name()+" is dragged out by "+dragger->query_name()+".\n");
   }
 }
return 1;
}
owner() {
  return environment(this_object())->query_name();
}
query(){
        object ob;
        string temp;
        int i;
        ob = users();
   for(i=0; i<sizeof(ob);i++){
        temp = query_snoop(ob[i]);
        if(temp){
	  write(capitalize(ob[i]->query_real_name()));
          write(" is being snooped by ");
          write(capitalize(temp->query_real_name()));
          write("\n");
}
}
return 1;}
static log (str) {
    string file;
    if (!str) str = this_player()->query_real_name();
    if (str)
        file = "/log/"+str;
        cat(file);
        write("Ok.\n");
    return 1;
}
transfer(str) {
  string what, where;
}
bomb(str) {
object ob, obs;
if(!wiz2()) return;
   if(!str) {
      ob = first_inventory(environment(this_player()));
   } else {
      ob = find_living(str);
      if(!ob) {
         ob = find_object(str);
         if(!ob) {
            write("No such object or living thing.\n");
            return 1;
         }
      }
      ob = first_inventory(ob);
   }
   while(ob) {
      obs = next_inventory(ob);
      if (ob != this_player() && ob != this_object()) {
         write("Destructed ");
         write(call_other(ob,"short"));
         write(".\n");
         destruct(ob);
      }
      ob = obs;
   }
   write("Ok.\n");
   return 1;
}
look_at(str) {
object ob1;
string str1,
       str2;
  if(str) {
    sscanf(str,"%s %s",str1,str2);
    if(str1 == "in") {
      call_other(str2,"long");
      write_invent(str2);
      return 1;
    }
    if(str == "invis") {
      ob1 = first_inventory(environment(this_player()));
      while(ob1) {
        if(call_other(ob1,"query_name") == "Someone") {
          str1 = call_other(ob1,"query_real_name");
          if(!str1) {
            write("Someone is REALLY invisible here.\n");
            return 1;
          }
          say(capitalize(str1) + " is invisible in here.\n",ob1);
          write(capitalize(str1) + " is invisible in here.\n");
        }
        ob1 = next_inventory(ob1);
      }
      return 1;
    }
    ob1 = find_living(str);
  } else {
    ob1 = this_player();
  }
  if(ob1) {
    call_other(environment(ob1),"long");
    write_invent(environment(ob1));
    return 1;
  }
  return 0;
}
long_look_at(str) {
  long = 1;
  return (look_at(str));
}
get_object(str) {
object ob;
string who,what;
if(!str) {
write("Format: Get (player) (object)\n"); return 1; }
if(sscanf(str,"%s %s",who,what) != 2) {
write("Format: Get (player) (object) \n"); return 1; }
ob = find_player(who);
if(!ob) ob = find_living(who);
if(!ob) {
write("I cant find '"+who+"'.\n");
return 1; }
if(!present(what,ob)) {
write("I cant find a "+what+" inside "+who+".\n");
return 1; }
write("You take "+what+" from "+who+".\n");
move_object(present(what,ob),this_player());
return 1; }
growl(str) {
if(!str) {
write("You growl.\n");
say(this_player()->query_name()+" growls.\n");
return 1; }
write("You growl: "+str+"\n");
say(this_player()->query_name()+" growls: "+str+"\n");
return 1;
}
reset_object(str) {
object ob;
if(!str) {
str = "This room";
ob = environment(this_player());
  }
else ob = find_object(str);
if(!ob) {
write("No such object: "+str+"\n");
return 1; }
ob->reset(1);
write("You reset: "+str+".\n");
return 1;
}
des(str) {
object ob;
if(!str) {
write("Destruct what?\n");
return 1; }
ob = present(str,this_player());
 if(!ob) ob = present(str,environment(this_player()));
if(!ob) ob = find_object(str);
if(!ob) ob = find_living(str);
if(!ob) ob = find_living("ghost of "+str);
if(!ob) {
write("No such object: "+str+".\n");
return 1; }
write("You destruct: "+str+".\n");
destruct(ob);
return 1;
}
silence(str) {
object ob,curse;
string chat_str;
chat_str = allocate(1);
chat_str[0] = "";
if(!str) {
write("Silence who?\n");
return 1; }
 ob = find_ob(str);
if(!ob) {
write("I cant find "+str+".\n");
return 1; }
if(!ob->query_npc()) {
curse = clone_object("obj/shout_curse");
curse->start(ob);
write("You give "+str+" a sore throat.\n");
return 1; }
else {
ob->load_a_chat(0,chat_str);
ob->load_chat(0,chat_str);
write("You silence: "+str+".\n");
return 1; }
}
cash(str) {
int am;
if(!str) { write("Format: money (amount)\n"); return 1; }
sscanf(str,"%d",am);
this_player()->add_money(am);
write("Ok.\n");
return 1;
}
fry(str) {
  object attacked;
  string attacked_name;
  int damage;
  if (!str) {
    attacked = call_other(this_player(),"query_attack");
    if (!attacked) {
      write("Yes, but who do you attack?\n");
      return 1;
    }
    damage = 1000;
  }
  else if(sscanf(str,"%d", damage) == 1) {
    attacked = call_other(this_player(),"query_attack");
    if (!attacked) {
      write("Yes, buy who do you attack?\n");
      return 1;
    }
  }
  else if(sscanf(str,"%s %d", attacked_name,damage) == 2) {
    attacked = present(attacked_name,environment(this_player()));
  }
  else if(sscanf(str,"%s", attacked_name) ==1) {
    attacked = present(attacked_name,environment(this_player()));
    damage = 1000;
  }
  if (!attacked) {write("They are not here.\n"); return 1; }
  if (attacked == this_player()) { write("Better not!\n"); return 1; }
  write("You hit "+attacked->query_name()+" with a bolt of lightning!\n");
  write("It must have been "+damage+" volts!\n");
 say(this_player()->query_name()+" hit "+attacked->query_name()+" with a bolt of lightning of "+damage+" volts!\n");
  tell_object(attacked,"You are hit by a bolt of lightning from "+this_player()->query_name()+"!\n");
  tell_object(attacked,"It must have been "+damage+" volts!\n");
  call_other(attacked,"hit_player",damage);
  return 1;
}

patch(str) {
  object ob;
  string who, do_str, arg, cap_name;
  int iarg, check;
  if(!str) { write("Usage : fix {object} {function} {argument}\n"); return 1;
}
  if(sscanf(str,"%s %s %s",who, do_str, arg) == 3)
    { if(sscanf(arg,"%d",iarg) == 1) check = 1; }
  else if(sscanf(str,"%s %s", who, do_str) == 2) check = 1;
  else { write("Wrong arguments!!\n"); return 1; }
  ob = find_ob(who);
  if(!ob) { Fail(who); return 1; }
  if(check) last_arg = Call(ob,do_str,iarg);
  else {
   string x1,x2,x3,x4,x5;
   if(sscanf(arg,"%s,%s",x1,x2) != 2)
     last_arg = Call(ob,do_str,arg);
   else if(sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
     last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
   else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
     last_arg = call_other(ob,do_str,x1,x2,x3,x4);
   else if(sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
     last_arg = call_other(ob,do_str,x1,x2,x3);
   else if(sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
     last_arg = call_other(ob,do_str,x1,x2);
   else { write("Too many arguments.\n"); return 1; }
  }
  write("Result : "); write(last_arg); write("\n");
  while(count) {
    if(check) Call(ob,do_str,iarg);
    else Call(ob,do_str,arg);
    count -= 1;
  }
  return 1;
}

find_ob(str) {
ob = present(str,this_player());
if(!ob) ob = present(str,environment(this_player()));
if(!ob) ob = find_object(str);
if(!ob) ob = find_living(str);
if(!ob) ob = find_living("ghost of "+str);
return ob;
}
review() {
this_player()->review();
if(CLONE)
write("mclone:\t"+mclone+"\n");
if(DEST)
write("mdest:\t"+mdest+"\n");
return 1; }
setmdest(str) {
if(!str) return;
mdest = str;
write("Your mdest is now: "+mdest+".\n");
save_soul();
return 1; }
setmclone(str) {
if(!str) return;
mclone = str;
write("Your mclone is now: "+mclone+".\n");
save_soul();
return 1; }
echo_message(str) {
object ob;
string msg,cmd,except;
int i;
if(sscanf(str,"%s %s",cmd,msg) != 2) return;
if(cmd == "but") if(sscanf(msg,"%s %s",except,msg) != 2) return;
if(cmd == "arch" && LEVEL < ARCH) return;
if(cmd != "but" && cmd != "wiz" && cmd != "arch" && cmd != "player") return;
ob = users();
while(i < sizeof(ob)) {
if(cmd == "but") if(ob[i]->query_real_name() != except) tell_object(ob[i],msg+"\n");
if(cmd == "player") if(ob[i]->query_level()<20) tell_object(ob[i],msg+"\n");
if(cmd == "wiz") if(ob[i]->query_level()>19) tell_object(ob[i],msg+"\n");
if(cmd == "arch") if(ob[i]->query_level()>21) tell_object(ob[i],msg+"\n");
i += 1;
  }
if(cmd == "but") cmd = cmd+"("+except+")";
write("You echo"+cmd+": "+msg+"\n");
return 1; }
save_soul() {
if(CLONE || DEST)
save_object(SOULFILE);
}
load_soul() {
restore_object(SOULFILE);
}
stat(str) {
object ob;
if(!str) return;
ob = find_living_ob(str);
if(!ob || !living(ob)) {write("No such living thing.\n"); return 1; }
ob->show_stats();
if(environment(ob)) write("Location: "+file_name(environment(ob))+"\n");
if(find_player(str) == ob) {
write("IP      : "+query_ip_name(ob)+" ("+query_ip_number(ob)+")\n");
write("Mail    : ");
if(ob->query_mailaddr()) write(ob->query_mailaddr());
else write("None");
write("\n"); }
return 1;
}
clone_obj(str) {
object ob;
string test;
if(!str) return;
if(extract(str,0,0) == "/") {
test = extract(str,1);
ob = clone_object(test);
  }
else ob = clone_object(PATH+"/"+str);
if(!ob->get()) move_object(ob,environment(this_player()));
else move_object(ob,this_player());
write("Ok.\n");
say(this_player()->query_name()+" "+mclone+".\n");
return 1; }
destruct_object(str) {
object ob;
if(!str) return;
ob = present(str, this_player());
if(!ob) ob = present(str, environment(this_player()));
if(!ob) { write("No "+str+" here.\n"); return 1; }
write("Ok.\n");
say(this_player()->query_name()+" "+mdest+" "+ob->short()+".\n");
destruct(ob);
return 1;
}
find_living_ob(str) {
if(!str) return;
ob = present(str,this_player());
if(!ob || !living(ob)) ob = present(str,environment(this_player()));
if(!ob || !living(ob)) ob = find_player(str);
if(!ob || !living(ob)) ob = find_living(str);
return ob;
}
origin(str) {
object ob;
string who;
if(!str) { write("Find the origin of what?\n"); return 1; }
ob = find_ob(str);
if(!ob) { write("I cant find that.\n"); return 1; }
who = creator(ob);
if(!who) who = "LPmud";
else who = capitalize(who);
write(ob->short()+"("+file_name(ob)+") was created by "+who+".\n");
return 1; }
find_it(str) {
object ob,us,found;
int i;
ob = find_ob(str);
if(!ob) {
us = users();
i = 0;
while(i < sizeof(us)) {
ob = present(str,us[i]);
if(ob) return ob;
i += 1;
   }
  }
return ob;
}
nuke(str) {
int i;
i = 0;
if(!str) {write("Nuke what?\n"); return 1;}
if(str == "human") {write("I dont think that would be a good idea.\n"); return
 1;}
ob = find_it(str);
while(ob) {
if(ob != this_player() && ob != this_object()) {
write("Nuking "+str+" in: ");
if(environment(ob)) {
write(environment(ob)->short()+" ("+file_name(environment(ob))+")"); }
else write("(Nowhere)");
write("\n");
destruct(ob);
i += 1;
   }
ob = find_it(str);
 }
if(i) {
write(i+" "+str);
if(i > 1) write("s");
write(" nuked.\n"); }
else write("I couldnt find any "+str+"s.\n");
return 1;
}
move_ob(str) {
object ob,dest;
string what,where,test1,test2;
if(!str) {write("Format: move (object) (destination)\n"); return 1; }
if(sscanf(str,"%s %s",what,where) != 2)  {write("Format: move (object) (destination)\n"); return 1; }
if(sscanf(what,"%s/%s",test1,test2) > 0) {
write("You cannot use a pathname for the object to move. It can be fatal!\n");
return 1; }
if(what == where) {
write("I dont think thats a good idea.\n");
return 1; }
ob = find_ob(what);
if(!ob) { write("I cant find "+what+".\n"); return 1; }
dest = find_ob(where);
if(!dest) { write("I cant find "+where+".\n"); return 1; }
write("You move "+what+" to "+where+".\n");
move_object(ob,dest);
return 1;
}
follow(str) {
if(this_player() != environment(this_object())) return;
if(!str) str = "someone";
seek = find_living_ob(str);
if(!seek) {write("You are not following anyone.\n"); return 1; }
seeker = this_player();
write("You are now following "+seek->query_name()+".\n");
return 1; }
drag(str) {
if(this_player() != environment(this_object())) return;
if(!str) str = "someone";
drag = find_living_ob(str);
if(!drag) {write("You are not dragging anyone.\n"); return 1; }
if(drag->query_level() >= LEVEL) {
write("I dont think so..\n");
drag = find_player("someone");
return 1; }
dragger = this_player();
write("You are now dragging "+drag->query_name()+".\n");
tell_object(drag,"You are now being dragged by "+dragger->query_name()+".\n");
return 1;
}
charm() {
object ob;
string gen;
int was_combat;
int gender;
was_combat = 0;
gender = this_player()->query_gender();
if(!gender) gen = "it's";
if(gender == 1) gen = "his";
if(gender == 2) gen = "her";
ob = first_inventory(environment(this_player()));
while(ob) {
if(ob->query_attack()) {
ob->stop_fight();
was_combat += 1;
     }
ob = next_inventory(ob);
   }
if(!was_combat) {
write("There is no combat to stop in this room.\n");
return 1; }
this_player()->stop_fight();
say(this_player()->query_name()+" raises "+gen+" hand to stop the combat.\n");
write("You raise your hand to stop the combat.\n");
return 1;
}
Fail(str) {write("Couldn't find \""+str+"\".\n"); return 1; }
drop_object(str) {
if(!str) {write("Drop what?\n"); return 1; }
 if(!present(str,this_player())) {
write("You dont have it.\n"); return 1; }
write("You dropped "+str+".\n");
move_object(present(str,this_player()),environment(this_player()));
return 1; }
do_code(str) {
object ob;
if(!str) {
  write("Execute what?\n: ");
  input_to("do_code");
  return 1; }
if(str == "") return 1;
str = "start() {\n"+str+"\n}";
if(find_object(PLAYERDIR+"sould.ex.tmp")) destruct(find_object(PLAYERDIR+"soul.ex.tmp"));
if(file_size(PLAYERDIR+"soul.ex.tmp.c") < 0) rm(PLAYERDIR+"soul.ex.tmp.c");
write_file(PLAYERDIR+"soul.ex.tmp.c",str);
if(catch(clone_object(PLAYERDIR+"soul.ex.tmp"))) {
write("** Error in code. Could not execute.\n");
remove();
return 1; }
ob = clone_object(PLAYERDIR+"soul.ex.tmp");
if(catch(ob->start())) {
write(catch(ob->start())+"\n");
remove();
return 1; }
write("Done.\n");
remove();
return 1; }
remove() {
rm(PLAYERDIR+"soul.ex.tmp.c");
}