/*
// File: exclude_array.c
// A simul_efun module.
// Thanks to the folks at Portals for this one.
// Author: either Huthar or Wayfarer, I presume.
// Now a part of the TMI distribution mudlib.
// Purpose: to remove a range from an array
// Tossed into Nirvana by Shadowhawk the NUISANCE
*/

#pragma strict_types
#pragma save_types

mixed *exclude_array(mixed *arr, int from, int to) {
  mixed *bottom,*top;
   
  bottom = ({ });
  top = ({ });
   
  if(!to) to = from;
  if(from > 0)
    bottom = arr[0 .. from - 1];
  if(to < sizeof(arr) - 1)
    top = arr[to + 1 .. sizeof(arr) - 1];
  return bottom + top;
}
