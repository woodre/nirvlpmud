#define tp this_player()->qury_name()
inherit "obj/treasure";
  reset(arg) {
   if(arg) return;

   set_id("keyone");
   set_alias("key");
   set_short("A small iron key");
   set_long("A strong iron key that is used to unlock the prison cell.\n");
   set_weight(1);
   set_value(10);
}

