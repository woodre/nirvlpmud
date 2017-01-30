inherit "obj/weapon";

string soulbinder;
int special_hits;
int special_heals;

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("crossbow");
    set_alias("bow");
    set_short("Crossbow");
    set_long(
"The bow is pure black with black arrows; the only other color is\n"+
"the silver from the deadly tips of the arrows.\n");
    set_class(15);
    set_value(1000);
    set_weight(3);
    set_hit_func(this_object());
}

query_long() {
  string my_long;
  my_long = long_desc;
  if( soulbinder )
    my_long += this_object()->query_short()+" is soulbound to "+capitalize(soulbinder)+".\n";
  if( special_hits )
    my_long += this_object()->query_short()+" has done "+special_hits+" special hits.\n";
  if( special_heals )
    my_long += this_object()->query_short()+" has done "+special_heals+" special heals.\n";
  return my_long;
}

wield( string str ) {
  if( id(str) && this_player() && present(this_object(), this_player()) &&
      this_player()->query_real_name() != soulbinder )
  {
    write("For some reason you are unable to wield this weapon.\n");
    return 1;
  }
  else
    return ::wield(str);
}

mixed
weapon_hit(object attacker) {
  if(random (100) < 30) {
    write("The handle of your reaper is soaked with more blood.\n");
    say(this_player()->query_name() + "'s reaper is soaked with " +
    this_player()->query_possessive() + " opponent's blood.\n");
    special_hits++;
    return(random(6)+3);
  }
  if( this_player() && random(100) > this_player()->query_attrib("wil") ) {
    this_player()->add_hit_point( 10 );
    special_heals++;
    write("You are healed by your weapon, WTF!?\n"); 
  }
}

set_binder( string str ) { soulbinder = str; }
query_binder() { return soulbinder; }

locker_arg(){  
  string *args;
  args = ({ soulbinder, special_hits, special_heals });
  return implode( args, "|" ); 
}

locker_init(arg){  
  string *args;
  args = explode( arg, "|" );
  if( sizeof(args) == 3 ) {
    soulbinder = args[0];
    special_hits = args[1];
    special_heals = args[2];
  }
}
