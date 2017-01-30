Look(str) {
   object ob, target,list;
    int i;
   if (!str) return 0;
   target = find_living(str);
   if (str == "me") target = this_player();
   if (str == "here") target = environment(this_player());
   if (str == "here") write (target->short()+" : ");
   if(str == "all"){
    list=users();
    for(i=0;i<sizeof(list);++i){
    target=find_player(list[i]->query_real_name());
   if(target->query_level() < 20){
   write("\n");
   write ("Inventory of ");
   write(target->query_real_name());
   write ("( "+file_name(target)+" )\n");
   write ("\n");
   ob = first_inventory(target);
   while(ob) {
      if (ob->short())
         write(ob->short()+" : ("+file_name(ob)+")\n");
      else
         write ("Invisible Object : ("+file_name(ob)+")\n");
      ob = next_inventory(ob);
   }
   }
   }
   return 1;
   }
   if(!target) target=find_object(str);
   if (!target) {
      write ("There is no such living creature.\n");
      return 1;
   }
   write ("Inventory of ");
   if (str != "here") write( target->query_short()+" : ");
   write ("( "+file_name(target)+" )\n");
   write ("\n");
   ob = first_inventory(target);
   while(ob) {
      if (ob->short())
         write(ob->short()+" : ("+file_name(ob)+")\n");
      else
         write ("Invisible Object : ("+file_name(ob)+")\n");
      ob = next_inventory(ob);
   }
   return 1;
}