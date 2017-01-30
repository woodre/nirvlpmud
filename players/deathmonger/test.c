
id(str){ return str == "test"; }
init(){
   object ob;
   ob = first_inventory(this_player());
    if(!ob) write("Sorry.\n");
   while(ob = next_inventory(this_player())){
         if(ob->id("soul")){
            shadow(ob, 1);
            write("Bingle.\n");
             write("Bingle.\n");
         }
   }
   add_action("frog", "frog");
}

frog(){
    object ob;
    ob = present("soul", this_player());
   shadow(ob, 1);
   write("bingle.\n");
   return 1;
}
