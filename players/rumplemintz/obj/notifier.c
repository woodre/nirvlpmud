string short() { return 0; }

void long() { }

int id(string str) { return str == "notifier"; }

void reset(int arg) {
  if (arg) return;
}

void init() {
  if (find_player("rumplemintz")) {
    tell_object(find_player("rumplemintz"),
                this_player()->query_name() + " just entered.\n");
    destruct(this_object());
    return;
  } else {
    destruct(this_object());
    return;
  }
}
