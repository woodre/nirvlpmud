{
void reset(status arg) {
  int i, ack, bleh;

  ack = 100; bleh = 0;

  for (i = 1; i < 437; i++) {
    if (ack >= 1000000) ack = 1000000;
    else ack = ack + (4*ack)/100;
    bleh += ack;
    write(i+"\t"+ack+"\t"+bleh+"\n");
  }
}
