/*
  ru784.c - abortion pill
*/

inherit "obj/treasure";
#define TP this_player()

reset(arg) {
  set_short("red RU784 pill");
  set_long(
    "A fire red pill with yellow lettering.  It's used to terminate\n"+
    "unwanted pregnancy.  All one needs to do is 'swallow' it.\n");
  set_value(25);
  set_weight(1);
}

init() {
  ::init();
  add_action("swallow", "swallow");
  add_action("read","read");
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "pill" || str == "ru784" || str == "RU784") {
  write("The yellow lettering reads 'XXX - Danger!'\n");
  return 1; }
}

swallow(str) {
if (str!="pill" && str!="abortion pill" && str!="ru784 pill") return 0;
if(random(100) < 10) {
  write("You swallow the nasty tasting pill and feel very nauseous..\n");
  TP->raise_stamina(-1);
    if(TP->query_attrib("sta") < 0) TP->set_attrib("sta") == 0;
  return 1; }
if(!this_player()->query_pregnancy()){
  write("You swallow the pill but were not pregnant.\n");
  destruct(this_object());
  return 1; }
this_player()->clear_pregnancy();
destruct(this_object());
write("You swallow the poisonous pill and kill your unborn baby..\n");
return 1; }


id(str) { return (str=="pill"  || str=="abortion pill" || str=="ru784"); }
