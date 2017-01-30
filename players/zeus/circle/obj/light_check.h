
light_check(){
  if(USER->test_dark()){
    write("Your powers fail here.\n");	
	return 1;
  }
  return 0;
}
