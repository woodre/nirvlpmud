#pragma strong_types

inherit "room/room";

status door_is_open;
int rescount;
string password;

void
throw_out() {  /* Called at reset to kick people out */
  object ob, next_ob;
  ob = first_inventory(this_object());
  while(ob) {
    next_ob = next_inventory(ob);
    if (living(ob)) {
      move_object(ob, "players/angmar/castle/treasury_entrance");
      tell_object(ob, "You feel dizzy for a moment. Where are you?\n");
    }
    ob = next_ob;
  }
}

void
populate() {  /* Called at reset to populate the room */
  object chainmail, obj, mon;
  
  if (!present("chainmail")) {
    chainmail = clone_object("obj/armor");
    chainmail->set_name("chainmail");
    chainmail->set_short("heavy chainmail");
    chainmail->set_long(
	       "This chainmail looks rusty, and must be very old.\n"+
	       "There are a few darkened splotches of blood here and there,\n" +
	       "but it looks like a formidable piece of armour.\n");
    chainmail->set_alias("heavy chainmail");
    chainmail->set_value(1000);
    chainmail->set_weight(7);
    chainmail->set_ac(3);
    chainmail->set_type("armor");
    move_object(chainmail,this_object());
  }
  if (!present("sapphire")) {
    obj = clone_object("obj/treasure");
    obj->set_id("sapphire");
    obj->set_short("A sapphire");
    obj->set_long(
"The facets of the sapphire shimmer and glint in the light.\n"+
"You examine it closely, and notice the workmanship inherent in the gem.\n"+
"This is a fine stone, indeed.\n");
    obj->set_value(200);
    move_object(obj, this_object());
  }
  if (!present("money")) {
    obj = clone_object("obj/money");
    obj->set_money(312);
    move_object(obj, this_object());
  }
    if (!present("money")) {
    obj = clone_object("obj/money");
    obj->set_money(12);
    move_object(obj, this_object());
  }
  if (!present("crown")) {
    obj = clone_object("obj/treasure");
    obj->set_id("crown");
    obj->set_short("A golden crown");
    obj->set_long(
"At first glance, this crown seems to be a crude adornment for a long-dead\n" +
"monarch.  On closer inspection, however, you notice a small gem pattern\n" +
"that renders this crown to be of high value.\n");
    obj->set_value(400);
    move_object(obj,this_object());
  }
  if (!present("diamond")) {
    obj = clone_object("obj/treasure");
    obj->set_id("diamond");
    obj->set_short("A diamond");
    obj->set_long(
"This diamond is much larger than others you have seen in the world.\n" +
"You cannot estimate the number of carats on this rock, but what you\n" +
"do know about gems hints that this diamond may be worth a lot.\n");
    obj->set_value(300);
  move_object(obj,this_object());
  }
  if (!present("spear")) {
    obj = clone_object("obj/weapon");
    obj->set_name("spear");
    obj->set_short("A heavy spear");
    obj->set_long(
"It's about six feet long, with a metal head inserted into the tip.\n" +
"Some type of coarse cord is wrapped around the tip to hold the point in\n" +
"the spear.  You notice that the middle section of the spear seems worn,\n" +
"as if it were used in many battles.\n");
    obj->set_class(14);
    obj->set_weight(4);
    obj->set_value(400);
    move_object(obj,this_object());
  }
  if (!present("sword")) {
    obj = clone_object("obj/weapon");
    obj->set_name("sword");
    obj->set_short("An ancient sword");
    obj->set_long(
"This sword has the nicks and scrapes of a well-used blade.  Although the\n"+
"hilt has been replaced several times, the blade is as keen and sharp\n" +
"as they day it was first ready for battle.\n");
    obj->set_class(17);
    obj->set_weight(5);
    obj->set_value(2100);
    move_object(obj,this_object());
  }
  /*  Too easy, moving this to somewhere else. - Rumplemintz
  if (!present("doomsgiver"))
    move_object(clone_object("players/angmar/o/doomsgiver"), this_object();
  */
  if (!present("money")) {
    obj=clone_object("obj/money");
    obj->set_money(125);
    move_object(obj,this_object());
  }
}

void
new_password() {
  int x;
  
  x=random(6);
  if(x==0) password="tarantor";
  if(x==1) password="hashnuk";
  if(x==2) password="gothnir";
  if(x==3) password="hurfurin";
  if(x==4) password="alannen";
  if(x==5) password="rhastul";
  x=random(6);
  if(x==0) password=password+" osibilum";
  if(x==1) password=password+" shiryllis";
  if(x==2) password=password+" fornor";
  if(x==3) password=password+" es";
  if(x==4) password=password+" eth";
  if(x==5) password=password+" sureth";
  x=random(6);
  if(x==0) password=password+" brupp";
  if(x==1) password=password+" hades";
  if(x==2) password=password+" grukk";
  if(x==3) password=password+" elte";
  if(x==4) password=password+" connon";
  if(x==5) password=password+" benambra";
}

void
reset(status arg) {
  throw_out();
  populate();
  door_is_open = 0;
  "players/angmar/castle/treasury_entrance"->doors_open();
  if (rescount == 0)
    new_password();
  set_heart_beat(1);

  if (arg)
    return;
  set_light(1);
  short_desc = "The treasury";
}    

string realm(){ return "NT"; }

mixed
got_rings() {
  return (present("trlock1", this_player()) &&
          present("trlock2", this_player()) &&
          present("trlock3", this_player()));
}

void
catch_it(string str) {
  string a,b;

  if ((sscanf(str, "%s" +password+ "%s",a,b) == 2) && got_rings()) {
    "players/angmar/castle/treasury_entrance"->password_ok();
    write("The giant doors slowly and soundlessly swing open!\n");
    write("Angmar's treasury lies open in front of you!\n");
    say("The giant doors slowly and soundlessly swing open!\n");
    say("Angmar's treasury lies open in front of you!\n");
    door_is_open=1;
    this_player()->set_quest("angmar");
    write("Your quest is completed!\n");
  }
}

string
query_password() { /* called from oracle */
  return password;
}

void
prevent_reset() {  /* called from oracle */
  rescount = 200;
  set_heart_beat(1);
}

void heart_beat() {
  if (rescount > 0)
    rescount-=1;
}

int
query_rescount() {  /* for debugging only */
  return rescount;
}

int
query_door() {
  return !door_is_open;
}

void
init() {
  room::init();
  add_action("open_door", "open");
  add_action("close_door", "close");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("south"); add_verb("south");
#else
  add_action("south", "south");
#endif
}

void
long(string str) {
  if (str == "door" || str == "doors") {
    if (door_is_open)
      write("The doors are open.\n");
    else
      write("The doors are closed.\n");
  }
  write("You are inside Angmar's treasury.\n");
  write("The only obvious exit is to the south.\n");
}

mixed
id(string str) {
  return str=="door" || str=="doors";
}

status
south() {
  if (!door_is_open) {
    write("The doors are closed.\n");
    return 1;
  }
  this_player()->move_player("south#players/angmar/castle/treasury_entrance");
  return 1;
}

status
open_door(string str) {
  if (str != "door" && str != "doors")
    return 0;
  if (door_is_open) { 
    write("The doors are already open!\n");
    return 1;
  }
  door_is_open = 1;
  write("You barely need to touch the doors. They seem to swing\n");
  write("wide open by some unvisible force.\n");
  say(this_player()->query_name()+" opened the doors.\n");
  return 1;
}

status
close_door(string str) {
  if (str != "door" && str != "doors")
    return 0;
  if (!door_is_open) { 
    write("They are already closed!\n");
    return 1;
  }
  write("The doors are too heavy. You can't move them.\n");
  return 1;
}
