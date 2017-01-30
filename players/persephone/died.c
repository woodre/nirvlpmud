inherit "obj/monster";
object attacker;
string attacker_name;
init(){
   add_action("pick","pick");
}

reset(arg){
   object gold,crown;
   ::reset(arg);
   if(arg) return;
   set_name("felzar");
   set_race("human");
   set_alias("witch");
   set_short("Felzar, Witch Queen of Midnight!");
   set_long("Felzar was not a man, but a powerful sorceress!\n");
   set_level(70);
   set_hp(2500);
   set_al(-1000);
   set_wc(1);
   set_ac(12);
   set_dead_ob(this_object());
   gold=clone_object("obj/money");
   gold->set_money(5000);
   move_object(gold,this_object());
   crown=clone_object("players/ladyfinger/obj/crown");
   move_object(crown,this_object());
   set_heart_beat(1);
}
heart_beat(){
   int a;
   object spirit,room;
   ::heart_beat();
   room = environment(this_object());
   attacker=this_object()->query_attack();
   if(attacker){
      attacker_name=attacker->query_real_name();
      if(present(attacker_name,environment(this_object()))){
         a = random(6);
         if (a < 3){
            attacker->hit_player(random(25));
            if (1 == random(2)){
               tell_room(room,"A fireball springs from Felzar's fingertips.\n");
             }
            else{
               tell_room(room,"Tiny icicles shoot from Felzar's hand.\n");
             }
            tell_room(room,"\n");
         }
         
         if (a > 3){
            attacker->hit_player(random(30)+10);
            if (1 == random(2)){
               tell_room(room,"Felzar casts a mighty lightning bolt!\n");
             }
            else{
               tell_room(room,"A prismatic spray is loosed by Felzar!\n");
             }
            tell_room(room,"\n");
         }
         
         if (a == 3){
            attacker->hit_player(random(40)+20);
            tell_room(room,"Felzar launches an attack of ungodly fury and fire!\n");
            tell_room(room,"\n");
         }
         if (1 == random(5)){
            if (!present("spirit")){
               tell_room(room,"Felzar raises her arms chanting, 'Y-som-ni-bus!'\n");
               tell_room(room,"A powerful evil spirit arives to attack!\n");
               spirit=clone_object("/players/ladyfinger/monster/spirit");
               move_object(spirit,environment(this_object()));
               spirit->attack_object(attacker);
             }
         }
      }
   }
}
pick(arg){
   if(!arg){
      write("Don't even think about it.\n\n");
      return 1;
   }
   if(arg){
      write("Don't even think about it.\n\n");
      return 1;
   }
}
monster_died(){
   object ob,room;
   string roomy;
   room=environment(this_object());
   tell_room(room,"\nFelzar's imminent death causes a collapse in space and time!\n");
   tell_room(room,"You feel yourself being pulled elsewhere!\n");
   ob = first_inventory(environment(this_object()));
   while(ob) {
      object cur;
      cur = ob;
      ob = next_inventory(ob);
      move_object(cur,"/players/ladyfinger/room/tower6/finale");
      move_object(cur,"/players/ladyfinger/room/tower6/finale");
   }
   return 0;
   
}
