/*                                                                            *
 *      File:             /players/angel/area/town/obj/l_rose.c               *
 *      Function:         flower                                              *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

id(str) { return str == "rose" || str == "red rose";}

short() { return ""+HIR+"A beautiful red rose"+NORM+""; }

long() {
    write("This large red rose is very beautiful to view and smell.\n");
    write("                                                                     \n");
    write(""+HIR+"           ________                                   "+NORM+"\n");
    write(""+HIR+"          /~ ___~\\/~\\                               "+NORM+"\n");
    write(""+HIR+"        /~~/~ _ ~~\\  |                               "+NORM+"\n");
    write(""+HIR+"       |  | /~o~ / ~\\|                               "+NORM+"\n");
    write(""+HIR+"       \\_ \\--_~/    \\                              "+NORM+"\n");
    write(""+HIR+"        \\ ~~-   |   /"+HIG+"                _ _ .-:  "+NORM+"\n");
    write(""+HIR+"          \\ \\ __\\ / "+HIG+"            .-~  .-~  / "+NORM+"\n");
    write(""+HIR+"             ~~~~"+HIG+"\\  \\        .~ .-~   .~     "+NORM+"\n");
    write(""+HIG+"                   \\  \\'     \\ '_ _ -~             "+NORM+"\n");
    write(""+HIG+"                      `.`.    //                      "+NORM+"\n");
    write(""+HIG+"             . - ~ ~-.-/`.`-.//                       "+NORM+"\n");
    write(""+HIG+"          .-~   . - ~ /  .  \\                        "+NORM+"\n"); 
    write(""+HIG+"         .' .-~      .       \\ :/~-.~-./:            "+NORM+"\n");
    write(""+HIG+"        /_~_ _ . - ~           ~- ~- ~- ~-.~-._       "+NORM+"\n");
    write(""+HIG+"                                         ~-.<         "+NORM+"\n");
    write("                                                                     \n");
}
get()
{
     return 1;
}
query_weight()
{
   return 1;
}
query_value()
{
return 100;
}
init()
{
 add_action("smell_rose", "smell");
}
smell_rose(str)
{
 if ((!str) || !id(str))
{
  return 0;
}
write("You smell the sweet scent of the rose.\n");
return 1;
}