/*  Allows players to blast objects for some guild power */
/*         --- by Cosmo on 2/21/97 ---                   */

#define ROOM_OB present(str,environment(this_player()))
#define INV_OB present(str,this_player())

ranger_blast(str){
   object ob;
   int val;
   if(!str){
      write("What do you want to blast?\n");
      return 1;
   }
   if(!ROOM_OB && !INV_OB){
      write("That is not present to be blasted.\n");
      return 1;
   }
   if(this_player()->query_level() > 19 && this_player()->is_player()){
      write("Stop trying to help the players.\n");
      return 1;
   }
   if (INV_OB){
      if (INV_OB->drop() > 0){
         write("You can't blast that!\n");
         return 1;
       }
      ob = INV_OB;
      say(CAPNAME+" drops the "+ob+" on the ground and takes aim.");
      write("You set the "+ob+" on the ground.");
   }
   else{
      if(!ROOM_OB->get() || !living(ROOM_OB)){
         write("You can't blast that!\n");
         return 1;
      }
      ob = ROOM_OB;
   }
   val = ob->query_value();
   if(val > 2000){
      val = 2000;
   }
   val = ((val)/10);
   val = random(val);
   if(val < 5){
      val = 5;
   }
   add_power_points(val);
   say(CAPNAME+" draws "+this_player()->query_possessive()+
      " blaster, pulls the trigger, and disintegrates\nthe "+ob+" with a"+
      " single pulse of "+COMM->COLOR+" light.");
   write("You pull out your blaster and with one swift motion, you blow the\n"+
      ob+" into smithereens.\n");
   write("You have donated "+val+" Power Points to the Guild.\n");
   destruct(ob);
   return 1;
}

