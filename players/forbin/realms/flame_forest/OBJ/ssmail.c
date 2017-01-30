inherit "obj/armor";
#include "/players/fred/closed/bloodfist/defs.h"
object Me, Gob;
int S, G;
int Dented;

id(str){ return (::id(str) || str == "salamite_bfeq"); }

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("salamite scalemail");
  set_alias("scalemail");
  set_short(HIR+"Sala"+NORM+RED+"mite "+HIR+"Scale"+NORM+RED+"mail"+NORM);
  set_type("armor");
  set_ac(3);
  set_weight(3);
  set_value(5000+random(5000));
  Dented = 0;
}

long(string str) {
  long_desc =
    "This supple leather tunic is fitted with many salamite scales\n"+
    "forming a strong suit of scalemail.  The pieces interlock tightly\n"+
    "around a silver plate in the center of the chest.  Inside the\n"+
    "rounded plate, a whirlwind of sand has been etched, it's finely\n"+ 
    "carved lines dusted with powered ruby.  The armor feels strong,\n"+    
    "almost like platemail.  While its rigidity might hamper one's\n"+ 
    "movement, it looks like it'd provide nice protection in combat.\n";
  if(Dented) 
    long_desc += "A large dent has crushed a hole in one side of the armor.\n";    
  if(this_player()->query_guild_name() == "bloodfist")
    long_desc += RED+"The scalemail radiates with an envigorating power.\n"+NORM;
  ::long();
}

query_save_flag() { 
  if(Dented) {
    write("The scalemail has been dented and will no longer fit in storage.\n");
    return 1; 
  }
  else return 0; 
}

drop(silently) {
  Me = worn_by;
  G = ::drop(silently);
  if(worn_by == 0 && Me == this_player()) {
    if((Gob = present("bloodfist_gob", this_player()))) {
      Gob->add_attribb(0, 24);  /* agility */
      Gob->add_attribb(3, -27); /* vigor */
      Gob->add_attribb(1, -27); /* might */
      Gob->advance_checks();      
    }
  }
  ac = 3;
  return G;
}

wear(string str) {
  S = worn;
  G = ::wear(str);
  if(!S && worn_by == this_player()) {
    if(this_player()->query_extra_level() > 30)
      ac = 5;
    else if(this_player()->query_extra_level() > 6)
      ac = 4;
    else 
      ac = 3;      
    if((Gob = present("bloodfist_gob", this_player()))) {
      Gob->add_attribb(0, -24); /* agility */
      Gob->add_attribb(3, 27);  /* vigor */
      Gob->add_attribb(1, 27);  /* might */
      Gob->advance_checks();            
    }
  }
  return G;
}

remove(string str) {
  Me = worn_by;
  G = ::remove(str);
  if(worn_by == 0 && Me == this_player())
    if((Gob = present("bloodfist_gob", this_player()))) {
      Gob->add_attribb(0, 24);  /* agility */
      Gob->add_attribb(3, -27); /* vigor */
      Gob->add_attribb(1, -27); /* might */
      Gob->advance_checks();            
    }
  ac = 3;
  return G;
}

do_special(object owner) {
  if(!owner) return;
  if(!random(13) && !Dented) {
    tell_object(owner,
      "Your scalemail deflects part of your opponents blow.\n");
    if(random(251) == 13) { 
      tell_object(owner,
        "The blow dents your scalemail.\n");
      Dented = 1;       
      this_object()->set_short(HIR+"Sala"+NORM+RED+"mite "+HIR+"Scale"+NORM+RED+"mail"+NORM+" [dented]");
    }
    return 2;
  }
}

xfer_special() {
  Me = worn_by;
  if(worn_by == 0 && Me == this_player())
    if((Gob = present("bloodfist_gob", this_player())))
    {
      Gob->add_attribb(0, 24);  /* agility */
      Gob->add_attribb(3, -27); /* vigor */
      Gob->add_attribb(1, -27); /* might */
      Gob->advance_checks();
    }
}
