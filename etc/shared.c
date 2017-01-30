static varargs int security_check(string key,mixed value,status writing)
{
  closure cpp,cs,lf;
  switch (object_name(previous_object()))
  {
    case "global/server/wizline":
    case "global/server/events.new":
    case "global/server/events":
    case "global/server/doors":
    case "global/server/time":  // Alfe 1997-Jun-25
    case "global/server/users": // Alfe 1995-Mar-10
    case "obj/post_master":     // Alfe 1995-Mar-04
    case "etc/editor":
    case "global/server/skills": // Ugh 1995-May-16
    case "etc/shared": // Let master & simul_efun use this via bind_lambda()
      return 1;
  }
#if 1  // Alfe 1997-Jun-26
  // the following uglinesses with symbol_function are necessary because
  // the simul_efun object uses us at startup, i.e. when it isn't installed
  // yet. at this moment the simul_efuns caller_stack(), log_file() and
  // check_previous_privilege() do not yet exist.
  // funcall()ing cpp didn't work either, so i called "kernel/server"
  // directly which is also very ugly.
  if ((cpp=symbol_function("check_previous_privilege")) &&
      (cs=symbol_function("caller_stack")) &&
      (lf=symbol_function("log_file")) &&
#if 0  // Alfe 2001-Aug-30
      "kernel/server"->check_privilege(1,1)
#else
      efun::call_other("kernel/server","check_privilege",1,1)
#endif
      ) {
    if (writing)
      funcall(lf,
              "SHARED",
              sprintf("%s: %s set key %O to value %O\n",
                      ctime(),
                      implode(map(funcall(cs,1),#'to_string)," < "),
                      key,value));
    else
      funcall(lf,
              "SHARED",
              sprintf("%s: %s queried key %O\n",
                      ctime(),
                      implode(map(funcall(cs,1),#'to_string)," < "),
                      key));
    return 1;
  }
#endif
  return 0;
}

void set_global(string key,mixed value)
{
  if (!security_check(key,value,1))
    return;
  if (!mappingp(get_extra_wizinfo(0)))
    set_extra_wizinfo(0,([ ]));
  get_extra_wizinfo(0)[key] = value;
}

mixed query_global(string key)
{
  mapping temp;
  if (!security_check(key))
    return 0;
  temp = get_extra_wizinfo(0);
  return mappingp(temp) && temp[key];
}

mixed query_entries()
{
  mapping m;
  m = get_extra_wizinfo(0);
  if (m)
    return m_indices(m);
  return ({ });
}
