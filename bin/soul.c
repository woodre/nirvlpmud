/*
 * Everybody needs a soul, or they will wind up being called Wayne or Garth
 * Written by Profezzorn
 *
 * several changes for Tubmud done by Carador, 1993/1994
 * some ideas for verbs by Ereborn (taken from his Extended Soul)
 * a lot of other ideas for verbs and adverbs by a lot of other people
 * Everything embedded in #ifdef INTERMUD3 by Fafnir 1997-Dec-18
 * Completely updated and changed to use the message system, Coogan, Nov 2000
 *
 */

#pragma strong_types
#pragma no_shadow
#pragma no_inherit

#include <describe.h>
#include <event.h>
#include <libs.h>
#include <regexps.h>
#include <prop/player.h>
#include <message.h>
#include <closures.h>
#ifdef INTERMUD3
#include <imud3.h>
#endif
#include <termcol.h>    // Coogan, 25-Nov-2003
#include <money.h>
#include <server.h>
#include <intermud.h>

#ifdef MORE
#undef MORE
#endif
#define MORE(X,Y) (this_player()->view_text(X,Y), this_player()->start_view())

#define S_VERB           10
#define S_HOW            20  // argument of S_HOW can be of type string or array
#define S_AT             30
#define S_TARGET         40
#define S_BODY           50  // a bodypart
#define S_TEXT           60
#define S_OBJECT         70  // followed by S_TARGET or S_AGENT
#define S_POSSESSIVE     80  // followed by S_TARGET or S_AGENT
#define S_MESSAGE        90
#define S_THE_AGENT     100  // will be expanded to M_THE, this_player()
                             // Alfe 2002-Jan-31
#define S_ADD_VERB      110  // ({ S_ADD_VERB, "verb", 
#define S_AGENT         120  // this_player()   Alfe 2002-Jan-31
#define S_S             130  // followed by S_TARGET or S_AGENT
#define S_PRONOUN       140  // followed by S_TARGET or S_AGENT
#define S_BODY_TARGET   150  // followed by S_BODY, to give a target for the
                             // next bodypart but not to mention the target
                             // explicitely also with name in the message
#define S_REAL_VERB     160  // this is for internal use only, to keep knowledge
                             // about the real verb in case of feeling
                             // changers like "try", "don't", "fail" etc.

#define _F_EVENT     0
#define _F_RECEIVED  1
#define _F_MESSAGE   2

inherit "basic/daemon";
inherit "basic/name";
inherit "bin/tools/intermud_soul";
inherit "basic/create";

private static string* current_adverb_list = 0;
private static object  current_this_player;
private static string  current_commandline;
private static mapping how=([]), bodydata=([]);
private static mapping modificator_list;
private static mapping global_feeling_event, remote_targets;
private static string  verb_string, adverb_string, bodypart_string;
private static string  feeling_kind;
private static object* channel_listeners;
private static int     remote;
private static object *env_list, *inv_list;
private static mapping map_id, map_fakeitem;
private static mapping has_soul_add;

varargs void feel(mixed *d, int flag);
int do_feel(string p);
int feeling(string p);


///////////////////////////////////////////////////////////////////
//
// some wrapper functions for LIB_SOUL

mixed* get_rules(string verb) {
  return LIB_SOUL->get_rules(verb);
}

mixed* get_matching_rule(string verb, object *who, string *adv,
                         string message, string *body) {
  return LIB_SOUL->get_matching_rule(verb, who, adv, message, body);
}

string* get_verbs() {
  return LIB_SOUL->get_verbs();
}

string* get_adverbs() {
  return LIB_SOUL->get_all_adverbs(this_player());
}

status query_is_verb(string v) {
  return LIB_SOUL->query_is_verb(v);
}

status query_is_adverb(string w) {
  return LIB_SOUL->query_is_adverb(w);
}

///////////////////////////////////////////////////////////////////

varargs string implode_nicely(string *dum, string last_word) {
  /* second, optional argument added by Carador, 13-Sep-1993 */
  return make_list(dum, "nothing", last_word);
}

mapping get_modificator_list() {
  if (sizeof(modificator_list))
    return modificator_list;
  else
    return ([ "again", 
              "almost", 
              "also", 
              "anyway",
              "but",
              "dont", 
              "don't", 
              "fail", 
              "not", 
              "refuse", 
              "still", 
              "suddenly", 
              "too", 
              "try", 
              "trynot", 
           ]);
}

// this mapping is only for 'help soul'. If you want to change the bodydata,
// do that in get_bodydata_for_verb() below.
mapping get_bodydata() {
  if (sizeof(bodydata))
    return bodydata;
  return ([
            "arm"        : "on the arm",
            "back"       : "on the back",
            "beard"      : "through the beard",
            "behind"     : "on the behind",
            "butt"       : "in the butt",
            "cheek"      : "on the cheek",
            "chest"      : "on the chest",
            "chin"       : "on the chin",
            "ear"        : "on the ear",
            "erm"        : "on the ... erm ...",  // Alfe 1997-May-16
            "everywhere" : "everywhere",
            "eye"        : "in the eye",
            "eyebrow"    : "on the eyebrow",
            "face"       : "in the face",
            "foot"       : "on the foot",
            "forehead"   : "on the forehead",
            "hand"       : "on the hand",
            "head"       : "on the head",
            "hurts"      : "where it hurts",
            "leg"        : "on the leg",
            "lips"       : "on the lips",
            "mouth"      : "on the mouth",
            "neck"       : "in the neck",
            "nose"       : "on the nose",
            "rib"        : "in the ribs",
            "shoulder"   : "on the shoulder",
            "side"       : "in the side",
            "stomach"    : "in the stomach",
            "toe"        : ({ "on ", S_POSSESSIVE, S_TARGET, " right toe" }),
         ]);
}

mixed get_bodydata_for_verb(string verb, string body, status aimed,
                            mixed people, status player_self) {
  string onto;
  mixed result;
  int with_prefix;

  with_prefix = 1;       // Coogan, 15-Feb-2001

  if (verb == "admire"  ||   // Coogan, 23-Aug-2001
      verb == "cover"   ||   // Coogan, 15-Feb-2001
      verb == "close"   ||   // Coogan, 17-Sep-2001
      verb == "cry"     ||   // Coogan, 11-Mar-2003
      verb == "wrinkle" ||   // Coogan, 27-Jul-2006
      verb == "shake"   ||   // Coogan, 31-Aug-2006
      verb == "wipe"    ||   // Coogan, 31-Aug-2006
      verb == "stretch" ||   // Alfe, 2006-Sep-28
      verb == "rub"          // Coogan, 10-Oct-2007
      ) {
    with_prefix = 0;
  }

  // DEBUG_POINT_TP("coogan", ({ verb, body, aimed, people, player_self }));

  result = "";

  switch (body) {
  case "arm":
    switch (verb) {
    case "close":
    case "cover":
    case "cry":
      if (aimed)
        result = "arm";
      else
        result = ({ S_POSSESSIVE, people, " arm" });
      break;
    case "admire":
    case "stretch":  // Alfe 2006-Sep-28
    case "look":
      result  = ({ with_prefix ? "at " : "" });
      result += ({ player_self ? S_POSSESSIVE : S_S });
      result += ({ people, " arm" });
      break;
    case "stroke":
    case "bite":
      if (result == "")
        result = "in the";  // fall through
    default:
      if (result == "" && with_prefix && aimed)
        result = "on ";
      result = ({ result, player_self ? S_POSSESSIVE : S_S, people, " arm" });
      break;
    }
    break;
  case "back":
    switch (verb) {
    case "admire":
    case "stretch":  // Alfe 2006-Sep-28
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " back" });
      break;
    case "kick":
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "")
        result = "on the ";
      if (!with_prefix)
        result = "";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " back" }));
    }
    break;
  case "beard":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " beard" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "through the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " beard" }));
      break;
    }
    break;
  case "behind":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " behind" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " behind" }));
      break;
    }
    break;
  case "butt":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " butt" });
      break;
    case "kiss":
    case "stroke":  // Coogan, 28-Nov-2002
    case "touch":  // Coogan, 28-Nov-2002
      if (with_prefix && result == "")
        result = "on the ";  // fall through
    default:
      if (with_prefix && result == "")
        result = "in the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " butt" }));
      break;
    }
    break;
  case "cheek":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " cheek" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " cheek" }));
      break;
    }
    break;
  case "chest":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "upon " : "" });
      result += ({ S_S, people, " chest" });
      break;
    case "lean":
      result = ({ "on ", player_self ? S_POSSESSIVE : S_S, people, " chest" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " chest" }));
      break;
    }
    break;
  case "chin":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "at " : "" });
      result += ({ S_S, people, " chin" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " chin" }));
      break;
    }
    break;
  case "ear":
    switch (verb) {
    case "close":
      result = "ears";
      break;
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " ear" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " ear" }));
      break;
    }
    break;
  case "erm":
    switch (verb) {
    case "cover":
      if (aimed)
        result = "... erm ...";
      else
        result = ({ S_POSSESSIVE, people, " ... erm ..." });
      break;
    case "hold":
      result = ({ S_OBJECT, people, " on the ... erm ..." });
      break;
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " ... erm ..." });
      break;
    case "raise":
      result = ({ S_POSSESSIVE, people, " ... erm ..." });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ... erm ...";
      else
        result += "... erm ...";
    }
    break;
  case "everywhere":
    switch (verb) {
    case "hold":
      result = ({ S_OBJECT, people, " everywhere" });
      break;
    case "look":
      result = ({ "everywhere on ", people });
      break;
    case "admire":
    case "raise":
      result = ({ "all parts of ", S_OBJECT, people });
      break;
    case "rub":
      if (player_self || aimed)
        result = "body everywhere";
      else
        result = body;
      break;
    default:
      result = "everywhere";
    }
    break;
  case "eye":
    switch (verb) {
    case "cover":
      if (aimed)
        result = "eyes";
      else
        result = ({ S_POSSESSIVE, people, " eyes" });
      break;
    case "admire":
    case "look":
      result = ({ with_prefix ? "into " : "" });
      result += ({ S_S, people, " eyes" });
      break;
    case "kiss":
      result = ({ "on the eyes" });
      break;
    case "close":
      result = "eyes";
      break;
    default:
      if (with_prefix)
        result = "in the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " eye" }));
      break;
    }
    break;
  case "eyebrow":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "at " : "" });
      result += ({ S_S, people, " eyebrow" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : "an eyebrow");
      break;
    }
    break;
  case "face":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "into " : "" });
      result += ({ S_S, people, " face" });
      break;
    case "stroke":
      result = ({ "over ", S_POSSESSIVE, people, " face" });
      break;
    default:
      if (with_prefix)
        result = "in the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " face" }));
      break;
    }
    break;
  case "foot":
    switch (verb) {
    case "admire":
    case "look":    
      result = ({ with_prefix ? "at " : "" });
      result += ({ S_S, people, " foot" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
     if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " foot" }));
      break;
    }
    break;
  case "forehead":
    switch (verb) {    
    case "admire":
    case "look":        
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " forehead" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:    
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body
                      : ({ S_POSSESSIVE, people, " forehead" }));
      break;
    }
    break;
  case "hand":
    switch (verb) { 
    case "admire":
    case "look":    
      result = ({ with_prefix ? "at " : "" });
      result += ({ S_S, people, " hand" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:        
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " hand" }));
      break;
    }
    break;
  case "head":
    switch (verb) {     
    case "admire":
    case "look":        
      result = ({ with_prefix ? "at " : "" });
      result += ({ S_S, people, " head" });
      break;
    case "rub":
      if (aimed)
        result = body;
      else
        result = ({ S_OBJECT, people, " on the head" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : "on the head");
      break;
    }
    break;
  case "hurts":
    switch (verb) {
    case "hold":
      result = ({ S_OBJECT, people, " where it hurts" });
      break;
    case "look":    
      result = ({ "at ", people, " where it hurts" });
      break;            
    case "admire":
    case "raise":
      result = ({ "all of ", S_OBJECT, people, " that hurts" });
      break;
    case "cover":  // Coogan, 15-Feb-2001
    case "rub":
      if (aimed)
        result = ({ "body where it hurts" });
      else
        result = ({ S_OBJECT, people, " where it hurts" });
      break;
    case "close":
      result = ({ "body where it hurts" });
      break;
    default:
      result = "where it hurts";
      break;
    }
    break;
  case "leg":
    switch (verb) { 
    case "admire":
    case "look":    
      result = ({ with_prefix ? "upon " : "" });
      result += ({ S_S, people, " leg" });
      break;
    case "close":
      result = "legs";
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " leg" }));
      break;
    }
    break;
  case "lips":
    switch (verb) {
    case "admire":
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " lips" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " lips" }));
      break;
    }
    break;
  case "mouth":
    switch (verb) {    
    case "admire":
    case "look":    
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " mouth" });
      break;    
    case "bite":
      result = "in the ";  // fall trough!
    default:    
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " mouth" }));
      break;
    }
    break;
  case "neck":
    switch (verb) {    
    case "admire":
    case "stretch":  // Alfe 2006-Sep-28
    case "look":    
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " neck" });
      break;    
    default:    
      if (with_prefix)
        result = "in the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " neck" }));
      break;
    }
    break;
  case "nose":
    switch (verb) {    
    case "admire":
    case "look":    
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " nose" });
      break;    
    case "bite":
      result = "in the ";  // fall trough!
    default:    
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " nose" }));
      break;
    }
    break;
  case "rib":
    switch (verb) {
    case "close":
      result = "ribs";
      break;
    case "admire":
    case "look":        
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " ribs" });
      break;
    case "touch":
      result = "on the ";  // fall through
    default:
      if (verb != "touch")
        result = "in the ";  // fall through
    case "cover":
      result = (aimed ? result + "ribs" : ({ S_POSSESSIVE, people, " ribs" }));
      break;
    }
    break;
  case "shoulder":
    switch (verb) {
    case "admire":
    case "stretch":  // Alfe 2006-Sep-28
    case "look":
    case "lean":
      result = ({ with_prefix ? "on " : "" });
      result += ({ player_self ? S_POSSESSIVE : S_S, people, " shoulder" });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix)
        result = "on the ";
      result = (aimed ? result + body
                      : ({ S_POSSESSIVE, people, " shoulder" }));
      break;
    }
    break;
  case "side":
    switch (verb) {    
    case "admire":
    case "stretch":  // 2006-Sep-28
    case "look":
    case "lean":
      result = ({ with_prefix ? "on " : "" });
      result += ({ player_self ? S_POSSESSIVE : S_S, people, " side" });
      break;    
    default:    
      if (with_prefix)
        result = "in the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " side" }));
      break;
    }
    break;
  case "stomach":
    switch (verb) {    
    case "admire":
    case "look":    
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " stomach" });
      break;    
    default:    
      if (with_prefix)
        result = "in the ";
      result = (aimed ? result + body : ({ S_POSSESSIVE, people, " stomach" }));
      break;
    }
    break;
  case "toe":
    switch (verb) {
    case "cover":
      if (aimed)
        result = "right toe";
      else
        result = ({ S_POSSESSIVE, people, " right toe" });
      break;
    case "admire":
    case "look":        
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " toe" });
      break;
    case "cry":
      result = "toes"; //(aimed ? result + body
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix && aimed)
        result = "on ";
      result = ({ result, S_POSSESSIVE, people, " right toe" });
      break;
    }
    break;
  default:  // this is a self defined bodypart
    if (body == "") {   // Coogan, 27-Jul-2006, to exclude S_BODY
      result = ({ });
      break;
    }
    switch (verb) {
    case "cover":
      if (aimed)
        result = body;
      else
        result = ({ S_POSSESSIVE, people, " ", body });
      break;
    case "close":
    case "cry":
      result = body;
      break;
    case "rub":
      result = (aimed ? body : ({ S_POSSESSIVE, people, " ", body }));
      break;
    case "admire":
    case "stretch":  // Alfe 2006-Sep-28
    case "look":
      result = ({ with_prefix ? "on " : "" });
      result += ({ S_S, people, " ", body });
      break;
    case "bite":
      result = "in the ";  // fall trough!
    default:
      if (result == "" && with_prefix && aimed)
        result = "on ";
      result = ({ result, S_POSSESSIVE, people, " ", body });
      break;
    }
    break;
  }
  return result;
}

mapping get_how() {
  if (how && sizeof(how))
    return how;
  return ([
            "extremely":    1,
            "very":         1,
            "somewhat":     1,
            "mildly":       1,
            "almost":       1,
            "quite":        1,  // Alfe 1999-May-11
            "slightly":     1,  // Alfe 1998-Apr-28
            "hardly":       1,  // Chameloid, 3-Oct-1997
            "barely":       1,
            "not":          1,  // Coogan, 06-Nov-2000
            "indeed":       1,  // Coogan, 27-Mar-2002
         ]);
}

string get_verb_string() {
  if (verb_string)
    return verb_string;
  return
    verb_string=sprintf("  %-=77s\n",
                        implode_nicely(sort_array(get_verbs(),#'>)));
}

string get_adverb_string() {
  if (adverb_string)
    return adverb_string;
  return
    adverb_string=sprintf("  %-=77s\n",
#if 0  // Coogan, 27-Feb-2002
                               implode_nicely(sort_array(m_indices(adverbs),
                                                         #'> )));
#else
                       implode_nicely(get_adverbs()));
#endif
}

string get_bodydata_string() {
  if (bodypart_string)
    return bodypart_string;
  return bodypart_string =
           break_string(implode_nicely(sort_array(m_indices(bodydata),#'>)),
                        79, 3);
}

int adverb(string str) {
  string *tmp, v, adv;
  mixed *rules;
  mapping adv_map;
  int i;

  if (!str)
    return notify_fail("Please give an argument for 'adverb'.\n"
                       "Read 'help adverb' for details.\n"), 0;
  if (str == "show") {  // take care that this will not be a soul verb
                        // in the future! Coogan.
    adv_map = this_player()->query_extern_data("bin/soul", "adverbs");
    if (!adv_map || !sizeof(adv_map)) {
      message("At the moment, you've no adverbs set.\n");
      return 1;
    }
    tmp = sort_array(m_indices(adv_map), #'<);
    message("Verb            Adverb                   \n"
            "=========================================\n");
    for (i = sizeof(tmp); i-->0; )
      printf("%-15s %-25s\n", tmp[i],
                              (adv_map[tmp[i]] == "" ? "(none)"
                                                     : adv_map[tmp[i]]));
    return 1;
  }
  tmp = explode(str, " ") - ({ "" });
  if (!sizeof(tmp))
    return notify_fail("Give a verb.\n"), 0;
  if (query_is_verb(tmp[0]) == 0)
    return notify_fail("'" + tmp[0] + "' is not a soul command.\n"), 0;
  if (sizeof(tmp) < 2)
    return notify_fail("Give an adverb for '" + tmp[0] + "'.\n"), 0;
  v   = tmp[0];
  adv = tmp[1];
  adv_map = this_player()->query_extern_data("bin/soul", "adverbs");
  rules = get_rules(v);
  if (member(rules[<1], S_HOW) == -1) {
    message("This feeling doesn't support usage of adverbs.\n");
    return 1;
  }
  if (adv == "/")
    adv = "";
  if (adv_map)
    if (adv == "default")
      adv_map = m_delete(adv_map, v);
    else
      adv_map = adv_map + ([ v : adv ]);
  else if (adv != "default")
    adv_map = ([ v : adv ]);
  this_player()->set_extern_data("bin/soul", "adverbs", adv_map);
  if (adv == "default")
    message("Adverb settings for '" + v + "' removed.\n");
  else {
    if (adv == "")
      message("Set no default adverb for '" + v + "'.\n");
    else
      message("Default adverb for '" + v + "' set to '" + adv + "'.\n");
  }
  return 1;
}

void create() {
  mixed h;
  int i;

  if (!clonep()) {
    set_global_listening_event("feeling", 1);
    listen_event("feeling");
  }
  how              = get_how();
  bodydata         = get_bodydata();
  verb_string      = get_verb_string();
  adverb_string    = get_adverb_string();
  modificator_list = get_modificator_list();

#if 0  // Coogan, 24-May-2002
  h = m_indices(verbs);
#else
  h = get_verbs();
#endif
  for (i=0; i < sizeof(h); i++)
    add_command("do_feel", h[i]);

  foreach (h : modificator_list)
    add_command("do_feel", h);

  add_command("help",    "help");
  add_command("feeling", "feeling");
  add_command("adverb",  "adverb");  // Coogan, 11-Apr-2001
}

status help(string s) {
  if (!s)
    return 0;
  if (s == "adverb") {
    message("With the 'adverb' command you can set default adverbs for \
particular verbs without having to use aliases. \n\n\
Example:\n\
  adverb nod happily           - sets 'happily' as default adverb for 'nod'\n\
  adverb grin /                - sets an empty default adverb for 'grin'\n\
  adverb grin default          - and this deletes the default adverb we've\n\
                                 just set for 'grin'\n\
  adverb show                  - shows all adverbs set \n\n");
    return 1;
  }
/* help soul added by Carador, 18-Jul-1993, help feelings and adverbs changed */
  if (s == "soul") {
    MORE("\
--- Feelings: ---\n\
   All feelings ('help feelings' to see a list) can be combined with 'and',\n\
   ',' or just by adding them. Feelings can be done in several ways and/or to\n\
   several people. All feelings can also be prepended with: \n\
   again, almost, also, anyway, dont (don't), fail, not, refuse, still,\n\
   suddenly, too, try and trynot respectively. Some of the feelings \n\
   can specify a special part of the body, e.g. kick or pat. You can\n\
   add a message to some feelings by putting it into \" (mumble, curse), you\n\
   may separate feelings by | to avoid misunderstandings like the following:\n\
   'smile punch cara' vs. 'smile | punch cara'.\n\n\
   Some feelings are ambiguous with other commands, such as 'say', 'tell',\n\
   or 'shout'. To not confuse them you may prepend them with the keyword\n\
   'feeling' to force the respective feeling, and not the command.\n\n\
   If you target feelings at players that are not in the same room with you,\n\
   the feeling will automatically become an 'afar' feeling. Make sure you\n\
   completely spell out the target players' names in this case. You may\n\
   optionally give other players' names who are not target but should receive\n\
   the output as well. Prepend those with the '@' mark. Examples:\n\
   'smile chameloid' -> only Chameloid and you will receive the output\n\
   'poke webster chameloid' -> Chameloid, Webster, and you receive the output\n\
   'grin chameloid @webster' -> ditto, but Webster isn't targetted\n\
   For some muds it's also possible to send feelings directly to players in\n\
   those muds: 'nod coogan@othermud'  -> You nod at Coogan@Othermud.\n\
               'nod @coogan@othermud' -> From afar, you nod.\n\n\
--- Targets: ---\n"+"\
   You can specify one (or more people) directly by typing the name(s) after\n\
   the feeling. Names may be abbreviated by an unambiguous prefix. It is also\n\
   possible to direct feelings at obstacles.\n\
   Additional commands:\n\
     'all', 'everyone', 'everybody': all persons in the same room.\n\
     'me', 'I', 'myself' : yourself.\n\
   If you specified someone (a group) in a previous feeling, you can specify\n\
   the same person (group) in the next feeling by: him/her/it (them),\n\
   example: grin har kick him, or: pat har orc grimace them.\n\n\
--- Adverbs: ---\n\
   You can add one (or more) adverbs to every feeling. Adverbs may also be\n\
   abbreviated by an unambiguous prefix. ('help adverbs' to see a list). You\n\
   may enter own adverbs with: /adverbly or <in your matter>. You can omit a\n\
   default adverb of a feeling by adding a / to the feeling (e.g. smile /).\n\
   All adverbs can be prepended with a grade.\n\
   To set a default adverb for a particular verb, see 'help adverb' for \n\
   details.\n\n\
--- Bodyparts: ---\n\
   For some verbs you can also give a bodypart. The soul tries to discover\n\
   how the bodypart is handled. It's also possible to give self-defined\n\
   bodyparts 'on the fly'. Examples:\n\
   'slap coogan hand' -> You slap Coogan on the hand.\n\
   'raise hand'       -> You raise your hand.\n\
   'stroke me $fur$'  -> You stroke yourself on your fur.\n\
   Available bodyparts are:\n" + get_bodydata_string() + "\n",
     "help soul");
     return 1;
  }
  if (s == "feelings") {
    MORE("--- Feelings: ---\n"+
         verb_string+
         sprintf("--- Grades: ---\n  %-=77s\n",
                 implode_nicely(m_indices(how)))+
         "--- Bodyparts: ---\n" +
         get_bodydata_string(),
         "help feelings");
    return 1;
  }
  else if (s == "adverbs") {
    MORE("--- Adverbs: ---\n" + adverb_string,
         "help adverbs");
    return 1;
  }
  return do_feel(s);
}

string get_name(object o) {
  if (!channel_listeners)
    return lower_case(o->query_name() ||
                      (living(o) ? "somebody" : "something"));
  return o->query_real_name();
}

varargs mixed get_names(object o) {
  string n1, n2;
  if (!channel_listeners)
    // added LIB_STRINGS call, Coogan, 23-May-2003
    n1 = LIB_STRINGS->latin12ascii(lower_case(o->query_name() ||
                                   (living(o) ? "somebody" : "something")));
  else
    n1 = o->query_real_name();
#if 0  // Coogan, 23-May-2003
  if ((n2 = LIB_NAME->to_real_name(n1)) != n1)
    return ({ n1, n2 });
#endif
  return n1;
}

string query_name(object o) {
  if (channel_listeners)
    return o->query_vis_name();
  return describe(o, ARTICLE_THE, 0, -1);     // Carador, Feb-1996
}

// Coogan: hmmmmmmmmm ..............
int isplay(object o) {
#if 0  // Alfe 1996-Sep-25
  return !!((query_once_interactive(o) || o->query_npc()) && o->short());
#else
  return !!o->short()
#if 1  // Coogan, 12-Nov-2002
         || !!(!o->short() && !living(o) && o->query_name() && o->query_long())
#endif
         ;
#endif
}

object *get_ambig_persons() {
  return filter(users(),
                (: load_name($1) != "obj/login" :));
}

object *get_persons() {
  return (channel_listeners ||
          filter((all_inventory(environment(this_player()))),
                 (#'isplay)));
}

string *get_person_names() {
  string *n1, *n2;
//  DEBUG_POINT_TP("coogan", ({ }));
  n1 = map(get_persons(), #'get_name);
  n2 = map(n1, (: string n;
                  if ((n = LIB_NAME->to_real_name($1)) != $1)
                    return ({ $1, n }); :));
  return flatten_array(n2);
}

mixed prefix(string *dum, string pr, string errm) {
  string *q;
  //DEBUG_POINT_TP("coogan", ({ dum, pr, errm }));
  pr = QUOTE_FOR_REGEXP(pr);
  q = regexp(dum, "^"+pr);  // try to find a as beginning...
#if 0  // made more trouble than good.  Alfe 1998-Mar-20
  if (!sizeof(q))  // Alfe 1997-Feb-25   nothing found
    q = regexp(dum, pr);  // then try also as substring...
#else // Ugh Mar-23-1998
  if (!sizeof(q))
    q = regexp(dum, "\\<"+pr);
#endif
  if (sizeof(q) == 1)  // found exactly one?
    return q[0];  // return it
  if (!sizeof(q)) {  // found none?
    if (pr[<1] == 'y') {  // maybe somebody gave 'happy' but we of course
                          // only have 'happily' in our database. check this.
      pr[<1] = 'i';
      q = regexp(dum, "^"+pr);
      if (sizeof(q) == 1)
        return q[0];
      if (!sizeof(q))  // found still none?
        return 0;  // return failure
    }
    else
      return 0;  // return failure
  }
  // else: found more than one; ask which was meant
  notify_fail(errm+"\n"+break_string("Was it "+implode_nicely(q," or ")+"?\n"),
              -1);
  return -1;  // return ambiguity
}

mixed get_person(string who) {
  return prefix(get_person_names(), who, "Who do you mean?");
}

void receive_event(mapping e, string type, int prio) {
  global_feeling_event = copy(e);
}

mixed* parse_one_rule(mixed rule, string verb, object *who, string *adverb,
                      string message, string *body, string *modificator,
                      object agent) {
  int j;
  mixed *msg, h, *msg_tail;

  if (who && sizeof(who))
    who = m_indices(mkmapping(who));

  msg = ({ });
  msg_tail = ({ });
// if (this_player() && this_player()->query_real_name()=="coogan")
// DEBUG_POINT("coogan", ({ rule }));
  if (member(modificator, "suddenly") > -1) {
    msg += ({ S_TEXT, "suddenly,", S_THE_AGENT });
    modificator -= ({ "suddenly" });
  }

  if (member(modificator, "dont") > -1 ||
      member(modificator, "don't") > -1) {
    if ((j = member(msg, S_VERB)) > -1)
      msg[j..j] = ({ S_VERB, "try", S_TEXT, "not to", S_REAL_VERB, S_TEXT, });
    else
      msg += ({ S_VERB, "try", S_TEXT, "not to" });
    modificator -= ({ "dont", "don't" });
    msg_tail = ({ S_TEXT, ", but", S_VERB, "fail", S_TEXT, "miserably" });
  }

  if (member(modificator, "but") > -1) {
    msg = ({ S_TEXT, "but", S_THE_AGENT }) + msg;
    modificator -= ({ "but" });
  }

  if (member(modificator, "fail") > -1) {
    if ((j = member(msg, S_VERB)) > -1)
      msg[j..j] = ({ S_VERB, "try", S_TEXT, "not to", S_REAL_VERB, S_TEXT });
    else
      msg += ({ S_VERB, "try", S_TEXT, "to" });
    modificator -= ({ "fail" });
    msg_tail = ({ S_TEXT, ", but", S_VERB, "fail", S_TEXT, "miserably" });
  }

  if (member(modificator, "trynot") > -1) {
    if ((j = member(msg, S_VERB)) > -1)
      msg[j..j] = ({ S_VERB, "try", S_TEXT, "not to", S_REAL_VERB, S_TEXT });
    else
      msg += ({ S_VERB, "try", S_TEXT, "not to" });
    modificator -= ({ "trynot" });
  }

  if (member(modificator, "try") > -1) {
    if ((j = member(msg, S_VERB)) > -1)
      msg[j..j] = ({ S_VERB, "try", S_TEXT, "to", S_REAL_VERB, S_TEXT });
    else
      msg += ({ S_VERB, "try", S_TEXT, "to" });
    modificator -= ({ "try" });
  }

  if (member(modificator, "refuse") > -1) {
    if ((j = member(msg, S_VERB)) > -1)
      msg[j..j] = ({ S_VERB, "refuse", S_TEXT, "to", S_REAL_VERB, S_TEXT });
    else
      msg += ({ S_VERB, "refuse", S_TEXT, "to" });
    modificator -= ({ "refuse" });
  }

  for (j = 0; j < sizeof(rule); j++) {

    switch (rule[j]) {
    case S_ADD_VERB:
      msg += ({ S_ADD_VERB, rule[j+1], rule[j+2] });
      j = j + 2;
      break;

    case S_VERB:
      if (sizeof(rule) == j+1 ||                // rule ends after S_VERB or
          intp(rule[j+1])) {                    // no special verb
        if (member(msg, S_VERB) == -1)
          msg += ({              S_VERB, verb });  // take care, that only one
        else                                       // S_VERB is contained in msg
          msg += ({ S_REAL_VERB, S_TEXT, verb });  // save the real verb!
        break;
      }
      if (member(msg, S_VERB) == -1)
        msg += ({              S_VERB, rule[j+1] });  // special verb
      else
        msg += ({ S_REAL_VERB, S_TEXT, rule[j+1] });
      j++;
      break;

    case S_HOW:
      if (sizeof(adverb))
        msg += ({ S_HOW, adverb });
      if (sizeof(rule) > j+1 &&                 // skip a default adverb
          !intp(rule[j+1]))
        j++;
      break;

    case S_AT:
      if (intp(rule[j+1]))
        msg += ({ S_AT, "at" });
      else {
        msg += ({ S_AT, rule[j+1] });
        j++;
      }
      break;

    case S_TARGET:
      if (!sizeof(who))         // a person must be given! This should never
        return                  // happen, because the event already took place
          notify_fail("Need person for " + verb + ".\n"), 0;
      msg += ({ S_TARGET, who });                  // we add the array!
      break;

    case S_BODY_TARGET:
      if (!sizeof(who))
        who = ({ agent });
      msg += ({ S_BODY_TARGET, who });
      break;

    case S_BODY:
      if (sizeof(body))
        msg += ({ S_BODY, body });
      if (sizeof(rule) > j+1 &&                 // skip the default bodypart,
          !intp(rule[j+1]))                     // if there is any
        j++;
      break;

    case S_TEXT:
      msg += ({ S_TEXT, rule[j+1] });
      j++;
      break;

    case S_MESSAGE:
      if (sizeof(rule) == j+1 ||                // rule ends after S_MESSAGE
          intp(rule[j+1])) {                    // no default message
        if (message != "")
          msg += ({ S_MESSAGE, message });
        break;
      }
      if (message != "")
        msg += ({ S_MESSAGE, message });
      else
        msg += ({ S_MESSAGE, rule[j+1] });
      j++;
      break;

    case S_POSSESSIVE:
      msg += ({ S_POSSESSIVE });
      break;

    case S_OBJECT:
      msg += ({ S_OBJECT });
      break;

    case S_S:
      msg += ({ S_S });
      break;

    case S_PRONOUN:
      msg += ({ S_PRONOUN });
      break;

    case S_AGENT:
      msg += ({ S_AGENT });
      break;

    default:
      msg += ({ rule[j] });
    }
  }

  if (member(modificator, "not") > -1) {
    j = member(msg, S_VERB);
    msg[j..j] = ({ S_VERB, "do", S_TEXT, "not", S_TEXT });
  }

  if (member(modificator, "also") > -1) {
    j = member(msg, S_VERB);
    if (member(msg, S_THE_AGENT) == -1)
      msg[j..j-1] = ({ S_THE_AGENT, S_TEXT, "also" });
    else
      msg[j..j-1] = ({              S_TEXT, "also" });
    modificator -= ({ "also" });
  }

  if (member(modificator, "still") > -1) {
    j = member(msg, S_VERB);
    if (member(msg, S_THE_AGENT) == -1)
      msg[j..j-1] = ({ S_THE_AGENT, S_TEXT, "still" });
    else
      msg[j..j-1] = ({              S_TEXT, "still" });
    modificator -= ({ "still" });
  }

  if (member(modificator, "almost") > -1) {
    j = member(msg, S_VERB);
    if (member(msg, S_THE_AGENT) == -1)
      msg[j..j-1] = ({ S_THE_AGENT, S_TEXT, "almost" });
    else
      msg[j..j-1] = ({              S_TEXT, "almost" });
    modificator -= ({ "almost" });
  }

  if (member(modificator, "again") > -1) {
    msg += ({ S_TEXT, "again" });
    modificator -= ({ "again" });
  }

  if (member(modificator, "anyway") > -1) {
    msg += ({ S_TEXT, "anyway" });
    modificator -= ({ "anyway" });
  }

  if (member(modificator, "too") > -1) {
    msg += ({ S_TEXT, ", too" });
    modificator -= ({ "too" });
  }
  msg += msg_tail;
// if (this_player() && this_player()->query_real_name()=="coogan")
// DEBUG_POINT("coogan", ({ msg }));
  return msg;
}

mapping send_feeling_event(mapping feeling_event) {
  mapping event_sent;

  global_feeling_event = 0;
  event_sent = deep_copy(feeling_event);
  // DEBUG_POINT_TP("coogan", ({ feeling_event }));
  if (channel_listeners)
    return event_sent;
  send_event("feeling", event_sent,
#if 0  // Coogan, 18-Jan-2002
             map(m_indices(remote_targets), #'environment) - ({ 0 }) +
#else
             map(feeling_event[E_REMOTE_TARGET], #'environment) - ({ 0 }) +
#endif
             ({ environment(this_player()) }));

  feeling_event = global_feeling_event;
  // added next if(), Coogan, 31-Jan-2001
  if (!feeling_event ||                 // and this check, Coogan, 07-Jun-2001
      feeling_event[E_CANCELLED] == 1)
    return ([ ]);
  return feeling_event;
}

#if 0  // Coogan, 12-Jul-2001
private object my_parse_living(string word, string next_word, int words_used) {
  object ob;
  string tmp;

  if (next_word) {
    if ((LIB_GRAMMAR->parse_living(&ob, 0, 0, 1, ({ word, next_word }),
                                   word + " " + next_word)) &&
        ob && isplay(ob)) {
      words_used = 1;
      return ob;
    }
  }

  ob = (present(word, environment(this_player())) ||
        present(word, this_player()));

  if (!ob) {  // added this branch, Coogan, 06-May-1999
    tmp = to_vis_name(word);
    if (tmp)
      ob = present(tmp, environment(this_player())) ||
           present(tmp, this_player());
  }

  if (ob && isplay(ob))
    return ob;
  return 0;
}
#endif

private object my_parse_target(string *input_words, int words_used) {
  object ob, last_ob;
  mixed aux;
  string tmp, *it;
  int i, last_r, r, res;

  // Coogan, 13-Jul-2001, much improved the function speed
  r = sizeof(input_words) - 1;

  for (i = 0; i <= r; i++)
    if (input_words[i][0] == '\"' ||  // a text
        input_words[i][0] == '/'  ||  // a simple self-defined adverb
        input_words[i][0] == '<'  ||  // a complex self-defined adverb
        input_words[i][0] == '$')
      break;  // we know that we only have to parse to that point right now

  if (i < r) {
    if (i > 0)
      input_words = input_words[0..i-1];
    else
      input_words = input_words[0..i];
    r = sizeof(input_words) - 1;
  }

  while (r >= 0) {
    tmp = implode(input_words[0..r], " ");
    ob = present(tmp, environment(this_player())) ||
         present(tmp, this_player());
    if (!ob &&  // fakeitem handling added, Coogan, 14-Jul-2001
        environment(this_player())->query_items()                   &&
        sizeof(environment(this_player())->query_items())           &&
        sizeof((it = environment(this_player())->query_items()[0])) &&
        member(it, tmp) > -1) {
      ob = clone_object("bin/tools/soul_fakeitem");
      ob->set_name(tmp);
      if (LIB_LANGUAGE->could_be_plural(tmp))
        ob->set_plural();
      else
        ob->set_neuter();
      move_object(ob, environment(this_player()));
    }
    if (ob && !isplay(ob))
      ob = 0;
    if (last_ob && last_ob != ob) {
      words_used = last_r;
      return last_ob;
    }
    if (ob) {
      last_ob = ob;
      last_r  = r;
    }
    r--;
  }
  if (last_ob) {
    words_used = last_r;
    return last_ob;
  }
  return 0;
}

static void initialize_map_id(status force) {  // rewritten, Coogan, 03-Aug-2001
  int i, j;
  string *ids, id;
  object o;

  if (channel_listeners) {  // added this case, Coogan, 12-Nov-2001
    map_id = m_allocate(sizeof(channel_listeners));
    foreach (o : channel_listeners) {
      ids = (o->query_id()      || ({ })) +
            (o->query_real_id() || ({ })) +
            (o->query_name()      ? ({ o->query_name()      }) : ({ })) +
            (o->query_real_name() ? ({ o->query_real_name() }) : ({ })) +
            (o->query_property(P_MONEY) ? ({ "money", "coins" }) : ({ }));
      ids = map(ids, #'lower_case);
      foreach (id : ids) {
        if (!member(map_id, id))
          map_id[id] = ({ });
        if (member(map_id[id], o) == -1)
          map_id[id] += ({ o });
      }
    }
    return;
  }

  if (!env_list || force) {
    env_list = filter((all_inventory(environment(this_player()))),
                      (#'isplay));
  }
  if (!inv_list || force) {
    inv_list = filter(all_inventory(this_player()), #'isplay);
  }
  // the sizes are very very rough assumes
  map_id = m_allocate(sizeof(env_list) + sizeof(inv_list), 1);
  foreach (o : env_list) {
    ids = (o->query_id()      || ({ })) +
          (o->query_real_id() || ({ })) +
          (o->query_name()      ? ({ o->query_name()      }) : ({ })) +
          (o->query_real_name() ? ({ o->query_real_name() }) : ({ })) +
          (o->query_property(P_MONEY) ? ({ "money", "coins" }) : ({ }));
    ids = map(ids, #'lower_case);
    foreach (id : ids) {
      if (!member(map_id, id))
        map_id[id] = ({ });
      if (member(map_id[id], o) == -1)
        map_id[id] += ({ o });
    }
  }
  foreach (o : inv_list) {
    ids = (o->query_id()      || ({ })) +
          (o->query_real_id() || ({ })) +
          (o->query_name()      ? ({ o->query_name()      }) : ({ })) +
          (o->query_real_name() ? ({ o->query_real_name() }) : ({ })) +
          (o->query_property(P_MONEY) ? ({ "money", "coins" }) : ({ }));
    ids = map(ids, #'lower_case);
    foreach (id : ids) {
      if (!member(map_id, id))
        map_id[id] = ({ });
      if (member(map_id[id], o) == -1)
        map_id[id] += ({ o });
    }
  }
  map_fakeitem = 0;  // create that only if really needed
}

static void initialize_map_fakeitem() {  // Coogan, 03-Aug-2001
  mixed items;
  if ((items = environment(this_player())->query_items()) &&
      sizeof(items) &&
      pointerp(items[0]))  // added this check, Coogan, 22-Aug-2001
    map_fakeitem = mkmapping(items[0]);
  else
    map_fakeitem = ([ ]);
}

// Coogan, 03-Aug-2001  
object parse_local_target(string *input_words, int words_used) {
  object o, old_o;
  string id, tmp;
  int w, old_w, amount, i;

  w = sizeof(input_words) - 1;

  for (i = 0; i <= w; i++)
    if (input_words[i][0] == '\"' ||  // a text
        input_words[i][0] == '/' ||  // a simple self-defined adverb
        input_words[i][0] == '<' ||  // a complex self-defined adverb
        input_words[i][0] == '$')
      break;  // we know that we only have to parse to that point right now

  if (i < w) {
    if (i > 0)
      input_words = input_words[0..i-1];
    else
      input_words = input_words[0..i];
  }

  // many players have the "hand" made by Durin long years ago.
  // Commands like 'raise hand' result in 'You raise an eyebrow on your hand',
  // which is often surprising. Take care of this, but not too carefully
  // to limit the eval. Coogan, 31-Aug-2006
  if (input_words[0] == "hand")
    return 0;

  // begin from left.
  o = 0;
  w = 0;
  for (i = 0; i < sizeof(input_words); i++) {
    if (old_o && !o) {                          // didn't found a better match
      words_used = old_w - 1;
      return old_o;
    }
    old_o = o;
    old_w = w;

    // added this workaround for players with special chars (umlauts et al)
    // in their names
    if (i == 0 &&
        LIB_NAME->valid_name(input_words[0]) &&
        (tmp = LIB_NAME->to_real_name(input_words[0])) != input_words[0])
      id = tmp;  // found a player with special chars in the name
    else
      id = lower_case(implode(input_words[0..i], " "));  // test this id now
    amount = 0;
    o = 0;

    if (i < sizeof(input_words) - 1) {
      if ((amount = to_int(input_words[i+1])) < 0)
        amount = 0;                             // let it bug later
    }
    if (member(map_id, id)) {
      if (amount <= sizeof(map_id[id])) {
        if (amount > 0)
          o = map_id[id][amount-1];
        else
          o = map_id[id][amount];
        w = i + 1 + !!amount;
        continue;
      }
    }

    // test references, Coogan, 28-Apr-02
    if ((o = this_player()->query_referenced(id))) {
      w = i + 1;
      continue;
    }

    // now test fake items
    if (!map_fakeitem)                  // initialize that only if needed
      initialize_map_fakeitem();
    if (member(map_fakeitem, id)) {
      o = clone_object("bin/tools/soul_fakeitem");
      o->set_name(id);
      if (LIB_LANGUAGE->could_be_plural(id))
        o->set_plural();
      else
        o->set_neuter();
      move_object(o, environment(this_player()));
      w = i + 1;
      continue;
    }
  }

  if (o) {
    words_used = w - 1;
    return o;
  }
  if (old_o) {
    words_used = old_w - 1;
    return old_o;
  }
  words_used = 0;
  return 0;
}

private object my_parse_remote_mud(string name, string mud, string *words,
                                   int words_used) {
  string *tmp, mudname;
  int i, s;
  object sd;

#if 1 // INTERMUD3
  i = 0;
  tmp = explode(words[0], "@");
  if (sizeof(tmp) > 2)
    return 0;
  tmp -= ({ "" });
  if (sizeof(tmp) != 2)
    return 0;
  name = tmp[0];
  mudname = tmp[1];
  s = sizeof(words);
#if 0
  while (!(mud = IMUD3->get_mud_name(mudname)) &&
#else
  while (!(mud = SE_INTERMUD->get_mud_name(mudname)) &&
#endif
         ++i < s) {
    mudname += " " + words[i];
  }
  if (!mud)
    return 0;
  words_used = i;
  return create_sould(name, mud);
#else
  return 0;
#endif
}

// added this function for verbs like 'be' which want to get adjectives instead
// of adverbs.  Alfe 1997-Jul-3
string adjectivise(string adverb) {
  switch (adverb) { // Chameloid, 5-Oct-1997
    case "in a friendly manner": return "friendly";
    case "in a deadly fashion":  return "deadly";
    case "xenophobly":           return "xenophobic";
    case "idly":                 return "idle";
    case "into space":           return "in space";
    case "wobblingly":           return "wobbly";
  }
  if (adverb[<11..] == "fatheringly" || adverb[<11..] == "motheringly")
    return adverb[0..<6] + "ly";
  if (adverb[<3..] == "bly" &&
      (adverb[<4] == 'a' || adverb[<4] == 'e' || adverb[<4] == 'o' ||
       adverb[<4] == 'i' || adverb[<4] == 'u'))
    return adverb[0..<2] + "e";
  if (adverb[<3..] == "ily")
    return adverb[0..<4] + "y";
  if (adverb[<2..] == "ly")
    return adverb[0..<3];
  return adverb;
}

status adjective_verb(string verb) {
  switch (verb) {
  case "be":
  case "become":
  case "stay":
  case "seem":
  case "appear":
    return 1;
  }
  return 0;  // Coogan, 24-Mar-2011
}

mapping build_event_mapping(mixed *rule, string verb, object *who, string *adv,
                            string message, string *body, string *modificator) {
  mapping e, player_adv;  // Coogan, 11-Apr-2001, added player_adv
  int i;

  player_adv = this_player()->query_extern_data("bin/soul", "adverbs") || ([ ]);
  // added all code with player_adv, Coogan, 11-Apr-2001
  if ((i = member(rule, S_HOW)) > -1) {
    if (sizeof(rule) > i+1) {                   // rule continues after S_HOW
      if (pointerp(rule[i+1])) {                // with something or ...
        adv = (sizeof(adv) && adv) ||
              (player_adv[verb] ? ({ player_adv[verb] }) : rule[i+1]);
      }
      else if (stringp(rule[i+1])) {            // with an adverb or ..
        adv = (sizeof(adv) ? adv : 0) ||
              (player_adv[verb] ? ({ player_adv[verb] }) : ({ rule[i+1] }));
      } else {  /* intp(rule[i+1])) */          // with a token
        adv = (sizeof(adv) ? adv : 0) ||
              (player_adv[verb] ? ({ player_adv[verb] }) : ({ }));
      }
    } else {
      if (player_adv[verb])
        adv = ({ player_adv[verb] });
    }
    adv = (adv - ({ "" })) || ({ });            // remove "" resulting from '/'
  }

  if ((i = member(rule, S_BODY)) > -1) {
    if (sizeof(rule) > i+1) {                   // rule ends after S_BODY or
      if (pointerp(rule[i+1]))
        body = (sizeof(body) && body) || rule[i+1];
      else if (stringp(rule[i+1]))
        body = (sizeof(body) && body) || ({ rule[i+1] });
    }
    body = body || ({ });
  }

  e = ([
         E_FEELING      : verb,
         E_TYPE         : feeling_kind,
         E_AGENT        : this_player(),
         E_PERSONS      : who,
         E_ADVERBS      : adv,
         E_MSG          : message,
         E_BODYPARTS    : body,
         E_MODIFICATION : modificator,
      ]);

  return e;
}

varargs mapping parse_soul_command(string text, int offset) {
  string verb, *q, *adv, *body, tmp, message;
  object *who, ob, *people;
  mapping persons;

  mixed *msg, *rules, *rule, off, h;
  object *tmp1;
  string *words, word, _how, *modificator, name, mud;
                                 // _how: the grade, if given (e.g. very)
                                 // modificator: too, also, suddenly, ...
                                 // but modificators can be combined:
                                 // -> Suddenly, Coogan also nods.
                                 // -> Coogan still tries not to laugh.
  int i, j, fi, words_used, u, tmpremote;
  mapping feelings, event_mapping;

  if (!offset)
    offset = 1;
  who  = ({ });
  adv  = ({ });
  body = ({ });
  message = "";

  remote_targets = ([ ]);
  words = explode(text, " ") - ({ "" });

  _how = 0;
  modificator = ({ });

  feelings = m_allocate(1, 3);   // ([ 0: event; message; 0
                                 //           ............
                                 //    n: event; message; 0 ])
  fi = 0;                        // index for actual verb in feelings

  initialize_map_id(1);  // Coogan, 27-Jul-2001
  // DEBUG_POINT_TP("coogan", ({ text }));
  for(i = 0; i < sizeof(words); i++) {
    word = words[i];
    // DEBUG_POINT_TP("coogan", ({ "i = " + i, "word = " + word }));
    if (word[0] != '\"' &&  // take care, if there's a "," as separator used
        word[0] != '/'  &&  // outside of a feeling-message
        word[0] != '<'  &&
        word[0] != '$'  &&
        word[<1]== ',')  {  /* checks for " ' < added by Cara, 19-jul-1993 */
      word = word[0 .. <2];  // 'nod coogan, alfe' --> 'nod coogan alfe'
      words[i] = word;       // and save the change, Coogan, 10-Jan-2002
    }

    if (word[0] == '\"') {              // text in '"'?
      message = "\"" + word[1..];       // leave the rest of the text (or the
      for (i++;    // strlen-check added, Coogan, 26-Feb-2002
           (strlen(word) == 1 || message[<1] != '\"') && i < sizeof(words);
           i++)
        message += " " + words[i];      // rest of the line) untouched, don't
      if (message[<1] == '\"') {        // parse it
        message = message[0..<2];
        i--;
      }
      message += "\"";
      continue;
    }

    switch (word) {
      case "and":
      case "&":
      case "at":
      case "to":
      case "before":
      case "in":
      case "on":
      case "the":
        break;

      case "my":  // Coogan, 16-Jan-2003
        break;

      case "me":
      case "myself":
      case "I":
        who += ({ this_player() });
        break;

      case "them":
        if (sizeof(who) || !sizeof(feelings))
          return notify_fail("Who?\n", -1), 0;
        if (sizeof(tmp1=m_indices(
                          mkmapping(feelings[sizeof(feelings)-1,
                                             _F_EVENT][E_PERSONS]))) < 2) {
          if (!sizeof(tmp1) ||
              !tmp1[0]->query_plural())
            return notify_fail("Who?\n", -1), 0;
        }
        who = tmp1;
        break;

      case "him":
        if (sizeof(who) || !sizeof(feelings))
          return notify_fail("Who?\n", -1), 0;
        if (sizeof(tmp1=filter_objects(m_indices(mkmapping(
                                         feelings[sizeof(feelings)-1,
                                                 _F_EVENT][E_PERSONS])),
                                       "query_male")) != 1)
          return notify_fail("Who?\n", -1), 0;
        who = ({ tmp1[0] });
        break;

      case "her":
        if (sizeof(who) || !sizeof(feelings))
          return notify_fail("Who?\n", -1), 0;
        if (sizeof(tmp1=filter_objects(m_indices(mkmapping(
                                         feelings[sizeof(feelings)-1,
                                                  _F_EVENT][E_PERSONS])),
                                       "query_female")) != 1)
          return notify_fail("Who?\n", -1), 0;
        who = ({ tmp1[0] });
        break;

      case "it":
        if (sizeof(who) || !sizeof(feelings))
          return notify_fail("Who?\n", -1), 0;
        if (sizeof(tmp1=filter_objects(m_indices(mkmapping(
                                         feelings[sizeof(feelings)-1,
                                                  _F_EVENT][E_PERSONS])),
                                       "query_neuter")) != 1)
          return notify_fail("Who?\n" ,-1), 0;
        who = ({ tmp1[0] });
        break;

    case "all":
    case "everybody":
    case "everyone":
      if (!people)
        people = filter(get_persons(),
                        lambda(({ 'x }),
                               ({ #'||,
                                  ({ #'interactive,'x }),
                                  ({ #'&&,
                                     ({ #'!,
                                        ({ #'query_once_interactive, 'x }) }),
                                     ({ #'living, 'x }),
                                     ({ #'call_other, 'x, "query_npc" })
                                  })
                               })));
      who += people - ({ this_player() });
      break;

    case "also":
    case "too":
    case "try":
    case "trynot":
    case "dont":
    case "don't":
    case "anyway":
    case "still":
    case "fail":
    case "again":
    case "refuse":
    case "but":
      if (word == "don't")
        modificator += ({ "dont" });
      else
        modificator += ({ word });
      break;

    case "not":
    case "suddenly":
    case "almost":
      if (!verb) {   // we don't have a verb yet
        modificator += ({ word });
        break;
      }
      // fall through as we have a verb, and 'suddenly' is an adverb
    default:

 /* check for person moved to this place by Carador, 2-Sep-1993,
    additionally we check if there has been given a verb before,
    cause if there is no verb, no person can be meant in this place */

      words_used = 0;
#if 0  // Coogan, 12-Jul-2001
      if (verb &&
          (ob = my_parse_living(word,
                                (i + 1 < sizeof(words) ? words[i+1] : 0),
                                &words_used)) &&
          // added next (), Coogan, 17-Aug-2000
          (!channel_listeners || interactive(ob))) {
        who += ({ ob });
        i += words_used;
        break;
      }
#else
      if (verb) {
#if 0  // Coogan, 27-Jul-2001, 0 again, 03-Aug-2001
        ob = my_parse_target(words[i..], &words_used);
#else
        ob = parse_local_target(words[i..], &words_used);
//DEBUG_POINT_TP("coogan", ({ ob, words[i..] }));
#endif
        if (ob && (!channel_listeners || interactive(ob))) {
          who += ({ ob });
          i += words_used;
          break;
        }
#if 0
        if ((ob = prefix(map(filter(users(),
                                            (: load_name($1) != "obj/login" :)),
                             (: lower_case($1->query_name()) 
#endif
      }
#endif
      if (verb &&
          ob = my_parse_remote_mud(&name, &mud, words[i..], &words_used)) {
        who += ({ ob });
        remote_targets += ([ ob ]);
        i += words_used;
        break;
      }

      if (verb &&  // verb check, Coogan, 15-Mar-2004
          !channel_listeners &&
          (ob = find_player(word)) &&
          interactive(ob)) {  // interactive() added by Coogan, 04-May-1999
        if (ob->short() || query_is_wizard(this_player())) {
          remote = 1;
          remote_targets += ([ ob ]);
          who += ({ ob });
          break;
        }
      }
      if (!channel_listeners && word[0..0] == "@") {
        if ((ob = find_player(word[1..])) &&
            interactive(ob)) {  // interactive() added by Coogan, 04-May-1999
          remote = 1;
          remote_targets += ([ ob ]);
          break;
        }
        if (sizeof(words) == i+1)  // last word
          ob = my_parse_remote_mud(&name, &mud, ({ word[1..] }), &words_used);
        if (sizeof(words) > i+1)  // more words
          ob = my_parse_remote_mud(&name, &mud, ({ word[1..] }) + words[i+1..],
                                   &words_used);
        if (ob) {
          remote = 1;
          remote_targets += ([ ob ]);
          i += words_used;
          break;
        }
      }

      // moved that to here, Coogan, 13-Jul-2001
      if (!_how     &&    // if there's a special grade, take this as
          how[word] &&    // the first part for the grade of the feeling
          verb) {         // but take care for 'not' also as modificator verb
        _how = word;
        break;
      }

      // moved that to here from below, Coogan, 22-Aug-2001
      /* following lines added by Carador, 17-Jul-1993, to enable
         self-defined adverbs: */

      if (word[0] == '/') {
        word = word[1..];
        if (_how) {
          adv += ({ _how + " " + word });
          _how = 0;
        }
        else
          adv += ({ word });
        break;
      }

      if (word[0] == '<') {
        tmp = " " + word[1..];
        for (i++; tmp[<1] != '>' && i < sizeof(words); i++)
          tmp += " " + words[i];
        if (tmp[<1] == '>') {
          tmp = tmp[0..<2];
          i--;
        }
        tmp = tmp[1..];
        if (_how) {
          adv += ({ _how + " " + tmp });
          _how=0;
        }
        else
          adv += ({ tmp });
        break;
      }

      if (word[0]  == '$' &&       // self-defined bodypart
          word[<1] == '$')     {
        body += ({ word[1..<2] });
        break;
      }

      if (off = bodydata[word]) {
        if (verb) {                 // save the verb 'eye'
          if (word != "back" || member(body, word) == -1) { // an exception:
            body += ({ word });     // back is both bodypart and used as adverb
            break;
          }
        }
      }

      if (query_is_adverb(word)) {
        if (_how) {
          adv += ({ _how + " " + word });
          _how=0;
        }
        else
          adv += ({ word });
        break;
      }

 /* ok, the command obviously meant no person, so look if it was a verb,
    another problem was: 'cause players may have verbs as names, the soul
    didn't know if the verb or the person was meant, example:
    Let 'Growl' be a player,
    smile growl growl carador,
    there might be two meanings:
    smile at growl and growl at carador,
    or smile at growl, growl and carador.
    So I added the command | which definitely starts a new verb, in our
    example:  smile growl growl carador will result in:
                smile at growl, growl and carador, whereas:
              smile growl | growl carador will result in:
                smile at growl and growl at carador,

    done by Carador, 2-Sep-1993

    changed from "|" to "then" by Macbeth, 13-Oct-1997
    
    */

      if (query_is_verb(word) ||
          word == "then" || word == "|") {  // new verb found?
        if (verb) {                             // we still have a verb,
                                                // so finish that first.
          rule = get_matching_rule(verb, who, adv, message, body);
          // DEBUG_POINT_TP("coogan", ({ rule }));
          if (!rule)                            // Error!
            return 0;
          event_mapping = build_event_mapping(rule, verb, who, adv,
                                              message, body, modificator);
          feelings += ([ fi : 0; 0; 0]);
          feelings[fi, _F_EVENT]   = event_mapping;
          fi++;
          message = "";
          modificator = ({ });
          _how = 0;
          adv  = ({ });
          who  = ({ });
          body = ({ });
        }
        if (word == "then" || word == "|")
          verb = 0;
        else
          verb = word;
        break;
      }

      // changed the next block to parse also abbreviations of remote persons,
      // Coogan, 25-Feb-2002
      h = people || get_ambig_persons();
      // DEBUG_POINT_TP("coogan", ({ h, persons }));
      if (!persons) {
#if 0  // Coogan, 30-Apr-2003
        persons = mkmapping(map(h, #'get_name), h);
#else
        mixed *ns, nse;
        int nsi;
        ns = map(h, #'get_names);
        // DEBUG_POINT_TP("coogan", ({ ns, h }));
        for (nsi = sizeof(ns); nsi-->0; ) {
          if (pointerp(ns[nsi])) {
            ns += ({ ns[nsi][1] });
            h  += ({ h[nsi] });
            ns[nsi] = ns[nsi][0];
          }
        }
        //DEBUG_POINT_TP("coogan", ({ ns, h }));
        persons = mkmapping(ns, h);
#endif
      }

      tmpremote = (word[0] == '@');

      //DEBUG_POINT_TP("coogan", ({ persons, word }));
      if (off = prefix(m_indices(persons),
#if 0  // Coogan, 23-May-2003
                       word,
#else
                       LIB_STRINGS->latin12ascii(tmpremote ? word[1..] : word),
#endif
                       "Who was that?")) {
        if (off == -1)
          return 0;
        if ((persons[off]->short() || query_is_wizard(this_player())) &&
            interactive(persons[off])) {
          //DEBUG_POINT_TP("coogan", ({ tmpremote, persons[off], environment(persons[off]), environment(this_player()) }));
          if (tmpremote ||  // check for tmpremote, Coogan, 19-Nov-2003
              environment(persons[off]) != environment(this_player())) {
            remote = 1;
            remote_targets += ([ persons[off] ]);
          }
          if (!tmpremote)
            who += ({ persons[off] });
        }
        break;
      }

      for (u=1, tmp=word;
#if 0  // Coogan, 27-Feb-2002
           -1==(off=prefix(m_indices(adverbs), tmp,
#else
           -1==(off=LIB_SOUL->get_adverb(tmp,
#endif
                           "What adverb (or adjective) was that?")) &&
           u+i < sizeof(words);
           u++)
        tmp += " " + words[i+u];
      if (off) {
        if (off == -1)
          return 0;
        if (adjective_verb(verb))
          off = adjectivise(off);
        i += u-1;
        if (_how) {
          adv += ({ _how + " " + off });
          _how = 0;
        }
        else
          adv += ({ off });
        break;
      }
      notify_fail("Missing person or misspelled word " + (offset+i) + " (\"" +
                  word + "\")\n", -1);
      return 0;
    }  // switch
    // DEBUG_POINT_TP("coogan", ({ "end of for()", verb, word }));
  }  // for
  if (verb) {    // added check for verb, 'cause of '|' there may be no verb
                 // Carador, 2-Sep-1993
    if (!(rule = get_matching_rule(verb, who, adv, message, body)))
      return 0;
    event_mapping = build_event_mapping(rule, verb, who, adv, message, body,
                                        modificator);
    feelings += ([ fi : 0; 0; 0 ]);
    feelings[fi, _F_EVENT]   = event_mapping;
    fi++;
  }
  if ((fi = sizeof(feelings))) {        // added this code here to add the
    tmp1 = m_indices(remote_targets);   // remote targets to the event mappings,
    for (i = 0; i < fi; i++)            // could only be done after finish of
      feelings[i, _F_EVENT][E_REMOTE_TARGET] = tmp1;    // parsing all input.
    return feelings;                                    // Coogan, 02-Jul-2001
  }
  return 0;
}

varargs mixed* compose_message_output(mixed *msg) {
  mixed *result, *r, *bps;
  int i, j, k, l, m;
  object *_who;             // we need it maybe later for the bodyparts again
  object *all_targets;      // all persons affected by feelings (for remote);
  string s;                 // the output is sent to all_persons+remote_targets
                            // in case of remote, otherwise to the room of the
                            // player + remote_targets
  status valid_who, add_agent;
  string verb;              // needed for verb-dependent bodydata
  mixed *adverbs;           // to filter message-based adverbs
  int possessive;           // possessive case for some special verbs,
                            // 'You nod at X and ruffle his hair.'
  object *rooms;            // the get_room()s of the receivers

  add_agent = 1;
  result = ({ });

  if (channel_listeners) {
    all_targets = channel_listeners;
  } else {
    if (remote_targets && sizeof(remote_targets)) {
      all_targets = ({ this_player() });
      for (i = 0; i < sizeof(msg); i++) {
        if ((j = member(msg[i], S_TARGET)) > -1)
          all_targets += msg[i][j+1];
      }
    } else {
      all_targets = filter((environment(this_player())->query_receivers() ||
                            all_inventory(environment(this_player()))) +
                           all_inventory(this_player()),
                           (#'living));
    }
// debug("coogan", all_targets);
    all_targets   = m_indices(mkmapping(all_targets) + remote_targets);
  }
//DEBUG_POINT_TP("coogan", ({ msg }));
  for (i = 0; i < sizeof(msg); i++) {
    r = msg[i];
    verb = 0;                             // reset the verb, Coogan, 23-Aug-2001
    for (j = 0; j < sizeof(r); j++) {
// debug("coogan", r[j]);
// debug("coogan", ({ result }));
      switch (r[j]) {

      case S_ADD_VERB:
        result += ({ M_VERB, r[j+1] });
        if (r[j+2] == S_TARGET) {
          result += ({ _who });
        } else if (r[j+2] == S_AGENT) {  // Coogan, 14-Jan-2002
          result += ({ this_player() });  // Alfe 2002-Jan-31
        } else {
          result += ({ this_player(), M_PRONOUN, M_OBJECT,
                       /* M_DESCRIBE_UNOWNED, */
                       this_player() });  // Alfe 2002-Jan-31
        }
        j = j + 2;
        break;

      case S_REAL_VERB:                         // this has higher prio
        verb = r[j+2];                          // for the bodydata
        break;

      case S_VERB:
        if (!verb)
          verb = r[j+1];
        result += ({ M_VERB, r[j+1], this_player() });  // Alfe 2002-Jan-31
        j++;
        if (valid_who)                          // mark the _who to be deleted
          valid_who = 0;                        // next time
        else
          _who = 0;                             // the targets are expired
        break;

      case S_HOW:
        adverbs = filter(r[j+1], #'pointerp);
        bps = r[j+1] - adverbs;
        if ((k = sizeof(adverbs))) {
          // for: r[j+1] == ({({ " under", S_POSSESSIVE, S_AGENT, " breath" })})
          // added the for() here, Coogan, 05-Dec-2000
          for (l = 0; l < k; l++) {
            if ((m = member(adverbs[l], S_POSSESSIVE)) > -1)
              adverbs[l][m] = M_PRONOUN;
            if ((m = member(adverbs[l], S_AGENT)) > -1)
              adverbs[l][m..m] = ({ M_S, this_player() });  // Alfe 2002-Jan-31
          }
          s = make_list(bps, "", "");
          if (strlen(s)) {
            s += " and";
          }
        } else {
          s = make_list(r[j+1]);
        }
        if (strlen(s) || sizeof(adverbs)) {
// debug("coogan", ({ result }));
          // added this if() to prevent double spaces between a verb and
          // the next feeling beginning with S_HOW, Coogan, 02-Apr-2001
          // added check for sizeof(result), Coogan, 05-Apr-2001
          if (!sizeof(result) ||
              !stringp(result[<1]) || result[<1][<1] != ' ')
            // next if() added, Coogan, 25-May-2001
            if (sizeof(result) || !channel_listeners || !add_agent)
              result += ({ " " });
          if (strlen(s)) {
            result += ({ s, M_SPACE });
          }
          if (sizeof(adverbs)) {
            int ad = 0, sad;
            sad = sizeof(adverbs);
            while (ad < sad) {
              result += adverbs[ad];
              ad++;
              if (ad < sad)
                result += ({ ", " });
              if (ad == sad - 1)
                result += ({ " and " });
            }
            result += ({ M_SPACE });
          }
        }
        j++;
        break;

      case S_AT:
        result += ({ " " + r[j+1] });
        if (sizeof(r) < j+2)                           // rule ends
          result += ({ " " });
        else                                    // fixed bug, added this branch,
          result += ({ M_SPACE });              // Coogan, 16-Oct-2002
        j++;
        break;

      case S_TARGET:
        // this part is to make the output nicer, e.g.
        // 'You grin at the knight and smile at him.' instead of
        // 'You grin at the knight and smile at the knight.'
        valid_who = 1;
        if (_who && sizeof(_who) &&
            sizeof(_who) == sizeof(r[j+1]) &&
            sizeof(_who) == sizeof(_who & r[j+1])) {    // the same targets
          if (sizeof(_who) == 1) {
            if (possessive)
              result += ({ M_PRONOUN, _who[0] });
            else
              result += ({ M_OBJECT, M_PRONOUN, _who[0] });
          } else {
            if (possessive)
              result += ({ M_TARGETS, _who, " all of ",
                           M_TARGETS, all_targets,
                           M_POSSESSIVE, M_PRONOUN, _who });
            else
              result += ({ M_TARGETS, _who, " all of ",
                           M_TARGETS, all_targets,
                           M_OBJECT, M_PRONOUN, _who });
          }
        } else {
          if (possessive)  // added this check, Coogan, 20-Aug-2001
            result += ({ M_THE, M_OBJECT, r[j+1] });
          else {
            if (!sizeof(remote_targets) &&   // added these checks for some
                pointerp(r[j+1]) &&          // special cases, Coogan,28-Apr-02
                (present(r[j+1][0], environment(this_player())) ||
                 present(r[j+1][0], this_player())))
              result += ({ M_THE, M_OBJECT, r[j+1] });
            else
              result += ({ M_THE, M_OBJECT, /* M_DESCRIBE_UNOWNED, */ r[j+1] });
          }
        }
        possessive = 0;  // in any case unset possessive after the target
                         // was evaluated, Coogan, 10-May-2001
        _who = r[j+1];
        j++;
        break;

      case S_BODY_TARGET:
        valid_who = 1;
        possessive = 0;
        _who = r[j+1];
        j++;
        break;

      case S_BODY:
        bps = map(r[j+1],
                  lambda(({ 'x, 'y, 'z, 'a, 'b }),
                         ({ #'get_bodydata_for_verb, 'y, 'x, 'z, 'a, 'b })),
                  verb, !!_who, _who || this_player(),
                  (_who && pointerp(_who) && sizeof(_who) == 1 &&
                   _who[0] == this_player()));
        if (sizeof(bps) && sizeof(bps[0]))  // Coogan, 27-Jul-2006
          result += ({ " " });
        for (k = 0; k < (l=sizeof(bps)); k++) {
          if (!stringp(bps[k])) {               // a more complicated bodypart
            if ((m = member(bps[k], S_S)) > -1) {
              bps[k][m..m] = ({ M_S });
            }
            if ((m = member(bps[k], S_POSSESSIVE)) > -1) {
              bps[k][m..m] = ({ M_POSSESSIVE });
            }
            if ((m = member(bps[k], S_OBJECT)) > -1) {
              bps[k][m..m] = ({ M_OBJECT });
            }
            if ((m = member(bps[k], S_TARGET)) > -1) {
              bps[k][m..m] = _who || this_player();  // Alfe 2002-Jan-31
            }
            result += bps[k];
          } else
            result += ({ bps[k] });
          if (k < l-2)                          // not yet the last bodypart;
            result += ({ ", " });               // make_list() fails with
          else                                  // mixed types in the
            if (k == l - 2)                     // *list argument,
              result += ({ " and " });          // so we have to do it ...
        }
        j++;
        break;

      case S_TEXT:
        if (j > 0 && r[j+1][0]!=',')    // add a space, if the text is not
                                        // added at the beginning or does not
          result += ({ " " });          // begin with a "," like 'You ok, too.'
        result += ({ r[j+1], M_SPACE });
        j++;
        break;

      case S_MESSAGE:
        if (r[j+1] == "nothing" || r[j+1] == "something") // for say/tell/etc.
          result += ({ " ", r[j+1] });                    // without message
        else
          result += ({ ", " + r[j+1] });
        j++;
        break;

      case S_THE_AGENT:                 // explicitely give the agent
        result += ({ /* M_DESCRIBE_UNOWNED, */ M_THE, this_player() });
                                                            // Alfe 2002-Jan-31
        if (i == 0)                     // important: For 'Suddenly, ...'
          add_agent = 0;                // don't write the agent before giving
                                        // out the message
        break;

      case S_AGENT:
        result += ({ /* M_DESCRIBE_UNOWNED, */ this_player() });
                                                          // Alfe 2002-Jan-31
        if (!_who)  // Coogan, 01-Feb-2001
          _who = ({ this_player() });
        break;

      case S_POSSESSIVE:
        result += ({ M_POSSESSIVE });
        if (pointerp(r[j+1])) {         // S_POSS, ({ S_AGENT, S_TARGET })
          mixed pi, *pr;
          pr = map(r[j+1], (: switch ($1) {
                              case S_AGENT : return this_player();
                              case S_TARGET: return $2;
                              }
                              // == default, outside switch() because of
                              // NO_WARN_MISSING_RETURN; Coogan, 26-Mar-2011
                              return $1; :), _who);
          pr = flatten_array(pr);
          result += ({ pr });
          j++;
        }
        break;

      case S_OBJECT:
        result += ({ M_THE, M_OBJECT });
        break;

      case S_S:
        result += ({ M_THE, M_S });
        possessive = 1;
        break;

      case S_PRONOUN:
        result += ({ M_PRONOUN, r[j+2] });
        j = j + 2;
        break;

      default:
        result += ({ r[j] });           // just add it; seems to be a message
        break;                          // token.
      }
    }
    if (i < sizeof(msg) -2)
      result += ({ ", " });
    else if (i == sizeof(msg) -2)
      result += ({ " and " });
  }

  if (!sizeof(result))  // e.g. a feeling event was changed
    return 0;           // Coogan, 09-Jan-2001

  if (channel_listeners) {
    if (add_agent)
      // removed 2nd pair of [] in the message below, Coogan, 12-Dec-2003
      result = ({ M_TARGETS, channel_listeners, " ",
                  M_TARGETS, ({ this_player() }), "You",  // Alfe 2002-Jan-31
                  M_TARGETS, channel_listeners - ({ this_player() }),
                     this_player()->query_vis_name(),
                  M_TARGETS, channel_listeners, " " }) + result;
    else
      result = ({ M_TARGETS, channel_listeners, " ",
                  M_CAPITALIZE }) + result;
    if (!stringp(result[<2]) ||
        result[<2][<1] != '?' &&
        result[<2][<1] != '!')
      result += ({ "." });
    // result += ({ "]" });
//DEBUG_POINT_TP("coogan", ({ result }));
  } else {
    if (add_agent)
      result = ({ /* M_DESCRIBE_UNOWNED, */ M_THE, this_player() }) + result;
                                                            // Alfe 2002-Jan-31
    if (!stringp(result[<2])  ||
        result[<2][<1] != '?' &&
        result[<2][<1] != '!')
      result += ({ "." });
//DEBUG_POINT_TP("coogan", ({ "remote targets", remote_targets }));
//DEBUG_POINT_TP("coogan", ({ "all targets", all_targets }));
//if (global_feeling_event[E_AGENT] == find_player("coogan"))
//  debug("coogan", global_feeling_event);

    // added next filtering of all_targets, as remote targets can have been
    // taken out of the sent event, Coogan, 10-Jan-2001
    // added the room check, Coogan, 14-Dec-2001
    rooms = map(global_feeling_event[E_RECEIVERS], #'get_room);
#if 1  // Alfe 2002-Jan-17
    rooms = flatten_array(rooms + map(rooms,
                                      (: m_indices($1->query_viewers() ||
                                                   ([])) :)) - ({ 0 }));
#endif
    all_targets = filter(all_targets,
                         lambda(({ 'x, 'y }),
                                ({ #'>,
                                   ({ #'member, 'y, ({ #'get_room, 'x }) }),
                                   -1 })), rooms);
//DEBUG_POINT_TP("coogan", ({ "remote targets", remote_targets }));
//DEBUG_POINT_TP("coogan", ({ "all targets", all_targets }));
    if (sizeof(remote_targets))  // TERMCOL_REMOTE_FEELING by Coogan,23-Nov-2000
      result = ({ M_TARGETS, m_indices(remote_targets) + all_targets,
                  M_CNTL_SEQ,
#if 0  // Coogan, 19-Oct-2001
                  TERMCOL_REMOTE_FEELING,
#else
                  M_APPLY, (: (TERMCOL_REMOTE_FEELING":" +
                               ($1 && to_real_name($1->query_name()))) :),
                  M_ARG, E_AGENT,
#endif
                  "From afar, " }) + result + ({ M_CNTL_SEQ, TERMCOL_NORMAL });
    else
      result = ({
#if 1 // Coogan, 18-Jan-2002
                  M_ROOM, environment(global_feeling_event[E_AGENT]),
#else
                  M_TARGETS, all_targets,
#endif
                  M_CNTL_SEQ,
#if 0  // Coogan, 19-Oct-2001
                  TERMCOL_FEELING
#else
                  M_APPLY, (: (TERMCOL_FEELING":" +
                               ($1 && to_real_name($1->query_name()))) :),
                  M_ARG, E_AGENT,
#endif
                  }) +
                  result + ({ M_CNTL_SEQ, TERMCOL_NORMAL });
  }
//if (this_player() && this_player()->query_real_name()=="coogan")
//DEBUG_POINT_TP("coogan", ({ result }));
  return result;
}

mixed* compose_message(mapping f) {
  mixed *msg, *adv, *body, *rule;
  int i, *fi;
  string verb, *modificator, message;
  object *who, agent;

  msg = ({ });
  fi = sort_array(m_indices(f), #'>);
  for (i = 0; i < sizeof(fi); i++) {
//if (this_player() == find_player("coogan")) debug("coogan", f[i]);
    if (!f[i, _F_MESSAGE]) {
      verb        = f[i, _F_EVENT][E_FEELING];
      who         = f[i, _F_EVENT][E_PERSONS];
      adv         = f[i, _F_EVENT][E_ADVERBS];
      message     = f[i, _F_EVENT][E_MSG];
      body        = f[i, _F_EVENT][E_BODYPARTS];
      modificator = f[i, _F_EVENT][E_MODIFICATION];
      agent       = f[i, _F_EVENT][E_AGENT];
      if (!(rule = get_matching_rule(verb, who, adv, message, body))) {
        return 0;
      }
      f[i, _F_MESSAGE] = parse_one_rule(rule, verb, who, adv, message,
                                        body, modificator, agent);
    }
    msg += ({ f[i, _F_MESSAGE] });
  }
  return msg;
}

int do_feel(string p) {
  string verb, verb_tmp;
  mixed *q, *msg, *new_msg, *rule;
  int e, i, *fi;
  mapping feelings;
  object *rt;

  string message, *adv, *body;
  object *who, agent;
  string *modificator;

  channel_listeners = 0;
  verb = query_verb();
  if (!member(modificator_list, verb) &&
      !query_is_verb(verb) &&
      verb != "feeling")
    return 0;
  if (member(({ "say" /*, "listen", "lick", "smell", "sniff", "taste" 
                      */  }), verb) > -1)
    return 0;
  if (verb == "look" && (!p || (p && p[0..2] == "at ")))
    return 0; /* cara */
  feeling_kind = "feeling";
  if (verb == "feeling")
    verb = p;
  else if (p)
    verb += " " + p;
  if (!(feelings = parse_soul_command(verb)))
    return 0;
  fi = sort_array(m_indices(feelings), #'>);  // some feelings can be cancelled
                                              // so don't use the raw indices
  remote_targets = ([ ]);       // delete them to rebuild them anew out of
                                // all processed events, Coogan, 02-Jul-2001
  for (i = 0; i < sizeof(fi); i++) {
    feelings[i, _F_RECEIVED] = send_feeling_event(feelings[i, _F_EVENT]);
    verb        = feelings[i, _F_RECEIVED][E_FEELING];
    who         = feelings[i, _F_RECEIVED][E_PERSONS];
    adv         = feelings[i, _F_RECEIVED][E_ADVERBS];
    message     = feelings[i, _F_RECEIVED][E_MSG];
    body        = feelings[i, _F_RECEIVED][E_BODYPARTS];
    modificator = feelings[i, _F_RECEIVED][E_MODIFICATION];
    agent       = feelings[i, _F_RECEIVED][E_AGENT];
    if ( sizeof(feelings[i, _F_EVENT][E_PERSONS]) &&    // the original targets
        !sizeof(feelings[i, _F_RECEIVED][E_PERSONS])) { // are all deleted, so
      m_delete(feelings, i);    // delete the feeling too, otherwise a rule
      continue;                 // without targets could match, which is
    }                           // not intended. Coogan, 02-Jul-2001
    if (!sizeof(feelings[i, _F_EVENT][E_PERSONS]) &&          // no targets
        !sizeof(feelings[i, _F_RECEIVED][E_PERSONS]) &&       // but all remote
         sizeof(feelings[i, _F_EVENT][E_REMOTE_TARGET]) &&    // targets are
        !sizeof(feelings[i, _F_RECEIVED][E_REMOTE_TARGET])) { // gone, so
      m_delete(feelings, i);                    // delete this feeling too.
      continue;                                 // Coogan, 02-Jul-2001
    }
    if (!(rule = get_matching_rule(verb, who, adv, message, body))) {
      m_delete(feelings, i);                    // something is wrong: no rule!
      continue;                                 // so better delete that feeling
    }
    feelings[i, _F_MESSAGE] = parse_one_rule(rule, verb, who, adv, message,
                                             body, modificator, agent);
    remote_targets += mkmapping(feelings[i, _F_RECEIVED][E_REMOTE_TARGET]);
                                                // Coogan, 02-Jul-2001
//    if (sizeof(remote_targets))
//      DEBUG_POINT("coogan", ({ "remote_targets", remote_targets }));
  }

  msg = compose_message(feelings);
//  DEBUG_POINT_TP("coogan",  ({ msg }));
//  DEBUG_POINT("coogan", ({ "remote_targets", remote_targets }));
  msg = compose_message_output(msg);
//  DEBUG_POINT_TP("coogan",  ({ msg }));
  if (msg)  { // Coogan, 09-Jan-2001 {
    // DEBUG_POINT_TP("coogan", ({ msg[0..] }));
    // DEBUG_POINT_TP("alfe",   ({ msg[0..] }));
    send_message(msg, ([ E_AGENT : this_player() ]));
  }
  return 1;
}

varargs status wizline(string p, string channel, int tm_type) {
  mixed *q,*r;
  object rp, tp;
  string w, service;
  int i;

  mapping f;
  mixed *msg;

  if (!p) {
    notify_fail("What feeling?\n");
    return 0;
  }

  if (!channel)
    channel = "soul";

  tm_type = tm_type || INTERMUD_LOCAL;
  if (member(LIB_CHANNELS->query_all_channels(tm_type), channel) < 0) {
    notify_fail("That's no valid channel.\n");
    return 0;
  }

  remote = 0;
  channel_listeners = LIB_CHANNELS->get_listeners(channel, tm_type);

  if (!sizeof(channel_listeners)) {
    notify_fail("Nobody would hear you.\n");
    channel_listeners = 0;
    return 0;
  }
#ifdef INTERMUD3
  else if (tm_type == INTERMUD_3)
    channel_listeners += ({ find_object(__MASTER_OBJECT__) });
    // kernel/master is only a place-holder for the 'other' message in
    // case of a channel emote without targets
#endif

  if (!(f = parse_soul_command(p, 2))) {
    channel_listeners = 0;
    return 0;
  }
  msg = compose_message(f);
#ifdef INTERMUD3
  tp = 0;
  if (!sizeof(remote_targets)) {
    channel_listeners += ({ (tp = create_sould()) });
    service = "channel-e";
  }
  else
    service = "channel-t";
  foreach (rp : (m_indices(remote_targets) + (tp ? ({ tp }) : ({ })))) {
    rp->set_channel_emote(1);
    rp->set_channel(channel);
    rp->set_transmission_type(tm_type);
    rp->set_service(service);
  }
  channel_listeners += m_indices(remote_targets);
#endif
  msg = compose_message_output(msg);
//DEBUG_POINT_TP("coogan",({channel_listeners,remote_targets,msg,service,tp }));

#ifdef INTERMUD3
  if (tm_type == INTERMUD_3 &&
      (IMUD3->query_channels())[channel]) {
    w = message2string(msg[0..], find_object(__MASTER_OBJECT__));
    foreach (rp : m_indices(remote_targets) + (tp ? ({ tp }) : ({ })))
      rp->set_other_msg(w);
    if (service == "channel-e")
      tp && tell_object(tp, "\n");  // well - send the msg ONLY to the
                // intermud object. The real msg was already given with
                // set_other_msg(), the tell_object() only calls catch_tell().
    else        // service == "channel-t": send the msg to the intermud
                // object[s]. The player-receivers will get the message
                // back from the i3-router.
      foreach (rp : m_indices(remote_targets) + (tp ? ({ tp }) : ({ })))
        tell_object(rp, message2string(msg[0..], rp));
  } else {
#endif
    LIB_CHANNELS->channel_shout_message(channel, msg[0..], ({ channel }), 0);
#ifdef INTERMUD3
  }
#endif
  channel_listeners = 0;
  return 1;
}

status feeling_do(string s) {
  mixed h;
#if 1  // Alfe 2002-Jan-25
  h = member(s,':');
  if (h >= 0)
    h = ({ s[0..h-1], s[h+1..] });
  else
    h = ({});
#else
  h = explode(s,":") - ({ "" });
#endif
  if (sizeof(h) < 2)
    return notify_fail("Try 'feeling do <adverbs>: <command>'.\n"), 0;
  while (h[1][0] == ' ')
    h[1] = h[1][1..];
  h = ({ h[0],implode(h[1..], " ") });
  if (!(h[0]=parse_soul_command("nod / " + h[0],1)))
    return 0;
  current_adverb_list = h[0][_F_EVENT][E_ADVERBS];
  current_this_player = this_player();
  current_commandline = this_player()->query_commandline();
  h = !!command(regreplace(h[1], "^ *", "", 1), this_player());
  current_adverb_list = current_commandline = current_this_player = 0;
  return h;
}

string query_current_adverb_string() {
  if (this_player() == current_this_player)
    return (sizeof(current_adverb_list) == 1
            ? current_adverb_list[0]
            : make_list(current_adverb_list));
}

int feeling(string p) {
  string v;
  mixed *q;
  int e;

  channel_listeners = 0;
  if (!p) {
    write("What feeling?\n");
    return 1;
  }
  if (p[0..2] == "do ")  // Alfe 1998-Apr-23
    return feeling_do(p[3..]);
  feeling_kind = "feeling";
  return do_feel(p);
  return 1;
}

int dispatch(string verb, string arg) {
  remote = 0;
  remote_targets = m_allocate(2, 0);
  channel_listeners = 0;
  return daemon::dispatch(verb, arg);
}

