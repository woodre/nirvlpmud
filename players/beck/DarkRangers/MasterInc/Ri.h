Ri(){
   object ob;
   write("Dark Ranger Inventory.\n");
   write("_______________________\n");
   for(ob = first_inventory(this_player()); ob; ob = next_inventory(ob)){
      if(!ob->query_auto_load() && !ob->id("soul"))
         write(ob->short()+"\n");
   }
   return 1;
}
