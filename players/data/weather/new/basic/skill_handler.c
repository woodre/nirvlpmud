/****************************************************************************
          /complex/skill.c written Jun-1995 by Ugh for Tubmud
****************************************************************************/

#pragma strong_types

#include <server.h>
#include <event.h>

private mapping influences;

void modify_skill(mapping e,string t,int p);
void modify_skills(mapping e,string t,int p);

/*
 * set_influence() can set an influence for a skill that is to be modified 
 * in the vicinity of this object.
 * - skill is the skill-to-be-tested as string delimited by '|'
 * - type is a keyword for the influence giving the possibility to 
 * add and remove special influences in the existence of this object.
 * - function can be:
 *   - a function-name (string) which will be called in the object whose
 *     skill is to be modified (e.g. "query_int" for ob->query_int()),
 *   - a closure, getting the object whose skill is to be modified as
 *     argument (e.g. #'query_light for query_light(ob)).
 * - amount can be:
 *   - an array, where the element is returned, whose index was returned by
 *     the call to 'function',
 *   - a mapping (the result of 'function' is taken as index as well)
 *   - a closure which will get the result of 'function' as argument.
 *   the result amount should be integers in the range of -100 to 100
 *   where a negative value will result in a percentual malus and a 
 *   positive value a percentual bonus added to or substracted from 
 *   the value to be modified later (SEE ALSO /basic/living/skill_test).
 */
static void set_influence(string skill, string type, mixed func, mixed amount) {
  string handler;
  skill = SE_SKILLS->convert_skillname(skill);
  if (!influences) {
    influences = ([]);
    /* only listen to the event if not called by the default handler */
    if (!((handler = SE_SKILLS->query_skill_handler(skill)) &&
          find_object(handler) == this_object())) {
      listen_event("modify_skill",200,#'modify_skill);
      listen_event("modify_skills",200,#'modify_skills);
    }
  }
  if (!influences[skill])
    influences[skill] = ([type : func; amount]);
  else if (!func)
    /* delete this influence */
    m_delete(influences[skill],type);
  else
    influences[skill] += ([type : func; amount]);
}

static void set_influences(string skill, mixed *i) {
  map(i, lambda(({'a}),({#'apply, #'set_influence, skill, 'a})));
}

int query_reward(object who, int success, int difficulty, string skill) {
  // overload this function, if you wish an advance-schema that is
  // learning by doing for the skill
  return 0;  // Coogan, 26-Mar-2011
}

int * get_influences(string skill, object who) {
  int i, *result;
  string *keys;
  mixed h;
  mapping inf;
  inf = influences && influences[skill];
  result = ({});
  if (!inf)
    return result;
  for (i=sizeof(keys=m_indices(inf));i--;) {
    if (stringp(h = inf[keys[i]]))
      h = call_other(who,h);
    else if (closurep(h))
      h = funcall(h,who);
    if (mappingp(inf[keys[i],1]))
      result += ({ inf[keys[i],1][h] });
    else if (pointerp(inf[keys[i],1]))
      result += inf[keys[i],1][h..h];
    else
      result += ({ funcall(inf[keys[i],1],h,who) }) ;
  }
  return result;
}

void modify_skill(mapping e,string t,int p) {
  e[E_MODIFICATION] += get_influences(e[E_TYPE],e[E_AGENT]);
}

void modify_skills(mapping e, string t, int p) {
  int i;
  mixed h;
  string *skills;

  skills = m_indices(e[E_SKILL]);
  for (i = sizeof(skills); i-->0; )
    if (h = get_influences(skills[i],e[E_AGENT]))
      e[E_MODIFICATION][skills[i]] += h;
}

