inherit "obj/monster";

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("critter");
   set_alias("clan_critter_create");
   set_al(0);
   set_short("A Critter");
   set_long("A critter for you to smack around.\n");
}
