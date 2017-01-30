inherit "obj/treasure";

string *names;

static void cmd_print();

void
reset(int arg) {
   if (arg) return;
   set_id("object");
   set_short("object");
   set_long(
"A wiz object.\n");
   set_weight(0);
   set_value(0);
   set_save_flag();
  names = ({"rattlesnake","vortex","fawkes",});
}

void init() {
  add_action("cmd_test","t1");
  add_action("cmd_print","t2");
}

status
cmd_test(string str) {
  object ob, who;
  
  ob = clone_object("/players/dragnar/daemons/shop_shadow");
  who = find_player("rumplemintz");
  ob->doShopShadow(who);
  return 1;
}

cmd_print() {
  int i;

  for(i=0; i<sizeof(names); i++) {
    tell_object(this_player(), i+". "+names[i]+"\n");
  }
  return 1;
}

set_names(string *tmp) { names = tmp; }
