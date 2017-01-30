#define tp this_player()
id(str) { return str == "cocaine"; }
int cadd, ctol, catime;

/* cadd = the addictive value for the user
 * ctol = the tolerance value for the user
 * catime = the last time cocaine was used */
 
long() { write("A line of cocaine.  You may 'snort' it.\n"); }

short() { return "A small amount of cocaine"; }

get() { return 1; }
drop() {return 0;}
query_weight() { return 1; }
query_value() { return 0; }
query_save_flag() { return 0;}

init() {
    add_action("snort", "snort");
}

snort(str) {
object ob;
    if (str == "cocaine") {   
    if(!present("sterm_cocaine",tp)) {
    ob = clone_object("/players/mythos/mmisc/drugs/cocaine/sterm.c");
    ob->set_timer(0);
    move_object(ob,this_player());
    command("save",tp);}
    else {
    present("sterm_cocaine",tp)->set_timer(-1); }
    say(capitalize(tp->query_real_name())+" cuts a line of cocaine and "+
        " snorts it.\nStrength seems to flow into "+
        tp->query_objective()+"!.\n");
    write("You cut the line and snort the cocaine.\nEnergy seems to flow into you!\n");
    if(restore_object("players/mythos/mmisc/drugs/cocaine/add/"+tp->query_real_name())) {
      if(time()-catime > 30000) {
         cadd = cadd - 1;
         if(cadd < 0) { cadd = 0; }
         ctol = ctol - 1;
         if(ctol < 0) { ctol = 0; }
      } else {
      cadd = cadd + 2;
      ctol = ctol + 2; }
    } else {
    cadd = 1;
    ctol = 1; }
    catime = time();
    if(ctol > 10) {
    if(ctol - 10 > 49) {
    tp->heal_self(40); }
    else {
    tp->heal_self(100 - (ctol - 10));}
    } else {
    tp->heal_self(100);}
    save_object("players/mythos/mmisc/drugs/cocaine/add/"+tp->query_real_name());
    destruct(this_object());
    return 1;}
}
