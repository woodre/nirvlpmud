inherit "obj/armor";
/*
 guild_gloves.c - when a vampire guild member wears them, he/she/it is
                 protected from the effects of carrying holy items
*/

is_castle() { return 1; }


reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("gloves");
  set_alias("vampire gloves");
  set_short("White linen gloves");
  set_long(
    "These are a pair of soft white linen gloves.  They might protect\n"+
    "an undead creature while it was carrying holy objects.\n");
  set_type("gloves");
  set_ac(1);
  set_weight(1);
  set_value(500);
}

query_save_flag() { return 1; }

id(str) { return str=="gloves" || str=="guild gloves" || str=="vampire gloves"; }
