/*  The Master of the Wild Hunt.....
*   BEWARE!
*/
inherit "/obj/monster.c";
string *hunt_member;
string *hunt_path;
int npc;
int hb;
int count;
int test;
string hunted;
reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("Master of the Hunt");
   set_alias("master");
   set_alt_name("hunter");
   set_race("energy");
   set_short("The Master Of The Hunt");
   set_long(""+
      "");
   set_level(25);
   set_wc(35);
   set_ac(20);
   set_hp(2000);
   set_can_kill(1);
   set_heart_beat(1);
   set_hbflag("hbstayon");
   npc = 0;
   count = 0;
   test = 0;
   hb = 0;
   kill_ob = 0;
   hunt_member = ({ });
   call_out("do_move",10);
}
query_player_shell(){return 1;}
/*  The file that moves the wild hunt along */

q_hunted(){
   return kill_ob;
}
s_hunted(arg){
   kill_ob = arg;
   return 1;
}
heart_beat(){
   int l;
   int n;
   int p; 
   ::heart_beat();
   p = 0;
   hunt_path = ({"north","north","east","north","north","northwest","north","east","northeast","northeast","northeast","east","east","east","east","east","east","east","east","north","north","north","north","east","east","north","east","east","north","north","east","east","east","east","east","east","east","east","east","east","east","east","east","east","east","end",});
   if(hunt_path[count] == "end"){
      for(l=0; l<sizeof(hunt_member); l++){
         p += 1;
      }
      if(p < 2){
         tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n");
         destruct(this_object());
         return 1;
      }
      n = random(p);
      s_hunted(hunt_member[n]);
      if(!present(q_hunted(), environment(this_object()))){
         tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
            "The evil that summoned him has left the lands of Nirvana.\n");
         destruct(this_object());
         return;     
      }
   }
   if(this_object()->query_attack())
      s_hunted(this_object()->query_attack());
   if(present("pack",environment(this_object()))){
      if(present("pack",environment(this_object()))->query_attack())
         s_hunted(present("pack",environment(this_object()))->query_attack());
   }
   if(present(q_hunted(), environment(this_object()))){
      get_hunted();
   }
   if(!present(q_hunted(), environment(this_object()))){
      if(hb > 10){
         find_hunted();
      }
   }
}

add_hunters(){
   object ob;
   for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
      if(living(ob)){
         if(random(100) < 30){
            /* make them part of the hunt */
            hundd_hunter(ob);
         }
       }
   }
   return 1;
}
do_move(){
   if(hb < 10){
      add_hunters();
      move_hunt(hunt_path[count]);
      count += 1;
      hb = 0;
      call_out("do_move",10);
   }
}

move_hunt(str){
   int i;
   if(present("pack", environment(this_object()))){
      command(str, present("pack", environment(this_object())));
   }
   command(str);
   for (i=0; i<sizeof(hunt_member); i++) {
      move_object(hunt_member[i], environment(this_object()));
      command("look", hunt_member[i]);
   }
}

get_hunted(){
   object killer;
   int j;
   object dead;
   if(!present(q_hunted(), environment(this_object()))){
      return;
   }
   if(present(q_hunted(), environment(this_object()))){
      hb = 15;
      dead = present(q_hunted(), environment(this_object()));
      if(!dead->is_player()){ npc = 1;}
   }
   for( j=0; j<sizeof(hunt_member); j++){
      killer = hunt_member[j];
      if(killer != dead){
         killer->attack_object(dead);
       }
   }
   if(present("pack", environment(this_object()))){
      present("pack", environment(this_object()))->attack_object(dead);
      dead->attack_object(present("pack", environment(this_object())));
   }
   if(!present("pack", environment(this_object()))){
      this_object()->attack_object(dead);
      dead->attack_object(this_object());
   }
}

find_hunted(){
   int k;
   if(npc == 1){
      if(present(q_hunted(),environment(this_object()))){
         add_hunters();
         get_hunted();
         return 1;
      }
      tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
         "The evil that summoned him has left the lands of Nirvana.\n");
      destruct(this_object());
      return 1;
   }
   if(q_hunted()){
      if((q_hunted())->query_ghost()){
         tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
            "The evil that summoned him has been destroyed.\n");
         destruct(this_object());
         return 1;
      }
      add_hunters();
      if(!present(q_hunted(), environment(this_object()))){
         if(present("pack", environment(this_object()))){
            move_object(present("pack", environment(this_object())), environment((q_hunted())));
         }
         for(k=0; k<sizeof(hunt_member); k++){
            if(present(hunt_member[k], environment(this_object()))){
               move_object(hunt_member[k], environment((q_hunted())));
             }
         }
         move_object(this_object(), environment((q_hunted())));
      }
      get_hunted();
      return 1;
   }
   tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
      "The evil that summoned him has left the lands of Nirvana.\n");
   destruct(this_object());
   return 1;
}

add_hunter(arg){
   int puke;
   object hoth;
   object sorry;
   object tpack;
   if(present(q_hunted(), environment(this_object()))){
      sorry = present(q_hunted(), environment(this_object()));
   }
   if(present("pack", environment(this_object()))){
      tpack = present("pack", environment(this_object()));
   }
   if(present("hoth", environment(this_object()))){
      hoth = present("hoth", environment(this_object()));
   }
   if(arg == hoth){
      return 1;
   }
   if(arg == this_object()){
      return 1;
   }
   if(arg == sorry){
      return 1;
   }
   if(arg == tpack){
      return 1;
   }
   if(sizeof(hunt_member) < 1){
      hunt_member = ({ arg });
      return 1;
   }
   for(puke=0; puke<sizeof(hunt_member); puke++)
   {
      if(hunt_member[puke] == arg)
         {
         puke=sizeof(hunt_member);
         return 1;
       }
      if(!hunt_member[puke])
         {
         hunt_member += ({ arg });
         puke=sizeof(hunt_member);
         return 1;
       }
   }
   hunt_member += ({ arg });
   return 1;
}
