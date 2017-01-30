#include "/players/pavlik/guild/mages/defs.h"

/*
 * for compat with verte's channel
 */
object * query_mages()
{
  object *u, *m;
  int i;

  m = ({});

  i = sizeof(u = users());
  while(i--)
  {
    if(u[i] && present(GOBID, u[i]))
	m += ({ u[i] });
  }
  return m;
}

string query_tag()
{
  return HIC+"["+HIR+"*"+HIC+"]"+NORM;
}

void add_history(string str)
{
   "/obj/user/chistory"->add_history("MAGES", str);
}

void tell_members(string str)
{
  object *ob;
  int i;

  i = sizeof(ob = query_mages());
  while(i--)
  {
	if(present(GOBID, ob[i]) && !present(GOBID, ob[i])->query_muffled())
		tell_object(ob[i], str);
  }
}

