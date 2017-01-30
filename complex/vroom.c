#include <prop/room.h>
#include <prop/vroom.h>

inherit "/complex/room";

private mapping clone_list;
private string owner;

#if 0  // this checkt is nasty; blueprints must be ok, too.  Alfe 2002-Jan-21
void reset(int arg)
{
  if (clonep(this_object()))
    room::reset(arg);
}
#else
#if 0 // this doesn't work in those cases where the populate is overridden
      // Ugh, Mar-8-02
void configure() {
  if (clonep(this_object()))
    room::configure();
}

void populate() {
  if (clonep(this_object()))
    room::populate();
}
#else
// status query_no_populate() { return !clonep(); }

// Ugh, Mar-8-02, only suppress populate
// status query_no_configure() { return !clonep(); }
#endif
#endif

void set_owner(string identifier)
{
  if (!owner || !identifier)
    owner = identifier;
}

string query_owner()
{
  return owner;
}

/* This function is called by objects which are created by this
 * object and which thus inherit this vroom owner dynamically from
 * the room. Ugh Mar-11-02
 * This behavior is implemented in /basic/vroom_owner which saves the 
 * owner in the property P_VROOM_OWNER. This class is inherited by
 * standard livings and items. If your items are not cloned by the
 * room, you have to set the property 'manually' before or after
 * moving them into a vroom-clone. Ugh Oct-10-02
 */
string query_vroom_owner() {
  return
    query_owner() ||
    (clonep() ? load_name()->query_vroom_owner() : object_name());
}

string identify(object who)
{
  if (!who)
    return 0;
#if 1 // Ugh Mar-11-02
  return
    who->query_vroom_owner() ||
    (query_once_interactive(who) && who->query_real_name()) ||
    object_name(who);
#else
  if (query_once_interactive(who))
    return who->query_real_name();
  else
    return object_name(who);
#endif
}

object find_clone(mixed who)
{
  string identifier;
  if (clonep(this_object()))
    return load_name(this_object())->find_clone(who);
  identifier = stringp(who) ? who : identify(who);
  return clone_list && clone_list[identifier];
}

object load_clone(mixed who)
{
  string identifier;
  object ob;
  if (clonep(this_object()))
    return load_name(this_object())->load_clone(who);
  identifier = stringp(who) ? who : identify(who);
  ob = clone_list && clone_list[identifier];
  if (ob)
    return ob;
  set_owner(identifier); // ugh-ly hack :-)
  ob = clone_object(load_name(this_object()));
  set_owner(0);
  if (clone_list)
    clone_list[identifier] = ob;
  else
    clone_list = ([ identifier : ob ]);
  ob -> set_owner(identifier);
  return ob;
}

void add_exit(mixed dest, string dir, mixed hook, mixed flags) {
  // next 4 lines by Coogan, 14-Oct-2002
  if (stringp(dest) && dest[0..1]=="./")
    dest=implode(explode(object_name(this_object()),"/")[0..<2],"/")+dest[1..];
  else if (stringp(dest) && dest[0..2]=="../")
    dest=implode(explode(object_name(this_object()),"/")[0..<3],"/")+dest[2..];
#if 1 // Ugh Mar-11-02
  room::add_exit (lambda (({}), 
                      ({#'||, 
                        ({#'call_other, 
                          ({#'=, 
                            'ob, 
                            ({#'funcall, dest})
                          }), 
                          "find_clone", 
                          ({#'||,
                            ({#'this_player}),
                            ({#'query_vroom_owner})
                          })
                        }),  
                        'ob
                      })), 
                /* this closure does a 
                  return
                    (ob=funcall(dest))->find_clone(this_player() ||
                                                    query_vroom_owner()) ||
                    ob);
                */
              dir, 
              hook, 
              flags);
#else
  room::add_exit (lambda (({}), 
                      ({#'||, 
                        ({#'call_other, 
                          ({#'=, 
                            'ob, 
                            ({#'funcall, dest})
                          }), 
                          "load_clone", 
                          ({#'owner})
                        }),  
                        'ob
                      })), 
                /* this closure does a 
                  return ((ob=funcall(dest))->load_clone(owner)||ob); */
              dir, 
              hook, 
              flags);
#endif
}

void init()
{
  if (clonep(this_object()))
    room::init();
  else if (this_player()->query_vroom_owner() != object_name())
    move_object(this_player(),load_clone(this_player()));
}

int clean_up(int refs) {
  object ob;
  if (refs) /* refs==0 iff clonep(this_object()) */
    return 1;
  if (query_property(P_NO_CLEANUP))
    return 0;
  for (ob=first_inventory();ob;ob=next_inventory(ob))
    if (query_once_interactive(ob))
      return 1; // changed to 1 by Ugh Mar-8-2002
                // try clean up later again
  destruct(this_object());
  return 0;  // Coogan, 27-Mar-2011
}

void notify_destruct()
{
  object *clones;
  int i;
  if (clonep(this_object()) || !clone_list)
    return;
  clones = m_values(clone_list);
  for (i=0;i<sizeof(clones);i++)
    if (clones[i])
      destruct(clones[i]);
}

varargs void add_action(string func,string verb,int flag)
{
  if (clonep(this_object()))
    efun::add_action(func,verb,flag);
}
