#include "/players/cosmo/closed/ansi.h"

id(str) {
    return str == "map";
}

reset(arg) {
  if(arg) return;
}

long() {
    write("Read it.\n");
}

short() {
    write("A map of D.C.\n");
}
drop() {return 0;}
get() {return 1;}

init() {
  add_action("read","read");
}

read() {
  write("\n"+
"              a=Air and Space        k=Kennedy Center\n"+
"       z      c=US Capitol           l=Lincoln Memorial\n"+
"       |      d=Natural History      m=Merry-go-round\n"+
"       |      e=American History     s=Supreme Court\n"+
"  Key--g      g=Georgetown           t=Treasury\n"+
"    /   \\     h=Gallery of Art       w=Washington Monument\n"+
"   /     \\    i=Ice Skating Rink     y=White House\n"+
"  x       \\   j=Jefferson Memorial   z=Zoo\n"+
"  |        \\ \n"+
"  x--k      x--x--x\n"+
"   \\        |  |  |\n"+
"    x       x  y  x\n"+
"     \\      |     |\n"+
"      x     x  x  x     e     d\n"+
"      |     |  |  |     |     |\n"+
"      x  x--x--x--x--x--x--x--x--x---x--x\n"+
"      |  |           |        |      |  |\n"+
" Mem--x--l--x--x--w--x     m  i    x-c  s\n"+
"       \\ |           |     |         |\n"+
"         x--x--x--x--x--x--x--x--x---x\n"+
"                     |        |  |\n"+
"                  t--x        h  a\n"+
"                   / |\n"+
"                  j  |\n"+
"                    14th\n");
  return 1;
}
