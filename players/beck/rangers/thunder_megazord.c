inherit "obj/monster";
#include "/players/beck/rangers/Defs.h"
static int old_hp;
static int old_exp;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("thunder megazord");
   set_level(20);
   set_alias("megazord");
   set_race("RangerMegazord");
   set_hp(350);
   set_ep(1000);
   set_al(1000);
   set_short("The Thunder MEGAzord");
   set_wc(30);
   set_ac(15);
   set_can_kill(1);
   set_chance(10);
   set_spell_dam(10);
   set_dead_ob(this_object());
   set_hbflag("hbstayon");
   old_hp = 350;
   old_exp = 1000;
   call_out("pl_damage",4);
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
         ob = first_inventory(corpse);
      }
   }
   move_object(oc, environment(corpse));
   command("look", oc);
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
   this_object()->attack_object(ta);
   ta->attack_object(this_object()); /* previous by wiz */
   return 1;
}
pl_damage(){
   int n;
   int new_hp;
   int damage;
   int new_exp;
   int exp;
   object first;
   object ob;
   if(this_object()->query_attack()){
      n = 0;
      new_hp = this_object()->query_hp();
      damage = (old_hp - new_hp)/3;
      old_hp = new_hp;
      new_exp = this_object()->query_exp();
      exp = (3*(new_exp - old_exp));
      old_exp = new_exp;
      for(ob = first_inventory(this_object()); ob; ob = next_inventory(ob)){
         if(ob->is_player()){
            n = n + 1;
            ob->add_hit_point(-damage);
            if(MASTER->QPowerPoints() < 10){
               tell_object(ob,"The MEGAzord is out of POWER!\n");
               call_out("pl_damage",5);
               return 1;
            }
            ob->add_exp(exp);
          }
      }
      MASTER->APowerPoints(-10);
      if( n == 0){
         say("Without someone to control them, the Thunderzords separate and fly away.\n");
         destruct(this_object());
         return 1;
      }
   }
   call_out("pl_damage",5);
   return 1;
}
query_player_shell(){return 1;}
