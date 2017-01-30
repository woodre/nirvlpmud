#include "/players/mythos/closed/ansi.h"
id(str) {return str == "area";}
query_auto_load() { return "/players/mythos/closed/play/tell.c:"; }

init() {
  add_action("all","all");
}

all(str) {
  if(!str) {
   write("try again...\n");
  return 1;}
  else {
  string col, word;
  sscanf(str, "%s %s",col,word);
  if(col == "R") {
    say(RED+word+NORM+"\n");
    write(RED+word+NORM+"\n");
  return 1;}
  if(col == "G") {
    say(GRN+word+NORM+"\n");
    write(GRN+word+NORM+"\n");
  return 1; }
  if(col == "BL") {
    say(BLU+word+NORM+"\n");
    write(BLU+word+NORM+"\n");
  return 1;}
  if(col == "B") {
    say(BOLD+word+NORM+"\n");
    write(BOLD+word+NORM+"\n");
  return 1; }
  if(col == "HR") {
    say(HIR+word+NORM+"\n");
    write(HIR+word+NORM+"\n");
  return 1; }
  if(col == "BB") {
    say(BOLD+BLINK+word+NORM+"\n");
    write(BOLD+BLINK+word+NORM+"\n");
  return 1;}
  if(col == "SR") {
    shout(RED+word+NORM+"\n");
    write(RED+word+NORM+"\n");
  return 1; }
  if(col == "SB") {
    shout(BOLD+word+NORM+"\n");
    write(BOLD+word+NORM+"\n");
  return 1; }
  if(col == "SBL") {
    shout(BLU+word+NORM+"\n");
    write(BLU+word+NORM+"\n");
  return 1; }
  if(col == "SRB") {
    shout(HIR+BLINK+word+NORM+"\n");
    write(HIR+BLINK+word+NORM+"\n");
  return 1; }
  return 1;}
return 1;}
