#include "/players/hippo/bs.h"
inherit "obj/monster";

#define MOV_RATE 10
object dna_repair;
void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("hiv");
set_alias("virus");
set_alias("hiv-virus");
set_alias("aids");
set_short("A HIV-virus");
set_long("Oeps.. you meet a HIV-virus here. You know what that means. You'd"+BS+
   "better run away, before it's gonna get you."+BS);
set_level(20);
set_ac(17);
set_wc(30);
set_al(-1000);
set_aggressive(1);
set_a_chat_chance(20);
   load_a_chat("GROAARG! I'm gonna get you!!!"+BS);
   load_a_chat("BRULL! You'd better take your ass outta here!!!"+BS);
   load_a_chat("You'll never get the repair mechanism back, i took it !!!"+BS);
   load_a_chat("You'll never get the repair mechanism back, i took it !!!"+BS);
       call_out("random_move",MOV_RATE);
}

status random_move(){
   int n;
   if(this_object()->query_attack()) {
      call_out("random_move",MOV_RATE);
      return 1;
   }
n=random(12);
   switch(n) {
      case 0 : command("north"); break;
      case 1 : command("east"); break;
      case 2 : command("south"); break;
      case 3 : command("west"); break;
      case 4 : command("up"); break;
      case 5 : command("down"); break;
case 6 : command("northwest"); break;
case 7 : command("northeast"); break;
case 8 : command("southeast"); break;
case 9 : command("southwest"); break;
case 10 : command("blood"); break;
case 11 : command("diffuse"); break;
   }
   call_out("random_move",MOV_RATE);
   return 1;
} 
