/****************************************************************************
      resources.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

private mapping free, unused, all, shared, required, resource_ids;

void
create()
{
  all = ([]);
  free = ([]);
  shared = ([]);
  required = ([]);
  unused = ([]);
  resource_ids = ([]);
}

void
add_resource(string resource, string *ids)
{
  int i;
  if (member(all,resource))
    return;
  all += ([ resource ]);                
  free += ([ resource ]);               // free
  for (i = sizeof(ids); i--; )
  {
    if (!member(resource_ids,ids[i]))
      resource_ids[ids[i]] = ([]);
    resource_ids[ids[i]] += ([ resource ]);
  }
}

void
remove_resource(string resource)
{
  map(({all,unused,free,shared,required}),#'m_delete,resource); 
  walk_mapping(resource_ids,lambda(({'id,'resources}),
				   ({#'-=,'resources,([resource])})));
}

status
require_resource(string resource, mixed who)
{
  if (!who || member(unused,resource))
    return 0;
  if (member(free,resource))
  {
    required[resource] = who;
    m_delete(free,resource);
    return 1;
  }
}

status
free_resource(string resource, mixed who)
{
  if (!member(all,resource))
    return 0;
  if (required[resource] && required[resource] == who)
  {
    free += ([ resource ]);
    m_delete(required,resource);
    return 1;
  }
}

status
share_resource(string resource, mixed who)
{
  if (!who || member(unused,resource))
    return 0;
  if (member(free,resource) || member(shared,resource))
  {
    if (member(free,resource))
    {
      shared[resource] = ([ who ]);
      m_delete(free,resource);
    }
    else 
      shared[resource] += ([ who ]);
    return 1;
  }
}

status
free_shared_resource(string resource, mixed who)
{
  int i;
  if (member(shared,resource) && member(shared[resource],who))
  {
    m_delete(shared[resource],who);
    if (!sizeof(shared[resource]))
    {
      m_delete(shared,resource);
      free += ([ resource ]);
    }
    return 1;
  }
}

void
deactivate_resource(string resource)
{
  if (member(all,resource))
    unused += ([ resource ]);
}

void
activate_resource(string resource)
{
  unused -= ([ resource ]);
}

mapping
get_resources(string id)
{
  if (!id)
    return mkmapping(m_indices(all));
  else if (member(resource_ids,id))
    return copy(resource_ids[id]);
}

varargs status
query_unused(string resource, object requirer)
{
  return member(unused,resource);
}

varargs status
query_free(string resource, object requirer)
{
  return !query_unused(resource,requirer) && member(free,resource);
}

status 
query_shared(string resource)
{
  return !member(unused,resource) && member(shared,resource);
}

status
query_required(string resource)
{
  return !member(unused,resource) && member(required,resource);
}

varargs mapping
has_resources(string *r, status some, object ob)
{
  int i;
  mixed h;
  mapping bag, result;
  result = ([]);
  bag = m_allocate(sizeof(r),0);
  for (i = sizeof(r); i; i--)
  {
    h = get_resources(r[<i]);
    if (!h)
    {
      if (some)
	continue;
      else
	return 0;
    }
    h -= bag;
    h -= filter_indices(h,#'query_unused, ob||previous_object());
    if (sizeof(h))
    {
      h = m_indices(h)[0];
      bag += ([ h ]);
      result += ([ h : r[<i] ]);
    }
    else if (!some)
      return 0;
  }
  return result;
}

varargs mapping 
substitute_resources(string *req, string *sha,status some,object ob)
// the arguments are passed call-by-reference
{
  int i;
  string *req_result, *sha_result;
  mixed h;
  mapping bag, result;
  bag = m_allocate(sizeof(req)+sizeof(sha),0);
  for (i = sizeof(req); i; i--)
  {
    h = get_resources(req[<i]);
    if (!h)
    {
      if (some)
	continue;
      else
	return 0;
    }
    h -= bag;
    h = filter_indices(h,#'query_free,ob||previous_object());
    if (sizeof(h))
    {
      h = m_indices(h)[0];
      result += ([ h : req[<i] ]);
      bag += ([ h ]);
    }
    else if (!some)
      return 0;
  }
  req_result = m_indices(bag);
  for (i = sizeof(sha); i; i--)
  {
    h = get_resources(sha[<i]);
    if (!h)
    {
      if (some)
	continue;
      else
	return 0;
    }
    h -= bag;
    h = filter_indices(h,#'query_free,ob||previous_object()) +
	filter_indices(h,#'query_shared);
    if (sizeof(h))
    {
      h = m_indices(h)[0];
      result += ([ h : sha[<i] ]);
      bag += ([ h ]);
    }
    else if (!some)
      return 0;
  }
  req = req_result;
  sha = m_indices(bag) - req_result;
  return result;
}

status 
can_substitute_resources(string *req, string *sha)
// the arguments are passed call-by-reference
{
  int i;
  string *req_result, *sha_result;
  mixed h;
  mapping bag;
  bag = m_allocate(sizeof(req)+sizeof(sha),0);
  for (i = sizeof(req); i; i--)
  {
    h = get_resources(req[<i]);
    if (!h)
      return 0;
    h -= bag;
    h = filter_indices(h,#'query_free,previous_object());
    if (sizeof(h))
      bag += ([ m_indices(h)[0] ]);
    else
      return 0;
  }
  req_result = m_indices(bag);
  for (i = sizeof(sha); i; i--)
  {
    h = get_resources(sha[<i]);
    if (!h)
      return 0;
    h -= bag;
    h = filter_indices(h,#'query_free,previous_object()) +
	filter_indices(h,#'query_shared);
    if (sizeof(h))
      bag += ([ m_indices(h)[0] ]);
    else
      return 0;
  }
  req = req_result;
  sha = m_indices(bag) - req_result;
  return 1;
}

status
require_and_share_resources(string *req, string *sha, mixed who)
{
  mapping old_shared, old_free;
  if (!req)
    req = ({});
  if (!sha)
    sha = ({});
#if 0
  if (!can_substitute_resources(&req,&sha))
    return 0;
#else
  if (sizeof(filter(req + sha,#'query_unused)))
    return 0;
  if (sizeof(filter(req,#'query_free)) < sizeof(req))
    return 0;
  if (sizeof(filter(sha,#'query_free) + 
             filter(sha,#'query_shared)) < sizeof(sha))
    return 0;
#endif
  filter(req,#'require_resource,who);
  filter(sha,#'share_resource,who);
  return 1;
}

void
free_resources(string *req,string *sha,mixed who)
{
  if (req)
    filter(req,#'free_resource,who);
  if (sha)
    filter(sha,#'free_shared_resource,who);
}

varargs string *
query_required_resources(mixed who)
{
  return who ?
    m_indices(filter_indices(required,
                             lambda(({'r}),
                                    ({#'==,
                                      who,
                                      ({#'[,required,'r})})))) : 
    m_indices(required);
}

varargs string *
query_shared_resources(mixed who)
{
  return who ?
    m_indices(filter_indices(shared,
                             lambda(({'r}),
                                     ({#'member,
                                       ({#'[,shared,'r}),
                                       who})))) :
    m_indices(shared);
}

string *
query_used_resources()
{
  return m_indices(all) - m_indices(unused);
}

mixed *
query_requiring(mixed resources)
{
  if (!resources)
    return m_values(resources);
  else
  {
    if (stringp(resources))
      resources = ({ resources });
    return 
      m_values(filter_indices(required,
			      lambda(({'r}),
				     ({#'>=,
				       ({#'member,quote(resources),'r}),
				       0}))));
  }
}

mixed *
query_sharing(mixed resources)
{
  if (!resources)
    return m_indices(fold_left(#'+,m_values(shared),([])));
  else 
  {
    if (stringp(resources))
      resources = ({ resources });
    return
      m_indices(
	fold_left(
	  #'+,
	  m_values(filter_indices(shared,
				  lambda(({'r}),
					 ({#'>=,
					   ({#'member,
					     quote(resources),
					       'r
					   }),
					   0})))),
	  ([])));
  }
}

mixed *
query_requirer(mixed resources)
{
  return query_requiring(resources) + query_sharing(resources);
}

static void
free_all_resources()
{
  mixed h;
  int i;
  h = query_required_resources();
  for (i = sizeof(h); i--; )
    m_delete(required,h[i]);
  free += mkmapping(h);
  h = query_shared_resources();
  for (i = sizeof(h); i--; )
    m_delete(shared,h[i]);
  free += mkmapping(h);
}
