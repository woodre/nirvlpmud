#define MASTER_R "/players/dune/objects/eyedaem.c"

id(str) { return str == "eyes" || str == "fire_eyes_elemental"; }
reset() {}
short() { return "Eyes of Fire"; }
long() {
   MASTER_R->howto();}

query_value() {return 4500;}
get() { return 1; }

init() {
   add_action("view","view");
   add_action("viewon","viewon");
   }

view(str) {
   object ob;
   if (!str) {
      write("View what or who?\n"); return 1;}
   if(present(str, environment(environment(this_object())))) {
      ob = present(str, environment(environment(this_object())));
      if (find_player(str) && (ob->query_level() >= 20)) {
         MASTER_R->view(str); return 1; }
      queryp(str, ob);
      return 1; }
   MASTER_R->view(str); return 1; }

viewon(str) {
   object ob;
   string who, what;
   if (!str) {
      write("Usage: Viewon [person] [object].\n"); return 1;}
   if(!sscanf(str, "%s %s", who, what)) {
      write("Usage: Viewon [person] [object].\n");
   return 1;}
   if(present(str, environment(environment(this_object())))
    && present(what,
    present(str, environment(environment(this_object()))))) {
      ob = present(what,
       present(str, environment(environment(this_object()))));
      queryo(what, ob);
    return 1; }
   MASTER_R->viewon(str);
   return 1; }

queryo(what, ob) { MASTER_R->queryo(what, ob);
                   return 1; }

queryp(str, ob) { MASTER_R->queryp(str, ob);
                  return 1; }

queryw() { MASTER_R->queryw(); return 1; }
