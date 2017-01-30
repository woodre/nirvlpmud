#pragma strong_types

#include <prop/item.h>
#include <grammar.h>
#include <message.h>

inherit "basic/heap";

private int max_hands_amount = 1;       // max. amount to fill in with hands
private int max_tool_amount = 5;        // max. amount to fill in with a tool
private string* tools;                  // possible ids of tools
private string platform;                // if the player is on a platform (id)
private int heap_element_encumbrance;   // the encumbrance of one heap element


int query_heap_element_encumbrance() {
  return heap_element_encumbrance;
}

void set_heap_element_encumbrance(int i) {
  heap_element_encumbrance = i;
}

string query_platform() {
  return platform;
}

void set_platform(string s) {
  platform = s;
}

string* query_tools() {
  return tools[0..];
}

void set_tools(string *t) {
  tools = t;
}
    
int query_encumbrance() {
  return query_amount() * heap_element_encumbrance;
}

void init() {
  add_action_rule("fill "G_WORDS" into "G_OBJECT,  "fill_heap");
  add_action_rule("fill "G_WORDS" in "G_OBJECT,    "fill_heap");
  add_action_rule("fill "G_OBJECT" with "G_WORDS,  "fill_heap");
  add_action_error_message("fill", "Fill what into what?\n");

  add_action_rule("put "G_WORDS" into "G_OBJECT,   "put_heap");
  add_action_rule("put "G_WORDS" in "G_OBJECT,     "put_heap");

  if (tools && member(tools, "broom") > -1) {
    add_action_rule("sweep "G_WORDS" into "G_OBJECT, "sweep_heap");
    add_action_rule("sweep "G_WORDS" in "G_OBJECT,   "sweep_heap");
  }
}

int do_action(string action, mapping args) {
  object floor, heap, tool;
  int poss_enc, diff, enc, amount;
  mixed tmp;

  if (!id(args[G_WORDS]))
    return 0;
  if (!args[G_OBJECT]->can_put_and_get(args[G_OBJECT,1], this_object()))
    return 0;

  floor = (platform && present(platform, environment(this_player()))) ||
          environment(this_player());
  heap = present(args[G_WORDS], floor) ||
         present(args[G_WORDS], environment(floor));
  if (!heap &&
      LIB_LANGUAGE->could_be_plural(args[G_WORDS])) {
    string sing;
    sing = LIB_LANGUAGE->to_singular(args[G_WORDS])[0];
    heap = present(sing, floor) || present(sing, environment(floor));
  }
  if (!heap || heap != this_object())
    return notify_fail("What do you want to " + query_verb() +
                       " into the " + args[G_OBJECT,1] + "?\n");
  tool = 0;
  if (tools && sizeof(tools)) {
    foreach (tmp : tools) {
      if ((tool = present(tmp, this_player())))
        break;
    }
  }
  poss_enc = args[G_OBJECT]->query_container_max_encumbrance() -
             args[G_OBJECT]->query_container_encumbrance();
  amount = query_amount();
  if (query_encumbrance() > poss_enc) {
    set_tmp_amount(1);
    enc = query_encumbrance();
    amount = poss_enc / enc;
    if (amount < 1) {
      send_message(({ M_WRITE, M_THE, M_ARG, G_OBJECT,
                      " is already full!" }), args);
      return 1;
    }
  }
  if (!tool) {
    amount = max_hands_amount;
    if (amount != query_amount(1))
      send_message(({ "using ", M_PL_POSSESSIVE, " bare hands, ", M_PL_THE,
                      M_PL_VERB, "fill", " some of ", M_ME_THE,
                      " into ", M_THE, M_ARG, G_OBJECT, "." }), args);
    else
      send_message(({ "using ", M_PL_POSSESSIVE, " bare hands, ", M_PL_THE,
                      M_PL_VERB, "fill", M_ME_THE,
                      " into ", M_THE, M_ARG, G_OBJECT, "." }), args);
  }
  else {
    if (max_tool_amount && amount > max_tool_amount)
      amount = max_tool_amount;
    if (amount != query_amount(1))
      send_message(({ M_PL_THE, M_PL_VERB, "use", M_THE, tool, " to fill "
                      "some of ", M_ME_THE,
                      " into ", M_THE, M_ARG, G_OBJECT, "." }), args);
    else
      send_message(({ M_PL_THE, M_PL_VERB, "use", M_THE, tool, " to fill ",
                      M_ME_THE,
                      " into ", M_THE, M_ARG, G_OBJECT, "." }), args);
  }
  set_tmp_amount(amount);
  move_object(this_object(), args[G_OBJECT]);
  return 1;
}

