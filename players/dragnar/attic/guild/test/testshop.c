/* Shardak guild, (tm) Dragnar/John
 * Portable shop/Demon merchant is (c) Balowski/Rasmus, 950201
 *   "Mowing down mc's like I'm mowing the lawn"
 */
#define MASTER "players/dragnar/guild/test/portshop"
#define MASTER2 "players/dragnar/guild/test/tag"
#define GASHMASTER "players/dragnar/guild/test/wound"

get() { return 0;}
drop() { return 0;}
short() { return "Port shop test";}
long() { write( "Commands: sell, tag, untag, inv\n");}
id(str) { return str=="shop";}
init() {
  add_action( "sell", "sell");
  add_action( "tag", "tag");
  add_action( "untag", "untag");
  add_action( "inv", "inv");
  add_action( "gash", "gash");
}

sell(str) { return MASTER->sell( str);}
tag(str) { return MASTER2->tag( str);}
untag(str) { return MASTER2->untag( str);}
inv(str) { return MASTER2->inventory( str);}
gash(str) { return GASHMASTER->gash( str);}
