#include "/players/wocket/closed/ansi.h"
cmd(){
   object mageautoload;
   object book;
   previous_object()->save_book();
   destruct(previous_object());
   book = clone_object("/players/wocket/mages/book.c");
   move_object(book,this_player());
   if(present("mageautoload",this_player()))
      destruct(present("mageautoload",this_player()));
   mageautoload = clone_object("/players/wocket/mages/mageautoload.c");
   move_object(mageautoload,this_player());
   write(HIR+"Guild object updated...\n"+NORM);
   return 1;
}
