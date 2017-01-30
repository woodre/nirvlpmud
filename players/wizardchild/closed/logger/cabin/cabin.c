/* scabin.c: daemonized cabins (growl) */
#define ROOT_DIR "/players/wizardchild/closed/logger/"
#define THERE(s) present("logger pack", s)
#define INVIT(s) present("cabin invite", s)
#define MASTER "/players/wizardchild/closed/logger/masterob.c"
static string owner, long, outside;
static string *in_cabin;
reset(arg) { 
  if(arg) return 0; set_light(1); 
  move_object(clone_object(ROOT_DIR+"cabin/sign.c"), this_object());
}
set_owner(str) {
  owner = lower_case(str);
  if(!THERE(find_player(owner))) destruct(this_object());
  long = THERE(find_player(owner))->query_cabin_long();
  outside = THERE(find_player(owner))->query_cabin_outside();
  if(!long) long = "A generic log cabin. You can drop up to 10 items here.";
  if(!outside) outside - "A generic log cabin.";
  return 1;
}
short() { return capitalize(owner)+"'s Log Cabin"; }
long() {
  if(environment(this_player()) == this_object()) {
    write(long+"\n");
    write("Type 'leave cabin' to exit.\n");
  } else {
    write(outside+"\n");
    if(this_player()->query_real_name() == owner)
      write("Type 'enter cabin' to enter it.\n");
  }
  return 1;
}
id(str) { return (str == "cabin" || str == "log cabin" && environment(this_player()) != this_object()); }
init() {
  if(!THERE(this_player()) && this_player()->query_level() < 30 && !INVIT(this_player())) {
    write("You should not be in here, little boy.\n");
    move_object(this_player(), "room/church");
  } else if(environment(this_player()) == this_object()) {
    add_action("leave", "leave");
    if(this_player()->query_real_name() == owner && THERE(this_player())) {
      in_cabin = THERE(this_player())->query_in_cabin();
      add_action("invite", "invite");
      add_action("list", "list");
      add_action("drop_item", "drop");
      add_action("get_item", "get");
    }
  } else if(this_player()->query_real_name() == owner && THERE(this_player()))
    add_action("enter", "enter");
}
enter(str)   { return (id(str) && MASTER->c_enter(this_object())); }
leave(str)   { return (id(str) && MASTER->c_leave(this_object())); }
invite(str)  { return MASTER->c_invite(str,this_object());         }
list(str)    { return MASTER->c_list(str,this_object());           }
get_item(s)  { return MASTER->c_get_item(s,this_object());         }
drop_item(s) { return MASTER->c_drop_item(s,this_object());        }
query_in_cabin() { return in_cabin; }
query_owner() { return owner; }
set_in_cabin(x) { in_cabin = x; }
