/*                                                                    
*    File: /players/shinshi/areas/school/obj/map2.c                
*    Function: object
*    Author(s): Shinshi@Nirvana       
*    Copyright: Copyright (c) 2009 Shinshi      
*               All Rights Reserved   
*    Source: 04/30/09           
*    Notes:                                                          
*                                                                    
*                                                                    
*    Change History:                                                 
*/

inherit "/obj/treasure";

id(str) { return (str == "map" || str == "tech map"); }

short() { return "A map of the tech wing"; }
long() {
	write(" \n");
	write("*************************************************\n");
	write("*     N                                         *\n");
	write("*    W+E                                        *\n");
	write("*     S                                         *\n");
	write("*                             H                 *\n");
    write("*                             |  G              *\n");
    write("*                   J------------|  F           *\n");
    write("*                           |    |<             *\n");
    write("*                           I    |  E           *\n");
    write("*                                |              *\n");
    write("*                              D-|              *\n");
    write("*                                |-C            *\n");
    write("*                                |              *\n");
    write("*                                |              *\n");
    write("*                            B----------------->*\n");
    write("*                                     |         *\n");
    write("*                                     A         *\n");
    write("*                                               *\n");
    write("*************************************************\n");
    write("                                                 \n");
    write("                                                 \n");
    write("A = Mader, B = Green, C = Thompson, D = Somers,  \n");
    write("E = Mens 2, F = Womans 2, G = Hillyer,           \n");
    write("H = Trecanelli, I = Zimmerman, J = Hoylman       \n");
    write("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
}

query_value() { return 0; }
query_save_flag() { return 0; }
query_weight() { return 1; }
get(){ return 1; }

reset(arg)
{
	if(arg) return;
}