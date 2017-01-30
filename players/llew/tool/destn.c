destn(str) {
   string who;
   int num;
   object ob;
   if(this_player()->query_level() < 21) destruct(this_object());
   if(sscanf(str, "%s %d", who, num) != 2) return 0;
   if(!find_player(who)) {
      write("player not found.\n");
      return 1;
   }
   ob=all_inventory(find_player(who))[num-1];
   if(!ob) {
      write("Object not present.\n");
      return 1;
   }
   destruct(ob);
   write("Object #"+num+" dested from "+capitalize(who)+".\n");
   return 1;
}
