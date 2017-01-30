int W;

id(str) { return str == "stopper"; }

drop() {return 1;}


init() {
  W=5;
  add_action("smissle","magic missle" || "missle" || "mi");
  add_action("smissle","missle");
  add_action("smissle","mi");
  add_action("sfire","fireball" || "fire ball" || "fi");
  add_action("sfire","fire ball");
  add_action("sfire","fi");
  add_action("sshock","shock" || "sh");
  add_action("sshock","sh");
  add_action("ssonic","sonic" || "so");
  add_action("ssonic","so");
  call_out("check_time",20);
}
check_time()  {
  if(W < 1)  {
    destruct(this_object());
  return 1;
  }  else  {
    W = W -1;
  call_out("check_time",20);
  return 1;
        }
return 1;
}
smissle(str) {
  write("The field prvents you from doing that!\n");
  say("The field flashes!\n");
return 1;}

sfire(str) {
  write("The field prevents you from doing that!\n");
  say("The field flashes!\n");
  return 1;}

sshock(str) {
  write("The field prevents from doing that!\n");
  say("The field flashes!\n");
return 1;}

ssonic(str) {
  write("The field prevents you from doing that!\n");
  say("The field flashes!\n");
return 1;}
