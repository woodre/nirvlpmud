inherit "/obj/treasure.c";
int dmg_taken;

reset(arg){
   set_heart_beat(1);
}

get(){ return 0; }
drop(){ return 0; }

id(str){ return str == "@jaraxle@"; }

heart_beat(){
   if(!environment()) return;
   if(!environment()->is_npc()){ destruct(this_object()); return 1; }
   if(!random(3)){
      dmg_taken = environment()->query_dam_taken_this_round();
      environment()->heal_special(dmg_taken);
   }
}
