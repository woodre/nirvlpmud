string short() { return 0; }

int id(string str) { return str == "rlogit"; }

void long() { }

void reset(int arg) {
  if (arg) return;
}

void init() {
#ifndef __LDMUD__
  add_action("logit"); add_xverb("");
#else
  add_action("logit", "", 3);
#endif
  if (!environment(this_object())) return;
  if (find_player("rumplemintz")) {
    tell_object(find_player("rumplemintz"),
                this_player()->query_real_name() +
                " just entered a logit room!\n" +
                "-> " + file_name(environment(this_object())) + "\n->\n");
    return;
  }
}

void logit(string str) {
  if (!environment(this_object())) return;
  if (find_player("rumplemintz")) {
    tell_object(find_player("rumplemintz"),
                this_player()->query_real_name() + " -> " + query_verb() +
                str + "\n");
  }
  log_file("RUMPLOG", "--- Logit room " +
                      (file_name(environment(this_object())) ?
                       file_name(environment(this_object())) :
                       "Unknown") +
                      "---" + ctime(time()) + "\n");
  log_file("RUMPLOG", ": " + this_player()->query_real_name() + " -> " +
                      query_verb() + str + "\n");
  return;
}

