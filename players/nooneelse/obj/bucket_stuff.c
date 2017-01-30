/* bucket_stuff.c - put pain from a bucket on someone after they're hit with
                    a bucket for a while
*/

#include "/players/nooneelse/color.h"

int bucket_color;

reset(arg) {
  if (arg) return;
  call_out("trash_this", 100);
}

extra_look() {
  if (bucket_color=="red")
    return RED+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
  if (bucket_color=="yellow")
    return YELLOW+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
  if (bucket_color=="blue")
    return BLUE+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
  if (bucket_color=="green")
     return GREEN+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
 if (bucket_color=="purple");
    return PURPLE+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
}

trash_this() { destruct(this_object()); }

start_bucket_stuff(arg) { bucket_color = arg; }

drop() { return 1; }

id(str) { return str=="paint" || str=="bucket stuff" || str=="bucket_stuff"; }
