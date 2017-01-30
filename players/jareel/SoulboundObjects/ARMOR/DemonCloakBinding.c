inherit "obj/armor";
inherit "obj/container.c";
#include "/players/jareel/define.h"
#define SHOP "obj/daemons/shop_daemon"

string soulbinder;

void
reset(int arg) {
    ::reset(arg);
    if (arg) return;
    set_name("cloak");
    set_type("cloak");
    set_alias("demon cloak");
    set_short(HIK+"Demon Cloak of Holding"+NORM+" ["+HIK+"Demon Forged"+NORM+"]"+NORM);
    set_long(
      "Demon Cloaks are forged from the flesh of a void demon in the rare\n"+
      "demonic soul fire of an Ember Sembraki Demon. Forging bags is an ancient\n"+
      "practice that turns chaotic flesh into a protective shell that will allow\n"+
      "you can store items in the cloaks dark void. To see what is in your cloak\n"+
      MAG+"'cloakinv'"+NORM);
    set_ac(1);
    set_res(1);
    set_value(1000);
    set_weight(1);
    set_max_weight(500); /* Major Drop on a Big Mob Item is Soul Bound to a
                            Player that is the plan anyway Soul Bound will
                            be (500) if its No save will be (1000) */
}

long() {
  ::long();
  if( soulbinder )
    write(this_object()->short()+" is soulbound to "+capitalize(soulbinder)+".\n");
}

wear( string str ) {
  if( id(str) && this_player() && present(this_object(), this_player()) &&
      this_player()->query_real_name() != soulbinder )
  {
    write("For some reason you are unable to wear this armor.\n");
    return 1;
  }
  else
    return ::wear(str);
}

set_binder( string str ) { soulbinder = str; }
query_binder() { return soulbinder; }

locker_arg(){        return soulbinder; }
locker_init(arg){    set_binder(arg); }

init() {
  ::init();
  add_action("cloakinv","cloakinv");
}

cloakinv( string str ) {
  return SHOP->list( str );
}

query_empty_shop() { return short_desc+" is empty."; }
query_backshop() { return this_object(); }
