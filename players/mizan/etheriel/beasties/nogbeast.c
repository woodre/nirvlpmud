inherit "/players/mizan/core/monster.c";
int head1,head2,head3,head4;
int hps;

init(){
   ::init();
}

reset(arg){
   object weapon,ammo,note;
   int a;
   ::reset(arg);
   if(arg) return;
   set_name("nog");
   set_race("nog");
   set_alias("nog");
   set_short("Nog");
   set_level(19);
   set_hp(500);
   set_al(500);
   set_wc(22);
   set_ac(16);
  weapon=clone_object("/players/mizan/etheriel/items/spuckcannon.c");
   move_object(weapon,this_object());
  move_object(clone_object("/players/mizan/etheriel/items/spuckballs.c"), weapon);
   move_object(clone_object("/players/mizan/etheriel/items/spuckballs-ext2"), this_object());
     while(a < 4) {
       ammo=clone_object("/players/mizan/etheriel/items/spuckballs.c");
       move_object(ammo, this_object());
       a++;
       }
   set_chat_chance(10);
   load_chat("Nog makes grunting noises.\n");
   load_chat("Nog ploozles at you.\n");
   load_chat("Nog goes: nog nog nog nog nog.\n");
   enable_commands();
}
long(){write("This is a Nog, the Spuck equivalent of an armored troop carrier.\n"+
	"Nogs often absorb Spucktroopers and carry them to wherever they want\n"+
	"to go. Personally, this thing looks alot like a really big Boofer.\n"+extra_long()); }

heart_beat(){
   int dam;
   object attacker,room;
   string attacker_name;
   ::heart_beat();
   hps=this_object()->query_hp();
   room=environment(this_object());
   if(!room) return;
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
/* NewbieGuard */
  if(attacker->query_level() < 5) {
    tell_object(attacker, "Mizan tells you: RUN!!! This sucker is HARD!!!\n");
    command("down", attacker);
  return;
  }
         if(head1 == 0){
            if(1 == random(5)){
               tell_room(room,"Nog smushes "+capitalize(attacker_name)+" with its bulk!\n");
               dam=random(10);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Nog tried to smush "+capitalize(attacker_name)+" but missed.\n");
            }
            if(this_object()->query_hp() < 50){
               head1 = 1;
               tell_room(room,"Nog is tired, and decides not to smush anymore.\n");
            }
         }
         if(head2 == 0){
            if(1 == random(5)){
               tell_room(room,"Nog shoots a chunk of itself at "+capitalize(attacker_name)+" and hits!\n");
               dam=random(10);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Nog shoots a chunk of itself at "+capitalize(attacker_name)+" but misses.\n");
            }
            if(this_object()->query_hp() < 100){
               head2 = 1;
               tell_room(room,"Nog is getting too small to shoot its parts around anymore.\n");
            }
         }
         if(head3 == 0){
            if(1 == random(5)){
               tell_room(room,"Nog foggles "+capitalize(attacker_name)+".\n");
               dam=random(10);
	       tell_object(attacker, "You've been foggled! It hurt!\n");
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Nog tried to foggle "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 300){
               head3 = 1;
               tell_room(room,"Nog ran out of foggling power.\n");
            }
         }
         if(head4 == 0){
            if(1 == random(5)){
               tell_room(room,"Nog electrocutes "+capitalize(attacker_name)+".\n");
               dam=random(10);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Nog tried to electrocute "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 150){
               head4 = 1;
               tell_room(room,"Nog's internal battery died.\n");
            }
         }
      }
   }
}
extra_long(){
   string desc1;
   int hp;
   hp=this_object()->query_hp();
   desc1 = "in good shape.";
   if(hp < 500){desc1 = "slightly hurt.";}
   if(hp < 275){desc1 = "somewhat hurt.";}
   if(hp < 80){desc1 = "in bad shape.";}
   if(hp < 50){desc1 = "very bad shape.";}
   if(hp < 30){desc1 = "fighting for its life.";}
   if(hp < 20){desc1 = "in critical condition.";}
   return "Nog is "+desc1+"\n";
}
