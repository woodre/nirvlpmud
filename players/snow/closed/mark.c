#include "/players/boltar/things/esc.h"
 
#define TP this_player()
#define ENV environment
#define ETP ENV(TP)
#define CAP capitalize
#define TO this_object()
#define PRE present
#define MARK PRE("mark",TP)
#define MO move_object
#define TE tell_object
#define TR tell_room
#include "/players/snow/color.h"

id(str) { return str == "mark"; }
long() { 
   write("A mark of the Magi.\n"+
         "Type 'markhelp' for help files!\n");
return 1;
}
markhelp() {
  write("The mark currently has these powers..\n"+
    "healme:                      Heals you a lot.\n"+
    "paz:                         Stops all fighting.\n"+
    "bottleup <player>:           Trans <player> to bottle.\n"+
    "convert <player>:            Trans <player> to church.\n"+
    "movit <object><player>:      Move object to player.\n"+
    "geto <player>:               Transports to <player>.\n"+
    "summon <player>:             Summons <player>.\n"+
    "force <player><what>:        Forces <player> to do <what>.\n"+
    "ghostin <player>:            Turns <player> into a ghost.\n"+
    "exorcism <player>:           Removes ghost from <player>.\n"+
    "vanish <item><player>:       Dests <item> from <player>.\n"+
    "steal <item><player>:        Takes <item> from <player>.\n"+
    "check <function>:            Calls a function.\n"+
    "setnum <pl><fun><amt>:       Sets an integer function.\n"+
    "set2num <pl><fun><fun><amt>: Sets a dual integer function.\n"+
    "setword <pl><fun><word>:     Sets a word function.\n"+
    "pget <object>:               Takes object.\n"+
    "pdrop <object>:              Drops object.\n"+
    "wtell <player><str>:         Tells player <string>.\n"+
    "allinv <object>:             Shows inventory of room/obj/etc.\n"+
    "metas:                       List of meta commands.\n"+
    "dests:                       List of desting commands.\n"+
    "binds:                       List of binding commands.\n"+
    "where:                       Places possible to 'hop' to.\n"+
    "hop <place>:                 Hop to <place>.\n"+
    "do <cmd>, <cmd>, etc.        Execute a series of commands.\n"+
    "guild <player>:              Checks guild status of <player>.\n"+
    "unguild <player>:            Removes guild status of <player>.\n"+
    "view <player> <a/h>:         Quicktyper checking device.\n"+
    "upall:                       Updates all cyberninja implants.\n"+
    "obput <path> <where>         Moves <path> to <where>.\n"+
    "tsunami                      Washes everyone in room to church.\n"+
    "titleme:                     Sets "+WHITE+"Snow"+OFF+" title.\n"+
    "hand <player><objectpath>:   Gives <object> to <player>.\n");
return 1;
}
 
healme() { 
    write("The mark heals you.\n");
    call_other(this_player(),"heal_self",100000000);
    return 1;
}
 
no_fight() {
 object ob;
    ob=first_inventory(environment(this_player()));
    while(ob) {
      if(living(ob)) {
        if(ob->query_attack()) {
          (ob->query_attack())->stop_fight();
          ob->stop_fight();
        }
      }
      ob = next_inventory(ob);
    }
  write("You raise a hand, and the fighting stops.\n");
  say(this_player()->query_name()+" raises a hand, and the fighting stops.\n");
return 1;
}
 
dungeon_player(str) {
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
   tell_object(ob,"You are bottled up.\n");
   move_object(ob, "players/snow/closed/bottle.c");
   tell_room(there,capitalize(str)+" is bottled up.\n");
   write (capitalize(str) + " is bottled up.\n");
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
 
trans_object(str) {
    string stuff,rece;
    object stuff1,rece1;
    if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   write("You fail to send.\n");
          return 1;
      }
    if(!present(stuff) || !find_living(rece))
      {   write("Stuff or receiver not present.\n");
          return 1;
      }
    rece1=find_living(rece);
    stuff1=present(stuff);
    move_object(stuff1,rece1);
    tell_object(rece1,"A "+stuff+" appears in your arms.\n");
    write( "Transfer of "+stuff+" complete.\n" );
return 1;
}
 
goto(str) {
  object ob;
 
  ob = find_player(str);
  if(!ob) { write(capitalize(str)+" cannot be found.\n"); return 1; }
  write("You begin transfer...\n");
  move_object(this_player(),environment(ob));
  write("Transfer complete.\n");
  command("look",this_player());
return 1;
}
 
bring_player(str) {
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
 tell_object(ob, "You feel a strange tingling in your body...\n"+
      "You look down and realize you can see right through yourself...\n"+
      "You are sucked into the ether...\n");
    move_object(ob, environment(this_player()));
    tell_room(there, capitalize(str)+
    " disappears into the ether...\n");
    say (capitalize(str) + " reforms in the room.\n");
    write (capitalize(str) + " appears before you.\n");
    return 1;
}
 
force (str) {
    object player;
      string name,cmd;
if (!str) return 0;
if ((sscanf (str,"%s %s",name,cmd))<2) return 0;
   player=find_living(name);
 if (!player) notify_fail(capitalize(name) + "is not online.\n");
command(cmd,player);
return 1;
}
 
add_ghost(str) {
   object ghob;
   ghob = find_living(str);
   call_other(ghob, "second_life", 0);
   write(str + " is now a ghost.\n");
   return 1;
}
 
rem_ghost(str) {
   object ghob;
   ghob = find_player(str);
     tell_object(ghob, "\n\n\n" +
     "You scream and writh around.\n" +
     "Your head spins...\n" +
     "The ghost is exorcised and your body reforms anew.\n");
   call_other(ghob, "remove_ghost", 0);
   write(str + " is no longer a ghost.\n");
return 1;
}
 
vanish(str) {
    string thing,ppl;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s",thing,ppl) !=2)))
        {  write("Vanish: Wrong syntax!\n");
           return 1;
         }
      ppl1 = find_living(thing);
      thing1 = present(ppl, ppl1);
       if(!ppl1 || !thing1)
         { write("Vanish: Player or item not present!\n");
           return 1;
         }
       destruct(thing1);
      write("<DESTED>: "+ppl+".\n");
      write("You destroyer, you!\n");
     return 1;
}
 
steal(str) {
    string thing,ppl;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s",thing,ppl) !=2)))
        {  write("Vanish: Wrong syntax!\n");
           return 1;
         }
       ppl1= find_living(ppl);
       thing1= present(thing,ppl1);
       if(!ppl1 || !thing1)
         { write("Vanish: Player or item not present!\n");
           return 1;
         }
       move_object(thing1,this_player());
      write("<TAKEN>: "+thing+".\n");
      write("You are the master thief!\n");
      return 1;
  }
        
check(arg) {
  object who;
  string ppl,funct;
  if((!arg) || ((sscanf(arg,"%s %s",ppl,funct) !=2)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who = present(ppl, environment(this_player()) );
  if(!who) who = present(ppl, this_player());
  if(!who) who = find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write(capitalize(ppl)+"'s "+funct+": "+call_other(who,funct,)+".\n");
  return 1;
}
 
setnum(arg) {
  object who;
  string ppl,funct;
  int num;
  if((!arg) || ((sscanf(arg,"%s %s %d",ppl,funct,num) !=3)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write("Ok.\n"); call_other(who,funct,num);
  return 1;
}
 
set2num(arg) {
  object who;
  string ppl,funct;
  int num,num2;
  if((!arg) || ((sscanf(arg,"%s %s %d %d",ppl,funct,num,num2) !=4)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write("Ok.\n"); call_other(who,funct,num,num2);
  return 1;
}
 
setword(arg) {
  object who;
  string ppl,funct,word;
  if((!arg) || ((sscanf(arg,"%s %s %s",ppl,funct,word) !=3)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write("Ok.\n"); call_other(who,funct,word);
  return 1;
}
 
power_get(str) {
  object ob;
  if(!str) return 0;
  ob = present(str,environment (this_player()));
   if(!ob) { write ("No "+str+" here.\n"); return 1; }
write ("You take: "+ob->short() + ".\n");
move_object(ob,this_player());
return 1;
}
 
power_drop(str) {
     object ob;
    if(!str) return 0;
    ob = present(str,this_player());
    if(!ob) { write("You don't have that...\n"); return 1; }
    move_object(ob,environment(this_player()));
    write("You have dropped the " +str+ ".\n");
return 1;
}
 
identify_object(str) {
   object ob;
   ob=present(str,this_player());
   if(!ob) {
     write("That is not in your inventory.\n");
   return 1;
   }
   if(ob) {
      write("<IDENTIFY>\n");
      write("NAME:          "+ob->short()+"\n");
      write("weapon class:  "+ob->weapon_class()+"\n");
      write("armor class:   "+ob->armor_class()+"\n");
      write("weight:        "+ob->query_weight()+"\n");
      write("value:         "+ob->query_value()+"\n");
      write("save:          "+ob->query_save_flag()+"\n");
      return 1;
   }
}
 
wiz_tell(str) {
object plyr;
string who;
string what;
string myname;
if(!str) { write("Tell what?\n"); return 1; }
  if(sscanf(str,"%s %s",who,what) != 2) {
    write("Tell <who> <what>.\n"); return 1; }
    plyr = find_living(who);
    myname = BOLD+capitalize(this_player()->query_real_name())+OFF;
  if(!plyr) { write(capitalize(who)+" is not online right now.\n"); return 1; }
  if(!plyr->query_interactive()) { write(who+" is disc.\n"); return 1; }
  if(this_player()->query_invis() > 1) {
    TE(plyr, myname+" quietly tells you ~ "+what+" ~\n");
    write("You tell "+capitalize(who)+": "+BOLD+what+OFF+"\n");
  plyr->add_tellhistory("Snow tells you: "+what);
  return 1;
  }
  TE(plyr, myname+" tells you <~> "+BOLD+what+OFF+" <~>\n");
 write("You essence to "+capitalize(who)+": <~>"+BOLD+what+OFF+"<~>\n");
  plyr->add_tellhistory("Snow tells you: "+what);
return 1;
}

settrib(str) {
  string one, two;
  int three;
  if(!str || sscanf(str,"%s %s %d",one,two,three) != 3) {
    write("Usage: settrib <player> <attrib> <number>\n");
    return 1;
  }
  if(!find_player(one)) { write(capitalize(one)+" not found."); return 1; }
  call_other(find_player(one),"set_attrib",two,three);
  write("Your will is done.\n");
  return 1;
}

all_room(string str) {
   object room, allroom;
  int i;
  if(!str) room = ETP;
  if(!room) room = find_object(str);
  if(!room) room = find_player(str);
  if(!room) room = find_living(str);
  if(!room) { write("Room/Object/Player ["+str+"] not found.\n"); return 1; }
  allroom = all_inventory(room);
  write("--[("+file_name(room)+") : "+room->short()+"]--\n");
  for(i=0; i < sizeof(allroom); i++) {
    write("("+file_name(allroom[i])+") : "+allroom[i]->short()+"\n");
  }
  return 1;
}

dest_all_room(string str) {
   object room, allroom;
  int i;
  if(!str) room = ETP;
  if(!room) room = find_object(str);
  if(!room) room = find_player(str);
  if(!room) room = find_living(str);
  if(!room) { write("Room/Object/Player ["+str+"] not found.\n"); return 1; }
  allroom = all_inventory(room);
  write("--[("+file_name(room)+") : "+room->short()+"]--\n");
  for(i=0; i < sizeof(allroom); i++) {
    write("("+file_name(allroom[i])+") : DESTED\n");
    destruct(allroom[i]);
  }
  return 1;
}

dest_all(string str) {
  string one, two, three, four, five;
  int a, b, c;
  object ob, ob2, ob3;
  if(!str) {
    write("Usage: destall <object or filename> or\n"+
          "       destall p <level>\n");
    return 1;
  }
  if(sscanf(str,"%s",one) == 1) {
    ob = users();
    for(a=0; a < sizeof(ob); a++) {
      ob2 = all_inventory(ob[a]);
      for(b=0; b < sizeof(ob2); b++) {
        if(file_name(ob2[b]) == one ||
           ob2[b]->id() == one) {
          two = ob2[b]->short();
          three = environment(ob2[b])->query_real_name();
          write("~D ["+two+"] from : "+capitalize(three)+"\n");
          destruct(ob2[b]);
        }
      }
    }
    write("Destruction complete.\n");
    return 1;
  }
  if(sscanf(str,"%s %d",one,a) == 2) {
    if(one == "p") {
      write("Destructing players under level: ["+a+"]\n");
      ob = users();
      for(b=0; b < sizeof(ob); b++) {
        c = ob[b]->query_level();
        if(c < a) {
          write("~D ["+ob[b]->query_real_name()+"]\n");
          destruct(ob[b]);
        }
      }
      write("Destruction complete.\n");
      return 1;
    }
  }  
}

place_object(string str) {
  object to, what;
  string one, two;
  if(!str  || sscanf(str,"%s %s",one, two) != 2) { 
    write("Usage: obput <object path> <who, what, or where>\n"); 
    return 1; 
  }
  what = clone_object(one);
  if(!what) {
    write("["+one+"] failed to be cloned.\n");
    return 1;
  }
  to = present(two,this_player());
  if(!to) to = find_player(two);
  if(!to) to = find_living(two);
  if(!to) {
    move_object(one,two);
    write("["+one+"] moved to "+two+"\n");
    return 1;
  }
  move_object(one,to);
  write("["+one+"] moved to "+to->query_real_name()+"\n");
  return 1;
}

put_player(str) {
  object p;
  string one, two;
  if(!str || sscanf(str, "%s %s", one, two) != 2) {
    write("Usage: pplayer <player> <where>\n"); return 1; }
  p = find_player(one);
  move_object(p, two);
  write(one+" moved to destination "+two+"\n");
  return 1; }

obdest(string str) {
  if(!str) {
    write("What object would you like to dest?\n");
    return 1;
  }
  if(!find_object(str)) {
    write("Object ["+str+"] not found.\n");
    return 1;
  }
  destruct(find_object(str));
  return 1;
}

wave_away(string str) {
  object ob;
  int i;
  if(!str || (str != "p" && str != "o" && str != "all")) {
    write("Usage: tsunami <p , o , or all>\n"); return 1; }
  ob = all_inventory(ETP);
  TR(ETP,"<>A tsunami RAGES through the room!<>\n");
  if(str == "p") {
    for(i=0; i < sizeof(ob); i++) {
      if(ob[i]->query_real_name() != "snow" &&
         ob[i]->is_player()) {
        TE(ob[i],"\n               The wave CRASHES into you!\n\n");
        MO(ob[i],"/room/church");
        command("look",ob[i]);
      }
    }
  }
  if(str == "o") {
    for(i=0; i < sizeof(ob); i++) {
      if(!living(ob[i])) {
        TE(TP,"  D ["+file_name(ob[i])+"] : "+ob[i]->short()+"\n");
        destruct(ob[i]);
      }
    }
  }
  if(str == "all") {
    for(i=0; i < sizeof(ob); i++) {
      if(living(ob[i]) && ob[i]->query_real_name() != "snow") {
        TE(ob[i],"\n             The wave CRASHES into you!\n\n");
        MO(ob[i],"/room/church");
        TE(ob[i],"....You wash ashore in the church...\n");
      }
      if(!living(ob[i])) {
        TE(TP,"  D ["+file_name(ob[i])+"] : "+ob[i]->short()+"\n");
        destruct(ob[i]);
      }
    }
  }
  TR(ETP,"<>The wave disappears.<>\n");
  return 1;
}

find_dest(string str) {
  object gone;
  gone = find_object(str);
  if(gone) {
    write(" D ["+gone->short()+"] on "+ENV(gone)->short()+"\n");
    destruct(gone);
    return 1;
  }
  write(CAP(str)+" not found.\n");
  return 1;
}

add(arg) {
  int answer, sum1, sum2;
  if(!arg) { notify_fail("Add what?\n"); return 0; }
  if(sscanf(arg, "%d %d", sum1, sum2) !=2) {
    notify_fail("Numbers.\n"); return 0; }
  answer = sum1 + sum2;
  write("Answer = "+answer+".\n");
  return 1; }

subtract(arg) {
  int answer, sum1, sum2;
  if(!arg) { notify_fail("Subt what?\n"); return 0; }
  if(sscanf(arg, "%d %d", sum1, sum2) !=2) {
    notify_fail("Numbers.\n"); return 0; }
  answer = sum1 - sum2;
  write("Answer = "+answer+".\n");
  return 1; }

multiply(arg) {
  int answer, sum1, sum2;
  if(!arg) { notify_fail("Mult what?\n"); return 0; }
  if(sscanf(arg, "%d %d", sum1, sum2) !=2) {
    notify_fail("Numbers.\n"); return 0; }
  answer = sum1 * sum2;
  write("Answer = "+answer+".\n");
  return 1; }

divide(arg) {
  int answer, sum1, sum2;
  if(!arg) { notify_fail("Divi what?\n"); return 0; }
  if(sscanf(arg, "%d %d", sum1, sum2) !=2) {
    notify_fail("Numbers.\n"); return 0; }
  answer = sum1 / sum2;
  write("Answer = "+answer+".\n");
  return 1; }

title_me() {
  write("Setting pretitle...\n");
 TP->set_pretitle("    ("+WHITE+BOLD+"*"+OFF+") ("+WHITE+BOLD+"*"+OFF+")"+WHITE+BOLD);
  write("Setting title...\n");
  TP->set_title(OFF+"("+WHITE+BOLD+"*"+OFF+")");
  write("Setting alignment...\n");
  TP->set_al_title(WHITE+BOLD+"*"+OFF);
  return 1; }

light_value(str) {
  object ob, checkob;
  int lit;
  if(str) {
    ob = find_player(str);
    if(!ob) ob = find_living(str); }
  if(!ob) ob = TP;
  if(!ob) return;
  if(!environment(ob)) return;
  checkob = clone_object("/players/snow/closed/lcheck.c");
  move_object(checkob, environment(ob));
  lit = checkob->lightcheck();
  destruct(checkob);
  write(file_name(environment(ob))+" light = "+lit+"\n");
  return 1; }

newbie_pretitle(str) {
 object ob;
  if(!str) { write("Npre who?\n"); return 1; }
  ob = find_player(str);
  if(!ob) { write(str+" is not on Nirvana.\n"); return 1; }
 ob->set_pretitle("("+BOLD+BLUE+"Newbie Helper"+OFF+")");
  write("Newbie helper pretitle set for "+str+".\n");
  return 1; }

lacar_title() {
  object ob;
  ob = find_player("lacar");
  if(!ob) { write("Lacar is not on Nirvana.\n"); return 1; }
  ob->set_title(BOLD+GREEN+"--'--,-"+OFF+BOLD+RED+"@"+OFF+" Lady Of Roses "+BOLD+RED+"@"+OFF+BOLD+GREEN+"-,--'--"+OFF);
  write("Lacar title set.\n"); return 1; }
