id(str){ return (str == "bookcases" || str == "shelves" || str == "bookcase" || str == "bookshelves"); }
long(){
object book;
book = first_inventory(this_object());
write("Oak bookcases that stretch from the floor to the ceiling.\n");
write("    They contain:\n");
while(book){
  if(book) write(book->short()+"\n");
  book = next_inventory(book);
}
}

reset(){
int i,a;
object book;
string *files;
files = get_dir("/players/wocket/mages/obj/books/");
for(i=0,a=sizeof(files);i<a;i++){
book = clone_object("/players/wocket/mages/obj/books/"+files[i]);
if(book) move_object(book,this_object());
}
}


