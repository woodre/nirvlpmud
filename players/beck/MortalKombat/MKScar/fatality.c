main(){
   object att;
   if(!this_player()->query_attack())
      return;
   att = this_player()->query_attack();
   if(att->query_hp() > 40)
      return;
   if((att->query_hp()/att->query_mhp())*100 >0)
      return;
   if((previous_object()->QMKScore()/10) < random(100)){
      write("You can not get your opponent into position and they take advantage.\n");
      this_player()->hit_player(5,att);
      return 1;
   }
   previous_object()->SFatalityTemp();
   write("You set your opponent up for a fatality!\n");
   return 1;
}   

      