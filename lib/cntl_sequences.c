/*
 * lib/cntl_sequences.c
 *
 * This file contains functions concerning control sequences (ANSI, Xterm)
 */

#pragma strong_types
#pragma no_clone
#pragma no_inherit

#include <cntl_sequences.h>
#include <prop/player.h>
#include <termcol.h>
#include <bits.h>

inherit "basic/coloured_string";

private nosave mapping plain_mapping;

static void compute_plain_mapping() {
  string *models, *codes;
  int i;

  models = m_indices(TERMCOL_MODELS);
  for (i = sizeof(models); i-->0; ) {
    codes = (codes || ({ })) + m_indices(TERMCOL_MODELS[models[i]]);
  }
  models = m_indices(TERMCOL_DESC_MODELS);
  for (i = sizeof(models); i-->0; ) {
    codes = (codes || ({ })) + m_indices(TERMCOL_DESC_MODELS[models[i]]);
  }
  models = m_indices(TERMCOL_TECH_MODELS);
  for (i = sizeof(models); i-->0; ) {
    codes = (codes || ({ })) + m_indices(TERMCOL_TECH_MODELS[models[i]]);
  }
  codes += m_indices(TERMCOL_SERVICES);
  codes += TERMCOL_DESC_DESCRIPTIONS;
  codes += TERMCOL_TECH_DESCRIPTIONS;
  codes += ({ TERMCOL_DESC TERMCOL_LIVING });

  codes += /*map(*/m_indices(TERMCOL_CS_SEQUENCES);//,
               // (: "%^" + $1 + "%^" :));

  plain_mapping = m_reallocate(mkmapping(codes), 1);
  plain_mapping = map(plain_mapping,(: "" :));
}

mapping get_plain_mapping() {
  if (plain_mapping)
    return copy(plain_mapping);  // copy()
  compute_plain_mapping();
  return copy(plain_mapping);  // copy()
}

// This function is mainly called by living->compute_terminal_colour_mapping().
// A test, if the object pl is supporting services/technical/colours et all,
// is already done in basic/player/colour.c before calling this function here
// and could be dropped here, but who knows ...
mixed get_colour_code_sequence(mixed key, object pl) {
  string k1, k2, model, setting, orig_key;
  int resolved = 0, ind, state;

  if (pointerp(key))
    return flatten_array(map(key, #'get_colour_code_sequence, pl));

  if (!stringp(key))
    return "";  // ignore that key, should be better than raise_error()

  if (!pl || !(model = pl->query_property(P_TERMCOL_MODEL)))  // no colours
    return "";
  setting = pl->query_property(P_TERMCOL_SETTING);
  state   = pl->query_property(P_TERMCOL_STATUS);

  // tokens like TERMCOL_RED, TERMCOL_BOLD
  if (member(TERMCOL_MODELS[model], key))
    return TERMCOL_MODELS[model][key];

  // tokens for descriptions like (TERMCOL_DESC TERMCOL_RED)
  if (member(TERMCOL_DESC_MODELS[model], key) &&
      TEST_BIT(state, TERMCOL_BIT_DESCRIPTION))
    return TERMCOL_DESC_MODELS[model][key];

  // tokens for technical messages (TERMCOL_TECH TERMCOL_RED)
  if (member(TERMCOL_TECH_MODELS[model], key) &&
      TEST_BIT(state, TERMCOL_BIT_TECHNICAL))
    return TERMCOL_TECH_MODELS[model][key];

  // All simple colour tokens (TERMCOL_*_{RED,BOLD,BG_*}) have been handled.
  // Now the more complicated ones.

  // the special description and technical colour defines
  // (TERMCOL_DESC TERMCOL_PLAYER, TERMCOL_TECH TERMCOL_INFO) need extra
  // handling
  if (member(TERMCOL_DESC_DESCRIPTIONS, key) > -1)
    key = key[sizeof(TERMCOL_DESC)..];   // cut "DESC_"
  else if (member(TERMCOL_TECH_DESCRIPTIONS, key) > -1)
    key = key[sizeof(TERMCOL_TECH)..];   // cut "TECH_"

  else if ((ind = strstr(key, ":")) > 0) {   // ":<name>" is only for services,
    orig_key = key;                          // therefore an 'else if'
    key = orig_key[0..ind-1];
  }

  if (member(TERMCOL_DESCRIPTIONS, key)) {
    // e.g. TERMCOL_PLAYER
    if (!TEST_BIT(state, TERMCOL_BIT_DESCRIPTION))
      return "";
    resolved = 1;
  }
  else if (member(TERMCOL_TECHNICAL, key)) {
    // e.g. TERMCOL_INFO
    if (!TEST_BIT(state, TERMCOL_BIT_TECHNICAL))
      return "";
    resolved = 1;
  }
  else if (member(TERMCOL_SERVICES, key)) {
    // e.g. TERMCOL_SAY
    if (!TEST_BIT(state, TERMCOL_BIT_SERVICE))
      return "";
    resolved = 1;
  }

  if (member(TERMCOL_CS_SEQUENCES, key)) {
    if (!TEST_BIT(state, TERMCOL_BIT_DESCRIPTION) &&
        !TEST_BIT(state, TERMCOL_BIT_TECHNICAL)   &&
        !TEST_BIT(state, TERMCOL_BIT_SERVICE))
      return "";
    return TERMCOL_CS_SEQUENCES[key];
  }

  if (!resolved) {       // unknown key
    return "";
  }

  key = orig_key || key;

  if ((k1 = pl->query_fg_colour(setting, key)) &&
      TERMCOL_MODELS[model][k1])
    k1 = TERMCOL_MODELS[model][k1];
  else
    k1 = "";

  if ((k2 = pl->query_bg_colour(setting, key)) &&
      TERMCOL_MODELS[model][TERMCOL_BG_PREFIX + k2])
    k2 = TERMCOL_MODELS[model][TERMCOL_BG_PREFIX + k2];
  else
    k2 = "";

  return k1 + k2;
}

// called by sefun::describe() and from get_colour_code() below
string get_living_colour_description(object agent, object target) {
  mixed o;

  if (!target || !agent || !living(target))
    return "";
  // DEBUG_POING("rumplemintz", ({ agent, target }));
  o = agent->query_attack();
  o = (o ? ({ o }) : ({ })) +
      (agent->query_alt_attack() || ({ })) +
      ({ agent->query_hunted(), agent->query_hunter(),
         target->query_hunter() }) - ({ 0 });
  if (member(o, target) > -1 || target->query_aggressive())
    return TERMCOL_DESC_ENEMY;
  if (interactive(target))
    return TERMCOL_DESC_PLAYER;
  return TERMCOL_DESC_NPC;
}

// this function is mainly called by message() with M_CNTL_SEQ.
// If the colour key is known, it is mapped to the appropriate colour key
// for terminal_colour().
// Examples: TERMCOL_INFO        --> %^TECH_INFO%^
//           TERMCOL_EXIT        --> %^DESC_EXIT%^
//           TERMCOL_SAY         --> %^SAY%^
//           TERMCOL_RED         --> %^RED%^
//           TERMCOL_DESC_RED    --> %^DESC_RED%^

mixed get_colour_code(mixed key, object pl) {
  string k1, k2, res, model;
  int i;

  if (pointerp(key))
    return flatten_array(map(key, #'get_colour_code, pl));

  if (!stringp(key))
    return "";  // ignore that key, should be better than raise_error()
  /*
  if (pl->query_real_name()=="rumplemintz")
    DEBUG_POINT("rumplemintz",({key,pl}));
  */

  if (key == TERMCOL_LIVING &&
      this_player()) {
    return get_living_colour_description(pl, this_player());
  }
  // description and technical keys are always without ":name"
  if (member(TERMCOL_DESCRIPTIONS, key))
    return TERMCOL_DESCRIPTIONS2DESC_DESCRIPTIONS[key];
  if (member(TERMCOL_TECHNICAL, key))
    return TERMCOL_TECHNICAL2TECH_DESCRIPTIONS[key];

  // for message arrays, it's possible to give M_CNTL_SEQ, TERMCOL_DESC_RED,
  // and the key already has the %^ at the beginning/end:
  // check those keys for DESC_ or TECH_, others are not allowed here.
  if (key[<2..<1]=="%^") {
     if (key[0..6] == "%^"TERMCOL_DESC || key[0..6] == "%^"TERMCOL_TECH)
       return key;
     return "";
  }

  // rest: service keys (possibly with ":name") or *_NORMAL
  return "%^" + key + "%^";
}

string quote_for_terminal_colour(string s) {
  //  return regreplace(s,"([%^])","%^\\1%^",1);
  return regreplace(s,"%\\^","%^%^",1);  // cheaper version according to doc
}


