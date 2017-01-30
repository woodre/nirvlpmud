/*  Allows players to donate objects for some guild power */

donate_object(str){
   object ob;
   int val;
   if(!str){
      write("What do you want to donate?\n");
      return 1;
   }
   if(!present(str, this_player())){
      write("You do not have one of that to donate.\n");
      return 1;
   }
   if(this_player()->query_level() > 19 && this_player()->is_player()){
      write("Stop trying to help the players.\n");
      return 1;
   }
   ob = present(str, this_player());
   val = ob->query_value();
   if(ob->drop() > 0){
      write("You can't donate that!\n");
      return 1;
   }
   if(val > 2000){
      val = 2000;
   }
   val = ((val)/10);
   val = random(val);
   if(val < 5){
      val = 5;
   }
   add_power_points(val);
   write("You donate "+val+" Power Points to the Guild.\n");
   destruct(ob);
   return 1;
}
