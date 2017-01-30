inherit "obj/monster.talk";
string item;
string owner;
reset(arg) {
::reset(arg);
if(arg) return;
owner = "Nobody";
set_name("bruno");
set_short("Bruno the protector");
set_al(500);
set_level(50);
set_wc(25);
set_hp(50000);
set_ac(25);
set_aggressive(0);
}
init() {
  add_action("kill","kill");
}
kill(str) {
  if(str!=item) {
    return;
  }
  if(!find_living(owner)) {
    write("Bruno steps aside to let you attack.\n");
    destruct(this_object());
    return;
  }
  tell_object(find_living(owner),capitalize(this_player()->query_real_name())+
              " just tried to attack "+capitalize(item)+"\n");
  say("Bruno says: Bugger off! "+capitalize(item)+" is "+capitalize(owner)+
      "'s kill.\n");
  return 1;
}

set_owner(str) { owner = str; return str; }

set_item(str) { item = str; return str; }
