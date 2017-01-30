int main(string str){
  if(str == "on"){
    write("You turn your KnightSpeech on.\n");
    previous_object()->set_kspeech(0);
    return 1;
  }
  if(str == "off"){
    previous_object()->set_kspeech(1);
    write("You turn your KnightSpeech off.\n");
    return 1;
  }
  write("Usage: 'kspeech <on|off>'\n");
  return 1;
}
