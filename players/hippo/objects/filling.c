#include "/players/hippo/bs.h"
reset(arg) {
        if(arg) return;
}

id( str ) {
   if(str=="filling") return 1;
        return 0;
}

long() {
   write("This might be a very valuable object. However, if you"+BS+
      "got enough money, you could throw it away."+BS);
}

short()
   {return"A golden filling";}
get() {
        return 1;
}
drop() {
        return 0;
}
query_value() {
   return(500);
}
