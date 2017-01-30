/*
 * Inherit this to start shadows, and help to provide info about
 * objects that are shadowing. shadow(ob, 0) will return the last
 * object that has shadowed ob. But there may be more than one
 * active shadow. query_shadow_ob() will give the 'upper' most
 * shadow object. query_shadow_list() will provide a list of all
 * currently active shadows
 */

object *shadows;

static status filter_zeros(object ob) { return (ob) ? 1 : 0; }

object *query_shadow_list() {
  if (!shadows) shadows = ({});
#ifndef __LDMUD__
  return shadows = filter_array(shadows, "filter_zeroes", this_object());
#else
  return shadows = filter(shadows, "filter_zeroes", this_object());
#endif
}


/* don't call this or you will upset the list */

void set_shadow_list(object *arg) {
  string file;

  if (previous_object()) { /* lets restrict wizard damage */
    if (!sscanf(file_name(previous_object()), "obj/shadows/%s",file)) return;
  }
  shadows = arg;
}

object query_shadow_ob() { return this_object(); }


static void shadow_object(object ob) {
  object obj;
  int i;

  if (!ob) {
    destruct(this_object());
    return;
  }
  if (!shadows) shadows = ({});
  if ((obj = shadow(ob, 0))) {
    shadows = (object *)obj->query_shadow_list();
  }
  shadow(ob, 1);
  shadows += ({ this_object(), });
  for (i = 0; i < sizeof(shadows); i++) { /* all shadows have same list */
    if (shadows[i]) shadows[i]->set_shadow_list(shadows);
  }
}

