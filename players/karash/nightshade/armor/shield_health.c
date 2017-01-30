inherit "obj/armor";
object player, shd;
reset(arg) 
{
   ::reset(arg);
if (arg) return;
set_name("shield of health");
set_short("Ranger Shield");
set_long("A large metal shield. It is very neat and will inform you of\n"
+ "how much damage you take in a fight.\n");
   set_type("shield");
   set_ac(1);
   set_weight(3);
   set_value(200);
   set_alias("health");
}
init() {
::init();
if (player && player != worn_by) {
if (shd) destruct(shd);
player = 0;
if (worn_by) {
shd = clone_object("/players/nightshade/closed/obj/inform");
shd->shadow_target(worn_by);
player = worn_by;
}
}
  }
wear(str) {
::wear(str);
if (worn_by && !player) {
  player = worn_by;
  if (shd) destruct(shd);
   shd = clone_object("players/nightshade/closed/obj/inform");
  shd->shadow_target(player);
write ("You feel as if someone was watching over you.\n");
return 1;
      }
}

take_off() {
::take_off();
player = 0;
if (shd) destruct(shd);
}
remove(str) {
if (!::remove(str)) return 0;
player = 0;
if (shd) destruct(shd);
return 1;
}
