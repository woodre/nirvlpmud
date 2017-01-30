/*
 * basic/poisonable.
 * Written by Coogan for Tubmud, Feb-1998
 *
 */

private string poison_type;
private int poison_rate = 0;
private int poison_speed = 0;
private int poison_drain_rate = 0;
private int poison_drain_speed = 0;

string
query_poison_type() {
  return poison_type;
}

int
query_poison_rate() {
  return poison_rate;
}

int
query_poison_speed() {
  return poison_speed;
}

int
query_poison_drain_rate() {
  return poison_drain_rate;
}

int
query_poison_drain_speed() {
  return poison_drain_speed;
}

void
set_poison_type(string type) {
  poison_type = type;
}

void
set_poison_rate(int rate) {
  if (rate > 0)
    poison_rate = rate;
  else
    poison_rate = 0;
}

void
set_poison_speed(int speed) {
  if (speed > 0)
    poison_speed = speed;
  else
    poison_speed = 0;
}

void
set_poison_drain_rate(int rate) {
  if (rate > 0)
    poison_drain_rate = rate;
  else
    poison_drain_rate = 0;
}

void
set_poison_drain_speed(int speed) {
  if (speed > 0)
    poison_drain_speed = speed;
  else
    poison_drain_speed = 0;
}

