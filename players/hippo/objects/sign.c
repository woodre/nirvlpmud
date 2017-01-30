reset(arg) {
#include "/players/hippo/bs.h"
        if(arg) return;
}

id( str ) {
   if(str=="sign") return 1;
        return 0;
}

long() {
write ("You see a sign, pointing to the hand, to some water (?) and to "+BS+
      "some unidentified strange, black stuff. I bet you'll never know"+BS+
      "what that all is, unless you look at the hand more carefully and maybe even "+BS+
      "have shaken it. Maybe reading the sign, will make things more clear?"+BS);
}

short()
   { return "A sign, pointing to the enormous hand"; }
init()
{
   add_action("do_read","read");
}

do_read (str) {
write (
         "While reading, you see some other strange stuff. Some fluid substance, "+BS+
        "with harder things in it. You hope you never get into something like that!"+BS+
        ""+BS+
        "Under this message, you see something written. It must have been done"+BS+
      "by somebody who shaked the hand ones. You hardly can read it:"+BS+
       ""+BS+
       "        Pe ople beLoW l ev el  16 SHouLd Bett eR NoT ent e R alOnE ! !"+BS);
   return 1;
}
get() {
      write("You can not take that! It's stuck to the ground."+BS);
        return 0;
}
drop() {
        return 0;
}
