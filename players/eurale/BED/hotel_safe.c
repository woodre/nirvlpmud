#define SAVEPATH "players/eurale/BED/save/"

string* registry;
string* schedule;

store(string* new_registry, string* new_schedule) {
  registry = new_registry;
  schedule = new_schedule;
  save_object(SAVEPATH + "office");
  }

int restore_safe() {
  int x;
  x = restore_object(SAVEPATH + "office");
  return x;
}

string* get_registry() { return registry; }
string* get_schedule() { return schedule; }

