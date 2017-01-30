 
#pragma strict_types
#pragma save_types
 
mixed *deconstruct_mapping(mapping map) {
  int i, so;
  mixed *indices, *savemap;
  savemap = ({ });
  indices = keys(map);
  for( i = 0, so = sizeof(indices); i < so; i++ )
    savemap += ({ indices[i], map[indices[i]] });
  return savemap;
}
