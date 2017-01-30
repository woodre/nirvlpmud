#include "/players/maledicta/ansi.h"
inherit "obj/treasure";
#define COMM present("comm_helmet_mal", ppl[x])
int freq;

reset(arg) {
set_id("watch");
set_alias("comm_helmet_mal");
set_short(BOLD+"Communicator Watch"+NORM);
set_long(
"This is a small steel wrist communicator.  It allows you\n"+
"to speak with others that carry it or the communications\n"+
"helmet. \n"+
"To use the communication equipment:\n"+
"  freq  - Tells the current frequency it is on.\n"+
"  freq <1-10000> - sets the frequency.\n"+
"  radio <message> - will send to everyone on that\n"+
"                         frequency.\n"+
"Aliases for radio = rad and .\n");
set_weight(1);
set_value(200);
}

query_freq(){ return freq; }

init(){ 
 ::init();
 add_action("freq", "freq");
 add_action("radio", "radio", 3);
#ifndef __LDMUD
  add_action("radio"); add_xverb(".");
#else
  add_action("radio", ".", 3);
#endif
 }

freq(int i){
  int woo;
  if(!i){ 
  write("You are currently on frequency "+HIM+freq+NORM+".\n");
  return 1;
  }
  sscanf(i, "%d", woo);
  if(woo < 1 || woo > 10000){
    write("Frequency range is limited to 1 to 10000.\n");
    return 1;
    }
  write("Frequency set to "+woo+".\n");
  freq = woo;
  return 1;
  }

radio(str){
  int x;
  object ppl;
 if(!str){ write("radio <message>\n"); return 1; }
 if(!freq){ write("You must set a frequency!\n"); return 1; }
 
  ppl = users();
  for(x = 0; x < sizeof(ppl); x ++){
    if(ppl[x] != this_player()){
      if(COMM){
         if(COMM->query_freq() == freq){
           tell_object(ppl[x],
          HIG+this_player()->query_name()+" radios in, \""+NORM+GRN+str+NORM+HIG+"\""+NORM+"\n");
         }
      }    
    }
  }
 tell_room(environment(this_player()),
 this_player()->query_name()+" says: "+str+"\n", ({ this_player() }));
 tell_object(this_player(), "You radio in: "+str+"\n");
 return 1;
 }





