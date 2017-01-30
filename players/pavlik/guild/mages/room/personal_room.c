#include "/players/pavlik/guild/mages/macs"
#define OWN capitalize(owner)
#define PROOM "players/pavlik/guild/mages/rooms/PROOMS/"

string owner;
string descrip;
string exit;
string preserve;

reset(arg){
  if(arg) return;
  owner = "noone";
  descrip = "A room in the Mage's Tower ('info')";
  exit = "out";
  preserve = 0;
}

short(){ return OWN+"'s Room in the Mage's Tower"; }

long(){
  write(descrip);
  write("There is one obvious exit: "+exit+".\n");
  return;
}

id(str){ return str == "mage room" || str == owner+"'s mage_room"; }
get(){ return 0; }
drop(){ return 1; }
set_owner(str){ owner = str; }

init(){
  add_action("set_descrip","descrip");
  add_action("go_away","out");
  add_action("set_exit","exit");
  add_action("go_away", exit);
  add_action("room_help","info");
  add_action("invite","invite");
  add_action("cmd_list","list");
  add_action("cmd_retrieve","retrieve");
  add_action("cmd_store","store");
  add_action("cmd_clear","clear");
  if(this_player()->query_guild_rank() > 50){
    add_action("preserve_object","preserve");
    add_action("thaw_object","thaw");
    add_action("whats_here","pres?");
  }
}

/* do not dest this object */
clean_up() {
  return 0;
}

renew(){
  if(owner == "noone") return 1;
  restore_object(PROOM+owner);
  return 1;
}

do_save(){
  if(owner == "noone") return 1;
  save_object(PROOM+owner);
  return 1;
}

room_help(){
  if(rlname != owner) return 1;
  write(
  "This is your very own room within the Mage's Tower.\n"+
  "You can decorate this room however you please.\n"+
  "- Commands are:\n"+
  "  descrip             - set the room description\n"+
  "  exit <str>          - set your exit command\n"+
  "                        note: 'out' is also valid exit cmd\n");
  write(
  "  invite <plyr>       - invite someone into your room.\n"+
  "                        note: player must be in lobby OR main room\n"+
  "");
  write(
  "  store <item>        - store an item in the room, a maximum of 3\n"+
  "  retrieve <item>     - retrieve an item from the room\n"+
  "  list                - list all items stored in the room\n"+
  "  clear <num>         - clear a bugged item from the room.\n");
  return 1;
}

go_away(){
  write("You leave the room.\n");
  say(ME+" leaves the room.\n");
  if(guild) move_object(tp, "players/pavlik/guild/mages/room/mage_lobby");
  else move_object(tp, "players/pavlik/guild/mages/room/main");
  command("look", tp);
  return 1;
}

set_descrip(){
  if(rlname != owner) return 1;
  descrip = "";
  write("Changing the room description ...\n");
  write("Enter '**' on a line by itself to end.\n");
  input_to("addto_descrip");
  return 1;
}

addto_descrip(str){
  write(">");
  if(str == "**"){
    write("You redecorate the room ... Nice touch!\n");
    save_object(PROOM+owner);
    return 1;
  } else {
    descrip = descrip+str+"\n";
    input_to("addto_descrip");
  return 1;
  }
}

set_exit(str){
  if(rlname != owner) return 1;
  if(!str || str == "exit"){
    write("You don't want to do that.\n");
    return 1;
    }
  add_action("go_away", str);
  write("Your exit is now set to: "+str+"\n");
  exit = str;
  save_object(PROOM+owner);
  return 1;
}

invite(str){
  object obj;
  if(rlname != owner){
    write("This isn't your room.  You can't invite people here!\n");
    return 1;
    }
  move_object(tp, "players/pavlik/guild/mages/room/mage_lobby");
  obj = present(str, env);
  if(!obj){
  move_object(tp, "players/pavlik/guild/mages/room/main");
  obj = present(str, env); }
  if(!obj){
    write(capitalize(str)+" could not be found.\n");
    move_object(tp, this_object());
    return 1;
    }
  move_object(tp, this_object());
  write("You invite "+capitalize(str)+" into your room.\n");
  say(ME+" invites "+capitalize(str)+" into the room.\n");
  tell_room(env, capitalize(str)+" enters.\n");
  move_object(obj, this_object());
  tell_object(obj, ME+" invites you in.\n");
  command("look", obj);
  return 1;
}

preserve_object(str){
  object obj;
  string num;

  if(rlname != owner) return 1;
  if(tp->query_money() < 300){
    write("It costs 300 coins to preserve an object.\n");
    write("You don't have that kind of money.\n");
    return 1;
    }

  if(!str){
    write("Preserve what?\n");
    return 1;
    }

  if(preserve != 0){
    write("You have already preserved an item.\n");
    return 1;
    }

  obj = present(str, tp);

  if(!obj){
    write("You do not have a "+str+".\n");
    write("You must have the object on your person.\n");
    return 1;
    }

  if(obj->query_save_flag() == 1){
    write(capitalize(str)+" cannot be preserved.\n");
    return 1;
    }

  if((creator(obj)==0) || (obj->drop())){
    write(capitalize(str)+" cannot be preserved.\n");
    return 1;
    }

  sscanf(object_name(obj), "%s#%s", preserve, num);

  write(
  "You cast a spell of preservation over "+obj->short()+".\n"+
  "The item is encased in a magical crystal that will keep it safe\n"+
  "even if the world was to end.\n"+
  "You carefully hide the preserved object away.\n");
  destruct(obj);
  tp->add_money(-300);
  do_save();
  return 1;
}

thaw_object(){
  object obj;

  if(rlname != owner) return 1;
  if(preserve == 0){
    write("You do not have anything preserved.\n");
    return 1;
    }

  obj = clone_object(preserve);
  move_object(obj, this_player());
  write(
  "You carefully remove the preserved item from its hiding place.\n"+
  "You cast a spell that disapates the magic crystal casing.\n"+
  "You pick up "+obj->short()+".\n");
  preserve = 0;
  do_save();
  return 1;
}

whats_here(){
  object obj;
  if(rlname != owner){
    write("You don't see anything.\n");
    if(find_player(owner)) tell_object(find_player(owner),
    ME+" searched your Mage room.\n");
    return 1;
    }
  if(preserve == 0){
    write("You do not have anything preserved.\n");
    return 1;
    }
  obj = clone_object(preserve);
  write("You have "+obj->short()+" preserved in a magic crystal.\n");
  destruct(obj);
  return 1;
}

query_mguild(){ return "Private Room"; }

#define LOCKERD "/players/pavlik/guild/mages/lockerd"

int
can_store(object who)
{
    return 6;
}

cmd_store(string str)
{
    object ob, scar;
    string tmp, name;

    if (this_player()->query_real_name() != owner) return 0;
    if (!str || !(ob = present(str, this_player()))) {
	notify_fail("Store what?\n");
	return 0;
    }
    name = (string) this_player()->query_real_name();
    if ((int) LOCKERD->items_stored(name) >= can_store(this_player()))
      return (write("There is not room for it.\n"), 1);
    if (tmp = (string) ob->query_name())
      str = tmp;
    if (ob->drop()) {
	write("You are not able to put it in the room.\n");
	return 1;
    }
    if (!LOCKERD->store_item(name, ob)) {
	write("It refuses to go into the room.\n");
	return 1;
    }
    if (ob) destruct(ob);
    write("Your " + str + " has been stored.\n");
    return 1;
}

cmd_retrieve(string str)
{
    object ob;
    string name;
    int x;

    if(this_player()->query_real_name() != owner) return 0;
    if (!str) return (notify_fail("Retrieve which item?\n"), 0);
    name = (string) this_player()->query_real_name();
    x = atoi(str);
    if (x < 1 || (x > (int) LOCKERD->items_stored(name))) {
	write("You do not have such a thing stored.\n");
	return 1;
    }
    ob = (object) LOCKERD->retrieve_item(name, str);
    if (!ob)
	write("You were unable to retrieve it.\n");
    else {
	if (transfer(ob, this_player()))
	  transfer(ob, this_object());
	name = (string)ob->query_name() || "thing";
	write("You retrieve your " + name + ".\n");
    }
    return 1;
}

cmd_list(string str)
{
    object scar;
    string tmp, name;

    if (this_player()->query_real_name() != owner) return 0;
    name = (string) this_player()->query_real_name();
    tmp = (string) LOCKERD->list_items(name);
    if (!tmp)
      write("You have nothing in your room.\n");
    else
      write(tmp);
    
    if (can_store(this_player()) == 1)
      write("You have room for a total of 1 item in your room.\n");
    else
      write("You have room for a total of " + can_store(this_player()) +
	    " items in your room.\n");
    return 1;
}

cmd_clear(string str)
{
    int x;
    string name;

    if(this_player()->query_real_name() != owner) return 0;
    if (!str) return (notify_fail("Clear out which spot?\n"), 0);
    name = (string) this_player()->query_real_name();
    x = atoi(str);
    if (x < 1 || (x > (int) LOCKERD->items_stored(name))) {
	write("You do not have such a thing stored.\n");
	return 1;
    }
    LOCKERD->remove_item(name, str);
    write("It has been disintegrated.\n");
    return 1;
}

query_dont_clean_obs_here() { return 1; }
