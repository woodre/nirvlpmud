

/*
 * FAMILIAR (3/24/94)
 * The familiar must be cloned using the familiar stone (fam_stn.c) or
 * the variables will not be set corrcetly.
 */

inherit "obj/monster";

reset(arg) {
    if(arg) return;
    set_ep(200);
    set_al(100);
    set_wc(10);
    set_ac(2);
    set_alias("familiar");
    set_long("A magical looking creature.\n");
    set_dead_ob(this_object());
    enable_commands();
    ::reset(0);
}

string owner, tmp_short;
object dest;

set_owner(o) { owner = o; }

set_tmp_short(s) { tmp_short = s; }

monster_died() {
   if(find_player(owner)) {
     tell_object(find_player(owner), "You familiar has been killed!\n");
   }
}

short() {
     return tmp_short;
  ::short();
}

catch_tell(str) {
   object stone;
   dest = environment(this_object());
   if(find_player(owner)) {
     tell_object(find_player(owner), "%"+str);
     return 1;
   } else {
     destruct(this_object());
     return 1;
   }
}

