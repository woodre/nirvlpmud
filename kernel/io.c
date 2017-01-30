#pragma strong_types
#pragma save_types

#include "/kernel/defs.h"

private static mixed privilege;
private static mixed unguarded_privilege;
private static mixed *security_handle;

nomask static void
set_privilege(mixed priv)
{
  if (extern_call())
    return;
  if (object_name(this_object())==SECURITY)
  {
    privilege = priv;
    return;
  }
  if (!efun::call_other(SECURITY,"valid_privilege",priv))
    return;
  if (stringp(priv) && priv[0]=='#')
  {
    if (query_once_interactive(this_object())
        && object_name(this_object())[<strlen(priv)..]==priv)
      privilege = priv;
    return;
  }
  privilege = efun::call_other(SECURITY,"reduced_privilege",priv,
                               efun::call_other(SECURITY,"query_protection",
                                                this_object(),1));
}

nomask mixed
query_privilege()
{
  return privilege;
}

nomask mixed
query_unguarded_privilege()
{
  return unguarded_privilege;
}

nomask int
verify_privilege_granted(mixed *handle)
{
  return security_handle == handle;
}

nomask varargs static mixed
unguarded(mixed priv, closure code, mixed args)
{
  if (extern_call())
    return 0;
  unguarded_privilege = priv;
  return efun::call_other(SECURITY,"call_unguarded",
                          code,args,security_handle=allocate(1));
}

