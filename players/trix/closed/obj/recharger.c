reset(arg) {
        if(arg) return;
        /* Initialization code goes here */

}

long() {
           write("A little vending machine.  Type 'items' to see what you can buy.\n");
           return 1;
        }

short() {
   return "A little vending machine";
}

id(str) {
        if( str == "machine" ) return 1;
        return 0;
}

init() {          
        add_action( "buy", "buy" );
        add_action("charge","recharge");
   add_action("info","info");
        add_action( "list", "items");
        return 1;
}

query_weight()
{   return 50;
}

list()
  { cat("/players/trix/helpdir/weaponlist");
    return 1;
  }

buy(str)
{  
   object cosa;
   string choice;
   int right;
   right=0;
   if((!str) || ((sscanf(str,"%s",choice) !=1)))
     { tell_object(this_player(),"Buy what?!?\n");
       return 1;
     }
   if (choice=="trix-71")
{

      if (call_other(this_player(), "query_money") < 45000) /* vital bug fix */
      {
        notify_fail("You don't have enough money.\n");
        return 0;
      }
     cosa=clone_object("players/trix/closed/obj/shotgun.c");
   if (!call_other(this_player(), "add_weight",
            call_other(cosa, "query_weight"))) {
      write("You can't carry that much.\n");
      return 1;
    }
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy a trix-71 automatic shotgun.\n"); 
     call_other(this_player(), "add_money", -4500);
   right=1;
   }

   if (choice=="clip")
   { 
     if(this_player()->query_money() < 750) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/closed/obj/clippy.c");
   if (!call_other(this_player(), "add_weight",
            call_other(cosa, "query_weight"))) {
      write("You can't carry that much.\n");
      return 1;
     }
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy a cartridge clip of 5 shots for your trix-71.\n"); 
     call_other(this_player(), "add_money", -750);
   right=1;
   }

   if (choice=="set")
  {
     if(this_player()->query_money() < 5000) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/closed/obj/shotgun.c");
   if (!call_other(this_player(), "add_weight",
            call_other(cosa, "query_weight"))) {
      write("You can't carry that much.\n");
      return 1;
}
     move_object(cosa,this_player());
     call_other(this_player(), "add_money", -5000);
     cosa=clone_object("players/trix/closed/obj/clippy.c");
   if (!call_other(this_player(), "add_weight",
            call_other(cosa, "query_weight"))) {
      write("You can't carry that much.\n");
      return 1;
      }
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy a cartridge a trix-71 automatic shotgun with a clip of 5 shots.\n"); 
   right=1;
 
   }

   if (choice=="scanner")
   {
     if(this_player()->query_money() < 100) { write("You don't have enough money.\n"); return 1; }
     cosa=clone_object("players/trix/closed/obj/scanner.c");
   if (!call_other(this_player(), "add_weight",
            call_other(cosa, "query_weight"))) {
      write("You can't carry that much.\n");
      return 1;
    }
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy a virtual scanner.\n"); 
     call_other(this_player(), "add_money", -100);
   right=1;
   }
/*
   if (choice=="emoter")
   {
     if(call_other(this_player(),"query_money",)<100) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/closed/obj/emoter.c");
   if (!call_other(this_player(), "add_weight",
            call_other(cosa, "query_weight"))) {
      write("You can't carry that much.\n");
      return 1;
   }
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy an emoter.\n"); 
     call_other(this_player(), "add_money", -1000);
     right=1; 
   }
*/
/*
   if (choice=="flirter")
   { object what;
     what=present("flirter",this_player());
     if(what) {
       if(call_other(what,"query_version")==4) { tell_object(this_player(),"You have already have the latest version !\n"); return 1; }
       else { destruct(what);
              cosa=clone_object("players/trix/closed/obj/flirter.c");
              move_object(cosa,this_player());
              tell_object(this_player(),"You are given the latest version of the flirter.\n");
              return 1;
            }
     }       
     if(call_other(this_player(),"query_money",)<100) { write("You don't have enough money.\n"); return 1; } 
     cosa=clone_object("players/trix/closed/obj/flirter.c");
     move_object(cosa,this_player());
     tell_object(this_player(),"You buy a flirter.\n"); 
     call_other(this_player(), "add_money", -100);
     log_file("trix.f",call_other(this_player(),"query_real_name")+"\t"+ctime(time())+"\n");
     right=1; 
   }
*/
   if (!right) tell_object(this_player(),"I'm afraid you can't buy it here.\n");
      return 1;
}


charge(arg)
 { int num;
   object gun;
   if((!arg) || ((sscanf(arg,"%d",num) !=1))) {write("Huh?!?\n"); return 1; }
   gun=present("trix-71",this_player());
   if(!gun) {write("Hey, you have no trix-71 to recharge!!!\n"); return 1; }
   call_other(gun,"recharge",num);
   return 1;
 }
   
info(arg)
 {
   if(arg=="trix-71")
    { cat("/players/trix/helpdir/guninfo");
      return 1;
    }   
 }

get() {
        return 0;
}

drop() {
        return 1;
}
