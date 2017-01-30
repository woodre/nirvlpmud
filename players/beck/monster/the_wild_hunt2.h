/*  The file that moves the wild hunt along */

string *hunt_member;
string *hunt_path;
int npc;
int hb;
int count;
int test;
string hunted;
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
   if(hb == 10){
      add_hunters();
      move_hunt(hunt_path[count]);
      hb = 0;
   }
   if(present(q_hunted(), environment(this_object()))){
         get_hunted();
   }
   else { 
     if(hb > 10){
        find_hunted();
     }
   }
   hb += 1;
   count += 1;
}

add_hunters(){
   object ob;
   for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
      if(living(ob)){
         if(random(100) < 30){
            /* make them part of the hunt */
            add_hunter(ob);
         }
       }
   }
   return 1;
}

move_hunt(str){
   int i;
   if(present("pack", environment(this_object()))){
      command(str, present("pack", environment(this_object())));
   }
   command(str,this_object());
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
