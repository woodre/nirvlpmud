#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "obj/monster.c";
int hubble;
string beano;
object rope;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("vraalen");
set_alias("wanderer");
set_race("human");
set_short("Vraalen "+BOLD+"("+RED+"Ares Vendor"+NORM+BOLD+") ["+NORM+RED+"Wanderer"+NORM+BOLD+"]"+NORM);
set_long(
  " Vraalen is an older man that stands about 5 foot 6 inches. He\n"+
  "is wearing a long black robe with a piece of white twine tied\n"+
  "around his waist. A small glowing bag that is believed to hold\n"+
  "several 'items' is held leisurely in his old withered hand.\n");
 
set_level(10);
add_money(400+random(100));
set_hp(150);
set_al(1000);
set_ac(8);
set_wc(14);
set_gender("male");
set_aggressive(0);
set_chat_chance(3);
load_chat("Vraalen's eyes twinkle.\n");
load_chat("Vraalen asks, 'Ey der, what kin I gets fer ya?'.\n");
load_chat("Vraalen smiles at you.\n");
load_chat("Vraalen says, 'Culd ya tells me how to gets to da Dangerus Blade?'\n");
load_chat("Vraalen glances around.\n");
load_chat("Vraalen says, 'Ya shuld visit the inn, good place fer rest.'\n");
load_chat("Vraalen rummages through his bag.\n"); 
call_out("rolling_rolling_rolling", 30);
}

init(){
 ::init();
   add_action("bunchofstuff", "items");
   add_action("yeahsure", "buy");
 } 

rolling_rolling_rolling(){
  int poof;
  string goof;
  poof = random(8);
  switch(poof){
   case 0: goof = "north"; break;
   case 1: goof = "south"; break;
   case 2: goof = "east"; break;
   case 3: goof = "west"; break;
   case 4: goof = "shop"; break;
   case 5: goof = "bar"; break;
   case 6: goof = "inn"; break;
   case 7: goof = "out"; break; }
  if(!query_attack()){
  command(goof);  }
  call_out("rolling_rolling_rolling", 30);
  return 1; }


bunchofstuff(){
  write("Vraalen says, 'Ay so ya wants to see whas I got ey? ok heres me list.'\n\n");
  write(BOLD+"     ------------------------------------------------\n");
  write("     |"+NORM+YEL+"                 Vraalen's List"+NORM+BOLD+"                  |\n");
  write("     |"+NORM+YEL+"      Items                       Amount"+NORM+BOLD+"          |\n");     
  write("     ------------------------------------------------\n");
  write("     |                                              |\n");                    
  write("     |"+NORM+YEL+"   1. Kite                          50"+NORM+BOLD+"            |\n");                      
  write("     |                                              |\n"); 
  write("     |"+NORM+YEL+"   2. Flowers                       75"+NORM+BOLD+"            |\n");        
  write("     |                                              |\n");
  write("     |"+NORM+YEL+"   3. Pet Rock                     200"+NORM+BOLD+"            |\n"); 
  write("     |                                              |\n");
  write("     |"+NORM+YEL+"   4. Pogo Stick                   150"+NORM+BOLD+"            |\n");
  write("     |                                              |\n");
  write("     ------------------------------------------------"+NORM+YEL+"\n");
  write("                         You can 'buy #'"+NORM+"\n\n");
  return 1; }
 
yeahsure(str){
  if(str == "1"){
   hubble = 50;
   rope = CO("/players/fred/tcity/kite.c");
   beano = "a kite";
   }
  else if(str == "2"){
   hubble = 75;
   rope = CO("/players/fred/tcity/flowers.c");
   beano = "a bouquet flowers";
   }
  else if(str == "3"){
   hubble = 200;
   rope = CO("/players/fred/tcity/rock.c");
   beano = "a pet rock";
   }
  else if(str == "4"){
   hubble = 150;
   rope = CO("/players/fred/tcity/pstick.c");
   beano = "a pogo stick";
   }
  else{
   write("Vraalen looks confused.\n");
   return 1;
  }
 if(call_other(TP, "query_money", 0) < hubble){
    write("Vraalen chuckles. 'Yer gonna need more money fer dat one.'\n");
    destruct(rope);
    return 1; }          
 if(!TP->add_weight(rope->query_weight())) {
    write("Vraalen says, 'Ya canna seem to carry dat.'\n");
    destruct(rope);
    return 1; }  
 write("Vraalen smiles happily and hands you "+beano+".\n");                
 say(TPN+ " buys "+beano+".\n");
 MO(rope, TP);
 TP->add_money(-(hubble));
 return 1;
 }   
