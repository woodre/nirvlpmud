#define tp this_player()
inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("plaque");
    set_short("A Plaque");
    set_long("A Marble Plaque us before you.\n"+
              "Type 'members' to see the member's log\n"+
              "and 'oaths' or 'oaths2' or 'oaths3' or\n"+
      "oaths4 or 'oaths5' or 'oaths6'\n"+
         "or 'oaths7' or 'oaths8' or 'oaths9'\n"+
           "or 'oaths10'\n"+
            "for a log of oaths\n");
    set_weight(10000);
}

init() { 
  ::init();
  add_action("oaths","oaths");
  add_action("oaths2","oaths2");
  add_action("oaths3","oaths3");
  add_action("oaths4","oaths4");
  add_action("oaths5","oaths5");
  add_action("oaths6","oaths6");
  add_action("oaths7","oaths7");
   add_action("oaths8","oaths8");
  add_action("oaths9","oaths9");
  add_action("oaths10","oaths10");
  add_action("members","members");
}

members() {
/*
call_other("/closed/wiz_soul", "more","/players/mythos/closed/guild/ENTER");
*/
tail("/players/mythos/closed/guild/ENTER");
return 1;}

oaths() {
/*
call_other("/closed/wiz_soul", "more","/players/mythos/closed/guild/OATHS");
*/
cat("/players/mythos/closed/guild/OATHS");
return 1;}

oaths2() {
cat("/players/mythos/closed/guild/OATHS2");
return 1;}

oaths3() {
cat("/players/mythos/closed/guild/OATHS3");
return 1;}

oaths4() {
cat("/players/mythos/closed/guild/OATHS4");
return 1;} 

oaths5() {
cat("/players/mythos/closed/guild/OATHS5");
return 1;}

oaths6() { 
cat("/players/mythos/closed/guild/OATHS6");
return 1;}

oaths7() {
  cat("/players/mythos/closed/guild/OATHS7"); return 1; }

oaths8() {
  cat("/players/mythos/closed/guild/OATHS8"); return 1; }

oaths9() {
  cat("/players/mythos/closed/guild/OATHS9"); return 1; }

oaths10() {
  cat("/players/mythos/closed/guild/OATHS10"); return 1; }
