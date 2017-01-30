#include "/players/mythos/closed/ansi.h"
#define ep  environment(this_object())
#define eep environment(ep)
int biom, pulse_rate, jj, col;
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
               "      blue is default.\n"); 
         write("Type <config> to change the types of living\n"+
               "creatures you wish to scan.  The default is\n"+
               "set for any living creature <for both>\n"+
               "To check for Biometer settings type <settings>\n");
         write("                                    -Mythos\n");
       }
drop() {return 0;}
get() {return 1;}
query_value() { return 0;}
query_weight() { return 1;}

reset(arg) {
  if(arg) return;
  col = ({0,0});
  biom = 0;
  SCREEN = BLU;
  pulse_rate = 3;
  msg = "A Biometer";
}

init() {
if(ep == this_player()) {
  if(ep->query_real_name() == "guest") { destruct(this_object()); return 1; }
   if(this_player()->query_guild_name() != "cyberninja")
  add_action("bion","bion"); 
  add_action("bion","readon");
  add_action("screen_color","screen");
  add_action("update","biofix");
  add_action("change_pulses","rate");
  add_action("configure","config");
  add_action("shows","settings");}
}

configure(str) {
string row, column;
int gen;
  if(!str) { write("Usage: config <which> <type>\n"+
                   "       which = 1, 2, both\n"+
                   "       type = mon, live, pet, kid, play\n"+
                   "         note:  live = any living thing\n"+
                   "                mon = non-kid/non-pet/non-player monster\n"+
                   "                pet = pet type monster\n"+
                   "                kid = kid type monster\n"+
                   "                play = player\n");
            return 1;}
  if(sscanf(str,"%s %s",column,row) != 2) return 0;
  if(column != "1" && column != "2" && column != "both") { write("Beep!\nYou have mistyped.\n"); return 1;}
  if(row != "mon" && row != "live" && row != "pet" && row != "kid" && row != "play") {
  write("Beep!\nYou have mistyped.\n"); return 1;}
  if(row == "live") gen = 0;
  if(row == "mon") gen = 1;
  if(row == "pet") gen = 2;
  if(row == "kid") gen = 3;
  if(row == "play") gen = 4;
  if(column == "1") col[0] = gen;
  if(column == "2") col[1] = gen;
  if(column == "both") col[0] = col[1] = gen;
  shows();
return 1;}

shows() {
string show;
int k;
if(!ep) return 1;
  tell_object(ep,"Configuration of Biometer is: \n");
  for(k=0;k<sizeof(col);k++) {
    switch(col[k]) {
      case 0: show = "Living"; break; 
      case 1: show = "Monster"; break;
      case 2: show = "Pet"; break; 
      case 3: show = "Kid"; break; 
      case 4: show = "Player"; break; 
  }
  tell_object(ep,"  Type: "+show);
  }
  tell_object(ep,"\n  Screen: "+SCREEN+" ");
    if(SCREEN == GRN) tell_object(ep,"Green"+NORM+"\n");
    if(SCREEN == BLU) tell_object(ep,"Blue"+NORM+"\n");
    if(SCREEN == WHT) tell_object(ep,"White"+NORM+"\n");
    if(SCREEN == MAG) tell_object(ep,"Purple"+NORM+"\n");
    if(SCREEN == BLK) tell_object(ep,"Black"+NORM+"\n");
  tell_object(ep,"  Rate set: "+pulse_rate/3+" heartbeats.\n");
return 1;}

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
  write("Biometer turned on.\n");
  shows();
  write("  Scanning environment....\n\n\n"+
        RED+"  Scan done.\n\n"+NORM);
  msg = "A Biometer "+BLU+" <on>"+NORM;
  hbb();
  }
return 1;}

hbb() {
object targ;
object checked;
int k,l,n,max;
int selfmax;
  if(!biom) { return 1;}
  if(!ep) return 1;
  if(!living(ep)) { biom = 0; msg = "A Biometer"; return 1;}
  l = 0;
  checked = 0;
  targ = all_inventory(eep);
  tell_object(ep,BOLD+"U: "+NORM);
  selfmax = ep->query_mhp();
  if(selfmax > 0)
  tell_object(ep,RED+((ep->query_hp()) * 10 /selfmax) + "/10  "+NORM);
  else tell_object(ep,"Your Max HP is 0 or less.  Log out and log back in!\n");
  for(n=0;n<sizeof(col);n++) {
  max = 0;
  for(k = 0; k <sizeof(targ);k++) {
    if(targ[k] != ep && living(targ[k]) && !(targ[k]->id("messenger")) &&
       !(targ[k]->query_invis()) && !(targ[k]->query_ghost()) && !max && targ[k] != checked) {
         if(col[n] == 0 || 
            (col[n] == 1 && !(targ[k]->is_player()) && !(targ[k]->is_kid()) && !(targ[k]->is_pet())) ||
            (col[n] == 2 && targ[k]->is_pet() && !(targ[k]->is_kid())) ||
            (col[n] == 3 && targ[k]->is_kid()) ||
            (col[n] == 4 && targ[k]->is_player())) { 
    if(targ[k]->query_real_name() != "guest") {
     if(targ[k]->query_mhp()) {
      tell_object(ep,BOLD+targ[k]->query_name());
      tell_object(ep,NORM+": "+SCREEN+
            targ[k]->query_hp() * 10 / targ[k]->query_mhp()+"/10  "+NORM);
      checked = targ[k];
      max = 1;
    }
  }
      }
      }
  }
  }
  tell_object(ep,"\n");
call_out("hbb",pulse_rate);
return 1;}

update() {
   if(!ep) return 1;
  move_object(clone_object("/players/mythos/mmisc/biometer.c"),ep);
  write("Biometer refreshed and updated.\n");
  command("readon",this_player());
  destruct(this_object());
return 1;}
