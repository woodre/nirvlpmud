void send_event(mapping event,object *handlers)
{
  "/global/server/events"->send_event(event,handlers);
}

void send_local_event(mapping event,mixed room)
{
  int i;
  object *handlers;
  if (!pointerp(room))
    send_event(event,({ room }) + all_inventory(room));
  else
  {
    handlers = ({ });
    for (i=0;i<sizeof(room);i++)
      handlers += ({ room[i] }) + all_inventory(room[i]);
    send_event(event,handlers);
  }
}
