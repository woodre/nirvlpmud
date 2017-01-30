inherit "/obj/monster.c";
#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h"


object Owner;
string OwnerName;
int OwnerNumber;
string message;
object ownerattack;
set_OwnerName(str){ OwnerName = str; return 1;}
set_Owner(arg){ Owner = arg; return 1;}
set_OwnerNumber(arg){ OwnerNumber = arg; return 1;}
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
      if("/players/beck/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber))
      {
        tell_room(ENVOB, "The Zord flies back to the Command Center.\n");
        destruct(this_object());
        return 1;
      }
   }
   return;
}
set_message(str){
   message = str;
   return 1;
}

heart_beat(){
   if(!environment()) { set_heart_beat(0); return; } /* added by verte 6.6.01 */
   if(!Owner || !find_living(OwnerName) || Owner->query_ghost()){
      tell_room(environment(this_object()),"A Zord flies away for repairs.\n");
      "/players/beck/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber);
      destruct(this_object());
      return;
   }
   if(!present(Owner, environment(this_object()))){
      tell_room(ENVOB,"A "+message+" leaves.\n");
      move_object(this_object(), environment(Owner));
      tell_room(ENVOB,"A "+message+" arrives.\n");
   }
   if(!Owner->query_interactive() && !TO->query_attack())
      return;
   ::heart_beat();
   if(!attacker_ob && Owner && present(Owner, ENVOB) && present(Owner,ENVOB)->query_attack())
   { /* additional present() check by verte 6.6.01 */
      ownerattack = present(Owner, ENVOB)->query_attack();
      if(!ownerattack->is_player() || present(Owner,ENVOB)->RangerNPC())
      {
         this_object()->attack_object(present(Owner, ENVOB)->query_attack());
         if(weapon_class > random(30)) ZordRage(attacker_ob, 1);
         if(weapon_class > random(60)) ZordRage(attacker_ob, 5);
         if(weapon_class > random(90)) ZordRage(attacker_ob, 7);
      }
   }
   if(TO->query_attack() && !present(Owner, ENVOB)->query_attack()){
      if((TO->query_attack())->is_player())
         (this_object()->query_attack())->hit_player(50,"other|zord");
      tell_room(ENVOB,"The Zord becomes ferocious and crushes "+
         (this_object()->query_attack())->query_name()+" with immense force.\n");
   }
}


monster_died(object monster){ 
  tell_room(environment(this_object()),"The Zord flies back to the Command Center for serious repairs.\n");
  destruct(present("corpse",environment(this_object())));
  "/players/beck/Rangers/Commands/Zord.c"->reset_ownership(OwnerNumber);
  return;
}

query_player_shell(){ return 1;}

ZordRage(object a, int modifier)
{
  if(!a) return;
  a->hit_player( ((weapon_class*modifier)/2),"other|laser");
  tell_room(ENVOB, RageMessage());
  return 1;
}

string
RageMessage()
{
  string RageMessage, AttackerName;
  switch( random(4))
  {
    case  0: RageMessage =
      "A " + message + " inflicts great damage on the enemy\n";
      break;
    case  1: RageMessage =
      "A " + message + " surges into the heat of battle.\n";
      break;
    case  2: RageMessage =
      "A " + message + " leaps in to attack!\n";
      break;
    case  3: RageMessage =
      capitalize(OwnerName) + "'s " + message + " ferociously attacks the enemy.\n";
      break;
    default: RageMessage =
      "A " + message + " lashes out in a vicious attack.\n";
  }
  return RageMessage;
}

