int caught;
id(str) {return str=="flowers" || str=="roses" || str=="bouquet";}

init() {
  add_action("throw","throw");
  add_action("throw","toss");
}

short() {return "A bridal bouquet";}

long() {
  write("A stunning bouquet of white roses, fit for only the most\n");
  write("beautiful of brides-- like you.\n");
  write("Don't forget to 'toss' the bouquet after the wedding!\n");
	return 1;
}
get() {return 1;}
drop() {
  write("The flowers wilt and die as you drop them.\n");
  destruct(this_object());
  return 1;}
throw(id) {
object mem;
object mem2;
object catcher;
object temp;
int count;
int x;
x=0;
count=0;
mem=users();
mem2=allocate(15);
  if(!id) { return 0;}
  if(caught) {
    write("Only the bride can toss the bouquet!\n");
    return 1;}
  while(x<sizeof(mem)) {
   if(mem[x]->query_gender()=="female" && mem[x] != this_player()) {
  if(!present("wedding ring",mem[x])) {
    temp=mem[x];
    mem2[count]=temp;
  count +=1;
}
}
  x +=1;
}
  if(!count) {
    write("You toss the bouquet into the air, but there is no one "+
"around\nto catch it.  The bouquet crashes to the ground.\n");
    destruct(this_object());
    return 1;}
     x=random(count);
  catcher=mem2[x];
   write("You toss the bouquet high into the air.\n");
   write(capitalize(catcher->query_name())+" reaches up and catches it.\n");
   move_object(this_object(),catcher);
  shout(capitalize(this_player()->query_name())+" throws a bridal "+
  "bouquet high into the air.\n"+capitalize(catcher->query_name())+
" reaches up and catches the bouquet!\n");
  caught=1;
  return 1;}
