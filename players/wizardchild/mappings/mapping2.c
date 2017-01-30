mixed *mapping_to_mixed(mapping map) {
  int i,so;
  mixed *key,*out;
  out = ({ });
  key = keys(map);
  for(i=0,so=sizeof(key); i < so; i++) {
    out += ({ key[i] });
    out += ({ map[key[i]] });
  }
  return out + ({ });
}
mapping mixed_to_mapping(mixed *m) {
  mapping map;
  int i,so;
  map = ([ ]);
  so = sizeof(m);
  while(i < so) {
    map += ([ m[i] : m[(i+1)] ]);
    i += 2;
  }
  return map;
}
