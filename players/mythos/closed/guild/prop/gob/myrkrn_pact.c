#include "/players/mythos/closed/ansi.h"
#include "/players/mythos/closed/guild/def.h"
#define eep environment(ep)
int biom, pulse_rate, jj, dimmed,nnum,col;
string msg;
string SCREEN;
    
    
id(str) { return str == "biometer" || str == "myrkrn_pact" || 
                str == "amulet" || str == "dyre"; }
short() { return msg;}
long() { write("This is the Amulet of Dyre.  A strange dark metal\n"+
               "makes up its chain and a glowing, deep "+HIM+"purple"+NORM+
               " stone is set into it.  \nIts powers lie dormant within until "+
               "the word 'die-nu' is spoken.\n"+
               "Note: the rate may be changed- <rate> <# 1-5>\n"+
               "      the toggle for the emotes is <effect on/off>\n"+
               "      the initial settings are: rate 1, effect on\n"+
               "      to update type <update_bion>\n"+
               "      to change screen color type <screen>\n"+
               "      blue is default.\n"); 
         write("Type <config> to change the types of living\n"+
               "creatures you wish to scan.  The default is\n"+
               "set for any living creature <for both>\n"+
               "To check for Amulet's settings type <settings>\n");
         write("                                    -Mythos\n");
       }
drop() {return 1;}
get() {return 0;}
query_auto_load() { return "/players/mythos/closed/guild/prop/gob/myrkrn_pact.c:";}


query_value() { return 0;}
query_weight() { return 1;}

reset(arg) {
  if(arg) return;
  col = ({0,0});
  biom = 0;
  SCREEN = BLU;
  dimmed = 1;
  pulse_rate = 3;
  msg = "Amulet of Dyre";
  call_out("hbb",3);
}

init() {
if(ep == this_player()) {
if(!pp) { destruct(this_object()); return 1; }
  add_action("screen_color","screen");
  add_action("change_pulses","rate");
  add_action("configure","config");
  add_action("shows","settings");
  add_action("dimmer","effect");
  add_action("bion","die-nu"); 
  add_action("dimmer","effect");
  add_action("change_pulses","rate");
  add_action("update","update_bion");}
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

dimmer(str) {
  if(!str) return 0;
  if(str != "on" && str != "off") return 0;
  if(str == "on") { 
    dimmed = 1;
    write("The amulet flares to life!\n");
    say("The Amulet of Dyre suddenly flares to life!\n");
  }
  else { 
    dimmed = 0; 
    write("The amulet dims.\n");
  }
return 1;}

shows() {
string show;
int k;
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
    write("The amulet's inner flame dims.\n"+
          "The Dark Fae disperse and the room brightens.\n");
    if(dimmed) {
    say("The Dark Fae in "+capitalize(tpn)+"'s eys extinguish.\n"+
        "Suddenly the room seems a bit brighter.\n");
    }
    msg = "Amulet of Dyre";
  } else {
    write("\nYou gather the Fae around you and whisper the word: "+HIG+
          "DIE-NU"+NORM+
          "\nThe Dark Fae responds and your senses heighten.\n\n");
    shows();
    if(dimmed) { write("on\n"); }
    else { write("off\n"); }
    if(dimmed) {
      say(capitalize(tpn)+"'s eyes glaze for a moment and \n"+
          "he whispers the word "+
          HIG+"DIE-NU.\n"+NORM+
          "Dark Fae flares brightly in his eyes and \n"+
          "the lights in the room dim briefly\n");
    }
  msg = "Amulet of Dyre"+HIM+" <glowing>"+NORM;
  }
return 1;}

hbb() {
object targ, pjt, poss;
int k,l,q,wq;
object checked;
int n,max;
  if(biom && ep) {
  l = 0;
  checked = 0;
  targ = all_inventory(eep);
  tell_object(ep,BOLD+"U: "+NORM);
  tell_object(ep,RED+((ep->query_hp()) * 10 / ep->query_mhp())+"/10  "+NORM);
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
      tell_object(ep,BOLD+targ[k]->query_name());
      tell_object(ep,NORM+": "+SCREEN+
            targ[k]->query_hp() * 10 / targ[k]->query_mhp()+"/10  "+NORM);
      checked = targ[k];
      max = 1;
      }
      }
  }
  }
  tell_object(ep,"\n");
  if(present(fear,ep) && !(present(fear,ep)->query_defence())) {
  for(k = 0; k <sizeof(targ);k++) {
    if(targ[k]->is_player() && targ[k] != ep && !(targ[k]->id("masakado")) &&
       !(targ[k]->id("amoril")) && !(targ[k]->id("jinro"))) {
         if(targ[k]->query_attack() && targ[k]->query_level() < 20) {
         if(targ[k]->query_attack() == ep) {
           tell_object(targ[k],capitalize(ep->query_real_name())+
             " turns to gaze at you with eyes of deep purple.\n"+
             "He whispers softly but clearly, 'I am not your play thing!'\n"+HIM+
             "Dark Fae erupts from the ground beneath you...\n"+NORM+
             "When the fae receds you find yourself in the void.\n");
           tell_object(ep,
            "You turn to gaze at "+targ[k]->query_name()+"- rage burning in you.\n"+
            "You whisper softly but clearly, 'I am not your play thing!'\n"+HIB+
            "The Dark Fae responds to your needs and envelops "+
            targ[k]->query_name()+".\n"+NORM+
            "The Fae sends "+targ[k]->query_name()+" to the void.\n");
            tell_room(eep,targ[k]->query_name()+" leaves at the Fae's command!\n");
            move_object(targ[k],"/room/void.c");
         call_out("hbb",pulse_rate);
  return 1;}}
    }
  }
 }
  }
  
  /* here the party object check is placed */
  if(ep) {
  pjt = present("party object",ep);
  if(pjt) {
    if(pjt->short() != "A party object (leader)") {  
      command("party leave",ep); 
      call_out("hbb",pulse_rate);
    return 1;}
    poss = users();
    wq = 0;
    for(q=0;q<sizeof(poss);q++) {
      if(present("party object",poss[q]) && poss[q] != ep) {
         if(present("party object",poss[q])->leadername() == capitalize(epn) &&
            poss[q]->query_real_name() != "stone" &&
            poss[q]->query_real_name() != "alita" && nnum > 3) {
              command("party share "+poss[q]->query_real_name()+" "+
                       (((poss[q]->query_level())/5) + 1),ep);
              wq = 1;
         }
      }
    }
    nnum = nnum + 1;
    
    if(wq) { command("party share "+epn+" "+ep->query_level(),ep); wq = 0; nnum = 0;}
 } }
call_out("hbb",pulse_rate);
return 1;}

update() {
  move_object(clone_object("/players/mythos/closed/guild/prop/gob/myrkrn_pact.c"),
              tp);
  write(HIB+"Bion updated...\n"+NORM);
  tp->save_me();
  destruct(this_object());
return 1;}