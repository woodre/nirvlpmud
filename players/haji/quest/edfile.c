#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
  extra_init() {
   object ob;
   string str,str1,str2;
     str="grail key";
     str1="gar";
     str2="arg";
    ob=this_player();
   if(!present(str,ob)) {
     write("You dont have a grail key go back and get one to continue.\n");
     move_object(ob,"players/haji/e1.c");
    return 1;
  }
    if(!present(str1,ob)) {
     write("You don't have a branch go back and get one to continue.\n");
      move_object(ob,"players/haji/e1.c");
   return 1;
 }
    if(!present(str2,ob)) {
     write("You don't have a diary go back and get one to continue.\n");
      move_object(ob,"players/haji/e1.c");
    return 1;
  }
    if(present(str,ob)) {
   write("Congratulations you have solved your quest!!!!!\n");
   call_other(ob,"set_quest","grail");
       destruct(present(str,ob));
       destruct(present(str2,ob));
       destruct(present(str1,ob));
   
  return 1;
  }

 return 1;
 }
ONE_EXIT("players/haji/quest/lev11.c", "north",
  "A room",
    "This is an immense room,you see a path towards the north.\n",1)
