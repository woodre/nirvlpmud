inherit "obj/monster.c";

reset(arg) {
    object book;
    ::reset(arg);
    if (arg)
	return;
    set_name("bookkeeper");
    set_level(19);
    set_wc(24);
    set_ac(10);
   set_no_clean(3);
    set_short("An intelligent looking bookkeeper");
     set_long("He looks as if he can enlighten you.\n");
    set_alias("bookkeeper");
     book=clone_object("players/haji/rush/obj/rbook");
     move_object(book,this_object());
    set_chat_chance(40);
     load_chat("Bookkeeper asks: Do you want to be enlightened?\n");
}
catch_tell(str) {
    string who, what,why;
    object ob;

    if(sscanf(str, "%s says: %s", who, what) !=2) {
	return;
}
    if(sscanf(str, "%s enlighten me%s",who,what)==2){
       write("ddkdkdkdk");
       write("Bookkeeper says: So, you wish to be enlightened!\n");
       write("Bookkeeper says; Well, I have in my possesion a book which will do just that!\n");
       write("Bookkeeper says: It will cost you 1000 dollars in welfare checks  since we are a welfare state.\n");
       add_action("buy","buy");
       write("Bookkeeper says: Just type in 'buy book' and you will be on your way to a better state.\n");
       return 1;
   }
  return 1;
  }
buy(str) {
    object che,che1,che2;
    string str1,str2,str3;
    int x,y,z;
    if(str=="book") {
       write("Bookkeeper says: So! You want to buy Rush's book!\n");
       che=(present("check",this_player()));
       if(che==0) {
         write("Bookkeeper says: I'm sorry but you do not have any welfare checks, and we can't\naccept money thanks to the federal government.\nCome back later.\n");
         return 1;
       }
       x=call_other(che,"query_val",0);
       if(x<1000) {
         write("Bookkeeper says: I'm sorry thanks to inflation the book cost 1000 dollars in checks which you don't have.\n");
         return 1;
       }
       if(!present("rbook",this_object())) {
          write("Bookkeeper says: I'm sorry but I have sold out of Rush's great book.\nCome back later!\n");
          return 1;
       }
       che1=(present("rbook",this_object()));
       call_other(che,"set_val",x-1000);
       move_object(che1,this_player());
       write("Bookkeeper says: Thank you for buying Rush's book, have a nice day!\n");
       return 1;
  }
     else {
      write("I'm sorry we don't have that item here.\n");
      return 1;
  }
}
