inherit "/obj/monster.c";
#include "/players/beck/Defs.h"
#include "/players/beck/DarkRangers/RangerDefs.h"

object Owner;
string OwnerName;
string message;
object ownerattack;
set_OwnerName(str){ OwnerName = str; return 1;}
set_Owner(arg){ Owner = arg; return 1;}
reset(){
   ::reset();
   set_name("zord");
   set_alt_name("RangerZord");
   set_race("machine");
   set_can_kill(1);
   set_hbflag("hbstayon");
   set_dead_ob(this_object());
   set_long("This is the personal Zord of a Power Ranger.\n");
}
init(){
   ::init();
   add_action("release","release");
}
long(){
   ::long();
   if(COMM){
      write("Type 'release' to send your Zord back to the command center.\n");
   }
}
release(){
   if(this_player() == Owner){
      COMM->SZord(0);
      tell_room(ENVTP, "The Zord flies back to the Command Center.\n");
      destruct(this_object());
      return 1;
   }
   return;
}
set_message(str){
   message = str;
   return 1;
}

heart_beat(){
   if(!Owner || !find_living(OwnerName)){
      tell_room(environment(this_object()),"A Zord flies away for repairs.\n");
      destruct(this_object());
      return;
   }
   if(!present(Owner, environment(this_object()))){
      tell_room(ENVTP,"A "+message+" leaves.\n");
      move_object(this_object(), environment(Owner));
      tell_room(ENVTP,"A "+message+" arrives.\n");
   }
   if(!Owner->query_interactive() &&!TO->query_attack())
      return;
   ::heart_beat();
   if(!this_object()->query_attack() && present(Owner,ENVTP)->query_attack()){
      ownerattack = present(Owner, ENVTP)->query_attack();
      if(!ownerattack->is_player() || present(Owner,ENVTP)->RangerNPC()){
         this_object()->attack_object(present(Owner, ENVTP)->query_attack());
      }
   }
   if(this_object()->query_attack() && !present(Owner, ENVTP)->query_attack()){
      (this_object()->query_attack())->hit_player(35);
      tell_room(ENVTP,"The Zord becomes ferocious and crushes "+
         (this_object()->query_attack())->query_name()+" with immense force.\n");
   }
}


monster_died(object monster){
   if(Owner)
      present("DarkRangerCommunicator",Owner)->SZord(0);
   tell_room(environment(this_object()),"The Zord flies back to the Command Center for serious repairs.\n");
   destruct(present("corpse",environment(this_object())));
   return;
}
query_player_shell(){ return 1;}
