/*
 * attacker.c -- written by Ugh Oct-2001 for Tubmud
 *
 * this module provides access to the different attack-facilities
 */

#include <event.h>
#include <combat.h>

private static mixed *attacks;

mixed *get_attacks() {
  return (attacks || ({})) - ({0});
}

void add_attack(mixed def) {
  attacks = get_attacks()+({def});
}

void remove_attack(mixed def) {
  attacks = get_attacks()-({def});
}
