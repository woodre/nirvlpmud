inherit "obj/treasure";
reset(arg){
   if(!arg){
      set_short("A dispenser");
        set_long("This is Rumplemintz's toy dispenser.  To see what it has to offer you,\n"+
                "type list.  If you would like something added, mail or tell Rumplemintz.\n");
      set_alias("dispenser");
   }
}
init(){
   add_action("hit","hit");
   add_action("list","list");
   ::init();
}
hit(str){
   object glove,koosh,can,bark,booger,sock,dartbag;
   object heal;
   if(str=="1"){
      glove=clone_object("/players/rumplemintz/obj/glove");
      if(this_player()->query_money() < 300){
         write("You don't have enough money.\n");
         destruct(glove);
         return 1;
      }
      move_object(glove,this_player());
      this_player()->recalc_carry();
      this_player()->add_money(-300);
      write("You buy a glove.\n");
      return 1;
   }
   if(str=="2"){
      koosh=clone_object("/players/rumplemintz/obj/koosh");
      if(this_player()->query_money() < 300){
         write("You don't have enough money.\n");
         destruct(koosh);
         return 1;
      }
      move_object(koosh,this_player());
      this_player()->recalc_carry();
      this_player()->add_money(-300);
      write("You buy at koosh ball.\n");
      return 1;
   }
   if(str=="3"){
     can=clone_object("/players/rumplemintz/obj/scotch");
     if(this_player()->query_money() < 300){
       write("You don't have enough money.\n");
       destruct(can);
       return 1;
       }
       move_object(can, this_player());
       this_player()->recalc_carry();
       this_player()->add_money(-300);
       write("You buy a can of Scotch Guard.\n");
       return 1;
   }
   if(str=="4"){
     bark=clone_object("/players/rumplemintz/obj/bark");
     if(this_player()->query_money() < 500){
       write("You don't have enough money.\n");
       destruct(bark);
       return 1;
     }
     move_object(bark,this_player());
     this_player()->recalc_carry();
     this_player()->add_money(-500);
     write("You buy a slab of bark.\n");
     return 1;
   }
        if(str=="5"){
        booger=clone_object("/players/rumplemintz/obj/booger");
        if(this_player()->query_money() < 150){
        write("I can't believe you can't afford a booger!\n");
        destruct(booger);
        return 1;
        }
        move_object(booger,this_player());
        this_player()->recalc_carry();
        this_player()->add_money(-150);
        write("You buy some flem.\n");
        return 1;
        }
        if(str=="6"){
        sock=clone_object("/players/rumplemintz/obj/hsock");
        if(this_player()->query_money() < 300){
        write("Homey don't play Dat!  Get some money!\n");
        destruct(sock);
        return 1;
        }
        move_object(sock,this_player());
        this_player()->recalc_carry();
        this_player()->add_money(-300);
        write("Homey hands you a sock.\n");
        return 1;
        }
        if(str=="7"){
        dartbag=clone_object("/players/rumplemintz/obj/dartbag");
        if(this_player()->query_money() < 650){
        write("How bad do you really want these darts...\nGet some money!\n");
        destruct(dartbag);
        return 1;
        }
        move_object(dartbag,this_player());
        this_player()->recalc_carry();
        this_player()->add_money(-650);
        write("Rumplemintz himself hands you a bag of darts.\n");
        return 1;
        }
        if(str=="8"){
        heal=clone_object("/players/rumplemintz/obj/heal");
        move_object(heal,this_player());
        this_player()->recalc_carry();
        write("Healified.\n");
        return 1;
        }
   write("Usage: hit <number>  \n");
   return 1;
}
list(){
   write("What's in this dispenser.\n");
   write("`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'\n");
   write("1. A Big Glove............300 coins\n");
   write("2. A Koosh Ball...........300 coins\n");
   write("3. Can of Scotch Guard....300 coins\n");
   write("4. A Slab of Bark.........500 coins\n");
   write("5. A booger...............150 coins\n");
   write("6. A Homey Sock...........350 coins\n");
   write("7. A dartbag..............650 coins\n");
   write("`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'`'\n");
   write("'hit #' to buy an item.\n");
   return 1;
}
get(){return 0;}
