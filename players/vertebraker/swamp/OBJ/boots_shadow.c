#include "../define.h"
int x; object shdw;

start_shadowing(object ob) {
   shdw = ob; shadow(shdw,1); }

stop_shadowing() {
   shadow(shdw,0); destruct(TO);
   return 1; }

query_gelatin() { if(shdw->query_worn()) return 1; }


init() {
   if(shdw)
   shdw->init();
   if(!x) {
      call_out("ungoo",500); 
      x = 1; } }

short() {
   return shdw->short()+" <"+HIW+"adhesive"+NORM+">";
}
long() { shdw->long();
   write(BOLD+"They are covered with a sloppy gelatin.\n"+NORM); }

ungoo() {
   if(shdw && living(ENV(shdw))) tell_object(ENV(shdw),BOLD+"The gelatin slides off the boots and disappears.\n"+NORM);
   stop_shadowing();
   return 1; }
