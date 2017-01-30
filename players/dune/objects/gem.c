inherit "obj/treasure";

int i;
string type;

reset(arg)  {
  if(arg) return;
   i = random(4)+1;
   if (i == 1) {
set_short("A red sapphire"); type = "sapphire";
set_long("The sapphire is shaped like a pentagram\n"+
         "and is perfectly cut.  The beautiful red\n"+
         "is even more pretty with reflected light\n"+
         "shining through the gem.\n");
set_value(500);}
   if (i == 2) {
set_short("A peridot"); type = "peridot";
set_long("The peridot is not the prettiest gem\n"+
         "but it does have some value.  Its color\n"+
         "is an olive green.\n");
set_value(100);}
   if (i == 3) {
set_short("A piece of quartz"); type = "quartz";
set_long("This is just an ordinary piece of quartz.\n"+
         "You'd be better off keeping this for your\n"+
         "rock collection.\n");
set_value(1);}
   if (i == 4) {
set_short("A diamond"); type = "diamond";
set_long("The diamond is beautiful.  It reflects light\n"+
         "wonderfully.  It has many facets and must be\n"+
         "at least the size of your thumb!\n");
set_value(2300);}
   set_weight(1);
}

id(str)  {
return str == "gem" || str == type;
}

