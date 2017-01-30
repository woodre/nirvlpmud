

short()
{
      return "A glowing glob of some unknown substance";
}

query_value()
{
        return 1;
}

  query_weight() {   return 0; }
long()
{
write("It looks unlike anything you have seen before.\n");
write("You may be able to eat it, or even breath it through your nose.\n");
}

init() {
     add_action("eat","eat");
     add_action("snort","snort");
}

id(str) {
    return str == "glob" || str == "substance";
}

eat(str) {
    if (str && !id(str))
        return 0;
write("You don't feel so good....\n");
write("You feel every,every strange....\n");
write("That stuff tingles all the way down....\n");
write("It might have been radioactive.\n");
lower_attrib(1);
lower_attrib(2);
  destruct(this_object());
    return 1;
}

get() {
 write("Your hand tingles as you hold the glob.\n");
    return 1;
}
lower_attrib(arg) {
  int la,ok;
  string las;
  ok = 0;
  while (ok < 1) {
  la = random(7);
  if (la == 8) return 1;
  if (la == 7) las = "strength";
  if (la == 6) las = "will_power";
  if (la == 5) las = "magic_aptitude";
  if (la == 4) las = "piety";
  if (la == 3) las = "stamina";
  if (la == 2) las = "stealth";
  if (la == 1) las = "luck";
  if (la == 0) las = "intelligence";
if (call_other(this_player(), "query_attrib", extract(las,0,2)) > 0)
   ok = 1;
  if(arg == 2)
    ok =0;
  if(arg == 2 && call_other(this_player(), "query_attrib",extract(las,0,2))<20)
   ok = 1;
}
if (arg == 1) {
call_other(this_player(), "raise_" + las, -1);
return 1;
}
if (arg == 2) {
call_other(this_player(), "raise_" + las, 1);
return 1;
}
}
snort(){
  object sxob;
  string wo,wh;
       sxob = this_player();
       if(sxob->query_gender() == "female"){
       call_other(sxob, "set_gender", "male");
       write("As you finish sorting the substance you feel your body begin to change.\n"+
       "You watch helplessly as the shape of your body changes and you begin to\n"+
     "see breasts dissapear and muscles grow larger. The transformation completes,\n"+
     "and you become a male.\n");
   write("You feel that the right clothes may cure this.\n");
      }
    else write("You snort the waste.\n");
   destruct(this_object());
       return 1;
 }
