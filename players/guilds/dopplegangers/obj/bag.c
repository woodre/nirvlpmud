int local_weight, MAX_WEIGTH;
string long_desc, short_desc;

int set_long(string str) { long_desc = str; }
void long() {
  if(!long_desc)
    write(short_desc);
  else
    write(long_desc);
}

void reset(status arg) {
  if (arg)
    return;
  local_weight = 0;
  MAX_WEIGTH = 6;
  short_desc = "A bag";
}

int query_weight() { return 1; }

int id(string str) { return str == "bag" || str == "magical bag"; }
int query_value() { return 5; }
int add_weight(int w) {
  if (local_weight + w > MAX_WEIGTH)
    return 0;
  local_weight += w;
  return 1;
}

int set_short(string str) { short_desc = str; }
string short() { return short_desc; }

int can_put_and_get() { return 1; }
int get() { return 1; }

int prevent_insert() {
  if (local_weight > 0) {
    write("You can't when there are things in the bag.\n");
    return 1;
  }
  return 0;
}

set_max_weigth(x) { MAX_WEIGTH = x; }
query_max_weigth() { return MAX_WEIGTH; }
