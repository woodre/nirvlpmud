/*
 * /basic/mass.c -- a basic class for things with an explicit mass like
 * weights.
 *
 * Use the simul_efun get_mass() to determine the mass of an unknown object
 * because this will first try to use this class and then encumbrance.
 */

private mixed mass;

int query_mass() {
  return funcall(mass);
}

void set_mass(mixed m) {
  mass = m;
}
