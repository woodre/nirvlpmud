#define TOB tell_object
#define TP  this_player()
#define QCN query_real_name()
#define ENV environment

id(str) { return str == "spyer"; }
short () {return "A Spyer";}
long() {write("To spy on a person, type 'spy <player>'.\n");}
get() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
drop() { destruct(this_object()); return 0; }
init() {add_action("spy","spy");}

spy(string str) {
  object room, ob;
  object *inv;
  int i;
  if(!str) {
     write("Who do you want to spy on?\n");
     return 1;}
  if(!find_player(str)) {
     write("User "+capitalize(str)+" not found.\n");
     return 1;}
  i = 0;
  ob = find_player(str);
  room = ENV(ob);
  inv = all_inventory( room );
  TOB( TP, ""+room->long()+"\n\n");
  TOB( TP, "Objects ("+sizeof(inv)+")\n");
  for( i = 0; i < sizeof( inv ); i++ ) {
    if( living(inv[i])) handle_living(inv[ i ]);
    else handle_object( inv[ i ] );
  }
  TOB( TP, "\n" );
  return 1;
}

void handle_living( object test ) {
  if(interactive(test)) {
    TOB( TP, test->QCN+" "+test->query_title()+"\n");
    } 
  else {
    TOB( TP, test->query_name()+"\n");
    }
}

void handle_object( object test ) {
if(test->short()) {
  TOB( TP, "Item: "+test->short()+
           "  Value: "+test->query_value()+
           "  Weight: "+test->query_weight()+"\n"+
           "      Filename: "+file_name(test)+"\n");
  return;}
else {
  TOB( TP, "Unknown item: "+test->query_short()+
           "  Value: "+test->query_value()+
           "  Weight: "+test->query_weight()+"\n"+
           "      Filename: "+file_name(test)+"\n");
  }
return;
}
