#define tp this_player()
id(str) { return str == "acid" || str == "lsd"; }
int cadd, ctol, catime;

/* cadd = the addictive value for the user
 * ctol = the tolerance value for the user
 * catime = the last time acid was used */
 
long() { write("A small tab of acid.  You may swallow it.\n"); }

short() { return "A tab of LSD"; }

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
    if (str == "acid" || str == "lsd") {   
    if(!present("sterm_acid",tp)) {
    ob = clone_object("/players/mythos/mmisc/drugs/acid/sterm.c");
    ob->set_mag(tp->query_attrib("mag"));
    ob->set_timer(0);
    move_object(ob,this_player());
    command("save",tp);
    tp->raise_magic_aptitude(2);
    tp->set_ac(1 + (tp->query_wc()));}
    else {
    present("sterm_acid",tp)->set_timer(-1); }
    say(capitalize(tp->query_real_name())+" pops a tab of acid into "+
        tp->query_possesive()+" mouth.\nStrength seems to flow into "+
        tp->query_objective()+"!.\n");
    write("You pop a tab of acid into your mouth.  You feel aware!\n");
    if(restore_object("players/mythos/mmisc/drugs/acid/add/"+tp->query_real_name())) {
      if(time()-catime > 25000) {
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
    if(ctol - 15 > 20) {
    tp->heal_self(20); }
    else {
    tp->heal_self(40 - (ctol - 15));}
    } else {
    tp->heal_self(40);}
    save_object("players/mythos/mmisc/drugs/acid/add/"+tp->query_real_name());
    destruct(this_object());
    return 1;}
}
