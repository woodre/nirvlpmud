/*
 * /kernel/simul/message.c
 *
 * Originally from Tubmud - Implemented on Nirvana
 * Rumplemintz
 */

#include <message.h>
#include <kernel.h>
#include <lpctypes.h>
#include <closures.h>
#include <describe.h>
#include <libs.h>
#include <prop/player.h>
#include <prop/room.h>
#include <inventory.h>
#include <regexps.h>
#include <is_wizard.h>

#include "/kernel/simul/list.h"
#include "/kernel/simul/fold.h"
#include "/kernel/simul/array.h"
#include "/kernel/simul/misc.h"
#include "/kernel/simul/string.h"
#include "/kernel/simul/game.h"
#include "/kernel/simul/lpc.h"
#include "/kernel/simul/is_wizard.h"
#include "/kernel/simul/message.h"

#define DESCRIBE_OBJECTS

/*
 * The code of group2string() is extremely complex (deeply nested ifs); maybe
 * the following table helps to understand it.
 *
 * S is the possibly plural subject of the sentence,
 * O the possibly plural object:
 * S hit(s) O.  S hit(s) O's feet.
 * S hit(s) it. S hit(s) its feet.
 *
 * plural O
 * |  relation between S and O (`|' = no in both; `X' = some in both)
 * |  |  possessive (x=yes, -=no)
 * |  |  | pronoun (x=yes, -=no, *=doesn't matter)
 * |  |  | |
 * | S?O | |  Object                                World
 * -  #  - -  you                                   O
 * -  #  - x  you                                   OBJ(O)
 * -  #  x -  your                                  O's
 * -  #  x x  your                                  POSS(O)
 * -  =  - *  yourself/-ves                         SELF(S)
 * -  =  x *  your own                              POSS(O) own
 * ===========================================================================
 * x  =  - *  yourselves                            themselves
 * x  =  x *  your own                              their own
 * ---------------------------------------------------------------------------
 * x  >  - -  O-TO and yourself/-ves                O
 * x  >  - x  yourself/-ves                         SELF(O)
 * x  >  x -  your own and O-TO's                   O's own
 * x  >  x x  your own                              POSS(O) own
 * ---------------------------------------------------------------------------
 * x  |  - - !you and O-TO                          O
 * x  |  - x !you                                   them
 * x  |  x -  your and O-TO's                       O's
 * x  |  x x  your                                  their
 * ---------------------------------------------------------------------------
 * x </X - - !TO|S: SELF(S&O), O-S-TO and you       SELF(S&O) and O-S
 *            TO<S: yourself/-ves and O-S
 * x </X - x !TO|S: SELF(S&O), OBJ(O-S-TO) and you  SELF(S&O) and OBJ(O-S)
 *            TO<S: yourself/-ves and OBJ(O-S)
 * x </X x -  TO|S: POSS(S&O) own, O-S-TO's and your POSS(S&O) own and O-S's
 *            TO<S: your own and O-S's
 * x </X x x  TO|S: POSS(S&O) own and your          POSS(S&O) own and POSS(O-S)
 *            TO<S: your own and POSS(O-S)
 *
 * The lines with the ! befor the "Object"-column are the ones that have to
 * add a -rself (or -rselves) to the "you" in them if we have the case of the
 * active objects. ("The bench is occupied by yourself.")
 */

#define POSS(x) (sizeof(x)>1? "their" : ((x)[0]->query_possessive() || "its"))
#define OBJ(x) (sizeof(x)>1? "them" : ((x)[0]->query_objective() || "it"))
#define SELF(x) ((sizeof(x)>1 || (x)[0]->query_plural())? "themselves" : \
                 ((x)[0]->query_objective() || "it")+"self")

#define YOU(o, cloak_explained) ((!cloak_explained && \
                                  query_once_interactive(o))? \
                                 ((cloak_explained = 1), \
                                  you_description(o)) : \
                                 "you")

private string you_description(object o) {
  mixed h;
  string name;
  h = o->query_property(P_DONT_SHOW_CLOAKED);
  name = o->query_name();
  if ((stringp(h) && name == h) ||
      (objectp(h) && name == h->query_current_vis_name()) ||
      (intp(h) && (h || name == o->query_vis_name())))
    return "you";
  return "you [" + name + "]";
}

private string get_possessive_pronoun(object o,
                                      status with_of,
                                      object perceiver) {
  string poss;
  if (o == perceiver)  // looking at ourselves?
    return "your" + (with_of? "s" : "");
  poss = o->query_possessive() || "it";
  if (with_of && (poss == "her" || poss == "their"))
    return poss + "s";
  else
    return poss;
}

private object _environment(object ob) {
  return ENVIRONMENT(ob);
}

varargs string describe_object(mixed o, string id, mixed article, int full,
                               mixed subject, status possessive_s,
                               object perceiver);

private varargs string get_owner_possessive(mixed o, string id, mixed subject,
                                            status with_of, object perceiver) {
  object o_env, perceiver_env;
  mixed h;
  if (subject && !pointerp(subject))
    subject = ({ subject });
  else if (!subject)
    subject = ({});
  if (stringp(o))
    return 0;
  if (!perceiver)
    perceiver = this_player();
  perceiver_env = _environment(perceiver);
  o_env = _environment(o);
  if (id && o->query_fakeitem_id(id)) {
    if (o == perceiver_env)  // fakeitem of the room?
      return 0;
    if (member(subject, o) >= 0) {
      return get_possessive_pronoun(o, with_of, perceiver);
    }
    else {
      return describe_object(o, 0, ARTICLE_THE, 0, subject, 1, perceiver);
    }
  }
  // we are not a fakeitem
  if (!(o == perceiver_env ||      // the room itself
        o_env == perceiver_env ||  // in the room
        !o_env ||                  // another room far away ;-]
        !_environment(o_env))) {    // thing in a room
    if (member(subject, o_env) >= 0 ||
        o_env == perceiver) {
      return get_possessive_pronoun(o_env, with_of, perceiver);
    }
    else {
      return describe_object(o_env, 0, ARTICLE_THE, 0, subject, 1, perceiver);
    }
  }
}

varargs string describe_object(mixed o, string id, mixed article, int full,
                               mixed subject, status possessive_s,
                               object perceiver) {
  object o_env, perceiver_env;
  mixed h;
  if (subject && !pointerp(subject))
    subject = ({ subject });
  else if (!subject)
    subject = ({});
  if (stringp(o))
    return describe(o, article, full, 0, possessive_s);
  if (!perceiver)
    perceiver = this_player();
  perceiver_env = _environment(perceiver);
  o_env = _environment(o);
  if (id && o->query_fakeitem_id(id)) {
    if (member(subject, o) >= 0) {
      if (h=o->query_fakeitem_short(id))
        id = h;
    }
    else {  // not full describe
      if (h=o->query_fakeitem_name(id))
        id = h;
    }
    if (o == perceiver_env ||  // fakeitem of the room?
        article == ARTICLE_NONE ||
        !intp(article) ||  /* ({ M_ARTICLE, "<string>", o }) wouldn't
                            * work otherwise, Chameloid, 4-Aug-97
                            */
        (environment(o) &&
         environment(o)->is_mount(o)))  /* prevention of Ando-Anca's Alfe
                                         * Alfe 2003-Jun-24
                                         */
      return describe(id, article, 0, 0, possessive_s);
    switch (article) {
    case ARTICLE_THE:
      return describe(id, get_owner_possessive(o, id, subject, 0, perceiver),
                      0, 0, possessive_s);
    case ARTICLE_A:
      return (describe(id, article) + " of " +
              get_owner_possessive(o, id, subject, 1, perceiver));
    default:
      raise_error("Illegal article to describe_object()\n");
    }
  }
  // we are not a fakeitem
  if (o == perceiver_env ||  // the room itself
      o_env == perceiver_env ||  // in the room
      !o_env ||  // another room far away ;-)
      !_environment(o_env) ||  // thing in a room
      article == ARTICLE_NONE || !intp(article))
    // ({ M_ARTICLE, "<string>", o }) wouldn't
    // work otherwise, Chameloid, 4-Aug-97
    return describe(o, article, full, -1, possessive_s);
  if (environment(o) &&
      environment(o)->is_mount(o))
    return describe(o, article, 0, -1);
  switch (article) {
  case ARTICLE_THE:
    return describe(o, get_owner_possessive(o, id, subject, 0, perceiver),
                    full, -1, possessive_s);
  case ARTICLE_A:
    return (describe(o, article, 0, -1) + " of " +
            get_owner_possessive(o, id, subject, 1, perceiver));
  default:
    raise_error("Illegal article to describe_object()\n");
  }
  NO_WARN_MISSING_RETURN;
}

private string *collect_objects(string *items) {
  int i, j;
  string pre, post, ord_plus_post;
  for (i=0; i<sizeof(items)-1; i++)
    if (items[i] && sscanf(items[i], "%s %s", pre, post) == 2) {
      for (j=1;
           (i+j < sizeof(items) &&
            (ord_plus_post=LIB_PARSE->get_ordinal(j+1) + " " + post,
             items[i+j] == pre + " "  + ord_plus_post ||
             items[i+j] == pre + "n " + ord_plus_post));
           j++)
        ;  // do nothing
      if (j > 1)
        if (j == 2)
          items[i..i+1] = ({ pre + " first and second " + post });
        else
          items[i..i+j-1] = ({ (pre + " first through " +
                                LIB_PARSE->get_ordinal(j) + " " + post) });
    }
  return items;
}

//private
varargs string *list_objects(mixed *items, mixed article, int full,
                             status poss, closure desc,
                             status describe_unowned_flag) {
  mixed *obs;
  mixed *others;
  mixed result;
  desc = desc || symbol_function("describe"); // Chameloid, 9-Jan-99
  if (describe_unowned_flag) {
    return describe_list(items, article, full, poss, desc);
  }
  obs = filter(items, #'objectp);
  others = items - obs;
  obs = map(order_objects(obs), desc, article, full, 0, poss);
  // added '0' above; for describe() this is the 'count'
  // argument, poss is the 4th, not 3rd arg for describe()
  obs = collect_objects(obs);
  result = obs + describe_list(others, article, full, poss, desc);
  return result;
}

private string group2string(object o, object *group, object *subject,
                            int object_flag, status pronoun_flag,
                            mixed article, status possessive_flag,
                            status full_flag, closure desc,
                            status cloak_explained,
                            status describe_unowned_flag) {
  mixed h;
  object *group_subject;
  object *subject_group;
  object *intersection;
  group_subject = group - subject;
  subject_group = subject - group;
  intersection = subject & group;
  if (!sizeof(group)) {  // nobody
    if (object_flag && !sizeof(subject)) {  // nobody is also acting
      return "himself";
    }
    else {  // not reflexive
      if (pronoun_flag) {  // nobody's pronoun
        if (possessive_flag) {  // possessive pronoun
          return "his";
        }
        else {  // simple pronoun
          return "he";
        }
      }
      else {  // nobody's name
        return describe("nobody", article || ARTICLE_NONE, 0, 0,
                        possessive_flag);
      }
    }
  }
  else {  // at least two entries; sender takes care of this
    if (object_flag) {  // Object of the sentence
      if (!sizeof(group_subject) &&
          !sizeof(subject_group)) {  // subject = object
        if (member(group, o) >= 0) {  // object
          return (possessive_flag? "your own" : "yourselves");
        }
        else {  // world
          return (possessive_flag? "their own" : "themselves");
        }
      }
      else if (!sizeof(group_subject)) {  // subject > object
        if (member(group, o) >= 0) {  // we are part
          if (possessive_flag) {
            if (pronoun_flag) {
              return "your own";
            }
            else {
              return make_list(({ "your own" }) +
                               list_objects(group-({ o }), article, full_flag,
                                            possessive_flag, desc,
                                            describe_unowned_flag));
            }
          }
          else {
            if (pronoun_flag) {
              return o->query_plural()? "yourselves" : "yourself";
            }
            else {
              return (make_list(({ (o->query_plural()?
                                    "yourselves" : "yourself") })+
                                list_objects(group-({ o }), article, full_flag,
                                             possessive_flag, desc,
                                             describe_unowned_flag))+
                      (possessive_flag? " own" : ""));
            }
          }
        }
        else { // we are world
          if (pronoun_flag) {
            if (possessive_flag) {
              return POSS(group) + " own";
            }
            else {
              return SELF(group);
            }
          }
          else {
            return make_list(list_objects(group, article, full_flag,
                                          possessive_flag, desc,
                                          describe_unowned_flag));
          }
        }
      }
      else if (!sizeof(intersection)) {  // subject | object
        if (member(group, o) >= 0) {  // we are part
          if (possessive_flag) {
            if (pronoun_flag) {
              return "your";
            }
            else {
              return make_list(({ "your" })+
                               list_objects(group-({ o }), article, full_flag,
                                            possessive_flag, desc,
                                            describe_unowned_flag));
            }
          }
          else {
            if (pronoun_flag) {
              return object_flag==2? "yourselves" : "you";
            }
            else {
              return make_list(({ (object_flag==2?
                                   (o->query_plural()?
                                    "yourselves" : "yourself") :
                                   YOU(o, cloak_explained)) })+
                               list_objects(group-({ o }), article, full_flag,
                                            possessive_flag, desc,
                                            describe_unowned_flag));
            }
          }
        }
        else {  // we are world
          if (pronoun_flag) {
            if (possessive_flag) {
              return "their";
            }
            else {
              return "them";
            }
          }
          else {
            return make_list(list_objects(group, article, full_flag,
                                          possessive_flag, desc,
                                          describe_unowned_flag));
          }
        }
      }
      else {  // subject </X object
        if (member(group, o) >= 0) {  // object
          if (member(subject, o) >= 0) {  // TO<S
            if (possessive_flag) {
              if (pronoun_flag) {
                return "your own and " + POSS(group_subject);
              }
              else {
                return make_list(({ "your own" }) +
                                 list_objects(group_subject, article,
                                              full_flag, possessive_flag, desc,
                                              describe_unowned_flag));
              }
            }
            else {
              if (pronoun_flag) {
                return ((o->query_plural()?
                         "yourselves and " : "yourself and ") +
                        OBJ(group_subject));
              }
              else {
                return make_list(({ o->query_plural()?
                                    "yourselves" : "yourself" }) +
                                 list_objects(group_subject, article,
                                              full_flag, possessive_flag, desc,
                                              describe_unowned_flag));
              }
            }
          }
          else {  // TO|S
            if (possessive_flag) {
              if (pronoun_flag) {
                return POSS(intersection) + " own and your";
              }
              else {
                return make_list(({ POSS(intersection) + " own" }) +
                                 list_objects(group_subject-({ o }), article,
                                              full_flag, possessive_flag, desc,
                                              describe_unowned_flag) +
                                 ({ "your" }));
              }
            }
            else {
              if (pronoun_flag) {
                return (SELF(intersection) +
                        (sizeof(group_subject-({ o }))?
                         // this is to fix this example:
                         // M_TARGETS, webster, M_SUBJECT, me,
                         // M_OBJECT, M_PRONOUN, ({ me, webster })
                         ", " + OBJ(group_subject-({ o })) : "") +
                        (object_flag==2?
                         (o->query_plural()?
                          " and yourselves" : " and yourself") :
                         " and you"));
              }
              else {
                return make_list(({ SELF(intersection) }) +
                                 list_objects(group_subject-({ o }), article,
                                              full_flag, possessive_flag, desc,
                                              describe_unowned_flag)+
                                 ({ object_flag==2?
                                    (o->query_plural()?
                                     "yourselves" : "yourself") :
                                    YOU(o, cloak_explained) }));
              }
            }
          }
        }
        else {  // world
          if (possessive_flag) {
            if (pronoun_flag) {
              return POSS(intersection) + " own and " + POSS(group_subject);
            }
            else {
              return make_list(({ POSS(intersection) + " own and " }) +
                               list_objects(group_subject, article, full_flag,
                                            possessive_flag, desc,
                                            describe_unowned_flag));
            }
          }
          else {
            if (pronoun_flag) {
              return SELF(intersection) + " and " + OBJ(group_subject);
            }
            else {
              return make_list(({ SELF(intersection) }) +
                               list_objects(group_subject, article, full_flag,
                                            possessive_flag, desc,
                                            describe_unowned_flag));
            }
          }
        }
      }
    }
    else {  // Subject or world
      if (member(group, o) >= 0) {  // we are part
        if (pronoun_flag) {
          return possessive_flag? "your" : YOU(o, cloak_explained);
        }
        else {
          return make_list(list_objects(group-({ o }), article,
                                        full_flag, possessive_flag, desc,
                                        describe_unowned_flag)+
                           ({ (possessive_flag?
                               "your" :
                               YOU(o, cloak_explained)) }));
        }
      }
      else { // we are not part
        if (pronoun_flag) {
          return possessive_flag? "their" : "they";
        }
        else {
          return make_list(list_objects(group, article, full_flag,
                                        possessive_flag, desc,
                                        describe_unowned_flag));
        }
      }
    }
  }
}

// the following function is in most aspects just a wrapper for
// describe_object(), but when the thing to be described is not an object
// then the given number is taken in account and describe is made.
// this function could also be named describe_object_with_describe_signature()
// or describe_object_or_describe() or something but i think no name could
// be as explanatory as this comment ...
private varargs string describe_maybe_object(mixed what, mixed article,
                                             int full, int count,
                                             status poss_s, mixed subject,
                                             mixed id) {
  if (count > 1)
    return describe(what, article, full, count, poss_s);
  return describe_object(what, id, article, full, subject, poss_s,
                         previous_object());
}

// This returns an array. First element is an array of strings (all to be
// capitalized), the second element is the indention.
private mixed *message2strings(object o, mixed *m,
                               status receiver_is_in_targets,
                               mixed indent, mapping args) {
  mixed g, h;
  status cloak_explained;
  closure desc, simple_desc;
  string *result;
  int i;
  object *subject;
  mixed article;
  status full_flag, object_flag, possessive_flag, pronoun_flag;
  status plural, second_person, simple_describe_flag, describe_unowned_flag;
  string space;  // this is an empty string after a string and a space else.
  string name;

#define INSERT_O_IN_CALLER_STACK  /* this is necessary because at least
                                   * describe_maybe_object() relys on it.
                                   */
#ifdef INSERT_O_IN_CALLER_STACK
  simple_desc = bind_lambda(unbound_lambda(({ 'a,'b,'c,'d,'e,'f,'g,'h }),
                                           ({ bind_lambda(#'funcall, o),
                                              (#'describe),
                                              'a,'b,'c,'d,'e,'f,'g,'h })),
                            o);
#else
  simple_desc = (#'describe);
#endif

#ifdef DESCRIBE_OBJECTS
#  ifdef INSERT_O_IN_CALLER_STACK
  desc = bind_lambda(unbound_lambda(({ 'what,'the,'full,'count,'poss_s,
                                       'subject,'id }),
                                    ({ bind_lambda(#'funcall, o),
                                       (#'describe_maybe_object),
                                       'what,'the,'full,'count,'poss_s,
                                       'subject,'id })),
                     o);
#  else
  desc = (#'describe_maybe_object);
#  endif
#else
  desc = simple_desc;
#endif

#define DESCRIBE_WITH_PLAYER
#ifdef DESCRIBE_WITH_PLAYER
  desc =        lambda(({ 'a,'b,'c,'d,'e,'f,'g,'h }),
                       ({ (#'with_player), o, desc,
                          ({ CL_ARRAY, 'a,'b,'c,'d,'e,'f,'g,'h }) }));
  simple_desc = lambda(({ 'a,'b,'c,'d,'e,'f,'g,'h }),
                       ({ (#'with_player), o, simple_desc,
                          ({ CL_ARRAY, 'a,'b,'c,'d,'e,'f,'g,'h }) }));
#endif

  cloak_explained = 0;
  simple_describe_flag = describe_unowned_flag = 0;
  subject = ({});
  article = ARTICLE_A;
  possessive_flag = full_flag = object_flag = 0;
  result = ({ "" });
  space = "";
  for (i=0; i<sizeof(m); i++) {
    switch (typeof(m[i])) {
    case T_STRING:
      if (receiver_is_in_targets) {
        result[<1] += (article != ARTICLE_A?
                       (space +
                        funcall(simple_desc, m[i], article, full_flag, -1,
                                possessive_flag, subject, 0)) :
                       m[i]);
        space = "";
      }
      break;
    case T_OBJECT:
      if (!receiver_is_in_targets)
        break;
      if (object_flag &&
          ((sizeof(subject)==1 && m[i]==subject[0]) ||
           member(subject, m[i]) >= 0))  // reflexive
        if (m[i] == o)  // we, reflexive
          if (possessive_flag)
            result[<1] += space + "your own";
          else
            result[<1] += space + (o->query_plural()?
                                   "yourselves" : "yourself");
        else  // someone else, reflexive
          if (possessive_flag)
            result[<1] += space + (m[i]->query_possessive() || "its") + " own";
          else
            result[<1] += space + (m[i]->query_plural()? "themselves" : 
                                   (m[i]->query_objective() || "it") + "self");
      else  // not reflexive
        if (m[i] == o)  // we, not reflexive
          if (possessive_flag)
            result[<1] += space + "your";
          else if (object_flag == 2)
            result[<1] += space + (o->query_plural()?
                                   "yourselves" : "yourself");
          else
            result[<1] += space + YOU(o, cloak_explained);
        else  // someone else
          if (pronoun_flag)
            if (object_flag)
              result[<1] += space + (m[i]->query_objective() || "it");
            else if (possessive_flag)
              result[<1] += space + (m[i]->query_possessive() || "its");
            else
              result[<1] += space + (m[i]->query_pronoun() || "it");
          else
            result[<1] += space + (describe_unowned_flag?
                                   describe(m[i], article, full_flag,
                                            possessive_flag) :
                                   funcall((simple_describe_flag?
                                            simple_desc : desc),
                                           m[i], article, full_flag, -1,
                                           possessive_flag, subject, 0));
      space = " ";
      break;
    case T_POINTER:
      if (receiver_is_in_targets)
        if (sizeof(m[i]) == 1)
          result[<1] += space + (describe_unowned_flag?
                                 describe(m[i][0], article, full_flag,
                                          possessive_flag) :
                                 funcall((simple_describe_flag?
                                          simple_desc : desc),
                                         m[i][0], article, 0, full_flag,
                                         possessive_flag, subject, 0));
        else
          result[<1] += space + group2string(o, m[i], subject, object_flag,
                                             pronoun_flag, article,
                                             possessive_flag, full_flag,
#ifdef DESCRIBE_OBJECTS
                                             (simple_describe_flag ?
                                              simple_desc :
                                              lambda(({ 'what,'the,'full,
                                                        'count,'poss_s }),
                                                     ({ (#'funcall),
                                                        desc,
                                                        'what,'the,'full,
                                                        'count,'poss_s,
                                                        quote(subject), 0 }))
                                              ),
#else
                                             desc,
#endif
                                             &cloak_explained,
                                             describe_unowned_flag);
      space = " ";
      break;

    case T_NUMBER:
      // This here must come before the next if ()
      if (m[i] == M_CNTL_SEQ) {
        if (!o->query_property(P_TERMCOL_MODEL) ||  // no colour model,
                                                   // not receiver: ignore!
            !receiver_is_in_targets) {
          i++;
          break;
        }
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_CNTL_SEQ\n");
        if (!stringp(m[i+1]) &&
            !pointerp(m[i+1]))
          raise_error("Bad type of argument 1 to token M_CNTL_SEQ: " +
                      m[i+1] + "!\n");
        h = LIB_CNTL_SEQUENCES->get_colour_code(m[i+1], o);
        if (pointerp(h)) {
          h -= ({ 0 });
          if (sizeof(h))
            h = implode(h, "");
          else
            h = 0;
        }
        if (h)
          result[<1] += h;
        i++;
        break;
      }

      if (receiver_is_in_targets)
        switch (m[i]) {
        case M_EXCLUDE:
          receiver_is_in_targets = ((member(m[++i], o) < 0) &&
                                    receiver_is_in_targets);
          break;
        case M_TARGETS:
          receiver_is_in_targets = (member(m[++i], o) >= 0);
          break;
        case M_SUBJECT:
          subject = m[++i];
          if (objectp(subject))
            subject = ({ subject });
          break;
        case M_OBJECT:
          object_flag = 1;
          continue;  // to retain the set `object_flag'
        case M_ACTIVE_OBJECT:
          object_flag = 2;
          continue;  // to retain the set `active_object_flag'
        case M_ARTICLE:
          article = m[++i];
          continue;  // to retain the set `article'
        case M_FULL:
          full_flag = 1;
          continue;  // to retain the set `full_flag'
        case M_S:
          possessive_flag = 1;
          continue;  // to retain the set `s_flag'
        case M_PRONOUN:
          pronoun_flag = 1;
          continue;  // to retain the set `pronoun_flag'
        case M_SIMPLE_DESCRIBE:
          simple_describe_flag = 1;
          continue;  // to retain the set flag
        case -500:  // M_DESCRIBE_UNOWNED is a combination
          describe_unowned_flag = 1;
          continue;  // to retain the set flag
        case M_CAPITALIZE:
          result[<0..<1] = ({ "" });
          break;
        case M_INDENT:
          indent = m[++i];
          break;
        case M_DESCRIBE_FUNCTION:
          desc = bind_lambda(unbound_lambda(({ 'a,'b,'c,'d,'e,'f,'g,'h }),
                                            ({ bind_lambda(#'funcall, o),
                                               m[++i],
                                               'a,'b,'c,'d,'e,'f,'g,'h })),
                             o);
          break;
        case M_ADD:
          if (mappingp(m[++i])) {  // mapping version?
            if (h=m[i][o])  // this receiver especially mentioned in m[i]?
              result[<1] += h;
            else  // no, then give him the default m[i][0]
              result[<1] += m[i][0];
          }
          else if (closurep(m[i])) {  // closure version?
            result[<1] += apply(m[i], o, args, m[i+1]);
            i++;
          }
          else {  // no, array-version
            if (!pointerp(m[i]))  // assertion
              raise_error("M_ADD with neither mapping nor closure nor"
                          " array\n");
            i++;
            if ((objectp(m[i]) && o==m[i]) ||
                (pointerp(m[i]) && member(m[i], o) >= 0))
              if (pointerp(m[i-1][0]))
                result[<1] += fold_left(#'+, transpose_array(m[i-1])[0], "");
              else
                result[<1] += m[i-1][0];
            else
              if (pointerp(m[i-1][0]))
                result[<1] += fold_left(#'+, transpose_array(m[i-1])[1], "");
              else
                result[<1] += m[i-1][1];
          }
          space = "";
          break;
        case M_ADVERBS:
          if (h="bin/soul"->query_current_adverb_string()) {
            result[<1] += space + h;
            space = " ";
          }
          break;
        case M_SPACE:
          space = " ";
          break;
        case M_VERB:
          if (!pointerp(m[++i]))
            h = ({ m[i] });
          else {
            h = m[i];
            "etc/filer"->log_file("message.verbs", ctime() + ": " +
                                  object_name(previous_object(1)) + "\n");
          }
          // unfortunately the nasty behaviour of putting a space before the
          // verb to spare the extra string " " makes it necessary to remove
          // it now.
          if (space == " ")
            h = map(h, (: $1[0]==' '? $1[1..] : $1 :));
          plural = (objectp(m[i+1])?
                    m[i+1]->query_plural() :
                    (pointerp(m[i+1]) &&
                     (sizeof(m[i+1]) > 1 ||
                      (sizeof(m[i+1]) == 1 &&
                       objectp(m[i+1]) &&
                       m[i+1][0]->query_plural()))));
          second_person = (objectp(m[i+1])?
                           (o==m[i+1]) :
                           (pointerp(m[i+1]) &&
                            member(m[i+1], o) >= 0));
          // conjugate the verb:
          if (!second_person)   // third_person
            if (!plural)        // third_person, singular
              h = map(h, symbol_function("third_person_s", LIB_LANGUAGE));
            else                // third_person, plural
              h = map(h, symbol_function("second_person", LIB_LANGUAGE));
          // this is a very cheap and ugly solution for the case that
          // plurals do something and are seen by others.  this is always
          // the same as the second_person (be -> they are).
          else                  // second_person
            h = map(h, symbol_function("second_person", LIB_LANGUAGE));
          result[<1] += space + make_list(h);
          subject = m[++i];
          if (!pointerp(subject))
            subject = ({ subject });
          space = " ";
          break;
        case M_DELAY:
        case M_PRESENT:
        case M_ALWAYS:
        case M_DEFAULT:
#define RAISE_ERRORS
#ifdef RAISE_ERRORS
          raise_error("Unimplemented feature in message: " + m[i] + "\n");
#else
          __MASTER_OBJECT__->runtime_error("Unimplemented feature in"
                                           " message: " + m[i] + "\n",
                                           __FILE__,object_name(this_object()),
                                           __LINE__);
#endif
          break;
        default:
          if (receiver_is_in_targets)
            result[<1] += space + to_string(m[i]);
          space = " ";
          break;
      }
      else
        switch (m[i]) {
        case M_TARGETS:
          receiver_is_in_targets = (member(m[++i], o) >= 0);
          break;
      }
    }
    article = ARTICLE_A;
    (simple_describe_flag =
     describe_unowned_flag =
     pronoun_flag =
     possessive_flag =
     full_flag = 0);
    object_flag = 0;
  }
  return ({ result, indent });
}

// this is a mapping of receivers pointing on unfinished messages.
private mapping unfinished_messages = ([]);

private int last_message_length;

public int query_last_message_length() { return last_message_length; }

/*
 * This is the function that is called for each reciever to receive a
 * message. It tries to send the message arrays itself to the receiver's
 * receive_message() but builds the string itself if there is no such
 * function.
 */
private varargs void receive_message(object o, mixed m,
                                     status receiver_is_in_targets,
                                     mapping viewers, mapping args) {
  mixed h;
  mixed old;
  int indent;
  status continued;
  if (!o)
    return;
  // does the receiving object have an own function to handle the message?
  if (!objectp(o))
    raise_error(sprintf("receiver is no object: %O\n", o));
  if (call_resolved(&h, o, "receive_message",
                    m, receiver_is_in_targets, viewers, args))
    return;  // yes, it has.  our work is done here.
  // does the receiving object have any means to get the string?
  if (!interactive(o) && !function_exists("catch_tell", o))
    return;  // no, it has not.  so we can abort here.
  if (stringp(m))
    m = ({ m });
  if (continued=(sizeof(m) && m[<1]==M_CONTINUED))
    m[<1..<1] = ({});
  // is there an unfinished (dangling) message for this receiver?
  if (old=unfinished_messages[o]) {
    h = message2strings(o, m, receiver_is_in_targets, old[1], args);
    h = ({ old[0][0..<2] + ({ old[0][<1]+h[0][0] }) + h[0][1..], h[1] });
  }
  else
    h = message2strings(o, m, receiver_is_in_targets, 2, args);
  if (!continued && viewers && member(viewers, o) && strlen(h[0][0])) {
    if (sizeof(viewers[o]) > 1 ||
        !member(viewers[o], "directly"))
      h[0][0] = make_list(m_indices(viewers[o])) + ", " + h[0][0];
  }
  if (continued)
    unfinished_messages[o] = h;
  else {
    m_delete(unfinished_messages, o);
#if 1  // 1 as long as there's no M_NO_CAPITALIZE yet
    m = implode(map(h[0], #'capitalize_coloured), "");
#else
    if (sizeof(h[0]) == 1)
      m = h[0][0];
    else
      m = implode(map(h[0], #'capitalize_coloured), "");
#endif
    if (!strlen(m))
      return;
    if (o == this_player())
      last_message_length = strlen(m);
    indent = h[1];
    h = call_other(o, "query_property", P_DISPLAY_WIDTH);
    if (h)
      // with_player() is used to ensure that o's toggle state for the colour
      // model is used
      // h-1 --> h
      m = with_player(o, #'break_string, ({ m, h, indent, -1 }));
    m += "\n";
    if (!call_resolved(&h, o, "catch_tell", m))
      tell_object(o, m);
  }
}

/*
 * This function returns the default active object; it depends only on the
 * previous_object(), but if you wish to change this behaviour this might
 * make sense.
 */
private varargs object default_active_object(object previous, object tp) {
  mixed a, b;
  if (previous->query_property(P_ROOM))
    return previous;
  tp = tp || this_player();
  if (!tp || living(previous) ||
      (previous==(a=environment(tp)) ||
       (b=environment(previous))==tp ||
       b==a))
    return previous;
  else
    return tp;
}

/*
 * Depending on the active_object this function returns the object that should
 * be declared as the message room for this message (might be the room around
 * the player the sending object is in or so).
 */
private object default_room(object active_object) {
  object e;
  for (e=active_object; e; e=environment(e))
    if (living(e))
      return environment(e) || e;
  return environment(active_object) || active_object;
}

/*
 * This functions gets the message room and returns a mapping (width 0) of the
 * receivers that hear the message in this room.
 */
private varargs mapping receivers_of_room(mixed room, mapping viewers) {
  mixed h;
  if (stringp(room))
    room = find_object(room);
  if (!room)
    return ([]);
  else {
    mapping viewing_rooms;
    mapping result;
    if (!mappingp(viewers) || !referencep(&viewers))
      raise_error("Bad argument 2 to receivers_of_room()\n");
    result = mkmapping(filter(all_inventory(room) + ({ room }), #'living));
    foreach (object target : result)
      if (viewers[target])
        viewers[target] += ([ "directly" ]);
      else
        viewers[target] = ([ "directly" ]);
    viewing_rooms = room->query_viewers();
    if (!viewing_rooms)
      return result;
    // otherwise modify the viewers properly:
    foreach (object viewing_room : viewing_rooms) {
      object *livings;
      mixed dirs;
      livings = filter(all_inventory(viewing_room) + ({ viewing_room }),
                       (#'living));
      dirs = mkmapping(viewing_room->query_view(object_name(room)) || ({}));
      foreach (object living : livings) {
        if (viewers[living])
          viewers[living] += dirs;
        else
          viewers[living] = dirs;
      }
    }
    return result + mkmapping(m_indices(viewers));
  }
}

/*
 * In this first pass M_ARGs, M_MEs, M_PLs, M_ME_ADDs, M_PL_ADDs, M_ME_VERBs,
 * M_PL_VERBs and the closures are evaluated, the argument m is changed and
 * should be given as reference parameter but it is returned as well.
 */
public varargs mixed *simplify_message_pass1(mixed m, mapping arguments) {
  mixed h;
  int i;
  string speak_tongue;

  for (i=0; i<sizeof(m); i++) {
    while (closurep(m[i]))
      m[i] = funcall(m[i]) || "";  // do not give out 0 but everything else
    if (m[i] == M_CANCEL)
      return ({ M_CANCEL });  // we let the token in to let the second
                              // simplification pass remove all pending
                              // messages.
    if (pointerp(m[i])) {
      m[i] = map(m[i], bind_lambda(#'funcall, previous_object()));
      if (sizeof(m[i]) == 1 && objectp(m[i][0]))
        m[i] = m[i][0];
    }
    else if (intp(m[i])) {
      switch (m[i]) {
      case M_SAYS:
        if (sizeof(m) < i+1)
          raise_error("Too few arguments to token M_SAYS\n");
        if (!(speak_tongue=
              (previous_object()->query_last_referenced_tongue() ||
               previous_object()->query_tongue())))
          "etc/filer"->log_file("TONGUE",
                                ctime() + ": " +
                                object_name(previous_object()) +
                                ", standing in " +
                                (environment(previous_object()) &&
                                 object_name(environment(previous_object()))) +
                                ", has no tongue\n");
        command("say in " + speak_tongue + " " +
                message2string(m[i+1..], previous_object(),
                               arguments), previous_object());
        m[i..] = ({});
        i--;  // redo at this point
        break;
      case M_SAYS_TO:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_SAYS_TO\n");
        if (!(speak_tongue=
              (previous_object()->query_last_referenced_tongue() ||
               previous_object()->query_tongue())))
          "etc/filer"->log_file("TONGUE",
                                ctime() + ": " +
                                object_name(previous_object()) +
                                ", standing in " +
                                (environment(previous_object()) &&
                                 object_name(environment(previous_object()))) +
                                ", has no tongue\n");
        command("to " + m[i+1]->query_real_name() + " say in " + speak_tongue +
                " " + message2string(m[i+2..], previous_object(), arguments),
                previous_object());
        m[i..] = ({ });
        i--;  // redo at this point
        break;
      case M_ARG:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_ARG\n");
        if (!arguments)
          raise_error("No arguments given for this message\n");
        if (h=catch(m[i+1..] = simplify_message_pass1(m[i+1..], arguments))) {
          if (is_wizard(this_player(), IW_TOOLUSER))
            printf("message was %O\n", m[i+1..]);
          else
            "etc/filer"->log_file("MESSAGE",
                                  sprintf("%s: %O\n", ctime(), m[i+1..]));
          raise_error(h);
        }
        m[i..i+1] = ({ arguments[m[i+1]] });
        i--;  // evaluate this again, please
        break;
      case M_CLASS:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_CLASS\n");
        i++;  // to avoid evaluation of the argument given to M_CLASS
        break;
      case M_SUPPRESS_VIEW:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_SUPPRESS_VIEW\n");
        i++;  // to avoid evaluation of the argument given to M_SUPPRESS_VIEW
        break;
      case M_DESCRIBE_FUNCTION:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_DESCRIBE_FUNCTION\n");
        i++; // to avoid evaluation of the closure given to M_DESCRIBE_FUNCTION
        break;
      case M_APPLY:
        if (sizeof(m) < i+3)
          raise_error("Too few arguments to token M_APPLY\n");
        if (h=catch(m[i+2..] = simplify_message_pass1(m[i+2..], arguments))) {
          if (is_wizard(this_player(), IW_TOOLUSER))
            printf("message was %O\n", m[i+2..]);
          raise_error(h);
        }
        h = apply(m[i+1], m[i+2]);
        m[i..i+2] = (pointerp(h)? h : ({ h || "" }));
        i--;
        break;
      case M_APPLY_WITH_ARGS:
        if (sizeof(m) < i+3)
          raise_error("Too few arguments to token M_APPLY_WITH_ARGS\n");
        if (h=catch(m[i+2..] = simplify_message_pass1(m[i+2..], arguments))) {
          if (is_wizard(this_player(), IW_TOOLUSER))
            printf("message was %O\n", m[i+2..]);
          raise_error(h);
        }
        h = apply(m[i+1], arguments, m[i+2]);
        m[i..i+2] = (pointerp(h)? h : ({ h || "" }));
        i--;
        break;
      case M_APPLY_FUNCTION:
        if (sizeof(m) < i+3)
          raise_error("Too few arguments to token M_APPLY_FUNCTION\n");
        if (h=catch(m[i+2..] = simplify_message_pass1(m[i+2..], arguments))) {
          if (is_wizard(this_player(), IW_TOOLUSER))
            printf("message was %O\n", m[i+2..]);
          raise_error(h);
        }
        h = apply_function(m[i+1], m[i+2]);
        m[i..i+2] = (pointerp(h)? h : ({ h || "" }));
        i--;
        break;
      case M_APPLY_FUNCTION_WITH_ARGS:
        if (sizeof(m) < i+3)
          raise_error("Too few arguments to token"
                      " M_APPLY_FUNCTION_WITH_ARGS\n");
        if (h=catch(m[i+2..] = simplify_message_pass1(m[i+2..], arguments))) {
          if (is_wizard(this_player(), IW_TOOLUSER))
            printf("message was %O\n", m[i+2..]);
          raise_error(h);
        }
        h = apply_function(m[i+1], arguments, m[i+2]);
        m[i..i+2] = (pointerp(h)? h : ({ h || "" }));
        i--;
        break;
      case M_CALL:
        if (sizeof(m) < i+3)
          raise_error("Too few arguments to token M_CALL\n");
        if (h=catch(m[i+2..] = simplify_message_pass1(m[i+2..], arguments))) {
          if (is_wizard(this_player(), IW_TOOLUSER))
            printf("message was %O\n", m[i+2..]);
          raise_error(h);
        }
        apply(m[i+1], m[i+2]);
        m[i..i+2] = ({});
        i--;
        break;
      case M_ME:
        m[i] = previous_object();
        break;
      case M_PL:
        m[i] = this_player();
        break;
      case M_ADD:  // just skip the (maybe) closure ahead
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_ADD\n");
        if (mappingp(m[i+1]))
          i += 1;
        else {  // closure or array
          if (sizeof(m) < i+3)
            raise_error("Too few arguments to token M_ADD\n");
          i += 2;
        }
        break;
      case M_ME_ADD:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_ME_ADD\n");
        m[i..i+1] = ({ M_ADD, m[i+1], previous_object() });
        i += 2;
        break;
      case M_PL_ADD:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_PL_ADD\n");
        m[i..i+1] = ({ M_ADD, m[i+1], this_player() });
        i += 2;
        break;
      case M_ME_VERB:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_ME_VERB\n");
        m[i..i+1] = ({ M_VERB, m[i+1], previous_object() });
        i += 2;
        break;
      case M_PL_VERB:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_PL_VERB\n");
        m[i..i+1] = ({ M_VERB, m[i+1], this_player() });
        i += 2;
        break;
      }
    }
  }
  return m;
}

public varargs mixed simplify_message_pass2(mixed m, mapping targets,
                                            mixed class, mapping viewers) {
  mixed h;
  int i;
  mixed article;
  status full_flag;
  if (!referencep(&targets))
    raise_error("Argument 2 to simplify_message_pass2() is no reference\n");
  if (class && !referencep(&class))
    raise_error("Argument 3 to simplify_message_pass2() is given but no"
                " reference\n");
  article = ARTICLE_A;
  full_flag = 0;
  for (i=0; i<sizeof(m); i++) {  // pass for several tokens
    switch (typeof(m[i])) {
    case T_NUMBER:
      switch (m[i]) {
      case M_CLASS:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_CLASS\n");
        class = m[i+1];
        m[i..i+1] = ({});
        i--;
        break;
      case M_DESCRIBE_GROUP:
        if (sizeof(m) < i+3)
          raise_error("Too few arguments to token M_DESCRIBE_GROUP\n");
        h = m[i+2];
        if (objectp(h))
          h = ({ h });
        m[i..i+2] = ({ LIB_LANGUAGE->describe_group_of(m[i+1], h) });
        break;
      case M_TARGETS:
        viewers = ([]);  // don't use viewers when targets are given directly
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_TARGETS\n");
        if (!pointerp(m[++i]))
          m[i] = ({ m[i] });
        targets += filter_indices(mkmapping(m[i]), #'living);
        break;
      case M_EXCLUDE:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_EXCLUDE\n");
        if (!pointerp(m[++i]))
          m[i] = ({ m[i] });
        break;
      case M_ROOM:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_ROOM\n");
        viewers = ([]);  // forget all of the before
        if (pointerp(m[++i])) {
          h = map(m[i], (: receivers_of_room($1, &$2) :), &viewers);
          h = fold_left(#'+, h, ([]));
        }
        else
          h = receivers_of_room(m[i], &viewers);
        targets += h;
        m[i-1] = M_TARGETS;
        m[i] = m_indices(h);
        break;

      case M_SUPPRESS_VIEW:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_SUPPRESS_VIEW\n");
        m[i] = M_EXCLUDE;
        ++i;
        h = ({});
        if (pointerp(m[i]))
          foreach (object viewer : m_indices(viewers)) {
            if (member(m[i], environment(viewer)) >= 0)
              h += ({ viewer });
          }
        else
          foreach (object viewer : m_indices(viewers))
            if (environment(viewer) == m[i])
              h += ({ viewer });
        m[i] = h;
        break;

      case M_ARTICLE:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_ARTICLE\n");
        article = m[++i];
        continue;  // retain the set `article'
      case M_FULL:
        full_flag = 1;
        continue;  // retain the set `full_flag'

      case M_DESCRIBE_FUNCTION: //the receivers should get the describe-closure
        // no check here because simplify_message_pass1() already checks
        i++;
        break;

      case M_DESCRIBE:
        if (sizeof(m) < i+2)
          raise_error("Too few arguments to token M_DESCRIBE\n");
        if (pointerp(m[i+1]))
          m[i..i+1] = ({ make_list(list_objects(m[i+1], article, full_flag),
                                   "nobody") });
        else
          m[i..i+1] = ({ describe(m[i+1], article, full_flag) || "someone" });
        break;
      case M_CANCEL:
        unfinished_messages -= targets;
        return 0;  // how brute
      }
    }
    article = ARTICLE_A;
    full_flag = 0;
  }
  return m;
}

/*
 * This builds a message together for a single receiver. The message may from
 * now on contain M_DESCRIBEs but no M_CONTINUEDs since they do not make much
 * sense in this context
 */
public varargs string message2string(mixed *m, object o, mapping args) {
  mixed h;
  mapping targets;
  targets = ([ o ]);
  h = simplify_message_pass1(m, args);
  h = simplify_message_pass2(h, &targets);
  if (!h)  // cancelled?
    return "";
  h = message2strings(o || this_player() || find_object(MASTER),
                      h, 1, 0, args)[0];
  return h[0] + implode(map(h[1..], #'capitalize_coloured), "");
}

public varargs void send_message(mixed m, mapping arguments,
                                 mixed active_or_targets) {
  mixed h;
  int i, j;
  mapping targets, starting_targets, viewers;
  mixed class, initial_class_dummy;

  viewers = ([]);
  if (mappingp(active_or_targets))
    targets = active_or_targets;
  else if (objectp(active_or_targets))
    targets = receivers_of_room(default_room(active_or_targets), &viewers);
  else {
    h = default_active_object(previous_object());
    targets = receivers_of_room(default_room(h), &viewers);
  }
  if (stringp(m))
    return (map_indices(targets, #'receive_message, m, 1, viewers, arguments),
            0);
  starting_targets = copy(targets);
  initial_class_dummy = class = m_allocate(0, 0);
  if (h=catch(m = simplify_message_pass1(m, arguments))) {
    debug_message(sprintf("message was %O\n", m));
    raise_error(sprintf("Re-raising error caught while simplifying bad"
                        " message: %s", h));
  }
  m = simplify_message_pass2(m, &targets, &class, &viewers);
  if (!m)  // cancelled?
    return;
  if (class != initial_class_dummy) {  // a class was given
    targets -= filter_indices(targets, (: $1->message_unwanted($2) :), class);
    starting_targets -= starting_targets - targets;
  }
  map_indices(starting_targets,
              (#'receive_message), m, 1, viewers, arguments);
  map_indices(targets - starting_targets,
              (#'receive_message), m, 0, viewers, arguments);
}

private mapping message_busy_objects = ([]);

varargs int query_message_busy(object o) {
  return message_busy_objects[o || previous_object()];
}

private varargs void message_2(mixed m, mapping arguments,
                               mixed presence_necessary, mixed *pre, int delay,
                               object previous, object active) {
  mixed h;
  int i;
  if (!previous)  // object might be destructed
    return;
  if (!pointerp(m)) {
    if (this_player() && query_once_interactive(this_player()))
      this_player()->tell_more(m);
    else
      write(break_string(m));
  }
  else
    for (i=0; i<sizeof(m); i++) {
      while (closurep(m[i]))
        m[i] = funcall(bind_lambda(#'funcall, previous), m[i]);
      if (mappingp(m[i]))
        arguments = m[i];
      else if (intp(m[i]))
        if (m[i] > 0)
          return call_out(#'message_2, m[i], m[i+1..], arguments,
                          presence_necessary, pre, delay, previous, active);
        else if (!m[i])
          ;  // do nothing (the 0 will probably be the result of a closure)
        else
          switch (m[i]) {
          case M_CANCEL:  // somebody wants to cancel the remaining messages
            if (!(--message_busy_objects[previous]))
              m_delete(message_busy_objects, previous);
            return;
          case M_PRE:
            if (sizeof(m) < i+2)
              raise_error("Too few arguments to token M_PRE\n");
            pre = m[++i];
            break;
          case M_INDENT:
            if (sizeof(m) < i+2)
              raise_error("Too few arguments to token M_INDENT\n");
            if ((h=member(pre, M_INDENT)) >= 0)
              pre[h+1] = m[++i];
            else
              pre += ({ M_INDENT, m[++i] });
            break;
          case M_DELAY:
            if (sizeof(m) < i+2)
              raise_error("Too few arguments to token M_DELAY\n");
            delay = m[++i];
            break;
          case M_PRESENT:
            presence_necessary = this_player();
            break;
          case M_ALWAYS:
            presence_necessary = 0;
            break;
          case M_DEFAULT:
            if ((h=member(pre, M_INDENT)) >= 0)
              pre[h..h+1] = ({});
            delay = 0;
            presence_necessary = 0;
            break;
          default:
#ifdef RAISE_ERRORS
            raise_error("Unimplemented feature in message: " + m[i] + "\n");
#else
            __MASTER_OBJECT__->runtime_error("Unimplemented feature in"
                                             " message: " + m[i] + "\n",
                                             __FILE__,
                                             object_name(this_object()),
                                             __LINE__);
#endif
            break;
          }
      else if (pointerp(m[i]) || stringp(m[i])) {
        if (!presence_necessary ||
            presence_necessary == previous ||
            environment(presence_necessary) == previous ||
            presence_necessary == environment(previous) ||
            environment(presence_necessary) == environment(previous)) {
          funcall(bind_lambda(#'funcall, previous), #'send_message,
                  (stringp(m[i])? m[i] : pre+m[i]), arguments, active);
          if (delay)
            return call_out(#'message_2, delay, m[i+1..], arguments,
                            presence_necessary, pre, delay, previous, active);
        }
        else
          break;
      }
    }
  if (!(--message_busy_objects[previous]))
    m_delete(message_busy_objects, previous);
}

varargs void message(mixed m, object player) {
  message_busy_objects[previous_object()]++;
  if (player)
    with_player(player, #'message_2,
                ({ m, ([]), 0, ({}), 0, previous_object(),
                   default_active_object(previous_object(), player) }));
  else
    message_2(m, ([]), 0, ({}), 0, previous_object(),
              default_active_object(previous_object()));
}

void write(mixed msg) {
  if (stringp(msg) && this_player() && query_once_interactive(this_player()))
    efun::write(terminal_colour(msg,
                                this_player()->get_terminal_colour_closure() ||
                                this_player()->get_terminal_colour_mapping()));
  else
    efun::write(msg);
}


varargs void say(mixed msg, mixed excl) {
  if (stringp(msg)) {
    msg = LIB_CNTL_SEQUENCES->to_verbatim(msg);
  }
  else {
    map(msg, (: stringp($1)? LIB_CNTL_SEQUENCES->to_verbatim($1) : $1 :));
  }
  if (excl)
    return efun::say(msg, excl);
  else
    return efun::say(msg);
}

void tell_object(object ob, string msg) {
  if (stringp(msg) && ob)
    efun::tell_object(ob,
                      terminal_colour(msg,
                                      (living(ob) &&
                                       ob->get_terminal_colour_closure() ||
                                       ob->get_terminal_colour_mapping()) ||
                                      LIB_CNTL_SEQUENCES->
                                      get_plain_mapping()));
  else
    efun::tell_object(ob, msg);
}

varargs void map_messages(mapping m, mapping args, mixed targets) {
  mixed h;
  h = flatten_array(m_indices(m)) - ({ 0 });
  h = sizeof(h)? ({ M_EXCLUDE, h }) : ({});
  if (targets)
    send_message(({ M_TARGETS, targets }) + h + m[0], args);
  else if (m[0])
    send_message(h + m[0], args);
  walk_mapping(m - ([ 0 ]), (: send_message(({ M_TARGETS, $1 }) + $2, $3) :),
               args);
}

