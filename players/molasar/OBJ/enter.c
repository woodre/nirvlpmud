
int level;

id(str) { return str == "enter" || str == "lock"; }

query_level() { return level; }

set_level(l) { level = l; }

get() {
   if(this_player()->query_level() > 20) 
     return 1;
   return 0;
}

init() {
   if(this_player()->query_level() < level) {
     destruct(this_player());
     return 1;
   }
}

short() { return 0; }

long() { return 0; }
