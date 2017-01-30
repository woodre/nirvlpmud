inherit "/obj/monster.c";
#include "/players/beck/rangers/defs.h"

object Owner;
string OwnerName;
set_OwnerName(str){ OwnerName = str; return 1;}
set_Owner(arg){ Owner = arg; return 1;}
is_pet(){ return 1;}
reset(){
   ::reset();
   set_name("battlezord");
   set_alt_name("ranger_battlezord");
   set_race("machine");
   set_can_kill(1);
   set_hbflag("hbstayon");
   set_dead_ob(this_object());
   set_long("This is the personal Battlezord of a Power Ranger.\n");
}
init(){
   ::init();
   add_action("release","release");
}
long(){
   ::long();
   if(COMM){
      write("Type 'release' to send your Battlezord back to the command center.\n");
   }
}
release(){
   if(this_player() == Owner){
      COMM->set_has_battlezord(0);
      write("You send your Battlezord back to the command center for repairs.\n");
      destruct(this_object());
      return 1;
   }
   return;
}

heart_beat(){
   ::heart_beat();
   if(!present(Owner, environment(this_object()))){
      if(!find_player(OwnerName)){
         tell_room(ENV,"A Battlezord flies away for repairs.\n");
         destruct(this_object());
         return;
      }
      tell_room(ENV,"A Battlezord leaves.\n");
      move_object(this_object(), environment(Owner));
      tell_room(ENV,"A Battlezord arrives.\n");
      return;
   }
      if(!this_object()->query_attack() && present(Owner, ENV)->query_attack()){
         this_object()->attack_object(present(Owner, ENV)->query_attack());
      }
}

monster_died(object monster){
   if(present(Owner, ENV)){
      present("ranger_communicator",present(Owner,environment(this_object())))->set_has_battlezord(0);
      destruct(present("corpse",environment(this_object())));
      tell_room(environment(this_object()),"The Battlezord flies back to the Command Center for serious repairs.\n");
      return;
   }
}
query_player_shell(){ return 1;}
