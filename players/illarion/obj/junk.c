inherit "obj/treasure.c";

void reset(int arg) {
  if(arg) return;

  set_id(call_other("players/illarion/obj/junk_maker","junk_name"));
  set_alias("junk");
  set_weight(1);
  set_value(0);
  set_short(capitalize((string)call_other("players/illarion/obj/junk_maker","junk_adjective"))+
    " "+name);
  set_long(short()+".\n");
}
