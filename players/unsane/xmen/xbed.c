inherit "room/room";

#define tp this_player()->query_name()
int book, desk;

reset (arg){
if (!arg){
set_light(1);
}
if (!present("magneto")) move_object(clone_object("/players/unsane/xmen/magneto"), this_object());
if (!present("professor")) move_object(clone_object("/players/unsane/xmen/professor"), this_object());
short_desc="Professor X's Bedroom";
items=({
  "bed","This bed is clean and well made.  The Professor is a stickler for order",
  "desk","This large desk is loaded with maps and files and such",
  "lamp","Just a small lamp for reading",
  "bookshelf","This bookshelf contains many volumes, on topics ranging from the occult to psychic power to robotics",
  "computer","This is just a small computer that the Professor works on.  Not Cerebro",
  "window","Yes, I guess there is a window here as well",});
dest_dir=({
"players/unsane/xmen/inter.c","east",});
long_desc =
"  This bedroom is emmaculate.  There is a large, sturdy bed here.  You also\n"+
"notice a massive oak desk, a bookshelf, a small lamp, and a huge computer\n"+
"against one wall.  Professor X spends most of his time here in his room\n"+
"worrying about the X-men and making important decisions.  You feel a prick\n"+
"at the back of your neck when you enter, and you realize you must have set\n"+
"off some kind of psychic alarm system.\n";
}
init(){
::init();
add_action("listen","listen");
   add_action("smell","smell");
   add_action("search","search");
}
search(str){
string a,b;
if (!str) {
write("What do you want to search?\n");
return 1;}
if (sscanf(str,"%sbook%s",a,b) == 2 && book < 1) {
write("You find a book entitled 'Dante's Inferno'.\n");
book++;
return 1;}
if (sscanf(str,"%sdesk%s",a,b) == 2 && desk < 1) {
write("You find a scrap of paper that looks interesting.\n");
move_object(clone_object("/players/unsane/xmen/paper"),this_player());
desk++;
return 1;}
write("You don't find anything important.\n");
return 1;}
smell(){
write("This room has a clean smell to it.\n");
say(tp+" takes a deep breath of the air.\n");
return 1;
}
listen(){
if (present("professor") && present("magneto")) write("Professor X and Magneto are in a shouting match about something important.\n");
else if (present("professor") || present("magneto")) write("This person is mumbling about something.\n");
else write("It is now silent here.\n");
say(tp + " perks up their ears.\n");
return 1;
}

