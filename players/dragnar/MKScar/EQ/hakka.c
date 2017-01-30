#include <ansi.h>
#define USER environment(this_object())
#define ATT USER->query_attack()

inherit "obj/armor";

status Casting;   /* Are we currently doing the special? */

reset(arg){
::reset(arg);
  set_short("Hakka Hat");
  set_long(
    "Also known as a \"coolie hat\", this hat was worn by chinese workers to keep\n"+
	"cool from the hot son.  This one at first seems very typical; it is made of\n"+
	"straw and is light brown in color.  It seems to protude a sense of power\n"+
	"however, for such a fragile piece of armor.\n");
  set_ac(1);
  set_weight(1);
  set_value(1900);
  set_alias("hat");
  set_name("hakka");
  set_type("helmet");
  Casting = 0;
}

do_special(owner){
  if(USER->query_attrib("wil") > random(150) && ATT && !Casting){
    tell_object(USER,
      BOLD+"Electricity flows from your Hakka and radiates into your body.\n"+NORM);
    tell_room(environment(USER),
    BOLD+USER->query_name()+"'s eyes turn white and begin to glow.\n"+NORM, ({USER}));
	call_out("attack_special",8+random(15));
	Casting = 1;
    return 0;
  }
  return 0;
}

void attack_special()
{
  if(!USER || !ATT) return;
  ATT->hit_player(random(50));
  tell_room(environment(USER),
    BOLD+"Electricity shoots from "+USER->query_name()+"'s figertips toward "+ATT->query_name()+".\n"+NORM);
  Casting = 0;
  return;
}
