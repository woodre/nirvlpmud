/*
 * generic jar object, Coogan, Feb-02
 * 
 */

#pragma strong_types

#include <prop/item.h>
#include <grammar.h>
#include <message.h>
#include <event.h>
#include <describe.h>
#include <persistence.h>

// liquid fakeitems of the environment, which can be filled into this container
#define FILL_IN_DEFAULTS  (({ "water" }))

//inherit "basic/handle";
inherit "complex/container";

private int bottleneck_width = 2;  // measured in centimeters


int query_open() {
  return 1;
}

int query_bottleneck_width() {
  return bottleneck_width;
}

varargs string query_taste(string id) {
  object o;
  if (id && (o = present(id, this_object())))
    return o->query_taste();
  return container::query_taste(id);
}

#if 0  // Coogan, 22-Apr-02
varargs string query_taste_string(string id) {
  object o;
  if (id && (o = present(id, this_object())))
    return o->query_taste_string(id);
  return container::query_taste_string(id);
}
#endif

string query_name() {
  return (sizeof(all_inventory(this_object())) ? "" : "empty ")+
          (container::query_name() || "jar");
}

string query_short() {
  mixed *i;
  i = filter_objects(all_inventory(this_object()), "query_property", P_LIQUID);
  return describe(query_name()) +
         (sizeof(i) ? " with "+make_list(describe_list(i, ARTICLE_NONE)) : "" );
}

varargs string query_long(string str) {
  int s;
  object *i;

  if ((s = sizeof((i = all_inventory(this_object())))))
    if (s == 1)
      return
        message2string(({ "This ", M_ME_NONE, M_ME_VERB, "seem", " to "
                          "contain ", M_NONE, i, ".\n" }));
    else
      return
        message2string(({ "This ", M_ME_NONE, M_ME_VERB, "seem", " to "
                          "contain ", M_SIMPLE_DESCRIBE, M_NONE, i, ".\n" }));
  else
    return message2string(({ "This is an ordinary ", M_ME_NONE, ".\n" }));
}

string *query_id() {
  mixed *i;
  // the container matches to its name and to contained liquids,
  // but NOT to non-liquid items which are also part of the inventory
  i = filter_objects(all_inventory(this_object()), "query_property", P_LIQUID);
  i = map(i, lambda(({ 'x }),
                    ({ #'call_other, 'x, "query_id" })));
  i = flatten_array(i);
  i = (i+container::query_id() + ({ query_real_name() || "jar" })) - ({ 0 });
  if (!first_inventory(this_object()))
    i += ({ "empty " + (query_real_name() || "jar") });
  return m_indices(mkmapping(i));
}

status id(string s) {
  return (member(query_id(), s) > -1);
}

string short() {
  return query_short();
}

varargs string long(string str) {
  return query_long(str);
}

void start_contents_drying_away() {
  int i;
  object *inv;
  if (i = sizeof(inv = all_inventory())) {
    while (i) {
      if (inv[i-1]->query_property(P_LIQUID))
        inv[i-1]->start_drying_away();
      i--;
    }
  }
}

void set_persistence_open_state(status o) {
  if (o)
    call_out("start_contents_drying_away", 2);
}

void set_bottleneck_width(int b) {
  bottleneck_width = b;
}

void create() {
  container::create();
}

void refresh() {
  container::refresh();
}

void configure() {
  container::configure();
  set_persistence(__FILE__, PER_KEEP_VARS, ({
    ({ "id",    "set_id",    "query_real_id" }),
    ({ "name",  "set_name",  "query_real_name" }),
    ({ "short", "set_short", "query_real_short" }),
    ({ "long",  "set_long",  "query_real_long" }),
    "bottleneck_width",
    }));
  set_short("a jar");
  set_long("A jar.\n");
  set_id("jar");
  set_property(P_LIQUID_CONTAINER);
  add_to_property(P_STATE_DESCRIPTION, ({ 0, "query_open_state_description" }));
  set_encumbrance(500);
  set_max_encumbrance(2000);
  set_bottleneck_width(3);

  add_action_error_message("empty", "Empty what?\n");
  add_action_error_message("pour",  "Pour what?\n");
  add_action_error_message("fill",  "Fill what into/with what?\n");
}

void init() {
  add_action_rule("empty "G_OBJECT" into "G_INDIRECT, "empty_into");
  add_action_rule("pour "G_OBJECT" into "G_INDIRECT,  "pour_into");

#if 0  // we need a kind of /basic/wetable for that
  add_action_rule("empty "G_OBJECT" over "G_INDIRECT, "empty_over");
  add_action_rule("pour "G_OBJECT" over "G_INDIRECT,  "pour_over");
#endif

  add_action_rule("empty "G_OBJECT, "empty");
  add_action_rule("pour "G_OBJECT,  "pour");

  add_action_rule("fill "G_INDIRECT" into "G_OBJECT,  "fill");
  add_action_rule("fill "G_INDIRECT" in "G_OBJECT,    "fill");
  add_action_rule("fill "G_OBJECT" with "G_INDIRECT,  "fill");
}

static int query_approximated_size(object x) {
  if (x->id("pea") || x->id("bean") || x->id("currant"))
    return 1;
  if (x->id("berry"))
    return 2;
  if (x->id("nut"))
    return 3;
  if (x->id("plum"))
    return 4;
  if (x->id("apricot"))
    return 5;
  if (x->id("apple") || x->id("pear") || x->id("ball"))
    return 10;
  if (x->id("fruit"))
    return 8;
  return 20;
}

private status test_pourable(object o) {
  if (o->query_property(P_LIQUID))
    return 1;
  if (query_bottleneck_width() &&
      (o->query_size()||query_approximated_size(o)) > query_bottleneck_width())
    return 0;
  return 1;
}
  
status do_action(string verb,mapping args) {
  mixed h, i, new;

  switch (verb) {

  case "empty":
  case "pour":
    if (args[G_OBJECT] != this_object())
      return 0;
    if (!sizeof(h = all_inventory()))
      return
        notify_fail(({({ M_WRITE, "But ", M_THE, this_object(), M_VERB,
                         "are", this_object(), " already empty." })})), 0;
    h = filter(h, #'test_pourable);
    if (!sizeof(h))
      return
        notify_fail(({({ M_THE, this_player(), M_VERB, "try", this_player(),
                         " to ", verb, M_POSSESSIVE, this_player(), M_THE,
                         this_object(), " but nothing falls out." })})), 0;
    send_message(({ M_PL_THE, M_PL_VERB, verb, M_ME_THE, "." }));
    for (i = sizeof(h); i--;) {
      if (h[i]->query_property(P_LIQUID))
        send_message(({ h[i]->query_real_short(), " ",
                        M_VERB, "drip", h[i], " out of ", M_ME_THE, "." }));
      else
        send_message(({ M_SIMPLE_DESCRIBE, h[i], M_VERB, "fall", h[i],
                        " out of ", M_ME_THE, "." }));
      move_object(h[i], environment(this_player()));
    }
    if (first_inventory())
      send_message(({ M_WRITE, "To get the last contents of ", M_ME_THE,
                      " you have to break ", M_ME_PRONOUN, "." }));
    return 1;

  case "empty_into":
  case "pour_into":
    if (args[G_OBJECT] != this_object())
      return 0;
    if (!sizeof(h=all_inventory()))
      return
        notify_fail(({({ M_WRITE, "But ", M_THE, this_object(), M_VERB, "are",
                         this_object(), " already empty." })})), 0;
    if (!args[G_INDIRECT]->can_put_and_get(args[G_INDIRECT,1], this_object()))
      return
        notify_fail(({({ M_WRITE, "You can't ", verb[0..<6], " ", M_THE,
                         this_object(), " into ", M_THE, args[G_INDIRECT,1],
                         "." })})), 0;
    if (args[G_INDIRECT] == this_object())
      return
        notify_fail(({({ M_WRITE, M_SUBJECT, this_object(), "You can't ",
                         verb[0..<6], " ", M_THE, this_object(), " into ",
                         M_OBJECTIVE, this_object(), "." })})), 0;
    h = filter(h, #'test_pourable);
    if (!sizeof(h))
      return
        notify_fail(({({ M_THE, this_player(), M_VERB, "try", this_player(),
                         " to ", verb[0..<6], M_POSSESSIVE, this_player(),
                         M_NONE, this_object(), " into ", M_POSSESSIVE,
                         this_player(), M_NONE, M_OBJECT, args[G_INDIRECT],
                         ", but ", M_VERB, "fail", this_player(), "." })})), 0;
    send_message(({ M_PL_THE, M_PL_VERB, verb[0..<6], M_PL_POSSESSIVE,
                    M_ME_NONE, " into ", M_THE, args[G_INDIRECT, 1], "." }));
    for (i = sizeof(h); i--;) {
      if (h[i]->query_property(P_LIQUID))
        send_message(({ h[i], M_VERB, "drip", h[i], " out of ", M_ME_THE,
                        " and into ", M_THE, args[G_INDIRECT,1], "." }));
      else
        send_message(({ h[i], M_VERB, "fall", h[i], " out of ", M_ME_THE,
                       " and into ", M_THE, args[G_INDIRECT,1], "." }));
      move_object(h[i], args[G_INDIRECT]);
    }
    return 1;

  case "fill":
    if (args[G_OBJECT] != this_object())
      return 0;
    if (query_container_encumbrance() == query_container_max_encumbrance())
      return notify_fail(({({ M_WRITE, "But ", M_THE, this_object(), M_VERB,
                              "are", this_object(), " still full!" })})), 0;
    if (args[G_INDIRECT] != environment(this_player())) {
      if (!args[G_INDIRECT]->query_property(P_LIQUID))
        return notify_fail(({({ M_WRITE, "You can only fill liquids into ",
                                M_THE, M_OBJECT, this_object(), "." })})), 0;
    }
    else {
      if (member(FILL_IN_DEFAULTS, args[G_INDIRECT,1]) == -1)
        return
          notify_fail("There is no liquid "+args[G_INDIRECT,1]+" here!\n"), 0;
      // create a dummy liquid to fill it in
      new = clone_object("complex/liquid");
      new->set_name(args[G_INDIRECT, 1]);
      new->set_invitro(1);
      new->set_short("some " + args[G_INDIRECT, 1]);
      new->set_long("Some " + args[G_INDIRECT, 1] + ".\n");
      new->set_id(({ "liquid", new->query_name(), new->query_short() }));
      new->set_encumbrance(query_container_max_encumbrance() -
                             query_container_encumbrance());
      i = 1;
    }
    if (!new)
      h = args[G_INDIRECT];
    if (h && h->query_encumbrance() >
          query_container_max_encumbrance() - query_container_encumbrance())
      {   // we have to split h
      mixed j;
      object p, p_new;
      
      j = h->query_invitro();
      h->set_invitro(1);  // for name, short and long desc
      h->renew_liquid(100);
      new=h->copy_liquid();
      h->set_invitro(j);
      // we re-scale both liquids to their encumbrances
      j = to_float(100 * (query_container_max_encumbrance() -
                                  query_container_encumbrance())) /
          to_float(new->query_encumbrance());
      new->renew_liquid(j);
      h->renew_liquid(100.0 - j);
      if (!new->short())  // Coogan, 26-Aug-2002
        new->set_short("some " + describe(h, ARTICLE_NONE));
      i = 1;
      }
    if (!new)
      new = h;
    move_object(new, this_object());
    send_message(({ M_PL_THE, M_PL_VERB, "fill", (i ? " some " : " all "),
                    "of the ", args[G_INDIRECT,1], " into ", M_ME_THE, "." }));
    return 1;
  }
  // default:
  return 0;
}

status hide_inventory(string dummy) {
  return 1;
}

status can_put_and_get(string container_id, object to_insert) {
  if (!to_insert)
    return id(container_id);
  if (to_insert->query_property(P_LIQUID))
    return (!environment(to_insert));
  if (to_insert->query_property(P_NOT_PORTABLE))
    return 0;
  if (!to_insert->query_property(P_EATABLE))  // only food
    return 0;
  if ((to_insert->query_size() || query_approximated_size(to_insert)) >
                                                   query_bottleneck_width())
    return 0;
  return 1;
}

int apply_action(string action, int level, mixed args) {
  return
    container::apply_action(action, level, args);
}

