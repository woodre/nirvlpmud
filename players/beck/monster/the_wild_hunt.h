/*  The file that moves the wild hunt along */

string *hunt_member;
string *hunt_path;
int npc;
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
start_the_hunt(){
   int p;
   int l;
   int n;
object pack;
object uhhh;
   object uhoh;
   object hunted_name;
   p = 0;
   hunt_path = ({"north","north","east","north","north","northwest","north","east","northeast","northeast","northeast","east","east","east","east","east","east","east","east","north","north","north","north","east","east","north","east","east","north","north","east","east","east","east","east","east","east","east","east","east","east","east","east","east","east","end",});
   if(present("pack", environment(this_object()))){
      pack = present("pack",environment(this_object()));
      if(pack->query_attack()){
         uhhh = pack->query_attack();
         s_hunted(uhhh->query_real_name());
      }
   }
   if(this_object()->query_attack()){
      uhoh = this_object()->query_attack();
      s_hunted(uhoh->query_real_name());
   }
   add_hunters();
   if(present(q_hunted(), environment(this_object()))){
      get_hunted();
      call_out("find_hunted",10);
      return 1;
   }
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
      hunted_name = hunt_member[n];
      s_hunted(hunted_name->query_real_name());
      if(!present(q_hunted(), environment(this_object()))){
         tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
            "The evil that summoned him has left the lands of Nirvana.\n");
         destruct(this_object());
         return 1;
      }
      get_hunted();
      call_out("find_hunted",10);
      return 1;
   }
   move_hunt(hunt_path[count]);
   if(present(q_hunted(), environment(this_object()))){
      get_hunted();
      call_out("find_hunted",10);
      return 1;
   }
   count += 1;
   call_out("start_the_hunt",10);
   return 1;
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
   command(str);
   for (i=0; i<sizeof(hunt_member); i++) {
      move_object(hunt_member[i], environment(this_object()));
      command("look", hunt_member[i]);
   }
   return 1;
}
get_hunted(){
   object killer;
   int j;
   object dead;
if(!present(q_hunted(), environment(this_object()))){
return 1;
}
   if(present(q_hunted(), environment(this_object()))){
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
   return 1;
}
find_hunted(){
   int k;
   if(npc == 1){
      if(present(q_hunted(),environment(this_object()))){
         add_hunters();
         get_hunted();
         call_out("find_hunted",10);
         return 1;
      }
      tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
         "The evil that summoned him has left the lands of Nirvana.\n");
      destruct(this_object());
      return 1;
   }
   if(find_living(q_hunted())){
      if(find_player(q_hunted())->query_ghost()){
         tell_room(environment(this_object()),"The Master of the Hunt disappears into the air.\n"+
            "The evil that summoned him has been destroyed.\n");
         destruct(this_object());
         return 1;
      }
      add_hunters();
      if(!present(q_hunted(), environment(this_object()))){
         if(present("pack", environment(this_object()))){
            move_object(present("pack", environment(this_object())), environment(find_living(q_hunted())));
         }
         for(k=0; k<sizeof(hunt_member); k++){
            if(present(hunt_member[k], environment(this_object()))){
               move_object(hunt_member[k], environment(find_living(q_hunted())));
             }
         }
         move_object(this_object(), environment(find_living(q_hunted())));
      }
      get_hunted();
      call_out("find_hunted",10);
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
