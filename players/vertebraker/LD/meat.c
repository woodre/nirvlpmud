string meatname;

set_meatname(string str) { meatname = str; }
query_meatname() { return meatname; }

save_me() { save_object("players/vertebraker/LD/"+meatname); }

restore_me() { restore_object("players/vertebraker/LD/"+meatname); }
