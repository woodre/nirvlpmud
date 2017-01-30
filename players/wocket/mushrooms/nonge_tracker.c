int tracker;

void register_nonge() {
  tracker ++;
}

void deregister_nonge() {
  tracker --;
}

int query_nonges() {
  return tracker;
}
