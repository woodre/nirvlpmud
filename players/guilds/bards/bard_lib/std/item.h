status get();
status drop(int silently);
status id(string s);
string short();
void long(string id);
string query_name();
int query_weight();
int query_value();

void set_name(string nom);
void set_ids(mixed i);
void set_weight(int x);
void set_value(int x);
void set_short(string s);
void set_long(string s);

status save_thing(string path);
status restore_thing(string path);
mixed locker_arg(int mix);
void locker_init(mixed a);

mixed query_property(string p);
void add_property(string p, mixed v);
void set_property(string p, mixed v);
void set_properties(mapping m);
