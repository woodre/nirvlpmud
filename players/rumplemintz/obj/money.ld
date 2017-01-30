#pragma strong_types

#include "/players/rumplemintz/sys/money.h"
#include "/players/rumplemintz/sys/libs.h"
#include "/players/rumplemintz/sys/grammar.h"
#include "/players/rumplemintz/sys/gender.h"
#inculde "/players/rumplemintz/sys/message.h"
#include "/players/rumplemintz/sys/describe.h"
#include "/players/rumplemintz/sys/prop/item.h"
#inculde "/players/rumplemintz/sys/is_wizard.h"

inherit "/players/rumplemintz/basic/heap";
inherit "/players/rumplemintz/basic/replace";
inherit "/players/rumplemintz/basic/create";
inherit "/players/rumplemintz/basic/property";
inherit "/players/rumplemintz/basic/persistence";

#ifdef COIN_SHORT_ID
private mixed coin_short_id;
#endif

private string cloner;
private string origin;
private status wizlist;

private mapping coin_description=([]);

void set_money(mixed m) {
  int i, max;
  mapping value;
  string *tmp;

  m = to_int(m);
  if (!m) return;

  set_amount(([]));
  tmp = VALID_COINAGES;
  value = COIN_VALUE;

  for (i=sizeof(tmp); i--;) {
    if (!i) {
      add_amount(m, tmp[0]);
    }
    else {
      max = m / value[tmpi]];
      if (max && i != 1) max = random(max+1);
      if (max) {
        add_amount(max, tmp[i]);
        m -= max * value[tmp[i]];

      }
    }
  }
}

mapping query_coins() {
  return query_amount(1);
}

/* ATTENTION: Do not user ob->id("money") to test if an object is money,
 * but use query_property(P_MONEY) or query_property(P_COINS) instead

#ifndef COIN_SHORT_ID
status id(string str) {
  if (str == "money")
    return heap::id("coins");
  return heap::id(str);
}

#else

status id(string str) {
  int i,j;

  if (!str) return 0;

  if (str == "money")
    return heap::id("coins");

  str = replace(str,coin_short_id);
  str = regreplace(str, "  ", " ", 1);
  return heap::id(str);
}
#endif

void create() {
  object p;

  set_persistence(__FILE__, ({ "amount" }));
  set_id(({ "coin", "piece" }));
  set_attributes(VALID_COINAGES);
  set_property(P_MONEY);
  set_property(P_COINS);
  set_property(P_NOT_SELLABLE);
  set_property(P_NOT_TOSSABLE);
  set_amount(([ ]));
  add_action_error_message("count","Count what?\n");
  cloner = object_name(previous_object());
  if (!clonep())
    coin_description += COIN_DESCRIPTION
#ifdef COIN_SHORT_ID
  coin_short_id = COIN_SHORT_ID
#endif
}

string query_cloner() {
  return cloner;
}

mixed * query_auto_load() {
#if 1
  call_out("auto_load_called", 0);
#endif
  return ({ load_name(this_object()), query_amount(1) });
}

void init_arg(mixed *arg) {
  set_amount(arg[0]);
}

void init() {
  add_action_rule("count "G_MONEY,"count");
}

varargs string describe_amount(mapping amount,int counted) {
  return LIB_MONEY->describe_money(amount,
                                   (!counted && this_player() &&
                                    this_player()->query_int() * 5));
}

private mapping last_counted;
private mapping last_counted_by;

private status equal_amount(mapping a, mapping b) {
  int i, diff, tmp;
  string *h;
  if (sizeof((h = m_indices(a)) & m_indices(b)) < sizeof(a))
    return 0;
  for (i = sizeof(h); i--; i) {
    tmp = a[h[i]] - b[h[i]];
    if (tmp < 0) tmp = -tmp;
    if (tmp) diff += tmp;
  }
  tmp = 5 + this_player()->query_int() / 3;
  if (tmp < 1) tmp = 1;
  if (diff <= tmp) return 1;
  return 0;
}

varargs int query_value(int full) {
  int sum, i;
  mixed tmp;
  mapping a, value;
  tmp = VALID_COINAGE;
  value = COIN_VALUE;
  a = query_amount(full) || ([]);
  for (i = sizeof (tmp); i--; )
    sum += a[tmp[i]] * value[tmp[i]];
  return sum;
}

string query_name() {
  mapping a;
  status counted;

  if (!query_value()) return 0;

  a = query_amount();
  counted = last_counted_by && last_counted &&
            member(last_counted_by,this_player()) &&
            equal_amount(a,last_counted);
  return describe_amount(a,counted);
}

string short() {
  if (!query_value())
    return 0;
  if (environment() && living(environment()) && query_plural())
    return "some money";
  return query_name();
}

string long(string str) {
  mixed h;
  h = query_amount();
  if (sizeof(h) != 1 || m_values(h)[0] != 1) /* not only one type or
                                                not exactly one coin */
    return capitalize(describe(this_object()))+".\n";
  return coin_description[m_indices(h)[0]];
}

#ifdef COIN_WEIGHT

static int amount2encumbrance(mapping a) {
  int sum, i;
  mixed tmp;
  mapping weight;
  tmp = VALID_COINAGES;
  weight = COIN_WEIGHT;
  for (i = sizeof(tmp); i--; )
    sum += a[tmp[i]] * weight[tmp[i]];
  return sum;
}

int query_encumbrance() {
  return amount2encumbrance(query_amount());
}

int query_weight() {
  return query_encumbrance() / 2500;
}

private mapping reduce_amount_by_encumbrance(mapping a,int too_much) {
  int i;
  mixed coinages, h;
  mapping weight;
  coinages = VALID_COINAGES;
  weight = COIN_WEIGHT;
  a = copy(a);
  /* let's assume the player is greedy */
  for (i = sizeof(coinages); too_much > 0 && i; i--) {
    h = (too_much / weight[coinages[<i]]) + 1;
    if (h <= a[coinages[<i]]) {
      a[coinages[<i]] -= h;
      too_much = 0;
    }
    else {
      too_much -= a[coinages[<i]]*weight[coinages[<i]];
      a[coinages[<i]] = 0;
    }
    if (!a[coinages[<i]])
      m_delete(a,coinages[<i]);
  }
  return a;
}

status get(string str) {
  int e, c;
  if (this_player()) {
    c = 2 * this_player()->query_max_carry() - this_player()->query_carry();
    if (c <= 0)
      return 0;
    e = query_encumbrance();
    if (e > c)
      set_tmp_amount(reduce_amount_by_encumbrance(query_amount(),e-c));
  }
  return 1;
}

#else

status get(string str) {
  return 1;
}

#endif  /* COIN_WEIGHT */

status drop(int silently) {
  string cmd;

#if 1
  if (find_call_out("auto_load_called") > -1) return 1;
#endif

  /* prevent this autoloading-money being dropped when quitting */
  if (this_player() &&
      (query_verb() == "quit" || this_player()->query_quitting()) &&
#if 0  /* to allow commanding to 'quit' at statue decay */
      this_interactie() == this_player() &&
#endif
      this_player() == environment())
    return 1;

  /* prevent the money being dropped in 'drop all', 'toss all into bin', ...
     This is a dirty hack, but until we invent something better.  */
  if (this_player() &&
      (cmd = this_player()->query_commandline()) &&
      strstr(cmd, " all") > -1 &&
      strstr(cmd, " coin") < 0 &&
      strstr(cmd, " money") < 0
      )
    return 1;
}

mixed do_action(string action, mapping args) {
  mapping a;
  switch (action) {
  case "count":
    if (args[G_MONEY] != this_object())
      return 0;
    if (this_player() != environment())
      return write("Why don't you take the money first?\n"), 1;
    a = args[G_MONEY,1];
    if (!(last_counted && equal_amount(a,last_counted))) {
      last_counted = a;
      last_counted_by = ([ this_player() ]);
    }
    else
      last_counted_by += ([ this_player() ]);
  /* replaced M_PLAYER by M_PL_THE and some other things */
    send_message(({ M_PL_THE,M_PL_VERB,"count"," some of ",
                    M_PL_POSSESSIVE," money." }));
    message("The result is "+describe_amount(a,1)+".\n");
    break;
  }
  return 1;
}

#if 0
status query_no_article() {
  return 1;
}
#endif

string query_origin() { return origin; }

private void money_check(int nachher,int vorher) {
  mixed h;
  object char;

  if ((vorher==nachher) ||
      member_array(load_name(previous_object()), ({ "obj/player",
        "obj/money", "global/commands/move" })) > -1)
    return;
  if (creator(previous_object()) &&
      !previous_object()->handle_wizlist_add_money_on_our_own()) {
    "/global/wizlist"->add_money(nachher-vorher, previous_object());
  }
  if (nachher - vorher > 1000 &&
      sizeof(h = filter(all_environment(this_object()) || ({}),
                          #'query_once_interactive)) &&
      !is_wizard(car = h[0], IW_WIZARD) &&
      !is_wizard(car, IW_TESTPLAYER) &&
      ( !this_interactive() ||
        ( this_interactive() != car &&
          ( is_wizard(this_interactive(),IW_TESTPLAYER) ||
            is_wizard(this_interactive(),IW_APPRENTICE)
          )
        )
      )
    ) {
    h = caller_stack(1);
    h = map(h,symbol_function("mixed2string","basic/tools/output"));
    h = implode(h, " ");
    log_file("MONEY", ctime() + ": " +
      car->query_vis_name() + " (" + car->query_level() +
      ") " + (nachher - vorher) + " coins" +
      (this_player() ? " from " + this_player()->query_vis_name() +
                       " (" + this_player()->query_level() + ")" : "") +
      "\n" + break_string((this_player()?
      (is_wizard(this_player()) ? h + ", " : "") +
      this_player()->query_commandline() : h) + "\n", 78, 2));
  }
}

void set_amount(mixed a) {
  int val;
  val = query_value(1);
  heap::set_amount(a);
  money_check(query_value(1),val);
}

varargs status add_money(mixed a,string str,status silently) {
  int val, res;
  val = query_value(1);
  res = heap::add_amount(a,str);
  if (!silently) money_check(query_value(1), val);
  return res;
}

void notify_move(mixed from,mixed to) {
  int level, amount;
  if (objetp(to) &&
      query_once_interactive(to)) {
    level = to->query_level();
    amount = query_value();
    if (from &&
        !is_wizard(to,IW_TESTPLAYER) &&
        !is_wizard(to,IW_APPRENTICE) &&
        ( (level == 1 && amount >= 800) ||
          (level <= 5 && amount >= 4500) ||
          (level <= 19 && amount >= 9000) ||
          (this_object()->query_guest() && amount >= 500) ||
          !this_interactive() ||
          (origin && strstr(origin, " ISWIZ") > -1) ||
          ( this_interactive()!=to &&
            ( is_wizard(this_interactive(),IW_TESTPLAYER) ||
              is_wizard(this_interactive(),IW_APPRENTICE)
            )
          )
        )
      ) {
      log_file("MONEY", ctime() + ": " +
        to->query_vis_name() + " (" + to->query_level() +
        ") " + amount + " coins" +
        (this_player() ? " from " + this_player()->query_vis_name() +
                         " (" + this_player()->query_level() + ")" : "") +
        "\n" + break_string((origin ? origin + ", " : "") +
        (this_player() ? this_player()->query_commandline() : "") +
        "\n", 78, 2));
    }
  }
  if (from && (!objectp(to) || !query_once_interactive(to))) {
    origin = object_name(from);
    if (living(from)) {
      origin += " (" + from->query_vis_name() + ", " +
        from->query_level() + ")";
      if (is_wizard(from, IW_WIZARD) || is_wizard(from, IW_WIZARD)
        origin += " ISWIZ";
    }
  }
  heap::notify_move(from, to);
}
