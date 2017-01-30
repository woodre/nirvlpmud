#include "/players/laera/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
  set_id("m-stone piece");
  set_alias("piece");
  set_short(HIB+"M-Stone Piece"+OFF);
set_long(

	"A broken piece of a magic stone, this bauble is worth very little.  It\n" +
	"has retained some magic power and could be used if one were a magic\n" +
	"user.\n");

  set_value(350 + random(300));
  set_weight(1);
}

