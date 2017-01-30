#include "/kernel/shared.h"

private static mapping shared_access;

nomask mixed allocate_shared_mem(string name, mixed initial) {
  string *allowed;

  if (!shared_access)
    shared_access = SHARED_ACCESS;
  if (allowed = shared_access[name]) {
    if (member(allowed, object_name(previous_object())) >= 0) {
      mapping wizinfo;
      mixed data;

      if (!(wizinfo = get_extra_wizinfo(0)))
        set_extra_wizinfo(0, wizinfo = ([ ]));
      if (!(data = wizinfo[name]))
        data = wizinfo[name] = initial;
      return data;
    }
  }
  return 0;
}

nomask void clear_shared_mem(string name) {
  string *allowed;

  if (!shared_access)
    shared_access = SHARED_ACCESS;
  if (allowed = shared_access[name]) {
    if (member(allowed, object_name(previous_object())) >= 0) {
      mapping wizinfo;

      if (!(wizinfo = get_extra_wizinfo(0)))
        set_extra_wizinfo(0, wizinfo = ([ ]));
      m_delete(wizinfo, name);
    }
  }
}

