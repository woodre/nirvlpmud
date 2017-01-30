#include "/players/eurale/closed/JUNK/color.h"

int bucket_color;

reset(arg) {
  if (arg) return;
  call_out("trash_this", 100);
}

extra_look() {
  if (bucket_color==0)
    return RED+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
  if (bucket_color==1)
    return YELLOW+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
  if (bucket_color==2)
    return BLUE+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
  if (bucket_color==3)
     return GREEN+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
 if (bucket_color==4);
    return PURPLE+capitalize(environment(this_object())->query_name())+
           " is covered with paint"+END;
}

trash_this() { destruct(this_object()); }

start_bucket_stuff(arg) { bucket_color = arg; }

drop() { return 1; }

id(str) { return str=="paint" || str=="bucket stuff" || str=="bucket_stuff"; }
