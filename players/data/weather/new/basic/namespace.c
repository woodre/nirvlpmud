/****************************************************************************
  namespace.c rewritten (using mappings instead of alists) by Ugh 05-Jul-1994
****************************************************************************/

#pragma strong_types

mapping namespace;

void add_namespace(mixed key) {
  if (!namespace) 
    namespace = ([ ]);
  if (!member(namespace,key))
    namespace += ([ key : 0 ]);
}

int set_namespace(mixed keys, mixed data) {
  mapping step;
  int depth;
  if (stringp(keys)) // Ugh Mar-10-1998
    keys = explode(keys, "|");
  /* the first key is the namespace-name */
  if (!(pointerp(keys) && sizeof(keys) && 
	namespace && member(namespace, keys[0])))
    return 0;
  step = namespace;
  /* create a new mapping for every key that hasn't a namespace yet */
  for (depth = 0; depth < sizeof(keys) - 1; depth++) {
    if (!step[keys[depth]]) 
      step[keys[depth]] = ([ ]);
    step = step[keys[depth]];
  }
  step[keys[depth]] = data;
  return 1;
}

mixed get_namespace(mixed keys) {
  mapping step;
  int depth;

  if (stringp(keys)) // Ugh Mar-10-1998
    keys = explode(keys, "|");
  if (!(pointerp(keys) && sizeof (keys) && (step = namespace))) 
    return 0;
  for (depth = 0; depth < sizeof (keys) - 1; depth++)
    if (!(step = step[keys[depth]])) 
      return 0;
  return step[keys[depth]];
}

/* mixed for compatibility */
//static 
mixed export_namespace() {
  return namespace;
}

#define mapping_alist(x) (pointerp(x) && sizeof(x) == 2 && \
			  pointerp(x[0]) && pointerp(x[1]) && \
			  sizeof(x[0]) == sizeof(x[1]))

private void alist_to_mapping(string key, mixed value, mapping map) {
  if (mapping_alist(map[key]))
    walk_mapping((map[key] = mkmapping(value[0], value[1])), 
		 #'alist_to_mapping,
                 map[key]);
}

static void import_namespace(mixed import) {
  if (mappingp(import))
    namespace = import;
  else if (mapping_alist(import))
    walk_mapping((import = mkmapping(import[0], import[1])), 
                 #'alist_to_mapping,
                 import);
  else
    namespace = 0;
}

