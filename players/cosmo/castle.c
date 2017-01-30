#define NAME "Cosmo"
#define DEST "room/plane1"

id(str) { return str == "path" || str == "gravel"; }

short() {
    return "A gravel path leading northwest";
}

long() {
    write("\n"+
"The gravel road splits off from the large open plain and initially heads\n"+
"northwest; however, it is a winding road that continues far into the\n"+
"distance.  It's difficult to determine the ultimate destination.  This\n"+
"path looks to be the road less traveled.\n");
}

init() {
  add_action("enter", "northwest");
  add_action("enter", "nw");
}

enter(str) {
    this_player()->move_player("northwest#/players/cosmo/dc/rooms/path/p1");
    write_file("/players/cosmo/log/PATH.LOG", this_player()->query_name()+
       " entered at "+ctime(time())+"\n");
    return 1;
}

reset(arg) {
object ob1;
  if (arg) return;
  move_object(this_object(), DEST);

/* A useless item, so I'm stopping it from autoloading. -Feldegast 12-16-00
  ob1 = clone_object("/players/cosmo/closed/batt.c");
  move_object(ob1,this_object());
  destruct(ob1);
*/

  move_object(clone_object("/players/cosmo/hslist/vds_new.c"),
    "/players/cosmo/workroom.c");
}

is_castle() { return 1; }
