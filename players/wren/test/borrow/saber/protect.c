id(str) { return str == "spell"; }
short();
long() { write("A spell of protection.\n"); }
query_weight() { return 0; }
query_value()  { return 0; }
drop() { return 1; }

reset(arg) {
   if (arg) return;
   call_out("spell_1", 1);
   call_out("end_spell", 10);
}

spell_1() {
string new_ac;
new_ac = this_player()->query_armor_class();
new_ac = new_ac + 2;
call_other(this_player(), "armor_class", new_ac);
tell_object(this_player(), "An invisible magic shield forms around your body.\n");
call_out("spell_1", 1);
 return 1;
}

end_spell() {
string old_ac;
old_ac = this_player()->query_ac();
old_ac = old_ac -2;
call_other(this_player(), "armor_class", old_ac);
tell_object(this_player(), "Your magic shield fades away into a fine mist.\n");
call_out("end_spell", 10);
return 1;
}
