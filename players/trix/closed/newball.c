#define ARCH 1
#define WIZ 1
#define ARCHCHANNEL 1
#define WIZCHANNEL 1
#define CLONE 0
#define DEST 0
#define LEVEL this_player()->query_level()
#define PATH this_player()->query_path()
#define PLAYERDIR "players/"+this_player()->query_real_name()+"/"
#define FILENAME "players/hurtbrain/closed/ball"
#define SOULFILE "players/"+this_player()->query_real_name()+"/chwand"
#define ECHO 1 /* Enable the wands echo wiz, echo arch, echo player, and echo but *  */
#define Call(XXX,YYY,ZZZ) call_other(XXX,YYY,ZZZ)
static object owner_ob,last_arg,seek,seeker,drag,dragger;
static object temp,ob;
static int wield,count;
static string alt_name, path;
string mdest,mclone;
static string filename;
static string stats;
static string name;
static string type,file_text,weapon_fname,armor_fname,treasure_fname,filename;
static string extra1,extra2,ex_race;
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


id(str) { if(str=="brain" || str=="tool")  return 1; return 0;}

short() { return "A bloody brain"; }

long() {
  write("This is a strange looking object. Everything is possible to do..\n");
  write("it does! (Sometimes it can also do the impossible).\n");
  write("Type 'info brain' for commands.\n");
}

get() {
  if(LEVEL >= 21) return 1;
  dest_flag = 1;
  return 1;
}

drop() { return 1; }

query_auto_load() { return FILENAME+":"; }

init() {
  if(!dest_flag) {
  if(!present(this_object(),this_player())) return 1;
  add_action("atell","archtell");
  add_action("atell","arch");
  add_action("nuke","nuke");
  add_action("snuf","snuf");
  add_action("make","create");
  add_action("log","log");
  add_action("wiz","wiz!");
  add_action("ttell","ttell");
  add_action("wield","wield");
  add_action("unwield","unwield");
  add_action("info","info");
  add_action("read_time","time");
  add_action("whos","whos");
  add_action("summon","trans");
  add_action("long_invent","I");
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
  add_action("long_look_at","Look");
  add_action("get_object","Get");
  add_action("growl","growl");
  add_action("des","Dest");
  add_action("reset_object","reset");
  add_action("silence","silence");
  add_action("rlog","rlog");
  add_action("cash","money");
  add_action("fry","fry");
  add_action("patch","patch");
    if(ECHO)
    add_action("echo_message","echo");
   add_action("destruct_object","destruct");
   add_action("stat","stat");
   add_action("do_code","execute");
   add_action("origin","origin");
   add_action("move_ob","move");
   add_action("follow","follow");
   add_action("drag","drag");
   add_action("charm","charm");
   add_action("man","man");
   add_action( "room", "room" );
   add_action( "dhl", "dhl" );
   add_action( "vanish", "vanish" );
   add_action( "force", "force" );
   add_action( "hsp", "hsp" );
   add_action( "leaf", "leaf" );
   add_action( "check2", "check_ob" );
   add_action( "check", "check" );
   add_action("iwho","iwho");
   add_action("wind","wind");
   load_soul();
   set_heart_beat(1);
  return 1;
  }
  write("You are not ready for the powers of a wizard!\n");
 say(this_player()->query_name()+" foolishly thinks himself worthy of a wizards skills.\n");
  destruct(this_object());
}

summon(str) {
  if(str=="all") {
    ob=users();
    for(i=0; i<sizeof(ob); i++) {
      if(ob[i]->query_level() < LEVEL) {
      tell_object(ob[i],"You think your mind would explode! Hurtbrain summons you.\n");
      tell_room(environment(this_player()),"\n"+this_player()->query_name()+" snaps his fingers and "+ob[i]->query_name()+" appears at his feet.\n");
      tell_room(environment(ob[i]),"\nYou see a flash of light ."+ob[i]->query_name()+" disappears in it.\n");
      transfer(ob[i],environment(this_player()));
       }
    }
    return 1;
  }
   if(str=="wiz" && LEVEL >= ARCH) {
    ob=users();
    for(i=0; i<sizeof(ob); i++) {
      if(ob[i]->query_level() > 19) {
      tell_object(ob[i],"You think your mind would explode! Hurtbrain summons you.\n");
      tell_room(environment(this_player()),"\n"+this_player()->query_name()+" snaps his fingers and "+ob[i]->query_name()+" appears at his feet.\n");
      tell_room(environment(ob[i]),"\nYou see a flash of light ."+ob[i]->query_name()+" disappears in it.\n");
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
  return 1;
}

info(str) {
  if(!id(str)) return 0;
  write("You now have the following commands:\n");
if(LEVEL >= ARCH) {
  if(ARCHCHANNEL)
  write("archtell (str):  Send a message over the arch-channel\n");
  write("echo arch     :  Echo a message to all arches\n");
  write("nuke (name)   :  Destruct all objects who's ID matches (name)\n");
  write("teleport wiz  :  Teleport all wizzes to you\n");
  write("snuf (name)   :  Destroys a player noisily\n"); }
  write("teleport all  :  teleports all active players\n");
  if(WIZCHANNEL) 
  write("wiztell (str) :  Send a message to all wizards. Can be abbreviated 'wiz (msg)'\n");
  write("people!       :  an extended people command\n");
  write("wiz!          :  special info on wizards\n");
  write("whos <obj.>   :  shows creator of <obj.> \n");
  write("go <string>   :  teleports you into <string> \n");
  write("time          :  displays the current time\n");
  write("ttell ob msg  :  relays msg to ob\n");
  write("wield tool    :  wield the power\n");
  write("unwield tool  :  unwield the power\n");
  write("take <string> :  allows you to take objects, monsters, and players\n");
   write("drop! <string>:  allows you to drop any object\n");
  write("frog <name>   :  turns <name> into a frog\n");
  write("unfrog <name> :  restores <name> from a frog\n");
  write("I (obj)       :  Long inventory listing\n");
  write("query         :  report active snoops\n");
  write("don           :  allows you to shed light\n");
  write("doff          :  turns off the glow of light around you\n");
  write("create        :  create a monster or object file\n");
  write("Look in (room):  Detailed look of a room\n");
  write("Look (obj)    :  Detailed look of (obj)'s environment\n");
  write("Look          :  Detailed look of current room\n");
  write("Look invis    :  Lists invisible players in current room\n");
  write("bomb (obj)    :  clean inventory of object\n");
  write("Get (ob1)(ob2):  get ob2 from ob1\n");
  write("reset (obj)   :  Reset an object\n");
  write("Dest (obj)    :  Global destruct\n");
  write("money +/- amt :  add/subtract coins\n");
  write("growl (msg)   :  Growl a message\n");
  write("silence (ob)  :  Silence player or monster\n");
  write("log           :  Read your error log\n");
  write("rlog          :  Remove your error log\n");
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
     write("man (topic)   :  Find documentation on a topic\n");
     write("execute (code):  Execute code\n");
     write("vanish(ob)(pl):  dest ob from pl's inv\n");
     write("hsp (mon)     :  says the hp and sp of a monster (player)\n");
     write("dhl (obj)(pl) :  send obj to pl\n");
     write("force(pl)(com):  force a pl to do com\n");
     write("room (str)    :  blind echo in the room\n");
     write("leaf (pla)    :  sends a leaflet to pla\n");
     write("iwho          :  shows who is invisible\n");
     write("wind(mon)(dam):  hit mon for dam hit points (if !dam it kills)\n");
     write("check\n");
     write("pla fun arg   :  check fun with argument arg in player pla\n");
     write("check_ob\n");
     write("obj fun arg   :  check fun with argument arg in object obj\n");
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
    tell_object(ob[i],"The clouds blacken as "+owner()+" raises the sword of"+
        " power into the air.\nYou can see raw energy pulsing in the sword"+
        " and in the clouds.  There is a\ndeafening crash as a bolt of"+
        " lightning destroys the body of "+capitalize(str)+".\n");
  }
  destruct(find_living(str));
  return 1;
}

atell(str) {
  object ob;
  int i;
  
  ob = users();
  for( i=0; i < sizeof(ob); i++) {
    if(ob[i]->query_level() > 99) {
      tell_object(ob[i],capitalize(this_player()->query_real_name())+
                  " <arch-channel> "+str+"\n");
    }
  }
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
        return 1;
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
  if(str=="all") return;
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
                write(name+"\n");
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
        write(str1 + " : Level[" + level + "]\n  : HP[" + hp + 
         "], AC{" + ac + "], WC[" + wc + "], AU[" + au + "], AL[" + al +
         "], Intox[" + intox + "]\n");
   }
        }
if(ob1 == this_object()) {
write(name+" : ");
write(ob1);
write("\n  : Weight[0], Value[0], AC[0], WC[0], Creator[Many Wizards]\n");
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
          write(capitalize(ob[i]->query_real_name())); /*get the invis too*/
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



make() {
line_num = 1;
abort_flag = 0;
coins = 0;
type = "";
weight = 0;
value = 0;
longs = allocate(40);
mess1 = allocate(20);
if(LEVEL < WIZ) {
write("Sorry, this is only for wizzes.\n");
return 1; }
wielded = 0;
worn = 0;
treasure_fname = "";
weapon_fname = "";
armor_fname = "";
in_edit = 0;
extra1 = "";
extra2 = "";
ex_race = "";
if(chat_str) {
i = 0;
while(i < num_chat) {
chat_str[i] = "";
i +=1;
    }
  }
if(a_chat_str) {
i = 0;
while(i < num_a_chat) {
a_chat_str[i] = "";
i += 1;
   }
}
num_chat = 0;
num_a_chat = 0;
hp = 0;
wc = 0;
ac = 0;
aggressive = 0;
chance = 0;
spell_mess1 = "";
spell_mess2 = "";
dam = 0;
random_pick = 0;
alias = "";
write("\n"+
"The ball will let you make these types of objects:\n"+
"monster, treasure, weapon, armor.\n"+
"Please enter a type to create.\n"+
": ");
input_to("start");
return 1;
}
get_name(str) {
if(!str || str == "") {
write("Aborted.\n");
if(in_edit) {
main_menu();
return 1; }
return 1; }
name = str;
if(in_edit) {
main_menu();
return 1; }
write("Alias(optional): ");
input_to("get_alias");
return  1; }
get_alias(str) {
if(str) alias = str;
if(in_edit) {
main_menu();
return 1; }
write("Short Description: ");
input_to("get_short");
return 1;
}
get_short(str) {
if(!str || str == "") {
write("Aborted.\n");
if(in_edit) {
main_menu();
return 1; }
return 1; }
short_desc = str;
if(in_edit) {
main_menu();
return 1; }
write("Enter Long Description. End with ** on a blank line.\n");
input_to("get_long");
old_long = long_desc;
long_desc = "";
write(line_num+">>");
return 1;
}
get_long(str) {
if(str == "**") {
if(in_edit && long_desc == "") {
long_desc = old_long;
line_num = old_num;
   }
if(in_edit) {
main_menu();
return 1; }
if(type != "monster") {
write("Value: ");
input_to("get_value");
return 1; }
write("Level: ");
input_to("get_level");
return 1;
}
long_desc = long_desc + str + "\n";
longs[line_num] = str;
line_num = line_num + 1;
write(line_num+">>");
input_to("get_long");
return 1;
}
get_level(str) {
if(!str || str == "") {
write("Aborted.\n");
if(in_edit) {
main_menu();
return 1;  }
return 1;
}
sscanf(str,"%d",level);
if(level <1) {
write("Please enter a valid level.\n");
write("Level: ");
input_to("get_level");
return 1;
}
if(in_edit) {
main_menu();
return 1; }
write("HPs(optional): ");
input_to("get_hp");
return 1;
}
get_hp(str) {
if(str && str != "") sscanf(str,"%d",hp);
if(in_edit) {
main_menu();
return 1; }
write("Race(Enter for Human): ");
input_to("get_race");
return 1;
}
get_race(str) {
if(str && str != "") race = str;
else race = "human";
if(in_edit) {
main_menu();
return 1; }
write("Alignment(Enter for 0): ");
input_to("get_al");
return 1; }
get_al(str) {
if(str && str != "") sscanf(str,"%d",al);
else al = 0;
if(in_edit) {
main_menu();
return 1; }
write("Chance of "+short_desc+" picking up objects: ");
input_to("get_random");
return 1; }
get_random(str) {
if(str) sscanf(str,"%d",random_pick);
if(!str || str == "") random_pick = 0;
if(random_pick > 100) random_pick = 100;
if(in_edit) {
main_menu();
return 1; }
write("WC(optional): ");
input_to("get_wc");
return 1; }
get_wc(str) {
if(str && str != "") sscanf(str,"%d",wc);
if(in_edit) {
main_menu();
return 1; }
write("AC(optional): ");
input_to("get_ac");
return 1; }
get_ac(str) {
if(str && str != "") sscanf(str,"%d",ac);
if(in_edit) {
main_menu();
return 1; }
write("Coins(Enter = 0): ");
input_to("get_coins");
return 1; }
get_coins(str) {
if(!str || str == "") coins = 0;
else sscanf(str,"%d",coins);
if(coins < 0) coins = 0;
if(in_edit) {
main_menu();
return 1; }
write("Aggressive(Enter = 0): ");
input_to("get_aggressive");
return 1; }
get_aggressive(str) {
if(str) sscanf(str,"%d",aggressive);
if(!str || str == "") aggressive = 0;
if(in_edit) {
main_menu();
return 1; }
write("Does this monster cast spells? ");
input_to("spells");
return 1; }
spells(str) {
if(str != "n" && str != "no") {
write("Spell_mess1(Seen by others): ");
input_to("get_mess1");
return 1; }
write("Does this monster talk? ");
input_to("chats");
return 1; }
get_mess1(str) {
if(!str) {
write("You must enter a spell_mess1");
write("Spell_mess1: ");
input_to("get_mess1");
return 1; }
spell_mess1 = str;
if(in_edit) {
main_menu();
return 1; }
write("Spell_mess2(Seen by attacker): ");
input_to("get_mess2");
return 1; }
get_mess2(str) {
if(!str) {
write("You must enter a spell_mess2");
write("Spell_mess2: ");
input_to("get_mess2");
return 1; }
spell_mess2 = str;
if(in_edit) {
main_menu();
return 1; }
write("Spell Damage: ");
input_to("get_dam");
return 1; }
get_dam(str) {
if(str && str != "") sscanf(str,"%d",dam);
if(!dam) dam = 5;
if(in_edit) {
main_menu();
return 1; }
write("Spell Chance: ");
input_to("spell_chance");
return 1; }
spell_chance(str) {
if(str && str != "") sscanf(str,"%d",chance);
if(!chance || chance < 0 || chance > 100) chance = 10;
if(in_edit) {
main_menu();
return 1; }
write("Can the monster talk? ");
input_to("chats");
return 1;
}
chats(str) {
if(str == "y" || str == "yes") {
write("Talk Chance(1-100): ");
input_to("get_chance");
return 1; }
write("Weapon filename(Enter = none): ");
input_to("weapon_fname");
return 1; }
get_chance(str) {
if(str && str != "") sscanf(str,"%d",chat_chance);
if(!chat_chance || chat_chance < 1 || chat_chance > 100) chat_chance = 10;
if(in_edit) {
main_menu();
return 1; }
write("Number of chats: ");
input_to("get_num_chats");
return 1; }
get_num_chats(str) {
if(str) sscanf(str,"%d",num_chat);
if(num_chat > 0) {
write("Chat message 1: ");
 
chat_str = allocate(num_chat);
i = 1;
input_to("chat_msgs");
return 1;
      }
if(in_edit) {
main_menu();
return 1; }
write("Number of attack_chats: ");
input_to("num_achat");
return 1;
}
chat_msgs(str) {
if(str) chat_str[i-1] = str+"\n";
else chat_str[i-1] = "";
i += 1;
if(i > num_chat) {
if(in_edit) {
main_menu();
return 1; }
write("Number of attack_chats: ");
input_to("num_achat");
return 1; }
write("Chat message "+i+": ");
input_to("chat_msgs");
return 1; }
num_achat(str) {
if(str) sscanf(str,"%d",num_a_chat);
if(num_a_chat > 0) {
 
write("A_Chat message 1: ");
a_chat_str = allocate(num_a_chat);
i = 1;
input_to("achat_msgs");
return 1; }
write("Weapon filename(Enter = none): ");
input_to("weapon_fname");
return 1; }
achat_msgs(str) {
if(str) a_chat_str[i-1] = str+"\n";
else a_chat_str[i-1] = "";
i += 1;
if(i <= num_a_chat) {
write("A_Chat message "+i+": ");
input_to("achat_msgs");
return 1; }
write("Weapon filename(Enter = none): ");
input_to("weapon_fname");
return 1; }
weapon_fname(str) {
if(str && str != "") {
weapon_fname = PLAYERDIR+str;
write("Wielded?: ");
input_to("get_wielded");
return 1; }
weapon_fname = "";
wielded = 0;
if(in_edit) {
main_menu();
return 1; }
write("Armor filename(Enter = none): ");
input_to("armor_fname");
return 1; }
get_wielded(str) {
if(str == "yes" || str == "y") wielded = 1;
if(in_edit) {
main_menu();
return 1; }
write("Armor filename(Enter = none): ");
input_to("armor_fname");
return 1; }
armor_fname(str) {
if(str && str != "") {
armor_fname = PLAYERDIR+str;
write("Worn?: ");
input_to("get_worn");
return 1; }
worn = 0;
armor_fname = "";
if(in_edit) {
main_menu();
return 1; }
write("Treasure filename(Enter = none): ");
input_to("treasure_fname");
return 1; }
get_worn(str) {
if(str == "y" || str == "yes") worn = 1;
if(in_edit) {
main_menu();
return 1; }
write("Treasure filename(Enter = none): ");
input_to("treasure_fname");
return 1; }
treasure_fname(str) {
if(str && str != "") treasure_fname =
PLAYERDIR+str;
else treasure_fname = "";
main_menu();
return 1; }
 
 
start(str) {
if(!str) {
write("Aborted.\n");
return 1; }
if(str == "monster" || str == "weapon" || str == "armor" || str == "treasure")
{
type = str;
write("Name: ");
input_to("get_name");
return 1; }
write("Invalid type.\n");
write(": ");
input_to("start");
return 1;
}
main_menu() {
in_edit = 1;
if(type == "monster") {
write("Object: Monster\n");
write("\n");
write("1) Name            : "+name+"\n");
write("2) Alias           : ");
if(alias && alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Race            : "+race+"\n");
write("4) Short           : "+short_desc+"\n");
write("5) WC              : ");
if(wc) write(wc+"\n");
else write("Default\n");
write("6) AC              : ");
if(ac) write(ac+"\n");
else write("Default\n");
write("7) HP              : ");
if(hp) write(hp+"\n");
else write("Default\n");
 
write("8) Level           : "+level+"\n");
write("9) Alignment       : "+al+"\n");
 write("10) Aggressive     : "+aggressive+"\n");
write("11) Chance/Take    : "+random_pick+"\n");
write("12) Coins          : "+coins+"\n");
write("13) Spell Message 1: ");
if(spell_mess1 && spell_mess1 != "") write(spell_mess1+"\n");
else write("(Not Defined)\n");
write("14) Spell Message 2: ");
if(spell_mess2 && spell_mess2 != "") write(spell_mess2+"\n");
else write("(Not Defined)\n");
write("15) Spell Chance   : "+chance+"\n");
write("16) Spell Damage   : "+dam+"\n");
write("17) Number/Chats   : ");
if(num_chat > 0) write(num_chat+"\n");
else write("(Not Defined)\n");
write("18) Number/A_Chats : ");
if(num_a_chat > 0) write(num_a_chat+"\n");
else write("(Not Defined)\n");
write("19) Weapon filename: ");
if(weapon_fname != "") {
write(weapon_fname);
if(wielded) write(" (wielded)\n");
else write("\n"); }
else write("(Not Defined)\n");
write("20) Armor filename: ");
if(armor_fname != "") {
write(armor_fname);
if(worn) write(" (worn)\n");
else write("\n");
   }
else write("(Not Defined)\n");
write("21) Treasure fname : ");
if(treasure_fname != "") write(treasure_fname+"\n");
else write("(Not Defined)\n");
write("22) Edit Long Description");
write("\n");
   }
if(type == "treasure") {
write("Object: Treasure\n");
write("1) Name           : "+name+"\n");
write("2) Alias          : ");
if(alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Short          : "+short_desc+"\n");
write("4) Value          : "+value+"\n");
write("5) Weight         : "+weight+"\n");
write("6) Edit Long Description.\n");
   }
if(type == "armor") {
write("Object: Armor\n");
write("1) Name           : "+name+"\n");
write("2) Alias          : ");
if(alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Short          : "+short_desc+"\n");
write("4) Value          : "+value+"\n");
write("5) Weight         : "+weight+"\n");
write("6) Armor Class   : "+ac+"\n");
write("7) Type           : "+arm_type+"\n");
write("8) Edit Long Description.\n");
   }
if(type == "weapon") {
write("Object: Weapon\n");
write("1) Name           : "+name+"\n");
write("2) Alias          : ");
if(alias != "") write(alias+"\n");
else write("(Not Defined)\n");
write("3) Short          : "+short_desc+"\n");
write("4) Value          : "+value+"\n");
write("5) Weight         : "+weight+"\n");
write("6) Weapon Class   : "+wc+"\n");
write("7) Extra Hit msg 1: ");
if(extra1 != "") write(extra1 + "\n");
else write("(Not Defined)\n");
write("8) Extra Hit msg 2: ");
if(extra2 != "") write(extra2 + "\n");
 
else write("(Not Defined)\n");
write("9) Extra Hit WC+  : ");
if(extra_wc) write(extra_wc+"\n");
else write("(Not Defined)\n");
write("10) Extra Chance  : ");
if(extra_chance) write(extra_chance+"\n");
else write("(Not Defined)\n");
write("11) Extra hit race: ");
if(ex_race != "") write(ex_race+"\n");
else write("ALL\n");
write("12) Edit Long Description.\n");
  }
write("\nw)rite e)dit q)uit r)ead long: ");
input_to("main_edit");
 
return 1; }
main_edit(str) {
if(str == "q") return 1;
if(str == "e") {
write("Edit Which?: ");
input_to(type+"_edit");
return 1; }
if(str == "w") {
write("Filename: ");
input_to("write_"+type);
return 1; }
if(str == "r") {
write("-----\nLong:\n-----\n"+long_desc);
main_menu();
return 1; }
main_menu();
return 1; }
treasure_edit(str) {
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Short: ");
input_to("get_short");
return 1; }
if(i==4) {
write("Value: ");
input_to("get_value");
return 1; }
if(i==5) {
write("Weight: ");
input_to("get_weight");
return 1; }
if(i==6) {
write("Enter Long Description. End with ** on a blank line.\n");
write("1>>");
old_num = line_num;
line_num = 1;
old_long = long_desc;
long_desc = "";
input_to("get_long");
return 1; }
main_menu();
return 1; }
weapon_edit(str) {
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Short: ");
input_to("get_short");
return 1; }
if(i==4) {
write("Value: ");
input_to("get_value");
return 1; }
if(i==5) {
write("Weight: ");
input_to("get_weight");
return 1; }
if(i==6) {
write("Weapon Class: ");
input_to("weapon_class");
return 1; }
if(i==7) {
write("$MN$ = Monster name, $TP$ = Player name, $CR$ = carriage return.\n");
write("Extra String 1: ");
input_to("get_extra1");
return 1; }
if(i==8) {
write("$MN$ = Monster name, $TP$ = Player name, $CR$ = carriage return.\n");
write("Extra String 2: ");
input_to("extra2");
return 1; }
if(i==9) {
write("WC+ in an extra hit(1-10): ");
input_to("extra_wc");
return 1; }
if(i==10) {
write("Chance of extra hit(1-100): ");
input_to("extra_chance");
return 1; }
if(i==11) {
write("Does this extra hit work on only one race?\nRace(Enter for all): ");
input_to("ex_race");
return 1;
 }
if(i==12) {
write("Enter Long Description. End with ** on a blank line.\n");
write("1>>");
old_num = line_num;
line_num = 1;
old_long = long_desc;
long_desc = "";
input_to("get_long");
return 1; }
main_menu();
return 1; }
armor_edit(str) {
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Short: ");
input_to("get_short");
return 1; }
if(i==4) {
write("Value: ");
input_to("get_value");
return 1; }
if(i==5) {
write("Weight: ");
input_to("get_weight");
return 1; }
if(i==6) {
write("Armor Class: ");
input_to("armor_class");
return 1; }
if(i==7) {
write("Armor Type: ");
input_to("get_arm");
return 1; }
if(i==8) {
write("Enter Long Description. End with ** on a blank line.\n");
old_num = 1;
line_num = 1;
old_long = long_desc;
long_desc = "";
write("1>>");
input_to("get_long");
return 1; }
main_menu();
return 1; }
write_monster(str) {
string test;
string temp;
string slask;
file_text = "";
slask = "\\nx";
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
add_line("");
add_line("inherit\"obj/monster\";");
add_line("reset(arg) {");
add_line("object gold;");
if(armor_fname != "") add_line("object armor;");
if(weapon_fname != "") add_line("object weapon;");
if(treasure_fname != "") add_line("object treasure;");
if(num_chat || num_a_chat) {
if(num_chat) add_line("string chat_str;");
if(num_a_chat) add_line("string a_chat_str;");
  }
add_line("::reset(arg);");
add_line("if(arg) return;");
if(num_chat && !num_a_chat) add_line("if(!chat_str) {");
if(num_a_chat && !num_chat) add_line("if(!a_chat_str) {");
if(num_chat && num_a_chat) add_line("if(!chat_str) {");
if(num_chat || num_a_chat) {
if(num_chat) add_line("chat_str = allocate("+num_chat+");");
if(num_a_chat) add_line("a_chat_str = allocate("+num_a_chat+");");
i = 0;
if(num_chat) {
while(i<num_chat) {
sscanf(chat_str[i],"%s\n",temp);
add_line("chat_str["+i+"] = \""+temp+extract(slask,0,0)+"n\";");
i += 1;
   }
 }
if(num_a_chat) {
i=0;
while(i < num_a_chat) {
sscanf(a_chat_str[i],"%s\n",temp);
add_line("a_chat_str["+i+"] = \""+temp+extract(slask,0,0)+"n\";");
i += 1;
   }
 }
add_line("  }");
 }
add_line("set_name(\""+name+"\");");
if(alias && alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
i=1;
add_long();
add_line("set_level("+level+");");
add_line("set_race(\""+race+"\");");
if(hp) add_line("set_hp("+hp+");");
if(al) add_line("set_al("+al+");");
if(wc) add_line("set_wc("+wc+");");
if(ac) add_line("set_ac("+ac+");");
if(aggressive) add_line("set_aggressive(1);");
if(chance) add_line("set_chance("+chance+");");
if(dam) add_line("set_spell_dam("+dam+");");
if(spell_mess1 && spell_mess1 != "")
add_line("set_spell_mess1(\""+spell_mess1+"\");");
add_line("set_spell_mess2(\""+spell_mess2+"\");");
if(num_chat) add_line("set_chat_chance ("+chat_chance+");");
i=0;
while(i<num_chat) {
add_line("load_chat(chat_str["+i+"]);");
i += 1;
}
if(num_a_chat) add_line("set_a_chat_chance("+chat_chance+");");
i=0;
while(i<num_a_chat) {
add_line("load_a_chat(a_chat_str["+i+"]);");
i += 1;
}
if(random_pick) add_line("set_random_pick("+random_pick+");");
if(coins) {
        add_line("gold=clone_object(\"obj/money\");");
        add_line("gold->set_money("+coins+");");
        add_line("move_object(gold,this_object());");
        }
if(armor_fname != "") {
add_line("armor = clone_object(\""+armor_fname+"\");");
add_line("if(armor) {");
add_line("move_object(armor,this_object());");
if(worn) add_line("command(\"wear \"+armor->query_name());");
add_line("  }");
   }
if(weapon_fname != "") {
add_line("weapon = clone_object(\""+weapon_fname+"\");");
add_line("if(weapon) {");
add_line("move_object(weapon,this_object());");
if(wielded) add_line("command(\"wield \"+weapon->query_name());");
add_line("   }");
   }
if(treasure_fname != "") {
add_line("treasure = clone_object(\""+treasure_fname+"\");");
add_line("if(treasure) move_object(treasure,this_object());");
    }
add_line("}");
write_it();
return 1;
}
add_line(str) {
if(file_text == 0) file_text = "";
file_text = file_text +str+"\n";
}
add(str) {
if(file_text == 0) file_text = "";
file_text = file_text +str;
}
monster_edit(str) {
if(!str && str == "") main_menu();
sscanf(str,"%d",i);
if(i==1) {
write("Name: ");
input_to("get_name");
return 1; }
if(i==2) {
write("Alias: ");
input_to("get_alias");
return 1; }
if(i==3) {
write("Race(Enter for Human): ");
input_to("get_race");
return 1; }
if(i==4) {
write("Short Description: ");
input_to("get_short");
return 1; }
if(i==5) {
write("WC(optional): ");
input_to("get_wc");
return 1; }
if(i==6) {
write("AC(optional): ");
input_to("get_ac");
return 1; }
if(i==7) {
write("HPs(optional): ");
input_to("get_hp");
return 1; }
if(i==8) {
write("Level: ");
input_to("get_level");
return 1; }
if(i==9) {
write("Alignment(Enter for 0): ");
input_to("get_al");
return 1; }
if(i==10) {
write("Aggressive(Enter = 0): ");
input_to("get_aggressive");
return 1; }
if(i==11) {
write("Chance of "+short_desc+" picking up objects: ");
input_to("get_random");
return 1; }
if(i==12) {
write("Coins(Enter = 0): ");
input_to("get_coins");
return 1; }
if(i==13) {
write("Spell_mess1(Seen by others): ");
input_to("get_mess1");
return 1; }
if(i==14) {
write("Spell_mess2(Seen by attacker): ");
input_to("get_mess2");
return 1; }
if(i==15) {
write("Spell Chance: ");
input_to("spell_chance");
 
return 1; }
if(i==16) {
write("Spell Damage: ");
input_to("get_dam");
return 1; }
if(i==17) {
write("Number of Chats: ");
input_to("get_num_chats");
return 1; }
if(i==18) {
write("Number of attack_chats: ");
input_to("num_achat");
return 1; }
if(i==19) {
write("Weapon filename(Enter = none): ");
input_to("weapon_fname");
return 1; }
if(i==20) {
write("Armor filename(Enter = none): ");
input_to("armor_fname");
return 1; }
if(i==21) {
write("Treasure filename(Enter = none): ");
 
input_to("treasure_fname");
return 1; }
if(i==22) {
write("Enter Long Description. End with ** on a blank line.\n");
old_num = line_num;
line_num = 1;
write("1>>");
old_long = long_desc;
long_desc = "";
input_to("get_long");
return 1; }
main_menu();
return 1; }
 
get_value(str) {
if(str != "") sscanf(str,"%d",value);
if(in_edit) {
main_menu();
return 1; }
write("Weight: ");
input_to("get_weight");
return 1; }
get_weight(str) {
if(str != "") sscanf(str,"%d",weight);
if(in_edit) {
main_menu();
return 1; }
if(type == "treasure") {
main_menu();
return 1; }
if(type == "weapon") {
write("Weapon Class: ");
input_to("weapon_class");
return 1; }
if(type == "armor") {
write("Armor Class: ");
input_to("armor_class");
return 1; }
return 1; }
 
static weapon_class(str) {
if(!str || str == "") {
write("You must enter a weapon class.\nWeapon Class: ");
input_to("weapon_class");
return 1; }
sscanf(str,"%d",wc);
if(in_edit) {
main_menu();
return 1; }
write("Does the "+short_desc+" have extra hits?: ");
input_to("does_extra");
return 1; }
does_extra(str) {
if(str != "y" && str != "yes") {
main_menu();
return 1; }
write("This message is seen by others in the room."+
"  The next message will be the one\n"+
"that is printed to the wielder of the weapon.\n");
print_macros();
write("Extra String 1: ");
input_to("get_extra1");
return 1; }
get_extra1(str) {
if(str != "") extra1 = str;
else extra1 = "$MN$ is slammed by $TP$'s "+name+".";
if(in_edit) {
main_menu();
return 1; }
write("This message is the one printed to the wielder"+
" of the weapon during an extra\n"+
"hit.\n");
print_macros();
write("Extra string 2: ");
input_to("extra2");
return 1; }
extra2(str) {
if(str != "") extra2 = str;
else extra2 = "$MN$ is slammed by your "+name+".";
if(in_edit) {
main_menu();
return 1; }
write("WC+ in an extra hit(1-10): ");
input_to("extra_wc");
return 1; }
extra_wc(str) {
if(str != "") sscanf(str,"%d",extra_wc);
if(extra_wc < 1 || extra_wc > 10) extra_wc = 2;
if(in_edit) {
main_menu();
return 1; }
write("Chance of extra hit(1-100): ");
input_to("extra_chance");
return 1; }
extra_chance(str) {
if(str != "") sscanf(str,"%d",extra_chance);
if(extra_chance < 1 || extra_chance > 100) extra_chance = 20;
if(in_edit) {
main_menu();
return 1; }
write("Does the extra hit work on only one race?\nRace(Enter for all): ");
input_to("ex_race");
return 1; }
static armor_class(str) {
if(str != "") sscanf(str,"%d",ac);
if(!ac) ac = 1;
if(in_edit) {
main_menu();
return 1; }
write("Armor type: ");
input_to("get_arm");
return 1;
  }
get_arm(str) {
if(str != "") arm_type = str;
if(str != "helmet" && str != "amulet" && str != "armor" && str != "shield" &&
str != "ring" && str != "glove" && str != "cloak" && str != "boot") {
write("Valid armor types are:\n\nhelmet, amulet, armor, shield,"+
" ring, glove, cloak, and boot.\n\n");
 
write("Armor type: ");
input_to("get_arm");
return 1; }
main_menu();
return 1; }
add_long() {
string slask;
i= 1;
slask = "\\nx";
if(long_desc != "") {
add_line("set_long(");
while(i<line_num) {
if(i>1) add("+ ");
add("\"");
add(longs[i]);
add(extract(slask,0,0));
add("n\"");
if(i == line_num - 1) add_line(");");
else add_line("");
i += 1;
   }
 }
}
write_treasure(str) {
string test;
string t1,t2;
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
file_text = "";
add_line("inherit\"obj/treasure\";");
add_line("reset(arg) {");
add_line("if(arg) return;");
add_line("set_id(\""+name+"\");");
if(alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
add_long();
add_line("set_value("+value+");");
add_line("set_weight("+weight+");");
add_line("}");
write_it();
return 1; }
write_armor(str) {
string test;
file_text = "";
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
add_line("inherit\"obj/armor\";");
add_line("reset(arg) {");
add_line("::reset(arg);");
add_line("if(arg) return;");
add_line("set_name(\""+name+"\");");
if(alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
add_long();
add_line("set_weight("+weight+");");
add_line("set_value("+value+");");
add_line("set_ac("+ac+");");
add_line("set_type(\""+arm_type+"\");");
add_line("}");
write_it();
return 1; }
write_weapon(str) {
string slask;
string test;
check_name(str);
if(abort_flag) {
abort_flag = 0;
main_menu();
return 1; }
file_text = "";
slask = "\\nx";
add_line("inherit\"obj/weapon\";");
add_line("reset(arg) {");
add_line("::reset(arg);");
add_line("if(arg) return;");
add_line("set_name(\""+name+"\");");
if(alias != "") add_line("set_alias(\""+alias+"\");");
add_line("set_short(\""+short_desc+"\");");
add_long();
add_line("set_value("+value+");");
add_line("set_weight("+weight+");");
add_line("set_class("+wc+");");
if(extra1 != "" && extra2 != "" && extra_wc && extra_wc)
add_line("set_hit_func(this_object());");
add_line("}");
if(extra1 != "" && extra2 != "" && extra_wc && extra_chance) {
add_line("weapon_hit(attacker) {");
if(ex_race != "") add_line("if(random(100)<"+extra_chance+" && attacker->query_race() == \""+ex_race+"\") {");
else add_line("if(random(100) < "+extra_chance+") {");
add("write(");
parse(extra2);
add_extra();
add_line("");
add("say(");
parse(extra1);
add_extra();
add_line("");
add_line("return "+extra_wc+";");
add_line("   }");
add_line("return 0;");
add_line(" }");
    }
write_it();
return 1; }
ex_race(str) {
if(str != "") ex_race = str;
else ex_race = "";
main_menu();
return 1; }
write_it() {
filename =
filename+".c"; /* PLAYERDIR+filename+".c"; */
if(file_size(filename) >= 0) {
write("Warning! "+filename+" exists! Overwrite? (y/n): ");
input_to("write_ok");
return 1; }
save_file();
return 1; }
write_ok(str) {
if(str != "y" && str != "yes") {
main_menu();
return 1; }
rm(filename);
save_file();
return 1;  }
save_file() {
write_file(filename,file_text);
if(file_size(filename) < 0) {
write("Error: Could not write file.\n");
 
main_menu();
return 1; }
write("\nDone.. "+short_desc+" created.\n");
write("Do you want to create another object?: ");
input_to("make_more");
}
check_name(str) {
string t1,t2;
if(sscanf(str,"%s.%s",t1,t2)>0) {
write(". and .. are not allowed in filenames!\(\".c\" is automatically added.)\n");
write("\n");
abort_flag = 1; }
else filename = str;
   }
make_more(str) {
if(str ==  "y" || str == "yes") {
make();
return 1; }
return 1; }
 


parse(str) {
string cmd;
if(!str) return;
i = 0;
while(i < 20) {
mess1[i] = "";
i += 1;
}
mess1[0] = str;
i = 0;
while(sscanf(mess1[i],"%s$%s$%s",mess1[i],cmd,mess1[i+2]) >0) {
if(cmd == "MN" || cmd == "TP" || cmd == "CR") {
mess1[i+1] = cmd;
i += 2;
    }
else { mess1[i+1] = "";
i += 2; }
 }
}
add_extra() {
int k;
k = 0;
while(k < i+1) {
if(k==1 && mess1[0] != "") add("+");
if(k > 1 && mess1[k] != "") add("+");
if(mess1[k]=="TP") add("this_player()->query_name()");
else if(mess1[k]=="MN") add("attacker->query_name()");
else if(mess1[k]=="CR") {
add("\""+extract("\\nx",0,0)+"n");
if(k<i) add("\"");
      }
else if(mess1[k] != "") {
add("\""+mess1[k]);
if(k < i) add("\"");
   }
k += 1;
  }
if(find_last() == "MN" || find_last() == "TP") add("+\"");
add(extract("\\nx",0,0)+"n\");");
  }
print_macros() {
write("The following symbols can be placed in your message."+
" The ball will convert\n"+
"them while writing the file for this weapon.\n");
write("Command -- Function\n");
write("   $MN$ -- includes monster's name in message.\n");
write("   $TP$ -- includes this player's name in message.\n");
write("   $CR$ -- includes a carriage return in message.\n");
write("\nNote: No spaces are needed between these commands.\n");
}
find_last() {
int k;
k = i;
while(k  >= 0) {
if(mess1[k] != "") return mess1[k];
k -= 1;
   }
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
      if(ob==this_player()&&ob!=this_object()&&ob->query_npc()!=1) {
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
rlog() {
rm("/log/"+this_player()->query_real_name());
write("Ok.\n");
return 1; }
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
  if(!str) { write("Usage: check {object} {function} {argument}\n"); return 1; }
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
if(str == "human") {write("I dont think that would be a good idea.\n"); return 1;}
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
if(sscanf(str,"%s %s",what,where) != 2)  { write("Format: move (object) (destination)\n"); return 1; }
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

man(str) {
    string manuals;

    i = 0;
    manuals = ({ "/doc", "/doc/efun",  "/doc/lfun", "/doc/helpdir",
"/doc/build", "/doc/w", "/doc/LPC" });
    if (str == 0) {
        write("Topics:\n");
        while (i < sizeof(manuals)) {
    write(manuals[i] + " ");
            i += 1;
        }
        write("\n");
        return 1;
    }
    str = "/" + str;
    while(i < sizeof(manuals)) {
if (file_size(manuals[i] + str) == -2) {
    write("Sub topics " + manuals[i] + str + ":\n");
    ls(manuals[i] +str);
            return 1;
        }
if (file_size(manuals[i] + str) > 0) {
    write(manuals[i] + str + ":\n");
/*
    this_player()->more(manuals[i] + str);
*/
    command("more "+manuals[i]+str,this_player());
            return 1;
        }
        i += 1;
    }
    write("Not found.\n");
    return 1;
}
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
if(find_object(PLAYERDIR+"soul.ex.tmp")) destruct(find_object(PLAYERDIR+"soul.ex.tmp"));
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
check2(arg)
{ object who;
  string ppl,funct;
    int nset;
      nset=0;
if((!arg) || (!(sscanf(arg,"%s %s %d",ppl,funct,nset))))
	 {  notify_fail("Check: Wrong syntax!\n");
	     return 0;
       }
	 who=present(ppl,this_player());
   if(!who) { write("No object with that name on.\n"); return 0; }
     write(capitalize(ppl)+"'s "+funct+": "+call_other(who,funct,nset)+".\n");
return 1;
}

wind (str)  {
	int num;
	object obj,env;
	if(!str)  {
		notify_fail("Who do you want to wind?\n");
		return 0;
		}
	num=0;
	sscanf(str,"%s %d",str,num);
	obj=find_living(str);
	if(!obj)   {
		notify_fail("No "+str+" active now.\n");
		return 0;
		}
	if(obj == find_player(str))  {
		notify_fail("You can't wind a player!\n");
		return 0;
		}
	env=environment(obj);
	write("You cast a magic wind on "+ call_other(obj,"query_name")+".\n");
	tell_room(env,"A magic wind starts to blow and "+call_other(obj,"query_name")+" gets some damage from it!\n");
	if(!num)
		call_other(obj,"hit_player",(obj->query_mhp())+1);
	else
		call_other(obj,"hit_player",num);
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

check(arg)
{ object who;
  string ppl,funct;
  int nset;
  nset=0;
  if((!arg) || (!(sscanf(arg,"%s %s %d",ppl,funct,nset))))
         {  notify_fail("Check: Wrong syntax!\n");
            return 0;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 0; }
  write(capitalize(ppl)+"'s "+funct+": "+call_other(who,funct,nset)+".\n");
  return 1;
}

leaf(str)
 {
      string stuff,rece;
       object stuff1,rece1;
       rece=str;
       if((!str))
	      {   notify_fail("You fail to send.\n");
              return 0;
	      }
      if(!present("leaflet") || !find_living(rece))
             {   notify_fail("Leaflet or receiver not present.\n");
               return 0;
             }
 rece1=find_living(rece);
 stuff1=present("leaflet");
 move_object(stuff1,rece1);
write("You send a leaflet to "+rece1->query_name()+".\n");
tell_object(rece1,"Hurtbrain sends you a leaflet saying: 'read it,it's important'.\n");
 return 1;
 }
 
hsp(str) {
  object who;
  string what;
  if(str) {
    who=find_living(str);
    if(!who) {
      notify_fail("That is not on the MUD!\n");
      return 0;
    }
        write(who->query_name()+" : hit points: "+who->query_hp()+"; spell points: "+who->query_sp()+".\n");
    return 1;
  }
  write("Usage: hsp <monster>\n");
  return 1;
}

room(str)
{
if(!str)  {
	tell_room(environment(this_player()),"\n");
	return 1;
	}
tell_room(environment(this_player()),str+"\n");
return 1;
}

dhl(str)
 { 
    string stuff,rece;
    object stuff1,rece1;
    if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   notify_fail("You fail to send.\n");
          return 0;
      }
    if(!present(stuff) || !find_living(rece))
      {   notify_fail("Stuff or receiver not present.\n");
          return 0;
      }
    rece1=find_living(rece);
    stuff1=present(stuff);
    move_object(stuff1,rece1);
    tell_object(rece1,"A little elf gives you a "+stuff+" saying it's from Hurtbrain.\n");
    write("You send a "+stuff+" to "+rece1->query_name()+".\n");

    return 1;
  }

vanish(str)
  {
    string thing,ppl;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s",thing,ppl) !=2)))
        {  notify_fail("Vanish: Wrong syntax!\n");
           return 0;
         }
       ppl1= find_living(ppl);
       thing1= present(thing,ppl1);
       if(!ppl1 || !thing1) 
         { notify_fail("Vanish: Player or item not present!\n");
           return 0;
         }
       destruct(thing1);
      write("Ok.\n");
      tell_object(ppl1,"Hurtbrain's eyes glows red and "+thing+" disappears from your inventory.\n");
         return 1;
  }
       
force(str) {
  object who;
  string what;
  if(sscanf(str,"%s %s",who,what)==2) {
    if(!find_living(who)) {
      notify_fail("That is not on the MUD!\n");
      return 0;
    }
    command(what,find_living(who));
    write("Done.\n");
    write("You forced :"+who+" to "+what+".\n");
    return 1;
  }
  write("Usage: force <player> <action>\n");
  return 1;
}
