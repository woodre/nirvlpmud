/*****************************************************************************
          /global/server/skills.c -- written Ugh 1995 for Tubmud
*****************************************************************************/

#pragma strong_types   // Coogan, 24-Mar-2011

#include <skills.h>
#include <kernel.h>
#include <event.h>
#include <libs.h>
#include <assert.h>
#include <skilltree.h>  // path changed, Coogan, 28-Dec-01

#define SKILL_PRIVILEGE "Skills:"
#define ERR_PRIV        "insufficient privilege"

#define SAVE_FILE       "/save/skills"
#define SAVE_FILE_TREE  "/save/skill_tree"
#define LOG_FILE        "Skills.handlers"
#define LOG_FILE_TREE   "Skills.tree"

inherit ACCESS;
inherit "/basic/create";

private mapping handlers;   // path -> handler

private mapping skill_tree; // path -> (default-forget-interval,
                            //          parent-weight,
                            //          number-of-subskills)

#define FORGET_INTERVAL 0
#define PARENT_WEIGHT 1
#define SUBSKILLS 2
#define SKILLS_DATA_WIDTH 3

        void introduce_skills();
private void modify_skills(mapping e, string t, int p);
  // private added, Coogan, 11-Oct-01

void create() {
  // Ugh Jul-5-1995
  set_global_listening_event("modify_skill",1);
  set_global_listening_event("modify_skills",1);
  listen_event("modify_skill");
  listen_event("modify_skills",0,#'modify_skills);
  handlers = LIB_SAVER->load(SAVE_FILE);
  skill_tree =
    LIB_SAVER->load(SAVE_FILE_TREE) ||
    m_allocate(100,SKILLS_DATA_WIDTH);
#ifdef NEW_SKILLS
  introduce_skills();
#endif
}

static void save_handlers(string mess)
{
  if (mess)
    log_file(LOG_FILE,
             ctime(time())+" "+
             (this_interactive() ? 
              this_interactive()->query_vis_name() : 
              object_name(previous_object())) + ": " + 
              mess+"\n");
  unguarded(1,#'call_other,({LIB_SAVER,"save",handlers,SAVE_FILE}));
}

static void save_skill_tree(string mess, int delayed)
{
  if (mess)
    log_file(LOG_FILE_TREE,
             ctime(time())+" "+
             (this_interactive() ? 
              this_interactive()->query_vis_name() : 
              object_name(previous_object())) + ": " + 
              mess+"\n");
  if (delayed) {
    if (find_call_out("save_skill_tree") < 0)
      call_out("save_skill_tree", 0, 0, 0);
  } else
    unguarded(1,#'call_other,({LIB_SAVER,"save",skill_tree,SAVE_FILE_TREE}));
}

void normalize_skill(mixed skill)
{
  assert(referencep(&skill));
  // the function is called with the argument call-by-reference
  assert((pointerp(skill) || stringp(skill)));
  if (pointerp(skill))
    skill = implode(skill,"|");
  skill = regreplace(skill, "^skill\\|", "", 0);
}

/* 
 * add_skill_handler() is called with a skill and a handler
 * the skill can be given as string delimited by '|' or as
 * skill-path-array. The handler must be given as loadable object_name
 * The successful use of add_skill_handler() will be logged to 
 * /log/Skills.handlers.
 */
public string add_skill_handler(string skill,mixed handler)
{
  if (!check_previous_privilege(SKILL_PRIVILEGE))
    return ERR_PRIV;
  if (stringp(handler))
  {
    if (catch(load_object(handler)))
      return "handler does not exist";
  } else if (objectp(handler)) {
    handler = object_name(handler);
  }
  assert(stringp(handler));
  normalize_skill(&skill);
  assert(stringp(skill));
  if (handlers && member(handlers,skill))
    return skill+" is already handled by "+handlers[skill];
  handlers = (handlers||([])) + ([skill : handler]);
  save_handlers("handler "+handler+" added for skill "+skill);
  return 0;
}

/*
 * remove_skill_handler() removed a previously added handler for the
 * given skill.
 * The successful use will be logged to /log/Skills.handlers.
 */
public string remove_skill_handler(string skill)
{
  if (!check_previous_privilege(SKILL_PRIVILEGE))
    return ERR_PRIV;
  normalize_skill(&skill);
  if (!(handlers && member(handlers,skill)))
    return "no handler defined for skill "+skill;
  m_delete(handlers,skill);
  save_handlers("handler removed for skill "+skill);
  return 0;
}

/*
 * The skill-handler of a skill can be queried with query_skill_handler().
 * Also, if you give no argument, you get all the skills and their 
 * handlers (as mapping skill -> handler).
 */
public mixed query_skill_handler(string skill)
{
  if (!skill)
    return handlers && copy(handlers);
  normalize_skill(&skill);
  return handlers && handlers[skill];
}

/*
 * This will be called as default-handler by /global/server/events
 * whenever send_event("modify_event", ... ) is done.
 * It will call in the respective handler the function 
 * modify_skill() is called with the modify_skill-event-mapping as 
 * argument.
 * This behaviour is defined by /save/event_handlers, so if you want
 * to change it, you have to do it there.
 */

/*
 * The sense of the formulae used in the following function is as follows:
 * - boni and mali are first summarized independently:
 *   - a bonus says, how many percent of the difference of the skill to 100
 *     is added to the skill.
 *     reason: the better you are in a skill, the less things that 
 *             could help you in your tasks while you were low in the skill,
 *             can help you (if I can climb like I was born to it naked,
 *                           boots of climbing won't help me as much as
 *                           they will while I am still learning to climb).
 *   - a malus says, how many percent of the skill are substracted from it.
 *     reason: If you are bad in a skill, handicaps had by people with
 *             a high skill can't bother you as much as them (you just can't
 *             determine WHY you are bad, you are just bad). The better you
 *             are in a skill, the more you perceive your handicaps, 
 *             although they won't make you as bad as someone unskilled.
 * - afterwards, the sum of the mali and the sum of the boni is calculated
 *   and used to compute the weighed average between the summarized
 *   bonus and malus.
 * EXAMPLE 1: skill 40, bonus 20: result 40+(100-40)*20% == 52
 * EXAMPLE 2: skill 40, malus 20: result 40-40*20% == 31
 * EXAMPLE 3: skill 40, boni 20 and 40, mali 10 and 30:
 *            result ((40+60*20%+48*40%)*60 + (40-40*10%-36*30%)*40)/(60+40) ==
 *                     ((40+12+19)*60 + (40-4-10)*40)/100 == 53
 */
public void receive_event(mapping e)
{
  int i, *h, malus, bonus, m_weight, b_weight, value;
  string handler;
  if (e[E_HANDLED])  // Alfe 95-Jun-20
    return;
  e[E_HANDLED]=1;  // Alfe 95-Jun-20
  if (handler = query_skill_handler(e[E_TYPE]))
    handler->modify_skill(e);
  h = e[E_MODIFICATION];
  malus = bonus = e[E_SKILL];
  for (i=sizeof(h);i--;)
  {
    value=h[i];
    if (value>0 && value<101)
    {
      b_weight += value;
      bonus = bonus + ((100-bonus)*value)/100;
    }
    else if (value<0 && value>-101)
    {
      m_weight -= value;
      malus = malus + (malus*value)/100;
    }
  }
  if (b_weight || m_weight)
    e[E_SKILL] = 
      ((bonus*b_weight)+(malus*m_weight))/(b_weight+m_weight);
}

private void modify_skills(mapping e, string t, int p) {
  mapping handlers;

  handlers =
    mkmapping(m_values(map_indices(e[E_SKILL],#'query_skill_handler)))-([0]);
  // call it in each handler only once!
  map_indices(handlers, #'call_other, "modify_skills", e);
}

/*
 * This function returns the reward for skills which do not have an own
 * handler.
 */
int query_default_reward(object who,int success,int difficulty,mixed skill) {
  return 0;  // on default, learning by doing is disabled.
}

/*
 * Every skill-handler for a skill whose improve-schema is learning by doing
 * should provide a function query_reward() which - dependant of the 
 * success, the player had, and the difficulty of the task, the player
 * completed - should return a reward for that skill-test (in skill-points to
 * be added)
 */
int query_reward(object who, int success, int difficulty, mixed skill)
{
  string handler;

  normalize_skill(&skill);
  if (handler = query_skill_handler(skill))
    return handler->query_reward(who,success,difficulty,skill);
  else
    return query_default_reward(who,success,difficulty,skill);
}

/*
 * The next function computes an integer-based version
 * of 100*exp(-x/500) in the range of 0 to MAX_EXP_FACTOR_RANGE
 * This means that the functions falls monotonously down to a value of 13
 * For parameters below 0 or above 1000, the values of the respective
 * parameter-limits are returned (100 for 0, 13 for 1000)
 */
#define MAX_EXP_FACTOR_RANGE 1000
#define EULER_FACTOR    0.002

private static mapping exp_skill_factor_table;

public int
exp_skill_factor(int x)
{
  int result;

  if (!intp(x))
    // added this_object() for prg_name(), Coogan, 12-Sep-00
    raise_error("Bad argument 1 to "+load_name(this_object())+
                "::exp_skill_factor()\n");
  if (!exp_skill_factor_table)
    exp_skill_factor_table = ([]);
  if (x > MAX_EXP_FACTOR_RANGE)
    x = MAX_EXP_FACTOR_RANGE;
  else if (x < 0)
    x = 0;
  if (!m_contains(&result,exp_skill_factor_table,x))
    result = exp_skill_factor_table[x] =
      to_int(exp(-to_float(x)*EULER_FACTOR)*100);
  return result;
}

public status
valid_skill_path(mixed skill)
{
  normalize_skill(&skill);
  return member(skill_tree,skill);
}

private static mapping parent_skill; // this is a cache

public string get_parent_skillpath(string path) {
  int i;
  string parent;

  if (!parent_skill) 
    parent_skill = ([]);
  if (member(parent_skill,path))
    return parent_skill[path];
  for (i = strlen(path); i--; )
    if (path[i] == '|')
      return
        parent_skill[path] =
          make_shared_string(path[0..i-1]);
  return parent_skill[path] = 0;
}

#define DEFAULT_PARENT_WEIGHT (16)

varargs public string introduce_skill(mixed path,
                                      int forget_interval,
                                      int parent_weight) {
  string p;

  if (!check_previous_privilege(SKILL_PRIVILEGE))
    return ERR_PRIV;
  if (valid_skill_path(&path))
    return "skill already exists";
  if (p = get_parent_skillpath(path)) {
    if (!valid_skill_path(p))
      return "can't create subskill of non-existing skill: "+p;
  }
  skill_tree += ([ path :
                    forget_interval; 
                    parent_weight || DEFAULT_PARENT_WEIGHT;
                    0 ]);
  while (p) {
    skill_tree[p,SUBSKILLS]++;
    p = get_parent_skillpath(p);
  }
  save_skill_tree("introduced path "+path+" with "
                  "forget_interval: "+forget_interval+", "
                  "parent_weight: "+parent_weight, 1 /* delayed */);
  return 0;  // Coogan, 24-Mar-2011
}

public string set_forget_interval(mixed path, int value) {
  int o;

  if (!check_previous_privilege(SKILL_PRIVILEGE))
    return ERR_PRIV;
  if (!valid_skill_path(&path))
    return "skill not valid";
  o = skill_tree[path,FORGET_INTERVAL];
  skill_tree[path,FORGET_INTERVAL] = value;
  save_skill_tree("changed forget_interval of path "+path+": "+o+" -> "+value,
                  1 /* delayed */);
  return 0;  // Coogan, 24-Mar-2011
}

public int get_forget_interval(mixed path) {
  normalize_skill(&path);
  return skill_tree[path,FORGET_INTERVAL];
}

public string set_parent_weight(mixed path, int value) {
  int o;

  if (!check_previous_privilege(SKILL_PRIVILEGE))
    return ERR_PRIV;
  if (!valid_skill_path(&path))
    return "skill not valid";
  o = skill_tree[path,PARENT_WEIGHT];
  skill_tree[path,PARENT_WEIGHT] = value;
  save_skill_tree("changed parent_weight of path "+path+": "+o+" -> "+value,
                  1 /* delayed */);
  return 0;  // Coogan, 24-Mar-2011
}

public int get_parent_weight(mixed path) {
  normalize_skill(&path);
  return skill_tree[path,PARENT_WEIGHT];
}

public int count_subskills(mixed path) {
  normalize_skill(&path);
  return skill_tree[path,SUBSKILLS];
}

/* the next functions are for conversion of skill-trees of the old and
   the new system into each other */

string convert_skillname(mixed path) {
  normalize_skill(&path);
  switch (path) {
    case "mental|craft|trade|appraise":
      return S_ESTIMATE_VALUE;
    case "miscellaneous|read|common":
    case "other|mental|read|common":
      return S_READ_COMMON;
    case "other|mental|know|heraldic":
      return S_HERALDRY;
    case "other|mental|know|herbalism":
      return S_M_HERBALISM;
    case "other|mental|sense|see":
      return S_SEE;
    case "other|mental|sense|hear":
      return S_HEAR;
    case "other|mental|sense|feel":
      return S_FEEL;
    case "other|craft|brew|ale":
      return S_P_BREW;
    case "other|craft|bard|flute":
      return S_P_PLAY_FLUTE;
    case "social|trading":
    case "other|craft|sales|trading":
    case "other|craft|merchant|trading":
      return S_M_TRADE;
    case "miscellaneous|searching":
    case "other|mental|sense|search":
      return S_SEARCH;
    case "miscellaneous|thieves|pickpocket":
    case "other|craft|thief|pickpocket":
      return S_P_PICK_POCKET;
    case "social|art|music":
    case "other|craft|bard|music":
      return S_P_MUSIC;
    case "other|mental|lang|lizard":
    case "other|mental|lang|exotic|reptile|lizard":
      return S_LIZTONGUE;
    case "other|mental|lang|draconian":
    case "other|mental|lang|exotic|reptile|dragon":
      return S_DRACONIAN;
    case "social|curiosity":
    case "other|mental|social|curiosity":
      return S_LORE;
    case "other|phys|agile|throw":
      return S_THROW;
    case "other|phys|dextrous|climbing":
    case "miscellaneous|climbing":
    case "other|phys|agile|climb":
      return S_CLIMB;
    case "miscellaneous|thieves|picklock":
    case "other|craft|thief|picklock":
      return S_P_PICK_LOCK;
    case "other|craft|forge":
      return S_P_SMITH;
    case "other|phys|endure|swim|surface":
    case "other|phys|endure|swim|dive":
      return S_SWIM;
    case "other|mental|see|tracking":
      return S_TRACK;
    case "combat|swinging|onehanded":
      return S_P_SWING;
    case "combat|swinging|twohanded":
      return S_P_TWOHANDED_SWING;
    case "combat|thrusting|onehanded":
      return S_P_THRUST;
    case "combat|thrusting|twohanded":
      return S_P_TWOHANDED_THRUST;
    case "combat|crushing|bashing":
      return S_P_BASH;
    case "combat|crushing|lashing":
      return S_P_LASH;
    case "combat|crushing|slashing":
      return S_P_SLASH;
    case "combat|ranged|shooting":
      return S_P_SHOOT;
    case "combat|ranged|sling":
      return S_P_SLING;
    case "combat|ranged|throwing":
      return S_P_THROW;
    case "combat|unarmed|brawl":
      return S_P_BRAWL;
    case "combat|unarmed|soft_martial_art":
      return S_P_SOFT_MARTIAL_ART;
    case "combat|unarmed|hard_martial_art":
      return S_P_HARD_MARTIAL_ART;
    default:
      return path;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 24-Mar-2011
}

/* t is of the form ({ ({ <name>, <exp>, <children> }), ... }) where <children>
 * is either 0 or something of the form of t
 */

#define SUM(x) (fold_left(#'+,x,0))

varargs mapping make_skill_tree(mixed *t, string path) {
  int i, s;
  mapping h, m;
  string name;

  m = ([]);
  if (t)
    for (i = sizeof(t); i--; ) {
      name = path ? path+"|"+t[i][0] : t[i][0];
      h = make_skill_tree(t[i][2],name);
      s = t[i][1] - SUM(m_values(h));
      /* if (s > 0) */
        h += ([ name : s ]);
      m += h;
    }
  return m;
}

mixed *compat_skill_tree(mapping tree) {
  mixed *root, *node, *parent;
  string *path, *paths;
  int i, j, k, all;
  status node_was_root;

  if (!mappingp(tree))
    return ({});
  paths = sort_array(m_indices(tree), #'<);
  root = ({});
  all = 0;

  // the 'parent' variable is only there because of the semantics of '+='
  // on arrays which changes the pointer to the array.
  // the variable is used to change the parent's reference to the new
  // child-array
  for (i = sizeof(paths); i--; ) {
    path = explode(paths[i],"|");
    node = root; // always begin at the root
    parent = 0;  // the root has no parent-node
    for (j = sizeof(path); j; j--) {
      for (k = sizeof(node); k--; ) { // search the children
        if (node[k][0] == path[<j]) {
          node[k][1] += tree[paths[i]];
          parent = node[k];
          node = parent[2];
          break;
        }
      }
      if (k < 0) { // no such child found -> add new child
        node_was_root = root == node;
        node += ({ ({path[<j], tree[paths[i]], ({})}) });
        if (node_was_root)
          root = node;
        if (parent)
          parent[2] = node;
        parent = node[<1];
        node = parent[2];
      }
    }
    node = root;
  }
  for (i = sizeof(root); i--; )
    all += root[i][1];
  return ({({"skill", all, root})});
}

void introduce_skills() {
  string *skills;
  int i;
  mixed h;

  skills = VALID_SKILLS;
  for (i = sizeof(skills); i; i--) {
    if (!valid_skill_path(skills[<i])) {
      if (h = unguarded(1, #'introduce_skill, ({skills[<i],0,10}))) {
      }
    }
  }
}
