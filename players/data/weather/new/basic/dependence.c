/*
  Inherit this if you want to have control over all the clones of your
  object.
  If the blueprint is destructed all clones are destructed as well.
  The function query_clones() returns an array of all clones.

  One thing is important: You have to make sure that reset(0) is
  called in all clones at their creation.

*/

inherit "basic/create";

#define BLUEPRINT load_name(this_object())

private object *clones;

void add_clone(object o) {
  if (clonep(this_object()))
    BLUEPRINT->add_clone(o);
  else {
    clones -= ({ o }); // Arkon, 15-Jan-1995
    clones += ({ o });
  }
}

void remove_clone(object o) {  // Coogan, 21-Oct-1998, for Walchy
  if (clonep(this_object()))
    BLUEPRINT->remove_clone(o);
  else
    clones -= ({ o });
}

object *query_clones() {
  if (clonep(this_object()))
    return BLUEPRINT->query_clones();
  else
    return clones -= ({ 0 });
}

void notify_destruct() {
  if (clonep(this_object()))
      // added this part of the branch, Coogan, 21-Oct-1998
    BLUEPRINT->remove_clone(this_object());
  else
    map(clones - ({ 0 }), #'destruct);
}

void refresh() {
  if (!clonep(this_object()))
    clones -= ({ 0 });
  "*"::refresh();
}

void create() {
  if (clonep(this_object()))
    BLUEPRINT->add_clone(this_object());
  else
    clones = ({ });
  "*"::create();
}

