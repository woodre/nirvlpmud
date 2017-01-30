inherit "room/room.c";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Inside Spuck";
  long_desc="\tYou are trapped inside Spuck. All around you is a thick,\n"+
"  gelatinous blob-like material that is utterly impossible to move\n"+
"  around in. Able to catch fleeting glimpses of what is going on ouside\n"+
"  through the semi-opaque material, you can only sit and wait for\n"+
"  the inevitable.\n";
  no_exits=1;
  call_out("destroy", 90);
}

destroy() {
  object ob;
  ob=first_inventory(this_object());
    while(ob) {
      object oc;
      oc=ob;
      oc=next_inventory(ob);
        if(living(oc)) {
	write("Spuck has absorbed you.\n");
	say((oc->query_name())+" disappears.\n");
        oc->save_me();
        destruct(oc);
        }
    }
  destruct(this_object());
}


