int is_locked, is_closed;
string key_desc, dest_dir, dest, long_desc, short_desc;
object key, partner;

get() { return 0; }
short() { return short_desc; }
long() {
     if(!long_desc)
          write("You see nothing special.\n");
     else
          write(long_desc);
     return 1;
}
id(str) { return str=="door"; }

set_partner(str) { partner=str; }
set_key_desc(str) { key_desc=str; }
set_dest(str) { dest=str; }
set_dest_dir(str) { dest_dir=str; }
set_is_closed(c) { is_closed=c; }
set_is_locked(l) { is_locked=l; }
set_short(str) { short_desc=str; }
set_long(str) { long_desc=str; }

init() {
     add_action("open", "open");
     add_action("close", "close");
     add_action("unlock", "unlock");
     add_action("lock", "lock");
     if(dest_dir) {
          add_action("enter", dest_dir);
     }
}

open(str) {
     if(!str||str!="door")
          return 0;
     if(is_locked) {
          write("The door is locked.\n");
          return 1; }
     is_closed=0;
     write("Ok.\n");
     set_both_doors();
     return 1;
}

close(str) {
     if(!str||str!="door")
          return 0;
     is_closed=1;
     write("Ok.\n");
     set_both_doors();
     return 1;
}

unlock(str) {
     if(!str||str!="door")
          return 0;
     if(!present(key_desc, this_player())) {
          write("You don't have the key.\n");
          return 1; }
     is_locked=0;
     write("Klick!\n");
     set_both_doors();
     return 1;
}

lock(str) {
     if(!str||str!="door")
          return 0;
     if(!present(key_desc, this_player())) {
          write("You don't have the key.\n");
          return 1; }
     if(!is_closed) {
          write("You must close the door.\n");
          return 1; }
     is_locked=1;
     write("Klick!\n");
     set_both_doors();
     return 1;
}

enter() {
     if(is_closed) {
          write("The door is closed.\n");
          return 1; }
     this_player()->move_player(dest_dir + "#" + dest);
     return 1;
}
set_both_doors() {
     object ob;
     ob=find_object(partner);
     partner->set_is_closed(is_closed);
     partner->set_is_locked(is_locked);
     return 1;
}
