/*
 *     man.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 */

inherit "obj/clean";

id(str)  {
return str == "corpse" || str == "man";
}

short()  {  return "Corpse of some man";  }

long()  {
    write("A rotting corpse of some unknown man.\n");
}

get()  { return 0; }

query_weight()  {  return 1;  }

query_value()  {  return 1;  }

