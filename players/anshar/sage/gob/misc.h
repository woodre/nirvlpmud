/* AUTOLOAD */
/*query_auto_load() { return "/players/anshar/sage/gob.c:"; } */
    
/* DROP AND GET */
drop () { return 1; }  /* undroppable */
get() { return 0; }    /* ungettable */


check_me(ob) {
  if(ob->query_real_name() == "anshar") return 1;
  if(ob == environment()) return 1;
  else return 0; }
