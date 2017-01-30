/*
*      File:             /players/lacar/area/park/obj/lwings.c
*      Function:         obj
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar (Carla J Merrill)
*                                All Rights Reserved
*      Source:    		11/22/2006
*      Notes:            area
*      Change History:
*/
inherit "obj/armor";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Ladybug wings");
  set_alias("wings");
  set_short("Ladybug wings");
  
  set_long("A pair of red wings with black spots.\n");
  set_type("misc");
  set_ac(1);
  set_weight(2);
  set_value(150);
  set_params("magical", 0, 10, "void");
}