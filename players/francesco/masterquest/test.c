
machining() {
 int a,b,c;
  object *inv;
  object room;
   room= "players/francesco/masterquest/machining.c";
    inv = all_inventory(room);
     if((c = sizeof(inv) > 0))
      {
      for(b = 0; b < c; b++)
       {
        if(inv[b]->is_player() && inv[b]->query_level()<20){
         write("The machining lab is already in use.\n");
         return 1;}
       }
      }
   this_player()->move_player("to the machining lab#players/francesco/masterquest/machining.c");
   return 1;
}

