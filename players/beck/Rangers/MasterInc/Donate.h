

/*  Allows players to blast objects for some guild power */
/*         --- by Cosmo on 2/21/97 ---                   */

/* addition 2003.03.21 -Forbin added color based on ranger ansi */

#define ROOM_OB present(str,environment(this_player()))
#define INV_OB present(str,this_player())

ranger_blast(str,string type){
   object ob;
   int val;
   int val2;
   if(!str){
      write("What do you want to blast?\n");
      return 1;
   }
   if(!ROOM_OB && !INV_OB){
      write("That is not present to be blasted.\n");
      return 1;
   }
   if(str == "scroll"){
      write("Sorry no more donating miniguild scrolls.\n");
      return 1;
   }
   if(QPowerPoints(type) > 2999){
      write("Guild Power is Full already.\n");
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
      say(TPNAME+" drops the "+str+" on the ground and takes aim.");
      say("\n");
      write("You set the "+str+" on the ground.");
      write("\n");
   }
   else{
      if(!ROOM_OB->get() || living(ROOM_OB)){
         write("You can't blast that!\n");
         return 1;
      }
      if(ROOM_OB->query_weight() > 100){
         write("You can't blast that!\n");
         return 1;
      }
      ob = ROOM_OB;
   }
   val = ob->query_value();
   if(val > 2000){
      val = 2000;
   }
   val2 = ((val)/20);
   val2 += random((val)/20);
   if(val2 < 5){
      val2 = 5;
   }
   if(val == 0){ val2 = 0; }
   if(str == "corpse"){ val2 = 15; }
   if(val2 + QPowerPoints(type) > 2999)
      val2 = 3000 - QPowerPoints(type);
   APowerPoints(val2,type);
   COMM->ASkillExp(3);
   COMM->ARangerPoints(val2);
   say(TPNAME+" draws "+this_player()->query_possessive()+
      " blaster, pulls the trigger, and disintegrates\nthe "+str+" with a"+
      " single pulse of "+COMM->QRangerAnsi()+COMM->COLOR+" light"+OFF+".");
   say("\n");
   write("You pull out your blaster and with one swift motion, you blow the\n"+
      str+" into smithereens.\n");
   write("You have donated "+val2+" Power Points to the Guild.\n");
   destruct(ob);
   return 1;
}
