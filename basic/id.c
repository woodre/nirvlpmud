/*
 * /basic/id.c
 *
 * Give an id to an object
 */

virtual inherit "basic/synonym";

string query_name();

private string *id_names;

string* query_real_id() {
  return id_names && id_names[0..];
}

string* query_id() {
  return query_real_id();
}

int id(string str) {
  string *ids, name;
  return str && (str = lower_case(get_synonym(str))) &&
                (str == ((name = query_name()) && 
                         (stringp(name)) &&
                        (name = lower_case(name))) || 
                 ((ids = query_id()) &&
                  (member(ids, str) >= 0)));
}

void add_id(mixed new_id) {
  if (stringp(new_id)) 
    new_id = ({ new_id });
  else if (!pointerp(new_id))
    return;
  new_id = map(new_id-({ 0 }), #'lower_case);  // -({ 0 }) inserted
                                                     // for the case that
                                                     // a 0 id is given in
                                                     // the array
#if 1  // Try to keep the order of id's if possible
  if (sizeof(m_indices(mkmapping(new_id))) != sizeof(new_id))
#endif
    new_id = m_indices(mkmapping(new_id));
  id_names = (query_real_id()||({})) - new_id + new_id;
}

void remove_id(mixed old_id) {
  if (stringp(old_id)) 
    old_id = ({ old_id });
  old_id = map(old_id, #'lower_case);
  id_names = (query_real_id()||({})) - old_id;
}

void set_id(mixed new_id) {
  id_names = 0;
  add_id(new_id);
}

// i took it out again. sigh. it is not possible to have one without problems
// without end.
#if 0  // the following code is to check in which occasions somebody clones
       // an object of this basic class (which should not be done of course).
       // It could lead to different behaviour of some objects (aka. "bugs")
       // if some subclass of ours just calls ::reset() without prefix for
       // the :: operator and now calls us instead of somebody else. This is
       // not our fault, but we should be warned that it could happen.

void reset(status refresh) {
  if (refresh ||  // not first reset?
      !clonep())  // we are the blueprint?
    return;
  if ("/" + load_name(this_object()) + ".c" != __FILE__)
    // we are inherited
    // nobody should call reset() in us when we are inherited, because we
    // are not supposed to have one, so this is an error of the above men-
    // tioned type. we try to make it clear in the error we raise.
    //raise_error("Please look into "__FILE__" at line "+__LINE__+"\n")
    ;
    // we don't raise this error anymore because if we are the only thing
    // in the object which defines a reset(), we may be called.
  else
    log_file("ILLEGAL",sprintf("%s: %O cloned by:\n%O\n",
                               ctime(),
                               this_object(),
                               caller_stack(1)));
}
#endif

