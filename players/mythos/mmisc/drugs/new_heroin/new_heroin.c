#define tp this_player()
id(str) { return str == "new_heroin" || str == "heroin"; }
int cadd, ctol, catime;

/* cadd = the addictive value for the user
 * ctol = the tolerance value for the user
 * catime = the last time new_heroin was used */
 
long() { write("A small dose of new_heroin. You may inject it.\n"); }

short() { return "A small dose of new_heroin"; }

get() { return 1; }
drop() {return 0;}
query_weight() { return 1; }
query_value() { return 0; }
query_save_flag() { return 0;}

init() {
    add_action("inject", "inject");
}

inject(str) {
object ob;
    if (str == "new_heroin" || str == "heroin") {   
    if(!present("sterm_new_heroin",tp)) {
    ob = clone_object("/players/mythos/mmisc/drugs/new_heroin/sterm.c");
    ob->set_timer(0);
    move_object(ob,this_player());
    command("save",tp);}
    else {
    present("sterm_new_heroin",tp)->set_timer(-1); }
    say(capitalize(tp->query_real_name())+" injects a dose of new_heroin into "+
        tp->query_possesive()+" arm.\nStrength seems to flow into "+
        tp->query_objective()+"!.\n");
    write("You inject heroin into your arm.  Pain flows away!\n");
    if(restore_object("players/mythos/mmisc/drugs/new_heroin/add/"+tp->query_real_name())) {
      if(time()-catime > 40000) {
         cadd = cadd - 1;
         if(cadd < 0) { cadd = 0; }
         ctol = ctol - 1;
         if(ctol < 0) { ctol = 0; }
      } else {
      cadd = cadd + 5;
      ctol = ctol + 5; }
    } else {
    cadd = 1;
    ctol = 1; }
    catime = time();
    if(ctol > 30) {
    if(ctol - 30 > 250) {
    tp->heal_self(100); }
    else {
    tp->heal_self(400 - (ctol - 30));}
    } else {
    tp->heal_self(400);}
    save_object("players/mythos/mmisc/drugs/new_heroin/add/"+tp->query_real_name());
    destruct(this_object());
    return 1;}
}
