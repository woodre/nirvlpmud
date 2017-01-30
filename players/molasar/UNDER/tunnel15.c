
int mech1, mech2, mech3, mech4;

reset(arg) {
     if(!arg)
       set_light(0);
       mech1 = 0;
       mech2 = 0;
       mech3 = 0;
       mech4 = 0;
}

id(str) { return str == "block 1" || str == "block 2" || str == "block 3" ||
          str == "block 4" || str == "block" || str == "blocks"; }

query_mech1() { return mech1; }

query_mech2() { return mech2; }

query_mech3() { return mech3; }

query_mech4() { return mech4; }

init() {
     add_action("northeast","northeast");
     add_action("move_block","move");
}

northeast() {
     call_other(this_player(),"move_player",
                    "northeast#players/molasar/UNDER/tunnel14");
     return 1;
}

move_block(str) {
      string me;
      me = this_player()->query_name();

     if(!str) {
       write("Move what?\n");
       return 1;
     }
     if(str == "block 1") {
       write("You move the first block.\n");
       say(capitalize(me)+" moves the first block.\n");
       if(call_other("players/molasar/UNDER/tunnel15","query_mech1") == 0) {
         mech1 = 1;
         return 1;
       } else
       mech1 = 0;
       return 1;
     }
     if(str == "block 2") {
       write("You move the second block.\n");
       say(capitalize(me)+" moves the second block.\n");
       if(call_other("players/molasar/UNDER/tunnel15","query_mech2") == 0) {
         mech2 = 1;
         return 1;
       } else
       mech2 = 0;
       return 1;
     }
     if(str == "block 3") {
       write("You move the third block.\n");
       say(capitalize(me)+" moves the third block.\n");
       if(call_other("players/molasar/UNDER/tunnel15","query_mech3") == 0) {
         mech3 = 1;
         return 1;
       } else
       mech3 = 0;
       return 1;
     }
     if(str == "block 4") {
       write("You move the fourth block.\n");
       say(capitalize(me)+" moves the fourth block.\n");
       if(call_other("players/molasar/UNDER/tunnel15","query_mech4") == 0) {
         mech4 = 1;
         return 1;
       } else
       mech4 = 0;
       return 1;
     }
     if(str == "block") {
       write("Move which block?\n");
       return 1;
     }
}

long(str) {
     if(str == "block 1") {
       if(call_other("players/molasar/UNDER/tunnel15","query_mech1") == 0) {
         write("The block is in its down position.\n");
         return 1;
       } else
       write("The block is in the up position.\n");
       return 1;
     }
     if(str == "block 2") {
       if(call_other("players/molasar/UNDER/tunnel15","query_mech2") == 0) {
         write("The block is in its down position.\n");
         return 1;
       } else
       write("The block is in its up position.\n");
       return 1;
     }
     if(str == "block 3") {
       if(call_other("players/molasar/UNDER/tunnel15","query_mech3") == 0) {
         write("The block is in its down position.\n");
         return 1;
       } else
       write("The block is in its up position.\n");
       return 1;
     }
     if(str == "block 4") {
       if(call_other("players/molasar/UNDER/tunnel15","query_mech4") == 0) {
         write("The block is in its down position.\n");
         return 1;
       } else
       write("The block is in its up position.\n");
       return 1;
     }
     if(str == "block" || str == "blocks") {
       write("Look at whick block?\n");
       return 1;
     }
     write("You are in a small room barely 6 foot in length and width.\n");
     write("There is a slight chill in the room due to a draft coming\n");
     write("through a crack to the north.  Along the southern wall of\n");
     write("room you can see four small blocks set into some sort of tracks.\n");
     write("   There is one obvious exit:  northeast\n");
}

short() { return "A small room"; }

