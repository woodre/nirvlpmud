#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name(GRN+"Goblin "+HIR+"Berzerker"+NORM);
   set_alias("berzerker");
   set_alt_name("goblin");
   set_race("goblin");
   set_short(GRN+"Goblin "+HIR+"Berzerker"+NORM);
   set_long("  A muscular. dark green tinted creature with red\n"+
      "beady eyes.  Drool spills freely from the cracks\n"+
      "of its mouth out of a sadistic grin.\n");
   set_level(12);
   set_hp(180);
   set_al(-1000);
   set_ac(5);
   set_aggressive(1);
   set_wc(18);
   set_dead_ob(this_object());
}

monster_died() {
   tell_room(environment(this_object()),
      "The "+GRN+"Goblin "+HIR+"Berzerker"+NORM+" falls to the ground lifeless.\n");
   return 0; }


special1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
say(GRN+"Goblin "+HIR+"Berzerker"+NORM+" screams angrilly, slashing into "+ATT_NAME+".\n");
   
   attacker_ob->hit_player(10+random(9));
}

special2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
say(GRN+"Goblin "+HIR+"Berzerker"+NORM+" charges blindly at "+ATT_NAME+".\n");
   
   attacker_ob->hit_player(14+random(6));
}

check_uni(){
   object uni;
   uni = present("unicorn",environment());
   if(uni){
      say("\tThe "+GRN+"Goblin "+HIR+"Berzerker"+NORM+" notices the "+HIW+"Unicorn"+NORM+"!\n");
      switch(random(4)){
case 0: say(GRN+"Goblin "+HIR+"Berzerker"+NORM+" charges blindly at the "+HIW+"Unicorn"+NORM+".\n");
         break;
case 1: say(GRN+"Goblin "+HIR+"Berzerker"+NORM+" rakes at the "+HIW+"Unicorn"+NORM+" with sharp claws.\n");
         break;
case 2: say(GRN+"Goblin "+HIR+"Berzerker"+NORM+" bites into the "+HIW+"Unicorn's"+NORM+" neck.\n");
         break;
case 3: say(GRN+"Goblin "+HIR+"Berzerker"+NORM+" pulls at the "+HIW+"Unicorn's"+NORM+" horn!\n");
         break;
      }
      uni->hit_player(10+random(10));
   }
}

heart_beat(){
 int i, x, z;
   ::heart_beat();
   if(!attacker_ob){
      object *obs;
      obs=all_inventory(environment(this_object()));
      x = sizeof(obs);
      for(z = 0; z < x; z++){
         if(obs[z]->query_guild_name() == "Knights Templar"){
attacked_by(obs[z]);
          }
      }
   }
   if(attacker_ob){
      i = random(10);
      switch(i){
         
         case 0..1: special1();
         break;
         
         case 2: special2();
         break;
         
         case 3..5: check_uni();
         break;
         
         case 6..9: return 0;
         break;
      }
   }
}
