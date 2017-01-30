#define tp this_player()
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("mirror");
    set_alias("mirror");
    set_short("A small mirror");
    set_long("A mirror.  You may 'see' yourself.\n");
    set_weight(1);
    set_value(200);
}

init() {
 ::init();
 add_action("see","see");
}

see() {
  write("You look in the mirror.\n");
  write(tp->long());
  say(capitalize(tp->query_real_name())+" looks in the mirror.\n");
return 1;}
