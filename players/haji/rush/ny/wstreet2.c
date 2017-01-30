inherit "room/room";
int i;
init() {
   add_action("west","west");
   add_action("northwest","northwest");
     add_action("north","north");
     add_action("south","south");
}
reset(arg) {
  monster();
  if(arg) return;
  short_desc="A street in New York";
long_desc="There is the putrid smell of liberals here....\n" +
          "You can barely hear yourself over the wimpering and the heaving.\n" +
          "To the south you see sanctuary as the EIB building looms over you.\n" +
          "To the west you see a bookstore, and finally, to the northwest,\n" +
          "you see the headquarters for R.U.S.H..\n";

set_light(1);

items = ({"bookstore",
"This is the bookstore that has that great book The way things ought to be.\n",
"headquarters",
"This is the headquarters for R.U.S.H.,it is the orgainization to be in.\n"
  });
}


monster() {
int count;
   object liberal;

   if(!present("liberal")) {
    while (i<6) {
      liberal = clone_object("players/haji/rush/char/lib");
      move_object(liberal, this_object());
     i++;
       }
    i = 0;
   }
}
west() {
   if(present("liberal")) {
      write("Liberal says: No! We can't allow you to go in there!\n");
      write("A liberal blocks your way.\n");
    return 1;
    }
      write("You move west into the bookstore.\n");
      call_other(this_player(),"move_player","leaves west to enlightenment#players/haji/rush/ny/bookstore");
     return 1;
   }
northwest() {
    if (present("liberal")) {
      write("Liberal says: No! we will not let you hear their viewpoint!\n");
      write("A liberal tries to block you way, however, some R.U.S.H. members\n");
      write("come out and push these liberal saps out of your way and escort you inside.\n");
      call_other(this_player(),"move_player","is escorted in R.U.S.H.#players/haji/rush/ny/RUSH");
    return 1;
   }
      write("You enter R.U.S.H. headquarters.\n");
      call_other(this_player(),"move_player","leaves into R.U.S.H.#players/haji/rush/ny/RUSH");
     return 1;
  }
north() {
   call_other(this_player(),"move_player","leaves north#players/haji/rush/ny/wstreet3");
 return 1;
  }
south() {
call_other(this_player(),"move_player","leaves south#players/haji/rush/ny/wstreet1");
   return 1;
  }
