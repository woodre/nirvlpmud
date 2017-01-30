inherit "room/room";
init() {
    add_action("east","east");
    add_action("convert","convert");
}
reset(arg) {
   if(arg) return;
   short_desc="Naval base Welfare office";
   long_desc="This is the welfare office for Naval base.\n" +
             "Since the federal government has made us into a\n" +
             "welfare state, we no longer can accept coins here.\n" +
             "Therefore, in order to make purchases here, you need\n" +
             "to convert your coins into welfare checks. Also, for when\n" +
             "you leave here, you may convert your checks back into coins.\n" +
             "On the wall you see a sign.\n" +
             "To return to the base go east.\n";
   set_light(1);
   items=({"sign",
       "This is where you can convert you checks into coins or vice versa.\n" +
       "To do so please type in convert and then the appropriate number.\n" +
       "         1.    Convert coins to welfare checks\n" +
       "         2.    Convert welfare checks to coins\n\n" +
       "Thank you for your time.\n",
});
}
east() {
      call_other(this_player(),"move_player","leaves east#players/haji/rush/nb/base1");
      write("You leave east.\n");
      return 1;
  }
convert(str) {
        if(str=="1") {
          convert_co();
          return 1;
          }
        if(str=="2") {
          convert_ch();
          return 1;
          }
        else {
         write("Invalid action.\n");
         return 1;
         }
    }
convert_co() {
      write("How many coins would you like to convert into welfare checks?\n");
      input_to("coins");
  }
coins(str) {
    int x;
   object check,che;
    int w,y,z;
     sscanf(str,"%d",x);
     w=x;
     if((this_player()->query_money())<x) {
         write("You do not have that many coins to convert.\n");
         return 1;
        }
     if(present("check",this_player())) {
         che=(present("check",this_player()));
         y=call_other(che,"query_val",0);
         z=x+y;
         x=z;
         destruct(che);
         }
     check=clone_object("players/haji/rush/obj/check");
     call_other(check,"set_val",x);
     move_object(check,this_player());
     call_other(this_player(),"add_money",0-w);
     write("You cash has been converted into a welfare check.\n");
     write("We apologize for the inconvenience,but the government\n");
     write("has made us into a socialist welfare state.\n");
     return 1;
  }
convert_ch() {
     object che;
     int y;
     if(!present("check",this_player())) {
         write("You do not have any checks to convert.\n");
         return 1;
        }
      che=(present("check",this_player()));
      y=call_other(che,"query_val",0);
      call_other(this_player(),"add_money",y);
      write("The welfare office gives you ");
      write(y);
      write(" coins for your check.\n");
      destruct(che);
      return 1;
}
