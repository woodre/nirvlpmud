lead_battle(){
   object attack;
   if(!this_player()->query_attack()){
      write("You are not attacking anyone.\n");
      return 1;
   }
   if(PowerPoints < 20){
      write("There is not enough power in the guild to aid you.\n");
      return 1;
   }
   attack = this_player()->query_attack();
   this_player()->attack_object(attack);
   attack->attack_object(this_player());
   tell_room(environment(this_player()),capitalize(this_player()->query_real_name())+
      " finds the courage to fight "+attack->query_name()+" harder.\n");
   APowerPoints(-20);
   COMM->ASkillExp(10);
   COMM->ACombatExp(10);
   return 1;
}
