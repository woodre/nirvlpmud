inherit"obj/weapon";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("sceptre of power");
set_alias("sceptre");
set_short("Sceptre of Power");
set_long(
"A sceptre bearing the symbols of the kingdom of Aldera. A weapon fit for a\n"
+ "King. A huge red ruby adorns the top of the sceptre drawing incredible amounts\n"
+ "of energy into its center. A formidable weapons in the right hands.\n");
set_value(15000);
set_weight(4);
set_save_flag(1);
set_class(20);
set_hit_func(this_object());
}
weapon_hit(attacker) {
if(random(100) < 20) {
write("\n"+"You suddenly feel the power of a King surge through you!"+"\n"+" You inflict a mighty blow upon "+attacker->query_name()+"!\n");
say("Almighty King "+this_player()->query_name()+" inflicts a mighty blow upon "+attacker->query_name()+"!\n");
return 5;
   }
return 0;
 }
