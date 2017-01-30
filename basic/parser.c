/*
 * basic/parser
 * The central parser module
 */

#include <grammar.h>
#include <libs.h>
#include <regexps.h>

private mapping rules;
private mapping classes;

// mapping rules:
// rules[family][verb] yields an array of rule entries
// that work for the given verb. (the family selector is for
// having more than one set of rules, e.g. one for parsing
// commands and one for parsing catch_tell() input.)
// The array consists of three subarrays, holding the
// following data:
// array[0][i] = the grammatical pattern
// array[1][i] = the object that defines the handler for the rule
// array[2][i] = the function within the object to be called.
// Note: objects may be given as strings to avoid problems when
// they get destructed.

// mapping classes:
// classes[class_name] maps a class into an object, function pair
// to be called for parsing that grammatical class.

// The following mapping is shared among ALL instances of this
// class. Therefore we have to make it private & static to
// prevent manipulation from outside which would affect all
// instances. It has the same layout as the variable classes.

#define DEFAULT_FAMILY "default"

private static mapping default_classes = ([ ]);

// for debugging.
varargs mixed query_rules(string verb, mixed family)
{
  family = family||DEFAULT_FAMILY;
  return
    verb ?
    rules && rules[family] && rules[family][verb] :
    rules && rules[family];
}

private void set_default_classes()
{
  if (sizeof(default_classes))
    return; // already initialized.
  // It is important that mapping += mapping changes the mapping
  // on the left hand side instead of generating a new mapping that
  // is the sum of both. Use mapping = mapping + mapping for the
  // latter case. But since we want to save memory, we want the
  // former.
  default_classes +=
  ([
    G_OBJECT:                   LIB_GRAMMAR;"parse_object",
    G_INDIRECT:                 LIB_GRAMMAR;"parse_indirect",
    G_FAKEITEM:                 LIB_GRAMMAR;"parse_fakeitem",
    G_LIVING:                   LIB_GRAMMAR;"parse_living",
    G_CONTAINER:                LIB_GRAMMAR;"parse_object",
    G_BODYPART:                 LIB_GRAMMAR;"parse_bodypart",
    G_ME:                       LIB_GRAMMAR;"parse_me",
    G_THIS_ME:                  LIB_GRAMMAR;"parse_this_me",
    G_ALL:                      LIB_GRAMMAR;"parse_all",
    G_ALL_OBJECT:               LIB_GRAMMAR;"parse_all_object",
    G_ALL_INDIRECT:             LIB_GRAMMAR;"parse_all_indirect",
    G_OBJECT_LIST:              LIB_GRAMMAR;"parse_object_list",
// I caution the use of all the following G_ALL-items
// and those with INVENTORY and ENVIRONMENT
// Rather check those things yourself.
    G_ALL_LIVINGS:              LIB_GRAMMAR;"parse_all_livings",
    G_ALL_ITEMS:                LIB_GRAMMAR;"parse_all_items",

    G_IN_INVENTORY:             LIB_GRAMMAR; "parse_in_inventory",
    G_IN_ENVIRONMENT:           LIB_GRAMMAR; "parse_in_environment",
    G_ALL_IN_INVENTORY:         LIB_GRAMMAR; "parse_all_in_inventory",
    G_ALL_IN_ENVIRONMENT:       LIB_GRAMMAR; "parse_all_in_environment",

    G_ONLY_IN_INVENTORY:        LIB_GRAMMAR; "parse_in_inventory",
    G_ONLY_IN_ENVIRONMENT:      LIB_GRAMMAR; "parse_in_environment",
    G_ALL_ONLY_IN_INVENTORY:    LIB_GRAMMAR; "parse_all_only_in_inventory",
    G_ALL_ONLY_IN_ENVIRONMENT:  LIB_GRAMMAR; "parse_all_only_in_environment",

    // the following two are just for compatibility
    G_ALL_INVENTORY:            LIB_GRAMMAR; "parse_all_in_inventory",
    G_ALL_ENVIRONMENT:          LIB_GRAMMAR; "parse_all_in_environment",

    G_TEXT:             LIB_GRAMMAR;"parse_text",
    G_WORDS:            LIB_GRAMMAR;"parse_words",
    G_WORD:             LIB_GRAMMAR;"parse_word",
    G_ANY_LIVING:       LIB_GRAMMAR;"parse_any_living",
    G_ANY_LIVINGS:      LIB_GRAMMAR;"parse_rem_livings",
    G_AMBIG_LIVINGS:    LIB_GRAMMAR;"parse_ambig_rem_livings",
    G_MONEY:            LIB_GRAMMAR;"parse_money",
    G_ANY_MONEY:        LIB_GRAMMAR;"parse_any_money",
    G_NUMBER:           LIB_GRAMMAR;"parse_number",
    G_ORDINAL:          LIB_GRAMMAR;"parse_ordinal",
    G_RANGE:            LIB_GRAMMAR;"parse_range",
    G_NUMBERS:          LIB_GRAMMAR;"parse_numbers",
    G_TIME:             LIB_GRAMMAR;"parse_time",
    G_SIDE:             LIB_GRAMMAR;"parse_side",
    G_EXIT:             LIB_GRAMMAR;"parse_exit",
    G_VIEW:             LIB_GRAMMAR;"parse_view",
    G_TONGUE:           LIB_GRAMMAR;"parse_tongue",
    G_ADVERB:           LIB_GRAMMAR;"parse_adverb",
    G_ADVERBS:          LIB_GRAMMAR;"parse_adverbs",
    G_COLOUR:           LIB_GRAMMAR;"parse_colour",
    G_RACE:             LIB_GRAMMAR;"parse_race",

#ifdef INTERMUD3
    G_REMOTE_RESOURCE:          LIB_GRAMMAR;"parse_remote_resource",
    G_MUD_NAME:                 LIB_GRAMMAR;"parse_mud_name",
#endif

  ]);
}

// Define a new grammatical pattern.
// rulestring is something like "give <object> to <living>".
// The string (without the leading verb) is converted into an array 
// of subarrays.
// Each of the subarrays is either a sequence of words or a sequence
// of grammatical classes. They alternate, and the first and the last
// subarray always hold words, not grammatical classes, even if
// the subarrays would be empty. The above string (with the verb
// removed) would be represented as:
// ({ ({ }), ({ "<object>" }), ({ "to" }), ({ "<living>" }), ({ }) })
// There may be no more than two classes without a word in between.
// For instance, "foo <bar> <baz> <hum>" can't be used as a pattern.
// It isn't rejected by make_rule(), though.
static mixed *make_rule(mixed rulestring) {
  string *tokens;
  string verb;
  mixed *rule;
  string *tail;
  int i;

  // Initialize classes if not done yet.
  if (!classes) {
    classes = m_allocate(0,2);
    set_default_classes();
  }

  // Split the string into words and make them shared.
  if (stringp(rulestring)) {
    tokens = explode(rulestring," ");
    for (i=0;i<sizeof(tokens);i++)
      tokens[i] = make_shared_string(tokens[i]);
  }
  else
    tokens = rulestring;

  // Strip off the verb and all leading words.
  for (i=1; i<sizeof(tokens); i++) {
    if (tokens[i][0]=='<' && tokens[i] != "<") {
      break; }
  }
  rule = ({ tokens[1..i-1] });
  tokens = tokens[i..];

  // Now the same for any trailing words.
  for (i=1; i<=sizeof(tokens); i++) {
    if (tokens[<i][0]=='<' && tokens[<i] != "<") {
      break; }
  }
  if (i > 1)
    tail = tokens[<i-1..];
  else
    tail = ({ });
  tokens = tokens[0..<i];

  // Now get classes and words, alternating between them.
  for (;;) {
    for (i=0;i<sizeof(tokens);i++) {
      if (tokens[i][0]!='<')
        break;
    }
    rule += ({ tokens[0..i-1] });
    if (i>=sizeof(tokens))
      break;
    tokens = tokens[i..];
    for (i=0;i<sizeof(tokens);i++) {
      if (tokens[i][0]=='<')
        break;
    }
    rule += ({ tokens[0..i-1] });
    tokens = tokens[i..];
  }

  rule += ({ tail });
  return rule;
}

// add_rule() first strips the verb off for faster parsing (later).
// Afterwards it builds a rule via make_rule() and registers it 
// in the appropriate mapping (rules).
static varargs void add_rule(mixed rulestring,string action,string handler,
                             mixed family) {
  mixed *list;
  string verb;
  string *tokens;
  mixed *rule;
  int i;

  // Initialize classes if not done yet.
  if (!classes) {
    classes = m_allocate(0,2);
    set_default_classes();
  }

  if (pointerp(rulestring)) {
    rule = map(rulestring,#'map,#'make_shared_string);
    verb = rule[0][0];
    rule[0] = rule[0][1..];
  }
  else {
    // Split the string into words and make them shared.
    tokens = explode(rulestring," ");
    for (i=0;i<sizeof(tokens);i++)
      tokens[i] = make_shared_string(tokens[i]);

    // Strip off the verb and all leading words.
    verb = tokens[0];
    rule = make_rule(tokens);
  }
  family = family || DEFAULT_FAMILY;
  if (!(list = rules && rules[family] && rules[family][verb]))
    list = ({ ({ }), ({ }), ({ }) });
  list[0] += ({ rule });
  list[1] += ({ handler || this_object() });
  list[2] += ({ action });
  if (!rules)
    rules = ([ family : ([ verb : list ; 0 ]) ]);
  else if (!rules[family])
    rules[family] = ([ verb : list ; 0 ]);
  else
    rules[family][verb] = list;
}

static varargs void
set_rules(mapping r, string family)
{
  if (!rules)
    rules = ([ family||DEFAULT_FAMILY : r ]);
  else
    rules += ([ family||DEFAULT_FAMILY : r ]);
}

// Define an error message on a per-verb basis. This is of course
// insufficient and should be improved upon. Perhaps adding an
// "error" rule family to weed out simple error patterns?
static varargs void add_error_message(string verb,mixed message,mixed family)
{
  family = family || DEFAULT_FAMILY;
  if (!rules)
    rules = ([family : ([ verb : 0 ; message ]) ]);
  else if (!rules[family])
    rules[family] = ([ verb : 0 ; message ]);
  else
    rules[family][verb,1] = message;
}

static varargs void remove_error_message(string verb,mixed family)
{
  family = family || DEFAULT_FAMILY;
  if (!rules)
    return;
  else if (!rules[family])
    return;
  else
    rules[family][verb,1] = 0;
}

// This tells you what verbs add_action() has to handle.
varargs mixed *query_rule_verbs(mixed family)
{
  family = family || DEFAULT_FAMILY;
  return
    rules && rules[family] ?
    m_indices(rules[family]) :
    ({ });
}

// Get rid of a rule again.
static varargs void remove_rule(mixed verb,string action, mixed family)
{
  mixed *list;
  int pos, i;
  
  family = family || DEFAULT_FAMILY;
  if (!rules || !rules[family])
    return;
  if(!verb) // for all verbs
    verb = query_rule_verbs(family);
  else 
    if (stringp(verb)) verb = ({verb});
  for (i = sizeof(verb); i--; ) {
    if (!(list = rules[family][verb[i]]))
      continue;
    while((pos = member(list[2], action))>=0) {
      list[0][pos..pos]=({ });
      list[1][pos..pos]=({ });
      list[2][pos..pos]=({ });
    }
  }
}

mapping query_classes()
{
  return classes || m_allocate(0,2);
}

// Add a new class.
static varargs void add_class(string class,string func,string handler)
{
  if (!classes)
  {
    classes = m_allocate(0,2);
    set_default_classes();
  }
  classes[class,0] = handler || this_object();
  classes[class,1] = func;
}

static varargs void set_classes(mapping c)
{
  if (!classes)
    set_default_classes();
  classes = c;
}

// Duplicate a class under another name.
static void duplicate_class (string class, string new)
{
  if (!classes)
  {
    classes = m_allocate (0,2);
    set_default_classes ();
  }
  classes[new,0] = classes[class,0] || default_classes[class,0];
  classes[new,1] = classes[class,1] || default_classes[class,1];
}

// Get rid of a class.
static void remove_class(string class)
{
  m_delete(classes,class);
}

private string class_scope;

// query_class_scope() returns the currently parsed class, if it is
// called from within a parsing function, which is called by match_rule()
// or match_class().
string query_class_scope()
{
  return class_scope;
}

static closure query_class_handler(string class)
{
  if (!classes)
  {
    classes = m_allocate (0,2);
    set_default_classes();
  }
  if (classes[class])
    return symbol_function(classes[class,1],classes[class]);
  else if (default_classes[class])
    return symbol_function(default_classes[class,1], default_classes[class,0]);
}

// match a class against a pattern
static varargs status
match_class(string class, mixed result1, mixed result2, int first, int last,
            string *words, string *text, mixed *args)
{
  string old_class_scope;
  mixed h;
  closure handler;
  handler = query_class_handler(class);
  if (!handler) return 0;
  if (!args) 
    args = ({first, last, words, text});
  else if (!pointerp(args))
    args = ({first, last, words, text, args});
  else
    args = ({first, last, words, text}) + args;
  old_class_scope = class_scope;
  class_scope = class;
  h = apply(handler, &result1, &result2, args);
  class_scope = old_class_scope;
  return h;
}

// This function is a dummy function except when parse_rule() is used
// If you do this, you should call parser::do_action(action,args); 
// in your do_action()
mixed do_action(string action, mapping args) { 
  switch (action) {
  case "return_args":
    return args;
  default: 
    return 0;
  }
  return 0;
}

// match_rule() is the heart of the parsing algorithm. In fact,
// it's nothing sophisticated, just a clever pattern matcher.
// The verb being already stripped off, only the rest of the
// text is matched. words just holds the lower case words and
// punctuation sumbols, while text also has the white space in
// between.
static mixed match_rule(string *words,string *text,mixed *rule,
                        mixed handler,string action)
{
  int i,j,k,l;
  int first,mid,last,monotone;
  int *current;
  mixed *match;
  string *tokens;
  string *head,*tail;
  string w;
  mapping args;
  mixed call1ob,call1func,call2ob,call2func;
  mixed arg, result;
  mixed primary,secondary;
  string old_class_scope;

  if (!handler)
    handler = this_object();

  // First, compare and strip off leading and trailing words.
  if (sizeof(words)<sizeof(head = rule[0])+sizeof(tail = rule[<1]))
    return 0;
  for (i=0;i<sizeof(head);i++)
    if (words[i] != head[i])
      return 0;
  for (i=sizeof(words)-sizeof(tail),j=0;j<sizeof(tail);i++,j++)
  {
    if (words[i] != tail[j])
      return 0;
  }
  words = words[sizeof(head) .. <sizeof(tail)+1];
  text = text[2*sizeof(head) .. <2*sizeof(tail)+1];
  rule = rule[1..<2];

  // Check the simple case that there are no more words to match.
  if (!sizeof(rule[0]))
  {
    if (sizeof(words))
      return 0;
    if (handler == this_object())
      return do_action(action,m_allocate(0,2));
    else
      return handler->do_action(action,m_allocate(0,2));
  }
  if (sizeof(words)<sizeof(rule[0])) return 0; 
      /* the words can't even match the first rule */

  // match is an array of arrays, holding matching positions for
  // each sequence of words.
  match = allocate(sizeof(rule));
  for (i=1;i<sizeof(rule);i+=2)
  {
    k = sizeof(words)-sizeof(tokens = rule[i]);
    w = rule[i][0];
    match[i] = ({ });
    // A simple substring matching algorithm. Boyer-Moore etc. would
    // probably be overkill.
    for (j=0;j<k;j++)
      if (words[j]==w)
      {
        for (l=1;l<sizeof(rule[i]);l++)
          if (words[j+l]!=rule[i][l])
            break;
        if (l==sizeof(rule[i]))
          match[i] += ({ j });
      }
    if (!sizeof(match[i]))
      return 0;
  }

  // The class scope is for nested classes and thus has to be reset
  // before match_rule() is left again
  old_class_scope = class_scope;

  // current is an array of integers, each addressing a position within
  // a subarray of match. matching positions must be strictly increasing,
  // a fact that is recorded by the monotone flag.
  current = allocate(sizeof(match));
  for (;;)
  {
    if (monotone = sizeof(match) < 2 || match[1][current[1]])
    {
      for (i=3;i<sizeof(current);i+=2)
      {
        // Does one match occur before the previous or do they overlap?
        // We need at least one word in between, too.
        if (match[i][current[i]]<=match[i-2][current[i-2]]+sizeof(rule[i-2]))
        {
          monotone = 0;
          break;
        }
      }
    }
    if (monotone)
    {
      // Now parse each grammatical class in turn and record the
      // outcome in the args mapping.
      args = m_allocate(1,2);
      for (i=0;i<sizeof(rule);i+=2)
      {
        // One or two classes to parse?
        if (sizeof(rule[i])==1)
        {
          // find positions within the 'words' array.
          if (i==sizeof(rule)-1)
            last = sizeof(words)-1;
          else
            last = match[i+1][current[i+1]]-1;
          if (i==0)
            first = 0;
          else
            first = match[i-1][current[i-1]]+sizeof(rule[i-1]);
          // find the parsing object and function for the class.
          if (!m_contains(&call1ob,&call1func,classes,rule[i][0]))
            m_contains(&call1ob,&call1func,default_classes,rule[i][0]);
          // Zero secondary, in case it doesn't get set by the
          // parsing routine. Then call the parsing function.
          secondary = 0;
          class_scope = rule[i][0];
          arg = call_other_2ref(call1ob,call1func,
                    &primary,&secondary,first,last,words,text);
          // If the parse failed, go around the loop again.
          if (!arg)
          {
            args = 0; // Announce that we failed.
            break;
          }
           // Else record the result.
           args[w=rule[i][0],0]=primary;
           args[w,1]=secondary;
        }
        else // Two classes to parse.
        {
          // find start and end of the words to be parsed.
          if (i==sizeof(rule)-1)
            last = sizeof(words)-1;
          else
            last = match[i+1][current[i+1]]-1;
          if (i==0)
            first = 0;
          else
            first = match[i-1][current[i-1]]+sizeof(rule[i-1]);
          // get the parsing routines.
          if (!m_contains(&call1ob,&call1func,classes,rule[i][0]))
            m_contains(&call1ob,&call1func,default_classes,rule[i][0]);
          if (!m_contains(&call2ob,&call2func,classes,rule[i][1]))
            m_contains(&call2ob,&call2func,default_classes,rule[i][1]);
          // now try to split the text in every conceivable way.
          for (mid = first;mid<last;mid++)
          {
            secondary = 0;
            // match the first class
            class_scope = rule[i][0];
            if (call_other_2ref(call1ob,call1func,
                           &primary,&secondary,first,mid,words,text))
            {
              args[w=rule[i][0],0]=primary;
              args[w,1]=secondary;
              secondary = 0;
              class_scope = rule[i][1];
              if (call_other_2ref(call2ob,call2func,
                             &primary,&secondary,mid+1,last,words,text))
              {
                args[w=rule[i][1]]=primary;
                args[w,1]=secondary;
                // yes, exiting will ignore further possible matches
                // but the cost for this would be too high.
                break;
              }
            }
          }
          // If we found a match, mid will be less than last.
          // Otherwise, try again.
          if (mid == last)
          {
            args = 0; // announce our failure
            break;
          }
        }
      }
      // If we found a full match, call the action handler.
      // Return if we succeeded.
      if (args)
      {
        if (handler == this_object())
          result = do_action(action, args);
        else
          result = handler->do_action(action,args);
        if (result)
        {
          class_scope = old_class_scope; // reset the class scope
          return result;
        }
      }
    }
    // Iterate over all possible values of current.
    // Algorithm is similar to incrementing a number where
    // every digit has a different base.
    for (i=2; i<sizeof(current); i+=2)
    {
      current[<i]++;
      if (current[<i]<sizeof(match[<i]))
        break;
      current[<i]=0;
    }
    // Overflow indicates we checked all possibilities. Fail.
    if (i>=sizeof(current))
    {
      class_scope = old_class_scope; // reset the class scope
      return 0;
    }
  }
  NO_WARN_MISSING_RETURN;
}

varargs mixed parse_rule(string rulestring,int f,int l,
                         string *w,string *t,mixed handler,string action)
{
  mixed *rule;
  rule = make_rule("dummyverb "+rulestring);
  return match_rule(w[f..l],t[f*2..l*2+1],rule,
                    handler||this_object(),action||"return_args");
}

// Parse a sentence by iterating over all possible patterns
// for a given verb.
varargs mixed parse_sentence(mixed sentence, mixed family)
{
  string *words,*text;
  string verb;
  mixed message;
  mixed *subrules;
  int i;
  // Split the text into words (if it hasn't been done so, yet),
  // the array has the form ({ws,verb,ws,word1,...,ws,wordn}) (ws:white-space)
  if (stringp(sentence))
    text =  regexplode(sentence,REGEXP_PARSER_WORD);
  else
    text = sentence;
  // words doesn't hold the whitespace part.
  if (sizeof(text) < 2)
    return 0;
  words = allocate(sizeof(text)/2-1);
  for (i=0;i<sizeof(words);i++)
    words[i] = text[2*i+3];
  words = map (words, #'lower_case);
  family = family || DEFAULT_FAMILY;
  subrules = query_rules((verb = text[1]),family);
  text = text[2..];
  // Iterate over all possible rules until we succeed or no more
  // rules are left.
  if (subrules) {
    // In case of no match we set the notify_fail message already now so
    // a more distinguished notify_fail message of the same level can be set
    // by one of the rules.
    message = rules && rules[family] && 
              rules[family][verb,1];
    if (closurep(message))
      message = funcall(message,sentence,({ verb })+words);
    if (pointerp(message))
      notify_fail(message[0],message[1]);
    else if (stringp(message) || closurep(message))
      notify_fail(message);
    for (i=0;i<sizeof(subrules[0]);i++)
      if (message = 
          match_rule(words,text,subrules[0][i],subrules[1][i],subrules[2][i]))
        return message;
  }
  return 0; // Failure.
}

// Hook for add_action()s to call the parser.
int parse_action(string arg)
{
  return parse_sentence(arg ? query_verb() + " " + arg : query_verb());
}

// Easy interface to use from init(). Perform the necessary
// add_action()s.
varargs static void add_actions(string func, string family) {
  string *verbs;
  int i;
  closure add_act;
  add_act = symbol_function("add_action",this_object()) || (#'add_action);
  if (!sizeof(verbs = query_rule_verbs(family))) 
    return;
  for (i = 0; i < sizeof(verbs); i++)
    funcall(add_act,(func||"parse_action"),verbs[i],1);
}

string *build_rules(mixed pattern) {
  int i, j;
  string *h, *p, *r;

  if (stringp(pattern))
    return ({pattern});
  if (pointerp(pattern)) { // patterns following each other
    if (!sizeof(pattern))
      return ({});
    h = build_rules(pattern[1..]);
    p = build_rules(pattern[0]);
    if (!sizeof(h))
      return p;
    else if (!sizeof(p))
      return h;
    r = allocate(sizeof(h)*sizeof(p));
    for (i = sizeof(h); i--; )
      for (j = sizeof(p); j--; )
        r[j*sizeof(p)+i] = p[j]+" "+h[i];
    return r;
  }
  if (mappingp(pattern)) { // patterns in no particular order
    if (!sizeof(pattern))
      return ({});
    pattern = m_indices(pattern);
    r = ({});
    for (i = sizeof(pattern); i--; )
      r += build_rules(({pattern[i],mkmapping(exclude_element(pattern,i))}));
    return r;
  }
}

