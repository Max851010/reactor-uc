#ifndef REACTOR_UC_BUILTIN_TRIGGERS_H
#define REACTOR_UC_BUILTIN_TRIGGERS_H

#include "reactor-uc/reaction.h"
#include "reactor-uc/reactor.h"
#include "reactor-uc/trigger.h"

typedef struct Startup Startup;

struct Startup {
  Trigger super;
};

void Startup_ctor(Startup *self, Reactor *parent, Reaction **effects, size_t effects_size);

#endif
