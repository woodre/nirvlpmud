inherit "obj/treasure";
reset(arg){
if (arg) return;
   set_weight(0);
   set_value(0);
}
id(str) { return str == "invis_obj"; }
long() { write ("Invisibility object. Neat, eh?\n");
}
get() { return 0; }
drop() { return 1; }
wear_off() {
environment(this_object())->visible();
destruct(this_object());
}
invis_em() {
environment(this_object())->set_invs_sp();
call_out("wear_off",random(300) + 120);
}
