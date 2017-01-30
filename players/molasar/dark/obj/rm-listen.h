
/*
 * Let the player 'listen' in an exit direction.
 * If there is a living object in the room they will hear something
 */

int no_listen;

set_no_listen(l) { no_listen = l; }
query_no_listen() { return no_listen; }

listen(direction) {
   int i, monster;
   object invob;
   
   if(member_array(direction, alias_cmd) != -1) {
     for(i=0; i < sizeof(alias_cmd); i++) {
        if(direction == alias_cmd[i])
          break;
     }
     direction = real_cmd[i];
   }
   if(member_array(direction, dest_cmd) == -1) {
     write("You can't listen in that direction.\n");
     return 1;
   }
   for(i=0; i < sizeof(dest_cmd); i++) {
      if(direction == dest_cmd[i])
        break;
   }
   if(dest_dir[i]->query_no_listen()) {
     write("You are unable to listen in that direction.\n");
     return 1;
   }
   monster = 0;
   invob = first_inventory(dest_dir[i]);
   while(invob) {
     if(living(invob))
       monster += 1;
     invob = next_inventory(invob);
   }
   if(monster > 0 && monster <= 2)
     write("You hear some faint noises coming from the "+dest_cmd[i]+".\n");
   else
     if(monster > 2 && monster <= 5)  
       write("You hear quite a bit of noise coming from the "+
                                                    dest_cmd[i]+".\n");
   else
     if(monster > 5)  
       write("There is a large ruckus coming from the "+dest_cmd[i]+".\n");
   else
     write("Your hear nothing from the "+dest_cmd[i]+".\n");
   return 1;
}


