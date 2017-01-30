
int shield, is_locked, is_closed, dest_key, can_lock;
object key, partner_ob;
string key_name, long_desc, short_desc, dest_dir, dest_room;
string id_name, alias_name;

id(str) { return (str==id_name || str==alias_name); }

set_name(str) { id_name=str; }
set_alias(str) { alias_name=str; }

reset(arg) {
     if(!shield)
          shield=1;
     if (can_lock)
          is_locked=1;
     is_closed=1;
     if (arg)
          set_both_doors();
}

init() {
     add_action("open", "open");
     add_action("close", "close");
     add_action("unlock", "unlock");
     add_action("lock", "lock");
     add_action("move_player", dest_dir);
     set_both_doors();
}

set_key_name(str) { key_name=str; }
query_key_name() { return key_name; }

set_long(str) { long_desc=str; }
long() {
     write(long_desc);
     return 1;
}

set_short(str) { short_desc=str; }
short() { return short_desc; }

set_dest_dir(str) { dest_dir=str; }
query_dest_dir() { return dest_dir; }

set_dest_room(str) {
     dest_room=str;
}
query_dest_room() { return partner_ob; }

set_partner_ob(ob) { partner_ob=ob; }
query_partner_ob() { return partner_ob; }

set_dest_key(arg) { dest_key=arg; }
query_dest_key() { return dest_key; }

set_can_lock(arg) { can_lock=arg; }
query_can_lock() { return can_lock; }

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
     if(!can_lock)
          return 0;
     if(!present(key_name, this_player())) {
          write("You don't have the key.\n");
          return 1; }
     is_locked=0;
     write("Klick!\n");
     if(this_player()->query_level()<40 && dest_key) {
          write("Odd....the key seems to have disappeared.\n");
          destruct(present(key_name, this_player())); }
     set_both_doors();
     return 1;
}

lock(str) {
     if(!str||str!="door")
          return 0;
     if(!can_lock)
          return 0;
     if(!present(key_name, this_player())) {
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

move_player() {
     if(is_closed) {
          write("The door is closed.\n");
          return 1; }
     if(shield) {
          write("An unseen voice asks, 'Key Code?': ");
          input_to("shield"); 
          return 1; }
     write("You pass through the field...\n");
     this_player()->move_player(dest_dir + "#" + dest_room);
     return 1;
}

set_shield(i) { shield=i; }
set_is_closed(c) { is_closed=c; }
set_is_locked(l) { is_locked=l; }

shield(i) {
     object castle;
     int test, sort, x;
     castle=find_object("players/bastion/castle");
     test=castle->query_code();
     sort=sscanf(i, "%d", x);
     if(!intp(x)) {
          write("Enter numeric values only.\n");
          return 1; }
     if(x!=test) {
          write("Sorry, that is incorrect.\n");
          return 1; }
     shield=0;
     set_both_doors();
     return 1;
}

query_shield() { return shield; }

set_both_doors() {
   if(!partner_ob) return 1;
     partner_ob->set_shield(shield);
     partner_ob->set_is_closed(is_closed);
     partner_ob->set_is_locked(is_locked);
     return 1;
}

