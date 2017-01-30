#include "/players/quicksilver/closed/color.h"

init()
{
  add_action("sniffme","sniff");
  add_action("sniffme","smell");
}

get() { return 1; }
drop() { 
   tell_object(environment(this_object()), "The rose falls silently to the ground and vanishes.\n");
   destruct(this_object());
   return 0; }
   
long() { return write(RED+"This is a very fine long-stemmed rose picked especially for you by Quicksilver.\nIt appears to be wonderfully fragrant."+NOSTYLE+"\n"); }
short() { return GRE+"----------,---'-,---,-'--}"+RED+"@"+NOSTYLE+"\n"; }
id(str) { return str=="rose"; }

sniffme(str) {
   if(!id(str)) return 0;
   write(RED+"You lift the rose to your nose and inhale slowly...\nThe sweet fragrance envelops you."+NOSTYLE+"\n");
   say(capitalize(this_player()->query_real_name())+" smells "+this_player()->query_possessive()+" long-stemmed rose.\n");
   return 1;
}
