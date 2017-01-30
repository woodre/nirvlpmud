#define me this_player()
inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Bursar's Office";
  long_desc = 
   "This is the bursar's office. Make sure to pay your bills.\n";
  dest_dir = ({"/players/bastion/guild/room/admin2", "southwest"});
  }
}

init(arg) {
  add_action("pay", "pay");
  ::init(arg);
}

pay() {
  object ob, soul;
  if(!present("registration form", this_player())) {
    notify_fail(format("The bursar says: I need to see your registration " +
     "form please.\n"));
    return 0;
  }
  if(this_player()->query_money() < 1500) {
    notify_fail(format("The bursar says: It will cost you 1500 gold to " +
     "enroll for one credit.\n"));
    return 0;
  }
  if(this_player()->query_sorcerer()) {
    int amt;
    soul=present("magesoul", this_player());
    if(sizeof(soul->query_spells_learned()) < 7) 
      amt=1000;
    else if(sizeof(soul->query_spells_learned()) < 14)
      amt=500;
    else amt=0;
    if(amt)
      write(format("The bursar says: Since you are a new student, you are " +
       "entitled to a grant of " + amt + " coins.\n"));
    this_player()->add_money((-1500) + amt);
  }
  else
    this_player()->add_money(-1500);
  write(format("You pay the bursar and she stamps your registration form " +
   "and hands you a receipt.\n"));
  ob=clone_object("obj/treasure");
  ob->set_id("bursar's receipt");
  ob->set_short("A bursar's receipt");
  ob->set_alias("receipt");
  move_object(ob, this_player());
  present("registration form", me)->set_read("You see a red box labelled \"" +
   "tuition paid\". It has the bursar's stamp in it.\n");
  return 1;
}
