/*
 * global/commands/magic
 *
 * If you change something of the event handling here, please keep in mind,
 * that this file is inheritted by global/commands/combat_magic,
 * so the same changes have to be made there, too.
 *
 * Coogan, 14-Dec-98
 *
 */

#pragma strong_types

#include <action.h>
#include <server.h>
#include <event.h>
#include <grammar.h>
#include <describe.h>

// static as long as new combat is not yet active, otherwise private
static int calculate_success(mapping e) {
  string art_path, lore_path;
  int ar, lr, diff, result;

  lore_path = SE_MAGIC->query_magic_skill_path(e[E_LORE]);
  art_path  = SE_MAGIC->query_magic_skill_path(e[E_ART]);

  // For the magic event we use the modified skill values. But for the
  // skill reward, we have to use the unmodified skill values, because
  // a guild can change the skill value due to changing the modify_skill
  // event - and if we take the (most probably) increased skill value into
  // account, the reward will be lower than the reward of an equally skilled
  // player who is not a member of that guild.

#if 0
debug("coogan", "reward = "+
      SE_SKILLS->
        query_reward(e[E_AGENT],
                     e[E_AGENT]->roll_dice(e[E_AGENT]->query_skill(art_path),
                                           e[E_ART,1]),
                     e[E_ART,1],
                     art_path));
#endif
  e[E_AGENT]->
    add_skill_points(lore_path,
      SE_SKILLS->
        query_reward(e[E_AGENT],
                     e[E_AGENT]->roll_dice(e[E_AGENT]->query_skill(lore_path),
                                           e[E_LORE,1]),
                     e[E_LORE,1],
                     lore_path));
  e[E_AGENT]->
    add_skill_points(art_path,
      SE_SKILLS->
        query_reward(e[E_AGENT],
                     e[E_AGENT]->roll_dice(e[E_AGENT]->query_skill(art_path),
                                           e[E_ART,1]),
                     e[E_ART,1],
                     art_path));

  lr = e[E_AGENT]->query_modified_skill(lore_path);
  ar = e[E_AGENT]->query_modified_skill(art_path);
  result = (lr + ar) / 3 + to_int(sqrt(to_float(lr * ar)));
  diff   = (e[E_LORE,1] + e[E_ART,1]) / 3 +
           to_int(sqrt(to_float(e[E_LORE,1] * e[E_ART,1])));
  result = e[E_AGENT]->roll_dice(result, diff);
  return (result > 100) ? 100 : result;
}

private status
try_spell(mapping spell) {
  string *req, *sha;
  object body;
  mixed h;

  h = SE_MAGIC->locate_spell(spell[E_SPELL]);

  if ((req = h->query_requirements()) &&
      sizeof(req)) {  // as long as COMBAT is not available, we make some
                      // primitive checks here
    if (member(req, "right hand") &&
        spell[E_AGENT]->query_wield()) {
      notify_fail("You can't use your right hand now because of your wielded "+
                  describe(spell[E_AGENT]->query_wield(), ARTICLE_NONE)+"!\n");
      return 0;
    }
    if (member(req, "left hand") &&
        sizeof(filter(spell[E_AGENT]->query_armour(),
                            lambda(({ 'x }),
                                   ({ #'==,
                                      ({ #'call_other, 'x, "query_type" }),
                                      "shield" }))))) {
      notify_fail("You can't use your left hand now because of your worn "
                  "shield!\n");
      return 0;
    }
    if (member(req, "hand")) {
      if (spell[E_AGENT]->query_wield()) {
        if (spell[E_AGENT]->query_wield()->query_twohander())
          return notify_fail("You don't have a free hand because of your "
                             "wielded "+describe(spell[E_AGENT]->query_wield(),
                                                 ARTICLE_NONE) + "!\n"), 0;
        if (sizeof(filter(spell[E_AGENT]->query_armour(),
                                lambda(({ 'x }),
                                       ({ #'==,
                                          ({ #'call_other, 'x, "query_type" }),
                                          "shield" })))))
          return
            notify_fail("You don't have a free hand to cast this spell.\n"), 0;
      }
    }
  }

  if (!h->init_spell(spell))
    return 0;
  spell[E_SUCCESS] = calculate_success(spell);

  call_out(#'send_event, spell[E_DELAY]/1000, E_MAGIC, spell,
                                                 environment(spell[E_AGENT]));
  set_timed_flag(spell[E_AGENT]->query_real_name()+"#running_spell",
                 spell[E_DELAY]/1000);
  call_out(#'set_timed_flag, spell[E_DELAY]/1000 - 1,
           spell[E_AGENT]->query_real_name()+"#delay_after",
           spell[E_EXTRA_DELAY]);
  return 1;
}

private status cast_spell(mapping data) {
  object pl;
  mapping se;
  string spell;
  mixed tmp;
  int level, delay;
  string lore_path, art_path;

  switch (sizeof(tmp=SE_MAGIC->identify_spell(data[E_SPELL], data[E_AGENT]))) {
    case 0: return notify_fail("Cast which spell?\n",-1), 0;
    case 1: break;
    default:
      notify_fail("Which spell do you want to cast: " +
                  make_list(tmp, 0, " or ") + "?\n");
      return 0;
  }
  spell = tmp[0];
  if (!(se = SE_MAGIC->query_spell_event(spell)))
    return SE_MAGIC->magic_error("\""+spell+"\": Invalid spell!"), 0;
  se[E_SPELL]  = spell;

  se += ([ E_TYPE  : "magic";       0,
           E_AGENT : data[E_AGENT]; data[E_AGENT]->query_name(), ]);
  if (data[E_TARGET])
    se += ([ E_TARGET : data[E_TARGET];
                        describe(data[E_TARGET], ARTICLE_NONE) ]);
  if (data[E_COMPONENT])
    se += ([ E_COMPONENT : data[E_COMPONENT];
                           describe(data[E_COMPONENT], ARTICLE_NONE) ]);

  if (test_timed_flag(se[E_AGENT]->query_real_name()+"#running_spell") > 0)
    return notify_fail("There is still a spell of yours running!\n"), 0;
  if (data[E_AGENT]->query_sp() < se[E_COST]) {
    notify_fail("You feel too exhausted to cast this spell.\n");
    return 0;
  }
  if (test_timed_flag(se[E_AGENT]->query_real_name() + "#delay_after") > 0) {
    notify_fail("You still feel too exhausted to cast a spell now.\n");
    return 0;
  }
  if (!SE_MAGIC->locate_spell(spell))
    return 0;

  lore_path = SE_MAGIC->query_magic_skill_path(se[E_LORE]);
  art_path  = SE_MAGIC->query_magic_skill_path(se[E_ART]);

  if (!se[E_AGENT]->query_skill(lore_path) ||
      !se[E_AGENT]->query_skill(art_path)  ||
      !se[E_AGENT]->query_spells(spell))
    return notify_fail("Cast which spell?\n"), 0;

#if 0  // Coogan, 06-Jan-99
  if (se[E_AGENT]->query_modified_skill(lore_path) < se[E_LORE,1] ||
      se[E_AGENT]->query_modified_skill(art_path)  < se[E_ART,1])
    return notify_fail("You are too unexperienced to cast this spell.\n"), 0;
#endif
  return try_spell(se);
}

status do_action (string verb, mapping args) {
  int number;
  string spell;
  mapping data; 

  data = ([ ]);
  data[E_SPELL] = args[G_WORDS];
  data[E_AGENT] = this_player();
  if (strstr(verb, "component", 0) >= 0) {
    if (!present(args[G_OBJECT], this_player()))
      return 0;
    data[E_COMPONENT] = args[G_OBJECT];
  }
  if (strstr(verb, "target", 0) >= 0) {
    if (args[G_INDIRECT] == environment(this_player()))
      data[E_TARGET] = ({ args[G_INDIRECT,1] });
    else
      data[E_TARGET] = ({ args[G_INDIRECT] });
  }
  if (strstr(verb, "multi", 0) >= 0) {
    if (number = args[G_ALL,1][1])
      data[E_TARGET] = args[G_ALL][0..number-1];
    else
      data[E_TARGET] = args[G_ALL];
  }

  if (this_player()->query_body())  // this is for combat testing
    return "global/commands/combat_magic"->cast_spell(data);

  return cast_spell(data);
}

