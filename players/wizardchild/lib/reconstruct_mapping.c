 
#pragma strict_types
#pragma save_types
 
mapping reconstruct_mapping(mixed *savemap) {
  int i, so;
  mapping map;
  map = ([ ]);
  for(i = 0, so = sizeof(savemap); i < so; i++)
    map += ([ savemap[i] : savemap[++i] ]);
  savemap[0..(size-1)] = ({ });
  return map;
}
