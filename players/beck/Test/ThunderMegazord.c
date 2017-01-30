inherit "obj/monster";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"
static int old_hp;
static int old_exp;
static int total_damage;
static string attacker_name;
object only_attack;
int in_battle;

realm(){ return "NT"; }
reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("thunder megazord");
   set_level(20);
   set_alias("megazord");
   set_race("RangerMegazord");
   set_hp(MASTER->QPowerPoints("Power Test"));
   set_ep(1000);
   set_al(1000);
   set_short("The Thunder "+BOLD+GREEN+"MEGA"+OFF+"zord");
   set_wc(35);
   set_ac(10);
   set_can_kill(1);
   set_chance(10);
   set_spell_dam(10);
   set_spell_mess1("The Megzord's Saber rips through the enemy with speed and precision.\n");
   set_dead_ob(this_object());
   set_hbflag("hbstayon");
   old_hp = hit_point;
   old_exp = 1000;
}
init(){
   ::init();
   if(present(this_player(), this_object())){
      add_action("move_zord","move");
      add_action("attack_other","demolish");
   }
   if(this_player()->query_level() > 19){
      add_action("zordin","zordin");
   }
}
move_zord(str){
   if(str != "north" && str != "south" && str != "east" && str != "west" &&
         str != "northeast" && str != "northwest" && str != "southeast" && str != "southwest" &&
      str != "up" && str != "down" && str != "in" && str != "out" && str != "exit" &&
      str != "enter" ){
      write("The Thunder Megazord cannot move that direction.\n");
      return 1;
   }
   command(str, this_object());
   look();
   return 1;
}
long(){
   if(present(this_player(), this_object())){
      write("You are inside the Thunder Megazord\n"+
         "You see a large control panel with various buttons and 2 joysticks.\n"+
         "You can 'move' the zord in any standard direction.\n"+
         "You can attempt to 'demolish' opponents, but beware...\n"+
         "When the Zord loses Power (hps)...so do you!\n"+
         "Make sure the guild power levels are high to power the Megazord through battle.\n"+
         "");
      return 1;
   }
   write("This is the awesome Thunder Megazord of the Power Rangers!\n"+
      "It is a 50 foot tall Robot comprised of 5 smaller Thunderzords.\n"+
      "The Thunder Megazord has tremendous power and strength.\n"+
      "");
   return 1;
}
zordin() {
   move_object(this_player(), this_object());
   return 1;
}
look(str){
   object ol;
   string sh;
   if(!str){
      environment()->long();
      for(ol = first_inventory(environment()); ol; ol = next_inventory(ol))
      if(ol !=this_object() && (sh = (string) ol->short())){
      tell_room(this_object(), sh); tell_room(this_object(), "\n");
      }
      return;
   }
   return 1;
}
catch_tell(string str){
   if(this_player() != this_object()){
      if(!this_player() || !present(this_player(), this_object()))
         tell_room(this_object(), str);
      return 1;
   }
   return 1;
}
monster_died(object monster){
   object corpse;
   object ob;
   object oc;
   set_short(0);
   log_file("beck.megazord","Megazord killed by "+
   attacker_name+" Damage: "+total_damage+" "+ctime(time())+"\n");
   MASTER->APowerPoints(-(MASTER->QPowerPoints("Power Test")),"Power Ranger");
   corpse = present("corpse", environment(this_object()));
   tell_room(corpse,"\n\n");
   tell_room(corpse,"You are thrown out of the Thunder Megazord.\n");
   tell_room(corpse,"\n\n");
   tell_room(corpse,"The Thunderzords separate and fly away.\n");
   tell_room(corpse,"\n\n");
   oc = first_inventory(corpse);
   for(ob = first_inventory(corpse); ob; ob = next_inventory(ob)){
      if(ob->is_player() && ob != oc){
         move_object(ob, environment(corpse));
         command("look", ob);
         ob->attack_object(only_attack);
         ob = first_inventory(corpse);
      }
   }
   move_object(oc, environment(corpse));
   command("look", oc);
   oc->attack_object(only_attack);
   destruct(corpse);
   return 0;
}
attack_other(str){
   object ta;
   if(!str){
      write("Who do you want to attack?\n");
      return 1;
   }
   ta = present(str, environment());
   if (!ta || !living(ta)){
      write("That target is not here.\n");
      return 1;
   }
   if(ta->is_player()){
      write("You can't attack players!!!\n");
      return 1;
   }
   if(only_attack){
      write("You can only attack one monster at a time!!!\n");
      return 1;
   }
   attacker_name = ta->NAME;
   this_object()->attack_object(ta);
   ta->attack_object(this_object()); /* previous by wiz */
   log_file("beck.megazord","Megazord attacked "+
   attacker_name+" "+ctime(time())+"\n");

   alt_attacker_ob = 0;
   return 1;
}
hit_player(arg){
   int n;
   int new_hp;
   int damage;
   int damage2;
   int new_exp;
   int exp;
   object first;
   object ob;
   hit_point = MASTER->QPowerPoints("Power Test");
   old_hp = hit_point;
   ::hit_player(arg);
   if(!TO) return;
   if(TO->query_ghost()) return;
   if(this_object()->query_attack()){
      n = 0;
      new_hp = hit_point;
      damage = (old_hp - new_hp);
      damage2 = damage;
      total_damage += damage;
      MASTER->APowerPoints(-(damage),"Power Test");
      damage = damage/5;
      for(ob = first_inventory(this_object()); ob; ob = next_inventory(ob)){
         if(ob->is_player() && !ob->query_ghost()){
            n = n + 1;
            ob->add_hit_point(-damage);
            tell_object(ob,"You take "+BOLD+RED+damage+OFF+" damage from the hit.\n");
            ob->monitor();
            if(ob->query_hp() <= 0) ob->hit_player(300);
         }
      }
      if( n == 0){
         say("Without someone to control them, the Thunderzords separate and fly away.\n");
         destruct(this_object());
         return;
      }
   }
   if(damage2 <= 0) return 0;
   return damage2;
}
heart_beat(){
   string msg;
   ::heart_beat();
   if(in_battle && !only_attack){
      ZordLeave();
      return;
   }
   if(query_attack()){
      in_battle = 1;
      if(hit_point < 100) msg = "critical";
      else if(hit_point < 1000) msg = "low";
      else if(hit_point < 2000) msg = "good";
      else msg = "very good";
      tell_room(TO,"Guild Power levels are "+BOLD+GREEN+msg+OFF+".\n");
      tell_room(TO,query_attack()->NAME+" hps: "+((10*query_attack()->query_hp())/(query_attack()->query_mhp()))+"/10\n");
      if(!only_attack){
         only_attack = query_attack();
      }
   }
}

ZordLeave(){
   object ob;
   object oc;
   set_short(0);
   log_file("beck.megazord","Megazord victorious over "+
   attacker_name+" Damage: "+total_damage+" "+ctime(time())+"\n");
   tell_room(TO,"The Battle is over and you are Victorious.\n");
   tell_room(TO,"\n\n");
   tell_room(TO,"The Thunderzords separate and fly away.\n");
   tell_room(TO,"\n\n");
   oc = first_inventory(TO);
   for(ob = first_inventory(TO); ob; ob = next_inventory(ob)){
      if(ob->is_player() && ob != oc){
         move_object(ob, environment(TO));
         command("look", ob);
         ob = first_inventory(TO);
      }
   }
   move_object(oc, environment(TO));
   command("look", oc);
   destruct(TO);
   return;
}


query_player_shell(){return 1;}
