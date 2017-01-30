/*
*      File:             /players/lacar/area/park/obj/fairywingsm.c
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
  set_name("Male fairy wings");
  set_alias("wings");
  set_short("Fairy wings");
  
  set_long("A pair of sparkling blue wings from a male fairy.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(150);
  set_params("magical", 0, 10, "void");
}