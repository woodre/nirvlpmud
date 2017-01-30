#include "/players/fred/ansi.h"
inherit "obj/monster.c";
string person;
int a, b, play, run;
object sword, necklace;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("vinni");
set_race("human");
set_short(BOLD+RED+"Vinni"+NORM+", the irate trader");
set_long(
  " Vinni is a short man who is known for being able to get\n"+
  "certain things. He is a trader by heart though and always\n"+
  "wants something in return. You could 'ask' him about a \n"+
  "sword or 'inquire' about a piece of armor.\n");
 
set_level(30);
set_hp(750);
set_al(1000);
set_ac(27);
set_wc(40);
set_aggressive(0);
}

init(){
  ::init();
    add_action("askem","ask");
    add_action("inquirem","inquire");
    add_action("sword","sword");
    add_action("necklace","necklace");
  }

askem(){
  person = this_player();
  play = 1;
  call_out("talk",3,person);
  return 1; }
  
inquirem(){
  person = this_player();
  run = 1;
  call_out("speak",3,person);
  return 1; }

talk(person){
  say_it();
  a += 1;
  if(a<18) call_out("talk",2,person);
  else { 
  play = 0;
  a = 0;
  }
  return 1; }

speak(person){
  yell_it();
  b += 1;
  if(b < 18) call_out("speak",2,person);
  else {
  run = 0;
  b = 0;
  }
  return 1; }

say_it(){
  string stuff;
   switch(a){
     case 0: stuff =  " "; break;
     case 1: stuff = "                      Vinni looks up at you..."; break;
     case 2: stuff = " "; break;
     case 3: stuff = "      You look like an honest person so I'll tell you what I'll do"; break;
     case 4: stuff = " "; break;    
     case 5: stuff = "         I've got this sword I got from some guy I used to know"; break;
     case 6: stuff = " "; break;
     case 7: stuff = "      I was told it was a pretty good sword so if you want it you'll\n"+ 
                     "             have to bring me some other weapons in return"; break;
     case 8: stuff = " "; break;
     case 9: stuff = " "; break;
     case 10: stuff = "             All you have to bring me are these 3 weapons:"; break;
     case 11: stuff = " "; break;
     case 12: stuff = HIY+"                             Holysinger\n"+
                      RED+"                           Trident of War\n"+                
                      BOLD+BLK+"                        Crossbow of Vengence"+NORM; break;
     case 13: stuff = " "; break;
     case 14: stuff = " "; break;
     case 15: stuff = "          Once you have the items I desire bring them back here\n"+
                      "             and give them to me. After that just type 'sword'"; break;
     case 16: stuff = "                    It will also cost you 10k in coins"; break;
     case 17: stuff = " "; break; }
    tell_object(person,
    BOLD+stuff+NORM+"\n");
    return 1; }

yell_it(){
  string yada;
   switch(b){
     case 0: yada = " "; break;
     case 1: yada = "                           Vinni looks up at you..."; break;
     case 2: yada = " "; break;
     case 3: yada = "            You look like an honest person so this is what I'll do"; break;
     case 4: yada = " "; break; 
     case 5: yada = "            I've got this necklace I got from some guy I used to know"; break;
     case 6: yada = " "; break;
     case 7: yada = "        I guess it's supposed to be a pretty good piece of equipment so\n"+
                    "                 you'll have to get me some other armor in return"; break;
     case 8: yada = " "; break;
     case 9: yada = " "; break;
     case 10: yada = "             All you have to do is bring me these 3 pieces of armor:"; break;
     case 11: yada = " "; break;
     case 12: yada = HIY+"                               A Bad Toupee\n"+
                     RED+"                           Amulet of Protection\n"+ 
                     BOLD+BLK+"                             Black Knee Boots"+NORM; break;
     case 13: yada = " "; break;
     case 14: yada = " "; break;
     case 15: yada = "             Once you have the items I desire bring them back here\n"+
                     "              and give them to me. After that just type 'necklace'"; break;
     case 16: yada = "                      It will also cost you 6k in coins"; break; 
     case 17: yada = " "; break; }
   tell_object(person,
   BOLD+yada+NORM+"\n");
   return 1; } 

  
necklace(){
object one,two,three, pentacle;

one = present("amulet of protection", this_object());
two = present("knee boots", this_object());
three = present("fredo's ugly toupee", this_object());

pentacle = clone_object("/players/fred/forest/Obj/pentacle.c");
if (call_other(this_player(), "query_money", 0) < 6000) {
    write("Vinni informs you: You do not have enough money for that.\n");
    destruct(pentacle);
    return 1;
     }
if(!this_player()->add_weight(pentacle->query_weight())) {
    write("Vinni informs you: You can't carry that much.\n");
    destruct(pentacle);
    return 1; }  
if(one && two && three){
this_object()->add_weight(-(one->query_weight()));
this_object()->add_weight(-(two->query_weight()));
this_object()->add_weight(-(three->query_weight()));
destruct(one);
destruct(two);
destruct(three); 

write("Vinni smiles at you and hands you a necklace.\n");
this_player()->add_money(-(6000));  
move_object(pentacle, this_player());
write_file("/players/fred/log/amulet", this_player()->query_name() + " received an amulet " + ctime()[4..15] + "\n");
return 1;
}

write("Vinni says: You haven't given me all the items yet.\n");
return 1;
}

sword(){
 object one, two, three,sword;
 
one = present("vengence_bow", this_object());
two = present("holysinger", this_object());
three = present("trident of war", this_object());

sword = clone_object("/players/fred/forest/Obj/tractus.c");
if (call_other(this_player(), "query_money", 0) < 10000) {
    write("Vinni informs you: You do not have enough money for that.\n");
    destruct(sword);
    return 1;
     }
if(!this_player()->add_weight(sword->query_weight())) {
    write("Vinni informs you: You can't carry that much.\n");
    destruct(sword);
    return 1; }  
if(one && two && three){
 this_object()->add_weight(-(one->query_weight()));
 this_object()->add_weight(-(two->query_weight()));
 this_object()->add_weight(-(three->query_weight()));
 destruct(one);
 destruct(two);
 destruct(three); 

write("Vinni smiles at you and hands you a sword.\n");
this_player()->add_money(-(10000));
move_object(sword, this_player());
write_file("/players/fred/log/sword", this_player()->query_name() + " received a sword " + ctime()[4..15] + "\n");
return 1;
}


write("Vinni says: You haven't given me all the items yet.\n");
return 1;
}


