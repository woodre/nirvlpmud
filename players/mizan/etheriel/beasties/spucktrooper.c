inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/Tracking-D.c"
int head1,head2,head3;
int hps;

init(){
   ::init();
}

reset(arg){
   object weapon,ammo,clip;
   object gold;
   int a;
   ::reset(arg);
   if(arg) return;
   set_name("spucktrooper");
   set_race("spuck");
   set_alias("trooper");
   set_short("A Spucktrooper");
   set_long("This is a Spucktrooper, the backbone of the league of Spucks.\n"+
	"Basically, it looks kind of like a huge cell, something that\n"+
	"crawled straight out of your biology book's diagrams.\n"+
	"It flashes though, and changes color every so often.\n");
   set_level(17);
   set_hp(425);
   set_al(400);
   set_wc(24);
   set_ac(14);
   gold=clone_object("obj/money");
   gold->set_money(random(200)+100);
   move_object(gold,this_object());
   weapon=clone_object("/players/mizan/etheriel/items/spuck-shotgun.c");
   move_object(weapon,this_object());
   ammo=clone_object("players/mizan/etheriel/items/spuckballs-ext2.c");
   move_object(ammo, weapon);
  move_object(clone_object("players/mizan/etheriel/items/spuckballs-ext2.c"), this_object());
   while(a<2) {
     clip=clone_object("players/mizan/etheriel/heals/eigth-note.c");
     move_object(clip, this_object());
     a++;
     }
   set_chat_chance(10);
   load_chat("Spucktrooper coggles noisily.\n");
   load_chat("Spucktrooper changes color.\n");
   enable_commands();
}

heart_beat(){
   int dam;
   object attacker,room;
   string attacker_name;
   ::heart_beat();
   hps=this_object()->query_hp();
   room=environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
/* Newbieguard */
  if(attacker->query_level() < 3) {
    tell_object(attacker, "Mizan tells you: RUN for your LIFE!!!\n");
    command("down", attacker);
    }
         if(head1 == 0){
            if(1 == random(5)){
               tell_room(room,"Spucktrooper fires a spuckball at "+capitalize(attacker_name)+".\n");
               dam=random(15);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Spucktrooper missed "+capitalize(attacker_name)+".\n");
            }
            if(this_object()->query_hp() < 270){
               head1 = 1;
               tell_room(room,"Spucktrooper jammed its Spuckball shotgun.\n");
            }
         }
         if(head2 == 0){
            if(1 == random(5)){
               tell_room(room,"Spucktrooper fuzzles "+capitalize(attacker_name)+" violently!\n");
               dam=random(5);
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Spucktrooper tried to fuzzle "+capitalize(attacker_name)+" but failed.\n");
            }
            if(this_object()->query_hp() < 150){
               head2 = 1;
               tell_room(room,"Spucktrooper loses its fuzzling abilities due to battle damage.\n");
            }
         }
         if(head3 == 0){
            if(1 == random(4)){
               tell_room(room,"Spucktrooper mogs "+capitalize(attacker_name)+".\n");
               dam=random(8);
	       tell_object(attacker, "You have been mogged!\n");
               attacker->hit_player(dam);
            }
            else {
               tell_room(room,"Spucktrooper tried to mog "+capitalize(attacker_name)+" but missed.\n");
            }
            if(this_object()->query_hp() < 40){
               head3 = 1;
               tell_room(room,"Spucktrooper loses its poot and cannot mog anymore.\n");
            }
         }
      }
   }
}
