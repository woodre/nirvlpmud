/* this recursive, defs.h includes it. -Bp
#include "/players/wocket/closed/ansi-blah.h"
*/
#include "/players/wocket/mages/def.h"

query_auto_load(){ return "/players/wocket/mages/mageautoload.c:"; }

id(str){ return (str == "mageautoload" || str == "secret_mage_autoload_name"); }
drop(){  return 1; }
get(){   return 0; }

init_arg(){
   object book;
   object mage;
   mage = this_player();
   book = clone_object(MAGEDIR+"book.c");
   if(mage->is_player()){
      move_object(book,mage);
    write(BCYN);
    write(BLK);
      cat(MAGEDIR+"GUILDNEWS");
      write(OFF);
   }
   else
      destruct(book);
}
