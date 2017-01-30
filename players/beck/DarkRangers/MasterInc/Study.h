study_enemy(str){
   object enemy;
   if(!present(str, environment(this_player()))){
      write(capitalize(str)+" is not here.\n");
      return 1;
   }
   enemy = present(str, environment(this_player()));
   if(!living(enemy)){ write(capitalize(str) +" is not a living being.\n"); return 1;}
write(enemy->short()+"\n");
   if(enemy->query_alignment() > 0){ write(capitalize(str)+ " appears to be good.\n");
      return 1;
   }
   if(enemy->query_alignment() < 0){ 
      write(capitalize(str) +" appears to be bad.\n");
      return 1;
   }
   write(capitalize(str) +" seems to be indifferent to good or evil.\n");
   return 1;
}
