inherit "obj/weapon";
int die, attacker, pain;
reset(arg) {
::reset(arg);
        if(!arg) {
           set_name("bat");
          set_class(11);
           set_value(100);
           set_weight(2);
           set_alias("knife");
    set_short("A deadly pocket knife");
set_long(
" An ordinary pocket knife.  Its quite rugged.  You have the urge to\n"+
"kill something with it.\n");
}
}
