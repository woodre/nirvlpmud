/******************************************************************************
          basic/hittable.c -- written by Ugh for Tubmud Jul-1997
              an interface for objects with hit-locations
******************************************************************************/
status query_unreachable(object by) { return by == this_object(); }

private static mixed hit_size;

void set_hit_size(mixed size) {
  hit_size = size;
}

varargs int get_hit_size(object hit_by) {
  if (!(hit_by && query_unreachable(hit_by)))
    return funcall(hit_size,hit_by);
  else
    return 0;
}

status id(string str);
varargs object *get_inventory();

varargs mapping get_sub_hit_locations(object hit_by, string str) {
  return fold_left(#'+,map_objects(get_inventory(),
                                   "get_hit_locations",
                                   hit_by,
                                   str)-({0}), ([]));
}

varargs mapping get_hit_locations(object hit_by, string str) {
  int h;

  mapping result;
  if (!str || id(str)) {
    result = get_sub_hit_locations(hit_by);
    if (h = get_hit_size(hit_by))
      result += ([ this_object() : h ]);
  } else {
    result = get_sub_hit_locations(hit_by, str);
  }
  return result;
}

varargs status get_total_hit_size(object hit_by, string id) {
  return
    fold_left(#'+,m_values(get_hit_locations(hit_by,id)));
}

varargs object get_hit_location(object hit_by, string id) {
  mapping hit_sizes;
  object *parts;
  int i, s, p, r;

  hit_sizes = get_hit_locations(hit_by, id);
  parts = m_indices(hit_sizes);
  p = fold_left(#'+,m_values(hit_sizes));

  if (p > 0) {
    r = random(p);
    for (i = sizeof(parts); i--; )
      if (r < (s+=hit_sizes[parts[i]]))
        return parts[i];
  }
  return 0;  // Coogan, 24-Mar-2011
}

