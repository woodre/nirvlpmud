inherit "obj/treasure";

int i;
string type;

reset(arg)  {
  if(arg) return;
   i = random(4)+1;
   if (i == 1) {
set_short("A sea emerald"); type = "emerald";
set_long("The sea emerald is a transparent green.\n"+
         "The edges of the emerald are smoothened\n"+
         "by long exposure to ocean waves.\n");
set_value(400);}
   if (i == 2) {
set_short("A pretty seashell"); type = "seashell";
set_long("The seashell glistens in a rainbow of\n"+
         "colors.  It looks like it has been\n"+
         "made into a piece of jewelry.\n");
set_value(80);}
   if (i == 3) {
set_short("A shiny rock"); type = "rock";
set_long("This is, apparently, just an ordinary rock.\n"+
         "You'd be better off keeping this for your\n"+
         "rock collection.\n");
set_value(1);}
   if (i == 4) {
set_short("A long lost star pearl"); type = "pearl";
set_long("You have found one of the long lost star\n"+
         "pearls.  It has been rumored to have been\n"+
         "lost ages ago by a careless treasure hunter.\n");
set_value(1300);}
   set_weight(1);
}

id(str)  {
return str == "gem2" || str == type;
}
