#define tp this_player()
id(str) { return str == "XTC" || str == "xtc"; }
int cadd, ctol, catime;

/* cadd = the addictive value for the user
 * ctol = the tolerance value for the user
 * catime = the last time XTC was used */
 
long() { write("A small red pill.  You may 'swallow' it.\n"); }

short() { return "A small dose of XTC"; }

get() { return 1; }
drop() {return 0;}
query_weight() { return 1; }
query_value() { return 0; }
query_save_flag() { return 0;}

init() {
    add_action("swallow", "swallow");
}

swallow(str) {
object ob;
    if (str == "XTC" || str == "xtc") {   
    if(!present("sterm_XTC",tp)) {
    ob = clone_object("/players/mythos/mmisc/drugs/XTC/sterm.c");
    ob->set_timer(0);
    move_object(ob,this_player());
    command("save",tp);}
    else {
    present("sterm_XTC",tp)->set_timer(-1); }
    say(capitalize(tp->query_real_name())+" pops a dose of XTC into "+
        tp->query_possesive()+" mouth.\nStrength seems to flow into "+
        tp->query_objective()+"!.\n");
    write("You pop a XTC into your mouth.  Energy seems to flow into you!\n");
    if(restore_object("players/mythos/mmisc/drugs/XTC/add/"+tp->query_real_name())) {
      if(time()-catime > 15000) {
         cadd = cadd - 1;
         if(cadd < 0) { cadd = 0; }
         ctol = ctol - 1;
         if(ctol < 0) { ctol = 0; }
      } else {
      cadd = cadd + 1;
      ctol = ctol + 2; }
    } else {
    cadd = 1;
    ctol = 1; }
    catime = time();
    if(ctol > 10) {
    if(ctol - 10 > 30) {
    tp->heal_self(40); }
    else {
    tp->heal_self(75 - (ctol - 10));}
    } else {
    tp->heal_self(75);}
    save_object("players/mythos/mmisc/drugs/XTC/add/"+tp->query_real_name());
    destruct(this_object());
    return 1;}
}
