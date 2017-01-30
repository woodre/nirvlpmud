inherit "obj/weapon";
int die, attacker, pain;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("bloodstained baseball bat");
    set_long("Hmm.. this bat is covered in blood. Interesting.\n");
    set_short("A bloodstained baseball bat");
    set_class(10);
    set_value(300);
    set_alias("bat");
    set_weight(2);
    set_hit_func(this_object());

}
}
