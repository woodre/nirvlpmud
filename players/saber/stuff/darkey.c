#define tp this_player()->qury_name()
inherit "obj/treasure";
reset(arg)
{   if (arg) return;
   set_id("key");
   set_alias("saber_swamp_key");
   set_short("A small silver key");
   set_long(
    "A small silver key with faint runes etched upon one side.\n");
   set_read(
    "You can't make out the runes.\n");
   set_weight(0);
   set_value(0);
}

saber_swamp_door_key() { return 1; }
