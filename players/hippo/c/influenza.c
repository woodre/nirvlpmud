#include "/players/hippo/bs.h"
inherit "obj/monster";

   int n;
#define MOV_RATE 20
void reset(int arg){
   ::reset(arg);
     if(arg) return;
set_name("influenza");
set_alias("virus");
set_short("The influenza virus");
set_long("This is a influenza virus. It's not very dangerous, but if you"+BS+
   "meet a lot of them, you'd maybe better put your wimpy on."+BS);
set_level(14);
set_wc(18);
set_ac(13);
set_hp(220);
set_al(-300);
set_aggressive(1);
add_money(500+random(500));  /* Fred */
set_a_chat_chance(5);
   load_a_chat("HAAAA! You wanna be infected?"+BS);
   load_a_chat("I'll call the other virusses!"+BS);
   load_a_chat("You should dare to come back when i'm not alone!"+BS);
   load_a_chat("You think you can hurt ME? With that silly weapon you wield??"+BS);
   load_a_chat("Oeps, you little bastard! That hurts!"+BS);
   load_a_chat("Influenza virus laughs... and laughs... and laughs!"+BS);
}
status random_move(){
   int n;
  if(!environment(this_object())) return 1;
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
