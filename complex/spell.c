/*
 * Generic spell *
 *
 * revised by Coogan, 14-Dec-98
 *
 */

#pragma strong_types

#include <event.h>
#include <message.h>
#include <combat.h>
#include <action.h>
#include <server.h>

inherit "basic/create";

private mapping spell;
private string author, info;
private int lore_level=50;  // the lore skill level [1..100] needed for learning
private int art_level =50;  // the art skill level [1..100] needed for learning

// functions for overloading
status init_spell (mapping spell) { return 1; }
void start_spell  (mapping spell) { }
void execute_spell(mapping spell) { }
void finish_spell (mapping spell) { }


void create() { 
  spell = m_allocate(10,2);
  spell[A_NEEDED_USED] = (["mind" : 1]);
}

static void set_spell(string str) {
  spell[E_SPELL] = str;
}

static void set_art(varargs mixed* args) {
  int difficulty;
  string art;
  if (!args || !sizeof(args))
    return raise_error("Wrong number of arguments to set_art()\n");
  difficulty = 50;
  if (sizeof(args) > 1)
    difficulty = args[1];
  art = args[0];
  if (member(SE_MAGIC->query_arts(), art) == -1)
    return;
  spell[E_ART,0] = art;
  if (difficulty < 0)
    difficulty = 0;
  if (difficulty > 100)
    difficulty = 100;
  spell[E_ART,1] = difficulty;
}

static void set_lore(varargs mixed* args) {
  string lore;
  int difficulty;
  if (!args || !sizeof(args))
    return raise_error("Wrong number of arguments to set_lore()\n");
  difficulty = 50;
  if (sizeof(args) > 1)
    difficulty = args[1];
  lore = args[0];
  if (member(SE_MAGIC->query_lores(), lore) == -1)
    return;
  spell[E_LORE,0] = lore;
  if (difficulty < 0)
    difficulty = 0;
  if (difficulty > 100)
    difficulty = 100;
  spell[E_LORE,1] = difficulty;
}

static void set_requisite(string str) {
  spell[E_REQUISITE] = str;
}

static void set_cost(int x) {
  spell[E_COST] = x;
}

static void set_delay(int x) {
  spell[E_DELAY] = x;
}

static void set_extra_delay(int x) {
  spell[E_EXTRA_DELAY] = x;
}

static void set_author(string str) {
  author = str;
}

static void set_info(string str) {
  info = str;
}

static void set_requirements(mixed req) {
  spell[A_NEEDED_USED] = (["mind" : 1]) + 
                         (mappingp(req) ? req : count_elements(req));
}

static void set_lore_learn_level(int l) {
  if (l < 0)
    l > 0;
  if (l > 100)
    l = 100;
  lore_level = l;
}

static void set_art_learn_level(int l) {
  if (l < 0)
    l > 0;
  if (l > 100)
    l = 100;
  art_level = l;
}

string query_spell() {
  return spell[E_SPELL];
}

string query_art() {
  return spell[E_ART,0];
}

int query_art_difficulty() {
  return spell[E_ART,1];
}

string query_lore() {
  return spell[E_LORE,0];
}

int query_lore_difficulty() {
  return spell[E_LORE,1];
}

string query_requisite() {
  return spell[E_REQUISITE];
}

mixed query_extra_delay() {
  return spell[E_EXTRA_DELAY];
}

int query_cost() {
  return spell[E_COST];
}

int query_delay() {
  return spell[E_DELAY];
}

string query_author() {
  return author;
}

string query_info() {
  return info;
}

mapping query_requirements() { 
  return spell[A_NEEDED_USED] || ([ "mind" : 1 ]);
}

int query_lore_learn_level() {
  return lore_level;
}

int query_art_learn_level() {
  return art_level;
}

nomask mapping query_event(object caster) { 
  mapping out;

//  out = copy(spell);
//  if (caster)
//    out[E_SKILL] = caster->query_magic();
  return copy(spell);
}

