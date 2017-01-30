inherit "room/room";
init() {
   add_action("east","east");
   add_action("buy","buy");
   add_action("buy","order");
}
reset(arg) {
    if(arg) return;
    short_desc="Soup kitchen in New York";
    long_desc="This is a federally funded soup kitchen.\n" +
              "You can buy government surplus food here.\n" +
              "However, we only accept welfare checks, since\n" +
              "the government will not take cash for payments\n" +
              "to make everyone reliant upon them. To return to " +
              "city go east .\n" +
              "You see a sign on the wall.\n";
    set_light(1);
    items=({ "sign",
             "This is the soup kitchen where you can order food.\n" +
             "To order type in buy or order followed by the appropriate\n" +
             "number.\n" +
             "        1.     Government surplus cheese     20 dollars\n" +
             "        2.     Government surplus honey      50 dollars\n" +
             "        3.     Government surplus meat       90 dollars\n" +
             "        4.     Government surplus soda       10 dollars\n" +
             "NOTE: we do NOT take cash you must pay by welfare check.\n",
           });
}
east() {
     call_other(this_player(),"move_player","leaves east#players/haji/rush/ny/estreet1");
     return 1;
    }
buy(str) {
     object che,che1;
     int x,y,z;
        che=(present("check",this_player()));
            if(che==0) {
              write("Sorry we only take welfare checks here and you do not have any.\n");
              return 1;
            }
            if(str=="1") {
              x=call_other(che,"query_val",0);
                if(x<20) {
                  write("You do not have enough checks to pay for this.\n");
                  return 1;
                }
                call_other(che,"set_val",x-20);
                call_other(this_player(),"heal_self",4);
                write("You eat some Government cheese.\n");
                return 1;
            }
            if(str=="2") {
              x=call_other(che,"query_val",0);
                if(x<50) {
                  write("You do not have enough checks for that.\n");
                  return 1;
                }
              call_other(che,"set_val",x-50);
              call_other(this_player(),"heal_self",8);
              write("You have some Government honey.\n");
              return 1;
            }
            if(str=="3") {
              x=call_other(che,"query_val",0);
                if(x<90) {
                  write("You do not have enough checks for that.\n");
                  return 1;
                }
              call_other(che,"set_val",x-90);
              call_other(this_player(),"heal_self",12);
              write("You eat some Government meat.\n");
              return 1;
            }
            if(str=="4") {
              x=call_other(che,"query_val",0);
                if(x<10) {
                  write("You do not have enough checks for that.\n");
                  return 1;
                }
              call_other(che,"set_val",x-10);
              call_other(this_player(),"heal_self",1);
              write("You drink some Government soda.\n");
              return 1;
            }
            else {
              write("Invalid entry.\n");
              return 1;
            }
  }
