/****************************************************************************
      weapon.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

#include <grammar.h>
#include <message.h>
#include <event.h>
#include <combat.h>
//#include <.h>
//#include <.h>

inherit "basic/create";
inherit "basic/parser";

private static mapping combat_actions;

varargs void
add_combat_action(string action,string *rules,mixed func)
{
  if (member(combat_actions,action))
    return;
  rules=rules || ({ action,
                    action+" at "G_BODYPART" with "G_OBJECT,
                    action+" at "G_LIVING" with "G_OBJECT,
                    action+" "G_OBJECT" at "G_BODYPART,
                    action+" "G_OBJECT" at "G_LIVING,
                    action+" at "G_BODYPART,
                    action+" at "G_LIVING,
                    "with "G_OBJECT" "+action+" at "G_BODYPART,
                    "with "G_OBJECT" "+action+" at "G_LIVING,
                    action+" "G_OBJECT }),
  combat_actions += ([action : rules; func]);
  map(rules,#'add_rule,action,0,"combat");
}

status
parse_combat_sentence(string action)
{
  return parse_sentence(action,"combat");
}

add_combat_action_rule(string action,string *rules)
{
  map(rules,#'add_action_rule,action);
}

// #define USE_ADD_ACTION_RULE
#ifdef USE_ADD_ACTION_RULE

private void
add_combat_action_rules()
{
  walk_mapping(combat_actions,lambda(({ 'action,'rules }),
                                     ({ (#'map),
                                        'rules,#'add_action_rule,'action })));
}

void
init()
{
  add_combat_action_rules();
}

#else

static void
add_combat_action_rules()
{
  walk_mapping(combat_actions,lambda(({ 'action,'rules }),
                                     ({ (#'map),
                                        'rules,#'add_rule,'action })));
}

void
init()
{
  add_actions("parse_combat_action","combat");
}

status parse_combat_action(string s) {
  return parse_sentence(s ? query_verb()+" "+s : query_verb(),"combat");
}

#endif

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

/*
 * The functions below are for the scheduling of the attacks.
 */

private mapping fightplan, active_fightplan;
private static mixed fightplan_key;

static status try_action(mixed action,closure callback);
static void run_action(mapping action,int call_id,closure callback);
static void finish_action(mapping action,int call_id,closure callback);
static void abort_action(mapping action,int call_id,closure callback);

void schedule_first_action(mixed key);
void schedule_next_action(mixed key, int success);

/*
 * This function is used by do_action() to find out the current fightplan_key.
 */
mixed query_fightplan_key() { return fightplan_key; }

/*
 * This function resets the counters of the part of the fightplan referred to
 * by the given key and returns the next (the first) command of it.
 */
string
get_first_command(mixed key)
{
  if (active_fightplan[key])
    return 0;
  fightplan[key,1]=fightplan[key,2]=0;
  return sizeof(fightplan[key,0]) &&
    sizeof(fightplan[key,0][0]) &&
    fightplan[key,0][0][0];
}

/*
 * This function works like get_first_command() but it does not reset the
 * counters first but increments them.
 * Argument skip says whether the next action of the current grouplet (skip=0)
 * or the first of the next grouplet (skip=1) shall be returned.
 * If skip is negative, the counters are not changed.
 */
string
get_next_command(mixed key, int skip)
{
  if (active_fightplan[key])
    return 0;
  if (!skip) {
    fightplan[key,2]=0;
    fightplan[key,1]++;
  }
  else if (skip > 0) {
    fightplan[key,2]++;
    if (fightplan[key,2] >=  // already over the end
        sizeof(fightplan[key][fightplan[key,1]])) {
      fightplan[key,2]=0;
      fightplan[key,1]++;
    }
  }
  // else if (skip < 0) don't move the indices (old command)
  if (fightplan[key,1] >= sizeof(fightplan[key]))  // too far
    fightplan[key,1] = 0;
  return 
    fightplan[key][fightplan[key,1]][fightplan[key,2]];
}

private void
begin_fightplan_action(mixed action_id)
{
  if (fightplan_key && action_id && !member(active_fightplan,fightplan_key))
    active_fightplan[fightplan_key] = action_id;
}

private void
finish_fightplan_action(mixed key, mixed success)
{
  if (key)
  {
    m_delete(active_fightplan,key);
    get_next_command(key,success);
  }
}

/*
 * This function is called by the parsing of the weapon
 * argument action contains data of the action to happen (mapping or closure)
 */
varargs void
schedule_action(mixed action)
{
  begin_fightplan_action(this_player()->
			   enqueue_action(lambda(0,
					  ({#'try_action,
					    action,
					    lambda(({'success}),
					 	   ({#'finish_fightplan_action,
					 	     fightplan_key,
					 	     'success}))}))));
}

/*
 * This function schedules the first action of the fightplan part refrerred
 * to by the given key.
 */
varargs void
schedule_first_action(mixed key)
{
  mixed h;
  if (key)
  {
    if (h = get_first_command(key))
    {
      fightplan_key = key;
      if (intp(fightplan_key))
	command(h,environment());
      else 
	parse_combat_sentence(h);
      fightplan_key = 0;
    }
  }
  else
    filter_indices(fightplan,#'schedule_first_action);
}

/*
 * This function schedules the action that follows the given one (which must
 * be from a fightplan of this weapon).
 */
varargs void
schedule_next_action(mixed key, int success)
{
  string c;
  if (key)
  {
    if (c = get_next_command(key, success))
    {
      fightplan_key = key;
      if (intp(fightplan_key))
	command(c,environment());
      else
	parse_combat_sentence(c);
      fightplan_key = 0;
    }
  }
  else
    filter_indices(fightplan,#'schedule_next_action,success);
}

/*
 * This function is called after an action if done and frees resources of the
 * given action (therefor the call_id).
 */
static void
finish_action(mapping action, int call_id, closure callback)
{
  string *req, *sha;
  if (sizeof(req=action[C_RESOURCES])+sizeof(sha=action[C_SHARED_RESOURCES]))
    this_player()->query_body()->free_resources(req,sha,call_id);
  this_player()->remove_concentration(call_id);
  funcall(callback,action[E_SUCCESS]);
}

/*
 * This function is called by abort() from the coordinator (which itself is
 * called when an action is to be aborted (parry, dodge)). It frees the re-
 * sources allocated by the action and re-schedules the aborted action.
 */
static void
abort_action(mapping action, int call_id, closure callback)
{
  string *req, *sha;
  if (sizeof(req=action[C_RESOURCES])+sizeof(sha=action[C_SHARED_RESOURCES]))
    this_player()->query_body()->free_resources(req,sha,call_id);
  this_player()->remove_concentration(call_id);
  // re-schedule the action
  funcall(callback,-1); // this signifies to schedule the last action again
}

/*
 * This function is called by run_action() and does the game-related things
 * of this action (messages, hit_player, whatever)
 */
void execute_action(mapping action) {
  send_event(action[E_TYPE]||"attack",action,environment(this_player()));
}

/*
 * This function is called by try_action() when it is about to start. It
 * should do all game-related things like messages.
 */
void begin_action(mapping action) {
  send_event("begin_"+(action[E_TYPE]||"attack"),action,
             environment(this_player()));
}

/*
 * This function is given (as closure) by the body to the coordinator and
 * called after the there specified number of ticks. It calls execute_action()
 * in the weapon (this object), frees the resources, starts the postruntime
 * (allocates the resources therefor again and lets finish_action() free them
 * after it again).
 * If you want to have an action consisting of several phases, you will have
 * to overload this for example.
 */
static void
run_action(mapping action,int call_id,closure callback)
{
  mixed h;
  string *req, *sha;
  object body;
  execute_action(action);
  body = this_player()->query_body();
  req = action[C_RESOURCES];
  sha = action[C_SHARED_RESOURCES];
  h = COMBAT->schedule_call(funcall(action[C_POSTRUNTIME]),
                            lambda(({'call}),
                                   ({#'finish_action,
                                     action,
                                     'call,
				     callback})));
  if (sizeof(req)+sizeof(sha))
  {
    body->free_resources(req,sha,call_id);
    body->require_and_share_resources(req,sha,h);
  }
}

mapping
build_action_mapping(string action, mapping args)
{
  return ([E_TYPE: action]);
}

mapping
build_action_event(mapping action)
{
  return copy(action);
}

string
action_failure(mapping action)
{
  return 0;
}

static status
can_do_action(mapping action)
{
  mixed msg;
  string *req, *sha;
  object body;
  req = action[C_RESOURCES];
  sha = action[C_SHARED_RESOURCES];
  body = this_player()->query_body();
  if (sizeof(req)+sizeof(sha) && !(body && body->has_resources(req+sha)))
    return 0;
  if (action[E_TYPE] == "attack" && 
      !(action[E_TARGET] && accessible(action[E_TARGET],this_player())))
    return 0;
  if (msg = action_failure(action))
    return send_message(msg), 0;
  return 1;
}

static status
can_do_action_now(mapping action)
{
  if (action[E_TYPE] == "attack")
  {
    if (!this_player()->can_attack(action[E_TARGET],action[E_RANGE]))
      return 0;
  }
  if (this_player()->query_concentration() < action[C_CONCENTRATION])
    return 0;
  if (sizeof(action[C_RESOURCES])+sizeof(action[C_SHARED_RESOURCES]))
    if (!this_player()->query_body()->
	  can_substitute_resources(&(action[C_RESOURCES]),
				   &(action[C_SHARED_RESOURCES])))
      return 0;
  return 1;
}

/*
 * This function is thought to be given to the body (as closure), tries to
 * allocate the needed resources and starts the action eventually (calls
 * begin_action() in the weapon (itself) and so on).
 */
static status
try_action(mixed action,closure callback)
{
  int call_id;
  mixed h;
  string *req,*sha;
  object body;
  h = funcall(action);  // if this does not return a mapping about the action,
                        // it should already have done everything necessary.
  if (mappingp(h))
  {
    h = build_action_event(h);
    if (!h[C_RESOURCES])
      h[C_RESOURCES] = ({});
    if (!h[C_SHARED_RESOURCES])
      h[C_SHARED_RESOURCES] = ({});
    if (!can_do_action(h))
    {
      funcall(callback,0);
      return 1;
    }
    if (!can_do_action_now(h))
    {
      // send_message(({M_WRITE,"You can't do that now."}));
      return 0;
    }
    body = this_player()->query_body();
    call_id = COMBAT->schedule_call(funcall(h[C_PRERUNTIME],h),
                                    lambda(({'call}),
                                           ({#'run_action,
                                             h,
                                             'call,
					     callback})),
                                    lambda(({'call}),
                                           ({#'abort_action,
                                             h,
                                             'call,
					     callback})));
    if (h[E_SKILL,1])
      h[E_SKILL] = 
	this_player()->test_and_improve_skill(h[E_SKILL,1],h[E_DIFFICULTY]);
    if (sizeof(h[C_RESOURCES])+sizeof(h[C_SHARED_RESOURCES]))
      body->require_and_share_resources(h[C_RESOURCES],
					h[C_SHARED_RESOURCES],call_id);
    if (h[C_CONCENTRATION])
      this_player()->set_concentration(call_id,h[C_CONCENTRATION]);
    begin_action(h);
    return 1;
  }
  return h;
}

//////////////////////////////////////////////////////////////////////

private string
fightplan_line(mixed key)
{
  string result;
  if (stringp(key))
    result = describe(key,ARTICLE_THE,DESCRIBE_SHORT,-1);
  else
    result = to_string(key);
  return result+": "+implode(map(fightplan[key],#'implode,","),";");
}

string
fightplan2string()
{
  mixed h;
  if (fightplan)
  {
    m_delete(fightplan,0);
    h = map_indices(fightplan,#'fightplan_line);
    return break_string(implode(m_values(h),"\n")+"\n");
  }
}

void set_fightplan(mixed key,mixed *plan) {
  if (key && pointerp(plan) && sizeof(plan) &&
      pointerp(plan[0]) && sizeof(plan[0]))
    fightplan[key] = plan;
}

void
create()
{
  combat_actions = ([]);
  fightplan = m_allocate(0,3);
  active_fightplan = ([]);
}

void
add_fightplan_key(mapping args)
{
  if (fightplan_key)
    args[C_FIGHTPLAN_KEY] = fightplan_key;
}

mixed
do_action(string action, mapping args)
{
  mixed h, msg;
  if (member(combat_actions,action))
  {
    if (args[G_OBJECT] && args[G_OBJECT] != this_object())
      return 0;
    if (args[G_LIVING] == this_player() ||
	(args[G_BODYPART] && args[G_BODYPART] == this_player()) ||
	(args[G_INDIRECT] && environment(args[G_INDIRECT]) == this_player()))
      return notify_fail("Attack yourself? No way!\n"), 0;
    if (!(args[G_LIVING] || args[G_BODYPART] || args[G_INDIRECT]))
    {
      if (!(h = this_player()->query_fighting(1)))
	return notify_fail("Attack whom?\n"), 0;
      h = m_indices(filter_indices(h,
				   "should_attack",
				   this_player()->query_body(),
				   this_object()));
      if (sizeof(h))
	args[G_LIVING] = h[random(sizeof(h))];
      else return 0;
    }
    if (h = build_action_mapping(action, args))
      if (msg = action_failure(h))
	return notify_fail(msg), 0;
      else 
	schedule_action(h);
    return 1;
  }
}
