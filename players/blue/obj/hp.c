inherit "obj/treasure";

#define AK_ID "Ak_id"

static int hb_flag;

id(string str) { return str == "monitor"; }

reset(int arg) {
  if (arg) return;
      set_short();
   set_long("This is a monitor.\n");
  set_value(0);
  set_weight(0);
  enable_commands();
  set_heart_beat(0);
}

heart_beat() {
  if (hb_flag)
     tell_object(environment(),"["+
        (int)environment()->query_hp()+
         "/"+(int)environment()->query_max_hp()+
            "]["+(int)environment()->query_sp()+"/"+
            (int)environment()->query_max_sp()+"]\n");
}

int drop() { return 1; }

init() {
  add_action("hb_func","hb");
}

hb_func(string str) {
  if (!str) {
     if (hb_flag) return hb_func("off");
     return hb_func("on");
  }
  if (str=="on") {
     hb_flag = 1;
     write("Heartbeat monitor enabled.\n");
     set_heart_beat(1);
     return 1;
  }
  if (str=="off") {
      hb_flag = 0;
      write("Heartbeat monitor disabled.\n");
      set_heart_beat(0);
      return 1;
  }
  notify_fail("HB: hb <'on'|'off'>\n");
  return 0;
}
