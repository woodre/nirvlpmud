object RealAttack;
status InFight;
string Fatality;

heart_beat() {
   object att;
   if(!environment(this_object())) return;
/*
   if(this_object()->query_attack()){
      att=(this_object()->query_attack());
      InFight = 1;
      if(this_object()->query_attack() == this_object()){
         stop_fight();
         call_out("BeginKombat",1);
      }
      if(att->query_ghost()){
         InFight = 0;
         stop_fight();
         ::heart_beat();
         return;
      }
   }
   if(InFight && !alt_attacker_ob){
      call_out("BeginKombat",1);
   }
*/
   ::heart_beat();
   if(this_object()->query_attack()){
      if(att->query_hp() < 50) {
         InFight = 0;
         tell_object(att, Fatality);
         if(name == "Shang Tsung"){
            "obj/user/one_chan.c"->chan_msg("Shang Tsung has defeated "+
               capitalize(att->query_real_name())+
               " and is still Champion of Mortal Kombat.\n","msg");
         }
         else{
            "obj/user/one_chan.c"->chan_msg(name+" has defeated "+
               capitalize(att->query_real_name())+
               " in Mortal Kombat.\n", "junk");
            
         }
         att->hit_player(200);  
         write_file("/players/beck/MortalKombat/DEATHS",att->query_name()+" died at the hands of "+name+" "+ctime(time())+"\n");
         return 1;
      }
   }
}

monster_died(){
   environment(this_object())->FinishEm(name);
   destruct(present("corpse",environment(this_object())));
   /*
   "obj/user/one_chan.c"->chan_msg(""+
      "A Voice says: "+RealAttack->query_name()+" Wins.\n"+
      "","junk");
   */
   if(name == "Shang Tsung"){
      "obj/user/one_chan.c"->chan_msg(capitalize(query_attack()->query_real_name())+
         " has defeated Shang Tsung and is now Champion of Mortal Kombat.\n","msg");
      move_object(clone_object("/players/dragnar/closed/scar"), query_attack());
      move_object(clone_object("/players/dragnar/items/amulet"), environment(this_object()));
      write_file("/players/beck/MortalKombat/CHAMPIONS",query_attack()->query_name()+" became champion on "+ctime(time())+"\n");
   }
   else{
      /*
      "obj/user/one_chan.c"->chan_msg(RealAttack->query_name()+" has defeated "+name+" in Mortal Kombat.\n"+
         "","junk");
      */
   }
   return 0;
}


RestartFight(){
  if(!environment(this_object())) return;
   environment(this_object())->BeginKombat();
   query_attack()->hit_player(30+random(30));
   tell_room(environment(this_object()),"Just as you think the fight has stopped...\n"+
      name+" smashed you with Full Force.\n");
}
StartFight(object RAttack){
   RealAttack = RAttack;
   attack_object(RealAttack);
   InFight = 1;
}
