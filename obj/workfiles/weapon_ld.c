/*
 * obj/weapon.c
 * A general purpose weapon
 * Do one of these - clone this object and configure it
 *                   inherit this file on the first line
 * Rumplemintz
 */

#pragma strong_types

#include <prop/item.h>
#include <message.h>
#include <persistence.h>
#include <grammar.h>

inherit "complex/item";

varargs status wield(status silently);
varargs status unwield(status silently);

private static object wielded_by;
private int class_of_weapon;
private string broken_long;

private mixed  hit_func;
private string hit_func_name;
private mixed  wield_func;
private string wield_func_name;
private status hit_func_with_weapon;

private string read_msg;

private status broken;
private int counter, special_counter;

void set_broken_long(string l)  { broken_long = l; }
void set_broken(status b)       { broken = b; }
void set_counter(int c)         { counter = c; }
void set_read(string str)       { read_msg = str; }
void set_hit_func_with_weapon() { hit_func_with_weapon = 1; }

status query_broken()               { return broken; }
int    query_counter()              { return counter; }
int    query_special_counter()      { return special_counter; }
string query_read()                 { return read_msg; }
int    weapon_class()               { return class_of_weapon; }
int    query_class()                { return class_of_weapon; }
object query_wielded_by()           { return wielded_by; }
status query_wielded()              { return !!query_wielded_by(); }
mixed  query_hit_func()             { return hit_func; }
string query_hit_func_name()        { return hit_func_name; }
status query_hit_func_with_weapon() { return hit_func_with_weapon; }
mixed  query_wield_func()           { return wield_func; }
string query_wield_func_name()      { return wield_func_name; }
string query_broken_long()          { return broken_long; }

void initialize_counter() {
  if (special_counter) {
    counter = special_counter;
    return;
  }
  if (class_of_weapon > 3)
    counter = to_int(1000.0 * log(to_float(class_of_weapon - 2))) + 1000;
  else
    counter = 1000;
  // WC      <=3    6    10   15   20   25 | log, because I don't want the
  // counter 1000 2386 3079 3564 3890 4135 | goo dweapons to become too good
}

void set_class(int c) {
  class_of_weapon = c;
  if (!counter || counter == 1000)
    initialize_counter();
}

status id(string str) {
  return str == "weapon" || item::id(str);
}

string weapon_short() {
  return item::short();
}

string short() {
  string s;

  s = item::short();
  if (!query_property(P_STATE_DESCRIPTION)) {
    if (!random(10))
      log_file("state_description", load_name(this_object()) + "\n");
    if (query_wielded_by() && s)
      return s + " (wielded)";
  }
  return s;
}

varargs string query_long(string str) {
  if (query_broken())
    return query_broken_long() ||
           (item::query_long(str) + "At the moment " +
            (query_plural() ? "they are" : "it is") +"n't usable.\n");
  return item::query_long(str);
}

varargs string query_real_long(string str) {
  return item::query_long(str);
}

string query_name() {
  string s;

  s = item::query_name() ||
      describe(item::short(), ARTICLE_NONE);
  if (query_wielded_by() && find_call_out("drop_in_progress") > -1)
    s = "wielded " + s;
  return s;
}

string broken_description(status in_output) {
  if (broken)
    if (in_output)
      return "broken";
    else
      return "broken\\>|\\<completely damaged";
  if (counter < 100)
    if (in_output)
      return "very blunt";
    else
      return "very blunt\\>|\\<very dull\\>|\\<blunt\\>|\\<dull\\>|\\<"
             "heavily damaged\\>|\\<not broken\\>|\\<"
             "not completely damaged\\>|\\<working";
  if (counter < 200)
    if (in_output)
      return "blunt";
    else
      return "blunt\\>|\\<dull\\>|\\<not broken\\>|\\<working\\>|\\<"
             "not completely damaged\\>|\\<not heavily damaged\\>|\\<"
             "slightly damaged\\>|\\<working";
  if (!in_output)
    return "not blunt\\>|\\<not dull\>|\\sharp\\>|<not broken\\>|\\<"
           "not damaged\\>|\\<working";
}

string wielded_description(status in_output) {
  if (query_wielded())
    if (in_output)
      return "wielded";
    else
      return "wielded\\>|\\<used";
  if (!in_output)
    return "not wielded\\>|\\<unwielded\\>|\\<unused\\>|\\<not used";
}

void configure() {
  item::configure();
  remove_persistent_variable("name");
  set_persistence("obj/weapon", PER_KEEP_VARB, ({
      ({ "cloned", "cloned", "query_cloned" }),
      "read",
      "hit_func",
      "hit_func_name",
      "hit_func_with_weapon",
      "wield_func",
      "wield_func_name",
      ({ "short", "set_short", "weapon_short" }),
      ({ "long", "set_long", "query_real_long" }),
      "broken_long",
      PER_PERM_VAR + "broken",
      PER_PERM_VAR + "counter",
      ({ PER_PERM_VARB + "special_counter", "set_persistent_special_counter",
         "query_special_counter" }),
      PER_PERM_VAR + "class" ,
      ({ PER_PERM_VAR + "value", "set_value", "query_real_value" }),
      ({ "encumbrance", "set_encumbrance", "query_weapon_encumbrance" }),
  }));
  add_to_property(P_STATE_DESCRIPTION, ({ 0, "wielded_description" }));
  if (!this_object()->query_auto_load())
    add_to_property(P_STATE_DESCRIPTION, ({ 0, "broken_description" }));
  set_property(P_WEAPON);
  set_id("weapon");
  set_short("a non-descript weapon");
  set_long(lambda(0,({ (#'+),
                       ({ (#'capitalize),
                          ({ (#'short) }) }),
                       ".\n" })));
  add_action_error_message("wield",   "Wield what?\n");
  add_action_error_message("unwield", "Unwield what?\n");
}

void init() {
  item::init();
  add_action("read", "read");

  add_action_rule("wield "G_OBJECT, "wield");
  add_action_rule("unwield "G_OBJECT, "unwield");
  add_action_rule("remove "G_OBJECT, "unwield");
}

int do_action(string action, mapping args) {
  mixed result;

  switch(action) {
  case "wield":
    if (args[G_OBJECT] == this_object())
      return wield();
    return 0;
  case "unwield":
    if (args[G_OBJECT] == this_object())
      return unwield();
    return 0;
  }
  return 0;
}

varargs status drop(status silently) {
  if (item::drop(silently))
    return 1;
  call_out("drop_in_progress", 0);
  return 0;
}

void notify_move(object from, mixed to) {
  if (from && query_wielded())
    unwield(1);
}

void notify_destruct() {
  if (query_wielded())
    unwield(1);
}

status read(string str) {
  if (!read_msg || !str || present(str, this_player()) != this_object())
    return 0;
  message(read_msg);
  return 1;
}

varargs status wield(status silently) {
  object old;

  if (!present(this_object(), this_player())) {
    if (!silently)
      notify_fail("First get it!\n");
    return 0;
  }
  if (query_wielded()) {
    if (!silently)
      notify_fail("You already wield it!\n");
    return 0;
  }
  if (query_broken()) {
    if (!silently)
      notify_fail("You can't wield a broken weapon!\n");
    return 0;
  }
  if (wield_func || wield_func_name) {
    if (!call_other(wield_func || this_object(),
                    wield_func_name || "wield",
                    this_object()))
      return 1;
  }
  if (old = this_player()->query_wield())
    old->unwield(1);
  wielded_by = this_player();
  this_player()->wield(this_object());
  if (environment(this_player()) && !silently)
    if (!old)
      send_message(({ M_PL_THE, M_PL_VERB, "wield", M_PL_POSSESSIVE,
                      M_NONE, M_ME, "." }));
    else
      send_message(({ M_PL_THE, M_PL_VERB, "put", " down ", M_PL_POSSESSIVE,
                      M_NONE, old, " and ", M_PL_VERB, "wield",
                      M_SIMPLE_DESCRIBE, M_ME, "." }));
  return 1;
}

varargs status unwield(status silently) {
  mixed h, tmp;

  if (!query_wielded_by()) {
    if (!silently &&
        this_player() &&
        present(this_object(), this_player()))
      notify_fail("You don't wield it!\n");
    return 0;
  }
  if (!query_wielded())
    return 0;
  if (h = query_wielded_by()) {
    wielded_by = 0;
    h->stop_wielding();
    if (!silently)
      send_message(({ M_THE, h, M_VERB, "remove", h, " ", M_POSSESSIVE, h,
                      M_NONE, M_ME, "." }));
  }
  return 1;
}

void set_name(mixed n) {
  string s;

  if (stringp(n))
    add_id(n);
  item::set_name(n);
}

void set_alias(string a) {
  add_id(a);
  if (!random(100))
    if (this_player())
      log_file("log.set_alias.weapon",
               load_name(this_object()) +
               "#" + this_player()->query_vis_name() + "#" +
               to_string(environment(this_player())) + "\n");
    else
      log_file("log.set_alias.weapon",
               load_name(this_object()) + "\n");
}

void set_not_buyable(status i) {
  if (i)
    set_property(P_NOT_BUYABLE);
  else
    remove_property(P_NOT_BUYABLE);
}

void set_persistent_special_counter(int c) {
  special_counter = c;
}

// for weapons with low WC and high extra hit to be independent from the WC
void set_special_counter(int c) {
  if (c < 1)
    return;
  special_counter = c;
  initialize_counter();
}

varargs void break_weapon(status silently) {
  int value;
  object trash;

  if (query_broken())
    return;
  if (query_wielded()) {
    if (!silently)
      send_message(({ M_WRITE, "You recognize that your wielded ", M_NONE,
                      M_ME, " broke!" }));
    unwield(silently);
  }
  if (class_of_weapon > 3) {
    if (value = item::query_value())
      set_value((class_of_weapon - 1) * value/class_of_weapon);
    class_of_weapon--;
  }
  else {
    trash = clone_object("complex/item");
    trash->set_name(query_name());
    trash->set_short(query_short() + " (useless)");
    trash->set_long("This weapon is completely broken, you cannot repair it "
                    "anymore.\n" + query_long());
    trash->set_id(query_id());
    trash->set_value(0);
    trash->set_encumbrance(query_encumbrance());
    trash->set_read(query_read());
    trash->set_info(query_info());
    move_object(trash, environment());
    destruct(this_object());
    return;
  }
  if (special_counter)
    special_counter = ((90 * special_counter) / 10 + 1) / 10;
  initialize_counter();
  set_broken(1);
}

// decay() called by the living who wield this object
void decay(int dam) {
  if (broken)
    return;
  if (dam < 1)
    counter--;
  else
    counter -= dam;
  if (counter <= 0)
    break_weapon(0);
}

varargs void set_wield_func(mixed ob, string funcname) {
  if (objectp(ob)) {
    if (ob == this_object())
      wield_func = 0;
    else {
      if (!clonep(ob))
        wield_func = load_name(ob);
      else
        wield_func = ob;
    }
  }
  else
    wield_func = ob;
  if (funcname)
    wield_func_name = funcname;
}

void set_wield_func_name(string funcname) {
  wield_func_name = funcname;
}

varargs void set_hit_func(mixed ob, string funcname) {
  if (objectp(ob)) {
    if (ob == this_object())
      hit_func = 0;
    else {
      if (!clonep(ob))
        hit_func = load_name(ob);
      else
        hit_func = ob;
    }
  }
  else
    hit_func = ob;
  if (funcname)
    hit_func_name = funcname;
}

void set_hit_func_name(string funcname) {
  hit_func_name = funcname;
}

mixed hit(mixed attacker) {
  return call_other(hit_func || this_object(),
                    hit_func_name || "weapon_hit",
                    attacker,
                    (hit_func_with_weapon ? this_object() : 0)
                   );
}

int query_value() {
  return query_broken() ? 0 : query_real_value();
}

int query_weapon_encumbrance() {
  return item::query_encumbrance();
}

int query_encumbrance() {
  if (query_wielded())
    return (2 * item::query_encumbrance() / 3);
  return item::query_encumbrance();
}

status query_is_weapon() {
  return 1;
}

