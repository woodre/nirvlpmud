inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset(arg){
 ::reset(arg);
  if(!arg){
   object mushie;
   mushie = clone_object("players/persephone/closed/mushroom");
   move_object(mushie, TOB);
   set_name("alys");
   set_alias("girl");
   set_short("A little girl called Alys");
   set_long("This is a little girl by the name of Alys. She actually\n" +
           "looks quite harmless and seems to be crying about\n" +
           "something.\n");
   set_level (4);
   set_wc(5);
   set_ac(8);
   set_hp(80);
   set_al(1000);
   set_aggressive(0);
   set_gender(2);
   set_chat_chance(35);
   load_chat("Alyss asks: Do you have something for me?\n");
   load_chat("Alyss claims: I have this mushroom if you have something for me\n");
   load_chat("Alyss sobs: I will never get home I don't have the pills.\n");
  }
}
attacked_by(obj){destruct("mushroom");::attacked_by(obj);}
catch_tell(str) {
   object from;
   string a;
   string b;
   string c;
   object next_dest;
   string next_out;
   from = this_player();
   if(!from) 
    return;
   if(sscanf(str, "%s gives %s to Alys.", a, b) ==2) {
      object ob, ob2;
     ob2 = this_object();
     ob = present(b, this_object());
     if(!ob || !call_other(ob,"id","speed"))
       return;
     write("Alyss curtseys gracefully and goes back home.\n");
     destruct(this_object());
     return;
}
}
  
