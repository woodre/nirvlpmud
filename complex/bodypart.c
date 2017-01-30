/****************************************************************************
    bodypart.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

#include <describe.h>
#include <bodypart.h>
#include <libs.h>
#include <prop/item.h>
#include <message.h>
#include <action.h>
#include <persistence.h>
#include <combat.h>
#include <action.h>
#include <event.h>
#include <inventory.h>

inherit BASIC_COMPOUND_BODYPART;
inherit BASIC_TOOL;
inherit "complex/item";

object get_environment() {
  object u;
  u = get_user();
  if (u) return u;
  u = get_compound();
  if (u)
    return ENVIRONMENT(u);
  return environment();
}

private string
bodypart_long()
{
  int i, j;
  mixed h;
  string result;
  object user;

  result =
    capitalize(describe_object(this_object(),query_name(),ARTICLE_THE))+".\n";
  user = get_user();
  if (sizeof(h = get_wearing())) {
    if (this_player() != user) {
      for (i = sizeof(h); i--; )
        if (h[i]) {
          for (j = i-1; j--; ) {
            if (h[i]->query_covering(h[j],this_object()))
              h[j] = 0;
          }
          if (!h[i]->query_transparent(this_object())) {
            h = h[i..];
            break;
          }
        }
      h -= ({ 0 });
    }
    result += 
      capitalize(message2string(({user,M_VERB,"are",user," wearing ",
                                  M_SIMPLE_DESCRIBE,h,
                                  " on ",M_ME_OBJECTIVE,".\n"})));
  }
  if (sizeof(h = get_wounds())) {
    result +=
      capitalize(message2string(({M_ME_PRONOUN,M_ME_VERB,"have",
                                  M_DESCRIBE_UNOWNED,h,".\n"})));
  } 
  // maybe insert health here
  if (!query_active_bodypart())
    result +=
      capitalize(message2string(({M_ME_PRONOUN,M_ME_VERB,"have",
                                  " been rendered inactive.\n"})));
  return result;
}

// avoid configuring of blueprints
void
create()
{
  if (!clonep())
    return;
  else {
    item::create();
    BASIC_TOOL::create();
  }
}

static int query_own_encumbrance() {
  return item::query_encumbrance();
}

varargs int query_encumbrance(string location) {
  mixed h;

  if (this_player() == get_user())
    return 0; // our own body doesn't weigh anything for us
  if (location && h = get_bodypart(&location))
    return h->query_encumbrance(location);
  return
    item::query_encumbrance() +
    BASIC_COMPOUND_BODYPART::query_encumbrance(location);
}

string query_active_state_description(status output) {
  if (output) {
    if (!query_active_bodypart())
      return "inactive";
  } else {
    string *result;
    if (query_active_bodypart())
      result = ({"active","not inactive","not deactivated","not limp"});
    else
      result = ({"not active","inactive","deactivated","limp"});
    return implode(result,"\\>|\\<");
  }
}

void
configure()
{
  item::configure();

  set_property(P_BODYPART);
  set_persistence(PER_NO_PERSISTENCE);
  set_name("bodypart");
  set_id(({"bodypart"}));
  set_short(0); // bodyparts are 'invisible'
  set_long(#'bodypart_long);
  set_hit_size(#'query_own_encumbrance);
  add_to_property(P_STATE_DESCRIPTION,#'query_position_state_description);
  add_to_property(P_STATE_DESCRIPTION,#'query_active_state_description);
}

void notify_destruct() {
  filter(get_wearing(),#'unwear);
}

void set_race(string r) {
  if (query_race())
    return;
  BASIC_COMPOUND_BODYPART::set_race(r);
  set_encumbrance(LIB_BODYPART->get_encumbrance(query_type(),r));
}

mapping build_action(string action, mapping args) {
  if (args) {
    if (args[A_G_POSITION] && !has_position(args[A_G_POSITION]))
      return 0;
    if (args[A_G_TOOL] && !identifies_me(args[A_G_TOOL,1],args[A_G_TOOL]))
      return 0;
  }
  return BASIC_TOOL::build_action(action,args);
}

status handle_event(mapping e, string t, int p) {
  return
    BASIC_TOOL::handle_event(e,t,p) ||
    item::handle_event(e,t,p);
}

status prevent_event(mapping e, string t, int p) {
  if (e[E_TOOL] == this_object())
    return
      item::prevent_event(e,t,p);
}

status 
id(string str)
{
  // str = cut_off_position(str);
  return item::id(str) || BASIC_COMPOUND_BODYPART::id(str);
}

status
get(string str)
{
  return BASIC_COMPOUND_BODYPART::get(str) && item::get(str);
}

status drop(int silently)
{
  return 1;
}

string
long(string str)
{
  if (!id(str) && query_component_id(str))
    return BASIC_COMPOUND_BODYPART::long(str);
  return item::long(str) || BASIC_COMPOUND_BODYPART::long(str);
}

varargs string
query_name(string str)
{
  mixed h;

  if (str && h = BASIC_COMPOUND_BODYPART::query_name(str))
    return h;
  return (query_position_description()||"")+(item::query_name());
}

varargs mixed query_property(string prop, string part) {
  return
    BASIC_COMPOUND_BODYPART::query_property(prop,part) ||
    item::query_property(prop);
}

void add_tool_action_rule(varargs mixed vargs) {
  return apply(#'add_component_action_rule,vargs);
}

object *get_inventory(string which, string preposition) {
  object *result;

  result = ({});
  result += item::get_inventory(which,preposition) || ({});
  result +=
    (BASIC_COMPOUND_BODYPART::get_inventory(which,preposition) || ({})) -
    result;
  return result;
}
