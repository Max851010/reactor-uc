#include "reactor-uc/environment.h"
#include "reactor-uc/reactor.h"
#include "reactor-uc/scheduler.h"

#include <stdio.h>

void Environment_assemble(Environment *self) {
  (void)self;
  printf("Assembling environment\n");
}
void Environment_start(Environment *self) {
  (void)self;
  printf("Running program\n");

  self->scheduler.run(&self->scheduler);
}

int Environment_wait_until(Environment *self, instant_t wakeup_time) {
  (void)self;
  (void)wakeup_time;
  return 0;
}

void Environment_ctor(Environment *self, Reactor **reactors, size_t reactors_size) {
  self->reactors = reactors;
  self->reactors_size = reactors_size;
  self->assemble = Environment_assemble;
  self->start = Environment_start;
  self->keep_alive = false;
  self->wait_until = Environment_wait_until;
  Scheduler_ctor(&self->scheduler, self);
}
