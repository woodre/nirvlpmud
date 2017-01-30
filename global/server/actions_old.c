/*****************************************************************************
            actions.c -- written by Ugh August 1995 for Tubmud
*****************************************************************************/
#include <closures.h>
#include <limits.h>
#include <time_units.h>
#include <grammar.h>
#include <libs.h>

inherit "basic/create";
inherit "basic/stack";
static functions inherit "basic/parser";

//#define IS_DAEMON
#ifdef IS_DAEMON
inherit "basic/daemon";
#endif

/* 
 * a rule which is in the rule-cache isn't necessarily inserted at the
 * right place, yet. 
 */
private mapping rule_cache;     /* verb -> [rule] */
private mapping error_handlers; /* handler -> error */
private mapping rule_handlers;  /* rule -> handler -> player -> 
                                    (action,function) */
private mapping handler_last_refreshed; /* handler -> time-of-refresh */

#define PRESENT_OBS(pl) (environment((pl)) ? \
                         all_inventory((pl)) + \
                         all_inventory(environment((pl))) + \
                         ({ environment((pl)) }) : \
                         all_inventory((pl)) + \
                         ({ (pl) }))

private object *
present_objects(object pl)
{
  mixed h;
  h = PRESENT_OBS(pl);
#if 0
  h +=
    m_indices(mkmapping(flatten_array(map_objects(h,"deep_components") -
                                      ({0})))) - h;
#endif
  return h;
}

private mapping present_rule_handlers = ([]);
private mapping present_error_handlers = ([]);

mixed
notify_error(string sentence,string *words)
{
  int i, prio;
  mixed h, error, result;
  h = top(present_error_handlers[words[0]]);
  present_error_handlers[words[0]] = 
    pop(present_error_handlers[words[0]]);
  prio = -2;
  for (i=sizeof(h); i--; )
    if (h[i] && (error = error_handlers[h[i]][words[0]]))
    {
      if (closurep(error))
        error = funcall(error,sentence,words);
      if (error)
      {
        if ((pointerp(error) && error[1] > prio) ||
            (stringp(error) && prio < 0))
          result = error;
      }
    }
  return result;
}

void
action_error_message_add(string verb,mixed error)
{
  if (!member(error_handlers,previous_object()))
    error_handlers[previous_object()] = 
      ([ verb : error ]);
  else
    error_handlers[previous_object()][verb] = error;
}

/*
 * classes added by foreign objects must contain '#'.
 * Also, there can be no two classes with the same name having 
 * different handler or function.
 */
varargs void
action_class_add(string class,string function,mixed handler)
{
  mixed h;
  if (!stringp(class) || sscanf(class,"<%s#%s>",h,h) != 2 ||
      !stringp(function))
    return;
  if (!handler)
    handler = load_name(previous_object());
  else if (!stringp(handler))
    handler = load_name(handler);
  h = query_classes();
  if (member(h,class) && (function != h[class,1] || handler != h[class,0]))
    raise_error("Can't add class twice with different handler or function.\n");
  add_class(class,function,handler);
}

varargs void
action_class_duplicate(string old,string new)
{
  mixed h;
  if (!stringp(new) || sscanf(new,"<%s#%s>",h,h) != 2)
    return;
  h = query_classes();
  if (member(h,new))
    return;
  duplicate_class(old,new);
}

private closure get_error_function(string sentence,string *words) {
  return lambda(0,({ (#'notify_error),
                     sentence,
                     quote(words) }));
}

varargs void
action_rule_add(string rule,string action,mixed function)
{
  int i;
  mixed h, rules, handlers;
  object handler;
  string verb;

  // is there a space in the rule?
  if ((i = strstr(rule," ")) < 0)
    verb = rule;
  else
    verb = rule[0..i-1];
  rules = query_rules();
  if (!rules[verb] || (i = member(rules[verb][2],rule)) < 0) {
    add_rule(rule,rule,load_name(this_object()));
#if 0  // Alfe 97-Jun-1
    add_error_message(verb,#'notify_error);
#else
    // this is necessary to avoid the side-effects taking place before the
    // matching of the rules because of the change in /basic/parser.c
    add_error_message(verb,#'get_error_function);
#endif
    rule_cache[verb] = query_rules()[verb][2] - ({ rule });
    if (!sizeof(rule_cache[verb]))
      m_delete(rule_cache,verb);
#ifdef IS_DAEMON
    add_command("parse_cmd",verb);
#endif
    clear_shared_mem("action_rules");
    allocate_shared_mem("action_rules",query_rules());
  } else if (rule_cache[verb] && member(rule_cache[verb],rule) >= 0) {
  // not recently inserted at the right place? 
    rules = transpose_array(rules[verb]);
    rule_cache[verb] -= ({ rule });
    handlers = copy(rule_handlers[rule]);
    // append the rule
    rules += rules[i..i];
    rules[i..i] = ({ });
    while (i < sizeof(rules) && rules[i][2] != rule)
    {
      h = rule_handlers[rules[i][2]];
      if (sizeof(handlers + h) < sizeof(handlers) + sizeof(h))
      {
        rule_cache[verb] -= ({ rules[i][2] });
        // append the rule
        rules += rules[i..i];
        rules[i..i] = ({ });
#if 0
        i--;
        handlers += h;
#else
        handlers += h;
        continue;
#endif
      }
      i++;
    }
    if (!sizeof(rule_cache[verb]))
      m_delete(rule_cache,verb);
    clear_shared_mem("action_rules");
    set_rules(allocate_shared_mem("action_rules",
                                  query_rules() + 
                                  ([ verb : transpose_array(rules); 
                                            #'notify_error 
                                  ])));
  }
  handler = previous_object();
  if (!member(rule_handlers,rule))
    rule_handlers[rule] = 
      ([ handler : 
          ([ this_player() : action; function||"do_action" ])
      ]);
  else if (!member((h = rule_handlers[rule]),handler))
    h[handler] = 
      ([ this_player() : action; function||"do_action" ]);
  else 
    h[handler] +=
      ([ this_player() : action; function||"do_action" ]);
#if 1
  if (!member(handler_last_refreshed,handler))
    handler_last_refreshed[handler] = time();
#endif
}

private void
action_remove(string rule,mapping handlers,object handler)
{
  if (handlers[handler])
    m_delete(handlers[handler],this_player());
}

varargs void
action_rule_remove(mixed rules)
{
  mixed h;
  if (!rules)
    walk_mapping(rule_handlers,#'action_remove,previous_object());
  else 
  {
    if (stringp(rules))
      rules = ({ rules });
    h = filter_indices(rule_handlers,
                       lambda(({'rule}),
                              ({#'>,
                                ({#'member_array,'rule,rules}),
                                -1
                              })));
    walk_mapping(h,#'action_remove,previous_object());
    rule_handlers += h;
  }
}

void
create()
{
  if (rule_handlers)
    return;
  rule_handlers = allocate_shared_mem("action_rule_handlers",([ ]));
  handler_last_refreshed =
    allocate_shared_mem("action_handler_last_refreshed",([ ]));
  rule_cache = allocate_shared_mem("action_rule_cache",([ ]));
  error_handlers = allocate_shared_mem("action_error_handlers",([ ]));
  set_classes(allocate_shared_mem("action_classes",m_allocate(0,2)));
  set_rules(allocate_shared_mem("action_rules",m_allocate(0,2)));
#ifdef IS_DAEMON
  filter(query_rule_verbs(),
               lambda(({'verb}),({#'add_command,"parse_cmd",'verb})));
#endif
#if 0  // Alfe 97-Jun-1
  filter(query_rule_verbs(),#'add_error_message,#'notify_error);
#else
  // the reason for this: same as above use of add_error_message()
  filter(query_rule_verbs(),#'add_error_message,#'get_error_function);
#endif
}

static mixed 
do_action(string rule, mapping args)
{
  mixed h, result;
  string verb;
  object *handlers;
  int i;
  // is there a space in the rule?
  if ((i = strstr(rule," ")) < 0)
    verb = rule;
  else
    verb = rule[0..i-1];
  h = rule_handlers[rule];
  // delete destructed objects
  if (h)
    m_delete(h,0);
  // any handlers for this rule?
  if (!h || !sizeof(h))
  {
    // no? then remove it
    remove_rule(verb,rule);
    if (h)
      m_delete(rule_handlers,rule);
    return 0;
  }
  // which of the present objects is a handler of that rule?
  handlers = top(present_rule_handlers[rule]);
  present_rule_handlers[rule] = pop(present_rule_handlers[rule]);
  for (i = sizeof(handlers); !result && i; i--)
    if (handlers[<i] && h[handlers[<i]][this_player()])
      if (closurep(h[handlers[<i]][this_player(),1]))
        result = funcall(h[handlers[<i]][this_player(),1],
                         h[handlers[<i]][this_player()],
                         args);
      else
        result = call_other(handlers[<i],
                            h[handlers[<i]][this_player(),1]||"do_action",
                            h[handlers[<i]][this_player()],
                            args);
  // we can throw away the error handlers if there was a result
  if (result)
    present_error_handlers[verb] = pop(present_error_handlers[verb]);
  return result;
}

private void
get_action_rules(string verb,mixed *r,mixed error,mapping result)
{
  result[verb] = r[2][0..];
}

public mapping
query_action_rules()
{
  mixed h;
  h = ([]);
  walk_mapping(query_rules(),#'get_action_rules,h);
  return h;
}

private void
get_rule_action(object handler, mixed actions, object player)
{
  if (actions[player])
    actions = ({ actions[player], actions[player,1] });
  else
    actions = 0;
}

private mixed
get_rule_handler(string rule, object handler, object player)
{
  mixed h, obs;
  h = rule_handlers[rule];
  if (handler)
    if (!h[handler])
      return 0;
    else
      h = ([ handler : h[handler] ]);
  else
  {
    obs = mkmapping(present_objects(player));
    h = filter_indices(h,lambda(({'ob}),({#'member,obs,'ob})));
  }
  walk_mapping(h,#'get_rule_action,player);
  return h;
}

private void
get_rule_handlers(string verb, string *rules, object handler, object player)
{
  mixed h;
  h = filter(map(rules,#'get_rule_handler,handler,player)-({0}),
                   (#'sizeof));
  rules = h;
}

public varargs mixed
get_actions(object handler, string verb, object player)
{
  mixed h;
  if (!player)
    player = this_player();
  h = with_player(player,#'query_action_rules);
  if (verb)
    if (h[verb])
      h = ([ verb : h[verb] ]);
    else
      h = 0;
  if (h)
  {
    walk_mapping(h,#'get_rule_handlers,handler,player);
    h = filter_indices(h,lambda(({'x}),({#'sizeof,({CL_INDEX,h,'x})})));
  }
  return h;
}

// static 
varargs mixed
query_rules(string verb,string family)
{
  int i;
  mixed h;
  object *obs, *handlers;
  h = parser::query_rules(verb,family);
  if (verb && h)
  {
    obs = present_objects(this_player());
    present_error_handlers[verb] = 
      push(filter(obs,error_handlers),present_error_handlers[verb]||({}));
    h = transpose_array(h);
    for (i=sizeof(h); i--; )
    {
      handlers = filter(obs,rule_handlers[h[i][2]]);
      if (sizeof(handlers))
        present_rule_handlers[h[i][2]] = 
          push(handlers,present_rule_handlers[h[i][2]]||({}));
      else
        h[i..i] = ({ });
    }
    if (!sizeof(h))
      return ({ ({ }), ({ }), ({ }) });
    else
      return transpose_array(h);
  }
  else
    return h;
}

public mixed
parse_action(string str)
{
  int i;
  i = caller_stack_depth();
  while (i--)
    if (previous_object(i) == this_object())
      break;
  if (i < 0)
  {
    present_rule_handlers -= mkmapping(m_indices(present_rule_handlers));
    present_error_handlers -= mkmapping(m_indices(present_error_handlers));
  }
  return parser::parse_action(str);
}

#ifdef IS_DAEMON
static mixed
parse_cmd(string str,string verb)
{
  int i;
  i = caller_stack_depth();
  while (i--)
    if (previous_object(i) == this_object())
      break;
  if (i < 0)
  {
    present_rule_handlers -= mkmapping(m_indices(present_rule_handlers));
    present_error_handlers -= mkmapping(m_indices(present_error_handlers));
  }
  return parse_sentence(str ? verb+" "+str : verb);
}
#endif

void
reset_actions()
{
  if (!check_previous_privilege(1))
    return;
  clear_shared_mem("action_rule_handlers");
  clear_shared_mem("action_handler_last_refreshed");
  clear_shared_mem("action_error_handlers");
  clear_shared_mem("action_rule_cache");
  clear_shared_mem("action_rules");
  clear_shared_mem("action_classes");
  rule_handlers = 0;
  create();
}

void
action_class_remove(string c)
{
  if (check_previous_privilege(1))
    parser::remove_class(c);
}

void
action_remove_rule(string r)
{
  if (check_previous_privilege(1))
  {
    parser::remove_rule(0,r);
    m_delete(rule_handlers,r);
  }
}

void
action_remove_rules(string verb)
{
  int i;
  mixed h;
  if (check_previous_privilege(1))
  {
    h = parser::query_rules(verb)[2];
    for (i = sizeof(h); i--; )
    {
      parser::remove_rule(0,h[i]);
      m_delete(rule_handlers,h[i]);
    }
  }
}

mixed
query_rule_handlers()
{
  return rule_handlers;
}

private void
clean_handler_from_living(object handler,mapping a,object l)
{
  if (a && member(a,l))
    m_delete(a,l);
  else
    a = 0;
}

private void
clean_not_present_handlers_from_living(string rule,mapping handlers,
                                       mapping present_handlers,object l)
{
  mixed h;
  if (handlers)
  {
    // subtract the present handlers
    h = handlers - present_handlers;
    // delete the living for each non-present handler
    walk_mapping(h,#'clean_handler_from_living,l);
    // overwrite the changed entries
    h = filter_indices(h,lambda(({'x}),({CL_INDEX,h,'x})));
    handlers += h;
  }
}

private void
clean_handler_from_livings(string rule,mapping handlers,
                           object handler,mapping livings)
{
  mixed h;
  if (handlers && (h = handlers[handler]))
    h = filter_indices(h,lambda(({'x}),({#'member,livings,'x})));
}

void
refresh_rule_handler(object o)
{
  mixed h;
  h = mkmapping(present_objects(o));
  if (living(o))
    walk_mapping(rule_handlers,#'clean_not_present_handlers_from_living,h,o);
  walk_mapping(rule_handlers,#'clean_handler_from_livings,o,h);
  // save time of last refreshing
  handler_last_refreshed[o] = time();
}

// the arguments counter and result are passed by reference
private status
random_choose(mixed key, int rand, int *counter_result)
{
  if (!counter_result[1])
  {
    if (rand==counter_result[0])
      return counter_result[1] = 1;
    counter_result[0]++;
  }
}

object
select_refresh_handler()
{
  mixed h;
  int i,r;
  // get those handlers which haven't been refreshed in a day
  h = filter_indices(handler_last_refreshed,
                     lambda(({'x}),
                            ({#'>,
                              time(),
                              ({#'+,
                                ({CL_INDEX,handler_last_refreshed,'x}),
                                ONE_DAY})})));
  // choose one key at random from the mapping
  // this looks rather complicated because the mapping's size
  // may well exceed the boundary of MAX_ARRAY_SIZE and thus
  // a simple m_indices() wouldn't be working
  if (sizeof(h))
  {
    h = filter_indices(h,#'random_choose,random(sizeof(h)),({ 0,0 }));
    return m_indices(h)[0];
  }
}

void
refresh()
{
  mixed h;
  while ((get_eval_cost() > MAX_COST-100000) &&
         (h = select_refresh_handler()))
    refresh_rule_handler(h);
}
