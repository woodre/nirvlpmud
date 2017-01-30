#define TR  tell_room(environment(this_object())
#define fine  145

id(str) {return str=="ceremony"; }

string initiate, sponsor, p, s;


drop() {return 0; }
get() {return 1;}

query_weight() {return 10000;}
query_value() {return 0; }

set_initiate(str) {
  initiate=str;}

set_sponsor(str) {
  sponsor=str;}

init() {
  set_heart_beat(1);
  add_action("final","woodewoo");
  add_action("dodatdere","dodatdere");
  }
  
int hb;
heart_beat() {
  


hb ++;
if(hb==2) {
  TR,"Mythos raises his hands and deep\n"+
     "within the Earth a bell sounds.\n");
}

if(hb==5 || hb== 10 || hb== 15 || hb== 20 || hb==25){
  TR,"\n\t\tBONG\n");
}

if(hb==30) {
  TR,"\nAs the bell's low tone fades away all \n"+
     "five figures bow in unison.\n");
}

if(hb==32) {
  TR,"The room darkens....\n");
  }
  
if(hb==35) {
  TR,"Mythos raises a hand and points a finger at "+capitalize(initiate)+".\n"+
     "He speaks in a low tone: I see we are here to lead someone to darkness.\n");
}

if(hb==38) {
 if(sponsor != "mythos") {
  command("nod",find_player(sponsor)); }
  else {
  TR,"Mythos gives a cold smile and stares at "+capitalize(initiate)+".\n"); }
}

if(hb==43) {
if(sponsor != "mythos") {
  command("say I have brought one who may become something of greatness",find_player(sponsor));
  } else {
  TR,"Mythos closes his eyes...\n");}
  }

if(hb==46) {
  TR,"Mythos nods and glances at the other guild members....\n");
  }
  
if(hb==49) {
  TR,"Clasping his hands together, Mythos intones in a low voice...\n");
}

if(hb==55) {
  TR,"Suddenly the room shakes...  a deep voice calls out from the altar!\n");
  }

if(hb==58) {
  TR,capitalize(initiate)+", know the power of darkness!\n");
  }

if(hb==61) {
  TR,"Know that once upon the path to darkness, the Dark Fae will not let go.\n"+
     "Know that an oath must be taken, and that oath must never be broken!\n");
}

if(hb==64) {
  TR,"Know that light can hurt one and darkness is your friend.\n"+
     "And know that power is something to always seek.\n");
}

if(hb==68) {
  TR,"Prophet, what is power?\n");
  }

if(hb==75) {
  TR,"The Prophet <Mythos> answers: Sacrifice- the First Principle.\n");
  }

if(hb==80) {
  TR,"Warden, what is power?\n"); }
  
if(hb==85) {
  TR,"The Warden answers: Strength and Strategy.\n");}

if(hb==90) {
  TR,"Praetor, what is power?\n");}

if(hb==95) {
  TR,"The Praetor answers: Balance and Magic.\n"); }

if(hb==100) {
  TR,"Archivist, what is power?\n"); }

if(hb==105) {
  TR,"The Archivist answers: Knowledge and Writing.\n"); }

if(hb==110) {
  TR,"Nameless, what is power?\n"); }

if(hb==115) {
  TR,"The Nameless answers: Secrets and Darkness.\n"); }
  
if(hb==125) {
  TR,"Think upon what path you wish to follow.....\n"+
     "Know that all is not as it seems....\n");
   }

if(hb==128) {
  TR,"Mythos smiles...\n\n"+
      "A strange wind blows..\n"); }
  
if(hb==135) {
  TR,"Thunder sounds and then all is quiet...\n"); }

if(hb==fine) {
  set_heart_beat(0);
  call_out("final_call",1);
  return 1;}
}

int f;

final_call(){
  destruct(present("quiet", find_player(initiate)));
  TR,"An ancient voice rumbles: ");
  TR,capitalize(initiate)+", ye muts now state thine oath.\n");
  move_object(this_object(), find_player(initiate));
  command("woodewoo", find_player(initiate));
  return 1;
}


final() {
  if(f) return;
  tell_object(find_player(initiate),"\nOath: ");
  f=1;
  input_to("oath");
  return 1;
  }
  
oath(p){
if(!p || p == "") {input_to("oath"); return 1;}
  move_object(this_object(),environment(find_player(initiate)));
  TR,capitalize(initiate)+"'s oath is as stated: "+p+"\n");
  write_file("/players/mythos/closed/guild/ceremony/oaths",capitalize(initiate)+
             "   -sponsored by "+capitalize(sponsor)+"    <"+ctime(time())+">\n"+
             "\tOath: "+p+"\n");
  call_out("last",6);
  return 1;}
  

last() {
  TR,"Let the one who shall guide "+capitalize(initiate)+"\n"+
     "come forth and seal the pact.\n");
     move_object(this_object(),find_player(sponsor));
  command("dodatdere",find_player(sponsor));
  return 1;
}

dodatdere()
{
  tell_object(find_player(sponsor),"\nWill you seal the pact? <Y/N>  ");
  input_to("seal",0);
  return 1;}

seal(s) {
  if(lower_case(s) == "y") {
  move_object(this_object(),environment(find_player(sponsor)));
    command("emote steps forward and presses a bloody finger to "+capitalize(initiate)+
    "'s forehead",find_player(sponsor));
    TR,"A VOICE rings out:  THE PACT IS SEALED!\n");
    move_object(clone_object("/players/mythos/closed/guild/ob.c"),find_player(initiate));
    write_file("/players/mythos/closed/guild/member/first/"+initiate,ctime(time())+" sponsor:"+
               sponsor+"\n");
    destruct(this_object());
    return 1;}
  if(lower_case(s) == "n") {
  move_object(this_object(),environment(find_player(sponsor)));
    TR,"The pact has been refused!\n");
    destruct(this_object());
    return 1;}
  write("What?\n");
  input_to("seal",0);
  return 1;}    
