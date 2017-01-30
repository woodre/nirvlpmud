#include <ansi.h>
inherit "obj/clean";

id(str)  {
return str == "fetus" || str == "gore";
}

short()  {  return HIR+"A puddle of fetus gore"+NORM;  }

long()  {
    write("This is all that remains of an aborted fetus.\n");
}

get()  { return 1;  }

query_weight()  {  return 1;  }

query_value()  {  return 75;  }
