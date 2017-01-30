#include "../def.h"
#define NOTE MEM+"obj/notes/"+tpn
#define GEN  MEM+"obj/notes/general"
#define RNO  restore_object(NOTE)
#define SNO  save_object(NOTE)
#define RGO  restore_object(GEN)
#define SGO  save_object(GEN)
string own;
string pword;
string msg;
string cag;
string header;

id(str) { return str == "notes" || str == "journal" || str == "diary" || str == "notebook"; }

short() { return "A small journal"; }

long() { write(""); }

reset(arg) {
    if(arg) return;
    header = ({"info"});
    msg = ({"Type 'note_help' for all commands\n"});
    cag = ({"main"});
}

drop() { return 1; }
get() { return 0; }

init() {
  if(tp == ep) {
    if(!hob) { destruct(this_object()); return 1; }
    if(!RNO) SNO;
  }
}  

notes(str) {
  if(!str) {
  return 1; }
  
return 1; }

read_notes(str) {
  if(!str) { }
  
return 1; }

delete_note(str) {
  if(!str) { }

return 1; }

move_note(str) {
  if(!str) { }
  
return 1; }

copy_note(str) {
  if(!str) { }
  
return 1; }

change_cat(str) {
  if(!str) { }
  
return 1; }

list_cat(str) {
return 1; }

list_notes(str) {
return 1; }
