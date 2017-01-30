#include "/players/mythos/closed/ansi.h"
#define ep  environment(this_object())
#define eep environment(ep)
int biom, pulse_rate, jj;
string msg;
string SCREEN;
    
id(str) {return str == "biometer" || str == "reader"; }
short() { return msg;}
long() { write("A Biometer.  To turn on or off\n"+
               "type <bion>.  To set how often\n"+
               "it is to go off type <rate> \n"+
               "<# of heartbeats>  normal rate\n"+
               "1 heartbeat.\n"+
               "Note: Lag will affect the rate.\n"+
               "      In case 'bion' is not possible\n"+
               "      use the command <readon>\n"+
               "      also, in case biometer has a glitch\n"+
               "      type <biofix> to get an update\n"+
               "      to change screen color type <screen>\n"+
               "      blue is default.\n"+
               "                         - Mythos\n"); }
drop() {return 0;}
get() {return 1;}
query_value() { return 0;}
query_weight() { return 1;}

reset(arg) {
  if(arg) return;
  biom = 0;
  SCREEN = BLU;
  pulse_rate = 3;
  msg = "A Biometer";
}

init() {
if(ep == this_player()) {
  add_action("bion","bion"); 
  add_action("bion","readon");
  add_action("screen_color","screen");
  add_action("update","biofix");
  add_action("change_pulses","rate");}
}

screen_color(str) {
  if(!str) { write("Usage: screen <color>\n"+
                   "Available colors are: \n"+
                   "        green, blue, white, purple, black\n");
             return 1;}
  if(str != "green" && str != "blue" && str != "white" &&
     str != "purple" && str != "black") return 0;
  if(str == "green") SCREEN = GRN;
  if(str == "blue") SCREEN = BLU;
  if(str == "white") SCREEN = WHT;
  if(str == "purple") SCREEN = MAG;
  if(str == "black") SCREEN = BLK;
  write("Screen of Biometer is now "+SCREEN+capitalize(str)+NORM+".\n");
return 1;}
  
change_pulses(str) { 
  if(!str) { jj = 1; }
  if(str && sscanf(str,"%d",jj) != 1) return 0;
   if(jj < 1) { jj = 1; }
   pulse_rate = jj * 3; 
   write("Biometer rate is now set at "+jj+" heartbeats.\n");
return 1;}

bion() {
  biom = !biom;
  if(!biom) {
    write("Biometer turned off.\n");
    msg = "A Biometer";
    remove_call_out("hb");
  } else {
  write("Biometer turned on.\n"+
        "Rate set at "+pulse_rate/3+" heartbeats.\n"+
        "Scanning environment....\n\n\n"+
        RED+"Scan done.\n\n"+NORM);
  msg = "A Biometer "+BLU+" <on>"+NORM;
  hbb();
  }
return 1;}

hbb() {
object targ;
int k,l,max;
  if(!biom) { return 1;}
  if(!living(ep)) { biom = 0; msg = "A Biometer"; return 1;}
  l = 0;
  targ = all_inventory(eep);
  tell_object(ep,BOLD+"U: "+NORM);
  tell_object(ep,RED+((ep->query_hp()) * 10 / ep->query_mhp())+"/10  "+NORM);

  for(k = 0; k <sizeof(targ);k++) {
    if(targ[k] != ep && living(targ[k]) && !(targ[k]->id("messenger")) &&
       !(targ[k]->query_invis()) && !(targ[k]->query_ghost())) {
       if(l > 4) { tell_object(ep,"\n"); l = 0; }
      tell_object(ep,BOLD+targ[k]->query_name());
      tell_object(ep,NORM+": "+SCREEN+
            targ[k]->query_hp() * 10 / targ[k]->query_mhp()+"/10  "+NORM);
      l = l + 1; 
      }
  }
  
  tell_object(ep,"\n");
call_out("hbb",pulse_rate);
return 1;}

update() {
  move_object(clone_object("/players/mythos/mmisc/biometer.c"),ep);
  write("Biometer refreshed and updated.\n");
  command("readon",this_player());
  destruct(this_object());
return 1;}
