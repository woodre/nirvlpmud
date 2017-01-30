/*
 * basic/healing - basic functions handling the different healing rates
 * written by Coogan, Januar 2001
 *
 */

#pragma strong_types

private int body_healing_rate, mind_healing_rate;

static string* query_persistent_variables() {  // Coogan, 16-May-2001
  return ({ "body_healing_rate", "mind_healing_rate" });
}

int query_body_healing_rate() {
  return body_healing_rate;
}

int query_mind_healing_rate() {
  return mind_healing_rate;
}

void set_healing_rate(int h) {  // for compatibility and easier handling
  body_healing_rate = mind_healing_rate = h;
}

void set_body_healing_rate(int b) {
  body_healing_rate = b;
}

void set_mind_healing_rate(int m) {
  mind_healing_rate = m;
}

