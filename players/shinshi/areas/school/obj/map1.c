/*                                                                    
*    File: /players/shinshi/areas/school/obj/map1.c                
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

id(str) { return (str == "map" || str == "main map"); }

short() { return "A map of the main floor"; }
long() {
	write(" \n");
	write("********************************************************\n");
	write("*     N                                                *\n");
	write("*    W+E               K  J I                          *\n");
	write("*     S                 \/  |                           *\n");
	write("*          Q  P       ------|-H                        *\n");
	write("*          |  |       |     |                          *\n");
	write("*      R----------O   L   M-|-G                        *\n");
	write("*        |      |-N         |          D               *\n");
	write("*      S-|      |           | V  B     |               *\n");
	write("*        |      |           |/   |     |               *\n");
	write("*<--------------------------A----------|               *\n");
	write("*               |                |     |               *\n");
	write("*               |                C     |-E             *\n");
	write("*               |                      |               *\n");
	write("*               |                      |-F             *\n");
	write("*               |                      |               *\n");
	write("*               T                      U               *\n");
	write("********************************************************\n");
	write("                                                        \n");
	write("                                                        \n");
	write("A = Entrance, B = Wasielewski, C = Hejl, D=Guidance     \n");
	write("E = Nurse, F = Copy Room, G = Special Ed, H = Stairs    \n");
	write("I = Cafeteria, J = Mens Room, K = Womens, L = Exit      \n");
	write("M = Petrey, N = Garback, O = Fulkrod, P = Hutchinson    \n");
	write("Q = Chamberlin, R = Mateer, S = Long, T = Office        \n");
	write("U = Exit 2, V = Stairs 2                                \n");
	write("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
}

query_value() { return 0; }
query_save_flag() { return 0; }
query_weight() { return 1; }
get(){ return 1; }

reset(arg)
{
	if(arg) return;
}