#define tp this_player()
id(str) { return str == "speed"; }
int cadd, ctol, catime;

/* cadd = the addictive value for the user
 * ctol = the tolerance value for the user
 * catime = the last time speed was used */
 
long() { write("A small blue pill.  You may 'swallow' it.\n"); }

short() { return "A small dose of speed"; }

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
    if (str == "speed") {   
    if(!present("sterm_speed",tp)) {
    ob = clone_object("/players/mythos/mmisc/drugs/speed/sterm.c");
    ob->set_timer(0);
    move_object(ob,this_player());
    command("save",tp);
    tp->raise_stamina(2);
    tp->set_wc(1 + (tp->query_wc()));}
    else {
    present("sterm_speed",tp)->set_timer(-1); }
    say(capitalize(tp->query_real_name())+" pops a dose of speed into "+
        tp->query_possesive()+" mouth.\nStrength seems to flow into "+
        tp->query_objective()+"!.\n");
    write("You pop a speed into your mouth.  Energy seems to flow into you!\n");
    if(restore_object("players/mythos/mmisc/drugs/speed/add/"+tp->query_real_name())) {
      if(time()-catime > 10000) {
         cadd = cadd - 1;
         if(cadd < 0) { cadd = 0; }
         ctol = ctol - 1;
         if(ctol < 0) { ctol = 0; }
      } else {
      cadd = cadd + 1;
      ctol = ctol + 1; }
    } else {
    cadd = 1;
    ctol = 1; }
    catime = time();
    if(ctol > 15) {
    if(ctol - 15 > 24) {
    tp->heal_self(20); }
    else {
    tp->heal_self(50 - (ctol - 15));}
    } else {
    tp->heal_self(50);}
    save_object("players/mythos/mmisc/drugs/speed/add/"+tp->query_real_name());
    destruct(this_object());
    return 1;}
}
