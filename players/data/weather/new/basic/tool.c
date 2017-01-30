/****************************************************************************
                tool.c -- written by Ugh and Alfe
****************************************************************************/
// A tool is something with which one can do one or more actions.
// This class provides the possibility to 'plan' ahead in the execution
// of actions.
// Also, it provides the possibility for actions which have a duration
// and to allocate resources, thus preventing other actions needing the
// same resources at the same time.

#include <event.h>
#include <closures.h>
#include <bodypart.h>
#include <action.h>
#include <combat.h>
#include <grammar.h>
#include <assert.h>

// the living using us
#define TOOL_USER (this_object()->get_user() || this_player() || environment())

#ifndef E_PRIORITY
#define E_PRIORITY "priority"
#endif

virtual inherit "basic/parser";

status query_tool() { return 1; }

object get_user();

// The following functions are for manipulating the data-structures above
void insert_next_action(mapping action, int mode);
void set_running_action(mapping action);
void set_current_action(mapping action);
void reset_next_actions();
void reset_running_action();
void reset_current_action();

mapping first_next_action();
mapping dequeue_next_action();
mapping get_running_action();
mapping get_current_action();

void try_schedule_next_action(status delay);
static void abort_running_action();  // static added, Coogan, 11-Oct-2001
status try_abort_running_action();
void abort_current_action();  // changed to void, Coogan, 18-Oct-2000
mapping interrupt_running_action();
static status start_current_action(status delay);
                                         // static added, Coogan, 11-Oct-2001

/********************************* Building **********************************/

// This function makes a concrete action event from an abstract action-mapping
static mapping build_action_event(mapping action) {
  return action;
}

// This function takes a _very_ rudimentary action-mapping and
// fills it with additional data depending on the action and the
// parsed arguments
// It is meant to be overloaded, so that abstract action-classes
// can implement it
mapping build_complete_action(mapping action, mapping args) {
  return action;
}

// This function should take the parsing result and return a 
// mapping that (abstractly) describes the action, so later on it
// can be instantiated in a more concrete form
// For instance, if the user just typed 'kick', it is inconclusive
// (at the moment) who should be kicked. Therefore, only in the moment
// that the kick should actually occur should an opponent be chosen.
// But, other things like 'what should be done', 'what is used', 
// 'what is needed', 'which skills should be tested', 'who is doing it' etc.
// can already be filled in here
// ATTENTION: This function also handles the building of planned actions
// which have a prefix (A_PLANNED_) prepended to the actual action.
// So, do not overload this function, but instead overload the function
// build_complete_action which is called at the end of this function
varargs mapping build_action(string action, mapping args, int mode) {
  mixed h;
  status action_planned;

  if (args && args[A_G_TOOL] && args[A_G_TOOL] != this_object())
    return 0;
  // planned actions all have the prefix prepended to their 'normal'
  // action-identifier
  h = regexplode(action,A_PLANNED_);
  if (sizeof(h) >= 3) {
    h[1..1] = ({});
    action = implode(h,"");
    action_planned = 1;
  }
  h = 
    ([E_TYPE   : "action"; "action",
      E_ACTION : action; action_planned,
      E_AGENT  : this_player();
                 this_player()->query_real_name() ||
                 this_player()->query_name(),
      E_TOOL   : this_object(); this_object()->query_name(),
      E_MODE   : mode; 0]);
  return
    build_complete_action(h,args || m_allocate(0,2));
}

/************************* Scheduling ************************************/

// This function is called when the next action should become the current
// action.
status prepare_action(mapping action, status delay) {
  mapping preparations;

  if (!(action || (action = get_current_action())))
    return 0;

  set_current_action(action);
  return start_current_action(delay);
}

status query_action_scheduled() {
  return (get_running_action() || get_current_action()) && 1;
}

// This function should schedule the next action to be the current action.
// The return value says whether a new action has been scheduled.
status schedule_next_action(status delay) {
  mixed failure;
  mapping action;

  // If there is still a current action (prepared or running),
  // abort scheduling of next one
  if (query_action_scheduled())
    return 0;
  // Do we have a next action from the tool-user?
  if (action = dequeue_next_action())
    return prepare_action(action, delay);
  else 
    return
      TOOL_USER->plan_next_action() &&
      query_action_scheduled();
}

// This function returns true, if a next action should be scheduled
// That should be the case, if the user requested it (e.g. typed a command),
// but otherwise should be false, if the user isn't fighting anymore
// (if this is a fighting tool)
status should_schedule_next_action() {
  return
    first_next_action() ||
    TOOL_USER->should_plan_next_action();
}

void try_schedule_next_action(status delay) {
  if (delay) { 
    if (find_call_out("try_schedule_next_action") < 0)
      call_out("try_schedule_next_action", 0, 0); // undelayed
  } else {
    if (should_schedule_next_action()) 
      schedule_next_action(delay);
    else 
      reset_next_actions();
  }
}

status schedule_action(mapping action) {
  mixed h;

  if (action[E_TOOL] != this_object())
    raise_error("scheduling action for other tool: "+
                object_name(action[E_TOOL])+"\n");
  switch (action[E_MODE]&A_MODE_INTERRUPT) {
    case A_MODE_INTERRUPT:
      // This will cause the current/prepared action to be interrupted
      // (if possible, and if that is not an interrupt-action itself)
      // and rescheduled at the beginning (after this action)
      if ((h = get_running_action()) && !(h[E_MODE]&A_MODE_INTERRUPT)) {
        if (h = interrupt_running_action()) {
          insert_next_action(h,A_MODE_INTERRUPT);
        }
      }
    // fall through
    default:
      // This will append the action at the end of the appropriate queue
      insert_next_action(action, 0);
    break;
  }
  // Schedule this new action, if no current/prepared action is running
  return query_action_scheduled() || schedule_next_action(0);
}

// abort the currently running action
// Although this normally aborts the current action only, if it is
// possible, the function precede_action() should only
// be called if the current action isn't running, yet
// If the current aciton _is_ already running and not abortable,
// the prescheduled action will not be scheduled
status precede_action(mapping action, mixed before) {
  if (!before)
    before = this_object();
  else if (mappingp(before))
    before = before[E_TOOL];
  if (objectp(before)) 
    before = before->stall_running_action();
  action[E_SUCCESS,1] = before;
  return schedule_action(action); 
}

varargs status preschedule_next_action(mapping action, mixed before) {
  return precede_action(action,before);
}

status reschedule_running_action() {
  mixed h;

  if (h = interrupt_running_action()) {
    insert_next_action(h,A_MODE_INTERRUPT);
    return 1;
  }
}

public mapping stall_running_action() {
  mixed h;

  if (h = get_running_action())
    h[A_STALLED] = 1;
  // debug("ugh", h[E_TOOL]->query_name()+": stalled "+h[E_ACTION]);
  return interrupt_running_action();
}

public void continue_stalled_action(status success, mapping action) {
  if (success) {
    action[A_STALLED] = 0;
    if (action[E_ID,1]) // save the planned flag
      action[E_ACTION,1] = action[E_ID,1][E_ACTION,1];
    insert_next_action(action,A_MODE_INTERRUPT);
  }
  try_schedule_next_action(1);
}

status query_equal_actions(mapping a1, mapping a2) {
  if (a1[E_ACTION] == a2[E_ACTION]) {
    // still _very_ crude
    return 1;
  }
}

// compare the given action with the scheduled ones and abort
// the first action that resembles the given action enough
int stop_action(mapping action) {
  mapping a;

  if (a = get_running_action()) {
    if (query_equal_actions(action,a))
      return try_abort_running_action(), 1;
  } else if (a = get_current_action()) {
    if (query_equal_actions(action,a))
      return abort_current_action(), 1;
  } else {
    // TODO: not implemented yet
  }
  return 0;  // Coogan, 27-Mar-2011
}

int do_action(string action, mapping args) {
  int i;
  mixed h, mode;
  status stop;

  // scan for "STOP_", "FAST_", "INTERRUPT_"
  h = regexplode(action,A_STOP_"|"A_FAST_"|"A_INTERRUPT_);
  if (sizeof(h) >= 3) {
    for (i = 1; !stop && !mode && i < sizeof(h); i+=2) {
      switch (h[i]) {
      case A_STOP_:
        stop = 1;
        break;
      case A_FAST_:
        mode = A_MODE_FAST;
        break;
      case A_INTERRUPT_:
        mode = A_MODE_INTERRUPT;
        break;
      }
      h[i..i] = ({});
      i--;
    }
    action = implode(h,"");
  }
  if (h = build_action(action, args, mode)) {
    if (stop) {
      TOOL_USER->notify_stop_action(h);
      return stop_action(h);
    } else {
      h[E_SUCCESS,1] = this_player()->fetch_then_command();
      if (schedule_action(h)) {
        TOOL_USER->notify_schedule_action(h);
        return 1; 
      } else {
        // TOOL_USER->notify_planned_action_finished(h);
        if (stringp(h[E_SUCCESS,1]))
          this_player()->add_then_command(h[E_SUCCESS,1]);
      }
    }
  }
  return 0;  // Coogan, 27-Mar-2011
}

// DEPRECATED
// this function should be called for adding rules which can be invoked
// from the action plan.
// It uses the inherited (local) parser instead of the global parser
// Therefore, this function must be called on creation of the object only
void add_planned_action_rule(string rule,string action) {
  // add_rule(rule,A_PLANNED_ + action,0,"planned");
}

/***************************** Variables-Manipulation ***********************/

// Here follow the global variables concerning running, prepared and next
// actions, as well as the methods manipulating them:

// The next action array is a list of actions that are planned for the future
// Whenever the current action is finished, the first action of this list
// will be prepared to become the next current action (if that is possible)
private static mapping *next_actions, *fast_next_actions;

void insert_next_action(mapping action, int mode) {
  mode |= action[E_MODE];
  if (mode&A_MODE_FAST) {
    if (!fast_next_actions)
      fast_next_actions = ({});
    if (mode&A_MODE_PREPEND) {
      fast_next_actions = ({action}) + fast_next_actions;
    } else {
      fast_next_actions += ({action});
    }
  } else {
    if (!next_actions)
      next_actions = ({});
    next_actions += ({action});
  }
} 

void reset_next_actions() {
  fast_next_actions = ({});
  next_actions = ({});
}

mapping first_next_action() {
  return
    (fast_next_actions && sizeof(fast_next_actions) && fast_next_actions[0]) ||
    (next_actions && sizeof(next_actions) && next_actions[0]);
}

mapping dequeue_next_action() {
  mapping h;

  if (h = first_next_action()) {
    if (fast_next_actions && sizeof(fast_next_actions)) {
      fast_next_actions = fast_next_actions[1..];
    } else {
      next_actions = next_actions[1..];
    }
    return h;
  }
  return 0;  // Coogan, 27-Mar-2011
}

// The current action is the abstract form of the currently running action
// The running action is the concrete form of the currently running action
private static mapping running_action, current_action;

void set_current_action(mapping action) {
  current_action = action;
}

void set_running_action(mapping action) {
  running_action = action;
}

void reset_current_action() {
  set_current_action(0);
}

void reset_running_action() {
  set_running_action(0);
}

mapping get_current_action() {
  return current_action;
}

mapping get_running_action() {
  return running_action;
}

/*************************** Handling of Action ****************************/

mixed handle_event(mapping m, string t, int p) {
  if (m[E_TOOL] != this_object())
    return 0;
  if (!m[E_HANDLED] && m[E_ACTION])
    return
      m[E_HANDLED] = call_other(this_object(),"handle_"+t+"_"+m[E_ACTION],m);
  return 0;  // Coogan, 27-Mar-2011
}

/************************* Handling of Resources ***************************/

/*
  The part of the preparations in the action takes the following form:

  ([ A_POSSIBLE_USED      : (identifier -> [objects]),    // mapping
     A_POSSIBLE_SHARED    : (identifier -> [objects]),
     A_USED               : [objects],                    // list of objects
     A_SHARED             : [objects],
     A_AWAITED            : [objects] ])
  
  e.g. (for an action needing two feet, two legs and sharing a chest and an
        abdomen)
  
  ([ A_POSSIBLE_USED    : ([ "leg"      : ({ leg1, leg2, leg3, leg4 }), 
                             "foot"     : ({ foot1, foot2, foot3, foot4 }) ]),
     A_POSSIBLE_SHARED  : ([ "chest"    : ({ chest })
                             "abdomen"  : ({ abdomen }) ]),
     A_USED             : ({ leg1, leg2, foot1 }),
     A_SHARED           : ({ chest }),
     A_AWAITED          : ({ abdomen, foot2, foot3, foot4 }) ])

  This would correspond to the sub-mapping of an action like this:

  ([ ...
     A_NEEDED_USED        : ([ "leg"      : 2, 
                               "foot"     : 2 ]),
     A_NEEDED_SHARED      : ([ "abdomen"  : 1,
                               "chest"    : 1 ]),
     ... ])
*/

// this function is used exclusively by start_current_action() -- once
// for the to-be shared resources and once for the to-be used ones.
// return value is the value of 'fail'.
private status fail_collect_resources(mapping needed,object *to_be_allocated,
                                      object *tested,object *awaited,
                                      mapping prep,status shared) {
  mixed h,w;
  string *parts;
  object *possible;
  int n,i,fail;

  if (needed) {
    // fill in the possible shared objects
    h = prep[shared? A_POSSIBLE_SHARED : A_POSSIBLE_USED] = 
        map_indices(needed,"get_bodyparts",TOOL_USER,1);

    // take the indices in decreasing order (of sizeof their values)
    // This is important, so that the smallest are tested first
    parts = sort_map_array(m_indices(h),
                           lambda(({'k}),({#'sizeof,({CL_INDEX,h,'k})})),
                           (#'<));
    for (i = sizeof(parts); i--; ) {
      // which parts are possible to be the ones that we want to share
      possible = prep[shared? A_POSSIBLE_SHARED : A_POSSIBLE_USED][parts[i]];

      // let n contain the number of the needed bodyparts of type 'parts[i]'
      // minus the number of these that are already shared
      n = needed[parts[i]] - sizeof(possible & to_be_allocated);

      possible -= tested;

      // which of the possible objects can be shared?
      h = filter_objects(possible,(shared?
                                   "can_share_bodypart" : "can_use_bodypart"));

      // if there have not been so many bodyparts allocatable as were needed to
      if (n > sizeof(h)) {
        awaited += possible-h;
        to_be_allocated += h;
        tested += possible;
        tested += flatten_array(map_objects(h,"deep_bodyparts")-({0}));
        fail = 1;
      } else { // enough resources found
        // take as many as needed from the allocatable bodyparts
        // Maybe the already-shared parts should get a preference here
        // (if they are to be shared), so that the other not-shared parts
        // could maybe still be 'used'
        w = h[0..n-1];
        // and choose them for later allocation
        to_be_allocated += w;
        // also prevent re-testing of the shared and the non-shareable parts
        tested += w;
        tested += flatten_array(map_objects(w,"deep_bodyparts")-({0}));
        tested += possible-h;
      }
    }
  }
  return fail;
}

#define A_FAIL_COLLECT_USED   1
#define A_FAIL_COLLECT_SHARED 2
#define A_FAIL_CONCENTRATE    4

static status do_preparations(mapping prep) {
  mixed h, w;
  int i, n;
  status fail;
  string *parts;
  mapping needed;
  object *possible, *tested, *awaited, *shared, *used;

  assert(this_object() == prep[E_TOOL]);
  awaited = prep[A_AWAITED] || ({});
  shared = prep[A_SHARED] || ({});
  used = prep[A_USED] || ({});
  // - used don't have to be tested, because they are already used by us
  // - shared don't have to be tested because they are already shared by us
  // - awaited don't have to be tested, because obviously we still wait for
  //   them to become free again
  tested = used + shared + awaited;

  // First test to-be-used
  if (needed = prep[A_NEEDED_USED])
    if (fail_collect_resources(needed,&used,&tested,&awaited,&prep,0)) 
      fail |= A_FAIL_COLLECT_USED;

  if (needed = prep[A_NEEDED_SHARED])
    if (fail_collect_resources(needed,&shared,&tested,&awaited,&prep,1))
      fail |= A_FAIL_COLLECT_SHARED;

  if (prep[A_CONCENTRATION] &&
      !TOOL_USER->has_concentration(prep[A_CONCENTRATION])) 
    fail |= A_FAIL_CONCENTRATE;

  // Now, did we get enough of the needed bodyparts?
  if (fail) {
    // Does this action have a high priority
    if (prep[E_PRIORITY] == AP_HIGH) {
      // allocate resources 'on a hunch'
      // Attention! This can cause deadlocks!!
      prep[A_USED] = used;
      filter_objects(used,"use_bodypart",this_object());
      prep[A_SHARED] = shared;
      filter_objects(shared,"share_bodypart",this_object());
    }
    // Wait for the other needed resources
    if (sizeof(awaited)) {
      prep[A_AWAITED] = awaited;
      filter_objects(awaited,"wait_for_bodypart",this_object());
    }
    // wait for enough concentration
    if ((fail&A_FAIL_CONCENTRATE) &&
        !TOOL_USER->query_waiting_for_concentration(this_object()))
      TOOL_USER->wait_for_concentration(prep[A_CONCENTRATION],this_object());
  } else { // the finding of all needed bodyparts didn't fail
    // allocate used bodyparts
    prep[A_USED] = used;
    filter_objects(used,"use_bodypart",this_object());
    // allocate shared bodyparts
    prep[A_SHARED] = shared;
    filter_objects(shared,"share_bodypart",this_object());
    // Also, stop waiting for all other 'waited-for' bodyparts
    filter_objects(awaited,"stop_waiting_for_bodypart",this_object());
    m_delete(prep,A_AWAITED);
    // allocate concentration
    if (prep[A_CONCENTRATION])
      TOOL_USER->use_concentration(prep[A_CONCENTRATION],this_object());
  }
  return !fail;
}

// This function frees all resources currently allocated by the given
// preparation mapping (which normally is an action mapping)
// Also, the waited for bodyparts are no longer waited for.
// If a tool has additional preparations made, it should overload
// this function to undo these preparations also.
void undo_preparations(mapping prep) {
  // Undo the preparations
  // free all allocated resources
  if (prep[A_USED]) {
    filter_objects(prep[A_USED],"free_bodypart",this_object());
    m_delete(prep,A_USED);
  }
  if (prep[A_SHARED]) {
    filter_objects(prep[A_SHARED],"free_bodypart",this_object());
    m_delete(prep,A_SHARED);
  }
  // notify all waited-for resources that they don't need to notify us
  // about their becoming free any longer
  if (prep[A_AWAITED]) {
    filter_objects(prep[A_AWAITED],"stop_waiting_for_bodypart",
                   this_object());
    m_delete(prep,A_AWAITED);
  }
  if (prep[A_CONCENTRATION]) { // awaited concentration
    if (TOOL_USER->query_waiting_for_concentration(this_object()))
      TOOL_USER->stop_waiting_for_concentration(this_object());
    else if (TOOL_USER->query_used_concentration(this_object()))
      TOOL_USER->free_concentration(prep[A_CONCENTRATION],this_object());
  }
}

public void notify_free_concentration() {
  mapping prep;

  if (prep = get_running_action()) {
    start_current_action(1);
  }
}

// This function is called if a bodypart changes its state (is freed (after
// having been used or shared), is activated or deactivated)
public void notify_awaited_bodypart(mixed reason,object part) {
  mapping h, prep;

  switch (reason) {
  case BP_FREED:
  case BP_ACTIVATED:
    if (prep = get_running_action()) {
      if (member(prep,A_AWAITED))
        prep[A_AWAITED] -= ({part});
      start_current_action(1);
    }
    break;
  case BP_DEACTIVATED:
    if (prep = get_running_action()) {
      if (member(prep,A_USED))
        prep[A_USED] -= ({part});
      if (member(prep,A_SHARED))
        prep[A_SHARED] -= ({part});
      start_current_action(1);
    }
    break;
  default:
    raise_error("Illegal reason to notify_awaited_bodypart()\n");
  }
}

// This function returns a failure-message, if the action is not possible
// (due to deactivated bodyparts or other missing needed resources)
// in the near future to execute.
// Otherwise, it returns 0.
static mixed query_action_impossible(mixed action) {
  int i;
  mixed h;
  string *parts;

  if (h = action[A_NEEDED_SHARED]) {
    h = map_indices(h,"get_bodyparts",TOOL_USER,1);
    parts = m_indices(h);
    for (i = sizeof(parts); i--; )
      if (sizeof(filter_objects(h[parts[i]],"query_active_bodypart")) <
          action[A_NEEDED_SHARED][parts[i]])
        return "Failed to "+action[E_ACTION]+".\n";
  }
  if (h = action[A_NEEDED_USED]) {
    h = map_indices(h,"get_bodyparts",TOOL_USER,1);
    parts = m_indices(h);
    // test, if there are 'enough' active bodyparts available
    for (i = sizeof(parts); i--; )
      if (sizeof(filter_objects(h[parts[i]],"query_active_bodypart")) <
          action[A_NEEDED_USED][parts[i]])
        return "Failed to "+action[E_ACTION]+".\n";
  }
  if (h = action[A_CONCENTRATION]) {
    if (!TOOL_USER->query_used_concentration(this_object()) &&
        TOOL_USER->get_max_concentration() < h)
      return "You can't concentrate enough to "+action[E_ACTION]+".\n";
  }
}

// This function returns a failure message, if the currently running action
// is not possible anymore (like if the target of an attack isn't available
// anymore or the weapon can't be used anymore etc.)
// It should be implemented by the action-classes for the specific actions
static mixed query_running_action_impossible(mixed action) {
  return 0;  // Coogan, 27-Mar-2011
}

/******************************* Abortion **********************************/

// This function is called by the scheduler if
// an error occurred during the call of the action
void abort_current_call() {
  mapping e;

  if (e = get_running_action()) {
    undo_preparations(e);
    reset_running_action();
  }
  reset_current_action();
  try_schedule_next_action(1);
}

// This function is for (unconditionally) aborting the current action
void abort_current_action() {
  mapping e;

  if (e = get_running_action()) {
    undo_preparations(e);
    if (e[E_ID])
      TOOL_USER->remove_call(e[E_ID]);
    if (e[E_ID,1][E_ACTION,1]) // planned?
      TOOL_USER->notify_planned_action_finished(e);
    reset_running_action();
  }
  reset_current_action();
  try_schedule_next_action(1);
}

// If the current action should be aborted, this function tests if
// that is possible at the moment
status can_abort_running_action() {
  mixed h;

  if ((h = get_running_action()) && h[E_ID]) 
    return 
      TOOL_USER->can_abort_call(h[E_ID]);
  return 1;
}

// This function causes the current action to be aborted altogether
// It should only be called if can_abort_running_action() returns true
static void abort_running_action() {
  mixed h;

  if ((h = get_running_action()) && h[E_ID]) {
    TOOL_USER->abort_call(h[E_ID]);
    if (h[E_ID,1][E_ACTION,1]) // planned?
      TOOL_USER->notify_planned_action_finished(h);
  }
  else 
    abort_current_action();
}

// This function aborts the currently running action if possible
// and returns a true value if it has done so successfully
// It also schedules the next action to be current action
status try_abort_running_action() {
  if (can_abort_running_action()) {
    abort_running_action();
    return 1;
  }
}

// This function should be called if someone wants to interrupt an
// action of ours
// It could be passed as abort-function to the coordinator
// If a current action is running, the function will try to abort it and 
// reschedule it as the first next action.
// If there is a prepared action, the preparations are undone and
// the prepared action is rescheduled as first next action
mapping interrupt_running_action() {
  mapping action;

  if (action = get_running_action()) {
    if (!try_abort_running_action())
      return 0;
  } else if (action = get_current_action()) {
    abort_current_action();
  }
  return action;
}

/********************************** Failing ********************************/

private static mixed fail_mess;
private static int   fail_prio;

private void set_fail_mess(mixed mess) {
  fail_mess = mess;
}

private void set_fail_prio(int prio) {
  fail_prio = prio;
}

public varargs void fail_action(mixed mess, int prio) {
  if (mess && (prio >= fail_prio)) {
    set_fail_prio(prio);
    set_fail_mess(mess);
  }
  abort_current_action();
}

static void reset_fail_message() {
  set_fail_prio(0);
  set_fail_mess(0);
}

static void send_fail_message() {
  if (fail_mess) {
    if (this_player() == TOOL_USER && this_player()->query_commandline())
      notify_fail(fail_mess,fail_prio);
    else 
      message(fail_mess,TOOL_USER);
    reset_fail_message();
  }
}

/********************************* Finishing ******************************/

static void running_action_finished() {
  mapping e;
  mixed succ;

  if (e = get_running_action()) {
    // free resources
    e[E_ID] = 0;
    abort_current_action();
    if (succ = e[E_SUCCESS,1]) {       // 'prescheduled' action
      if (closurep(succ))
        funcall(succ,e[E_SUCCESS]);
      else if (mappingp(succ))
        succ[E_TOOL]->continue_stalled_action(e[E_SUCCESS],succ);
      else if (stringp(succ) && e[E_SUCCESS])
        e[E_AGENT]->add_then_command(succ);
    }
  }
  // make room for new current action
  try_schedule_next_action(1);
}

// This function should be called by the current action when it is finished
// This function 'cleans up' after the current action
// It frees the resources and resets the current action to 0
// so that a new action can become current action
status finish_running_action(status aborted) {
  mapping e;

  if (e = get_running_action()) {
    if (aborted)
      e[A_ABORTED] = 1;
    e[E_ID] = 0;
    e[E_PHASE] = "finish";
    send_event("finish_action",e,environment(e[E_AGENT]));
    if (!e[E_CANCELLED])
      return 1;
  }
  send_fail_message();
  running_action_finished();
  return 0;  // Coogan, 27-Mar-2011
}

int schedule_action_finished(mapping e) {
  // schedule the finishing of the action unabortable:
  // (which is accomplished by not giving an abort-closure)
  return 
    e[E_ID] =
      TOOL_USER->schedule_call(member(e,A_FINISH_TIME) &&
                               e[A_FINISH_TIME,e[A_ABORTED]],
                               (#'running_action_finished));
}

static void notice_finish_action_event(mapping e) {
  if (e[E_TOOL] != this_object())
    return;
  schedule_action_finished(e);
}

static void running_action_aborted() {
  finish_running_action(1);
}

/***************************** Execution ***********************************/

static status execute_running_action() {
  mixed failure;
  mapping e;

  if (e = get_running_action()) {
    e[E_ID] = 0;
    // e[E_SUCCESS] = 1; // be optimistic
    e[E_PHASE] = "execute";
    send_event("action",e,environment(e[E_AGENT]));
    if (!e[E_CANCELLED])
      return 1;
  }
  send_fail_message();
  running_action_aborted();
  return 0;  // Coogan, 27-Mar-2011
}

status prevent_action_event(mapping e, string t, int p) {
  mixed mess;

  if (e[E_TOOL] != this_object())
    return 0;
  if (mess = query_running_action_impossible(e))
    return fail_action(mess,2), 1;
  return 0;  // Coogan, 27-Mar-2011
}

int schedule_finish_action_event(mapping e) {
  // schedule the finishing of the action unabortable:
  // (which is accomplished by not giving an abort-closure)
  return 
    e[E_ID] =
      TOOL_USER->schedule_call(member(e,A_RUNTIME) &&
                               e[A_RUNTIME,!e[E_SUCCESS]],
                               (#'finish_running_action),
                               e[A_ABORT_ACTION]);
}

static void notice_action_event(mapping e) {
  if (e[E_TOOL] != this_object())
    return;
  if (e[E_MODE]&A_MODE_SHORT)
    schedule_action_finished(e);
  else
    schedule_finish_action_event(e);
}

/**************************** Beginning *********************************/

static void begin_running_action_aborted() {
  running_action_aborted();
}

static status begin_running_action() {
  mixed failure;
  mapping e;

  if (e = get_running_action()) {
    e[E_ID] = 0;
    e[E_PHASE] = "begin";
    send_event("begin_action",e,environment(e[E_AGENT]));
    if (!e[E_CANCELLED])
      return 1;
  }
  send_fail_message();
  begin_running_action_aborted();
  return 0;  // Coogan, 27-Mar-2011
}

status prevent_begin_action_event(mapping e, string t, int p) {
  mixed mess;

  if (e[E_TOOL] != this_object())
    return 0;
  if (mess = query_running_action_impossible(e))
    return fail_action(mess,2), 1;
  return 0;  // Coogan, 27-Mar-2011
}

int schedule_action_event(mapping e) {
  // schedule the execution of the action abortable:
  return
    e[E_ID] = 
      TOOL_USER->schedule_call(member(e,A_PREPARE_TIME) && 
                               e[A_PREPARE_TIME],
                               (#'execute_running_action),
                               (#'begin_running_action_aborted));
}

static void notice_begin_action_event(mapping e) {
  if (e[E_TOOL] != this_object())
    return;
  schedule_action_event(e);
}

/******************************** Preparing *****************************/

static void prepare_action_aborted() {
  if (get_current_action())
    abort_current_action();
  // the action has been aborted before it has even begun!
  try_schedule_next_action(1);
}

status prepare_current_action() {
  mapping e;

  reset_fail_message();
  if (e = get_running_action()) {
    e[E_ID] = 0;
    e[E_PHASE] = "prepare";
    send_event("prepare_action",e,TOOL_USER);
    if (!e[E_CANCELLED] || e[A_STALLED])
      return 1;
  }
  send_fail_message();
  prepare_action_aborted();
  return 0;  // Coogan, 27-Mar-2011
}

status prevent_prepare_action_event(mapping e, string t, int p) {
  mixed mess;

  if (e[E_TOOL] != this_object())
    return 0;
  if (mess = query_action_impossible(e)) {
    // debug("ugh", ({ e[E_ACTION], this_object()->query_name() }));
    return fail_action(mess,2), 1;
  }
}

int schedule_begin_action_event(mapping event) {
  // don't do it at once, but with a certain delay
  // This delay is the delay between the 'decision' to do something
  // and the actual begin of the action
  // It should probably only be a value above 0 for very complex actions
  return
    event[E_ID] = 
      TOOL_USER->schedule_call(member(event,A_PREPARE_TIME) &&
                               event[A_PREPARE_TIME,1],
                               (#'begin_running_action),
                               (#'prepare_action_aborted));
}

status handle_prepare_action_event(mapping event) {
  if (event[E_TOOL] != this_object())
    return 0;
  event[E_SUCCESS] = do_preparations(event);
  return 1;
}

void notice_prepare_action_event(mapping event) {
  if (event[E_TOOL] != this_object())
    return;
  if (!event[E_SUCCESS])
    return;
  if (event[E_MODE]&A_MODE_SHORT)
    schedule_action_event(event);
  else
    schedule_begin_action_event(event);
}

int schedule_prepare_action_event(mapping e) {
  return
    e[E_ID] =
      TOOL_USER->schedule_call(0,
                               #'prepare_current_action,
                               #'prepare_action_aborted);
}

static status start_current_action(status delay) {
  mapping action, event;
  mixed mess;

  if (!(event = get_running_action())) {
    event = build_action_event(copy(get_current_action()));
    event[E_ID,1] = get_current_action();
    set_running_action(event);
  } /* else if (event[E_SUCCESS]) { // already successfully started
    return 1;
  } */
  // debug("ugh", event[E_TOOL]->query_name()+": "+event[E_ACTION]);
  // event[E_SUCCESS] = 1;
  // to avoid too deep recursions
  if (!delay) {
    if (prepare_current_action())
      return 1;
    return 0;
  }
  schedule_prepare_action_event(event);
  return 1;
}

// DEPRECATED
void create() {
  duplicate_action_class(G_WORD,A_G_POSITION);
  duplicate_action_class(G_WORD,A_G_DIRECTION);
  duplicate_action_class(G_OBJECT,A_G_TOOL);
  duplicate_action_class(G_OBJECT,A_G_WEAPON);
  duplicate_action_class(G_OBJECT,A_G_BODYPART);
  duplicate_action_class(G_INDIRECT,A_G_TARGET);
#if 0 // these are still the same
  duplicate_action_class(G_OBJECT,A_G_OBJECT);
  duplicate_action_class(G_INDIRECT,A_G_INDIRECT);
#endif
}

void notify_destruct() {
  abort_current_action();
}
