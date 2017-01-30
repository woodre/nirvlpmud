/*
 * /basic/behaviour.c bu Alfe for Tubmud 2002-Apr-19
 *
 * this file provides functionality for all objects which 'behave' in
 * a certain way.  this will mostly be used by NPCs to make their reactions
 * be more realistic.
 *
 */

mapping behaviour; /* this mapping represents a state chart by pointing
                    * from one state (a string) to:
                    * - a function which maps an event to a new state.
                    *   if this function returns 0, the state is not changed.
                    *   if this function returns an array, the first element
                    *   is the new state, the second argument is the new
                    *   additional state_info.
                    * - state information (e.g. chats appropriate in this
                    *   situation or descriptions for this state)
                    */

string current_state; /* this is the current state we are in */
mixed current_state_info; /* this is further information to the current state
                           */

void set_behaviour(mapping b) {
  behaviour = b;
}

// the following function is meant to be overloaded
void react_on_invalid_state_change(string new_current_state,
                                   mixed new_current_state_info) {
  current_state      = 0;
  current_state_info = 0;
}

// the following function is meant to be overloaded
void react_on_valid_state_change(string new_current_state,
                                 mixed new_current_state_info) {
  current_state      = new_current_state;
  current_state_info = new_current_state_info;
}

void apply_event(mixed event) {
  string new_current_state;
  mixed  new_current_state_info, reaction;
  
  reaction = funcall(behaviour[current_state], event,
                     current_state, current_state_info);
  if (pointerp(reaction)) {
    new_current_state      = reaction[0];
    new_current_state_info = reaction[1];
  }
  else if (reaction) {
    new_current_state      = reaction;
    new_current_state_info = 0;
  }
  else
    return;
  if (member(behaviour, current_state))
    react_on_valid_state_change(new_current_state, new_current_state_info);
  else
    react_on_invalid_state_change(new_current_state, new_current_state_info);
}
