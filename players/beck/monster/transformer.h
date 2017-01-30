/* The file for all transformers */

reset(){
   int n;
   if(random(100) < 10){
      set_robot();
   }
   set_form();
}
heart_beat(){
   if(this_object()->query_attack()){
      if(!query_robot()){
         transform();
         set_robot();
      }
   }
   if(query_robot()){
      transform();
      set_form();
   }
   ::heart_beat();
}
