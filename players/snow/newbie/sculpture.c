id(str) {return str == "sculpture";}
short() {write ("An Ice Sculpture\n");}
long() {write (
"This is a beautiful sculpture depicting a snow-covered field. There are\n"+
"snowflakes and snowmen wandering around with a beautiful sun shining\n"+
"overhead. It looks like a great place for young players to have fun in!\n"+
"Perhaps if you touched the sculpture you could actually go to the field\n"+
"and join in the fun...\n"); }

alias () {return "sculpture"; }
can_put_and_get() {return 0; }
get() {return 0; }
set_weight() {return 500; }


init() {
  add_action("touch","touch");
}

touch(arg) {
if (arg == "sculpture") {
/* Added by Pain 8/16/2000 */
if(this_player()->query_exp() > 30000 ||
this_player()->query_level() > 6) {
write ("You have seen too much violence to enter this peaceful area.\n");
return 1;
}
else
  say(this_player()->query_name()+" has become part of the sculpture!\n");
  move_object(this_player(),"/players/snow/newbie/newbie.c");
  command("look", this_player()); 
/*
write_file("/players/snow/log/newbie",ctime(time())+" "+
     this_player()->query_real_name()+" entered the ice sculture.\n");
*/
return 1;
    }
else
  write("Touch what?\n");
return 1;
}
