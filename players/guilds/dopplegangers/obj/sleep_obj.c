inherit "obj/treasure.c";

void reset(int arg) {
  ::reset(arg);

}

int id(string str) {
  return ::id(str) || str == "dopple_sleep_obj" ||
         str == "hp_regen_object" || str == "sp_regen_object";
}

int query_hp_regen() {
  return 6;
}

int wake(int wakeup) {
  if (wakeup
int sleep(int sleep_time, int curr_time) {
  if (!sleep_time || !curr_time) {
    destruct(this_object());
    return 0;
  }
  wake_time = curr_time + sleep_time;
  wake(wake_time);
  say(environment(this_player()->query_name()) +
      " falls into a deep sleep.\n");
  return 1;
}
