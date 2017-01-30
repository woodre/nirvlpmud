/*  My channel of eliteness.  Version 3.6.9  */
#include "/players/quicksilver/closed/color.h"

object poopers;
static int muffled;

reset(arg) {
/*
   "players/sado/shop/shop"->short();
   if(!present("qdisp", find_object("players/sado/shop/shop"))) move_object(clone_object("players/quicksilver/nicker"), find_object("players/sado/shop/shop"));
*/
   if(arg) return;
   poopers=({ });
   restore_object("players/quicksilver/closed/etc/poopers");
   "players/quicksilver/workroom"->short();
   "players/quicksilver/closed/qtell"->id();
   "players/quicksilver/closed/jtell"->id();  
   "players/quicksilver/closed/esoteric"->id();  
   "players/quicksilver/closed/wedding_band"->id();  
   return 1;
}

init() {
   write("[Poop]: Now in Poop-nicolor!\n");
   add_action("reclone","fresh_poop");
   add_action("qchat","poop");
   add_action("helpme","help");
   add_action("list_poopers","poowho");
   add_action("poop_on","poop_on");
   add_action("muffle","muffle_poop");
   add_action("unmuffle","unmuffle_poop");
}

query_auto_load() {
   return "/players/quicksilver/closed/qchan.c:";
}

get() { return 1; }
drop() { return 1; }
id(str) { return str=="qchat"; }

helpme(str) {
   if(str!="poop") return 0;
   write("Poop v. 3.6.9 commands:\n");
   write("   poop <msg>\t- Drop a load on the other poopers.\n");
   write("   poop :<msg>\t- Emoting, for times when you can't express shite in words.\n");
   write("   poop @<msg>\t- Poop echo.\n");
   write("   poowho\t- Show the other poopers currently on.\n");
   write("   fresh_poop\t- Get a new pooper.\n");
   write("   muffle_poop\t- For when you don't give a shit.\n");
   write("   unmuffle_poop- To return to a regular bal program.\n");
   return 1;
}

reclone() {
     object poop;
     
     poop=clone_object("players/quicksilver/closed/qchan");
     if(poop) {
          move_object(poop, environment(this_object()));
          write("You're back on 'the throne' again.\n");
          destruct(this_object());
          return 1;
     }
     write("Something is rotten in the state of Denmark.\n");
     return 1;
}

list_poopers() {
   object pooper;
   int x;
   
   write(YEL+"Currently logged in members of Clan Poop:"+NOSTYLE+"\n");
   for(x=0; x<sizeof(poopers); x++) {
      pooper=find_player(poopers[x]);
      if(pooper) write("   "+capitalize(poopers[x])+"\n");
   }
   return 1;
}

qchat(str) {
   string msg;
   object pooper;
   string name;
   int x;
   
   if(!str) {
      notify_fail("Are you gonna say anything?  Shit or get off the pot.\n");
      return 0;
   }
   if(muffled) {
      notify_fail("Er, you're like muffled or something.\n");
      return 0;
   }
   name=capitalize(this_player()->query_real_name());
   msg=YEL+(((str[0]==58)||(str[0]==64)) ? "<Poop>" : (name+" poops"))+
   ": "+NOSTYLE+((str[0]==58) ? (name+
   " ") : "")+(((str[0]==58)||(str[0]==64)) ? str[1..strlen(str)] : str)+"\n";
   for(x=0; x<sizeof(poopers); x++) {
      pooper=find_player(poopers[x]);
      if(pooper&&!present("qchat",pooper)->query_muffled()) 
         tell_object(pooper,msg);
   }
   return 1;
}

freshen() { restore_object("players/quicksilver/closed/etc/poopers"); }
query_muffled() { return muffled; }
query_poopers() { return poopers; }

muffle() { 
   if(muffled) {
      notify_fail("Er, you're already muffled or something.\n");
      return 0;
   }
   qchat(":doesn't give a poop (for now).");
   muffled=1;
   return 1;
}

unmuffle() { 
   if(!muffled) {
      notify_fail("Er, you're not muffled, dude.\n");
      return 0;
   }
   muffled=0;
   qchat(":starts giving a poop again.");
   return 1;
}

poop_on(str) {
   object who;
   int x;
   
   if(this_player()->query_real_name()!="quicksilver") return 0;
   if(!str) return 0;
   who=find_player(str);
   if(!who) {
      write(capitalize(str)+" isn't logged on.\n");
      return 1;
   }
   qchat(":poops on "+capitalize(str)+"!");
   poopers+=({ str });
   save_object("players/quicksilver/closed/etc/poopers");
   for(x=0; x<sizeof(poopers); x++) {
      who=find_player(poopers[x]);
      if(who&&present("qchat",who)) present("qchat",who)->freshen();
   }
   move_object(clone_object("players/quicksilver/closed/qchan"), who);
   return 1;
}
