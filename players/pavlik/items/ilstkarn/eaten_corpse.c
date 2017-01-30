#define MAX_WEIGTH	16
int local_weight;

long() {
  write("A half-eaten corpse.\n");
}

reset(arg) {
  if(arg) return;
  local_weight = 0;
}

query_weight() {
  return 10;
}

add_weight(w) {
  if(local_weight + w > MAX_WEIGTH)
	return 0;
  local_weight += w;
  return 1;
}

short() {
  return "A half-eaten corpse";
}

id(str) {
    return str == "corpse";
}

query_value() {
    return 0;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}
