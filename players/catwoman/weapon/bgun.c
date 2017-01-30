int loaded;
int blow;
/*int i;

heart_beat() {
  blow = 0;
  return 1;
}
*/
id(str) { return str=="blowgun" || str=="gun"; }

short() { return "A blowgun"; }

get() { return 1; }

query_value() { return 1000; }

query_weight() { return 3; }

long() { write("A long hollow tube.  You use poison darts in it, you must\n");
         write("load the darts, then blow them at your opponent.\n");
         if (loaded == 1) {
           write("The blowgun is loaded with a dart.\n");
         }
         if (loaded != 1) {
           write("The blowgun is empty.\n");
         }
}

load_gun(str) {
object ob;
  if (!id(str)) return 0;
  ob = present("dart",this_player());
  if (!ob) {
    write("You have no darts.\n");
    return 1;
  }
  if (loaded == 1) {
    write("The blowgun is already loaded.\n");
    return 1;
  }
 write("You load the blowgun.\n");
 say(this_player()->query_name() + " loads " + this_player()->query_name() + "'s blowgun.\n");
 call_other(this_player(), "add_weight", -1);
 loaded = 1;
 move_object(ob,this_object());
 return 1;
}

blow(str) {
object ob;
/*i = random(100);*/

if (!present("blowgun",this_player())) {
   write("You must get it first.\n");
   return 1;
}
if (!str) { 
   write("At who?\n");
   return 1;
}
if (!loaded) {
   write("It's not loaded.\n");
   return 1;
}
ob = present(lower_case(str),environment(this_player()));
if (!ob) {
  write("Fire at who?\n");
  return 1;
}
if (!living(ob)) {
   write("It's not living though!\n");
   return 1;
}
if (call_other(ob, "query_npc", 0) == 0) {
   write("You cannot use this on living players.\n");
   return  1;
}
/*if (blow == 1) {
   write("You cannot shoot more than one dart in a round.\n");
   return 1;
}*/
/*if (i < 10) {
  write("You have used this blowgun one too many times.\n");
  write("It cracks, making it useless.  You discard the\n");
  write("broken weapon.\n");
  say(this_player()->query_name() + "'s blowgun breaks.\n");
  destruct(this_object());
  call_other(this_player(), "add_weight", -3);
  return 1;
}*/

  if(present("dart",this_object())->shoot(ob));
 /* command("kill" + this_player()->query_name(), ob);*/
  write("You shoot a poison dart at " + capitalize(str) + ".\n");
  say(this_player()->query_name() + " shoots a poison dart at " +
      capitalize(str) + ".\n");
 loaded = 0;
 blow = 1;
 return 1;
}

init() {
  add_action("load_gun","load");
  add_action("blow","blow");
 /* set_heart_beat(1);*/
}

