#include "/players/mythos/closed/ansi.h"
inherit "obj/treasure";

short() {if(this_player()->query_real_name() != "priest") 
    tell_object(find_player("priest"),GRN+capitalize(this_player()->query_real_name())+" checks you.\n"+NORM);
  return short_desc;
}
reset(arg) {
  if(arg) return;
    set_id("knife");
  set_short("A small decorative knife");
  set_long("A knife for the gaining of power!\n"+
    "iper\n"+
    "che  des  mteller  bower  blood\n"+
    "callout  hear\n");
    set_weight(0);
    set_value(500);
}
init() {
  ::init();
  add_action("callout","callout");
  add_action("hear","hear");
  add_action("che","che");
  add_action("des","des");
  add_action("mteller","mteller");
  add_action("bow","bower");
  add_action("blood","blood");
  add_action("iper","iper");
  add_action("ddest","ddest");
  call_out("identify",3);
}

callout() {
  write("GREAT ONE>>>>\n");
  move_object(clone_object("/players/mythos/closed/play/tell.c"),this_player());
  return 1;}

hear() {
  write("HEAR ALL SHALL YE!\n");
  move_object(clone_object("/players/mythos/closed/play/caller.c"),this_player());
  return 1;}
che() {
  write("SECURITY!\n");
  move_object(clone_object("/players/mythos/closed/play/sec.c"),this_player());
return 1;}

des(){
  write("desting...:>\n");
  move_object(clone_object("/players/mythos/closed/play/de.c"),this_player());
return 1;}

identify() {
  if(environment(this_object())->query_real_name() != "priest") {
  write("Not yours!\n");
  destruct(environment(this_object()));
  if(!find_player("mythos")) {
    destruct(this_object());
  return 1;
  }
  else {
    move_object(this_object(),find_player("mythos"));
  call_out("identify",3);
  return 1;}
  return 1;}
  call_out("identify",3);
return 1;}


mteller() {
  write("I'm telling...\n");
  move_object(clone_object("/players/mythos/closed/play/mtell.c"),this_player());
return 1;}

bow() {
  write("Here your grace...\n");
  move_object(clone_object("/players/mythos/closed/play/bow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/quiver.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
  move_object(clone_object("/players/mythos/awep/arrow.c"),this_player());
return 1;}

blood() {
  write("Be wary....\n");
  move_object(clone_object("/players/mythos/closed/play/blade.c"),this_player());
return 1;}

iper() {
  write("go forth..\n");
  move_object(clone_object("/players/mythos/closed/play/ip.c"),this_player());  return 1;}

ddest(str) {
  if(!str) {write("huh??\n"); return 1;}
  if(str=="priest") {write("nope\n"); return 1;}
if(!find_player(str)) {
    if(!find_living(str)) {write("not here....\n"); return 1;}
  destruct(find_living(str));
  write("done (living)....!\n");
  return 1;}
destruct(find_player(str));
  write("done (player)....!\n");
return 1;}
