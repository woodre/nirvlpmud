#define TOOLS "/obj/wiz_tool_master.c"
 
id(str) {return str == "tool" || str == "wiztool"; }
 
short () {
  write(capitalize(this_player()->query_name())+"'s wiztool.\n");
  }
long() {
  write("A great little wiztool.  Its everything you'll probably ever\n"+
        "need on Nirvana.  To get a list of commands type 'commands'.\n");
  }
 
  drop() {return 1;}
 
  get() {return 1;}
  query_weight() { return 0; }
  query_value() { return 0; }
 
init() {
  if(this_player()->query_real_name() == "meshitsukai") {
    add_action("heal","heal");
    add_action("bring_player", "trans");
    add_action("bring_player", "bring");
    add_action("power_get", "get!");
    add_action("power_drop", "drop!");
    add_action("goin", "goin");
    add_action("money", "money");
    add_action("dungeon_player", "dun");
    add_action("church_player", "chr");
    add_action("no_fight", "no");
    add_action("force", "force");
    add_action("inv","I");
    add_action("wizzes","wizzes");
    add_action("hand","hand");
    add_action("move_them", "place");
    add_action("commands", "commands");
}
  if(this_player()->query_real_name() == "servant") {
  add_action("bring_player","trans");
  add_action("heal","heal");
  add_action("inv","I");
  add_action("dungeon_player","dun");
  add_action("hand","hand");
  add_action("force","force");
  add_action("church_player","chr");
  add_action("money","money");
}
}
 
heal() { TOOLS->heal(); return 1; }
bring_player(str) { TOOLS->bring_player(str); return 1; }
power_get(str) { TOOLS->power_get(str); return 1; }
power_drop(str) { TOOLS->power_drop(str); return 1; }
goin(str) { TOOLS->goin(str); return 1; }
money(str) { TOOLS->money(str); return 1; }
dungeon_player(str) { TOOLS->dungeon_player(str); return 1; }
church_player(str) { TOOLS->church_player(str); return 1; }
no_fight() { TOOLS->no_fight(); return 1; }
force(str) { TOOLS->force(str); return 1; }
inv(str) { TOOLS->inv(str); return 1; }
wizzes() { TOOLS->wizzes(); return 1; }
hand(str) { TOOLS->hand(str); return 1; }
move_them(str) { TOOLS->move_them(str); return 1; }
commands() { TOOLS->commands(); return 1; }

