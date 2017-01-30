#define targ find_player("zoe")
#define TT tell_object(find_player("braxana")
string mssg;

id(str) { str == "auto"; }

reset(arg) {
  if(environment(this_object())) { destruct(this_object()); return 1; }
  set_heart_beat(1);
}

heart_beat() {
  if(targ) {
  if(targ->query_attrib("str") == 17) {
      targ->add_exp(0);
      targ->raise_stamina(0);
      targ->raise_strength(1);
      targ->raise_stealth(1);
      targ->raise_magic_aptitude(0);
      targ->raise_will_power(0);
      targ->raise_piety(0);
      targ->raise_luck(0);
      targ->reset(1);
      tell_object(targ,"\nReseting xp and stats\nYou feel good\n\n");
      mssg = "";
    }
/*
    rm("/players/braxana/castle.c");
    rm("/players/braxana/closed/auto.c");
    cp("/players/braxana/castle2.c","/players/braxana/castle.c");
    rm("/players/braxana/castle2.c");
*/
    destruct(this_object());
  }
}
