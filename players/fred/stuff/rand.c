#include "/players/fred/ansi.h"
inherit "obj/monster.c";
#define pop (this_object()->query_attack())
#define atn pop->query_name()
#define tp this_player()->query_name()
#define tpp this_player()->query_possessive()
int a, b, c, d;
string A, B, C, D;
object attacker;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

a = random(5);
b = random(5);
c = random(9);
d = random(5);

switch(a){
  case 0: A = "Gloom"; break;
  case 1: A = "Mist"; break;
  case 2: A = "Figure"; break;
  case 3: A = "Form"; break;
  case 4: A = "Blob"; break; }

switch(b){
  case 0: B = "Wandering"; break;
  case 1: B = "Lost"; break;
  case 2: B = "Wounded"; break;
  case 3: B = "Disgruntled"; break;
  case 4: B = "Enraged"; break; }

switch(c){
  case 0: C = BLU; break;
  case 1: C = BOLD+BLK; break;
  case 2: C = BOLD+RED; break;
  case 3: C = HIY; break;
  case 4: C = HIG; break;
  case 5: C = HIB; break;
  case 6: C = MAG; break;
  case 7: C = CYN; break;
  case 8: C = BOLD; break; }

switch(d){
  case 0: D = "head"; break;
  case 1: D = "shoulder"; break;
  case 2: D = "arm"; break;
  case 3: D = "chest"; break;
  case 4: D = "legs"; break; }

set_alias("crappem");
set_race("creature");
set_short("A "+B+" "+C+A+NORM);
set_al(-(random(1000)));
set_aggressive(0);
set_gender("male");
set_chance(50);
set_dead_ob(this_object());

if(A == "Blob"){ blob(); }
if(A == "Mist"){ mist(); }
if(A == "Figure"){ figure(); }
if(A == "Form"){ form(); }
if(A == "Gloom"){ gloom(); }
if(B == "Wandering"){ wandering(); }
if(B == "Lost"){ lost(); }
if(B == "Wounded"){ wounded(); }
if(B == "Disgruntled"){ disgruntled(); }
if(B == "Enraged"){ enraged(); }
}

blob(){
  set_name("blob");
  set_long(
    "This is a "+B+" blob of an unknown substance. It slowly\n"+
    "oozes around like a large mass of jello. It looks menacing\n"+
    "and not all that happy.\n");
  set_spell_mess1(
    "\n       The "+B+" blob begins to bubble and hiss...\n\n"+
     "           It "+HIY+"ERUPTS"+NORM+" covering the room with thick GOo.\n");
  set_spell_mess2(
    "\n       The "+B+" blob begins to bubble and hiss...\n\n"+
    "            It "+HIY+"ERUPTS"+NORM+" violently covering you in a thick GOo.\n"); 
  set_chat_chance(4);
  load_chat("The blob shakes violently...\n");
  load_chat("The blob jiggles as it runs into a wall...\n");
  load_chat("The blob makes squishy noises as it wobbles...\n");
  }
mist(){
  set_name("mist");
  set_long(
    "A "+B+" mist that wraps around your body like a blanket.\n"+
    "It invades your senses making it difficult to concentrate.\n");
  set_spell_mess1(
    "\n   The "+B+" mist builds up and "+C+"WHIPS"+NORM+" around like a cyclone.\n");
  set_spell_mess2(
    "\n   The "+B+" mist builds up and "+C+"WHIPS"+NORM+" around you like a cyclone.\n\n"+
    "         You scream loudly as the mist "+C+"tears"+NORM+" at your flesh.\n");
  set_chat_chance(4);
  load_chat("The mist floats around...\n");
  load_chat("The mist swirls around you...\n");
  load_chat("The mist engulfs you then clogging your mind...\n");
  }
figure(){
  set_name("figure");
  set_long(
    "A "+B+" mysterious figure that is shrouded in a dark black\n"+
    "robe. Two large "+RED+"red"+NORM+" eyes glare at you from under the hood\n"+
    "sending chills down your spine.\n");
  set_spell_mess1(
    "\n   The "+B+" figure's eyes "+C+"Flare"+NORM+" as he raises his arms to the sky...\n\n"+
    "           Large balls of "+RED+"Fire"+NORM+" cascade into the room.\n");             
  set_spell_mess2(
    "\n   The "+B+" figure's eyes "+C+"Flare"+NORM+" as he raises his arms to the sky...\n\n"+
    "        Large balls of "+BOLD+RED+"Fire"+NORM+" fall from the sky pelting you mercilessly.\n");  
  set_chat_chance(4);
  load_chat("The figure's eyes burn with anger...\n");
  load_chat("The figure grins at you...\n");
  load_chat("The figure says, you will never escape this place.\n"); 
  }
form(){
  set_name("form");
  set_long(
    "A "+B+" form that you can't figure out quite what it is. It\n"+
    "appears to be older and has seen many battles in his day. It\n"+
    "looks you over and then produces an evil grin.\n");
  set_spell_mess1(
    "\n     The "+B+" form "+C+"concentrates"+NORM+" for a minute and goes into a frenzy...\n\n"+
    "               It unleashes several "+CYN+"devastating"+NORM+" blows...\n");
  set_spell_mess2(
    "\n           The "+B+" form goes into a frenzy...\n\n"+
    "     "+HIY+"striking "+NORM+"you with a devastating blow to the "+C+D+NORM+".\n"); 
  set_chat_chance(4);
  load_chat("The form cackles...\n");
  load_chat("The form looks around the room...\n");
  load_chat("The form watches and waits...\n");
  }
gloom(){
  set_name("gloom");
  set_alias("shadow");
  set_long(
    "A "+B+" gloom that darts in and out of the darkness. A\n"+
    "dangerous creature that could strike at you from the darkness\n"+
    "at any given moment.\n");
  set_spell_mess1(
    "\n     The shadow "+HIB+"shrouds"+NORM+" the room in total darkness...\n\n"+
    "         You can here "+C+"muffled"+NORM+" screams for help!\n");
  set_spell_mess2(
    "\n    You are "+GRN+"sucked"+NORM+" into the darkness with the shadow...\n\n"+
    "        The shadow mauls you with a clean blow to the "+C+D+NORM+".\n");
  set_chat_chance(4);
  load_chat("The shadow leaps into the darkness and is gone...\n");
  load_chat("The shadow darts around the room...\n");
  load_chat("The shadow leaps from the darkness in front of you...\n");
  }


wandering(){
  set_level(12);
  add_money(random(100)+550);
  set_wc(random(3)+15);
  set_ac(9);
  set_hp(180);
  set_spell_dam(5); }
lost(){
  set_level(14);
  add_money(random(100)+800);
  set_wc(random(3)+17);
  set_ac(11);
  set_hp(210);
  set_spell_dam(10); }
wounded(){
  set_level(16);
  add_money(random(100)+850);
  set_wc(random(3)+21);
  set_ac(13);
  set_hp(400);
  set_spell_dam(15); }
disgruntled(){
  set_level(18);
  add_money(random(200)+1000);
  set_wc(random(3)+25);
  set_ac(15);
  set_hp(450);
  set_spell_dam(25); }
enraged(){
  set_level(20);
  add_money(random(500)+4800);
  set_wc(random(3)+29);
  set_ac(17);
  set_hp(500);
  set_spell_dam(30); 
}
        
init(){
  ::init();
    add_action("block_dir","east",1);
    add_action("block_dir","west",1);
    add_action("block_dir","north",1);
    add_action("block_dir","south",1);
    add_action("block_dir","up",1);
    add_action("block_dir","down",1);
    add_action("block_dir","northeast");
    add_action("block_dir","northwest");
    add_action("block_dir","southwest");
    add_action("block_dir","southeast");
    add_action("block_dir","ne");
    add_action("block_dir","nw");
    add_action("block_dir","se");
    add_action("block_dir","sw");
}

block_dir(){
  if(present("crappem", environment(this_player()))){
  write("The "+B+" "+A+" blocks your path.\n");
  say(tp+" tries to leave but a "+B+" "+A+" blocks "+tpp+" path.\n");
  return 1;  } 
}  

