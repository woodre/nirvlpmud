#define tp this_player()->query_name()
#define tg this_player()->query_gender()

inherit "obj/treasure";

reset(arg) {
  if(arg) return;

  set_id("blood");
  set_short("A pool of blood");
  set_long("The blood of the Hinotori.  You may <drink> it.\n");
  set_weight(100000);
  set_value(2000);
}


init() {
  ::init();
  add_action("ddrink","drink");
  }
  
ddrink(str) {
  if(!str) {write("Drink what?\n"); return 1;}
  if(str == "blood") {
    write("You drink the blood...Something has changed...\n");
    say(capitalize(tp)+" drinks the blood...\n");
if(present("mythos_mark", this_player())){ destruct(this_object()); return 1; }
    move_object(clone_object("/players/mythos/amisc/forest/resur.c"),this_player());
    destruct(this_object());
    return 1;}
    }
