
goperson(str) {
   if(!str) {
      move_object(this_player(),environment("/players/llew/tool/randperson"->query_person()));
      return 1;
   }
   else {
      if(!find_player(str)) {
         write(capitalize(str)+" is not online.\n");
         return 1;
      }
      if(!environment(find_player(str))) {
         write(capitalize(str)+" has no environment.\n");
         return 1;
      }
      move_object(this_player(),environment(find_player(str)));
      return 1;
   }
}
