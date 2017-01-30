mixed *m_values(mapping map) {
  mixed *values, *indices;
  int i, size;

  values = ({ });
  indices = keys(map);
  for (i=0,size=sizeof(indices); i<size; i++)
    values += map[indices[i]];
  return values + ({ });
}

mixed *deconstruct_mapping(mapping map) {
  int i, size;
  mixed *indices, *savemap;

  savemap = ({ });
  indices = keys(map);
  for (i = 0, size = sizeof(indices); i < size; i++)
    savemap += ({ indices[i], map[indices[i]] });
  return savemap;
}

mapping reconstruct_mapping(mixed *savemap) {
  int i, size;
  mapping map;

  map = ([ ]);
  for (i=0, size=sizeof(savemap); i<size; i++)
    map += ([ savemap[i] : savemap[++i] ]);
  savemap[0..size-1] = ({ });
  return map;
}

status member(mapping m, mixed key) {
  int x;
  mixed *indices;
  indices = keys(m);
  for (x = 0; x < sizeof(m); x++) {
    if (indices[x] == key)
      return 1;
  }
  return 0;
}

int check_ip(string ipaddr, string *ips) {
  int x;
  for (x = 0; x < sizeof(ips); x++) {
    if (ipaddr == ips[x])
    return x;
  }
  return -1;
}

mixed *update_array(int num, mixed item, mixed *tmparray) {
  int x;

  for (x = 100; x > num; x--)
    tmparray[x] = tmparray[x-1];
  tmparray[num] = item;
  return tmparray;
}

