#include "/players/puppy/define.h"
#define TPPOS this_player()->query_possessive()
#define TPN this_player()->query_name()

id(str) {
   return str == "ribbon";
}
reset(arg)  {
   if(arg) return;
}

long() {
   write("This ribbon is a symbol of all the lives lost in the attacks\n");
   write("on the United States of America on 9-11-01.  All the lives of\n");
   write("everyone who tried to help them.  All of the lives of the\n");
   write("innocent.  'Wear'ing the ribbon close to your heart allows\n");
   write("you to honor the victims in your own small way.\n");
}

init()
{  add_action("blah", "wear");   }
blah(str)  {
   if(str == "ribbon")  {
      write("You look down and straighten your ribbon\n");
  say(TPN+" straightens "+TPPOS+" ribbon.\n");
      return 1;   }
}

short() { return 0;}
drop() {return 0;}
get() { return 0; }


extra_look() {
   
   if(environment() == this_player())
      write("You wear a"+ HIY +" small yellow ribbon"+ NORM +" pinned to your chest.\n");
   else write(environment()->query_name() + " wears a " +
         HIY + "small yellow ribbon" + NORM + " pinned to " +
      possessive(environment()) + " chest.\n");
}
query_auto_load() {return "/players/puppy/mem/ribbon.c:"; }
