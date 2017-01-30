#include "/players/mythos/myth/shape/def.h"
inherit "players/mythos/mytho/base";
string form;
string pretitle,title;


id(str) { return str == "myth" || str == "myth_soul" ||
                 str == form || str == "spirit" || str == "MYTHOSSYSOBJ"; }

query_auto_load() { return "/players/mythos/myth/shape/base.c:"; }

short() { return "Spirit of "+capitalize(form); }

long() {
   write("\n");
   write("myth_help will bring up the help files\n");
}

reset(arg) {
::reset(arg);
  if(arg) return;
  form = "snake";
  whatob = "shape";
}

init() {
::init();
if(tp == ep) {
}
}

query_form() { return form; }
set_form(str) { if(POWER->check_form(str)) form = str; gsave();}

retrieve() {
  pretitle = ep->query_pretitle();
  title = ep->query_title();
return 1; }

release() {
  ep->set_title(title);
  ep->set_pretitle(pretitle);
  if(ep->query_alignment() > 640)  ep->set_al_title("white lord"); 
  if(ep->query_alignment() > 320)  ep->set_al_title("paladin"); 
  if(ep->query_alignment() >160)    ep->set_al_title("crusader"); 
  if(ep->query_alignment() > 80)   ep->set_al_title("good");
  if(ep->query_alignment() > 40)   ep->set_al_title("honorable"); 
  if(ep->query_alignment() > -40)  ep->set_al_title("neutral"); 
  if(ep->query_alignment() > -80)  ep->set_al_title("malicious"); 
  if(ep->query_alignment() > -160) ep->set_al_title("evil"); 
  if(ep->query_alignment() > -320) ep->set_al_title("infamous"); 
  if(ep->query_alignment() > -640) ep->set_al_title("black knight"); 
  if(ep->query_alignment() < -639) ep->set_al_title("lord of evil"); 
return 1; }

/* POWER material */

