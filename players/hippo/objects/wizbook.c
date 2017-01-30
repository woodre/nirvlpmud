reset(arg) {
#include "/players/hippo/bs.h"
        if(arg) return;
}

id( str ) {
   if(str=="book") return 1;
        return 0;
}

long() {
write ("The title of the book is: 'The Wizzard Book', it"+BS+
  "looks like it is an interesting thing to read."+BS);
}

short()
   { return "A Wizzard Book"; }
init()
{
   add_action("do_read","read");
}

do_read (str) {
write ("This book is only for intelligent people like Hippo and Trix."+BS+
   "Please take your filthy hands off the book, and clean you ass"+BS+
   "before you go back to his workroom"+BS);
   return 1;
}
get() {
        return 1;
}
drop() {
        return 0;
}
