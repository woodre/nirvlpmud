Ri(string str){
   object ob;
   string shrt;
   if(str == "pack" && PO->QRangerPack()){
      write(RED+"Pack Inventory."+OFF+"\n");
      write("_______________________\n");
      for(ob = first_inventory(PO); ob; ob = next_inventory(ob)){
         shrt = ob->short();
         if(shrt) write(shrt+"\n");
      }
   }
   else{
      write("Power Ranger Inventory.\n");
      write("_______________________\n");
      for(ob = first_inventory(this_player()); ob; ob = next_inventory(ob)){
            /* uh.. short() check 6.6.01 by verte */
            if(ob->short() && !ob->query_auto_load()) write(ob->short() + "\n");
      }
   }
   write("_______________________\n");
   return 1;
}
