id(str) {
     if(str=="players/haji/harem/blow.c"||str=="blow") {return 1;}
  return 0;
  }
init() {
    object room;
     string name;
      room=find_object("players/haji/harem/main1");
      name=call_other(this_player(),"query_name",0);
    write("You look as you arrive in the room and see...\n");
    write("A bed a chair and a desk.\n");
    write("You then go sit on the bed.\n");
    write("Soon a young vivacious woman walks in wearing nothing.\n");
    write("She kneels on the floor before you....\n");
    write("You stand up in front of her.....\n");
    write("She then slowly pulls off your pants...\n");
    write("She applies her mouth to your dick...\n");
    write("and gives you the best blowjob you have ever had!!\n");
    write("You then get dressed and are shown out the door.\n");
    call_other(this_player(),"heal_self",15);
    tell_room(room,name);
    tell_room(room," arrives looking VERY relieved.\n");
    move_object(this_player(),room);
    return 1;
   }
