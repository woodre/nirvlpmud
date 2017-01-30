
/*
 * Guild Commander Room
 */

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object board;
   if(!present("board")) {
     board = clone_object("/players/sandman/paladin/cmdboard");
     move_object(board, this_object());
   }
}

id(str) { return str == "table" || str == "chair" || str == "chairs"; }

realm() { return "NT"; }

short() { return "Guild Commanders Conference Area"; }

long(str) {
   if(str == "table") {
     write("A polished and sturdy table made of an unidentifiable wood.\n");
     return 1;
   }
   if(str == "chair" || str == "chairs") {
     write("Plain wooden chairs devoid of any ornamentation. Armrests\n");
     write("and a small cushion provide comfort.\n");
     return 1;
   }
   write("You have entered the meeting room of the Guild Commanders of\n");
   write("the Paladins. The place is sparsely furnished, the only\n"); 
   write("contents being a large wooden table surrounded by high backed\n");
   write("chairs.\n");
   write("     There is one obvious exit: leave\n");
}

init() {
   if(!this_player()->query_npc()) {
     if(!present("guild_medal", this_player()) && 
                                this_player()->query_level() < 20) {
       write("Only Paladins and Wizards may access this room.\n");
       move_object(this_player(), "/players/sandman/paladin/entry");
       return 1;
     }
   }
   add_action("leave","leave");
}

leave() {
   this_player()->move_player("leaves#players/sandman/paladin/adv_guild");
   return 1;
}

