/*                                                                    
 *    File: /players/chip/closed/other/SATAN/satankey.c                
 *    Function: key item
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2008 Chip      
 *               All Rights Reserved   
 *    Source: 7/30/09           
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 */
inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "chips_key" || str == "key";
}

short() { return "A "+HIR+"b"+HIY+"u"+HIR+"r"+HIY+"n"+HIR+"i"+HIY+"n"+HIR+"g "+HIY+"r"+HIR+"e"+HIY+"d "+NORM+"key"; }
long() {
        write("A burning red key that has seven major ridges\n"+
                  "on the top which is inserted into the key hole.\n");
}

get() { return 1; }
query_weight() { return 2; }
query_value(){ return 4500; }