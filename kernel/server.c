/* NOTE:
 * Despite the length of this code, the only outside calls made are from
 * call_unguarded(). call_other()s to other object will be extremely
 * dangerous since they imply an unguarded() call.
 */
#pragma strong_types
#pragma no_shadow
#pragma no_inherit
#pragma no_clone
#pragma pedantic

#include "/kernel/defs.h"

inherit ACCESS;
inherit "/kernel/support/name";

#define ERR_PRIV      "insufficient privilege"
#define ERR_NODOMAIN  "accessing non-existing domain"
#define ERR_NOWIZ     "referring to non-existing wizard"
#define ERR_BADARG    "illegal or unusable parameter"
#define ERR_HAZARD    "hazardous setting of privileges"

private mapping privileges;   // mapping containing all privileges
                              // values are arrays of parents and children
private mapping read_access;  // maps directory -> protection level
private mapping write_access; // maps directory -> protection level
private mapping quota;        // maps wizard/domain names -> quota size
private mapping wizards;      // mapping containing all wizards and their level
private mapping domains;      // maps domains->mappings of members/lords
                              // (valued 2 for lords, 1 for members)
private mapping domainlists;  // wizard->domains
private mapping compatible;   // all wizards/domains that don't know about the
                              // new system


#define ACCESS_HISTORY_SIZE 10
private static string *access_history; // to record check_privilege() failures

private void
save_data()
{
#if 0
  unguarded(1,#'save_object,"/kernel/access");
  unguarded(1,#'save_object,"/kernel/access_backup");
#else
  save_object("/kernel/access");
  save_object("/kernel/access_backup");
#endif
}

private void
syslog(string text)
{
#if 0
  unguarded(1,#'write_file,
            ({ "/kernel/LOG",
               ctime()+": " +(this_interactive() ?
                              this_interactive()->query_vis_name() :
                              "<Server>") + ": " + text + "\n" }));
#else
  write_file("/kernel/LOG",
             ctime() +
             ": " + (this_interactive() ?
                     this_interactive()->query_vis_name() :
                     "<Server>") +
             ": " + text + "\n");
#endif
}

void
reset(int arg)
{
  if (arg || clonep(this_object()))
    return;
  set_privilege(1);
  // The following call is handled specially in the master. Using unguarded()
  // is impossible, since variables are not yet initialized
  if (!restore_object("/kernel/access"))
  {
    if (get_eval_cost() < 1000) // *sigh*
      for (;;);
    privileges = ([ ]);
    read_access = m_allocate(0,2);
    write_access = m_allocate(0,2);
    quota = ([ ]);
    domains = ([ ]);
    domainlists = ([ ]);
    wizards = ([ ]);
    compatible = m_allocate(0,0);
    save_data();
    return;
  }
  if (!sizeof(read_access))
    read_access = m_allocate(0,2);
  if (!sizeof(write_access))
    write_access = m_allocate(0,2);
  if (!sizeof(compatible))
    compatible = m_allocate(0,0);
}

int
query_prevent_shadow()
{
  return 1;
}

// This function has to be private, otherwise somebody might gain write
// access to the server's datastructures
private mixed *
walk_path(string file, int write)
{
  string *path;
  mixed *result;
  mapping node, subnode;
  int i;

  path = explode(file,"/")-({"","."});
  if (!sizeof(path))
    return 0;
  if (member(path, "..") >= 0)
    return 0;
  result = allocate(sizeof(path));
  node = write ? write_access : read_access;
  result[0] = !!write;
  for (i=1;i<sizeof(result);i++)
  {
    if (!m_contains(&(result[i]),&subnode,node,path[i-1]))
    {
      result[i]=-1;
      break;
    }
    if (!subnode)
      break;
    if (!sizeof(subnode))
    {
      node[path[i-1],1]=0;
      break;
    }
    node = subnode;
  }
  if (i == sizeof(result))
    --i;
  return ({ result, path[0..<2], i });
}

nomask mixed
query_protection(mixed file, int write)
{
  mixed *desc;
  int i;

  if (objectp(file))
    file = object_name(file);
  desc = walk_path(file, write);
  if (!desc)
    return !!write;  // root directory
  i = desc[2];
  desc = desc[0];
  while (desc[i] == -1)
    --i;
  return desc[i];
}

nomask varargs int check_privilege(mixed priv, int ignore);
nomask int higher_privilege(mixed a, mixed b);
nomask int valid_privilege(mixed priv);

nomask string
set_protection(string file, int write, mixed prot)
{
  mixed *desc;
  int i, j;
  mixed *priv;
  string *path;
  mapping node, subnode;

  desc = walk_path(file + "/foo", write);
  if (sizeof(desc[1]) > 6)
    return ERR_BADARG;
  if (prot != -1 && !valid_privilege(prot))
    return "invalid privilege identifier";
  if (stringp(prot) && prot[0] == '#')
    return "invalid privilege identifier";
  if (!desc)
    return "trying to change root directory's privilege";
  priv = desc[0];
  i = desc[2];
  while (priv[i]==-1)
    i--;
  if (i)
  {
    j = i-1;
    while (priv[j]==-1)
      j--;
  }
  else
    j = i;
  if (priv[i]==prot)
    return "directory already has this effective protection level";
  if (write && !check_privilege(priv[sizeof(desc[1])==i ? j : i]))
    return ERR_PRIV;
  if (!write && !check_privilege(1)) // Only staff can make read restrictions
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  if (prot != -1)
  {
    if (write && higher_privilege(prot,priv[i]))
      return ERR_HAZARD;
    if (!write && higher_privilege(priv[i],prot))
      return ERR_HAZARD;
    node = write ? write_access : read_access;
    path = desc[1];
    for (i=0; i<sizeof(path)-1; i++)
    {
      if (!member(node,path[i]))
        node += ([ path[i]:-1;subnode = m_allocate(1,2) ]);
      else if (!(subnode = node[path[i],1]))
        node[path[i],1] = subnode = m_allocate(1,2);
      node = subnode;
    }
    node[path[<1],0]=prot;
    save_data();
    return 0;
  }
  else
  {
    if (desc[2] != sizeof(desc[1]))
      return "directory not linked to a privilege level";
    node = write ? write_access : read_access;
    path = desc[1];
    for (i=0; i<sizeof(path)-1; i++)
      node = node[path[i],1];
    m_delete(node,path[<1]);
    save_data();
    return 0;
  }
}

nomask string
set_quota(string name, int amount)
{
  if (!member(quota,name))
    return ERR_NOWIZ;
  if (!check_privilege(1)) // Only staff can set quota
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  quota[name] = amount;
  save_data();
  return 0;
}

private int
valid_domain_name(string name)
{
  int *temp;

  temp = to_array(name)[0..strlen(name)-1];
  if (!sizeof(temp))
    return 0;
  temp -= ({ 'a', 'b', 'c', 'd', 'e', 'f',
             'g', 'h', 'i', 'j', 'k', 'l',
             'm', 'n', 'o', 'p', 'q', 'r',
             's', 't', 'u', 'v', 'w', 'x',
             'y', 'z', '-', '_' });
  return !sizeof(temp);
}

nomask varargs string
create_domain(string domain)
{
  if (!check_privilege(1)) // Only staff can create domains
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  if (!valid_domain_name(domain))
    return "invalid domain name";
  domain = lower_case(domain);
  if (domains[domain])
    return "domain already exists";
  domains[domain] = ([ ]);
  privileges[capitalize(domain)] = ([ "":({}),":":({}) ]);
  quota[capitalize(domain)] = 8;
  save_data();
  syslog("Created domain " + domain);
  return 0;
}

nomask string
delete_domain(string domain)
{
  string *members;
  int i;

  if (!check_privilege(1)) // Only staff can delete domains
    return ERR_PRIV;
  if (get_eval_cost() < 10000)
    for (;;);
  if (!domains[domain])
    return ERR_NODOMAIN;
  members = m_indices(domains[domain]);
  for (i=0; i<sizeof(members); i++)
  {
    mapping m;

    m = domainlists[members[i]];
    m_delete(m,domain);
  }
  m_delete(domains,domain);
  save_data();
  syslog("Deleted domain " + domain);
  return 0;
}

nomask string
add_domain_member(string domain, string member, int lord)
{
  if (!domains[domain])
    return ERR_NODOMAIN;
  if (!wizards[member])
    return ERR_NOWIZ;
  if (!check_privilege(capitalize(domain)))
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  domains[domain][member] = (lord ? 2 : 1);
  if (domainlists[member])
    domainlists[member] += ([ domain ]);
  else
    domainlists[member] = ([ domain ]);
  save_data();
  if (lord)
    syslog("Made " + member + " lord of " + domain);
  else
    syslog("Made " + member + " member of " + domain);
  return 0;
}

nomask string
remove_domain_member(string domain, string member)
{
  if (!domains[domain])
    return ERR_NODOMAIN;
  if (!domains[domain][member])
    return ERR_NOWIZ;
  if (!check_privilege(capitalize(domain)))
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  m_delete(domains[domain],member);
  m_delete(domainlists[member],domain);
  save_data();
  syslog("Removed " + member + " from domain " + domain);
  return 0;
}

nomask string
create_wizard(string wizard)
{
  wizard = to_real_name(wizard);
  if (!valid_name(wizard))
    return "invalid character name";
  if (wizards[wizard])
    return "this character is already recorded as a wizard";
  if (!check_privilege(1)) // Only staff can create wizards
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  wizards[wizard] = 1;
  privileges[wizard] = ([ "":({}),":":({}) ]);
  quota[wizard] = 8;
  save_data();
  syslog("Created wizard " + wizard);
  return 0;
}

nomask string
delete_wizard(string wizard)
{
  mixed d;

  if (!wizards[wizard])
    return ERR_NOWIZ;
  if (!check_privilege(1)) // Only staff can delete wizards
    return ERR_PRIV;
  if (get_eval_cost() < 10000)
    for (;;);
  m_delete(wizards,wizard);
  m_delete(privileges,wizard);
  d = domainlists[wizard];
  if (d)
  {
    int i;

    d = m_indices(d);
    for (i=0; i<sizeof(d); i++)
      m_delete(domains[d[i]],wizard);
  }
  save_data();
  syslog("Deleted wizard " + wizard);
  return 0;
}

nomask string
create_admin(string wizard)
{
  if (!wizards[wizard])
    return ERR_NOWIZ;
  if (!check_privilege(1)) // Only staff can create staff
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  wizards[wizard] = 2;
  save_data();
  syslog("Created admin " + wizard);
  return 0;
}

nomask string
delete_admin(string wizard)
{
  if (!wizards[wizard])
    return ERR_NOWIZ;
  if (!check_privilege(1)) // Only staff can delete staff
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  wizards[wizard] = 1;
  save_data();
  syslog("Deleted admin " + wizard);
  return 0;
}

private string
get_priv_owner(string priv)
{
  int n;

  if (!stringp(priv))
    return 0;
  n = member(priv, ':');
  if (n >= 0)
    priv = priv[0..n-1];
  if (!privileges[priv])
    return 0;
  return priv;
}

nomask string
define_privilege(string priv)
{
  string owner, long_priv;
  owner = get_priv_owner(priv);
  if (!owner)
  {
    if (priv[0] != '@' || member(priv, ':') >= 0)
      return "invalid privilege identifier";
    if (!check_privilege(1)) // Only staff can define privileges
      return ERR_PRIV;
    if (get_eval_cost() < 1000)
      for (;;);
    privileges[priv] = ([ "": ({ }), ":": ({ }) ]);
    save_data();
    syslog("Defined privilege " + priv);
    return 0;
  }
  if (!check_privilege(owner))
    return ERR_PRIV;
  if (get_eval_cost() < 1000)
    for (;;);
  long_priv = priv;
  priv = priv[strlen(owner)..];
  if (privileges[owner][priv])
    return "attempt to redefine privilege";
  privileges[owner][priv] = ({ });
  save_data();
  syslog("Defined privilege " + long_priv);
  return 0;
}

nomask string
undefine_privilege(string priv)
{
  mixed owner;

  owner = get_priv_owner(priv);
  if (!owner)
    return "invalid privilege identifier";
  if (strlen(owner)+1 >= strlen(priv))
  {
    if (!check_privilege(1))
      return ERR_PRIV;
  }
  else
  {
    if (!check_privilege(owner))
      return ERR_PRIV;
  }
  if (get_eval_cost() < 1000)
    for (;;);
  if (owner == priv)
    m_delete(privileges,priv);
  else
  {
    mapping list;

    list = privileges[owner];
    if (!list[priv[strlen(owner)..]])
      return "invalid privilege identifier";
    m_delete(list,priv[strlen(owner)..]);
  }
  save_data();
  syslog("Undefined privilege " + priv);
  return 0;
}

nomask mapping
query_privilege_list(string priv)
{
  mapping list, result;
  string *subs;
  int i;

  if (!(list = privileges[priv]))
    return 0;
  result = ([ ]);
  subs = m_indices(list);
  for (i=0; i<sizeof(subs); i++)
    result[priv+subs[i]] = list[subs[i]][0..];
  return result;
}

private mapping deep_copy(mapping m);

private void
assign_deep_copy(string key, mixed priv, mapping sub)
{
  if (sizeof(sub))
    sub = deep_copy(sub);
  else
    sub = 0;
}

private mapping
deep_copy(mapping m)
{
  m = copy(m);
  walk_mapping(m, #'assign_deep_copy);
  return m;
}

nomask mapping
query_access_tree(string path, int write)
{
  mapping result;
  string *p;
  int i;
  mixed priv;
  mapping sub;

  p = explode(path,"/")-({"","."});
  if (write)
    result = write_access;
  else
    result = read_access;
  if (!sizeof(p))
    return deep_copy(result);
  for (i=0; i<sizeof(p)-1 && sizeof(result); i++)
    result = result[p[i],1];
  if (sizeof(result) && m_contains(&priv,&sub,result,p[<1]))
    return ([ p[<1] : priv == -1
                        ? query_protection(path+"/foo",write)
                        : priv;
                      sizeof(sub) && deep_copy(sub) ]);
  else
  return ([ p[<1] : query_protection(path+"/foo",write); 0 ]);
}

nomask string
add_compatible(mixed *priv)
{
  int i;
  mapping list;

  for (i=0; i<sizeof(priv); i++)
    if (!wizards[priv[i]] && !domains[lower_case(priv[i])])
      return "invalid privilege identifier";
  if (!check_privilege(1))
    return ERR_PRIV;
  list = m_allocate(0,0);
  for (i=0; i<sizeof(priv); i++)
    list += ([ priv[i] ]);
  if (get_eval_cost() < 1000)
    for (;;);
  compatible += list;
  save_data();
  return 0;
}

nomask string
remove_compatible(mixed *priv)
{
  int i;
  mapping list;

  for (i=0; i<sizeof(priv); i++)
    if (!member(compatible,priv[i]))
      return "invalid privilege identifier";
  if (!check_privilege(1))
    return ERR_PRIV;
  list = copy(compatible);
  for (i=0; i<sizeof(priv); i++)
    m_delete(list,priv[i]);
  if (get_eval_cost() < 1000)
    for (;;);
  compatible = list;
  save_data();
  return 0;
}

nomask string
extend_access(string priv, string add)
{
  string owner, long_priv;

  owner = get_priv_owner(priv);
  if (!owner || !privileges[owner] || !privileges[owner][priv[strlen(owner)..]])
    return "invalid privilege identifier";
  if (!stringp(add) || !valid_privilege(add))
    return "invalid privilege identifier";
  if (owner == priv)
  {
    if (!check_privilege(1))
      return ERR_PRIV;
  }
  else
  {
    if (!check_privilege(owner))
      return ERR_PRIV;
  }
  if (get_eval_cost() < 1000)
    for (;;);
  long_priv = priv;
  priv = priv[strlen(owner)..];
  privileges[owner][priv] -= ({ add });
  privileges[owner][priv] += ({ add });
  save_data();
  syslog("Opened " + long_priv + " for " + add);
  return 0;
}

nomask string
restrict_access(string priv, string remove)
{
  string owner, long_priv;

  owner = get_priv_owner(priv);
  if (!owner || !privileges[owner] || !privileges[owner][priv[strlen(owner)..]])
    return "invalid privilege identifier";
  if (owner == priv)
  {
    if (!check_privilege(1))
      return ERR_PRIV;
  }
  else
  {
    if (!check_privilege(owner))
      return ERR_PRIV;
  }
  if (get_eval_cost() < 1000)
    for (;;);
  long_priv = priv;
  if (member(privileges[owner][priv], remove) < 0)
    return "invalid privilege identifier";
  privileges[owner][priv] -= ({ remove });
  save_data();
  syslog("Closed " + long_priv + " for " + remove);
  return 0;
}

nomask int
query_is_wizard(string name)
{
  return wizards[name];
}

nomask int
query_is_admin(string name)
{
  return wizards[name]==2;
}

nomask string *
query_admins()
{
  return m_indices(filter_indices(wizards,lambda(({ 'name, 'wizards }),
         ({ #'==,({ #'[,'wizards,'name }),2 })), wizards));
}

nomask int
query_is_domain(string name)
{
  return !!domains[name];
}

nomask string *
query_domain_members(string domain)
{
  mapping members;

  members = domains[domain];
  return members && m_indices(members);
}

nomask string *
query_domain_lords(string domain)
{
  mapping members;
  string *list;
  int i;

  members = domains[domain];
  if (!members)
    return 0;
  list = m_indices(members);
  for (i=0; i<sizeof(list); i++)
    if (members[list[i]] < 2)
      list[i] = 0;
  return list - ({ 0 });
}

nomask varargs string *
query_domains(string wizard)
{
  mapping d;

  if (!wizard)
    return m_indices(domains);
  if (!wizards[wizard])
    return 0;
  d = domainlists[wizard];
  return d ? m_indices(d) : ({ });
}

nomask int
valid_privilege(mixed p)
{
  int n;
  mapping list;

  if (intp(p))
    return p==0 || p==1;
  n = member(p, ':');
  if (n<0)
    n = strlen(p);
  if (list = privileges[p[0..n-1]])
    return member(list,p[n..]);
  // Test fo == 1 because there is a 0 element at the end.
  return p[0] == '#' &&
         sizeof(to_array(p[1..]) - ({ '0', '1', '2', '3', '4', '5', '6',
                                      '7', '8', '9' }))==1;
}

nomask int
higher_privilege(mixed a, mixed b)
{
  // This is THE central routine of the security system.
  // It determines the security hierarchy
  int m, n;

  if (!valid_privilege(a) || !valid_privilege(b))
    raise_error("Invalid privilege " + a + ", " + b + "\n");
  if (a==b)
    return 1;
  if (intp(a)) {
    if (a)
      return 1;
    return 0;
  }
  else if (intp(b))
  {
    if (!b)
      return 1;
    return 0;
  }
  if (a[0] == '#')
    return b==0;
  if (b[0] == '#')
    return a==1;
  m = member(a, ':');
  if (m<0)
    m = strlen(a);
  n = member(b, ':');
  if (n<0)
    n = strlen(b);
  a = ({ a[0..m-1], a[m..] });
  b = ({ b[0..n-1], b[n..] });
  if (a[0]==b[0]
      && strlen(a[1]) < strlen(b[1])
      && b[1][0..strlen(a[1])-1]==a[1])
    return 1;
  switch (b[0][0])
  {
    case 'A'..'Z':
      if (strlen(a[1])==0 && domains[lower_case(b[0])])
      {
        if (domains[lower_case(b[0])][a[0]] > !strlen(b[1]))
          return 1;
      }
  }
  if (member(privileges[b[0]][b[1]],a[0]+a[1]) >= 0)
    return 1;
  return 0;
}

nomask mixed
reduced_privilege(mixed priv, mixed max)
{
  if (higher_privilege(max,priv))
    return priv;
  return max;
}

nomask mixed
call_unguarded(closure code, mixed args, mixed *handle)
{
  mixed result;
  int stacksize;

  if (function_exists("verify_privilege_granted",previous_object()) != ACCESS)
    return 0; // faked call
  if (!efun::call_other(previous_object(),"verify_privilege_granted",handle))
    return 0; // faked too
  stacksize = caller_stack_depth();
  return apply(code,args);
}

private nomask int
access_failure(int depth, object where, mixed priv)
{
  string user, caller, cause;

  user = this_interactive() ? object_name(this_interactive()) : "<none>";
  cause = where ? object_name(where) : "<none>";
  where = caller_stack_depth() <= depth ? this_interactive()
                                        : previous_object(depth);
  caller = where ? object_name(where) : "<none>";
  if (!access_history)
    access_history = ({ });
  if (sizeof(access_history) > ACCESS_HISTORY_SIZE*4)
    access_history = access_history[4..];
  access_history += ({ user, caller, cause, priv+"" });
  return 0; // always needed
}

nomask string *
query_access_history()
{
  return access_history ? access_history[0..] : ({ });
}

nomask varargs int
check_privilege(mixed prot, int ignore)
{
  int stacksize;
  int i;
  object ob, next;

  if (!prot)
    return 1;
  stacksize = caller_stack_depth();
  next = previous_object(ignore);
  if (next == this_object())
  {                          // special unguarded case
    ignore--;
    next = previous_object(ignore);
  }
  for (i=ignore; i<stacksize; i++)
  {
    ob = next;
    next = previous_object(i+1);
    if (!ob)
      return access_failure(ignore,0,prot);
    if (next == this_object())
    {                        // This call is unguarded
      if ((next = previous_object(i+2)) != ob && next != this_object())
        // The object defining the closure did not call it
        return access_failure(ignore,next,prot);
      if (!next && prot)
        // This object has been destructed
        return access_failure(ignore,next,prot);
      if (function_exists("query_unguarded_privilege",next) != ACCESS)
        // faked
        return access_failure(ignore,next,prot);
      if (!higher_privilege(efun::call_other(next,"query_unguarded_privilege"),
                            prot))
        // insufficient privilege
        return access_failure(ignore,next,prot);
      if (!higher_privilege(query_protection(next,1),prot))
        // privilege higher than maximum allowed value
        return access_failure(ignore,next,prot);
      return 1;
    }
    switch (object_name(ob))
    {
      case MASTER:
      case SIMUL_EFUN:
      case SPARE_SIMUL_EFUN:
      case OBSOLETE_SIMUL_EFUN:
        continue;
    }
    if (function_exists("query_privilege", ob) != ACCESS)
    {
      string temp, temp2;
      if (sscanf(object_name(ob),"players/%s/%s",temp,temp2)==2)
      {
        if (member(compatible,temp))
          return higher_privilege(temp+":",prot)
                 || access_failure(ignore,ob,prot);
      }
      if (sscanf(object_name(ob),"domains/%s/%s",temp,temp2)==2)
      {
        if (member(compatible,capitalize(temp)))
          return higher_privilege(capitalize(temp)+":",prot)
                 || access_failure(ignore,ob,prot);
      }
      return access_failure(ignore,ob,prot);
    }
    if (!higher_privilege(efun::call_other(ob,"query_privilege"),prot))
      return access_failure(ignore,ob,prot);
  }
  ob = this_interactive();
  if (!ob)
    return access_failure(ignore,0,prot);
  if (function_exists("query_privilege",ob) != ACCESS)
    return access_failure(ignore,ob,prot);
  if (!higher_privilege(ob->query_privilege(),prot))
    return access_failure(ignore,ob,prot);
  return 1;
}

