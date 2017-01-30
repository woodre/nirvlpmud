inherit "room/room";
int i;
init() {
   add_action("west","west");
   add_action("give1","give");
     add_action("north","north");
     add_action("south","south");
}
reset(arg) {
  monster();
  if(arg) return;
  i = 0;
  /* above i = 0 is needed to make sure the i is set - Mythos <6-3-96> */
  short_desc="TV studio for the Rush Limbaugh show";
long_desc="This is the set for the greatest TV show of all time....\n" +
            "The Rush Limbaugh show. Being here makes you feel really\n" +
            "secure. To the north is a side booth and to the south is \n" +
            "the area for guests to the show.\n" +
            "The studio exit is to the west.\n";

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
    while (i<1) {
      liberal = clone_object("players/haji/rush/char/rush");
      move_object(liberal, this_object());
     i++;
       }
    i = 0;
   }
}
west() {
      call_other(this_player(),"move_player","leaves west to enlightenment#players/haji/rush/ny/eib/audi");
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
give1(str) {
      string who,what,why;
      object ob1,ob2,ob3;
      int w,x,y,z;
       if(sscanf(str, "%s to %s", who, what)!=2) {
          write("You must give something to someone.\n");
          return 1;
          }
         sscanf(str, "%s to %s",who, what);
             if(what!="rush") {
                call_other(this_player(),"give",str);
                 return 1;
             }
             ob1=(present(who,this_player()));
               if(!ob1) {
                 write("You do not have that to give.\n");
                 return 1;
                 }
                ob2=find_living(what);
                 if(!ob2) {
                    write("That is not here right now.\n");
                    return 1;
                   }
                   if(what="rush") {
                            call_other(this_player(),"set_quest","rush");
                             destruct(ob1);
                             write("Rush says: Congradulations!!!  You have now completed the ultimate quest and are now more completely enlightned\n");
                           return 1;
                       write("Bong!\n");
                       return 1;
                     }
}
