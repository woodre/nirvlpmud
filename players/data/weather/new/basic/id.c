/*
    basic/id.c - Give an id to an object.
    Feb 1992 by marion@cs.tu-berlin.de from Lars Pensj\o{} mudlib.n
*/

// added virtual, Coogan, 24-Jan-2001
virtual inherit "basic/synonym"; // added by Ugh 07-Dec-1994

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
  /* Perle 02-Apr-1995 insert check for str!=0 */
  return str && (str = lower_case(get_synonym(str))) &&
                (str == ((name = query_name()) && 
                         (stringp(name)) &&    // Carador, Mar-1996
                        (name = lower_case(name))) || 
                 ((ids = query_id()) &&  // cut '_real', Coogan, 07-Jul-1999
                  (member(ids, str) >= 0)));
}

// added by ardanna 05-Mar-1994
void add_id(mixed new_id) {
  if (stringp(new_id)) 
    new_id = ({ new_id }); // Ugh 23-Apr-1994 
  else if (!pointerp(new_id))
    return;
  new_id = map(new_id-({ 0 }), #'lower_case);  // -({ 0 }) inserted
                                                     // for the case that
                                                     // a 0 id is given in
                                                     // the array
                                                     //    Alfe 1996-Nov-28
#if 1  // Coogan, 11-Nov-1998: try to keep the order of id's if possible
  if (sizeof(m_indices(mkmapping(new_id))) != sizeof(new_id))
#endif
    new_id = m_indices(mkmapping(new_id)); // Chameloid, 27-Dec-1997
  id_names = (query_real_id()||({})) - new_id + new_id;
}

// added by Ugh 23-Apr-1994
void remove_id(mixed old_id) {
  if (stringp(old_id)) 
    old_id = ({ old_id });
  old_id = map(old_id, #'lower_case);
  // Ugh Apr-27-1995
  id_names = (query_real_id()||({})) - old_id;
}

// Ugh Apr-27-1995
void set_id(mixed new_id) {
  id_names = 0;
  add_id(new_id);
}

// i took it out again. sigh. it is not possible to have one without problems
// without end.  Alfe 1998-Feb-23
#if 0  // the following code is to check in which occasions somebody clones
       // an object of this basic class (which should not be done of course).
       // It could lead to different behaviour of some objects (aka. "bugs")
       // if some subclass of ours just calls ::reset() without prefix for
       // the :: operator and now calls us instead of somebody else. This is
       // not our fault, but we should be warned that it could happen.
       //                                 Alfe 1998-Feb-13
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
    // Alfe 1998-Feb-23
  else
    log_file("ILLEGAL",sprintf("%s: %O cloned by:\n%O\n",
                               ctime(),
                               this_object(),
                               caller_stack(1)));
}
#endif
