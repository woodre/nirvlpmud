#define tp this_player()
#define tpn tp->query_name()
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("seed");
    set_alias("golden seed");
    set_short("A golden seed");
    set_long("A golden seed that which contains powerful items.\n"+
             "Plant it and see what is within.\n");
    set_weight(1);
    set_value(10000);
}

query_save_flag() { return 0; }

init() { ::init(); add_action("plant","plant"); }

plant(str) {
object blade,robe;
int idset;
  if(!str) { write("Plant what?\n"); return 1; }
  if(id(str)) {
    write("You plant the seed in the ground.\n");
    say(tpn+" plants a seed in the ground.\n");
    tell_room(environment(this_player()),
    "Suddenly a Golden plant sprouts out from the ground.\n"+
    "The plant flowers and then immediately fruits.\n"+
    "The fruit grows and falls- breaking open.\n"+
    "Before you lies a blade of wonderous beauty and a shiny robe.\n");
    blade = clone_object("/players/mythos/dwep/seed_blade.c");
    robe = clone_object("/players/mythos/darmor/seed_robe.c");
    idset = random(1000000);
    blade->set_idset(idset);
    robe->set_idset(idset);
    move_object(blade,environment(this_player()));
    move_object(robe,environment(this_player()));
    destruct(this_object());
  return 1; }
}