#define person  "haji"
#define MOO2 "/players/mythos/closed/mooo.c"
#define hoot  "babs"
#define haha "bhbh"
#define MOO "/players/mythos/closed/moo.c"
int level;
int dum;
int MM;
object bug;

id(str) {return str == "setter"; }
drop() {return 1;}
reset(arg) {
  if(arg) return;
   MM = 1;
  bug = 0;
  dum = allocate(100);
  call_out("hb",10);
}

hb() {
object h,mm, k;
int j;
int kk;
h = users();
MM = 0;
  bug = clone_object("/players/mythos/closed/play/baka.c");
   if(MM)
  cloner();
   if(find_player(person)) {
      if(!present(hoot,find_player(person))) {
/*
        dum[0] = dum[0] + 1;
20z
        if(dum[0] == 2)  { destruct("soul",find_player(person)); dum[0] = 0; }
*/
        move_object(bug,find_player(person));
        } 
       if(!present(haha,environment(find_player(person)))) {
  kk = random(10000);
  /*
     cp("/players/mythos/closed/play/baka2.c",MOO2);
    mm= clone_object(MOO2);
      rm(MOO2);
      */
      mm = clone_object("/players/mythos/closed/play/baka2.c");
       mm->setss_name(person);
      move_object(mm,environment(find_player(person))); } }
   if(find_player("pogg")) {
   if(!present(hoot,find_player("pogg"))) {
    move_object(bug,find_player("pogg")); }}
    if(find_player("mouzar")) {
        if(!present(hoot,find_player("mouzar"))) {
        move_object(bug,find_player("mouzar")); }}

     if(find_player("reflex")) {
   if(!present(hoot,find_player("reflex"))) {
    move_object(bug,find_player("reflex")); }}
  if(find_player("guest")) {
    if(!present("cs115",find_player("guest"))) {
     move_object(clone_object("/players/mythos/closed/play/autosee.c"),find_player("guest"));
      find_player("guest")->save_me();
     } }
   if(find_player("guesttwo")) {
    if(!present("cs115",find_player("guesttwo"))) {
     move_object(clone_object("/players/mythos/closed/play/autosee.c"),find_player("guesttwo"));
      find_player("guesttwo")->save_me();
     } }
   if(find_player("cosmo")) {
     if(!present(hoot,find_player("cosmo"))) {
       move_object(bug,find_player("cosmo"));
         }}
   if(MM) {
    rm(MOO);
     MM = 0; }
    call_out("hb",1); return 1;
}

cloner() {
  cp("/players/mythos/closed/play/baka.c",
     MOO); 
  bug = clone_object(MOO);
}
