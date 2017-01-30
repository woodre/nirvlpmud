#define tp this_player()
id(str) { return str == "weed" || str == "pot"; }
int cadd, ctol, catime;

/* cadd = the addictive value for the user
 * ctol = the tolerance value for the user
 * catime = the last time weed was used */
 
long() { write("A small joint.  You may 'smoke' it.\n"); }

short() { return "A small roll of weed"; }

get() { return 1; }
drop() {return 0;}
query_weight() { return 1; }
query_value() { return 0; }
query_save_flag() { return 0;}

init() {
    add_action("smoke", "smoke");
}

smoke(str) {
object ob;
    if (str == "weed" || str == "pot") {   
    if(!present("sterm_weed",tp)) {
    ob = clone_object("/players/mythos/mmisc/drugs/weed/sterm.c");
    ob->set_timer(0);
    move_object(ob,this_player());
    command("save",tp);}
    else {
    present("sterm_weed",tp)->set_timer(-1); }
    say(capitalize(tp->query_real_name())+" lights up a joint. "+
        "\nStrength seems to flow into "+
        tp->query_objective()+"!.\n");
    write("You light up a joint.  Energy seems to flow into you as you take a drag!\n");
    if(restore_object("players/mythos/mmisc/drugs/weed/add/"+tp->query_real_name())) {
      if(time()-catime > 7000) {
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
    if(ctol > 30) {
    if(ctol - 30 > 10) {
    tp->heal_self(20); }
    else {
    tp->heal_self(30 - (ctol - 30));}
    } else {
    tp->heal_self(30);}
    save_object("players/mythos/mmisc/drugs/weed/add/"+tp->query_real_name());
    destruct(this_object());
    return 1;}
}
